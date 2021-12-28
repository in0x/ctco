#include "stdio.h"
#include <unordered_map>
#include <stdint.h>

using u64 = uint64_t;
using Cache = std::unordered_map<u64, u64>;

u64 climb(u64 n, u64 cur, Cache& cache) {
    if (cur == n) {
        return 1;
    } else if (cur > n) {
        return 0;
    }

    auto cached = cache.find(cur);
    if (cached != cache.end()) {
        return cached->second;
    }

    u64 total = climb(n, cur + 3, cache) +
                climb(n, cur + 2, cache) +
                climb(n, cur + 1, cache);

    cache[cur] = total;
    return total;
}

int main(int argc, char** argv) {
    Cache cache;
    u64 n = 37;

    printf("%llu ways\n", climb(n, 0, cache));
    return 0 ;
}