#include "Employee.h"
#include "Employees.h"

using namespace std;

const bool UNIT_TESTING = true;

/* Used for Calculating an Employee's Gross Salary */
const double EMPLOYEE_CODE_S_BASE_PAY = 800;
const double EMPLOYEE_CODE_O_BASE_PAY = 1000;
const double EMPLOYEE_CODE_M_BASE_PAY = 1500;
const double CLASSIFICATION_CODE_1_BONUS = 0.05;     // 5%
const double CLASSIFICATION_CODE_2_BONUS = 0.1;      // 10%
const double CLASSIFICATION_CODE_3_BONUS = 0.2;      // 20% 
const double EDUCATIONAL_CODE_1_BONUS = 0;		     // 0%
const double EDUCATIONAL_CODE_2_BONUS = 0.05;        // 5%
const double EDUCATIONAL_CODE_3_BONUS = 0.12;	     // 12%
const double EDUCATIONAL_CODE_4_BONUS = 0.2;	     // 20%
const double YEARS_OF_SERVICE_0_TO_10_BONUS = 0.05;  // 5%
const double YEARS_OF_SERVICE_ABOVE_10_BONUS = 0.01; // Add 1% for every year above ten to gross pay

const int MAX_NUM_OF_EMPLOYEES = 30;

void initalizeEmployees(Employee[MAX_NUM_OF_EMPLOYEES]);




struct Employee {
private: 
	bool isValidEmployee = false;
	string jobType;
	double employeeBasePay;
	double grossSalary;

public:
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

	void calculateJobType() {
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

	void calculateEmployeeBasePay() {

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
	
	bool validate() { // If all necessary info is found, the employee object is marked Valid
					  // Is a "Getter" for isValidEmployee
		/*if (
			employeeCode == 'S' ||
			employeeCode == 'O' ||
			employeeCode == 'M'
		) {
			if (
				classificationCode == 1 ||
				classificationCode == 2 ||
				classificationCode == 3
			) {
				if (yearsOfService > 0 && yearsOfService <= 50) {
					if (
						educationalCode == 1 ||
						educationalCode == 2 ||
						educationalCode == 3 ||
						educationalCode == 4
					) {
						isValidEmployee = true;
						return isValidEmployee;
					}
				}
			}
		}*/

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

	void calculateGrossSalary() {

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

};

struct Employees { // Container that holds an array of Employee Objects created from a txt file
	Employee employees[MAX_NUM_OF_EMPLOYEES];
	size_t employeesLength = 0;

	size_t currentEmployeeIndex = 0;

	enum employeeInfo {
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

	// Will parse txt file for employee info
	Employees(string filename, ifstream & employeeDataFile) {
		cout << "Reading employee data from " << filename << " ..." << endl;

		if (employeeDataFile.peek() == ifstream::traits_type::eof()) // Check if file is empty
			cout << filename << "has 0 employees listed";

		for (size_t i = 0; i < MAX_NUM_OF_EMPLOYEES; i++) { // Will read in 2 lines and create an Employee per iteration
			if (!employeeDataFile.eof()) {					// Txt file should have 2 lines per employee
				
				employeeInfo currentToken = firstName;
				for (; currentToken < 7; currentToken += 1) { // Will read in 7 tokens per employee from file
					currentToken = firstName;

				}
			}
		}
	}

private:
	void writeEmployeeInfo() {

	}
};

int main() {
	if (UNIT_TESTING) doUnitTesting();
	Employees employess_1 = Employees("namelist.txt", ifstream("namelist.txt"));
	Employees employess_2 = Employees("namelist2.txt", ifstream("namelist2.txt"));
	Employees employess_3 = Employees("namelist3.txt", ifstream("namelist3.txt"));
	


}

//// Will parse txt file for employee info. If all needed info is found, the employee object is marked Valid
//void initalizeEmployees(Employee employees[MAX_NUM_OF_EMPLOYEES], const ifstream & employeeDataFile) {
//	for (size_t i = 0; i < MAX_NUM_OF_EMPLOYEES; i++) {
//		employeeDataFile >> employees[i]
//	}
//}

void doUnitTesting() {

}