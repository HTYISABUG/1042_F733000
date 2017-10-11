#include <iostream>
#include <cstdlib>

using namespace std;

struct node{
	short num;
	struct node* next;
};
struct node* start;

inline void create(short n);
inline struct node* kill(short n);
inline void clean_list();

int main(){
	short input;
	short i , j;
	short count = 0;
	struct node* p;
	struct node* counter;
	start = NULL;

	while(cin >> input){
		if(input == 0){
			return 0;
		}
		//zero
		count = 0;
		//find ans
		for(i = input ; count != input ; i++){
			//filter
			if(1 <= i % (2 * input) && i % (2 * input) <= input){
				continue;
			}
			//make a cycle list
			for(j = 2 * input ; j >= 1 ; j--){
				create(j);
			}
			for(p = start ; p -> next != NULL ; p = p -> next){
			}
			p -> next = start;
			//reset counter
			counter = start;
			//start count
			while(count != input){
				//zero
				count = 0;
				//start count
				for(j = 1 ; j < i ; j++){
					counter = counter -> next;
				}
				//filter
				if(counter -> num <= input){
					break;
				}
				else{
					//kill
					counter = kill(counter -> num);
				}
				//count
				for(p = start ; !(p == start && count != 0) ; p = p -> next){
					count++;
				}
			}
			//clean_list();

			if(count == input){
				cout << i << '\n';
			}
		}
	}
}

inline void create(short n){
	struct node* create = (struct node*)calloc(1 , sizeof(struct node));
	create -> num = n;
	create -> next = start;
	start = create;
}

inline struct node* kill(short n){
	struct node* p;
	struct node* pre = NULL;
	for(p = start ; p -> num != n ; pre = p , p = p -> next){		
	}
	pre -> next = p -> next;
	free(p);
	return pre -> next;
}

inline void clean_list(){
	struct node* p;
	struct node* pre;
	for(p = start ; p -> next != start ; p = p -> next){
	}
	p -> next = NULL;
	while(start != NULL){
		for(pre = NULL , p = start ; p -> next != NULL ; pre = p , p = p -> next){
		}
		if(pre != NULL){
			pre -> next = NULL;
		}
		else{
			start = NULL;
		}
		free(p);
	}
}
