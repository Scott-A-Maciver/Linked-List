// Name:Scott Maciver
// Seneca Student ID:102205184
// Seneca email:smaciver1@myseneca.ca
// Date of completion:2019-11-30
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <deque>
#include <iostream>
#include <string>

#include "Task.h"

Task::Task(const std::string record) : Item(record)
{
	m_pNextTask = nullptr;
}

void Task::runProcess(std::ostream& os)
{
	if (m_orders.empty() == false) {
		if (m_orders.back().getOrderFillState() != true) {
			if (m_orders.back().getItemFillState(this->getName()) == false) {
				m_orders.back().fillItem(*this, os);
			}
		}
	}
}


bool Task::moveTask()
{
	if (m_orders.empty() == false) {
		if (m_orders.back().getItemFillState(getName()) == true) {
			if (m_pNextTask != nullptr) {
				m_pNextTask->operator+=(std::move(m_orders.back()));
				m_orders.pop_back();
			}
			return true;
		}
	}
	else {
		return false;
	}
	return false;
}

void Task::setNextTask(Task& next)
{
	m_pNextTask = &next;
}

bool Task::getCompleted(CustomerOrder& comp)
{
	if (m_orders.empty() == false) {
		if (m_orders.back().getOrderFillState() == true) {
			comp.operator=(std::move(m_orders.back()));
			m_orders.pop_back();
			return true;
		}
	}
	return false;
}

void Task::validate(std::ostream& os)
{
	os << this->getName() << " --> ";
	if (m_pNextTask != nullptr) {
		os << m_pNextTask->getName();
	}
	else {
		os << "END OF LINE";
	}
	os << std::endl;
}

Task & Task::operator+=(CustomerOrder&& custOrder)
{
	m_orders.push_front(std::move(custOrder));
	return *this;
}
