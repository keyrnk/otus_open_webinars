#include "RotatedStack.h"
#include <gtest/gtest.h>

TEST(RotatedStack, AddTest) {
    RotatedStack st;
    EXPECT_EQ(0, st.Size());

    st.Add(10);
    EXPECT_EQ(1, st.Size());
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
