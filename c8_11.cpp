#include <stdio.h>
#include <unordered_map>
#include <vector>
#include <array>

using Cache = std::vector<std::array<int, 4>>;

int get_ways(int amount, std::vector<int> const& parts, int idx, Cache& cache) {
    if (cache[amount][idx] != 0) {
        return cache[amount][idx];
    }

    if (idx >= (parts.size() - 1)) {
        return 1;
    }

    int ways = 0;
    for (int i = 0; i <= amount; i += parts[idx]) {
        int remaining = amount - i;
        ways += get_ways(remaining, parts, idx + 1, cache);
    }

    cache[amount][idx] = ways;
    return ways;
}


int main(int argc, char** argv) {
    int n = 100;
    
    Cache cache;
    cache.reserve(n + 1);
    for (int i = 0; i <= n; ++i) {
        cache.push_back({0, 0, 0, 0});
    }

    printf("%d ways\n", get_ways(n, {25, 10, 5, 1}, 0, cache));
    return 0;
}