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

template<class Sig, class F>
memoize_helper<Sig, std::decay_t<F>>
make_memoized_r(F &&f) {
    return {0, std::forward<F>(f)};
}

int main(){
    std::cout << "fib(10): " << fib(10) << std::endl;
    std::cout << "count: " << count << std::endl;
    auto fib_memoized = make_memoized_r<
            unsigned long long(int)>(
            [](auto& fib, int n) {
                std::cout << "Calculating " << n << "!\n";
                return n == 0 ? 0 : n == 1 ? 1 : fib(n - 1) + fib(n - 2);
            });
    fib_memoized(1);
    fib_memoized(2);
    fib_memoized(3);
    fib_memoized(4);
    fib_memoized(5);
    fib_memoized(6);
    count=0;
    fib_memoized(7);
    std::cout << "count: " << count << std::endl;
    count=0;
    fib_memoized(8);
    std::cout << "count: " << count << std::endl;
    count=0;
    fib_memoized(9);
    std::cout << "count: " << count << std::endl;
    fib_memoized(10);
    count = 0;
    std::cout << "fib_memoized(10): " << fib_memoized(10) << std::endl;
    std::cout << "count: " << count << std::endl;
    return 0;
}
