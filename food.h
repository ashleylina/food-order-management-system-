// food.h
#pragma once

#include <iostream>
#include <string>

const int MAX_ITEMS = 10;  

class food {
protected:
    std::string name;
    double price;
    int quantity;

public:
    food(std::string itemName, double itemPrice, int itemQuantity);
    virtual std::string getName() const;
    virtual double getPrice() const;
    virtual int getQuantity() const;
    virtual void display() const;
    virtual double calculateTotalPrice() const;  
    virtual ~food();
};

class combo : public food {
private:
    food* item1;
    food* item2;

public:
    combo(food* item1, food* item2);
    double calculateTotalPrice() const override;
    void display() const override;
};

class alarcarte : public food {
private:
    double discount;

public:
    alarcarte(std::string itemName, double itemPrice, double discount, int itemQuantity);
    double getDiscount() const;
    double getPrice() const override;
    void display() const override;
};

class Order {
private:
    static const int MAX_ITEMS = 10;  
    food* items[MAX_ITEMS];
    int itemCount;

public:
    Order();
    Order(std::string itemName, double itemPrice, int itemQuantity);
    void addItem(food* item);
    double calculateTotalPrice() const;
    double calculateDiscountedPrice(double totalPrice) const;
    bool makePayment(double amountPaid);
    void displayOrder() const;
    int getItemCount() const;
    food* getItem(int index) const;
};
