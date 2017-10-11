#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int main(){
	char in;
	bool check;
	int L , R , C , count , x;
	int i , j , k;
	int map[32][32][32];
	int pos[6] = {-1024 , -32 , -1 , 1 , 32 , 1024};
	queue<int*> save;

	while(cin >> L >> R >> C){
		if((L == 0 && R == 0) && C == 0){return 0;}
		memset(map , 1 , 32768 * sizeof(int));
		for(i = 1 ; i <= L ; i++){
			for(j = 1 ; j <= R ; j++){
				for(k = 1 ; k <= C ; k++){
					cin >> in;
					switch(in){
						case 'S':
							map[i][j][k] = 2;
							save.push(&map[i][j][k]);
							break;
						case '.':
							map[i][j][k] = 0;
							break;
						case '#':
							map[i][j][k] = 1;
							break;
						case 'E':
							map[i][j][k] = 3;
							break;
						default:
							cout << "Error '" << in << "'\n" ;
							return 0;
					}
				}
			}
		}

		count = 0;
		check = false;
		while(save.size()){
			x = save.size();
			count++;
			for(i = 0 ; i < x ; i++){
				for(j = 0 ; j < 6 ; j++){
					if(*(save.front() + pos[j]) == 0){
						save.push(save.front() + pos[j]);
					}
					if(*(save.front() + pos[j]) == 3){
						check = true;
						i = x;
						break;
					}
				}
				*(save.front()) = 1;
				save.pop();
			}
			if(check){break;}
			if(save.size() == 0){count = 0;}
		}
		while(!save.empty()){save.pop();}

		if(count){cout << "Escaped in " << count << " minute(s).\n";}
		else{cout << "Trapped!\n";}
	}

	return 0;
}

