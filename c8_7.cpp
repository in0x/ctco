#include <stdio.h>
#include <string>
#include <vector>

using Permuts = std::vector<std::string>;

Permuts get_permutations(std::string const& base_str, int idx) {
    if (idx < 0) {
        return { { "" } };
    }

    Permuts permuts = get_permutations(base_str, idx - 1);

    for (size_t i = 0, num_p = permuts.size(); i < num_p; ++i) {
        for (size_t c = 0, p_len = permuts[i].length(); c <= p_len; ++c) {
            std::string const& from = permuts[i];
            std::string cpy = from.substr(0, c) + base_str[idx];
            if (c != p_len) {
                cpy += from.substr(c, p_len - c);
            }
            permuts.push_back(cpy);
        }
    }

    return permuts;   
}

int main(int argc, char** argv) {
    // std::string base = "abcd";
    // Permuts permuts = get_permutations(base, base.size() - 1);
    // for (std::string const& p : permuts) {
    //     printf("%s\n", p.c_str());
    // }

    std::string base = "abc";

    Permuts permuts;
    permuts.push_back("");

    for (size_t i = 0, blen = base.size(); i < blen; ++i) {

        for (size_t p = 0, plen = permuts.size(); p < plen; ++p) {

            for (size_t c = 0, clen = permuts[p].size(); c <= clen; ++c) {
                std::string const& from = permuts[p];
                std::string cpy = from.substr(0, c) + base[i];
                if (c != clen) {
                    cpy += from.substr(c, clen - c);
                }

                permuts.push_back(cpy);
            }
        }
    }

    for (std::string const& p : permuts) {
        printf("%s\n", p.c_str());
    }

    return 0;
}