#include <cstdio>
#include <vector>
using namespace std;

int main(){
	int ele , Case , num , tar , input;
	int i , j;
	bool done;
	int buf[2];
	vector<vector<int> > save;
	vector<vector<int> >::iterator it;
	vector<int>::iterator ite;

	while(scanf("%d %d" , &ele , &Case) != EOF){
		for(i = 1 ; i <= ele ; i++){
			scanf("%d" , &input);
			if(save.empty()){
				buf[0] = input;
				buf[1] = i;
				save.push_back(vector<int>(buf , buf + 2));
			}
			else{
				done = false;
				for(it = save.begin() ; it != save.end() ; it++){
					if(input == (*it)[0]){
						(*it).push_back(i);
						done = true;
						break;
					}
				}
				if(!done){
					buf[0] = input;
					buf[1] = i;
					save.push_back(vector<int>(buf , buf + 2));
				}
			}
		}
		for(i = 0 ; i < Case ; i++){
			scanf("%d %d" , &num , &tar);
			for(it = save.begin() ; it != save.end() ; it++){
				if((*it)[0] == num){
					printf("%d\n" , (*it)[0]);
					break;
				}
			}
		}
	}

	return 0;
}
