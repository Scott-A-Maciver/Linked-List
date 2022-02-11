// Name:Scott Maciver
// Seneca Student ID:102205184
// Seneca email:smaciver1@myseneca.ca
// Date of completion:2019-11-30
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include "Item.h"
#include "Utilities.h"
#include <iostream>
#include <iomanip>
#include <string>

size_t Item::m_widthField;

Item::Item() {
	m_widthField = 1;
	m_description = "";
	m_name = "";
	m_quantity = 0;
	m_serialNumber = 0;
}

Item::Item(const std::string record)
{
	std::string err = "no valid token";
	Utilities util;
	size_t extractFrom = 0;
	std::string tmp;
	std::string::size_type sz;
	bool more = true;
	try {
		m_name = util.extractToken(record, extractFrom, more);
		extractFrom = (m_name.length() + 1);
		tmp = util.extractToken(record, extractFrom, more);
		m_serialNumber = std::stoi(tmp, &sz);
		extractFrom += (tmp.length() + 1);
		tmp = util.extractToken(record, extractFrom, more);
		m_quantity = std::stoi(tmp, &sz);
		extractFrom += (tmp.length() + 1);
		m_description = util.extractToken(record, extractFrom, more);
	}
	catch(std::string) {

	}
	m_widthField = m_name.length();
}

const std::string & Item::getName() const
{
	return m_name;
}

const unsigned int Item::getSerialNumber()
{
	unsigned int tmp = m_serialNumber;
	m_serialNumber++;
	return tmp;
}

const unsigned int Item::getQuantity()
{
	return m_quantity;
}

void Item::updateQuantity()
{
	if (m_quantity > 0) {
		m_quantity -= 1;
	}
}

void Item::display(std::ostream& os, bool full) const
{
	os << std::setw(m_widthField) << std::left << m_name;
	os << " [";
	os << std::right;
	os << std::setfill('0') << std::setw(6) << m_serialNumber;
	os << "]";
	os << std::setfill(' ');

	if (full == false) {
		os << std::endl;
	}
	else {
		os << " Quantity: "; 
		os << std::left;
		os << std::setw(m_widthField) << m_quantity;
		os << std::right;
		os << " Description: " << m_description << std::endl;
	}
}
