#include <stdio.h>
#include <math.h>

int findByValue(int *array, int value, int sizeArray){
	int middle, boundUpper, boundLower;
	
	boundUpper = sizeArray;
	boundLower = 0;
	middle = boundUpper / 2;

	if(array[boundLower] == array[boundUpper]) return boundUpper;

	if(array[boundUpper] > array[boundLower]){
		while( (boundUpper - boundLower) > 1){
			if(array[middle] < value){
				boundLower = middle;
				middle = (boundUpper + middle) / 2;
			}else{
				boundUpper = middle;
				middle = middle / 2;
			}
		} 

		if(array[boundLower] == value){
			return boundLower;
		}else{
			return boundUpper;
		}
	}else{
		while( (boundUpper - boundLower) > 1){
			if(array[middle] > value){
				boundLower = middle;
				middle = (boundUpper + middle) / 2;
			}else{
				boundUpper = middle;
				middle = middle / 2;
			}
		} 

		if(array[boundLower] == value){
			return boundLower;
		}else{
			return boundUpper;
		}
	}
}

int main(){
	int n, value, ret;

	scanf("%d %d", &n, &value);

	int array[n];

	for(int i = 0; i < n; i++){
		scanf("%d", &array[i]);
	}

	ret = findByValue(array, value, n - 1);
	printf("%d\n", ret + 1);
}