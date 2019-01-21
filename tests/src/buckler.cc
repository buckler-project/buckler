#include <vector>
#include <gtest/gtest.h>

#include "../../src/buckler.hpp"
#include "../../src/base.hpp"

using namespace buckler;

class BucklerTest : public ::testing::Test {};

TEST_F(BucklerTest, Scan) {
    Log expected_log("./data/scanners/sample-scanner", "./data/signatures/first", "./data/signatures/first/1.line");
    
    char _target[] = "hello\nworld";
    Target target = Target((unsigned char *)_target, sizeof(_target));

    Buckler buckler = Buckler(target);
    
    buckler.scanners.repository.parent_path = "./data/scanners/";
    buckler.signatures.repository.parent_path = "./data/signatures/";

    buckler.Load();

    Result result = buckler.Scan();

    ASSERT_TRUE(result.has_hit);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


