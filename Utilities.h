// Name:Scott Maciver
// Seneca Student ID:102205184
// Seneca email:smaciver1@myseneca.ca
// Date of completion:2019-11-30
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef _UTILITIES_SDDS_H
#define _UTILITIES_SDDS_H

#include <iostream>

//namespace sdds { Removed because tester does not use sdds namespace but leaving it in here for future proofing purposes
	class Utilities {
		size_t m_widthField = 1;
		static char m_delimeter;

	public:
		void setFieldWidth(size_t size);
		size_t getFieldWidth() const;
		const std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
		static void setDelimiter(const char delim);
		const char getDelimiter() const;
	};
//}

#endif