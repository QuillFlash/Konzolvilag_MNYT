#include "../Headers/StaffMember.hpp"
#include "../Headers/Contractor.hpp"

class Contractor;

double Contractor::CalculateNetIncome()
{
    int finalWage = Contractor::CalculateGrossIncome(GetWorkHours())
                    - (Contractor::CalculateGrossIncome(GetWorkHours()) * 0.3);
    return finalWage;
}