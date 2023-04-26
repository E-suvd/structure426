#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node *head;

void printLinkedList (){
	struct node *ptr=head;
	while (ptr!=NULL){
		printf ("%d ", ptr->data);
		ptr= ptr->next;
	}
}

void insertAtHead (int data){
	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data=data;
	new_node->next=head;
	head=new_node;
}

void insertAtTail (int data){
	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data=data;
	new_node->next=NULL;
	
	if (head==NULL){
		head=new_node;
	}else{
		struct node *ptr=head;
		while (ptr->next!=NULL){
			ptr=ptr->next;
		}
		new_node->next=NULL;
		ptr->next=new_node;
	}
}

void insertAtMiddle (int position, int data){
	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = data;
	if (head!=NULL){
		struct node *ptr = head;
		while (ptr->next!=NULL){
			ptr=ptr->next;
			position--;
			if (position==0){
				break;
			}
		}
		new_node->next=ptr->next;
		ptr->next = new_node;
	}else{

	}
}

void deleteFromHead(){
	struct node *ptr = head;
	head=ptr->next;
	free(ptr);
}

void deleteFromMiddle(){
	
}

void deleteFromTail(){
	struct node *ptr = head;
	while (ptr->next->next!=NULL){
		ptr=ptr->next;
	}
	free (ptr->next);
	ptr->next=NULL;
}
int main (){
	
	insertAtTail (2);
	insertAtHead (100);
	insertAtHead (90);
	insertAtTail (3);
	insertAtMiddle (2, 50);
	insertAtMiddle (3, 85);
	printLinkedList();
	printf ("\n");
	deleteFromHead ();
	printf ("\n");
	deleteFromTail();
	printLinkedList();
	return 0;
}


