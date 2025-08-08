#include <iostream>
#include <map>

int count = 0;

std::map<int,long long> cache{
  {0, 0},
  {1, 1}
};

long long 
fib(int n){
  auto cached_value = cache.find(n);
  if (cached_value != cache.end()){
     return cached_value->second;
  } else {
     count++;
     long long result = fib(n-1) + fib(n-2);
     cache[n] = result;
     return result;
  } 
}

int main(){
    std::cout << "fib(200): " << fib(200) << std::endl;
    std::cout << "count: " << count << std::endl;
    std::cout << "cache size: " << cache.size() << std::endl;
    std::cout << cache.find(200)->second << std::endl;
    return 0;
}
