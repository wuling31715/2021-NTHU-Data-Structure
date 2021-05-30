#include <stdio.h>
#include <string.h>

void swap(char &a, char &b) {
    char tmp = a;
    a = b;
    b = tmp;
}

int main(void) {
    char s[100] = "";
    scanf("%s", s);
    printf("%s\n", s);
    for (size_t i = 0; i < strlen(s) / 2; ++i) {
        swap(s[i], s[strlen(s) - i - 1]);
    }
    printf("%s\n", s);
    return 0;
}