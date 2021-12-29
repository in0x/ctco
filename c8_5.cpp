#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <unordered_map>
// 8 x 8 
// mul(8, 8) // 64
// mul(4, 8) // 32
// mul(2, 8) // 16
// mul(1, 8) // 8
              
// 8 x 7
// = mul(3, 8) + mul(4, 8)
// = mul(1, 8) + mul(2, 8) + mul(4, 8) // 56

// mul(3, 8) // 24
// = 
// mul(2, 8) // 16
// mul(1, 8) // 8
// +
// mul(1, 8) // 8

// +

// mul(4, 8) // 32 NOTE: 4 = [7 - 3]
// mul(2, 8) // 16
// mul(1, 8) // 8

using u32 = uint32_t;
using Cache = std::unordered_map<u32, u32>;

u32 multiply(u32 sml, u32 lrg, Cache& cache);

u32 recursive_multiply(u32 a, u32 b, Cache& cache) {
    int sml = a < b ? a : b;
    int lrg = a > b ? a : b;
    return multiply(sml, lrg, cache); 
}

u32 multiply(u32 sml, u32 lrg, Cache& cache) {
    assert(sml <= lrg);
    if (sml == 1) { return lrg; }
    
    auto found = cache.find(sml);
    if (found != cache.end()) {
        return found->second;
    }

    u32 half_sml = sml >> 1;
    u32 side1 = recursive_multiply(half_sml, lrg, cache);
    u32 total = 0;
    if (sml & 1) {
        total = side1 + recursive_multiply(sml - half_sml, lrg, cache);
    } else {
        total = side1 + side1;
    }

    cache.insert({sml, total});
    return total;
}

int main(int argc, char** argv) {
    Cache cache;
    printf("%u\n", recursive_multiply(23, 17, cache));
    return 0;
}