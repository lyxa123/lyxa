#include "Database.h"
#include "Company.h"
#include <iostream>
#include <string>
using namespace std;

/**
Add user input data to Database class
Pre: d - the Database object we want to store the items in
	 ticker - the company symbol
	 ceo - the company CEO surname
	 mcap - the company market cap in billion USD
	 sprice - the company stock price in USD
	 pchange - the company percentage change
Post: Add each datas to the Database class by using the add fuction from Database class 
Return:
*/
void add(Database &d, string ceo, string ticker, float mcap, float sprice, float pchange)
{
	d.add(ceo, ticker, mcap, sprice, pchange);
	cout << "Company Added Successfully!!" << endl;
}
/**
Remove all the data for a particular company
Pre: d - the Database object we want to clear the items from
	 ticker - the company symbol
Post: Remove a company's datas base on their Symbol(ticker) by calling the remove function from Datbase class
Return:
*/
void remove(Database &d, string ticker)
{
	d.remove(ticker);
}
/**
Convert a string to Upper case
Pre: in represents the string we want to convert to all capitalization 
Post: converts the string to its upper case by modifying the ASCII Value
Return: an capitalized version of the string variable
*/
string toUpper(string in)
{
	string ret = in;
	for (int i = 0; i < in.length(); i++)
	{
		if (ret[i] >= 97 && ret[i] <= 122)
			ret[i] -= 32;
	}
	return ret;
}

int main()
{
	cout << "Welcome to our Program!\nWhat would you like to do today?" << endl;
	string fileLoc = "C:\\Users\\lyxat\\Downloads\\Team_Project_22C_Fall2019 (1)\\Debug\\data.txt";
	string newFileLoc = "C:\\Users\\lyxat\\Downloads\\Team_Project_22C_Fall2019 (1)\\Debug\\newData.txt";
	int n;
	bool  cont = true;
	try
	{
		Database d(fileLoc, newFileLoc);

		while (cont)
		{
			cout << "1. Add Company\n"
				<< "2. Remove Company\n"
				<< "3. Search and Display a Company\n"
				<< "4. List Companies in hash table sequence\n"
				<< "5. List Companies in Alphabetical Order\n"
				<< "6. Print indented tree\n"
				<< "7. Efficiency\n"
				<< "8. Compare Companies\n"
				<< "9. Stock Purchase Simulator\n"
				<< "10. Quit\n";
			cin >> n;
			system("cls");
			if (n == 1) {
				cout << "ADD COMPANY" << endl;
				string ticker, ceo, sprice, mcap, pchange;
				float float_sprice, float_mcap, float_pchange;
				cout << "Enter the Stock Ticker: ";
				cin >> ticker;
				ticker = toUpper(ticker);
				cout << "Enter the CEO's last name: ";
				cin >> ceo;
				ceo = toUpper(ceo);
				bool invalidArgument = true;
				while (invalidArgument)
				{
					try {
						cout << "Enter the stock price: ";
						cin >> sprice;
						float_sprice = stof(sprice);
						cout << "Enter the market cap in billions: ";
						cin >> mcap;
						float_mcap = stof(mcap);
						cout << "Enter the percentage change: ";
						cin >> pchange;
						float_pchange = stof(pchange);
						add(d, ceo, ticker, float_mcap, float_sprice, float_pchange);
						invalidArgument = false;
					}
					catch (invalid_argument)
					{
						cout << "Invalid input!\n";
					}
				}
				
			}
			else if (n == 2) {
				cout << "REMOVE COMPANY" << endl;
				string ticker;
				cout << "Enter the Stock Ticker: ";
				cin >> ticker;
				ticker = toUpper(ticker);
				remove(d, ticker);
			}
			else if (n == 3) {
				cout << "SEARCH COMPANY" << endl;
				string ticker;
				cout << "Enter the Stock Ticker: ";
				cin >> ticker;
				ticker = toUpper(ticker);
				cout << endl;
				d.search(ticker);
			}
			else if (n == 4) {
				d.printhash();
			}
			else if (n == 5) {
				d.printkey();
			}
			else if (n == 6) {
				d.printTree();
			}
			else if (n == 7) {
				cout << "HASHTABLE EFFICIENCY" << endl;
				d.printEfficiency();
			}
			else if (n == 8) {
				cout << "COMPARE COMPANIES" << endl;
				string ticker1, ticker2;
				cout << "Enter the ticker of the first company: ";
				cin >> ticker1;
				ticker1 = toUpper(ticker1);
				cout << "Enter the ticker of the second company: ";
				cin >> ticker2;
				ticker2 = toUpper(ticker2);
				system("cls");
				d.compare(ticker1, ticker2);
			}
			else if (n == 9) {
				string ticker;
				int count;
				cout << "PURCHSE SIMULATOR" << endl;
				cout << "This module simulates what would have happened if you bought a certain stock on Nov 14th and sold it today.\n"; 
				cout << "Enter a ticker: ";
				cin >> ticker;
				cout << "How many did you buy: ";
				cin >> count;
				cout << endl;
				d.sim(toUpper(ticker), count);
			}
			else if (n == 10) {
				cout << "Thank you for using our program." << endl;
				cont = false;
				d.save(fileLoc);
				break;
			}
			else
				cout << "Please enter a valid menu option!" << endl;
			cout << endl;
		}

	}
	catch (const char* e)
	{
		cout << e << endl;
	}
	system("pause");
}



