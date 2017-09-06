#pragma once
#include <string>


class Employee {
	bool isValidEmployee = false;
	string jobType;
	double employeeBasePay;
	double grossSalary;

	string firstName;
	string lastName;
	char employeeCode;
	int idNumber;
	char classificationCode;
	int yearsOfService;
	int educationalCode;

	Employee(
		string firstName = "",
		string lastName = "",
		char employeeCode = '\0',
		int idNumber = 0000,
		char classificationCode = '\0',
		int yearsOfService = 0,
		int educationalCode = 0
	);

	void calculateJobType();
	void calculateEmployeeBasePay();
	bool validate();
	void calculateGrossSalary();
};