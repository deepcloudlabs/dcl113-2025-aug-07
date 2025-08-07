#include <vector>
#include <iostream>
#include <parallel/algorithm>
#include <functional>

#include "employee.h"

using namespace std;

void
print_employee(employee& emp){
   cout << emp << endl;
}

struct PrintEmployee { // function object
   void
   operator()(employee& emp){
       cout << emp << endl;
   }

};

int main(){
       vector<employee> employees{
            {"james",  "sawyer",   employee::department_t::it,      employee::gender_t::male,   250'000, "tr100", 1982},
            {"kate",   "austen",   employee::department_t::sales,   employee::gender_t::female, 350'000, "tr200", 1986},
            {"juliet", "burke",    employee::department_t::finance, employee::gender_t::female, 550'000, "tr300", 1988},
            {"jack",   "shephard", employee::department_t::hr,      employee::gender_t::male,   450'000, "tr400", 1978},
            {"jack",   "bauer",    employee::department_t::it,      employee::gender_t::male,   150'000, "tr500", 1956}
       };
       // imperative: external loop
       for (auto &employee: employees){
           cout << employee << endl;
       }

       // declarative: internal loop -> functional programming: --> I. STL <-- II. #include <ranges>
       // for_each: stl, HoF 
       // i) lambda expression
       auto print_employee_lambda = [](employee &emp){ cout << emp << endl; } ;
       function<void(employee&)> print_employee_lambda_function = [](employee &emp) -> void { cout << emp << endl; } ; 
       for_each(employees.begin(),employees.end(),[](employee &emp){ cout << emp << endl; });
       for_each(employees.begin(),employees.end(),print_employee_lambda);
       for_each(employees.begin(),employees.end(),print_employee_lambda_function);
       // ii) ordinary c functions
       for_each(employees.begin(),employees.end(),print_employee);
       // iii) function object
       for_each(employees.begin(),employees.end(),PrintEmployee{});

       return 0;
}
