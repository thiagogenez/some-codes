#include <stdio.h>
#include <stdlib.h>

int my_atoi(char *str, int n){
	int i = 1;
	int num = 0;
	while(n >= 0){

		int j = str[n--] - 48;
		j = j * i;
		num = num + j;
		i = i*10;
	}
	return num;
}

char *my_itoa(int num, int n){
	char *ret = malloc(n*sizeof(char));
	ret[n--] = '\0';
	int i = num % 10;
	num = num / 10;
	while (n >= 0){
		ret[n--] = i + 48;
		i = num % 10;
		num = num / 10;
	}
	return ret;
}

int main (void){
	char *num = malloc(3*sizeof(char));
	num = "321";
	int i = 321;
	printf("%d\n", my_atoi(num, 2));
	printf("%s\n", my_itoa(i,3));
	return 0;
}
