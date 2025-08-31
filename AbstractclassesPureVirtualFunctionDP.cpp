
#include<iostream>
#include<vector>
#include<memory>

//abstract class
class Payment{
    public:
    virtual void processPayment(double amount) const = 0;  // Pure virtual function
    virtual ~Payment() = default; //virtual destructor


};
class CreditCard : public Payment{
    public:
    void processPayment(double amount) const override{
        std::cout << "Processing credit card payment of $" << amount << "\n";
    }

};
class PayPal : public Payment{
    public:
    void processPayment(double amount) const override {
        std::cout << "Processing PayPal payment of $" << amount << "\n";
    }
};

class BankTransfar : public Payment{
    public:
     void processPayment(double amount) const override {
        std::cout << "Processing bank transfer of $" << amount << "\n";
    }
};

int main(){
     
    std::vector<std::unique_ptr<Payment>> payments;

    payments.push_back(std::make_unique<CreditCard>());
    payments.push_back(std::make_unique<PayPal>());
    payments.push_back(std::make_unique<BankTransfar>());

    for(const auto& payment : payments){
        payment->processPayment(100.0);
        
    }
}