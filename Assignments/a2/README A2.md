E-Commerce Order Management System
Product class :
    A class to hold product info . Category is an enum so it's restricted to valid values only. It has functions to display product details, update stock, and check if a product is available or not.
Customer class:
    A class for customer records (ID, name, email, phone, address), with functions to view and update the details.
Order Struct :
    It is made for storing order ID, customer ID, total amount, and two enums for order status and payment status. It handles creating, updating, confirming, cancelling, and displaying orders.
Payment enum:
    A PaymentMethod enum which has CREDIT_CARD / UPI / CASH paired with a union. I used a union here because at any given time we only need one piece of payment info either last-4 card digits or a UPI ID, so no point storing both union saves memory since it doesn't need separate space for each.
All the five scenarios given in the problem statement which are as follows
    Product out of stock
    Invalid product/customer ID
    Cancelling a delivered order
    Payment for a cancelled order
    Confirming an order with failed payment
are handled .

Things which are being done in the main function :
    Creates a few products and prints their details, then checks availability including one invalid ID to show the error handling done.
    Creates a customer, views their details, updates a few fields, views again to check if they were updated or not.
    Creates an order, tries to confirm it before paying ,it should fail, pays using credit card, then confirms.
    Updates the order amount and displays it.
    Creates another order, cancels it, then tries to pay for it anyway to check if the order is failed are we still able to pay for the cancelled order it should fail.
    Creates a third order, marks it delivered, then tries to cancel it , it should fail.

How to run the code:
    Compile it using : g++ -std=c++17 main.cpp -o ecommerce
    Then run it using : ./ecommerce
    While running, if it asks for credit card or UPI details during payment, just type something when prompted.