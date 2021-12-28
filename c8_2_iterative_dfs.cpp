#include "stdio.h"
#include <vector>
#include <unordered_set>
#include <stdint.h>
#include <assert.h>

// implement iterative DFS
int main(int argc, char** argv) {
    int width = 10;
    int height = 10;

    std::vector<bool> grid;
    grid.resize(10 * 10, true);
    // set some elements to false as impassible

    using u8 = std::uint8_t;
    using Cell = std::pair<int, int>;
    struct QItem {
        Cell cell;
        u8 visits_left;
    };

    struct Local {
        static int get_index(Cell cell, int width) {
            return cell.first + (cell.second * width);
        }
    };

    std::vector<QItem> queue;
    std::vector<Cell> path;
    std::unordered_set<int> visited;

    queue.push_back(QItem{{0, 0}, 2});
    path.push_back({0,0});

    Cell goal = {5 , 5};

    while (!queue.empty()) {
        QItem& current = queue.back();

        if (current.cell == goal) {
            break;
        } else if (current.visits_left == 0) {
            visited.insert(Local::get_index(current.cell, width));
            queue.pop_back();
            path.pop_back();
        } else {
            current.visits_left -= 1;
            Cell next;
            if (current.visits_left == 1) {
                next = {current.cell.first + 1, current.cell.second };
            } else if (current.visits_left == 0) {
                next = {current.cell.first, current.cell.second + 1 };
            } else {
                assert(false);
            }

            if (next.first >= width || next.second >= height) { 
                continue;
            }

            int idx = Local::get_index(current.cell, width);
            if (visited.find(idx) != visited.end()) {
                continue;
            }

            if (!grid[idx]) {
                continue;
            }

            queue.push_back({next, 2});
            path.push_back(next);
        }
    }

    for (Cell const& cell : path) {
        printf("[%d, %d]\n", cell.first, cell.second);
    }
}