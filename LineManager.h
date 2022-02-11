// Name:Scott Maciver
// Seneca Student ID:102205184
// Seneca email:smaciver1@myseneca.ca
// Date of completion:2019-11-30
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef _SDDS_LINEMANAGER_H
#define _SDDS_LINEMANAGER_H

#include <iostream>
#include <vector>
#include "Task.h"
#include "CustomerOrder.h"

class LineManager {
	std::vector<Task*> AssemblyLine;
	std::deque<CustomerOrder> ToBeFilled;
	std::deque<CustomerOrder> completed;
	unsigned int m_cntCustomerOrder;
public:
	LineManager(const std::string, std::vector<Task*>&, std::vector<CustomerOrder>&);
	bool run(std::ostream& os);
	void displayCompleted(std::ostream& os) const;
	void validateTasks() const;
};
#endif
