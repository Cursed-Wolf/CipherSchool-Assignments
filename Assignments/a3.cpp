#include <bits/stdc++.h>
using namespace std;

class Employee{
    int EmpId;
    string name;
    string Department;
    double base_salary;
    public:
        //no data is given
        Employee(){
            EmpId = -1;
            name="\0";
            Department="Unassigned";
            base_salary=0.00;
            cout<<"Empty Employee created "<<endl<<"Name : "<<name<<"\nEmployee Id : "<<EmpId<<"\nDepartment : "<<Department<<"\nSalary : "<<base_salary<<endl;
        }
        // a little data is given mainly name and id
        Employee(int id,string name){
            this->name=name;
            EmpId=id;
            Department="Unassigned";
            base_salary=0.00;
            cout<<"Employee created with missing data "<<endl<<"Name : "<<name<<"\nEmployee Id : "<<EmpId<<"\nDepartment : "<<Department<<"\nSalary : "<<base_salary<<endl;
        }

        //whole data is given properly
        Employee(int Empid, string name,string Dept,double salary){
            this->base_salary=salary;
            Department=Dept;
            this->name=name;
            EmpId=Empid;
            cout<<"Employee created "<<endl<<"Name : "<<name<<"\nEmployee Id : "<<EmpId<<"\nDepartment : "<<Department<<"\nSalary : "<< base_salary <<endl;
        }

        //need to dublicate a employee using an exisiting employee though the employee id should vary but the problem statement asked us to copy all the data so here it is ...
        Employee(Employee &other_employee){//here &other_employee is someothere object we would be using in the main function
            base_salary=other_employee.base_salary;
            EmpId=other_employee.EmpId;
            Department=other_employee.Department;
            name=other_employee.name;
            cout<<"Employee created (dublicate) "<<endl<<"Name : "<<name<<"\nEmployee Id : "<<EmpId<<"\nDepartment : "<<Department<<"\nSalary : "<< base_salary <<endl;
        }

        double calculatePay(){
            return base_salary;
        }
        double calculatePay(double Bonus){
            return base_salary+Bonus;
        }
        int calculatePay(int hours_worked, int hourly_rate){
            return base_salary+(hours_worked*hourly_rate);
        }
        double calculatePay(double Bonus_amount, int tax_percentage) {
            double total = base_salary + Bonus_amount;
            return total - (total * tax_percentage / 100);
        }

        void updateProfile(int salary){
            base_salary=salary;
            cout<<"Base salary updated Successfully"<<endl;
        }  
        void updateProfile(string Department){
            this->Department=Department;
            cout<<"Department updated Successfully"<<endl;
        }
        void updateProfile(int salary,string Department){
            base_salary=salary;
            this->Department=Department;
            cout<<"Salary and department updated Successfully"<<endl;
        }

};

int main() {

    Employee e1;
    Employee e2(101, "Adarsh");
    Employee e3(102, "Rahul", "IT", 50000);
    Employee e4(e3);

    cout << e3.calculatePay() << endl;
    cout << e3.calculatePay(5000.0) << endl;
    cout << e3.calculatePay(10, 200) << endl;
    cout << e3.calculatePay(5000.0, 10) << endl;

    e3.updateProfile("HR");
    e3.updateProfile(60000);
    e3.updateProfile(70000, "Finance");

    return 0;
}