#include "../Headers/StaffMember.hpp"
#include "../Headers/Menu.hpp"
#include "../Headers/CompanyIncome.hpp"
#include <string>

using namespace std;
class Menu;
class CompanyIncome;

Menu Menu::menu;
template <typename T>
T ParameterisedFieldListing(list<T>& aList, string& name,
                            string& dateOfBirth)
{
    for (T& person : aList)
    {
        if (name == person.GetName() && dateOfBirth == person.GetDateOfBirth())
        {
            cout << "Name: " << person.GetName() << endl;
            cout << "Date of Birth: " << person.GetDateOfBirth() << endl;
            cout << "Address: " << person.GetAddress() << endl;
            person.PrintAdditionalData();
        }
        else
        {
            cout << "There's no such person named " << name << " in our database." << endl;
        }
    }
}

void ClearConsole()
{
    #ifdef _WIN32
        system("cls");
    #elifdef _WIN64
        system("cls");
    #else
        system("clear");
    #endif
}

void Menu::Execute()
{
    try
    {
        bool isMenuRunning = true;
        while (isMenuRunning)
        {
            int mainMenuSelection;
            string mainMenuSelectionString;
            cout << "Welcome to Konzolvilág's English-language"
                    " financial resources management program!" << endl << endl;
            cout << "Please select an option:" << endl << endl;
            cout << "1) Declare monthly company income" << endl
                 << "2) List contract workers" << endl << "3) List hired employees"
                 << endl << "4) List executives" << endl << "5) Search by name and mother's name of birth"
                 << endl << "6) Add contractor" << endl << "7) Add employee" << endl
                 << "8) Add executive" << endl << "9) Modify contractor" << endl
                 << "10) Modify employee" << endl << "11) Modify executive" << endl
                 << "12) Delete contractor" << endl << "13) Delete employee" << endl
                 << "14) Delete executive" << endl << endl << "0) Exit" << endl << endl;
            cout << "Selection: " << endl;
            cin >> mainMenuSelectionString;
            cin.ignore();
            mainMenuSelection = stoi(mainMenuSelectionString);
            switch (mainMenuSelection)
            {
                case 0:
                    exit(EXIT_SUCCESS);
                case 1:
                    DeclareCompanyIncome();
                    break;
                case 2:
                    ListContractors();
                    break;
                case 3:
                    ListEmployees();
                    break;
                case 4:
                    ListExecutives();
                    break;
                case 5:
                    SearchByNameAndBirth();
                case 6:
                    AddContractor();
                    break;
                case 7:
                    AddEmployee();
                    break;
                case 8:
                    AddExecutive();
                    break;
                case 9:
                    ModifyContractor();
                    break;
                case 10:
                    ModifyEmployee();
                    break;
                case 11:
                    ModifyExecutive();
                    break;
                case 12:
                    DeleteContractor();
                    break;
                case 13:
                    DeleteEmployee();
                    break;
                case 14:
                    DeleteExecutive();
                    break;
                default:
                    throw invalid_argument("ERROR: Not a valid number.");
            }
        }
    }
    catch (invalid_argument& exception)
    {
        cerr << "ERROR: Invalid argument: " << exception.what() << endl;
        cout << "Press Enter to continue...";
        cin.ignore();
        ClearConsole();
        Execute();
    }
}

void Menu::DeclareCompanyIncome()
{
    try
    {
        ClearConsole();
        string companyIncomeString;
        cout << "Please enter a number: ";
        cin >> companyIncomeString;
        cin.ignore();
        int companyIncome = stoi(companyIncomeString);
        CompanyIncome companyIncomeObject;
        companyIncomeObject.SetCompanyIncome(companyIncome);
        ClearConsole();
        Execute();
    }
    catch (invalid_argument& exception)
    {
        cerr << "ERROR: Invalid argument: " << exception.what() << endl;
        cout << "Press Enter to continue...";
        Menu *menuCall = &menu;
        cin.ignore();
        ClearConsole();
        menuCall -> Execute();
        delete menuCall;
    }
}

void Menu::ListContractors()
{
    ClearConsole();
    for (Contractor& contractors : contractorList)
    {
        cout << "Name: " << contractors.GetName() << endl;
        cout << "Date of Birth: " << contractors.GetDateOfBirth() << endl;
        cout << "Address: " << contractors.GetAddress() << endl;
        cout << "Hourly pay: " << to_string(contractors.GetHourlyPay()) << endl;
        cout << "Hours spent working in this month: " << to_string(contractors.GetWorkHours()) << endl;
        cout << "Monthly income: " << to_string(contractors.CalculateNetIncome()) << endl;
    }
    cin.ignore();
    ClearConsole();
    Execute();
}

void Menu::ListEmployees()
{
    ClearConsole();
    for (Employee& employees : employeeList)
    {
        cout << "Name: " << employees.GetName() << endl;
        cout << "Date of Birth: " << employees.GetDateOfBirth() << endl;
        cout << "Address: " << employees.GetAddress() << endl;
        cout << "Salary: " << to_string(employees.GetFixedSalary()) << endl;
        cout << "Number of days on sick leave: " << to_string(employees.GetSickDays()) << endl;
    }
    cin.ignore();
    ClearConsole();
    Execute();
}

void Menu::ListExecutives()
{
    ClearConsole();
    for (Executive& executives : executiveList)
    {
        cout << "Name: " << executives.GetName() << endl;
        cout << "Date of Birth: " << executives.GetDateOfBirth() << endl;
        cout << "Address: " << executives.GetAddress() << endl;
        cout << "Salary: " << to_string(executives.GetFixedSalary()) << endl;
    }
    cin.ignore();
    ClearConsole();
    Execute();
}

void Menu::AddContractor()
{
    try
    {
        ClearConsole();
        string name;
        string dateOfBirth;
        string address;
        string hourlyPayString;
        string workHoursString;
        int hourlyPay, workHours;

        cout << "Your name: " << endl;
        getline(cin, name);

        cout << "Date of Birth: " << endl;
        getline(cin, dateOfBirth);

        cout << "Your address: " << endl;
        getline(cin, address);

        cout << "How much do you get paid per hour?" << endl;
        getline(cin, hourlyPayString);
        hourlyPay = stoi(hourlyPayString);

        cout << "How many hours do you work per month?" << endl;
        getline(cin, workHoursString);
        workHours = stoi(workHoursString);

        Contractor contractor(name, dateOfBirth,
                              address, hourlyPay,
                              workHours);
        auto iterator = contractorList.begin();
        contractorList.insert(iterator, contractor);
        ++iterator;
        ClearConsole();
        Execute();
    }
    catch (invalid_argument& exception)
    {
        cerr << "ERROR: Invalid argument: " << exception.what() << endl;
        cout << "Press Enter to continue...";
        cin.ignore();
        ClearConsole();
        Execute();
    }
    catch (out_of_range& exception)
    {
        cerr << "ERROR: Index is out of range: " << exception.what() << endl;
        cout << "Press Enter to continue...";
        cin.ignore();
        ClearConsole();
        Execute();
    }
}

void Menu::AddEmployee()
{
    try
    {
        ClearConsole();
        string name;
        string dateOfBirth;
        string address;
        string fixedSalaryString;
        int fixedSalary, sickDays;
        string sickDaysAnswer;
        string amountOfSickDaysString;

        cout << "Your name: ";
        getline(cin, name);

        cout << "Date of Birth: ";
        getline(cin, dateOfBirth);

        cout << "Your address: ";
        getline(cin, address);

        cout << "How much do you get paid per month? ";
        getline(cin, fixedSalaryString);
        fixedSalary = stoi(fixedSalaryString);

        cout << "Were you ill this month? ";
        getline(cin, sickDaysAnswer);
        if (sickDaysAnswer == "yes" || sickDaysAnswer == "Yes" || sickDaysAnswer == "YES")
        {
            cout << "For how many days you were ill?" << endl;
            getline(cin, amountOfSickDaysString);
            sickDays = stoi(amountOfSickDaysString);
            Employee employee(name, dateOfBirth,
                              address, fixedSalary,
                              sickDays);
            employee.CalculateSickPay();
            auto iterator = employeeList.begin();
            employeeList.insert(iterator, employee);
            ++iterator;
            ClearConsole();
            Execute();
        }
        else if (sickDaysAnswer == "no" || sickDaysAnswer == "No" || sickDaysAnswer == "NO")
        {
            Employee employee(name, dateOfBirth,
                              address, fixedSalary,
                              0);
            auto iterator = employeeList.begin();
            employeeList.insert(iterator, employee);
            ++iterator;
            ClearConsole();
            Execute();
        }
        else
        {
            throw invalid_argument("You did not provide a logical value.");
        }
    }
    catch (invalid_argument& exception)
    {
        cerr << "ERROR: Invalid argument: " << exception.what() << endl;
        cout << "Press Enter to continue...";
        cin.ignore();
        ClearConsole();
        Execute();
    }
    catch (out_of_range& exception)
    {
        cerr << "ERROR: Index is out of range: " << exception.what() << endl;
        cout << "Press Enter to continue...";
        cin.ignore();
        ClearConsole();
        Execute();
    }
}

void Menu::AddExecutive()
{
    try
    {
        ClearConsole();
        string name;
        string dateOfBirth;
        string address;
        int fixedSalary;
        string fixedSalaryString;
        string sickDaysAnswer;
        string amountOfSickDaysString;

        cout << "Your name: ";
        getline(cin, name);

        cout << "Date of Birth: ";
        getline(cin, dateOfBirth);

        cout << "Your address: ";
        getline(cin, address);

        Executive executive;
        fixedSalary = executive.CalculateNetFixedSalary();
        auto *detailedExecutive = new Executive(name, dateOfBirth,
                                                     address, fixedSalary);
        auto iterator = executiveList.begin();
        executiveList.insert(iterator, *detailedExecutive);
        ++iterator;
        ClearConsole();
        Execute();
        delete detailedExecutive;
    }
    catch (invalid_argument& exception)
    {
        cerr << "ERROR: Invalid argument: " << exception.what() << endl;
        cout << "Press Enter to continue...";
        cin.ignore();
        ClearConsole();
        Execute();
    }
    catch (out_of_range& exception)
    {
        cerr << "ERROR: Index is out of range: " << exception.what() << endl;
        cout << "Press Enter to continue...";
        cin.ignore();
        ClearConsole();
        Execute();
    }
}

void Menu::ModifyContractor()
{
    ClearConsole();
    string nameSearch;
    string birthDateSearch;

    cout << "Please enter the colleague's name: ";
    getline(cin, nameSearch);

    cout << "Colleague's birth date: ";
    getline(cin, birthDateSearch);

    for (Contractor& contractors : menu.contractorList)
    {
        if (nameSearch == contractors.GetName() && birthDateSearch == contractors.GetDateOfBirth())
        {
            cout << "Name: " << contractors.GetName() << endl;
            cout << "Date of Birth: " << contractors.GetDateOfBirth() << endl;
            cout << "Address: " << contractors.GetAddress() << endl;
            contractors.PrintAdditionalData();
            cout << endl;
            cin.ignore();
            cout << "Gotcha!" << endl;
        }
        else
        {
            cout << "There's no such contractors named " << nameSearch << " in our database." << endl;
        }
        string newAddress;
        cout << "Please type in the new address: ";
        getline(cin, newAddress);
        contractors.SetAddress(newAddress);
        cout << "Address modified successfully!" << endl;
        cin.ignore();
        ClearConsole();
        Execute();
        return;
    }
}

void Menu::ModifyEmployee()
{
    ClearConsole();
    string nameSearch;
    string birthDateSearch;

    cout << "Please enter the colleague's name: ";
    getline(cin, nameSearch);

    cout << "Colleague's birth date: ";
    getline(cin, birthDateSearch);

    for (Employee& employees : menu.employeeList)
    {
        if (nameSearch == employees.GetName() && birthDateSearch == employees.GetDateOfBirth())
        {
            cout << "Name: " << employees.GetName() << endl;
            cout << "Date of Birth: " << employees.GetDateOfBirth() << endl;
            cout << "Address: " << employees.GetAddress() << endl;
            employees.PrintAdditionalData();
            cout << endl;
            cin.ignore();
            cout << "Gotcha!" << endl;
        }
        else
        {
            cout << "There's no such employees named " << nameSearch << " in our database." << endl;
        }
        string newAddress;
        cout << "Please type in the new address: ";
        getline(cin, newAddress);
        employees.SetAddress(newAddress);
        cout << "Address modified successfully!" << endl;
        cin.ignore();
        ClearConsole();
        Execute();
        return;
    }
}

void Menu::ModifyExecutive()
{
    ClearConsole();
    string nameSearch;
    string birthDateSearch;

    cout << "Please enter the colleague's name: ";
    getline(cin, nameSearch);

    cout << "Colleague's birth date: ";
    getline(cin, birthDateSearch);

    for (Executive& executives : menu.executiveList)
    {
        if (nameSearch == executives.GetName() && birthDateSearch == executives.GetDateOfBirth())
        {
            cout << "Name: " << executives.GetName() << endl;
            cout << "Date of Birth: " << executives.GetDateOfBirth() << endl;
            cout << "Address: " << executives.GetAddress() << endl;
            executives.PrintAdditionalData();
            cout << endl;
            cin.ignore();
            cout << "Gotcha!" << endl;
        }
        else
        {
            cout << "There's no such executives named " << nameSearch << " in our database." << endl;
        }
        string newAddress;
        cout << "Please type in the new address: ";
        getline(cin, newAddress);
        executives.SetAddress(newAddress);
        cout << "Address modified successfully!" << endl;
        cin.ignore();
        ClearConsole();
        Execute();
        return;
    }
}

void Menu::DeleteContractor()
{
    ClearConsole();
    string nameSearch;
    string birthDateSearch;

    cout << "Please enter the colleague's name: ";
    getline(cin, nameSearch);

    cout << "Colleague's birth date: ";
    getline(cin, birthDateSearch);

    for (Contractor& contractors : menu.contractorList)
    {
        if (nameSearch == contractors.GetName() && birthDateSearch == contractors.GetDateOfBirth())
        {
            cout << "Name: " << contractors.GetName() << endl;
            cout << "Date of Birth: " << contractors.GetDateOfBirth() << endl;
            cout << "Address: " << contractors.GetAddress() << endl;
            contractors.PrintAdditionalData();
            cout << endl;
            cin.ignore();
            cout << "Gotcha!" << endl;
        }
        else
        {
            cout << "There's no such contractors named " << nameSearch << " in our database." << endl;
        }
        string deleteChoice;
        cout << "Do you want to delete this entry? ";
        getline(cin, deleteChoice);
        auto iterator = menu.contractorList.begin();
        if (deleteChoice == "yes" || deleteChoice == "Yes" || deleteChoice == "YES")
        {
            menu.contractorList.erase(iterator);
            cout << "Entry deleted successfully!" << endl;
        }
        else if (deleteChoice == "no" || deleteChoice == "No" || deleteChoice == "NO")
        {
            ++iterator;
            cin.ignore();
            ClearConsole();
            Execute();
            return;
        }
        else
        {
            throw invalid_argument("ERROR: Not a logical value.");
        }
        cin.ignore();
        ClearConsole();
        Execute();
        return;
    }
}

void Menu::DeleteEmployee()
{
    ClearConsole();
    string nameSearch;
    string birthDateSearch;

    cout << "Please enter the colleague's name: ";
    getline(cin, nameSearch);

    cout << "Colleague's birth date: ";
    getline(cin, birthDateSearch);

    for (Employee& employees : menu.employeeList)
    {
        if (nameSearch == employees.GetName() && birthDateSearch == employees.GetDateOfBirth())
        {
            cout << "Name: " << employees.GetName() << endl;
            cout << "Date of Birth: " << employees.GetDateOfBirth() << endl;
            cout << "Address: " << employees.GetAddress() << endl;
            employees.PrintAdditionalData();
            cout << endl;
            cin.ignore();
            cout << "Gotcha!" << endl;
        }
        else
        {
            cout << "There's no such employees named " << nameSearch << " in our database." << endl;
        }
        string deleteChoice;
        cout << "Do you want to delete this entry? ";
        getline(cin, deleteChoice);
        auto iterator = menu.employeeList.begin();
        if (deleteChoice == "yes" || deleteChoice == "Yes" || deleteChoice == "YES")
        {
            menu.employeeList.erase(iterator);
            cout << "Entry deleted successfully!" << endl;
        }
        else if (deleteChoice == "no" || deleteChoice == "No" || deleteChoice == "NO")
        {
            ++iterator;
            cin.ignore();
            ClearConsole();
            Execute();
            return;
        }
        else
        {
            throw invalid_argument("ERROR: Not a logical value.");
        }
        cin.ignore();
        ClearConsole();
        Execute();
        return;
    }
}

void Menu::DeleteExecutive()
{
    ClearConsole();
    string nameSearch;
    string birthDateSearch;

    cout << "Please enter the colleague's name: ";
    getline(cin, nameSearch);

    cout << "Colleague's birth date: ";
    getline(cin, birthDateSearch);

    for (Executive& executives : menu.executiveList)
    {
        if (nameSearch == executives.GetName() && birthDateSearch == executives.GetDateOfBirth())
        {
            cout << "Name: " << executives.GetName() << endl;
            cout << "Date of Birth: " << executives.GetDateOfBirth() << endl;
            cout << "Address: " << executives.GetAddress() << endl;
            executives.PrintAdditionalData();
            cout << endl;
            cin.ignore();
            cout << "Gotcha!" << endl;
        }
        else
        {
            cout << "There's no such executives named " << nameSearch << " in our database." << endl;
        }
        string deleteChoice;
        cout << "Do you want to delete this entry? ";
        getline(cin, deleteChoice);
        auto iterator = menu.executiveList.begin();
        if (deleteChoice == "yes" || deleteChoice == "Yes" || deleteChoice == "YES")
        {
            menu.executiveList.erase(iterator);
            cout << "Entry deleted successfully!" << endl;
        }
        else if (deleteChoice == "no" || deleteChoice == "No" || deleteChoice == "NO")
        {
            ++iterator;
            cin.ignore();
            ClearConsole();
            Execute();
            return;
        }
        else
        {
            throw invalid_argument("ERROR: Not a logical value.");
        }
        cin.ignore();
        ClearConsole();
        Execute();
        return;
    }
}

void Menu::SearchByNameAndBirth()
{
    ClearConsole();
    string nameSearch;
    string birthDateSearch;

    cout << "Please enter the colleague's name: ";
    getline(cin, nameSearch);

    cout << "Colleague's birth date: ";
    getline(cin, birthDateSearch);

    ParameterisedFieldListing<Contractor>(GetContractorList(), nameSearch, birthDateSearch);
    ParameterisedFieldListing<Employee>(GetEmployeeList(), nameSearch, birthDateSearch);
    ParameterisedFieldListing<Executive>(GetExecutiveList(), nameSearch, birthDateSearch);
    cout << "Press Enter to go back to the main menu.";
    cin.ignore();
    ClearConsole();
    Execute();
}
