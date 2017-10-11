#include <iostream>
#include <queue>
#include <utility>
#include <new>
#include <cstring>
using namespace std;
int main(){
	int i , j;
	int row , column , nonz , pos , num , count;
	int** mat;
	queue<int> pb;
	queue<int> nb;

	while(cin >> row >> column){
		mat = new int*[row];
		for(i = 0 ; i < row ; i++){
			mat[i] = new int[column];
			memset(mat[i] , 0 , column * sizeof(int));
		}
		for(i = 0 ; i < row ; i++){
			cin >> nonz;
			for(j = 0 ; j < nonz ; j++){
				cin >> pos;
				pb.push(pos);
			}
			for(j = 0 ; j < column && nonz != 0 ; j++){
				if(j + 1 == pb.front()){
					cin >> num;
					mat[i][j] = num;
					pb.pop();
				}
			}
			if(!pb.empty()){cout << "Error ! pb not empty .\n";return 0;}//debuger
		}
		cout << column << ' ' << row << endl;
		for(i = 0 ; i < column ; i++){
			count = 0;
			for(j = 0 ; j < row ; j++){
				if(mat[j][i] != 0){
					count++;
					pb.push(j + 1);
					nb.push(mat[j][i]);
				}
			}
			if(count){
				cout << count << ' ';
				while(pb.size() != 1){
					cout << pb.front() << ' ';
					pb.pop();
				}
				if(pb.size() == 1){
					cout << pb.front() << endl;
					pb.pop();
				}
			}
			else{cout << count << endl;}
			if(count){
				while(nb.size() != 1){
					cout << nb.front() << ' ';
					nb.pop();
				}
				if(nb.size() == 1){
					cout << nb.front() << endl;
					nb.pop();
				}
			}
			else{cout << endl;}
		}
		for(i = 0 ; i < row ; i++){delete[] mat[i];}
		delete mat;
	}

	return 0;
}
