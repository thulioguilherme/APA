#include <stdio.h>

//Just work on ascending arrays and without duplicate keys
int findByValue(int *array, int key, int low, int high){
	if(low > high) return -1;
	
	int middle = (low + high) / 2;
	
	if(array[middle] == key) return middle;

	if(array[low] <= array[middle]){
		if(key >= array[low] && key <= array[middle]){
			return findByValue(array, key, 1, middle - 1);
		}
		return findByValue(array, key, middle + 1, high);
	}

	if(key >= array[middle] && key <= array[high]){
		return findByValue(array, key, middle +1, high);
	}

	return findByValue(array, key, 1, middle - 1);
}

int main(){
	int n, key, ret;

	scanf("%d %d", &n, &key);

	int array[n];

	for(int i = 0; i < n; i++){
		scanf("%d", &array[i]);
	}

	ret = findByValue(array, key, 0, n - 1);
	printf("%d\n", ret + 1);
}