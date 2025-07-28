//              =====Creating of a Employee management system using STL=====
#include <iostream>
#include <vector>
#include <algorithm> // for sort, find_if, etc.
#include <numeric>
#include <iterator>
#include <string>
using namespace std;

struct Employee {
    int id;
    string name;
    double salary;
};

// Function to display employee details
// This function takes an Employee object and prints its details
// It is used with for_each to display each employee's information
// The function is defined outside of main to keep the code organized
// and to allow it to be reused if needed.
void displayEmployees (const Employee& emp) {
    cout << "ID: " << emp.id << ", Name: " << emp.name << ", Salary: " << emp.salary << endl;
}

int main () {
    // Create a vector of employees
    vector<Employee> employees = {
        {1, "Alice", 50000},
        {2, "Bob", 60000},
        {3, "Charlie", 55000},
        {4, "David", 70000},
        {5, "Eve", 45000},
        {6, "Frank", 80000},
        {7, "Grace", 52000},
        {8, "Hannah", 75000},
        {9, "Ian", 48000},
        {10, "Jack", 62000}
    };

    
//__________________________________________1_____________________________________________
    // sort is used to sort the employees by their salary
    sort(employees.begin(), employees.end(), [](const Employee& a, const Employee& b) {
        return a.salary > b.salary;
    });
    cout << "=== Employees sorted by salary--> (highest to lowest) ===\n" << endl;

    for_each(employees.begin(), employees.end(), displayEmployees); cout << endl;
    // for_each is used to display each employee's details

//___________________________________________2____________________________________________
    // copy_if is used to copy high earners to a new vector
    vector<Employee> HighEarners;

    copy_if(employees.begin(), 
            employees.end(), 
            back_inserter(HighEarners), // back_inserter is used to insert elements into HighEarners
            [](const Employee& emp) {
                return emp.salary > 55000;
                }
            );
    cout << "=== High earners (salary > 55000) ===\n" << endl;
    for_each(HighEarners.begin(), HighEarners.end(), displayEmployees); cout << endl;

//___________________________________________3____________________________________________
    // accumulate is used to calculate the total salary of all employees
    double totalSalary = accumulate(employees.begin(), employees.end(), 0.0, 
                        [](double sum, const Employee& emp)
                        {return sum + emp.salary;}
                        );
    cout << "Total salary of all employees: " << totalSalary << endl; cout << endl;

//__________________________________________4_____________________________________________
    double averageSalary = totalSalary / employees.size();
    cout << "Average salary of all employees: " << averageSalary << endl; cout << endl;

//__________________________________________5_____________________________________________
    auto highestPaid = max_element(employees.begin(), employees.end(), 
                                [](const Employee& a, const Employee& b) {
                                    return a.salary < b.salary;
                                });
    cout << "Highest paid employee: " << endl;
    displayEmployees(*highestPaid); cout << endl;

 return 0;
}