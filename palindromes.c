#include <string.h>
#include <stdio.h>

int is_palindrome(char *word) {
    /* Given a pointer to a string, return 1 if palindrome, 0 otherwise*/ 
    int length = sizeof(char)*strlen(word);
    for (int idx = 0; idx < length/2; idx++)
    {
        char left_char = word[idx];
        char right_char = word[length - 1 - idx];
        if (left_char != right_char)
        {
            return 0;
        }

    }
    return 1;
}

int smallest_palindrome(char *word) {
    /* Given a long string (very long) 
    return the length of the smallest substring-palindrome
    
    */

    int length = sizeof(char)*strlen(word);
    int res = 0;

    for (int idx = 1; idx < length; idx++)
    {
        char prev = word[idx - 1];
        char cur = word[idx];
        char next = word[idx + 1];

        if (prev == cur || cur == next) 
        {
            res = 2;
            return res;
        } else if (prev == next) {
            res = 3;
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    int res;
    
    char *word2 = "abcgfdlk"; 
    res = smallest_palindrome(word2);
    printf("%d\n", res);

    return 0;
}