#ifndef KONZOLVILAG_MNYT_EMPLOYEE_HPP
#define KONZOLVILAG_MNYT_EMPLOYEE_HPP
#include "StaffMember.hpp"
#include <string>
#include <utility>

using namespace std;
class StaffMember;

class Employee : public StaffMember
{
    private:
        int fixedSalary;
        int sickDays;
    public:
        Employee(string name_c, string dateOfBirth_c,
                 string address_c, int fixedSalary_c, int sickDays_c):
        StaffMember(std::move(name_c), std::move(dateOfBirth_c), std::move(address_c)),
        fixedSalary(fixedSalary_c),
        sickDays(sickDays_c)
        {}
        int& GetFixedSalary() { return fixedSalary; }
        int& GetSickDays() { return sickDays; }
        double CalculateSickPay() { return fixedSalary - (fixedSalary * 0.6); }
        void PrintAdditionalData() override
        {
            cout << "Salary: " << to_string(GetFixedSalary()) << endl;
            cout << "Number of days on sick leave: " << to_string(GetSickDays()) << endl;
        }
};

#endif // KONZOLVILAG_MNYT_EMPLOYEE_HPP
