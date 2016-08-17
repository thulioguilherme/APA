#include <stdio.h>
#include <stdlib.h>

struct node{
	struct node *next;
	int value;
};

struct linked_list{
	struct node *head;
	int size;
};

void initLList(struct linked_list *list){
	list->head = NULL;
	list->size = 0;	
}

void showLList(struct linked_list *list){
	struct node *tmp;
	tmp = list->head;
	while(tmp != NULL){
		printf("%d ", tmp->value);
		tmp = tmp->next;
	}
	printf("\n");
}

void insertLList(struct linked_list *list, int value){
	struct node *newNode, *tmp;
	newNode = malloc(sizeof(struct node));
	if(newNode == NULL){
		exit(1);
	} 

	if(list->size == 0){
		list->head = newNode;

	}else{
		tmp = list->head;
		while(tmp->next != NULL){
			tmp = tmp->next;
		}
		tmp->next = newNode;
	}

	newNode->next = NULL;
	newNode->value = value;
	list->size++;
}

int partition(struct linked_list *list, int begin, int end){
	int top, i, pivotValue;
	struct node *pivot, *sucessor;
	
	top = 0;
	i = begin;
	pivot = list->head;
	sucessor = pivot->next;
	while(i > 0){
		top++;
		pivot = sucessor;
		sucessor = sucessor->next;
		i--;
	}

	pivotValue = pivot->value;
	i = end - begin;
	while(i > 0){
		if(pivotValue > sucessor->value){
			pivot->value = sucessor->value;
			sucessor->value = (pivot->next)->value;
			
			pivot = pivot->next;
			top++;
		}
		sucessor = sucessor->next;
		i--;
	}
	pivot->value = pivotValue;
	return top;
}

void quicksort(struct linked_list *list, int begin, int end){
	int middle;
	if(begin < end){
		middle = partition(list, begin, end);
		quicksort(list, begin, middle - 1);
		quicksort(list, middle + 1, end);
	}
}

int main(){
	int n, i, tmp;
	struct linked_list myList;

	initLList(&myList);

	scanf("%d", &n);

	for(i = 0; i < n; i++){
		scanf("%d", &tmp);
		insertLList(&myList, tmp);
	}

	quicksort(&myList, 0, n - 1);

	showLList(&myList);
}