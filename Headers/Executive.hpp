#ifndef KONZOLVILAG_MNYT_EXECUTIVE_HPP
#define KONZOLVILAG_MNYT_EXECUTIVE_HPP
#include "StaffMember.hpp"
#include <utility>

class StaffMember;

class Executive : public StaffMember
{
    private:
        int fixedSalary{};
    public:
        Executive(string name_c, string dateOfBirth_c,
                string address_c, int fixedSalary_c):
                StaffMember(std::move(name_c), std::move(dateOfBirth_c), std::move(address_c)),
                fixedSalary(fixedSalary_c)
        {}
        Executive() : StaffMember() {}
        int CalculateNetFixedSalary();
        int GetFixedSalary() { return fixedSalary; }
        void PrintAdditionalData() override { cout << "Salary: " << to_string(GetFixedSalary()) << endl; }
};

#endif // KONZOLVILAG_MNYT_EXECUTIVE_HPP
