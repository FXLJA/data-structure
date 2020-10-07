#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int n;
int i;
struct Data{
	char c;
	struct Data *next, *prev;
}*head, *curr, *tail;

void pushHead(char c){
	curr=(struct Data *) malloc(sizeof(struct Data));
	curr->c = c;
	curr->next=NULL;
	
	if(head==NULL){
		head=tail=curr;
	}else{
		curr->next=head;
		curr->prev=curr;
		head=curr;
	}
}

void popHead(){
	if(head){
		curr = head;
		if(head == tail){
			head=NULL;
			tail=NULL;
		}
		else{
			head=head->next;
			head->prev=NULL;
		}
		free(curr);
	}
}

void display(){
	if(head){
		curr = head;
		while(curr){
			printf("%c ",curr->c);
			curr=curr->next;
		}
		printf("\n");
	}else{
		printf("No data\n");
	}
}

void menu(){
	printf("1. Input Kata, push char ke stack [max 10 kar]\n2. PopStack\n3. Peek / Top\n0. Exit, PopAll\nPilih : ");
}

void menu1(){
	char input[100];
	int m;
	printf("Masukkan Kata : ");
	gets(input);
	m=strlen(input);
	if(n+m>10){
		printf("FULL YOU DUMBASS");
		getchar();
		return;
	}	
	for(i=0; i<strlen(input); i++){
		pushHead(input[i]);
		n++;
	}	
}

void Peek(){
	if(head){
		printf("Peek Char : '%c'\n",head->c);
		getchar();
	}
}

int main()
{
	int choice;
	do{
		system("CLS");
		display();
		menu();
		scanf("%d",&choice);getchar();
		switch(choice){
			case 1:{
				menu1();
				break;
			}
			case 2:{
				if(n!=0){
					popHead();
					n--;
				}
				break;
			}
			case 3:{
				Peek();
				break;
			}
		}
	}while(choice!=0);
	return 0;
}
