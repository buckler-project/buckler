#include <vector>
#include <gtest/gtest.h>

#include "../../src/buckler.hpp"
#include "../../src/base.hpp"

#undef SIGNATURE_DIRECTORY
#define SIGNATURE_DIRECTORY "../data/signature/hoge.txt"

using namespace buckler;

std::vector<unsigned char> data {
    'h', 'e', 'l', 'l', 'o'
};

class BucklerTest : public ::testing::Test {};

TEST_F(BucklerTest, Scan) {
    Target target = Target(data);
    Buckler buckler = Buckler(target);
    buckler.Scan();
    ASSERT_TRUE(buckler.result.is_hit);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


