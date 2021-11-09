#include <linux/input.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {

    printf("ESC - is the key to exit and save output to ex3.txt\n");

    FILE *out = fopen("ex2.txt", "w");

    int keyboard = open("/dev/input/by-path/platform-i8042-serio-0-event-kbd", O_RDONLY);
    struct input_event ievent;

    
    read(keyboard, &ievent, sizeof(ievent));
    while (1) {
        if(ievent.type == EV_KEY && ievent.value == 0) {
            fprintf(out, "RELEASED 0x%04x (%i)\n", ievent.code, ievent.code);
        }
        if(ievent.type == EV_KEY && ievent.value == 1) {
            fprintf(output, "PRESSED 0x%04x (%i)\n", ievent.code, ievent.code);
        }
        if (ievent.type == EV_KEY && ievent.code == KEY_ESC) {
            break;
        }
    }
    fclose(out);
    close(keyboard);

    return 0;
}
