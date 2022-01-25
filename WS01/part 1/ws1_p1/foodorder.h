#ifndef SDDS_FOODORDER_H
#define SDDS_FOODORDER_H


extern double g_taxrate;
extern double g_dailydiscount;

namespace sdds {
	class FoodOrder
	{
		char m_name[10];
		char m_description[25];
		double m_price;
		bool m_dailySpecial;
	public:
		FoodOrder();
		std::istream& read(std::istream& istr);
		void display() const;
		~FoodOrder();
	};
}

#endif // !SDDS_FOODORDER_H

