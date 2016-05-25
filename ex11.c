#include <stdio.h>

int main(int argc, char *argv[])
{
	// go through each string in argv

// let's make our own array of strings
	char *states[] = {
		"California", "Oregon", "Washington", 
		"Texas"

	};
	int num_states = 4 + sizeof(argv);


	int i = 0;
	while(i < argc){
		printf("copying arg %d: %s into states\n", i, argv[i]);
		
		states[num_states + i] = argv[i];
		i++;
	}

	int y = 0; // watch out
	while(y < num_states){
		printf("state %d: %s\n", y, states[y]);
		y++;

	}

	// extra credit - use a while loop to copy argv into states


	return 0; //why not just make a void function?
}