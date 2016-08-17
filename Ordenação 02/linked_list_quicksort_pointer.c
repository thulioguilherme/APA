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
		printf("  %d", tmp->value);
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
	int top, i;
	struct node *tmp, *sucessor, *predecessor, *predPivot;
	
	top = 0;
	if(begin == 0){
		predPivot = NULL;
		predecessor = NULL;
		tmp = list->head;
		sucessor = tmp->next;
		i = end - begin;
		while(i > 0){
			if(tmp->value > sucessor->value){
				if(predPivot == NULL){
					if(predecessor == NULL){
						tmp->next = sucessor->next;
						list->head = sucessor;
						sucessor->next = tmp;

						sucessor = tmp->next;
						predPivot = list->head;
					}else{
						predecessor->next = sucessor->next;
						sucessor->next = tmp;
						list->head = sucessor;

						predPivot = list->head;
						sucessor = predecessor->next;
					}
				}else{
					if(predecessor == NULL){
						tmp->next = sucessor->next;
						predPivot->next = sucessor;
						sucessor->next = tmp;

						predPivot = predPivot->next;
						sucessor = tmp->next;
					}else{
						predecessor->next = sucessor->next;
						sucessor->next = tmp;
						predPivot->next = sucessor;

						predPivot = sucessor;
						sucessor = predecessor->next;
					}
				}
				top = top + 1;
			}else{
				predecessor = sucessor;
				sucessor = sucessor->next;
			}
			i--;
		}
	}else{
		i = begin;
		predecessor = NULL;
		predPivot = NULL;
		tmp = list->head;
		sucessor = tmp->next;
		while(i > 0){
			predPivot = tmp;
			tmp = sucessor;
			sucessor = sucessor->next;
			top = top + 1;
			i--;
		}

		i = end - begin;
		while(i > 0){
			if(tmp->value > sucessor->value){
				if(predecessor == NULL){
					tmp->next = sucessor->next;
					sucessor->next = tmp;
					predPivot->next = sucessor;

					predPivot = sucessor;
					sucessor = tmp->next;
				}else{
					predecessor->next = sucessor->next;
					predPivot->next = sucessor;
					sucessor->next = tmp;

					predPivot = sucessor;
					sucessor = predecessor->next;
				}
				top = top + 1;
			}else{
				predecessor = sucessor;
				sucessor = sucessor->next;
			}
			i--;
		}
	}
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