#include <vector>
#include <string.h>
#include <gtest/gtest.h>
#include <gmock/gmock.h>


#include "../../src/base.hpp"
#include "../../src/signature.cc"

using namespace buckler;

class SignaturesTest : public ::testing::Test {};

TEST_F(SignaturesTest, Signatures) {
    Signature signature = Signature("./data/signatures");
}

TEST_F(SignaturesTest, Path) {
    std::vector<std::string> vec = {
        "./data/signatures/second",
        "./data/signatures/first"
    };

    SignaturesList list = SignaturesList();
    SignaturesRepository repo = SignaturesRepository(&list);
    
    repo.parent_path = "./data/signatures";
    repo.LoadAll();

    std::cout << std::endl;
    std::cout << "-*-*-*-*- DATA -*-*-*-*-" << std::endl;

    list.Start();
    for(auto itr = vec.begin(); (itr != vec.end() && list.is_continue) ; ++itr) {
        std::string path =  list.Next().path;
        std::cout << std::endl;
        std::cout << "path: " << path << std::endl;
        std::cout << "expected: " << *itr << std::endl;
        std::cout << std::endl;
        EXPECT_EQ(*itr, path);
    }

    std::cout << std::endl;
}

TEST_F(SignaturesTest, PathList) {
    std::vector<std::string> vec = {
        "./data/signatures/second/2.line",
        "./data/signatures/second/3.line"
    };

    SignaturesList list = SignaturesList();
    SignaturesRepository repo = SignaturesRepository(&list);
    
    repo.parent_path = "./data/signatures";
    repo.LoadAll();

    list.Start();
    IteratableObject<std::string> path_list = list.Next().path_list;

    std::cout << std::endl;
    std::cout << "-*-*-*-*- DATA -*-*-*-*-" << std::endl;
    std::cout << std::endl;

    path_list.Start();
    for(auto itr = vec.begin(); (itr != vec.end() && path_list.is_continue) ; ++itr) {
        std::string path =  path_list.Next();
        std::cout << std::endl;
        std::cout << "path: " << path << std::endl;
        std::cout << "expected: " << *itr << std::endl;
        std::cout << std::endl;
        EXPECT_EQ(*itr, path);
    }

    std::cout << std::endl;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
