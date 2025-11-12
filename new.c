#include <stdio.h>
#include <string.h>

int main() {
    char arr[] = "i am cool";
    printf("%s\n", arr);
    char *p = strtok(arr," ");
    printf("%s\n", arr);
    return 0;
}