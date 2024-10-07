#include <iostream>
#include <exception>

class InsufficientFundsException : public std::exception {
    public:
        const char* what() const noexcept override {
            return "Insufficient funds";
        }
};

class InvalidOperationException : public std::exception {
    const char* what() const noexcept override {
        return "Invalid Operation";
    }
};

class BankAccount {
    public:
        BankAccount(double balance) : balance_(balance) {}

        void deposit(double amount) {
            if(amount <= 0) {
                throw InvalidOperationException();
            }
            balance_ += amount;
        }

        void withdraw(double amount) {
            if(amount <= 0 || amount > balance_) {
                throw InsufficientFundsException();
            }
            balance_ -= amount;
        }

        double getBalance() const {
            return balance_;
        }

    private:
        double balance_;
};

int main()
{
    BankAccount account(10000);

    try {
        account.deposit(20000);
        std::cout << "Balance after deposit: " << account.getBalance() << '\n';

        account.withdraw(1500);
        std::cout << "Balance after withdrawal: " << account.getBalance() << '\n';
    }
    catch(const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }

    return 0;
}