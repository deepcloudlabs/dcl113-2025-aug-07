#include <iostream>
#include <vector>
#include <functional>
#include <numeric>

using namespace std;

int main() {
    vector<int> ages {32,44,42,27,23,55,35,22,58};
    function<bool(int,int)> ascending_order = [](int p,int q){return p < q;};
    function<bool(int,int)> descending_order = [](int p,int q){return p > q;};
    function<bool(int,int)> descending_order2 = bind(ascending_order,placeholders::_2,placeholders::_1);
    function<bool(int,int)> descending_order3 = [ascending_order](int x,int y) -> bool {return ascending_order(y,x);};
    for_each(ages.begin(),ages.end(),[](int n){cout << n << " ";}); cout << endl;
    sort(ages.begin(),ages.end(),ascending_order);
    for_each(ages.begin(),ages.end(),[](int n){cout << n << " ";}); cout << endl;
    sort(ages.begin(),ages.end(),descending_order3);
    for_each(ages.begin(),ages.end(),[](int n){cout << n << " ";}); cout << endl;
    return 0;
}
