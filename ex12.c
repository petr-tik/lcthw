#include <stdio.h> 

int main(int argc, char *argv[])
{
	int i = 0;

	if(argc == 1){
		printf("You have no arguments - that's boring\n");
	} else if(argc > 1 && argc < 4){
		printf("here are your arguments:\n");
		for(i = 1; i <= argc; i++){
			printf("%s\n", argv[i]);
		} 
		printf("\n~~~~~~~~~~~\n");
	} else {
		printf("You have more than 4 arguments. I can't handle the truth! \n");

	}
	return 0;
}
