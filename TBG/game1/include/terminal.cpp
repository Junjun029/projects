#include <asm-generic/ioctls.h>
#include <csignal>
#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>
#include <signal.h>

void lock_terminal_size(unsigned short rows, unsigned short cols) {
    // Ignore the window change signal
    signal(SIGWINCH, SIG_IGN);

    // set the new terminal size 
    struct winsize ws;
    ws.ws_row = rows;
    ws.ws_col = cols;
    ws.ws_xpixel = 0;
    ws.ws_ypixel = 0;

    if (ioctl(STDOUT_FILENO, TIOCSWINSZ, &ws) == -1) {
        std::cerr << "Failed to set terminal size." << std::endl;
    }
}
