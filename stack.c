#include<stdio.h>
#include<string.h>

int stack[100000];
int length;

void push(int data);
void pop();
int peek();

int main()
{
	push(10);
	push(20);
	push(30);
	push(40);
	push(50);
	printf("%d\n",peek());
	pop();
	pop();
	printf("%d\n", peek());
}

void push(int data)
{
	stack[length] = data;
	length++;
}

void pop()
{
	stack[length - 1] = 0;
	length--;
}

int peek()
{
	return stack[length - 1];
}