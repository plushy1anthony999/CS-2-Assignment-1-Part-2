#include "Employees.h"

using namespace std;

Employees::Employees(string filename, ifstream & employeeDataFile) {
	cout << "Reading employee data from " << filename << " ..." << endl;

	if (employeeDataFile.peek() == ifstream::traits_type::eof()) // Check if file is empty
		cout << filename << "has 0 employees listed";

	for (size_t i = 0; i < MAX_NUM_OF_EMPLOYEES; i++) { // Will read in 2 lines and create an Employee per iteration
		if (!employeeDataFile.eof()) {					// Txt file should have 2 lines per employee

			//employees[i] = Employee();
			for (size_t j = 0; j < 7; j++) { // Will read in 7 tokens per employee from file
				
			}
		}
	}
}

void Employees::writeEmployeeInfo() {

}