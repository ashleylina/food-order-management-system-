// food.cpp
#include "food.h"
using namespace std;

// Implementation OF CLASSES
//FOOD CLASS IMPLEMENTATION
food::food(string itemName, double itemPrice, int itemQuantity)
    : name(itemName), price(itemPrice), quantity(itemQuantity) {}

string food::getName() const {
    return name;
}

double food::getPrice() const {
    return price * quantity;
}

int food::getQuantity() const {
    return quantity;
}

void food::display() const {
    cout << "Name: " << name << "\n";
    cout << "Price per item: RM " << price << "\n";
    cout << "Quantity: " << quantity << "\n";
    cout << "Total Price: RM " << getPrice() << "\n";
}

double food::calculateTotalPrice() const {
    return getPrice();
}

food::~food() {}

//COMBO CLASS INITIALIZATION
combo::combo(food* item1, food* item2) : food("Combo", 0.0, 1), item1(item1), item2(item2) {}

double combo::calculateTotalPrice() const {
    return item1->calculateTotalPrice() + item2->calculateTotalPrice();
}

void combo::display() const {
    cout << "Combo:\n";
    cout << "Item 1:\n";
    item1->display();
    cout << "Item 2:\n";
    item2->display();
    cout << "Total Price: RM " << calculateTotalPrice() << "\n";
}

//ALARCARTE CLASS INITIALIZATION
alarcarte::alarcarte(string itemName, double itemPrice, double discount, int itemQuantity)
    : food(itemName, itemPrice, itemQuantity), discount(discount) {}

double alarcarte::getDiscount() const {
    return discount;
}

double alarcarte::getPrice() const {
    return (food::getPrice() - discount) * food::getQuantity();
}

void alarcarte::display() const {
    cout << "Alar Carte:\n";
    food::display();
    cout << "Discount: RM " << getDiscount() << "\n";
}
//ORDER CLASS INITIALIZATION
Order::Order() : itemCount(0) {}

void Order::addItem(food* item) {
    if (itemCount < MAX_ITEMS) {
        items[itemCount++] = item;
    }
    else {
        cout << "Cannot add more items. Maximum limit reached.\n";
    }
}

int Order::getItemCount() const {
    return itemCount;
}

food* Order::getItem(int itemPosition) const {
    if (itemPosition >= 0 && itemPosition < itemCount) {
        return items[itemPosition];
    }
    else {
        cout << "Invalid item position.\n";
        return nullptr;
    }
}

double Order::calculateTotalPrice() const {
    double totalPrice = 0.0;

    for (int i = 0; i < itemCount; ++i) {
        totalPrice += items[i]->calculateTotalPrice();
    }

    return totalPrice;
}

double Order::calculateDiscountedPrice(double totalPrice) const {
    const double DISCOUNT_PRICE = 30.0;
    const double DISCOUNT_PERCENTAGE = 0.20;

    if (totalPrice > DISCOUNT_PRICE) {
        return totalPrice - (totalPrice * DISCOUNT_PERCENTAGE);
    }

    return totalPrice;
}

bool Order::makePayment(double amountPaid) {
    double total = calculateTotalPrice();
    double discountedTotal = calculateDiscountedPrice(total);

    return amountPaid >= discountedTotal;
}

void Order::displayOrder() const {
    cout << "Order Details:\n";

    for (int i = 0; i < itemCount; ++i) {
        items[i]->display();
        cout << "------------------------\n";
    }
}
