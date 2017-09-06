#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Employee.h"

const int MAX_NUM_OF_EMPLOYEES = 30;

class Employees { // Container that holds an array of Employee Objects created from a txt file

	Employee employees[MAX_NUM_OF_EMPLOYEES];
	size_t employeesLength = 0;

	size_t currentEmployeeIndex = 0;

	enum class employeeInfo {
		firstName,
		lastName,
		employeeCode,
		idNumber,
		classificationCode,
		yearsOfService,
		educationalCode
	};

	enum class EMPLOYEE_SORT_FLAGS {
		ID = 0x01,
		LAST_NAME = 0x02,
		GROSS_SALARY = 0x04
	};

public:
	// Will parse txt file for employee info
	Employees(string filename, ifstream & employeeDataFile);

private:
	void writeEmployeeInfo();
};