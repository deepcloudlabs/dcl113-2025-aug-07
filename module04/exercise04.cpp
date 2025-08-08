#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <functional>
#include "employee.h"

enum format_t {
    plain, full_name, full
};

auto
print_employee(const employee &emp, ostream &out, format_t format) {
    if (format == format_t::full_name) {
        out << "employee[ " << emp.getMLastName() << ", " << emp.getMFirstName()
            << " ]" << endl;
    } else if (format == format_t::full) {
        out << "employee[ " << emp.getMLastName() << ", " << emp.getMFirstName()
            << ", department: " << employee::department_name[emp.getMDepartment()]
            << ", birth year: " << emp.getMBirthYear()
            << ", salary: " << emp.getMSalary()
            << ", gender: " << employee::gender_name[emp.getMGender()]
            << ", iban: " << emp.getMIban()
            << " ]" << endl;
    } else if (format == format_t::plain) {
        out << "employee[ " << emp.getMLastName() << ", " << emp.getMFirstName()
            << ", department: " << employee::department_name[emp.getMDepartment()]
            << " ]" << endl;
    }
}

int main() {
    vector<employee> employees{
    {"james",  "sawyer",   employee::department_t::it,      employee::gender_t::male,   250'000, "tr100", 1982},
    {"kate",   "austen",   employee::department_t::sales,   employee::gender_t::female, 350'000, "tr200", 1986},
    {"juliet", "burke",    employee::department_t::finance, employee::gender_t::female, 550'000, "tr300", 1983},
    {"jack",   "shephard", employee::department_t::hr,      employee::gender_t::male,   450'000, "tr400", 1973},
    {"jack",   "bauer",    employee::department_t::it,      employee::gender_t::male,   150'000, "tr500", 1956},

    {"emily", "stone",     employee::department_t::hr,      employee::gender_t::female, 200'000, "tr501", 1995},
    {"liam", "clark",      employee::department_t::sales,   employee::gender_t::male,   180'000, "tr502", 1992},
    {"nora", "wright",     employee::department_t::finance, employee::gender_t::female, 220'000, "tr503", 1980},
    {"oliver", "hall",     employee::department_t::marketing, employee::gender_t::male, 190'000, "tr504", 1988},
    {"mia", "turner",      employee::department_t::it,      employee::gender_t::female, 310'000, "tr505", 1990},

    {"lucas", "scott",     employee::department_t::it,      employee::gender_t::male,   275'000, "tr506", 1996},
    {"sophia", "hill",     employee::department_t::hr,      employee::gender_t::female, 240'000, "tr507", 1985},
    {"ethan", "green",     employee::department_t::sales,   employee::gender_t::male,   300'000, "tr508", 1975},
    {"ava", "young",       employee::department_t::finance, employee::gender_t::female, 330'000, "tr509", 1989},
    {"noah", "king",       employee::department_t::marketing, employee::gender_t::male, 295'000, "tr510", 1994},

    {"ella", "baker",      employee::department_t::it,      employee::gender_t::female, 260'000, "tr511", 1993},
    {"logan", "adams",     employee::department_t::hr,      employee::gender_t::male,   310'000, "tr512", 1983},
    {"grace", "nelson",    employee::department_t::sales,   employee::gender_t::female, 150'000, "tr513", 1997},
    {"harry", "carter",    employee::department_t::finance, employee::gender_t::male,   200'000, "tr514", 1999},
    {"zoe", "mitchell",    employee::department_t::marketing, employee::gender_t::female, 185'000, "tr515", 1986},

    {"ben", "morris",      employee::department_t::it,      employee::gender_t::male,   400'000, "tr516", 1967},
    {"amelia", "rogers",   employee::department_t::hr,      employee::gender_t::female, 235'000, "tr517", 1979},
    {"jayden", "reed",     employee::department_t::sales,   employee::gender_t::male,   260'000, "tr518", 1982},
    {"hannah", "cook",     employee::department_t::finance, employee::gender_t::female, 270'000, "tr519", 1991},
    {"dylan", "bell",      employee::department_t::marketing, employee::gender_t::male, 210'000, "tr520", 1993},

    {"lily", "murphy",     employee::department_t::it,      employee::gender_t::female, 330'000, "tr521", 1990},
    {"ryan", "ward",       employee::department_t::hr,      employee::gender_t::male,   250'000, "tr522", 1988},
    {"chloe", "bailey",    employee::department_t::sales,   employee::gender_t::female, 195'000, "tr523", 1970},
    {"logan", "rivera",    employee::department_t::finance, employee::gender_t::male,   280'000, "tr524", 1992},
    {"scarlett", "cooper", employee::department_t::marketing, employee::gender_t::female, 225'000, "tr525", 1994},

    {"nathan", "richards", employee::department_t::it,      employee::gender_t::male,   245'000, "tr526", 1987},
    {"samantha", "cox",    employee::department_t::hr,      employee::gender_t::female, 190'000, "tr527", 1996},
    {"tyler", "howard",    employee::department_t::sales,   employee::gender_t::male,   165'000, "tr528", 1998},
    {"bella", "ward",      employee::department_t::finance, employee::gender_t::female, 210'000, "tr529", 1995},
    {"liam", "brooks",     employee::department_t::marketing, employee::gender_t::male, 220'000, "tr530", 1990},


    {"zoey", "kelly",      employee::department_t::it,      employee::gender_t::female, 235'000, "tr531", 1984},
    {"adam", "sanders",    employee::department_t::hr,      employee::gender_t::male,   270'000, "tr532", 1982},
    {"madison", "price",   employee::department_t::sales,   employee::gender_t::female, 255'000, "tr533", 1993},
    {"brayden", "bennett", employee::department_t::finance, employee::gender_t::male,   215'000, "tr534", 1997},
    {"aubrey", "wood",     employee::department_t::marketing, employee::gender_t::female, 205'000, "tr535", 1992},

    {"hunter", "barnes",   employee::department_t::it,      employee::gender_t::male,   240'000, "tr536", 1999},
    {"leah", "ross",       employee::department_t::hr,      employee::gender_t::female, 265'000, "tr537", 1985},
    {"joseph", "henderson",employee::department_t::sales,   employee::gender_t::male,   275'000, "tr538", 1981},
    {"penelope", "coleman",employee::department_t::finance, employee::gender_t::female, 285'000, "tr539", 1976},
    {"christopher", "jenkins",employee::department_t::marketing, employee::gender_t::male, 295'000, "tr540", 1980},

    {"savannah", "perry",  employee::department_t::it,      employee::gender_t::female, 305'000, "tr541", 1989},
    {"blake", "powell",    employee::department_t::hr,      employee::gender_t::male,   215'000, "tr542", 1994},
    {"riley", "long",      employee::department_t::sales,   employee::gender_t::female, 225'000, "tr543", 1996},
    {"aiden", "patterson", employee::department_t::finance, employee::gender_t::male,   235'000, "tr544", 1983},
    {"stella", "hughes",   employee::department_t::marketing, employee::gender_t::female, 245'000, "tr545", 1986}
    };


    ofstream to_file_full("./employees-full.txt");
    ofstream to_file_summary("./employees-summary.txt");
  
    function<void(employee&)> print_employee_to_console_with_full_details = bind(print_employee,placeholders::_1,ref(cout),full); 
    function<void(employee&)> print_full_employee_to_file = bind(print_employee,placeholders::_1,ref(to_file_full),full); 
    function<void(employee&)> print_plain_employee_to_file = bind(print_employee,placeholders::_1,ref(to_file_summary),plain); 
    function<void(employee&)> print_plain_employee_to_console = bind(print_employee,placeholders::_1,ref(cout),plain); 
    for_each(employees.begin(), employees.end(), print_employee_to_console_with_full_details); 
    for_each(employees.begin(), employees.end(), print_plain_employee_to_console); 
    for_each(employees.begin(), employees.end(), print_full_employee_to_file); 
    for_each(employees.begin(), employees.end(), print_plain_employee_to_file); 
    return 0;
}
