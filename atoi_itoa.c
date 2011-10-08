#include <stdio.h>
#include <stdlib.h>

int my_strlen(char *str){
	char *aux = str;
	int len = 0;
	while(aux != 0){
		len++;
		aux++;
		printf("%s\n",aux);
	}
	return len;
}

int my_atoi(char *str){
	int decimal = 1;
	int size = my_strlen(str);
	int integer = 0;
	while(size >= 0){
		int algarism = str[size--] - 48;
		algarism *= decimal;
		integer += algarism;
		decimal *= 10;
	}
	return integer;
}

/*
char *my_itoa(int num, char *ret){
	
	ret[n--] = '\0';
	int i = num % 10;
	num /= 10;
	while (n >= 0){
		ret[n--] = i + 48;
		i %= 10;
		num /= 10;
	}
	return ret;
}*/

int main (void){
	char *num = "321";
	int i = 321;
	printf("%d\n", my_atoi(num));
	//printf("%s\n", my_itoa(i,3));
	return 0;
}
