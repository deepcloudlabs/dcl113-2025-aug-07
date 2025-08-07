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

auto
order_by_salary_desc(employee &left,employee &right){
     return left.getMSalary() > right.getMSalary();
}

auto
order_by_salary_asc(employee &left,employee &right){
     return left.getMSalary() < right.getMSalary();
}

auto
order_by_age_asc(employee &left,employee &right){
     return left.getMBirthYear() > right.getMBirthYear();
}

auto
order_by_age_desc(employee &left,employee &right){
     return left.getMBirthYear() < right.getMBirthYear();
}

template<class T, class OrderBy, class CompareBy>
decltype(auto)
getOrder(OrderBy orderBy, CompareBy compareBy) { // Generic HoF
    return [orderBy, compareBy](const T &left, const T &right) {
        return compareBy(orderBy(left), orderBy(right));
    };
}


template<typename T>
struct Order { 
    virtual bool operator()(const T &left, const T &right) = 0;
};

template<typename T>
struct AscendingOrder : public Order<T> { // Function Object
    virtual bool operator()(const T &left, const T &right) {
        return left < right;
    }
};

template<typename T>
struct DescendingOrder : public Order<T> { // Function Object
    virtual bool operator()(const T &left, const T &right) {
        return left > right;
    }
};

auto
orderBySalary(const employee &emp){
    return emp.getMSalary();
}

auto
orderByBirthYear(const employee &emp){
    return emp.getMBirthYear();
}

template <class T>
bool
ascOrder(const T&x,const T&y){
   return x < y;
}

template <class T>
bool
descOrder(const T&x,const T&y){
   return x > y;
}

int main(){
       vector<employee> employees{
            {"james",  "sawyer",   employee::department_t::it,      employee::gender_t::male,   250'000, "tr100", 1982},
            {"kate",   "austen",   employee::department_t::sales,   employee::gender_t::female, 350'000, "tr200", 1986},
            {"juliet", "burke",    employee::department_t::finance, employee::gender_t::female, 550'000, "tr300", 1988},
            {"jack",   "shephard", employee::department_t::hr,      employee::gender_t::male,   450'000, "tr400", 1978},
            {"jack",   "bauer",    employee::department_t::it,      employee::gender_t::male,   150'000, "tr500", 1956}
       };
       for_each(employees.begin(),employees.end(),print_employee);
       sort(employees.begin(),employees.end(),order_by_salary_desc);
       cout << " after sorting:" << endl;
       for_each(employees.begin(),employees.end(),PrintEmployee{});
       sort(employees.begin(),employees.end(),order_by_salary_asc);
       cout << " after sorting:" << endl;
       for_each(employees.begin(),employees.end(),PrintEmployee{});
       sort(employees.begin(),employees.end(),order_by_age_asc);
       cout << " after sorting:" << endl;
       for_each(employees.begin(),employees.end(),PrintEmployee{});
       sort(employees.begin(),employees.end(),order_by_age_desc);
       cout << " after sorting:" << endl;
       for_each(employees.begin(),employees.end(),PrintEmployee{});
       sort(employees.begin(),employees.end(),getOrder<employee>(orderBySalary,ascOrder<double>));
       cout << " after sorting:" << endl;
       for_each(employees.begin(),employees.end(),PrintEmployee{});
       sort(employees.begin(),employees.end(),getOrder<employee>(orderByBirthYear,descOrder<int>));
       cout << " after sorting:" << endl;
       for_each(employees.begin(),employees.end(),PrintEmployee{});
       return 0;
}
