// Name:Scott Maciver
// Seneca Student ID:102205184
// Seneca email:smaciver1@myseneca.ca
// Date of completion:2019-11-30
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include "CustomerOrder.h"
#include "Utilities.h"
#include "Item.h"
#include <iostream>
#include <iomanip>
#include <vector>

size_t CustomerOrder::m_widthField;

CustomerOrder::CustomerOrder() : m_name(), m_product(), m_lstItem{ nullptr }
{
	m_cntItem = 0;
}

CustomerOrder::CustomerOrder(std::string dat)
{
	Utilities util;
	size_t extractFrom = 0;
	bool more = true;
	std::string tmp;
	ItemInfo **tmpItem;
	tmpItem = new ItemInfo*[20];
	size_t i = 0;
	m_cntItem = 0;


	try {
		m_name = util.extractToken(dat, extractFrom, more);
		extractFrom += (m_name.length() + 1);
		m_product = util.extractToken(dat, extractFrom, more);
		extractFrom += (m_product.length() + 1);
		while (extractFrom != dat.size() + 1) {
			tmp = util.extractToken(dat, extractFrom, more);
			extractFrom += (tmp.length() + 1);
			tmpItem[i] = new ItemInfo(tmp);
			m_cntItem++;
			i++;
		}
		m_lstItem = new ItemInfo*[m_cntItem];
		m_lstItem = tmpItem;

	}
	catch (std::string) {

	}
	if (CustomerOrder::m_widthField < util.getFieldWidth()) {
		CustomerOrder::m_widthField = util.getFieldWidth();
	}
}

CustomerOrder::CustomerOrder(const CustomerOrder &src)
{
	throw "deleted";
}

CustomerOrder::CustomerOrder(CustomerOrder &&src) noexcept : m_name(), m_product(), m_lstItem{nullptr}
{
	*this = std::move(src);
}

CustomerOrder::~CustomerOrder()
{
	delete[] m_lstItem;
}

CustomerOrder & CustomerOrder::operator=(CustomerOrder &&src)
{
	if (this != &src) {
		if (m_lstItem != nullptr) {
			delete[] m_lstItem;
		}

		m_name = src.m_name;
		m_product = src.m_product;
		m_cntItem = src.m_cntItem;
		m_widthField = src.m_widthField;
		m_lstItem = new ItemInfo*[m_cntItem];

		m_lstItem = src.m_lstItem;
		src.m_lstItem = nullptr;
	}
	return *this;
}

bool CustomerOrder::getItemFillState(std::string item) const
{
	for (size_t i = 0; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_itemName == item) {
			return m_lstItem[i]->m_fillState;
		}
	}
	return true;
}

bool CustomerOrder::getOrderFillState() const
{
	for (size_t i = 0; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_fillState == false) {
			return false;
		}
	}
	return true;
}

void CustomerOrder::fillItem(Item& item, std::ostream& os)
{
	for (size_t i = 0; i < m_cntItem; i++) {
		if (item.getName() == m_lstItem[i]->m_itemName) {
			if (item.getQuantity() <= 0) {
				os << "Unable to fill " << item.getName() << ", PRODUCT[" << item.getName() << "]" << std::endl;
			}
			else {
				item.updateQuantity();
				m_lstItem[i]->m_serialNumber = item.getSerialNumber();
				m_lstItem[i]->m_fillState = true;
				os << "Filled " << m_name << ", " << m_product << "[" << item.getName() << "]" << std::endl;
			}
		}
	}
}

void CustomerOrder::display(std::ostream& os) const
{
	os << m_name << " - " << m_product << std::endl;
	for (size_t i = 0; i < m_cntItem; i++) {
		os << "[";
		os << std::right;
		os << std::setfill('0') << std::setw(6) << m_lstItem[i]->m_serialNumber;
		os << "] ";
		os << std::setfill(' ');
		os << std::left;
		os << std::setw(CustomerOrder::m_widthField) << m_lstItem[i]->m_itemName;
		os << "     - ";
		if (m_lstItem[i]->m_fillState == true) {
			os << "FILLED" << std::endl;
		}
		else {
			os << "MISSING" << std::endl;
		}
	}
}
