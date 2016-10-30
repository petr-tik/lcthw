#include <stdio.h>
#include <string.h>
#include <ctype.h>


int strcpy_lowercase(char *dest, const char *src, size_t n) {
  /* Helper function for the parser. Given a pointer to desination and a pointer to source string with size_t n, copy char elements from src to dest and make them lowercase while copying   */
  size_t i;
  int errno;
  int ascii_code = 0; // ascii code for each letter
  for (i = 0; i < n && src[i] != '\0'; i++) {
    errno = sscanf(&src[i], "%c", &ascii_code);
    if(ascii_code > 64 && ascii_code < 91) //ascii range for uppercase
    {
      ascii_code += 32; // change ascii_code from upper to lower case
    } else // if char isn't in the alphabetic range
    {
      exit(1);
    }     
    sscanf(&ascii_code, "%c", &dest[i]);
    dest[i] = src[i];
} // for end
  for ( ; i < n; i++) {
    dest[i] = '\0';
} // for2 end
  return 0;
}

int main(int argc, char *argv[])
{
  int loop;
  char dest[30];
  strcpy(dest, argv[1]); 

  for(loop=0;loop<strlen(dest);loop++)
    dest[loop]=tolower(dest[loop]);

  printf("%s\n",dest);
  return 0;
}

