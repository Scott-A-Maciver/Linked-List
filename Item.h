// Name:Scott Maciver
// Seneca Student ID:102205184
// Seneca email:smaciver1@myseneca.ca
// Date of completion:2019-11-30
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef _ITEM_SDDS_H
#define _ITEM_SDDS_H

#include <iostream>
#include <string>

//namespace sdds {
	class Item {
		std::string m_name;
		std::string m_description;
		unsigned int m_serialNumber;
		unsigned int m_quantity;
		static size_t m_widthField;

	public:
		Item();
		Item(const std::string record);
		const std::string& getName() const;
		const unsigned int getSerialNumber();
		const unsigned int getQuantity();
		void updateQuantity();
		void display(std::ostream& os, bool full) const;
	};
//}

#endif