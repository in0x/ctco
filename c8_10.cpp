#include <stdio.h>
#include <vector>
#include <deque>
#include <unordered_set>

int get_idx(int x, int y, int width) {
    return x + (width * y);
}

bool is_valid_tap(int x, int y, int width, int height) {
    if (x < 0 || x >= width) {
        return false;
    }
    if (y < 0 || y >= height) {
        return false;
    }

    return true;
}

void flood_fill(std::vector<int>& cells, int width, int height, std::pair<int, int> start, int set_to) {
    int start_val = cells[get_idx(start.first, start.second, width)];
    
    std::deque<std::pair<int, int>> queue;
    queue.push_back(start);

    std::unordered_set<int> visited;
    visited.insert(get_idx(start.first, start.second, width));

    while (!queue.empty()) {
        auto [x, y] = queue.front();
        queue.pop_front();

        int idx = get_idx(x, y, width);    
        if (cells[idx] != start_val) {
            continue;
        }

        cells[idx] = set_to;

        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                if ((i == 0) && (j == 0)) continue;

                int n_x = x + i;
                int n_y = y + j;
                int n_idx = get_idx(n_x, n_y, width);

                if (!is_valid_tap(n_x, n_y, width, height)) continue;
                if (visited.find(n_idx) != visited.end()) continue;
                
                queue.push_back({n_x, n_y});
                visited.insert(n_idx);
            }
        }

    }

}

void print_cells(std::vector<int> const& cells, int width) {
    for (size_t i = 0, len = cells.size(); i < len; ++i) {
        if ((i % width) == 0) printf("\n");
        printf("%d ", cells[i]);
    }
    printf("\n");
}

int main(int argc, char** argv) {
    int width = 5;
    int height = 5;

    std::vector<int> cells;
    cells.insert(cells.end(), {0, 0, 0, 0, 0});
    cells.insert(cells.end(), {0, 1, 0, 1, 3});
    cells.insert(cells.end(), {0, 2, 1, 1, 1});
    cells.insert(cells.end(), {0, 0, 2, 1, 1});
    cells.insert(cells.end(), {1, 0, 0, 0, 0});

    printf("Before:\n");
    print_cells(cells, width);

    flood_fill(cells, width, height, {1, 1}, 5);

    printf("After:\n");
    print_cells(cells, width);

    return 0;
}