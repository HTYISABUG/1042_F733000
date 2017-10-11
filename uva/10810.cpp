#include <cstdio>
#include <cstdlib>
#include <new>

using namespace std;

int* mergesort(int* , int);
int* merge (int* , int* , int);

long count;

int main(){
	int length;
	int i , j;
	int* num;

	while(scanf("%d" , &length)){
		if(length == 0){break;}

		num = new int[length];
		for(i = 0 ; i < length ; i++){
			scanf("%d" , num + i);
		}

		count = 0;
		num = mergesort(num , length);

		printf("%ld\n" , count);
	}

	return 0;
}

int* mergesort(int* num , int length){
	if(length == 1){return num;}

	int* left = new int[length/2];
	int* right = new int[length-length/2];

	for(int i = 0 ; i < length ; i++){
		if(i < length / 2){left[i] = num[i];}
		else{right[i-length/2] = num[i];}
	}

	return merge(mergesort(left , length / 2) , mergesort(right , length - length / 2) , length);
}

int* merge(int* left , int* right , int length){
	int* result = new int[length];
	int i = 0 , j = 0 , k = 0 , l;
	while(i < length / 2 && j < length - length / 2){
		if(left[i] <= right[j]){result[k++] = left[i++];}
		else{result[k++] = right[j++];count += (length / 2 - i);}
	}
	while(i < length / 2){result[k++] = left[i++];}
	while(j < length - length / 2){result[k++] = right[j++];}

	return result;
}
