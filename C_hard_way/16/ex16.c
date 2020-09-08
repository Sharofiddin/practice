#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person {
	char *name;
	int age;
	int height;
	int weight;
};

struct Person *Person_create(char *name, int age, int height,
	       	int weight){
	struct Person *who = malloc(sizeof(struct Person));
	assert(who != NULL);

	who->name = strdup(name);
	who->age = age;
	who->height = height;
	who->weight = weight;

	return who;
}

void Person_destroy( struct Person *who)
{
	assert(who != NULL);

	free(who->name);
	free(who);
}

void Person_print( struct Person *who)
{
		printf("Name: %s\n", who->name);
		printf("\tAge: %d\n", who->age);
		printf("\tHeight: %d\n", who->height);
		printf("\tWeight: %d\n", who->weight);
}

int main(int argc, int *argv[])
{
	struct Person *sharof = Person_create("Sharofiddin Pardayev", 28,165,62);

	struct Person *frank = Person_create("Frank Blank", 20, 172, 65);

	printf("Sharofiddin is at memory location %p:\n", sharof);
	Person_print(sharof);

	printf("Frank is at memory location %p:\n", frank);
	Person_print(frank);

	sharof->age += 20;
	sharof->height += 2;
	sharof->weight -= 10;
	Person_print(sharof);
	
	frank->age += 20;
	frank->weight += 20;
	Person_print(frank);

	/*Person_destroy(sharof);
	Person_destroy(frank);*/


	return 0;
}



