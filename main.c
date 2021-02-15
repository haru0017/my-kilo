#include <termios.h>
#include <unistd.h>

void enableRawMode() {
    struct termios raw;

    tcgetattr(STDIN_FILENO, &raw);

    raw.c_lflag &= ~(ECHO);

    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

int main() {
    enableRawMode();

    char buf;
    while (read(STDIN_FILENO, &buf, 1) == 1 && buf != 'q');
    return 0;
}