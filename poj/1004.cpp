#include <cstdio>
int main(){
	short count;
	float sum = 0;
	float buffer;
	for(count = 0 ; count < 12 ; count++){
		scanf("%f" , &buffer);
		sum += buffer;
	}
	printf("$%.2f\n" , sum / 12);
	return 0;
}
