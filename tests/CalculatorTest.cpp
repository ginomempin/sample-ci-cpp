#include "Calculator.h"
#include <gtest/gtest.h>

TEST(DivTest, InvalidNumbers) {
    Calculator calc = Calculator();

    ASSERT_FALSE(calc.div(7, 0));
    ASSERT_EQ(0, calc.get_last_result());
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
