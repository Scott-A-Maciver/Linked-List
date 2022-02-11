// Name:Scott Maciver
// Seneca Student ID:102205184
// Seneca email:smaciver1@myseneca.ca
// Date of completion:2019-11-30
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef _SDDS_CUSTOMERORDER_H
#define _SDDS_CUSTOMERORDER_H
#include <string>
#include <iostream>
#include "Item.h"
struct ItemInfo;

class CustomerOrder {
	std::string m_name;
	std::string m_product;
	unsigned int m_cntItem;
	ItemInfo** m_lstItem;
	static size_t m_widthField;

public:
	CustomerOrder();
	CustomerOrder(std::string);
	CustomerOrder(const CustomerOrder&);
	CustomerOrder(CustomerOrder&&) noexcept;
	~CustomerOrder();
	CustomerOrder& operator=(CustomerOrder&) = delete;
	CustomerOrder& operator=(CustomerOrder&&);
	bool getItemFillState(std::string ) const;
	bool getOrderFillState() const;
	void fillItem(Item& item, std::ostream&);
	void display(std::ostream&) const;
};

struct ItemInfo
{
	std::string m_itemName;
	unsigned int m_serialNumber = 0;
	bool m_fillState = false;

	ItemInfo(std::string src) : m_itemName(src) {};
};
#endif
