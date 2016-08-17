//UFPB - 06/08/2016 - Aluno: Thulio Guilherme Silva de Amorim - Matrícula: 11328381
//Algoritmos baseado nas aulas de Ordenação e Recuperação de Dados ministradas pelo professor Fernando Matos - fernando@ci.ufpb.br

#include <stdio.h>

void showVector(int* vector, int size){
	for(int i = 0; i < size; i++){
		printf("%d ", vector[i]);
	}
	printf("\n");
}

void insertionsort(int* vector, int size){ //Best case: O(n) - Worst case: O(n²)
	int tmp, i;
	for(int j = 1; j < size; j++){
		tmp = vector[j];
		for(i = j - 1; (i >= 0) && (vector[i] > tmp); i--){
			vector[i + 1] = vector[i];
		}
		vector[i + 1] = tmp;
	}
}

int main(){
	int n;

	scanf("%d", &n);

	int vector[n];

	for(int i = 0; i < n; i++){
		scanf("%d", &vector[i]);
	}

	insertionsort(vector, n);

	showVector(vector, n);
}