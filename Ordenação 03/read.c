#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

char entropy[3][4] = {"10.", "50.", "90."};
char size[3][9] = {"100000.", "500000.", "1000000."};
char number[5][5] = {"1.in", "2.in", "3.in", "4.in", "5.in"};

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

void maxHeap(int* vector, int index, int size){
	int left = 2*index;
	int right = 2*index + 1;
	int largest;
	if(left <= size && vector[left] > vector[index]){
		largest = left;
	}else{
		largest = index;
	}

	if(right <= size && vector[right] > vector[largest]){
		largest = right;
	}

	if(largest != index){
		swap(index, largest, vector);
		maxHeap(vector, largest, size);
	}	
}

void buildHeap(int* vector, int size){
	for(int i = size / 2 - 1; i >= 0; i--){
	 	maxHeap(vector, i, size);
	}
}

void heapsort(int* vector, int size){ //Best case: O(n*logn) - Worst case: O(n*logn)
	buildHeap(vector, size);
	for(int i = size; i > 0; i--){
		swap(0, i, vector);
		size = size - 1;
		maxHeap(vector, 0, size);
	}
}

int partition(int* vector, int begin, int end){
	int pivot, top, i;
	pivot = vector[begin];
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

int cmpfunc (const void * a, const void * b){
   return ( *(int*)a - *(int*)b );
}


int main(int argc, char* argv[]){
	if(argc != 5){
		printf("Wrong number of arguments\n");
		exit(1);
	}

	FILE *output = fopen("result.txt", "a+");

	char string[30];
	strcpy(string, "./input/");
	strcat(string, entropy[atoi(argv[1])]);
	strcat(string, size[atoi(argv[2])]);
	strcat(string, number[atoi(argv[3])]);

	FILE *input = fopen(string, "r");
	char line[256];
	int count = 0;
				
	int n;
	if(atoi(argv[2]) == 0){
		n = 100000;
	}else if(atoi(argv[2]) == 1){
		n = 500000;
	}else{
		n = 1000000;
	}
				
	int vector[n];
	while(fgets(line, sizeof(line), input)){
		vector[count] = atoi(line);
		count++;
	}

	clock_t start, end;
	float total;

	if(atoi(argv[4]) == 0){
		fprintf(output, "FILENAME: %s\n", string);
		fprintf(stderr, "FILENAME: %s\n", string);
		start = clock();
		quicksort(vector, 0, n - 1);
		end = clock();
		total = (double)(end - start) / CLOCKS_PER_SEC;
		fprintf(output, "\tUsing Quicksort - %f second(s)\n", total);
		fprintf(stderr, "\tUsing Quicksort - %f second(s)\n", total);
	}else if(atoi(argv[4]) == 1){
		start = clock();
		heapsort(vector, n - 1);
		end = clock();
		total = (double)(end - start) / CLOCKS_PER_SEC;
		fprintf(output, "\tUsing Heapsort - %f second(s)\n", total);
		fprintf(stderr, "\tUsing Heapsort - %f second(s)\n", total);
	}else if(atoi(argv[4]) == 2){
		int keeper[n];
		start = clock();
		mergesort(vector, keeper, n);
		end = clock();
		total = (double)(end - start) / CLOCKS_PER_SEC;
		fprintf(output, "\tUsing Mergesort - %f second(s)\n", total);
		fprintf(stderr, "\tUsing Mergesort - %f second(s)\n", total);
	}else if(atoi(argv[4]) == 3){
		start = clock();
		qsort(vector, n, sizeof(int), cmpfunc);
		end = clock();
		total = (double)(end - start) / CLOCKS_PER_SEC;
		fprintf(output, "\tUsing Qsort - %f second(s)\n", total);
		fprintf(stderr, "\tUsing Qsort - %f second(s)\n", total);
	}else if(atoi(argv[4]) == 4){
		start = clock();
		selectionsort(vector, n);
		end = clock();
		total = (double)(end - start) / CLOCKS_PER_SEC;
		fprintf(output, "\tUsing Selection sort - %f second(s)\n", total);
		fprintf(stderr, "\tUsing Selection sort - %f second(s)\n", total);
	}else{
		start = clock();
		insertionsort(vector, n);
		end = clock();
		total = (double)(end - start) / CLOCKS_PER_SEC;
		fprintf(output, "\tUsing Insertion sort - %f second(s)\n", total);
		fprintf(stderr, "\tUsing Insertion sort - %f second(s)\n", total);
	}

	fclose(input);
	fclose(output);		
    return 0;
}