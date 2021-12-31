#include <stdio.h>
#include <vector>
#include <string>
#include <unordered_map>

using CharCount = std::unordered_map<std::string, int>;
using Permuts = std::vector<std::string>;

void get_permuts(std::string const& prefix, CharCount& counts, Permuts& out, int todo) {
    for (auto& [key, value] : counts) {
        assert(value >= 0);
        if (value == 0) {
            continue;
        }

        value -= 1;
        get_permuts(prefix + key, counts, out, todo - 1);
        value += 1;
    }

    if (prefix.length()) {
        out.push_back(prefix);
    }
}

int main(int argc, char** argv) {
    std::string base = "abbbcc";
    // std::string base = "abc";
    CharCount char_counts;
    for (char c : base) {
        std::string s(1, c);
        char_counts[s] += 1;
    }


    Permuts permuts;
    get_permuts("", char_counts, permuts, base.length());

    for (std::string const& s : permuts) {
        printf("%s\n", s.c_str());
    }

    return 0;
}
