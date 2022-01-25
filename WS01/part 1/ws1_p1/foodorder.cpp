#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "foodorder.h"
using namespace std;

double g_taxrate = 1;
double g_dailydiscount = 1;
namespace sdds {
	FoodOrder::FoodOrder()
	{
		m_name[0] = '\0';
		m_description[0] = '\0';
		m_price = 0.00;
		m_dailySpecial = false;
		//int counter = 0;
	}

	std::istream& FoodOrder::read(std::istream& istr)
	{
		if (!istr.fail()) {
			//istr >> m_name;
			//getline(istr, 
			//istr.get(m_name, 10, ',');
			istr.getline(m_name, 10, ',');
			istr.getline(m_description, 25, ',');
			istr >> m_price;
			istr.ignore();
			char ds_status = '\0';
			istr.get(ds_status);
			if (ds_status == 'Y') {
				m_dailySpecial = true;
			}
			else m_dailySpecial = false;
			//istr.getline(m_price, ',');
			//istr.ignore();
			//istr.get(m_price, 200, ',');
			//istr.ignore(200, ',');
		}
		return istr;
	}

	void FoodOrder::display() const
	{
		static int counter = 0;
		counter++;
		cout.setf(ios::left);
		cout.width(2);
		cout << counter;
		cout << ". ";
		if (m_name[0] != '\0') {
			cout.width(10);
			cout << m_name;
			cout << "|"; 
			cout.width(25);
			cout << m_description;
			cout << "|";
			cout.width(12);
			cout.setf(ios::fixed);
			cout.precision(2); 
			cout << m_price * (1 + g_taxrate);
			if (m_dailySpecial) {
				cout << "|";
				cout.width(13);
				cout.unsetf(ios::left);
				cout.precision(2); 
				cout << (m_price * g_taxrate) + (m_price - g_dailydiscount) << endl;
			}
			else cout << "|" << endl;
		}
		else cout << "No Order" << endl;
	}

	FoodOrder::~FoodOrder()
	{

	}
}