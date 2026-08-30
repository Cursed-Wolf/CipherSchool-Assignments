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
                    cout << "Out Of Stock" << endl;
                }
            }
            else{
                cout<<"Invalid product id"<<endl;
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

        void viewdetails(string cus_id) {
            if(customer_id==cus_id){
                cout << "Customer id : " << customer_id << endl
                    << "Name : " << name << endl
                    << "Registered email address : " << email << endl
                    << "Registered Phone number : " << phone_no << endl
                    << "Address : " << address << endl;
                }
            else{
                cout<<"Invalid customer id"<<endl;
            }
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
    failed,
    delivered
};

enum PaymentMethod {
    CREDIT_CARD,
    UPI,
    CASH
};

union Paymentinfo{
    char ar_last4digit_cc[5];
    char upi_id[100];
};

struct Order {
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

    void cancelorder(string oid){
        if(order_id==oid){
            if(o==delivered){
                cout<<"Cant cancel the order as its already delivered "<<endl;
            }
            else{
                o=cancelled;
                cout<<"Your order has been canceled"<<endl;
            }
        }else{
            cout<<"Invalid order id"<<endl;
        }
    }


    void updateOrder(float amt) {
        total_amt = amt;
    }

    void confirmOrder() {
        if(p!=Accepted){
            cout<<"Order cant be confirmed until payment is confirmed"<<endl;
        }
        else{
            o=confirmed;
            cout<<"Your Order is confirmed"<<endl;
        }
    }

    void displayOrder() {
        cout << "Order Id : " << order_id << " Customer Id : " << customer_id
             << " Total Amount : " << total_amt << endl;
    }

    void makepayemnt(PaymentMethod pm){
        Paymentinfo inf;
        if(o==failed || o==cancelled){
            cout<<"Payment cant be made for failed or cancelled order "<<endl;
        }
        else{
            if(pm==CREDIT_CARD){
                cout<<"Kindly enter the last 4 digit of your credit card : ";
                cin>>inf.ar_last4digit_cc;
                if(strlen(inf.ar_last4digit_cc)==4){
                    cout<<"Credit card validated successfully!!"<<endl;
                    p=Accepted;}
                else{
                    cout<<"Invalid Credit card details !"<<endl;
                    p=Declined;
                }
                
            }
            else if(pm==UPI){
                cout<<"Kindly enter your UPI ID :";
                cin>>inf.upi_id;
                cout<<"UPI Id validated successfully!!"<<endl;
                p=Accepted;
            }
            else if(pm==CASH){
                cout<<"Kindly use Cash!!"<<endl;
                p=Accepted;
            }
            else{
                cout<<"Something went wrong";
            }
        }
    }
};

int main() {

    Product p1("P101", "Laptop", 55000, 5, ELECTRONICS);
    Product p2("P102", "Notebook", 50, 0, STATIONERY);
    Product p3("P103", "Mixer", 3000, 3, KITCHEN);

    p1.displayproduct();
    cout << endl;
    p2.displayproduct();
    cout << endl;
    p3.displayproduct();
    cout << endl;

    p1.checkAvailability("P101");
    p2.checkAvailability("P102");
    p1.checkAvailability("P999");

    cout << endl;

    Customer c1(
        "C101",
        "Adarsh",
        "adarsh@gmail.com",
        9876543210,
        "Delhi"
    );

    c1.viewdetails("C101");
    cout << endl;

    c1.update_name("Adarsh Kumar");
    c1.update_address("Phagwara");
    c1.update_email("axa@gmail.com");
    c1.update_phonenum(9876501234);

    c1.viewdetails("C101");
    c1.viewdetails("C999");

    cout << endl;

    Order o1("O101", "C101", 55000);

    o1.displayOrder();
    cout << endl;

    o1.confirmOrder();
    cout << endl;

    o1.makepayemnt(CREDIT_CARD);
    o1.confirmOrder();

    cout << endl;

    o1.updateOrder(60000);
    o1.displayOrder();

    cout << endl;

    Order o2("O102", "C101", 3000);
    o2.cancelorder("O102");
    o2.makepayemnt(UPI);

    cout << endl;

    Order o3("O103", "C101", 50000);
    o3.o = delivered;
    o3.cancelorder("O103");

    return 0;
}