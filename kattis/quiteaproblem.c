#include <stdio.h>
#include <string.h>

char buf[1003];

int main() {
    while (gets(buf)) {
        if (strcasestr(buf, "problem") != NULL) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }
    return 0;
}
