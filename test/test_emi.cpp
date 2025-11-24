#include <gtest/gtest.h>
#include "../src/Loan.h"
#include "../src/Utils.h"
TEST(LoanCalculatorTest, NormalEMI)
{
    LoanCalculator calc;
    calc.setAmount(100000);
    calc.setInterest(12);
    calc.setPeriodTotal(12);
    double payment = calc.calculatePayment();
    EXPECT_NEAR(payment, 8884.78, 0.01);
}
TEST(LoanCalculatorTest, InvalidInput)
{
    LoanCalculator calc;
    calc.setAmount(-5000);
    calc.setInterest(12);
    calc.setPeriodTotal(12);
    EXPECT_THROW(calc.calculatePayment(), std::invalid_argument);
}
TEST(LoanCalculatorTest, LargeTenure)
{
    LoanCalculator calc;
    calc.setAmount(1000000);
    calc.setInterest(10);
    calc.setPeriodTotal(600);
    double payment = calc.calculatePayment();
    EXPECT_GT(payment, 0);
}
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}