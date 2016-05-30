#include <stdio.h>


int to_lower_case(char letter)
{
	// takes a letter, if upper case, returns lowercase, else nothing
	if(letter == '\0'){
		printf("Please enter a word\n");
		return 1;
	}
	int code; // ascii code for each letter
	int errno;
	errno = sscanf(&letter, "%c", &code);
	// printf("the ascii code for %c is %d\n", letter, code);
	if(code > 64 && code < 91) //ascii for uppercase
	{
		code += 32; // ascii code for upper case
		sscanf(&code, "%c", &letter);
		// format the value of ascii code as char and assign to char letter variable
	} 

	return letter;
}

int main(int argc, char *argv[])
{
	if(argc != 2) {
		printf("ERROR: You need only one argument\n");
		// this a typical error message, which aborts the program
		return 1;
	}
	int i = 0;
	for(i = 0; argv[1][i] != '\0'; i++) {
		char letter = argv[1][i];
		letter = to_lower_case(letter);
		switch(letter) {
			case 'a':
				printf("%d: 'a'\n", i);
				break;

			case 'e':
				printf("%d: 'e'\n", i);
				break;

			case 'i':
				printf("%d: 'i'\n", i);
				break;

			case 'o':
				printf("%d: 'o'\n", i);
				break;

			case 'u':
				printf("%d: 'u'\n", i); 
				break;

			case 'y':
				if(i > 2) {
					// it's only sometimes Y
					printf("%d: 'Y'\n", i);
				}
				break;

			default:
				printf("%d: %c is not a vowel\n", i, letter);

		}
	}
	return 0; // the programme ran with '0' errors
}
