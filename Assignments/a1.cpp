#include <bits/stdc++.h>
using namespace std;

class Gpay {
    int bankbalance = 0; //initialisation of the main amount as 0
    string name; // name of the user
    string phno; // phno of the user , we put phone no while making an account in Gpay
    int pwd; // password used for checking balance and tansactions

public:
    // seting an amount (a setter)
    void setamount(int a) {
        bankbalance = a;
    }
    // constructor for initialisation of phone number password and name
    Gpay() {
        cout << "Enter your phone number : ";
        cin >> phno;

        cout << endl << "Please set a password :";
        cin >> pwd;

        cout << endl << "Enter your name : ";
        cin >> name;

        cout << "Welcome to Google pay" << endl;
    }

    // for checking the details of any specific user
    void viewdetails(int psd) {
        if (pwd == psd) {
            cout << "\nGreetings " << name << endl;
            cout << "You have " << bankbalance << " in your account" << endl;
        }
        // if the password fails then it should not be shown
        else {
            cout << "Kindly check your phone number or password and try again";
        }
    }
    // this &other_obj is referencing any other existing object so that we can use that to deduct the amount sent from one object to another object
    // here way can only be either "IN" or "OUT" , in means the main object is recieving and the other object is sending and out means the main object is sending and the other object is recieving 
    void transaction(Gpay &other_obj, int amount, string way, int password) {
        //before any transaction happpens it asks for our password to checking the password if its right
        if (password == pwd) {

            if (way == "IN") {
                if (other_obj.bankbalance >= amount) {
                    bankbalance += amount;//coming to the main object so added
                    other_obj.bankbalance -= amount;//coming from the other object so deducting

                    cout << amount << " received successfully from " << other_obj.name;
                }
                else {
                    cout << "Not enough balance"; // if not enough balance is there so obviously transaction wont be continueing
                }
            }

            else if (way == "OUT") {
                bankbalance -= amount;//amount is going out from the main object so deducting
                other_obj.bankbalance += amount;//amountis coming from the main object to the other object so adding

                cout << amount << " sent successfully from " << other_obj.name;
            }
        }
        else {
            cout << "Incorrect password" << endl; // if the password is incorrect then transaction stops
        }
    }
    //destroying all the objects
    ~Gpay(){
        cout<<"Gpay account is deleted for "<<name<<endl;
    }
};

int main() {
    //making 5 objects
    Gpay g1, g2, g3, g4, g5;

    g1.setamount(5000);
    g2.setamount(10000);

    g1.transaction(g2, 10000, "IN", 1);

    g1.viewdetails(1);
    g2.viewdetails(2);
}