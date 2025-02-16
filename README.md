Food Order Management System
A C++ program that allows users to order food, select combo deals, and get discounts based on total purchase amount. The system calculates the total price, applies discounts, and handles payment processing.

Features
Order Ala Carte or Combo Meals.
20% discount for orders above RM30.
Calculates total price, discount, and payment balance.
Handles multiple items in a single order.
Displays order details before payment.
How to Use
Clone the repository
git clone https://github.com/ashleylina/food-order-management-system-.git
cd food-order-management-system

Compile the program
g++ main.cpp food.cpp -o food_order

Run the program
./food_order

Example Usage
----- BUY MORE RM30 TO GET 20% DISCOUNT ------
Menu:
1. Cheeseburger (RM 10.00)
2. Cola (RM 2.50)
5. Meal Combo 1 (Cheeseburger + Cola) - RM 12.50
Enter choice: 5
Do you want to order more? (y/n): y
Enter choice: 1
Do you want to order more? (y/n): n
Total Price: RM 22.50
Discounted Price: RM 22.50
Enter payment amount: RM 25
Payment successful! Balance: RM 2.50
Thank you!
File Descriptions
main.cpp – Handles user input, menu selection, and order processing.
food.h – Defines food-related classes (food, combo, alarcarte, Order).
food.cpp – Implements the functionality for food items and pricing.
License
This project is open-source and free to use.

Contact
Created by Ashleylina
Feel free to reach out with any questions or improvements!
