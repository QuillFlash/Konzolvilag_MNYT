#ifndef KONZOLVILAG_MNYT_MENU_HPP
#define KONZOLVILAG_MNYT_MENU_HPP
#include "StaffMember.hpp"
#include "Contractor.hpp"
#include "Employee.hpp"
#include "Executive.hpp"
#include <list>
#include <iostream>

class Contractor;
class Employee;
class Executive;

using namespace std;

class Menu
{
    private:
        list<Contractor> contractorList;
        list<Employee> employeeList;
        list<Executive> executiveList;
    public:
        list<Contractor>& GetContractorList() { return contractorList; }
        list<Employee>& GetEmployeeList() { return employeeList; }
        list<Executive>& GetExecutiveList() { return executiveList; }
        void Execute();
        void ListContractors();
        void ListEmployees();
        void ListExecutives();
        void AddContractor();
        void AddEmployee();
        void AddExecutive();
        void DeclareCompanyIncome();
        void SearchByNameAndBirth();
        void ModifyContractor();
        void ModifyEmployee();
        void ModifyExecutive();
        void DeleteContractor();
        void DeleteEmployee();
        void DeleteExecutive();
        static Menu menu;
};

#endif // KONZOLVILAG_MNYT_MENU_HPP
