#ifndef KONZOLVILAG_MNYT_STAFFMEMBER_HPP
#define KONZOLVILAG_MNYT_STAFFMEMBER_HPP
#include <iostream>
#include <string>
#include <utility>

using namespace std;

class StaffMember
{
    private:
        string name;
        string dateOfBirth;
        string address;
    public:
        StaffMember(string name_c, string dateOfBirth_c, string address_c):
            name(std::move(name_c)),
            dateOfBirth(std::move(dateOfBirth_c)),
            address(std::move(address_c))
        {}
        void SetAddress(const string &address) { this -> address = address; }
        StaffMember() = default;
        virtual ~StaffMember() = default;
        string& GetName() { return name; }
        string& GetDateOfBirth() { return dateOfBirth; }
        string& GetAddress() { return address; }
        virtual void PrintAdditionalData();
};

inline void StaffMember::PrintAdditionalData() {}
#endif // KONZOLVILAG_MNYT_STAFFMEMBER_HPP
