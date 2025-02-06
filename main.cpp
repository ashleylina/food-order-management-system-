#include <iostream>
#include "food.h"

using namespace std;

int main() {
    cout << "    THE RESTAURANT ORDER MANAGEMENT SYSTEM : ))" << endl;
    cout << "" << endl;
    cout << "----- BUY MORE RM30 TO GET 20% DISCOUNT------" << endl;

    Order order;

    char choice;
    int counter = 0;

    do {
        cout << "Menu:\n";
        cout << "1. Cheeseburger (RM 10.00)\n";
        cout << "2. Cola (RM 2.50)\n";
        cout << "3. Chicken Burger (RM 12.00)\n";
        cout << "4. Lemonade (RM 3.00)\n";

        alarcarte burger("Cheeseburger", 10.00, 0.00, 1);
        alarcarte soda("Cola", 2.50, 0.00, 1);
        alarcarte chickenBurger("Chicken Burger", 12.00, 0.00, 1);
        alarcarte lemonade("Lemonade", 3.00, 0.00, 1);

        cout << "5.COMBO DEALS : Meal Combo 1 (Cheeseburger + Cola) - RM 12.50\n";
        cout << "6.COMBO DEALS : Meal Combo 2 (Chicken Burger + Lemonade) - RM 14.00\n";
        cout << "Enter your choice (1-6): ";

        int menuChoice;
        cin >> menuChoice;

        // Process user's choice
        food* newItem = nullptr;

        switch (menuChoice) {
        case 1:
            newItem = new alarcarte("Cheeseburger", 10.00, 0.00, 1);
            break;
        case 2:
            newItem = new alarcarte("Cola", 2.50, 0.00, 1);
            break;
        case 3:
            newItem = new alarcarte("Chicken Burger", 12.00, 0.00, 1);
            break;
        case 4:
            newItem = new alarcarte("Lemonade", 3.00, 0.00, 1);
            break;
        case 5:
            newItem = new combo(&burger, &soda);
            break;
        case 6:
            newItem = new combo(&chickenBurger, &lemonade);
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 6.\n";
            continue;
        }

        order.addItem(newItem);
        ++counter;

        if (counter < MAX_ITEMS) {
            cout << "Do you want to order more? (y/n): ";
            cin >> choice;
        }
        else {
            cout << "Maximum order limit reached. Proceeding to payment.\n";
            choice = 'n';
        }

    } while (choice == 'y' || choice == 'Y');

    order.displayOrder();
    double totalPrice = order.calculateTotalPrice();
    double discountedTotal = order.calculateDiscountedPrice(totalPrice);

    cout << "Total Price: RM " << totalPrice << "\n";
    cout << "Discounted Total Price: RM " << discountedTotal << "\n";

    double amountPaid;
    bool paymentSuccessful = false;

    do {
        cout << "Enter the amount you want to pay: RM ";
        cin >> amountPaid;

        if (amountPaid >= totalPrice) {
            double balance = amountPaid - discountedTotal;
            cout << "Payment successful !! :  Balance: RM " << balance << "\n";
            cout << "Thank you!\n";
            paymentSuccessful = true;
        }
        else {
            cout << "....Insufficient payment....   : (( \n";
        }

    } while (!paymentSuccessful);

    for (int i = 0; i < order.getItemCount(); ++i) {
        delete order.getItem(i);
    }

    return 0;
}
