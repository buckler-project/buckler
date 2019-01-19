#include <vector>
#include <string.h>
#include <gtest/gtest.h>
#include <gmock/gmock.h>


#include "../../src/base.hpp"
#include "../../src/scanner.hpp"

using namespace buckler;

class ScannersTest : public ::testing::Test {};

TEST_F(ScannersTest, Scanners) {
    Signature signature = Signature("./data/scanners");
}

TEST_F(ScannersTest, Path) {
    std::vector<std::string> vec = {
        "./data/scanners/sample-scanner",
    };

    ScannersList list = ScannersList();
    ScannersRepository repo = ScannersRepository(&list);
    
    repo.parent_path = "./data/scanners";
    repo.LoadAll();

    std::cout << std::endl;
    std::cout << "-*-*-*-*- DATA -*-*-*-*-" << std::endl;

    list.Start();
    for(auto itr = vec.begin(); (itr != vec.end() && list.is_continue) ; ++itr) {
        std::string path = list.Next().path;
        std::cout << "path: " << path << std::endl;
        std::cout << "expected: " << *itr << std::endl;
        ASSERT_EQ(*itr, path);
    }
}

TEST_F(ScannersTest, LoadableFile) {
    std::string expected = "./data/scanners/sample-scanner/bin/libsample.so";
    ScannersList list = ScannersList();
    ScannersRepository repo = ScannersRepository(&list);
    
    repo.parent_path = "./data/scanners";
    repo.LoadAll();

    list.Start();
    std::string loadable_file = list.Next().loadable_file;

    std::cout << std::endl;
    std::cout << "-*-*-*-*- DATA -*-*-*-*-" << std::endl;
    std::cout << std::endl;
    std::cout << "path: " << loadable_file << std::endl;
    std::cout << "expected: " << expected << std::endl;
    std::cout << std::endl;

    ASSERT_EQ(expected, loadable_file);

    std::cout << std::endl;
}

TEST_F(ScannersTest, ScanOne) {
    char fizz[] = "fizz";
    char buzz[] = "buzz";

    std::vector<unsigned char> fizz_vector((unsigned char *)fizz, (unsigned char *)(fizz + sizeof(fizz)));
    std::vector<unsigned char> buzz_vector((unsigned char *)buzz, (unsigned char *)(buzz + sizeof(buzz)));

    Target fizz_target = Target((unsigned char *)fizz, sizeof(fizz));

    Scanner scanner = Scanner();
    scanner.loadable_file = "./data/scanners/sample-scanner/bin/libsample.so";
    bool has_hit = scanner.ScanOne(fizz_target, fizz_vector);
    bool has_unhit = scanner.ScanOne(fizz_target, buzz_vector);

    ASSERT_TRUE(has_hit);
    ASSERT_FALSE(has_unhit);
}


TEST_F(ScannersTest, Scan) {
    Log expected_log("./data/scanners/sample-scanner", "./data/signatures/first", "./data/signatures/first/1.line");

    Scanner scanner = Scanner();
    scanner.loadable_file = "./data/scanners/sample-scanner/bin/libsample.so";
    scanner.path = "./data/scanners/sample-scanner";

    char hit_char_ptr[] = "hello\nworld";
    char unhit_char_ptr[] = "hello\nworld!!";

    std::vector<unsigned char> _hit_target(hit_char_ptr, hit_char_ptr + sizeof(hit_char_ptr));
    std::vector<unsigned char> _unhit_target(unhit_char_ptr, unhit_char_ptr + sizeof(unhit_char_ptr));

    Target hit_target = Target(_hit_target);
    Target unhit_target = Target(_unhit_target);

    SignaturesController signature_controller = SignaturesController();
    signature_controller.repository.parent_path = "./data/signatures";
    signature_controller.Load();

    Signature signature = signature_controller.list.data[1];

    Result has_hit = scanner.Scan(hit_target, signature);
    Result has_unhit = scanner.Scan(unhit_target, signature);


    ASSERT_TRUE(has_hit.has_hit);
    ASSERT_FALSE(has_unhit.has_hit);

    Log actual = has_hit.hits[0];
    ASSERT_EQ(expected_log.scanner, actual.scanner);
    ASSERT_EQ(expected_log.signature, actual.signature);
    ASSERT_EQ(expected_log.signature_file, actual.signature_file);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
