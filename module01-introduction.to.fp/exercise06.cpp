#include <fstream>
#include <iostream>
#include <vector>
#include <ranges>
#include <functional>

using namespace std;

// problem: data
std::vector<std::string> file_names{
    std::string("/mnt/d/tmp/file1.txt"),
    std::string("/mnt/d/tmp/file2.txt"),
    std::string("/mnt/d/tmp/file3.txt"),
    std::string("/mnt/d/tmp/file4.txt"),
    std::string("/mnt/d/tmp/file5.txt")
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
open_file(const string& file){
    cout << "open_file(" << file << ")" << endl;
    return ifstream(file);
}

int
count_lines_in_file(ifstream input_file){
    cout << "count_lines_in_file()" << endl;
    return count(istreambuf_iterator<char>(input_file),istreambuf_iterator<char>(),'\n')+1;
}


int main() {
    std::vector<int> line_counts{};
    for (int count: file_names | ranges::views::transform(open_file) | ranges::views::transform(count_lines_in_file)
    ) {
        std::cout << "[for] line count: " << count << std::endl;
    }
    return 0;
}
