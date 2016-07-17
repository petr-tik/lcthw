#include <stdio.h>

void print_states(char *states[], int num_states) {
  int idx = 0;
  while(idx < num_states) {
    printf("State %d: %s\n", idx, states[idx]);
    idx++;
  }
}

int main(int argc, char *argv[])
{
// go through each string in argv
// done and refactored
// let's make our own array of strings


	int start_num_states = 4;
	int new_states = start_num_states + argc - 1;
	char *states[] = {
		"California", "Oregon", "Washington", 
		"Texas"
	};
	if(argc == 1){
		printf("I don't need to copy anything - great. \n");
	}
	
	// extra credit - use a while loop to copy argv into states

	int idx = 1;
	while(idx < argc){
		printf("copying arg %d: %s into states\n", idx, argv[idx]);
                states[start_num_states + idx - 1] = argv[idx];
                //printf("%d/%d\n", new_states - idx, idx - 1);
		idx++;
	};

        print_states(states, new_states);
	return 0; //why not just make a void function?
};

// failing 
// *** stack smashing detected ***: ./ex11 terminated
// ==12984== 
// ==12984== Process terminating with default action of signal 6 (SIGABRT)
