#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    // Note that `#include <iomanip>` is required for the following line,
    // which configures the `cout` object to print floating point numbers
    // as "fixed, to 2 decimal places, always showing the decimal point".
    cout << setprecision(2) << fixed << showpoint;

    // Declare input variables
    double loanAmount;
    double ratePercent;
    int numMonths;


    // Get user input
    cin >> loanAmount;
    cin >> ratePercent;
    cin >> numMonths;

    // Compute the required values:
    /*
     *               P * i
     *    A  =  ---------------
     *                      -n
     *           1 - (1 + i)
     */

    // double rateDecimal = ...
    double rateDecimal = ratePercent / 100;
    // double numerator = ...
    double numerator = loanAmount * rateDecimal;
    // double denominator = ...
    double denominator = (1 - pow(1 + rateDecimal,  -numMonths));
    // double monthlyPayment = ...
    double monthlyPayment = numerator / denominator;
    // double paidBack = ...
    double paidBack = monthlyPayment * numMonths;
    // double interestPaid = ...
    double interestPaid = paidBack - loanAmount;


    // Output the report here
    cout << "Loan Amount: $" << loanAmount << endl;
    cout << "Monthly Interest Rate: " << ratePercent << "%" << endl;
    cout << "Number of Payments: " << numMonths << endl;
    cout << "Monthly Payment: $" << monthlyPayment << endl;
    cout << "Amount Paid Back: $" << paidBack << endl;
    cout << "Interest Paid: $" << interestPaid << endl;

    return 0;
}
