// Name:Scott Maciver
// Seneca Student ID:102205184
// Seneca email:smaciver1@myseneca.ca
// Date of completion:2019-11-30
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include "Utilities.h"
#include <iostream>
#include <string>

char Utilities::m_delimeter;

void Utilities::setFieldWidth(size_t size)
{
	Utilities::m_widthField = size;
}

size_t Utilities::getFieldWidth() const
{
	return m_widthField;
}

const std::string Utilities::extractToken(const std::string & str, size_t & next_pos, bool & more)
{
	std::string tmp;
	std::string err = "no valid token";
	size_t find;
	tmp = str.substr(next_pos);
	find = tmp.find_first_of(m_delimeter, 0);

	if (find == 0) {
		throw err;
	}
	tmp = tmp.substr(0, find);
	if (tmp[0] != '\0') {
		more = true;
	}
	else {
		more = false;
	}

	setFieldWidth(tmp.size());
	return tmp;
}

void Utilities::setDelimiter(const char delim)
{
	m_delimeter = delim;
}

const char Utilities::getDelimiter() const
{
	return m_delimeter;
}
