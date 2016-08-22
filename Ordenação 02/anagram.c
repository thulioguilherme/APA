#include <stdio.h>
#include <string.h>

int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41,
	43, 47, 53, 59, 71, 67, 71};

struct Word{
	char string[20];
	char sorted[20];
	float value;
};

int partition(struct Word* input, int begin, int end){
	float pivot;
	char pivotString[20], pivotSorted[20];
	int top, i;

	pivot = input[begin].value;
	strcpy(pivotString, input[begin].string);
	strcpy(pivotSorted, input[begin].sorted);

	top = begin; 
	for(i = begin + 1; i <= end; i++){
		if(input[i].value < pivot){
			input[top].value = input[i].value;
			input[i].value = input[top + 1].value;

			strcpy(input[top].string, input[i].string);
			strcpy(input[i].string, input[top + 1].string);

			strcpy(input[top].sorted, input[i].sorted);
			strcpy(input[i].sorted, input[top + 1].sorted);

			top++;
		}
	}

	input[top].value = pivot;
	strcpy(input[top].string, pivotString);
	strcpy(input[top].sorted, pivotSorted);

	return top;
}

void quicksort(struct Word* input, int begin, int end){ //Best case: O(n*logn) - Worst case: O(n²)
	int middle;
	if(begin < end){
		middle = partition(input, begin, end);
		quicksort(input, begin, middle - 1);
		quicksort(input, middle + 1, end);
	}
}

float getValue(char* word, char* dest){
	int count = strlen(word);
	int i, j;
	char tmp;
	strcpy(dest, word);
	for(i = 0; i < count; i++){
		tmp = dest[i];
		j = i - 1;
		while((j >= 0) && ((int)tmp < (int)dest[j])){
			dest[j + 1] = dest[j];
			j = j - 1;
		}
		dest[j + 1] = tmp;
	}

	float total = 0;
	for(int i = 0; i < count; i++){
		total = total + (dest[i] - 96) * prime[i] * 0.0001;
	}

	return total;
}

int main(){
	int n, i;

	scanf("%d", &n);
	
	getchar();

	struct Word input[n];

	for(i = 0; i < n; i++){
		scanf("%s", input[i].string);
		input[i].value = getValue(input[i].string, input[i].sorted);
	}

	quicksort(input, 0, n - 1);

	for(i = 0; i < n; i++){
		printf("%s\n", input[i].string);
	}
}