#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[])
{
    char *str = "priteshtaral";
    int length;
    length = strlen(str);
    printf("\nString '%s' has length %d and is in memory at address: %p \n", str, length, str);
}