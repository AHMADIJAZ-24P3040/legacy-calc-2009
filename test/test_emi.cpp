#include <iostream>
#include "../src/Loan.h"
#include "../src/Utils.h"
using namespace std;
void testLoanBalance()
{
    LoanCalculator loan;
    loan.setAmount(10000);
    loan.setInterest(6);
    loan.setPayment(500);
    loan.setPeriodElapsed(12);
    double balance = loan.calculateLoanBalance();
    cout << "\n Test Loan balance:" << balance << endl;
}
void testPayment()
{
    LoanCalculator loan;
    loan.setAmount(10000);
    loan.setInterest(6);
    loan.setPeriodTotal(24);
    loan.setInitialPayment(0);
    loan.setOpeningFee(0);
    loan.setOpeningPercent(0);
    double payment = loan.calculatePayment();
    cout << "\n Test payment:" << payment << endl;
}
void testNumberPayments()
{
    LoanCalculator loan;
    loan.setAmount(10000);
    loan.setInterest(6);
    loan.setPayment(500);
    double n = loan.calculateNumberPayments();
    cout << "\n Test No of payments:" << n << endl;
}
void testLoanAmount()
{
    LoanCalculator loan;
    loan.setInterest(6);
    loan.setPayment(500);
    loan.setPeriodTotal(24);
    double amount = loan.calculateLoanAmount();
    cout << "\n Test Loan Amount:" << amount << endl;
}
void testInterestRate()
{
    LoanCalculator loan;
    loan.setAmount(10000);
    loan.setPayment(500);
    loan.setPeriodTotal(24);
    double rate = loan.calculateInterestRate();
    cout << "\n Test Loan rate:" << rate << "% " << endl;
}
int main()
{
    cout << "\n ======= Loan Calculator Tests ==========" << endl;
    testLoanBalance();
    testPayment();
    testNumberPayments();
    testLoanAmount();
    testInterestRate();
    cout << "==================================";
    return 0;
}