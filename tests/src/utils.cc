#include <vector>
#include <string.h>
#include <gtest/gtest.h>
#include <gmock/gmock.h>


#include "../../src/base.hpp"
#include "../../src/utils.cc"


#undef SIGNATURE_DIRECTORY
#define SIGNATURE_DIRECTORY "./data/signatures"

using namespace buckler;

class UtilsTest : public ::testing::Test {};

class TestList : public IteratableObject<std::string> {};

class TestRepository : public Repository<std::string> {
public:
    TestRepository(TestList *list, std::string parent_path) 
        : Repository(list, parent_path) {
            parent_path = SIGNATURE_DIRECTORY;
            config_path = "signature.yml";
            type = "signature";
        }

    std::string Load(YAML::Node config, std::string path) {
        return path;
    }
};

TEST_F(UtilsTest, LoadAll) {
    TestList list = TestList();
    TestRepository repo(&list, std::string("./data/signatures"));

    repo.LoadAll();

    std::cout << std::endl;
    std::cout << "-*-*-*-*- DATA -*-*-*-*-" << std::endl;

    list.Start();    
    while(list.is_continue) {
        std::cout << list.Next() << std::endl;
    }

    std::cout << std::endl;

    ASSERT_THAT(list.data, testing::ElementsAre<std::string> (
            std::string("./data/signatures/buckler-project/first"),
            std::string("./data/signatures/buckler-project/second")
        )
    );
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


