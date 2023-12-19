#include "../Headers/StaffMember.hpp"
#include "../Headers/Executive.hpp"
#include "../Headers/CompanyIncome.hpp"
#include "../Headers/Contractor.hpp"
#include "../Headers/Menu.hpp"

using namespace std;
class Executive;
class CompanyIncome;
class Contractor;
class Menu;

int Executive::CalculateNetFixedSalary()
{
    CompanyIncome companyIncome;
    long budget = companyIncome.GetCompanyIncome();
    int salaryExpenses;
    int contractorSum;
    int employeeSum;
    for (auto iterator = Menu::menu.GetContractorList().begin();
         next(iterator) != Menu::menu.GetContractorList().end(); ++iterator)
    {
        Contractor& numberToBeAddedTo = *iterator;
        Contractor& numberToAdd = *next(iterator);

        contractorSum = (numberToBeAddedTo.GetWorkHours() * numberToBeAddedTo.GetHourlyPay())
                + (numberToAdd.GetWorkHours() * numberToAdd.GetHourlyPay());
    }
    for (auto iterator = Menu::menu.GetEmployeeList().begin();
         next(iterator) != Menu::menu.GetEmployeeList().end(); ++iterator)
    {
        Employee& numberToBeAddedTo = *iterator;
        Employee& numberToAdd = *next(iterator);
        employeeSum = numberToBeAddedTo.GetFixedSalary() + numberToAdd.GetFixedSalary();
    }
    salaryExpenses = contractorSum + employeeSum;
    int profit = budget - salaryExpenses;
    if (profit > 0)
    {
        return profit * 0.001;
    }
    return profit;
}