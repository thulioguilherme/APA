//UFPB - 06/08/2016 - Aluno: Thulio Guilherme Silva de Amorim - Matrícula: 11328381
//Algoritmos baseado nas aulas de Ordenação e Recuperação de Dados ministradas pelo professor Fernando Matos - fernando@ci.ufpb.br

#include <stdio.h>

void showVector(int* vector, int size){
	for(int i = 0; i < size; i++){
		printf("%d ", vector[i]);
	}
	printf("\n");
}

void selectionsort(int* vector, int size){ //Best case: O(n²) - Worst case: O(n²)
	int min, tmp;
	for(int i = 0; i < size - 1; i++){
		min = i;
		for(int j = i + 1; j < size; j++){
			if(vector[j] < vector[min]){
				min = j;
			}
		}
		tmp = vector[min];
		vector[min] = vector[i];
		vector[i] = tmp;
	}
}

int main(){
	int n;

	scanf("%d", &n);

	int vector[n];

	for(int i = 0; i < n; i++){
		scanf("%d", &vector[i]);
	}

	selectionsort(vector, n);

	showVector(vector, n);
}