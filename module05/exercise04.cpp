#include <iostream>
#include "utility.h"

int count = 0;

long long 
fib(int n){
     count++;
  if (n == 0 || n==1){
     return n;
  } else {
     return fib(n-1) + fib(n-2);
  } 
}

int add(int u,int v){
  std::cout << "add(" << u << "," << v << ")" << std::endl;
  return u+v;
}

int main(){
    std::cout << "fib(10): " << fib(10) << std::endl;
    std::cout << "count: " << count << std::endl;
    auto fib_memoized = make_memoized(fib);
    fib_memoized(1);
    fib_memoized(2);
    fib_memoized(3);
    fib_memoized(4);
    fib_memoized(5);
    fib_memoized(6);
    fib_memoized(7);
    fib_memoized(8);
    fib_memoized(9);
    fib_memoized(10);
    count = 0;
    std::cout << "fib_memoized(10): " << fib_memoized(10) << std::endl;
    std::cout << "count: " << count << std::endl;
    auto add_memoized = make_memoized(add);
    add_memoized(3,5);
    add_memoized(3,5);
    add_memoized(3,5);
    add_memoized(3,5);
    add_memoized(3,5);
    add_memoized(3,5);
    add_memoized(3,5);
    add_memoized(3,5);
    add_memoized(3,5);
    return 0;
}
