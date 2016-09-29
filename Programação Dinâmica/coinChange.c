#include <stdio.h>

int coinChange(int *coins, int numberCoins, int amount){
	int i, j;
	int table[numberCoins + 1][amount + 1];

	if(amount == 0) return 1;

	if(numberCoins == 0) return 0;

	for(i = 0; i <= numberCoins; i++){
		table[i][0] = 1;
	}

	for(i = 0; i <= amount; i++){
		table[0][i] = 0;
	}

	for(i = 1; i <= numberCoins; i++){
		for(j = 1; j <= amount; j++){
			if(coins[i - 1] <= j){
				table[i][j] = table[i - 1][j] + table[i][j - coins[i - 1]];
			}else{
				table[i][j] = table[i - 1][j];
			}
		}
	}

	/*
	for(i = 0; i <= numberCoins; i++){
		for(j = 0; j <= amount; j++){
			printf("  %d", table[i][j]);
		}
		printf("\n");
	}*/

	return table[numberCoins][amount];
}

int main(){

	int numberCoins, amount;
	while(scanf("%d %d", &numberCoins, &amount) != EOF){	
		int coins[numberCoins];

		for(int i = 0; i < numberCoins; i++){
			scanf("%d", &coins[i]);
		}
	
		printf("%d\n", coinChange(coins, numberCoins, amount));

	};
	
	return 0;
}	