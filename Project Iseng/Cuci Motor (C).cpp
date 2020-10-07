#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 5

int motor=0;
int income=0;
int node=0;
int mark=0;

struct Data{
	char front[10];
	int n;
	char behind[10];
	int vip;
	struct Data *next, *prev;
}*head, *tail, *curr;

void display(){
	curr=head;
	while(curr){
		printf("%d.        ",motor+1);
		if(curr->vip==1){
			printf("vip    ");
		}else{
			printf("regular");
		}
		printf(" : %s %d %s\n",curr->front,curr->n,curr->behind);
		curr=curr->next;
		motor++;
	}
	motor=0;
}

void pushTail(char front[],int n, char behind[],int vip){
	curr = (struct Data *) malloc (sizeof(struct Data));
	strcpy(curr->front,front);
	curr->n=n;
	strcpy(curr->behind,behind);
	curr->vip=vip;
	curr->next=curr->prev=NULL;
	if(head == NULL) 
	{
		head = tail = curr;
	}
	else 
	{
		tail->next=curr;
		curr->prev=tail;
		tail=curr;
	}
	node++;
}

void add(){
	char s[15]="";
	char front[10],behind[10];
	int n,vip;
	do{
		printf("Insert Plate  [Number between 3000-6999] : ");
		gets(s);
		sscanf(s,"%s %d %s",&front,&n,&behind);
	}while(n<3000||n>6999||strlen(front)>2||strlen(behind)>3);
	do{
		printf("Insert Type [0 : regular, 1 : vip] : ");
		scanf("%d",&vip);
	}while(vip>1);
	pushTail(front,n,behind,vip);
}

void washvip(){
	if(head){
		curr=head;
		while(curr){
			if(curr->vip==1)break;
			curr=curr->next;
		}
		if(curr){
			printf("vip motorcycle-%s %d %s is washed. 15000 is paid",curr->front,curr->n,curr->behind);getchar();
			if(curr==head && curr==tail){
				head=tail=NULL;
			}else{	
				if(curr == head){
					head = head->next;
					head -> prev = NULL;
				}else if (curr == tail){
					tail = tail->prev;
					tail -> next = NULL;
				}else{
					curr -> prev -> next = curr -> next;
					curr -> next -> prev = curr->prev;
				}
			}
			free(curr);
			node--;
			mark=2;
			income+=15000;
		}else{
			mark=1;
		}
	}
}

void washreg(){
	if(head){
		curr=head;
		if(curr){
			printf("regular motorcycle-%s %d %s is washed. 10000 is paid",curr->front,curr->n,curr->behind);getchar();
			if(curr == head && curr ==tail){
				head=tail=NULL;
			}else{	
				if(curr == head){
					head = head->next;
					head -> prev = NULL;
				}else if (curr == tail){
					tail = tail->prev;
					tail -> next = NULL;
				}else{
					curr -> prev -> next = curr -> next;
					curr -> next -> prev = curr->prev;
				}
			}
			free(curr);
			node--;
			mark=1;
			income+=10000;
		}else{
			mark=0;
		}
	}
}

void wash(){
	washvip();
	if(mark==1)washreg();
	mark=0;
}

void popSearch(char front[],int n, char behind[]){
	int found=0;
	if(head){
		curr=head;
		while(curr){
			if(curr->n==n&&(!strcmpi(curr->front,front))&&(!strcmpi(curr->behind,behind))){
				found=1;
				break;
			}
			curr = curr->next;
		}
		if(curr&&found==1){
			if(curr->vip==1){
				printf("vip");
			}else{
				printf("regular");
			}
			printf(" motorcycle-%s %d %s is canceled.\n",curr->front,curr->n,curr->behind);getchar();
				if(curr == head && curr ==tail){
				head = tail = NULL;
			}else{	
				if(curr == head){
					head = head->next;
					head -> prev = NULL;
				}
				else if (curr == tail){
					tail = tail->prev;
					tail -> next = NULL;
				}else{
					curr -> prev -> next = curr -> next;
					curr -> next -> prev = curr->prev;
				}
			}
			free(curr);
			node--;
		}else{
			printf(" motorcycle-%s %d %s is not found.\n",front,n,behind);getchar();
		}
	}
}

void Delete(){
	char s[15]="";
	char front[10],behind[10];
	int n;
	do{
		printf("Insert Plate  [Number between 3000-6999] : ");
		gets(s);
		sscanf(s,"%s %d %s",&front,&n,&behind);
	}while(n<3000||n>6999||strlen(front)>2||strlen(behind)>3);
	popSearch(front,n,behind);
}

int main()
{
	int choice;
	do{
		system("CLS");
		if(node==0){
			printf("No Motorcyle\n\n");
		}else{
			display();
			printf("\n\n");
		}
		if(node==SIZE){
			printf("Total Queue:          %d [Queue is FULL]\n",node);
		}else{
			printf("Total Queue:          %d\n",node);
		}
		printf("Total Income :          %d\n\n",income);
		printf("Washing Queue\n");
			printf("=============\n");
			printf("1. Add reguler / vip motorcycle to washing queue\n");
			printf("2. Wash motorcycle from washing queue (priority : VIP first)\n");
			printf("3. Cancel specific motorcycle from washing queue\n");
			printf("0. Wash All, Exit\n");
			printf("Pilih : ");
			scanf("%d",&choice);getchar();
			switch(choice){
				case 1:{
					if(node<5){
						add();
					}
					break;
				}
				case 2:{
					wash();
					break;
				}
				case 3:{
					Delete();
					break;
				}
			}
	}while(choice!=0);
}
