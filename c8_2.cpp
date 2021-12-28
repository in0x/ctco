#include "stdio.h"
#include <vector>
#include <unordered_set>
#include <stdint.h>
#include <assert.h>

using u8 = std::uint8_t;
using Cell = std::pair<int, int>;
using Grid = std::vector<bool>;
using Path = std::vector<Cell>;
using Cache = std::unordered_set<int>;

static int get_index(Cell cell, int width) {
    return cell.first + (cell.second * width);
}

bool path_to(Path& path, Cache& cache, Grid const& grid, int width, int height, Cell cell, int& steps) {
    int idx = get_index(cell, width);
    
    if (cell.first >= width || cell.second >= height || !grid[idx]) {
        return false;
    }

    if (cache.find(idx) != cache.end()) {
        return false;
    }

    steps += 1;

    // if ((cell.first == (width - 1) && cell.second == (height - 1)) ||
    if ((cell.first == 6 && cell.second == 6) ||
        path_to(path, cache, grid, width, height, {cell.first, cell.second + 1}, steps) ||
        path_to(path, cache, grid, width, height, {cell.first + 1, cell.second}, steps)) {
        
        path.push_back(cell);
        return true;
    }

    cache.insert(idx);
    return false;
}

Path path_to_origin(Grid const& grid, int width, int height) {
    Path path;
    Cache cache;
    int steps = 0;
    path_to(path, cache, grid, width, height, {0, 0}, steps);
    printf("Took %d steps\n", steps);
    return path;
}

int main(int argc, char** argv) {
    int width = 10;
    int height = 10;

    std::vector<bool> grid;
    grid.resize(10 * 10, true);
    grid[get_index({5, 6}, width)] = false;
    // set some elements to false as impassible

    Path path = path_to_origin(grid, width, height);
    for (Cell const& cell : path) {
        printf("[%d,%d]\n", cell.first, cell.second);
    }
}