#include <stdio.h>
#include <assert.h>
#include <vector>

using Tower = std::vector<int>;

void move_top(Tower& from, Tower& to) {
    if (to.size() > 0 && from.back() > to.back()) {
        assert(false);
    }

    to.push_back(from.back());
    from.pop_back();
}

void move_disks(int num, Tower& from, Tower& to, Tower& buffer) {
    if (num <= 0) {
        return;
    }

    move_disks(num - 1, from, buffer, to);
    move_top(from, to);
    move_disks(num - 1, buffer, to, from);
}

int main(int argc, char** argv) {
    Tower t1, t2, t3;

    t1.push_back(3);
    t1.push_back(2);
    t1.push_back(1);

    move_disks(3, t1, t3, t2);
    for (int i : t3) {
        printf("%d ", i);
    }
    printf("\n");
}