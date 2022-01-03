#include <stdio.h>
#include <array>
#include <vector>

constexpr size_t WIDTH = 8;
using Columns = std::array<int, WIDTH>;

bool valid(Columns& cols, int row, int col) {
    for (int r = 0; r < row; r++) {
        int c = cols[r];
        if (c == col) {
            return false;
        }

        int col_dist = std::abs(c - col);
        int row_dist = row - r;
        if (col_dist == row_dist) {
            return false;
        }
    }

    return true;
}

void place_queens(int row, Columns cols, std::vector<Columns>& results) {
    if (row == WIDTH) {
        results.push_back(cols);
        return;
    }

    for (int col = 0; col < WIDTH; col++) {
        if (valid(cols, row, col)) {
            cols[row] = col;
            place_queens(row + 1, cols, results);
        }
    }
}

int main(int argc, char** argv) {
    std::vector<Columns> results;
    place_queens(0, {0,0,0,0,0,0,0,0}, results);

    for (Columns const& col : results) {
        for (int r : col) {
            printf("%d", r);
        }
        printf("\n");
    }
    
    return 0;
}