#include <iostream>
int count = 0;
/*
     fib(0) -> 1
     fib(1) -> 1
     fib(2) -> fib(1) + fib(0)
     fib(3) -> fib(2),fib(1), fib(1), fib(0)
     fib(4) -> fib(3) -> fib(2) -> fib(1)
                         fib(1)

     O(2^n)
*/
auto 
fib(int n){
  count++;
  if (n==0){
     return 0;
  } else if(n==1){
     return 1;
  } else {
     return fib(n-1) + fib(n-2);
  } 
}

int main(){
    std::cout << "fib(20): " << fib(20) << std::endl;
    std::cout << "count: " << count << std::endl;
    return 0;
}
