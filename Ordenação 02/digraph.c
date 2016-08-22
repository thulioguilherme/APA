#include <stdio.h>
#include <string.h>
#include <ctype.h>

int compareString(char* word, char* word2){
	int size = strlen(word);
	int size2 = strlen(word2);
	int i, j, k, count;
	float comp, comp2;

	if(size == 0){
		return 0;
	}else if(size2 == 0){
		return 1;
	}

	if(size > size2){
		count = size;
	}else{
		count = size2;
	}

	i = 0;
	j = 0;
	for(k = 0; (k < count) && (i < size) && (j < size2) ; k++){
		if( (word[i] == 'c') && (i <= size - 1) ){
			if(word[i + 1] == 'h'){
				comp = 99.5; 
				i++;
			}else{
				comp = (int)'c';
			}
		}else if( (word[i] == 'r') && (i <= size - 1)){
			if(word[i + 1] == 'r'){
				comp = 114.5;
				i++;
			}else{
				comp = (int)'r';
			}
		}else if( (word[i] == 'l') && (i <= size - 1)){
			if(word[i + 1] == 'l'){
				comp = 108.5;
				i++;
			}else{
				comp = (int)'l';
			}
		}else{
			comp = (int)word[i];
		}

		if( (word2[j] == 'c') && (j <= size2 - 1) ){
			if(word2[i + 1] == 'h'){
				comp2 = 99.5; 
				j++;
			}else{
				comp2 = (int)'c';
			}
		}else if( (word2[j] == 'r') && (j <= size2 - 1)){
			if(word2[j + 1] == 'r'){
				comp2 = 114.5;
				j++;
			}else{
				comp2 = (int)'r';
			}
		}else if( (word2[j] == 'l') && (j <= size2 - 1)){
			if(word2[j + 1] == 'l'){
				comp2 = 108.5;
				j++;
			}else{
				comp2 = (int)'l';
			}
		}else{
			comp2 = (int)word2[j];
		}

		if(comp2 > comp){
			return 0;
		}else if(comp > comp2){
			return 1;
		}

		i++;
		j++;
	}

	if(size > size2){
		return 1;
	}else{
		return 0;
	}
}

void convert2Lower(char *string){
	for(int i = 0; string[i]; i++){
		string[i] = tolower(string[i]);
	}
}

int main(){
	int n, i, j;

	scanf("%d", &n);

	getchar();

	char input[n][15];
	char string[15];

	for(i = 0; i < n; i++){
		scanf("%s", input[i]);
		convert2Lower(input[i]);
	}
	
	strcpy(string, "\0");
	for(i = 1; i < n; i++){
		strcpy(string, input[i]);
		j = i - 1;
		while((j >=0) && (compareString(string, input[j]) == 0)){
			strcpy(input[j + 1], input[j]);
			j = j - 1;
		}
		strcpy(input[j + 1], string);
	}

	for(i = 0; i < n; i++){
		printf("%s\n", input[i]);
	}
}