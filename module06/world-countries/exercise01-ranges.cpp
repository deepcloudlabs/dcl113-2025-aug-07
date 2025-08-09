/**
 * @author Binnur Kurt <binnur.kurt@gmail.com>
 */
#include "city.h"
#include "country.h"
#include "world-util.h"

#include <set>
#include <map>
#include <iostream>
#include <string>
#include <memory>
#include <algorithm>
#include <ranges>

using namespace std;
using namespace world;

map<int, shared_ptr<city>> cities;
map<string, shared_ptr<country>> countries;

void print_continent(const string &continent) {
    cout << continent << "\t";
}

int main() {
    create_world();
    auto continents = std::ranges::to<std::set<string>>(
                            countries | views::values 
                                      | views::transform([](auto p){return p->continent;})
           );
    for(auto cont: continents){
      cout << cont << endl;
    }
    return 0;
}
