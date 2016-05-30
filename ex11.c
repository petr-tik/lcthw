#include <stdio.h>

int main(int argc, char *argv[])
{
// go through each string in argv
// done and refactored
// let's make our own array of strings
	char *states[] = {
		"California", "Oregon", "Washington", 
		"Texas"
	};
	int start_num_states = 4;
	int num_states = 4 + argc - 1;

	int i = argc;
	if(argc == 1){
		printf("I don't need to copy anything - great. \n");
	}
	else {
	// extra credit - use a while loop to copy argv into states
		while(i > 1){
			printf("copying arg %d: %s into states\n", i, argv[i - 1]);
			
			states[start_num_states + i - 2] = argv[i - 1];
			printf("%d/%d\n", start_num_states + i - 2, num_states - 1);
			i--;
		};
	}
	int y = 0; // watch out
	while(y < num_states){
		printf("state %d: %s\n", y, states[y]);
		y++;
	};	
	return 0; //why not just make a void function?
};

// failing 
// *** stack smashing detected ***: ./ex11 terminated
// ==12984== 
// ==12984== Process terminating with default action of signal 6 (SIGABRT)
