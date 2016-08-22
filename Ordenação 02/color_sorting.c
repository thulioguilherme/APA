#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char delim[2] = " ";
char* token;

void swap(int i, int j, long int* vector){
	long int tmp = vector[i];
	vector[i] = vector[j];
	vector[j] = tmp;	
}

int partition2array(long int* principal, long int* secondary, int begin, int end){
	int pivot, top, i, aux;
	pivot = principal[begin];
	aux = secondary[begin];
	top = begin;

	for(i = begin + 1; i <= end; i++){
		if(principal[i] < pivot){
			principal[top] = principal[i];
			principal[i] = principal[top + 1];

			secondary[top] = secondary[i];
			secondary[i] = secondary[top + 1];
			top++;
		}
	}

	principal[top] = pivot;
	secondary[top] = aux;
	return top;
}

void quicksort2array(long int* principal, long int* secondary, int begin, int end){ //Best case: O(n*logn) - Worst case: O(n²)
	int middle;
	if(begin < end){
		middle = partition2array(principal, secondary, begin, end);
		quicksort2array(principal, secondary, begin, middle - 1);
		quicksort2array(principal, secondary, middle + 1, end);
	}
}

int main(){
	int n, i;
	scanf("%d", &n);

	getchar();

	char input_color[2*n + 1];
	long int input_color_code[n];
	long int input_intensity[n];

	//Obtem entrada
	scanf("%[^\n]", input_color);

	for(i = 0; i < n; i++){
		scanf("%ld", &input_intensity[i]);
	}
	
	i = 0; 
	token = strtok(input_color, delim);
	while(token != NULL){
		if(strcmp(token, "B") == 0){
			input_color_code[i] = 2;
		}else if(strcmp(token, "G") == 0){
			input_color_code[i] = 1;
		}else{
			input_color_code[i] = 0;
		}
		token = strtok(NULL, delim);
		i++;
	}

	quicksort2array(input_intensity, input_color_code, 0, n - 1);

	quicksort2array(input_color_code, input_intensity, 0, n - 1);

	for(i = 0; i < n; i++){
		if(input_color_code[i] == 0){
			printf("  R ");
		}else if(input_color_code[i] == 1){
			printf("  G ");
		}else{
			printf("  B ");
		}
	}
	printf("\n");

	for(i = 0; i < n; i++){
		printf("%3ld ", input_intensity[i]);
	}

	printf("\n");
}