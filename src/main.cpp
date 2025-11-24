#include <iostream>
#include <string>
#include "Loan.h"
#include "Utils.h"
using namespace std;
int main(int argc, char **argv)
{
  LoanCalculator calculator;
  auto config = readConfig("config.txt");
  calculator.setAmount(config["defaultAmount"]);
  calculator.setInterest(config["defaultInterest"]);
  calculator.setPeriodTotal((int)config["defaultPeriod"]);
  calculator.setPeriodElapsed((int)config["defaultPeriodElapsed"]);
  calculator.setPayment(config["defaultPayment"]);
  calculator.setInitialPayment(config["defaultInitialPayment"]);
  calculator.setOpeningFee(config["defaultFee"]);
  calculator.setOpeningPercent(config["defaultFeePercent"]);
  if (argc < 2)
  {
    cout << "\n Usage:";
    cout << "\n balance  - calculate remaining Loan";
    cout << "\n payment  - calculate Monthly payment";
    cout << "\n numpay  - No. payments required";
    cout << "\n amount   - calculate loan amount";
    cout << "\n interest  - calculate interest rate";
    return 0;
  }
  string cmd = argv[1];
  try
  {
    if (cmd == "balance")
    {
      cout << "\n Load balance=" << calculator.calculateLoanBalance() << endl;
    }
    else if (cmd == "payment")
    {
      double p = calculator.calculatePayment();
      cout << "\nMonthly Payment =" << p << endl;
      ;
    }
    else if (cmd == "numpay")
    {
      cout << "\n No. of payments:" << calculator.calculateNumberPayments() << endl;
    }
    else if (cmd == "amount")
    {
      cout << "\n Load amount=" << calculator.calculateLoanAmount() << endl;
    }
    else if (cmd == "interest")
    {
      cout << "\n Interest Rate =" << calculator.calculateInterestRate() << "%" << endl;
    }
    else
    {
      cout << "\n Invalid Command!" << endl;
    }
  }
  catch (const exception &e)
  {
    cerr << "Error:" << e.what() << endl;
  }
  return 0;
}