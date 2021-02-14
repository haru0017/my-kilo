#include <unistd.h>

int main() {
    char buf;
    while (read(STDIN_FILENO, &buf, 1) == 1 && buf != 'q');
    return 0;
}