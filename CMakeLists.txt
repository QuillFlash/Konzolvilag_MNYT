cmake_minimum_required(VERSION 3.28)
project(Konzolvilag_MNYT)

set(CMAKE_CXX_STANDARD 23)

add_executable(Konzolvilag_MNYT main.cpp
        Headers/StaffMember.hpp
        Classes/Contractor.cpp
        Headers/Contractor.hpp
        Classes/Menu.cpp
        Headers/Menu.hpp
        Headers/Employee.hpp
        Classes/Executive.cpp
        Headers/Executive.hpp
        Headers/CompanyIncome.hpp)

include_directories(Headers, Classes)
