#include <iostream>
#include <iomanip>
#include <string>
// WORK OF Giogioanni Morales
class Investment {
private:
    double initialInvestmentAmount;   // Initial investment amount
    double monthlyDeposit;            // Monthly deposit amount
    double annualInterestRate;        // Annual interest rate as a decimal
    int numberOfYears;                // Number of years for the investment
    double finalBalanceWithMonthlyDeposit;  // Final balance with monthly deposits
    double finalBalanceWithoutMonthlyDeposit; // Final balance without monthly deposits

public:
    // Setters for private data members
    void setInitialInvestmentAmount(double amount) {
        initialInvestmentAmount = amount;
    }

    void setMonthlyDeposit(double deposit) {
        monthlyDeposit = deposit;
    }

    void setAnnualInterestRate(double interestRate) {
        annualInterestRate = interestRate;
    }

    void setNumberOfYears(int years) {
        numberOfYears = years;
    }

    // Getters for private data members
    double getInitialInvestmentAmount() const {
        return initialInvestmentAmount;
    }

    double getMonthlyDeposit() const {
        return monthlyDeposit;
    }

    double getAnnualInterestRate() const {
        return annualInterestRate;
    }

    int getNumberOfYears() const {
        return numberOfYears;
    }

    // Calculate balance with monthly deposits
    double calculateBalanceWithMonthlyDeposit() {
        double totalBalance = initialInvestmentAmount; // Start with initial investment
        for (int year = 1; year <= numberOfYears; ++year) {
            double interestEarnedThisYear = 0; // Reset interest earned for the year
            for (int month = 1; month <= 12; ++month) {
                double monthlyInterestRate = annualInterestRate / 12; // Monthly interest rate
                double interestEarned = totalBalance * monthlyInterestRate; // Interest for the month
                interestEarnedThisYear += interestEarned; // Accumulate yearly interest
                totalBalance = totalBalance + monthlyDeposit + interestEarned; // Update total balance
            }
            // Display end balance and interest earned for the year
            std::cout << "Year " << year << " - End Balance: $" << std::fixed << std::setprecision(2) << totalBalance;
            std::cout << " (Interest Earned: $" << std::fixed << std::setprecision(2) << interestEarnedThisYear << ")" << std::endl;
        }
        std::cout << "Total Balance with Monthly Deposits: $" << std::fixed << std::setprecision(2) << totalBalance << std::endl;
        finalBalanceWithMonthlyDeposit = totalBalance; // Store final balance
        return totalBalance;
    }

    // Calculate balance without monthly deposits
    double calculateBalanceWithoutMonthlyDeposit(double initialBalance, double annualInterestRate, int numYears) {
        double totalBalance = initialBalance; // Start with initial investment
        for (int year = 1; year <= numYears; ++year) {
            double interestEarnedThisYear = 0; // Reset interest earned for the year
            for (int month = 1; month <= 12; ++month) {
                double monthlyInterestRate = annualInterestRate / 12; // Monthly interest rate
                double interestEarned = totalBalance * monthlyInterestRate; // Interest for the month
                interestEarnedThisYear += interestEarned; // Accumulate yearly interest
                totalBalance += interestEarned; // Update total balance
            }
            // Display end balance and interest earned for the year
            std::cout << "Year " << year << " - End Balance: $" << std::fixed << std::setprecision(2) << totalBalance;
            std::cout << " (Interest Earned: $" << std::fixed << std::setprecision(2) << interestEarnedThisYear << ")" << std::endl;
        }
        std::cout << "Total Balance without Monthly Deposits: $" << std::fixed << std::setprecision(2) << totalBalance << std::endl;
        finalBalanceWithoutMonthlyDeposit = totalBalance; // Store final balance
        return totalBalance;
    }

    // Wrapper method to calculate the final balance without monthly deposits
    void calculateFinalBalanceWithoutMonthlyDeposit() {
        finalBalanceWithoutMonthlyDeposit = calculateBalanceWithoutMonthlyDeposit(initialInvestmentAmount, annualInterestRate, numberOfYears);
    }

    // Print details for a specific year
    void printDetails(int year, double balance, double interestEarned) {
        std::cout << "Year " << year << " - End Balance: $" << std::fixed << std::setprecision(2) << balance
            << " (Interest Earned: $" << std::fixed << std::setprecision(2) << interestEarned << ")" << std::endl;
    }

    // Display balances with and without monthly deposits
    void displayBalances() {
        std::cout << "Year-End Balances with Monthly Deposits:" << std::endl;
        calculateBalanceWithMonthlyDeposit(); // Calculate and display balance with deposits

        std::cout << "\nYear-End Balances without Monthly Deposits:" << std::endl;
        calculateFinalBalanceWithoutMonthlyDeposit(); // Calculate and display balance without deposits
    }

    // Validate user input to ensure values are within acceptable ranges
    bool validateInputs() {
        // Check if all input values are positive and the number of years is at least 1
        if (initialInvestmentAmount < 0 || monthlyDeposit < 0 || annualInterestRate < 0 || numberOfYears < 1) {
            std::cout << "Error: All input values must be positive and the number of years must be at least 1." << std::endl;
            return false; // Return false if any validation fails
        }
        return true; // Return true if all validations pass
    }
};

int main() {
    // Declare variables for user input
    double initialInvestmentAmount, monthlyDeposit, annualInterestRate;
    int numberOfYears;

    // Get inputs from the user with prompts
    std::cout << "Enter initial investment amount: $";
    std::cin >> initialInvestmentAmount;
    std::cout << "Enter monthly deposit amount: $";
    std::cin >> monthlyDeposit;
    std::cout << "Enter annual interest rate (in percentage): ";
    std::cin >> annualInterestRate;
    std::cout << "Enter number of years: ";
    std::cin >> numberOfYears;

    // Create an Investment object and set its properties
    Investment investment;
    investment.setInitialInvestmentAmount(initialInvestmentAmount);
    investment.setMonthlyDeposit(monthlyDeposit);
    investment.setAnnualInterestRate(annualInterestRate / 100); // Convert percentage to decimal
    investment.setNumberOfYears(numberOfYears);

    // Validate inputs before performing calculations
    if (investment.validateInputs()) {
        // If inputs are valid, calculate and display year-end balances
        investment.displayBalances();
    }

    return 0;
}
