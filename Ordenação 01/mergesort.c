//UFPB - 06/08/2016 - Aluno: Thulio Guilherme Silva de Amorim - Matrícula: 11328381
//Algoritmos baseado nas aulas de Ordenação e Recuperação de Dados ministradas pelo professor Fernando Matos - fernando@ci.ufpb.br

#include <stdio.h>

void showVector(int* vector, int size){
	for(int i = 0; i < size; i++){
		printf("%d ", vector[i]);
	}
	printf("\n");
}

void mergeConquer(int begin, int middle, int end, int* vector, int* keeper){
	for(int i = begin; i <= end; i++){
		keeper[i] = vector[i];
	}
	int i = begin;
	int j = middle + 1;
	int k = begin;

	while(i <= middle && j <= end){
		if(keeper[i] <= keeper[j]){
			vector[k] = keeper[i];
			i++;
		}else{
			vector[k] = keeper[j];
			j++;
		}
		k++;
	}

	while(i <= middle){
		vector[k] = keeper[i];
		k++;
		i++;
	}

	while(j <= end){
		vector[k] = keeper[j];
		j++;
		k++;
	}
}

void mergeDivide(int begin, int end, int* vector, int* keeper){
	if(begin < end){
		int middle = begin + (end - begin) / 2;
		mergeDivide(begin, middle, vector, keeper);
		mergeDivide(middle + 1, end, vector, keeper);
		mergeConquer(begin, middle, end, vector, keeper);
	}
}

void mergesort(int* vector, int* keeper, int size){ //Best case: O(n*logn) - Worst case: O(n*logn)
	for(int i = 0; i < size; i++){
		keeper[i] = vector[i];
	}
	mergeDivide(0, size - 1, vector, keeper);
}

int main(){
	int n;

	scanf("%d", &n);

	int vector[n], keeper[n];

	for(int i = 0; i < n; i++){
		scanf("%d", &vector[i]);
	}

	mergesort(vector, keeper, n);

	showVector(vector, n);
}