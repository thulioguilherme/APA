//UFPB - 06/08/2016 - Aluno: Thulio Guilherme Silva de Amorim - Matrícula: 11328381
//Algoritmos baseado nas aulas de Ordenação e Recuperação de Dados ministradas pelo professor Fernando Matos - fernando@ci.ufpb.br

#include <stdio.h>
#include <stdlib.h>

void showVector(int* vector, int size){
	for(int i = 0; i < size; i++){
		printf("%d ", vector[i]);
	}
	printf("\n");
}

void swap(int i, int j, int* vector){
	int tmp = vector[i];
	vector[i] = vector[j];
	vector[j] = tmp;	
}

int partition(int* vector, int begin, int end){
	int pivot, top, i, pIndex;
	pIndex = begin + (rand() % (end - begin)); //Random pivot
	pivot = vector[pIndex];
	swap(begin, pIndex, vector);
	top = begin;

	for(i = begin + 1; i <= end; i++){
		if(vector[i] < pivot){
			vector[top] = vector[i];
			vector[i] = vector[top + 1];
			top++;
		}
	}

	vector[top] = pivot;
	return top;
}

void quicksort(int* vector, int begin, int end){ //Best case: O(n*logn) - Worst case: O(n²)
	int middle;
	if(begin < end){
		middle = partition(vector, begin, end);
		quicksort(vector, begin, middle - 1);
		quicksort(vector, middle + 1, end);
	}
}

int main(){
	int n;

	scanf("%d", &n);

	int vector[n];

	for(int i = 0; i < n; i++){
		scanf("%d", &vector[i]);
	}

	quicksort(vector, 0, n - 1);

	showVector(vector, n);
}