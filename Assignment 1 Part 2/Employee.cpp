#include "Employee.h"

using namespace std;

Employee::Employee(
	string firstName,
	string lastName,
	char employeeCode,
	int idNumber,
	char classificationCode,
	int yearsOfService,
	int educationalCode
) {
	// Initialize public member variables
	this->firstName = firstName;
	this->lastName = lastName;
	this->employeeCode = employeeCode;
	this->idNumber = idNumber;
	this->classificationCode = classificationCode;
	this->yearsOfService = yearsOfService;
	this->educationalCode = educationalCode;

	//Initialize private member variables
	calculateJobType();
	calculateEmployeeBasePay();
}

void Employee::calculateJobType() {
	switch (employeeCode) {
	case 'S':
		jobType = "Factory Worker";
		break;

	case 'O':
		jobType = "Office Worker";
		break;

	case 'M':
		jobType = "Management";
		break;
	}
}

void Employee::calculateEmployeeBasePay() {

	switch (employeeCode) {
	case 'S':
		employeeBasePay = EMPLOYEE_CODE_S_BASE_PAY;
		break;
	case 'O':
		employeeBasePay = EMPLOYEE_CODE_O_BASE_PAY;
		break;
	case 'M':
		employeeBasePay = EMPLOYEE_CODE_M_BASE_PAY;
		break;
	}
}

bool Employee::validate() { // If all necessary info is found, the employee object is marked Valid
							// Is a "Getter" for isValidEmployee
	if (
		(
			employeeCode == 'S' ||
			employeeCode == 'O' ||
			employeeCode == 'M'
		)
			&&
		(
			classificationCode == 1 ||
			classificationCode == 2 ||
			classificationCode == 3
		)
			&&
		(
			yearsOfService > 0 && yearsOfService <= 50
		)
			&&
		(
			educationalCode == 1 ||
			educationalCode == 2 ||
			educationalCode == 3 ||
			educationalCode == 4
		)
	) {
		isValidEmployee = true;
		return isValidEmployee;
	}

	else {
		isValidEmployee = false;
		return isValidEmployee;
	}

}

void Employee::calculateGrossSalary() {

	switch (classificationCode) {
	case 1:
		grossSalary = grossSalary + (employeeBasePay * CLASSIFICATION_CODE_1_BONUS);
		break;

	case 2:
		grossSalary = grossSalary + (employeeBasePay * CLASSIFICATION_CODE_2_BONUS);
		break;

	case 3:
		grossSalary = grossSalary + (employeeBasePay * CLASSIFICATION_CODE_3_BONUS);
		break;
	}

	if (yearsOfService <= 10)
		grossSalary = grossSalary + (employeeBasePay * YEARS_OF_SERVICE_0_TO_10_BONUS);
	if (yearsOfService > 10)
		grossSalary = grossSalary + (employeeBasePay * (YEARS_OF_SERVICE_0_TO_10_BONUS + ((yearsOfService - 10) * YEARS_OF_SERVICE_ABOVE_10_BONUS)));

	switch (educationalCode) {
	case 1:
		grossSalary = grossSalary + (employeeBasePay * EDUCATIONAL_CODE_1_BONUS);
		break;

	case 2:
		grossSalary = grossSalary + (employeeBasePay * EDUCATIONAL_CODE_2_BONUS);
		break;

	case 3:
		grossSalary = grossSalary + (employeeBasePay * EDUCATIONAL_CODE_3_BONUS);
		break;

	case 4:
		grossSalary = grossSalary + (employeeBasePay * EDUCATIONAL_CODE_4_BONUS);
		break;
	}
}