#include <stdio.h>
main(){
	char *name; int age; float weight;
	printf("%s", "Please enter your name: \n");
	scanf("%s",name);
	printf("%s", "Now please enter your age: \n\n");
	scanf("%d", &age);
	printf("%s", "How much do you weight: \n\n");
	scanf("5.2f", &weight);
	printf("Hello %s, you are %d years old and weigh %fkg \n\n", *name, age, weight);
	return 0;
}
