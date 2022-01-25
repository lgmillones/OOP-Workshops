/* -----------------------------------------------------------------
OOP345 Workshop 1 - part 2
Filename: foodorder.cpp
Author: Lucia Geraldine Millones
Student ID: 131037186
Email: lgmillones@myseneca.ca
Section: NCC
Instructor: Hong Huang
Date : 01 / 23 / 2022
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-------------------------------------------------------------------- */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include "foodorder.h"
using namespace std;

double g_taxrate = 1;
double g_dailydiscount = 1;

namespace sdds {
	FoodOrder::FoodOrder()
	{
		m_name[0] = '\0';
		m_description = nullptr;
		m_price = 0.00;
		m_dailySpecial = false;
	}


	FoodOrder::FoodOrder(const FoodOrder& src)
	{
		m_name[0] = '\0';
		m_description = nullptr;
		m_price = 0.00;
		m_dailySpecial = false;
		*this = src;
	}

	FoodOrder& FoodOrder::operator=(const FoodOrder& src)
	{
		if (this != &src) {
			delete[] m_description;
			m_description = nullptr;
			m_price = src.m_price;
			m_dailySpecial = src.m_dailySpecial;
			strcpy(m_name, src.m_name);
			if (src.m_description) {
				m_description = new char[strlen(src.m_description) + 1];
				strcpy(m_description, src.m_description);
			}
		}
		return *this;
	}

	std::istream& FoodOrder::read(std::istream& istr)
	{
		if (!istr.fail()) {	
			istr.getline(m_name, 10, ',');
			string str = " ";
			getline(istr, str, ',');
			delete[]m_description;
			m_description = new char[str.length() + 1];
			strcpy(m_description, str.c_str());
			istr >> m_price;
			istr.ignore();
			char ds_status = '\0';
			istr.get(ds_status);
			if (ds_status == 'Y') {
				m_dailySpecial = true;
			}
			else m_dailySpecial = false;
		}
		else {
			delete[] m_description;
			m_description = nullptr;
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
		delete[] m_description;
	}
}