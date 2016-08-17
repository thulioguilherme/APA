#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

const char delim[2] = " ";
char* token;

void showVector(long int* vector, int size){
	for(int i = 0; i < size; i++){
		printf("  %ld", vector[i]);
	}
	printf("\n\n");
}

void swap(int i, int j, long int* vector){
	long int tmp = vector[i];
	vector[i] = vector[j];
	vector[j] = tmp;	
}

int partition(long int* vector, int begin, int end){
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

void quicksort(long int* vector, int begin, int end){ //Best case: O(n*logn) - Worst case: O(n²)
	int middle;
	if(begin < end){
		middle = partition(vector, begin, end);
		quicksort(vector, begin, middle - 1);
		quicksort(vector, middle + 1, end);
	}
}

int main(){
	int n, i;
	scanf("%d", &n);

	getchar();

	char input_color[2*n + 1];
	int input_intensity[n];
	long int vector[n];

	char output_color[4*n + 1];
	int output_intensity[n];

	//Obtem entrada
	scanf("%[^\n]", input_color);

	for(i = 0; i < n; i++){
		scanf("%d", &input_intensity[i]);
	}
	
	i = 0; // De acordo com o caractere na i-nésima posição(R, G ou B), é aplicado um deslocamento no i-nésimo valor
	token = strtok(input_color, delim);
	while(token != NULL){
		if(strcmp(token, "B") == 0){
			vector[i] = ((input_intensity[i] + 1) << 16);
		}else if(strcmp(token, "G") == 0){
			vector[i] = ((input_intensity[i] + 1) << 8);
		}else{
			vector[i] = input_intensity[i] + 1;
		}
		token = strtok(NULL, delim);
		i++;
	}

	//Ordena o vetor de acordo com a valor obtido no deslocamento
	srand(time(NULL));
	quicksort(vector, 0, n - 1);

	output_color[0] = '\0';
	
	//Reverte o resultado do deslocamento
	for(i = 0; i < n; i++){
		if(vector[i] > 65536){ 
			strcat(output_color, "  B ");
			output_intensity[i] = (vector[i] >> 16) - 1;
		}else if(vector[i] > 256){ 
			strcat(output_color, "  G ");
			output_intensity[i] = (vector[i] >> 8) - 1;
		}else{
			strcat(output_color, "  R ");
			output_intensity[i] = vector[i] - 1;
		}
	}

	//Exibe o resultado
	printf("%s\n", output_color);
	for(i = 0; i < n; i++){
		printf("%3d ", output_intensity[i]);
	}
	printf("\n");
}