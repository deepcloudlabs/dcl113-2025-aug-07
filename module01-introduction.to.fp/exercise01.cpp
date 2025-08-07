#include <fstream>
#include <iostream>
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

// imperative programming: procedural programming
// global data: solution
int total_line_count = 0;

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
count_lines_imperative(const std::string &file) {
    std::ifstream input_file = open_file(file);
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

auto
count_lines_imperative(const std::vector<std::string> &files) {
    auto total_lines = 0;
    // external loop
    for (auto& file : files) {
        const auto line_count = count_lines_imperative(file);
        total_lines += line_count;
    }
    return total_lines;
}

int main() {
    ::total_line_count = count_lines_imperative(::file_names);
    std::cout << ::total_line_count << std::endl;
    return 0;
}