#include <vector>

int main(int argc, char** argv) {
    // std::vector<int> arr = {-3, 0, 1, 2, 3, 4, 6, 8, 9}; // len = 9
    // std::vector<int> arr = {-40, -20, -1, 1, 2, 3, 5, 7, 9, 12, 13};
    std::vector<int> arr = {-40, -20, -1, 1, 2, 3, 5, 7, 9, 12, 13, 49}; 
    // std::vector<int> arr = {-40, -20, 2, 3, 5, 6, 9, 10, 11, 12, 30, 49}; 
    // std::vector<int> arr = {-40, -20, 2, 4, 5, 6, 9, 10, 11, 12, 30, 49}; 

    size_t l = 0;
    size_t r = arr.size() - 1;

    while (l <= r) {
        size_t mid = (l + r) / 2;

        if (arr[mid] == (int)mid) {
            printf("Magic idx: %zu\n", mid);
            break;
        }
        else if (arr[mid] < (int)mid) {
            // check right partition
            l = mid + 1;
        } 
        else {
            // check left partition
            r = mid - 1;
        }
    }

    return 0;
}