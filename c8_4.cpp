#include "stdio.h"
#include "assert.h"
#include <vector>

using Set = std::vector<int>;

std::vector<Set> get_permuts_with_len(size_t len, Set const& base_set) {
    if (len == 0) {
        return { Set() };
    }

    std::vector<Set> permuts = get_permuts_with_len(len - 1, base_set);
    for (size_t i = 0, prev_count = permuts.size(); i < prev_count; ++i) {
        Set copy = permuts[i];
        copy.push_back(base_set[len - 1]);
        permuts.push_back(copy);
    }

    return permuts;
}

std::vector<Set> get_all_subsets(Set const& set) {
    return get_permuts_with_len(set.size(), set);
}

void all_permutations_bits(Set const& base_set) {
    assert(base_set.size() <= 64);

    size_t num_permuts = 1 << base_set.size();
    for (size_t i = 0; i < num_permuts; ++i) {
        printf("{ ");

        for (size_t bit = 0; bit < 64; ++bit) {
            size_t idx = (1llu << bit);
            if (i & idx) {
                printf("%d ", base_set[bit]);
            }
        }

        printf("}\n");
    }
}

int main(int argc, char** argv) {
    Set const base = {1, 2, 3, 4};
    std::vector<Set> permutations = get_all_subsets(base);

    printf("Recursive:\n");
    for (Set const& permut : permutations) {
        printf("{ ");
        for (int i : permut) {
            printf("%d ", i);
        }
        printf("}\n");
    }

    printf("Bits:\n");
    all_permutations_bits(base);

    return 0;
}