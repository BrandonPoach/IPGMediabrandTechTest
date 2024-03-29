// Back-End Technical Test.cpp by Brandon Poetsch
//

#include "stdafx.h"

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//Initialise Functions
void WelcomeMessage();
int GetGrossIncome(int);
int GetIncomeTax(int);
int GetNetIncome(int, int);
int GetSuper(int, float);

int main()
{
	bool end = false;
	WelcomeMessage();
	do {
		//Input Variables
		string first_name, last_name, start_date, end_date;
		int salary = 0;
		float super_rate = 0;
		char yn;

		//Output Variables
		int gross_income = 0, income_tax = 0, net_income = 0, super = 0;

		//Input Values Manually
		cout << "__________________________________________________________________________________________\n\n" << endl;
		cout << "Input: ";
		getline(cin, first_name, ',');
		getline(cin, last_name, ',');
		cin >> salary;
		cin.ignore();
		cin >> super_rate;
		cin.ignore();
		getline(cin, start_date, ',');
		getline(cin, end_date, '\n');

		//Remove any white spaces from Strings
		first_name.erase(remove(first_name.begin(), first_name.end(), ' '), first_name.end());
		last_name.erase(remove(last_name.begin(), last_name.end(), ' '), last_name.end());

		//Perform Calculation Functions
		gross_income = GetGrossIncome(salary);

		income_tax = GetIncomeTax(salary);

		net_income = GetNetIncome(gross_income, income_tax);

		super = GetSuper(gross_income, super_rate);

		//Output Results
		cout << "Here are your Results" << endl;
		cout << "Name: " << first_name << " " << last_name << endl;
		cout << "Pay Period: " << start_date << " - " << end_date << endl;
		cout << "Gross Monthly Income: $" << gross_income << endl;
		cout << "Income Tax: $" << income_tax << endl;
		cout << "Net Monthly Income: $" << net_income << endl;
		cout << "Super: $" << super << endl;

		cout << "Enter another input? (y/n)" << endl;
		cin >> yn;
		cin.ignore();

		if (yn == 'n') {
			end = true;
		}
	} while (end == false);

	system("pause");
    return 0;
}

void WelcomeMessage() {
	cout << "Hello Employee!" << endl;
	cout << "Please enter your First Name, Last Name, Annual Salary (No $ Sign), Super Rate (No % Sign), Payment Start Date and End Date" << endl;
	cout << "Example: 'Andrew,Smith,60050,9,01 March,31 March'" << endl;
	cout << "All values need to be separated by commas" << endl;
}

int GetGrossIncome(int salary) {
	return (salary / 12);
}

int GetIncomeTax(int salary) {
	//Tax Table
	if (salary <= 18200) {
		return 0; //Nil
	}
	else if (salary > 18200 && salary <= 37000) {
		return ((salary - 18200)*0.19); //19c for each $1 over $18,200
	}
	else if (salary > 37000 && salary <= 87000) {
		return ((salary - 37000)*0.325 + 3572); //$3,572 plus 32.5c for each $1 over $37,000
	}
	else if (salary > 87000 && salary <= 180000) {
		return ((salary - 87000)*0.37 + 19822); //$19,822 plus 37c for each $1 over $87,000
	}
	else //If $180,001 and over
	{
		return ((salary - 180000)*0.45 + 54232); //$54,232 plus 45c for each $1 over $180,000
	}
}

int GetNetIncome(int gross_income, int income_tax) {
	return (gross_income - (income_tax/12));
}

int GetSuper(int gross_income, float super_rate) {
	return (gross_income * (super_rate/12));
}



