#include <iostream>

// recursive function: halting condition -> recursive structure
auto // must follow the structure given above
factorial(int n){
  if (n==0 || n==1){
     return n;
  } else {
     return factorial(n-1) * n;
  } 
}

auto // must follow the structure given above
factorial2(int n){
  if (n > 1){
     return factorial(n-1) * n;
  } else {
     return 1;
  } 
}

int main(){
    std::cout << "5!: " << factorial2(5) << std::endl;
    return 0;
}
