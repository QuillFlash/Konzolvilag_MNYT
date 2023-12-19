#ifndef KONZOLVILAG_MNYT_COMPANYINCOME_HPP
#define KONZOLVILAG_MNYT_COMPANYINCOME_HPP

class CompanyIncome
{
    private:
        long companyIncome;
    public:
        CompanyIncome() {}
        long& GetCompanyIncome() { return companyIncome; }
        void SetCompanyIncome(long companyIncome) { this -> companyIncome = companyIncome; }
};

#endif // KONZOLVILAG_MNYT_COMPANYINCOME_HPP
