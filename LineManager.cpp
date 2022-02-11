// Name:Scott Maciver
// Seneca Student ID:102205184
// Seneca email:smaciver1@myseneca.ca
// Date of completion:2019-11-30
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include "LineManager.h"
#include "Utilities.h"
#include "Task.h"
#include "CustomerOrder.h"



LineManager::LineManager(const std::string dat, std::vector<Task*> &aLine, std::vector<CustomerOrder> &custOrders)
{
	std::ifstream ifs;
	std::string tok;
	std::string pntTo;
	ifs.open(dat);
	if (!ifs) {
		throw "bad file name";
	}

	for (size_t i = 0; i < aLine.size(); i++) {
		AssemblyLine.push_back(aLine[i]);
	}

	while (!ifs.eof()) {
		std::getline(ifs, tok, '|');
		if (ifs.peek() != EOF) {
			std::getline(ifs, pntTo, '\n');
		}
		else {
			pntTo = "empty";
		}
		for (size_t i = 0; i < AssemblyLine.size(); i++) {
			if (AssemblyLine[i]->getName() == tok) {
				for (size_t j = 0; j < AssemblyLine.size(); j++) {
					if (AssemblyLine[j]->getName() == pntTo) {
						AssemblyLine[i]->setNextTask(*AssemblyLine[j]);
					}
				}
			}
		}
	}

	for (size_t i = 0; i < custOrders.size(); i++) {
		ToBeFilled.push_front(std::move(custOrders[i]));
		m_cntCustomerOrder++;
	}
}

bool LineManager::run(std::ostream & os)
{
	if (ToBeFilled.size() != 0) {
		AssemblyLine[4]->operator+=(std::move(ToBeFilled.back()));
		ToBeFilled.pop_back();
	}
	for (size_t i = 0; i < AssemblyLine.size(); i++) {
		AssemblyLine[i]->runProcess(os);
	}
	for (size_t i = 0; i < AssemblyLine.size(); i++) {
		CustomerOrder co;
		if (AssemblyLine[i]->moveTask() != false) {
			if (AssemblyLine[i]->getCompleted(co) == true) {
				completed.push_back(std::move(co));
			}
		}
	}
	if (completed.size() == m_cntCustomerOrder) {
		return true;
	}
	else {
		return false;
	}

}

void LineManager::displayCompleted(std::ostream & os) const
{
	for (size_t i = 0; i < completed.size(); i++) {
		completed[i].display(os);
	}
}

void LineManager::validateTasks() const
{
	for (size_t i = 0; i < AssemblyLine.size(); i++) {
		AssemblyLine[i]->validate(std::cout);
	}
}
