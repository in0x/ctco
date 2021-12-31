#include <stdio.h>
#include <string>

void print_paren(int open, int closed, std::string s) {
    if (open == 0 && closed == 0) {
        printf("%s\n", s.c_str());
        return;
    }

    if (open) {
        print_paren(open - 1, closed, s + "(");
    }

    if (open < closed) {
        print_paren(open, closed - 1, s + ")");
    }
}

int main(int argc, char** argv) {
    print_paren(3, 3, "");
    return 0;
}