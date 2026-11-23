#include<stdio.h>
#include<stdlib.h>
struct Node{
	struct Node* prev;
	int data;
	struct Node* next;
}*head = NULL;
void create(int n){
	struct Node* p,*temp;
	int data,i;
	for(i=1;i<=n;i++){
		temp = (struct Node*)malloc(sizeof(struct Node));
		if(temp == NULL){
			printf("could not create\n");
			return ;
		}
		temp->prev = NULL;
		temp->next = NULL;
		printf("enter data\n");
		scanf("%d",&temp->data);
		if(head == NULL || i == 1){
			head = temp;
		}else{
			p = head;
			while(p->next!= NULL) p=p->next;
			p->next = temp;
			temp->prev = p;
		}
	}
}
void traverse(){
	struct Node* p = head;
	if(p==NULL){
		printf("empty list\n");
		return ;
	}
	while(p->next!=NULL){
		printf("%d\t",p->data);
		p=p->next;
	}
	printf("%d\n",p->data);
	while(p->prev!=NULL){
		printf("%d\t",p->data);
		p=p->prev;
	}
	printf("%d\n",p->data);
}
void deleteNode(int pos){
	struct Node*p = head;
	int count = 1;
	if(p == NULL){
		printf("empty list\n");
	}
	if(pos==1){
		head = p->next;
		if(p->next!=NULL)
			p->next->prev=p->prev;
		p->next = NULL;
		free(p);
	}else{
		while(p->next!=NULL && count<pos){
			count++;
			p=p->next;
		}
		if(count == pos){
			p->prev->next=p->next;
		if(p->next!= NULL)
			p->next->prev = p->prev;
		p->prev = NULL;
		p->next = NULL;
		free(p);
		}else{
			printf("position does not found\n");
		}
	}
}

void deleteNode(int);
void create(int);
void traverse();
int main(int argc,char* argv[]){
	int option,data,pos;
	while(1){
		printf("1. create list\n");
		printf("2. traverse list \n");
		printf("4. delete node\n");
		printf("10. exit\n");
		scanf("%d",&option);
		switch(option){
			case 1:
				printf("enter node\n");
				scanf("%d",&data);
				create(data);
				break;
			case 2:
				traverse();

				break;
			/*case 3:
				printf("insert node\n");
				scanf("*/
			case 4:
				printf("enter position to delete data:");
				scanf("%d",&pos);
				deleteNode(pos);
				break ;
			case 10:
				exit(0);
				break;
			default:
				printf("wrong option\n");
				break;
			}
	}
	return 0;
}

