#include "utils.h"
#include "engine.h"
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void configure_io_buffers(void)
{
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IOLBF, 0);
}

void handle_signal(int signal)
{
    if (signal == SIGINT) {
        write(STDOUT_FILENO, "\n", 1);
        fflush(stdout);
        exit(0);
    }
}

void setup_signal_handler(void)
{
    struct sigaction sa;

    sa.sa_handler = handle_signal;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGINT, &sa, NULL);
}

int main(int, char **, char **)
{
    configure_io_buffers();
    setup_signal_handler();
    while (1) {
        engine();
    }
    return 0;
}
