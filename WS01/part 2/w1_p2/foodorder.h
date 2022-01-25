/* -----------------------------------------------------------------
OOP345 Workshop 1 - part 2
Filename: foodorder.h
Author: Lucia Geraldine Millones
Student ID: 131037186
Email: lgmillones@myseneca.ca
Section: NCC
Instructor: Hong Huang
Date : 01 / 23 / 2022
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-------------------------------------------------------------------- */
#ifndef SDDS_FOODORDER_H
#define SDDS_FOODORDER_H

extern double g_taxrate;
extern double g_dailydiscount;

namespace sdds {
	class FoodOrder
	{
		char m_name[10];
		char* m_description;
		double m_price;
		bool m_dailySpecial;
	public:
		FoodOrder();
		std::istream& read(std::istream& istr);
		void display() const;
		FoodOrder(const FoodOrder& src);
		FoodOrder& operator=(const FoodOrder& src);
		~FoodOrder();
	};
}

#endif // !SDDS_FOODORDER_H

