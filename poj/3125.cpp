#include <cstdio>
#include <queue>
#include <utility>
using namespace std;

int main(){
	int i , j;
	int Case , num , pos , in , time;
	queue<pair<int , bool> > save;
	priority_queue<int> pri;

	while(scanf("%d\n" , &Case) != EOF){
		for(i = 0 ; i < Case ; i++){
			scanf("%d %d\n" , &num , &pos);
			for(j = 0 ; j < num ; j++){
				scanf("%d" , &in);
				if(j == pos){save.push(make_pair(in , true));}
				else{save.push(make_pair(in , false));}
				pri.push(in);
			}
			time = 0;
			while(1){
				if(save.front().first < pri.top()){
					save.push(save.front());
					save.pop();
				}
				else{
					time++;
					if(save.front().second){
						printf("%d\n" , time);
						break;
					}
					else{
						save.pop();
						pri.pop();
					}
				}
			}
			while(!save.empty()){save.pop();}
			while(!pri.empty()){pri.pop();}
		}
	}

	return 0;
}
