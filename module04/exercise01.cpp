#include <iostream>
#include <functional>
#include <numeric>

using namespace std;

bool is_larger(int x,int y){
   return x > y;
}

template <class T>
struct Topla {
   T operator()(T m,T n){
      return m+n;
   }
};

int main() {
    function<bool(int,int)> fun = is_larger;
    function<bool(int,int)> gun = greater<>();
    function<int(int,int)> sun = Topla<int>{};
    function<int(int,int)> tun = plus<int>{};
    cout << (fun(5,3) ? "5 is larger than 3" : "5 is smaller than 3")  << endl; 
    cout << (gun(5,3) ? "5 is larger than 3" : "5 is smaller than 3")  << endl; 
    cout << "3+5 is " << sun(3,5) << endl ;
    cout << "3+5 is " << tun(3,5) << endl ;
    return 0;
}
