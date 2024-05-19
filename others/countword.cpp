#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

char s[3000009];

signed main() {
    int cnt = 0;
    while (fgets(s, sizeof(s), stdin) != NULL) {
        int word = 0;
        for (int i = 0; i < strlen(s); i++) {
            if (s[i] != ' ' && s[i] != '\n') {
                word = 1;
            }
            if (s[i] == ' ' || s[i] == '\n') {
                cnt += word;
                word = 0;
            }
        }
    }
    printf("%d", cnt);
}
