#include<iostream>
#include<string>

using std::cout;
using std::endl;
using std::string;

class Employee
{
private:
	string name;
	string street;
	string city;
	string postcode;
public:
	void Display();
	Employee();
	Employee(string nm, string st, string ci, string po);
	~Employee();
    void change_name(string n);
};

Employee::Employee()
{
	name = "Default";
	street = "Default st.";
	city = "Default city";
	postcode = "000000";
}

Employee::Employee(string nm, string st, string ci, string po)
{
	name = nm;
	street = st;
	city = ci;
	postcode = po;
}

Employee::~Employee()
{
	cout << "Employee's information cleared."<<endl;
}

void Employee::Display()
{
	cout << "Emlpoyee's information:" << endl;
	cout << "Name: " << name << endl;
	cout << "Street add.: " << street << endl;
	cout << "City: " << city << endl;
	cout << "Postcode: " << postcode << endl;
}

void Employee::change_name(string n)
{
	name = n;
}

int main()
{
	Employee emp[5];
	emp[1] = Employee();
	emp[1].Display();
	emp[2] = Employee("Jiang", "Chuangxin rd. 195", "Shenyang", "110000");
	emp[2].Display();
	emp[3] = Employee("Wang", "Chuangxin rd. 196", "Dalian", "111000");
	emp[3].Display();
	emp[4] = Employee("Zhang", "Chuangxin rd. 197", "Anshan", "112000");
	emp[4].Display();
	emp[5] = Employee("Liu", "Chuangxin rd. 198", "Fushun", "113000");
	emp[5].Display();
	emp[2].change_name ("Ming");
	emp[2].Display();
}