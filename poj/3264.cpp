#include <cstdio>

#include <algorithm>
#include <new>
#include <utility>
using namespace std;

struct node{

	pair<int , int> range;
	int MIN , MAX;
	node *left , *right;

};
int Q[300000];
int MIN , MAX;

node* build(int , int);
void search(node* , int , int);

int main(){

	int QUAN , CASE , llim , rlim;
	node* tree;

	while(scanf("%d %d" , &QUAN , &CASE) != EOF){

		for(int i = 1 ; i <= QUAN ; i++){scanf("%d" , Q + i);}

		tree = build(1 , QUAN);

		for(int i = 0 ; i < CASE ; i++){

			MIN = 2000000;
			MAX = 0;
			scanf("%d %d" , &llim , &rlim);
			search(tree , llim , rlim);
			printf("%d\n" , MAX - MIN);

		}

	}

	return 0;

}

node* build(int llim , int rlim){

	int mid = (llim + rlim) >> 1;
	node* cur = new node;

	cur -> range.first = llim;
	cur -> range.second = rlim;

	if(llim == rlim){

		cur -> left = NULL;
		cur -> right = NULL;
		cur -> MIN = Q[mid];
		cur -> MAX = Q[mid];

	}
	else{

		cur -> left = build(llim , mid);
		cur -> right = build(mid + 1 , rlim);
		cur -> MIN = min(cur -> left -> MIN , cur -> right -> MIN);
		cur -> MAX = max(cur -> left -> MAX , cur -> right -> MAX);

	}

	return cur;

}

void search(node *tree , int llim , int rlim){

	if(tree -> range.first == llim && tree -> range.second == rlim){

		MIN = min(MIN , tree -> MIN);
		MAX = max(MAX , tree -> MAX);
		return;

	}
	
	int mid = (tree -> range.first + tree -> range.second) >> 1;

	if(rlim <= mid){search(tree -> left , llim , rlim);}
	else if(mid < llim){search(tree -> right , llim , rlim);}
	else{

		search(tree -> left , llim , mid);
		search(tree -> right , mid + 1 , rlim);

	}

}
