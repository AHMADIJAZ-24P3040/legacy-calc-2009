/**
 * @file Loan.h
 * @brief contains the LoanCalculator class for loan calculations
 * Procides methods:
 *  1. Loan balance
 *  2. Payement amount
 *  3. Number of payment
 *  4. Original loan amount
 *  5. Intertest rate
 *  6. Effective itnerest rate with fees
 */
#ifndef LOANCALCULATOR_H_INCLUDED
#define LOANCALCULATOR_H_INCLUDED

/*
Formulas from: http://oakroadsystems.com/math/loan.htm

Loan balance after n payments have been made:
  B_n = A*(1+i)^n - (P/i)*((1+i)^n - 1)


Payment amount on a loan:
  P = i*A / (1 - (1+i)^-N)


Number of payments on a loan: (You can use any logarithm base, as long as both logs use the same base.)
                              Aunt Sally offers to lend you $3500 at 6% for that new home theater system you want.
                              If you pay her back $100 a month, how long will it take?
                              Solution:  6% per year is 0.5% per month, or 0.005. P = 100 and A = 3500. N = 38.57
  N = -log(1-i*A/P) / log(1+i)


Original loan amount:
  A = (P/i)*(1 - (1+i)^-N)


Interest Rate:
  i = (((1 + P/A)^(1/q) - 1 )^q - 1)  NOTICE: This is an approximate not an exact solution
  where q = log(1+1/N) / log(2)


Variables:
A   	the loan amount (the principal sum) or initial investment
B_n or Bn   	(pronounced B sub n) the balance after n payments have been made. After the last payment has been made, B_N is zero.)
i   	the interest rate per period, not per year
      (For instance, if the loan payments are made monthly and the interest rate is 9%, then i = 9%/12 = 0.75% = 0.0075.)
n   	the number of time periods elapsed at any given point
N   	the total number of payments for the entire loan or investment
P   	the amount of each equal payment
*/

#include <string>
/**
 * @class LoanCalculator
 * @brief Calcualtes loan raleted tasks
 */
class LoanCalculator
{
public:             /**
                     * @brief Default constructs
                     */
  LoanCalculator(); /**
                     * @brief Destructor
                     */
  ~LoanCalculator() {}

  //
  // Setters and Getters
  //

  /**
   * Total loan amount A
   */
  /**
   * @brief sets the amount for A<=0
   */
  inline void setAmount(double A)
  {
    if (A <= 0)
    {
      throw std::invalid_argument("Amount must be positive");
    }
    amount_ = A;
    amountSet_ = true;
  } /**
     * @brief gets us the amount
     */
  inline double getAmount() const { return amount_; }

  /**
   * Initial down payment
   */
  /**
   * @brief sets the intial down payment
   */
  inline void setInitialPayment(float initialA) { initialPayment_ = initialA; } /**
                                                                                 * @brief gets intital down payment
                                                                                 */
  inline double getInitialPayment() const { return initialPayment_; }

  /**
   * Yearly interest rate i as in 6.75
   * Internally .0675/12 will be used
   * If 6.75 is passed to setInterest()
   *    getInterest() will return 6.75
   *    getPeriodicInterest() will return .0675/12.0
   */
  /**
   * @brief sets yearly interest rate
   */
  void setInterest(double i)
  {
    if (i <= 0)
    {
      throw std::invalid_argument("Interest must be positive");
    }
    interest_ = i;
    interestPeriodic_ = i / 100.0 / 12.0;
    interestSet_ = true;
  } /**
     * @brief gives the yearly interest rate when needed
     */
  inline double getInterest() const { return interest_; }
  inline double getPeriodicInterest() const { return interestPeriodic_; }
  /**
   * @brief sets the monthly payment throws if <=0
   */
  void setPayment(double P)
  {
    if (P <= 0)
    {
      throw std::invalid_argument("Payment must be positive");
    }
    payment_ = P;
    paymentSet_ = true;
  } /**
     * @brief Gets the monthly payment
     */
  inline double getPayment() const { return payment_; }
  /**
   * @brief Sets the total number of periods
   */
  void setPeriodTotal(int N)
  {
    if (N <= 0)
    {
      throw std::invalid_argument("Period must be positive");
    }
    periodTotal_ = N;
    periodTotalSet_ = true;
  } /**
     * @brief Gets the total numebr of periods
     */
  inline int getPeriodTotal() const { return periodTotal_; }
  /**
   * @brief Sets the elapsed time
   */
  void setPeriodElapsed(int n)
  {

    periodElapsed_ = n;
    periodElapsedSet_ = true;
  }
  /**
   * @brief Calcualtes loan raleted tasks
   */
  inline int getPeriodElapsed() const { return periodElapsed_; }

  inline void setOpeningFee(float fee) { openingFee_ = fee; }
  inline double getOpeningFee() const { return openingFee_; }

  inline void setOpeningPercent(float percent) { openingPercent_ = percent; }
  inline double getOpeningPercent() const { return openingPercent_; }

  inline void reset()
  {
    amount_ = initialPayment_ = interest_ = interestPeriodic_ = payment_ = openingFee_ = openingPercent_ = 0.0;
    periodTotal_ = periodElapsed_ = 0;
    amountSet_ = interestSet_ = paymentSet_ = periodTotalSet_ = periodElapsedSet_ = false;
  }

  //
  // The actual calculation methods
  //
  /**
   * @brief calculates the loan balance
   */
  double calculateLoanBalance();
  /**
   * @brief calcualtes the payemnt
   */
  double calculatePayment();
  /**
   * @brief calculates no of payments
   */
  double calculateNumberPayments();
  /**
   * @brief calculates the loan amount
   */
  double calculateLoanAmount();
  /**
   * @brief calculates itnerest rate
   */
  double calculateInterestRate();
  // The effective interest rate, once fees have been applied
  double calculateEffectiveInterestRate();

  std::string toString();

private:
  double amount_; // loan amount
  bool amountSet_;

  double initialPayment_; // initial down payment

  double interest_;         // interest rate, something like 6.75
  double interestPeriodic_; // this will be .0675/12
  bool interestSet_;

  double payment_; // payment amount
  bool paymentSet_;

  int periodTotal_; // total payment periods
  bool periodTotalSet_;

  int periodElapsed_; // number of elapsed payment periods
  bool periodElapsedSet_;

  // These two are used if loans charge a fee opening fee or percentage
  double openingFee_;
  double openingPercent_;
};

#endif // LOANCALCULATOR_H_INCLUDED
