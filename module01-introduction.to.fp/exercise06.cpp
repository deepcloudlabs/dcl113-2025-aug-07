#include <fstream>
#include <iostream>
#include <vector>
#include <ranges>
#include <functional>

using namespace std;

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
    std::cout << "[open_file] Opening file " << file << std::endl;
    return std::ifstream(file);
}

auto
count_lines(std::ifstream &input_file) {
    auto line_count = 1;
    char c;
    // external loop
    while (read_one_char(input_file,c)) {
        if (is_new_line(c)) {
            line_count++;
        }
    }
    std::cout << "[count_lines] " << line_count << std::endl;
    return line_count;
}

int main() {
    std::vector<int> line_counts{};
    for (int count: file_names | ranges::views::transform(open_file)
    ) {
        std::cout << "[for] line count: " << count << std::endl;
    }
    return 0;
}