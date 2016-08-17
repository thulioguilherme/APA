//UFPB - 06/08/2016 - Aluno: Thulio Guilherme Silva de Amorim - Matrícula: 11328381
//Algoritmos baseado nas aulas de Ordenação e Recuperação de Dados ministradas pelo professor Fernando Matos - fernando@ci.ufpb.br

#include <stdio.h>

int largest, n, sizeVector;

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

void maxHeap(int* vector, int index){
	int left = 2*index;
	int right = 2*index + 1;
	if(left <= n && vector[left] > vector[index]){
		largest = left;
	}else{
		largest = index;
	}

	if(right <= n && vector[right] > vector[largest]){
		largest = right;
	}

	if(largest != index){
		swap(index, largest, vector);
		maxHeap(vector, largest);
	}	
}

void buildHeap(int* vector){
	 n = sizeVector - 1;
	 for(int i = n/2; i >= 0; i--){
	 	maxHeap(vector, i);
	 }
}

void heapsort(int* vector){ //Best case: O(n*logn) - Worst case: O(n*logn)
	buildHeap(vector);
	for(int i = n; i > 0; i--){
		swap(0, i, vector);
		n = n - 1;
		maxHeap(vector, 0);
	}
}

int main(){
	int n;

	scanf("%d", &n);

	int vector[n];

	for(int i = 0; i < n; i++){
		scanf("%d", &vector[i]);
	}

	heapsort(vector);

	showVector(vector, n);
}