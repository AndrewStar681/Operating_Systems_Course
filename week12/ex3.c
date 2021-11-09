#include <linux/input.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {

    printf("ESC - is the key to exit and save output to ex3.txt\n");
    printf("TRY: P+A+C; P+E, C+E\n");

    FILE *out = fopen("ex3.txt", "w");

    int *keysPressed = calloc(300, sizeof(int));

    int keyboard = open("/dev/input/by-path/platform-i8042-serio-0-event-kbd", O_RDONLY);
    struct input_event ievent;

    while (1)
    {
        read(keyboard, &ievent, sizeof(ievent));
        if(ievent.type == EV_KEY && ievent.value == 0) {
            keysPressed[(int) ievent.code] = 0;
            fprintf(out, "RELEASED 0x%04x (%i)\n", ievent.code, ievent.code);
        }
        if(ievent.type == EV_KEY && ievent.value == 1) {
            keysPressed[(int) ievent.code] = 1;
            fprintf(out, "PRESSED 0x%04x (%i)\n", ievent.code, ievent.code);
        }
        for (int i = 0; i < 300; i++) {
            if (keysPressed[46] == 1 && keysPressed[30] == 1 && keysPressed[25] == 1) {
                fprintf(out, "Get some cappuccino!\n");
            }
            if (keysPressed[25] == 1 && keysPressed[18] == 1) {
                fprintf(out, "I passed the exam!\n");
            }
            if (keysPressed[18] == 1 && keysPressed[46] == 1) {
                fprintf(out, "Great work!\n");
            }
        }
        if (ievent.type == EV_KEY && ievent.code == KEY_ESC) {
            break;
        }
    }
    fclose(out);
    close(keyboard);

    return 0;
}
