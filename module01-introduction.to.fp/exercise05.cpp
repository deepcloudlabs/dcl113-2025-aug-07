#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
// problem: data
std::vector<std::string> file_names{
    std::string("d:\\tmp\\file1.txt"),
    std::string("d:\\tmp\\file2.txt"),
    std::string("d:\\tmp\\file3.txt"),
    std::string("d:\\tmp\\file4.txt"),
    std::string("d:\\tmp\\file5.txt")
};

// declarative programming: functional programming
// pipeline
inline
auto
is_new_line(char c) {
    return c == '\n';
}

auto&
read_one_char(std::ifstream& input,char &c) {
    return input.get(c);
}

auto
open_file(const std::string& file) {
    return std::ifstream(file);
}

auto
map_file_to_line_counts(const std::string &file_name) {
    std::ifstream input_file(file_name);
    auto line_count = 1;
    char c;
    // external loop
    while (read_one_char(input_file,c)) {
        if (is_new_line(c)) {
            line_count++;
        }
    }
    return line_count;
}

int main() {
    std::vector<int> line_counts{};
    // Higher-Order Function (HoF)
    // Internal Loop -> transform
    // vector<string> -- map --> vector<int> -- reduce --> int
    std::transform(file_names.begin(),file_names.end(),std::back_inserter(line_counts),map_file_to_line_counts);
    auto total_line_counts = std::accumulate(line_counts.begin(),line_counts.end(),int(),std::plus<int>{});
    std::cout << total_line_counts << std::endl;
    return 0;
}