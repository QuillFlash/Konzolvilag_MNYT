#ifndef KONZOLVILAG_MNYT_CONTRACTOR_HPP
#define KONZOLVILAG_MNYT_CONTRACTOR_HPP
#include "StaffMember.hpp"
//#include "Menu.hpp"
#include <string>
#include <stdexcept>
#include <utility>

using namespace std;
class StaffMember;

class Contractor : public StaffMember
{
    private:
        int hourlyPay;
        int workHours;
    public:
        Contractor(string name_c, string dateOfBirth_c,
                   string address_c, int hourlyPay_c, int workHours_c):
        StaffMember(std::move(name_c), std::move(dateOfBirth_c), std::move(address_c)),
        hourlyPay(hourlyPay_c),
        workHours(workHours_c)
        {}
        int& GetHourlyPay() { return hourlyPay; }
        int& GetWorkHours() { return workHours; }
        void PrintAdditionalData() override
        {
            cout << "Hourly pay: " << to_string(GetHourlyPay()) << endl;
            cout << "Hours spent working in this month: " << to_string(GetWorkHours()) << endl;
        }
        int CalculateGrossIncome(int hours) { return hourlyPay * hours; }
        double CalculateNetIncome();
};

#endif // KONZOLVILAG_MNYT_CONTRACTOR_HPP
