#include <iostream>
#include <vector>
#include <functional>
#include <numeric>

using namespace std;

int main() {
    vector<int> ages {32,44,42,27,23,55,35,22,58};
    function<bool(int,int)> is_greater = greater<>();
    // is_older_than_50: bool(int)
    // partial function
    function<bool(int)> is_older_than_50 = bind(is_greater,placeholders::_1,50);
    auto number_of_employees_older_than_50 = count_if(ages.begin(),ages.end(),is_older_than_50);
    cout << "Number of employees older than 50: " << number_of_employees_older_than_50 << endl;
    return 0;
}
