#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct EvenNumber {
    bool operator()(const int& n){
          return n%2 == 0;
    }
};

template<char delimeter_char>
struct PrintNumber {
    void operator()(const int& n){
          cout << n << delimeter_char;
    }
};

struct ToCubed {
    int operator()(const int& n){
         return n*n*n;
    }
};

struct Sum {
    int operator()(int accumulator,const int& n){
         return accumulator + n;
    }
};

int main() {
    vector<int> numbers{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // numbers -> filter if even -> map to cubed -> reduce to their sum
    // filter even numbers
    vector<int> even_numbers;
    copy_if(numbers.begin(),numbers.end(),back_inserter(even_numbers), EvenNumber{});
    for_each(even_numbers.begin(),even_numbers.end(),PrintNumber<','>{}); cout << endl;
    // map to their cubes
    vector<int> cubed_numbers;
    transform(even_numbers.begin(),even_numbers.end(),back_inserter(cubed_numbers), ToCubed{});
    for_each(cubed_numbers.begin(),cubed_numbers.end(),PrintNumber<':'>{}); cout << endl;
    // reduce the numbers to their sum
    auto sum = accumulate(cubed_numbers.begin(),cubed_numbers.end(),int{},Sum{});
         sum = accumulate(cubed_numbers.begin(),cubed_numbers.end(),int{},plus<int>{});
    cout << "sum is " << sum << endl;
    return 0;
}
