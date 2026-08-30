#include <bits/stdc++.h>
using namespace std;

enum category {
    ELECTRONICS,
    STATIONERY,
    KITCHEN,
    PERSONAL_CARE,
    FURNITURE
};

string categoryName(category c) {
    if (c == ELECTRONICS) 
       {return "ELECTRONICS";}
    else if (c == STATIONERY) 
        {return "STATIONERY";}
    else if (c == KITCHEN) 
        {return "KITCHEN SUPPLIES";}
    else if (c == PERSONAL_CARE) 
        {return "PERSONAL_CARE";}   
    if (c == FURNITURE) 
        {return "FURNITURE";}
    return "Invalid";
}

class Product {
    string product_id;
    string name;
    float price;
    int stock;
    category cat;

    public:
        Product(string pid, string n, float prc, int stk, category c) {
            product_id = pid;
            name = n;
            price = prc;
            stock = stk;
            cat = c;
        }

        void displayproduct() {
            cout << "Product Id : " << product_id << endl << " Product name : " << name << endl
                 << "Product Price : " << price <<endl<< " Product's Stock : " << stock
                << endl << " Category : " << categoryName(cat) << endl;
        }

        void updateStock(int s) {
            stock = s;
        }

        void checkAvailability(string id) {
            if (product_id == id) {
                if (stock > 0) {
                    cout << "There are " << stock << " of " << name << " available" << endl;
                } else {
                    cout << "Not Available" << endl;
                }
            }
        }
};

class Customer {
    string customer_id;
    string name;
    string email;
    long long int phone_no;
    string address;

    public:
        Customer(string cid, string n, string mail, long long int phno, string addr) {
            customer_id = cid;
            name = n;
            email = mail;
            phone_no = phno;
            address = addr;
        }

        void viewdetails() {
            cout << "Customer id : " << customer_id << endl
                 << "Name : " << name << endl
                 << "Registered email address : " << email << endl
                 << "Registered Phone number : " << phone_no << endl
                 << "Address : " << address << endl;
        }

        void update_name(string newname) {
            name = newname;
        }
        void update_address(string newaddress) {
            address = newaddress;
        }
        void update_phonenum(long long int phno) {
            phone_no = phno;
        }
        void update_email(string mail) {
            email = mail;
        }
};

enum paymentstat {
    Accepted,
    Declined,
    Banned
};

enum orderstat {
    pending,
    confirmed,
    cancelled,
    failed
};

class Order {
    public:
        string order_id;
        string customer_id;
        float total_amt;
        paymentstat p;
        orderstat o;

        Order(string oid, string cid, float amt) {
            order_id = oid;
            customer_id = cid;
            total_amt = amt;
            p = Declined;
            o = pending;
        }

        void updateOrder(float amt) {
            total_amt = amt;
        }

        void confirmOrder() {
            p = Accepted;
            o = confirmed;
        }

        void cancelOrder() {
            o = cancelled;
        }

        void displayOrder() {
            cout << "Order Id : " << order_id << " Customer Id : " << customer_id
                 << " Total Amount : " << total_amt << endl;
        }
};

int main() {

}