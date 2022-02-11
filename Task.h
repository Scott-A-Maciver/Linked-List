// Name:Scott Maciver
// Seneca Student ID:102205184
// Seneca email:smaciver1@myseneca.ca
// Date of completion:2019-11-30
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef _SDDS_TASK_H
#define _SDDS_TASK_H
#include <iostream>
#include <deque>
#include <string>
#include "Item.h"
#include "CustomerOrder.h"

class Task : public Item {
	std::deque<CustomerOrder> m_orders;
	Task *m_pNextTask;
public:
	Task(const std::string);
	Task(Task&) = delete;
	Task(Task&&) = delete;
	Task& operator=(Task&) = delete;
	Task& operator=(Task&&) = delete;
	void runProcess(std::ostream&);
	//moves task along assembly line using m_pnexttask pointer
	bool moveTask();
	void setNextTask(Task&);
	bool getCompleted(CustomerOrder&);
	void validate(std::ostream&);
	Task& operator+=(CustomerOrder&&);
};

#endif