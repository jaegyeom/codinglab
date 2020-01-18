#include<stdio.h>

typedef struct PERSON
{
	int age;
	float height;
	float weight;
	char name[10];
}Person;

int main()
{
	Person person;
	scanf("%d", &person.age);
	scanf("%f", &person.height);
	scanf("%f", &person.weight);
	scanf("%s", person.name);


	printf("%d\n", person.age);
	printf("%f\n", person.height);
	printf("%f\n", person.weight);
	printf("%s\n", person.name);
}