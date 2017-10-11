#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

struct point{int x , y , z;};
vector<point> save;
vector<double> length[6000];
int res[10];

void init(){

	save.clear();
	for(int i = 0 ; i < 6000 ; ++i) length[i].clear();
	fill(res , res + 10 , 0);

}

double callen(point a , point b){return sqrt(pow(a.x - b.x , 2) + pow(a.y - b.y , 2) + pow(a.z - b.z , 2));}

int main(){

	point in;
	double len;
	char out[5];

	init();

	while(cin >> in.x >> in.y >> in.z){
	
		if(!in.x && (!in.y && !in.z)) break;

		save.push_back(in);

		for(int i = 0 ; i < (int)save.size() - 1 ; ++i){

			len = callen(in , save[i]);
			length[i].push_back(len);
			length[save.size()-1].push_back(len);

		}

	}

	for(int i = 0 ; i < (int)save.size() ; ++i){

		sort(length[i].begin() , length[i].end());

		if(0 <= length[i][0] && length[i][0] < 1) ++res[0];
		else if(1 <= length[i][0] && length[i][0] < 2) ++res[1];
		else if(2 <= length[i][0] && length[i][0] < 3) ++res[2];
		else if(3 <= length[i][0] && length[i][0] < 4) ++res[3];
		else if(4 <= length[i][0] && length[i][0] < 5) ++res[4];
		else if(5 <= length[i][0] && length[i][0] < 6) ++res[5];
		else if(6 <= length[i][0] && length[i][0] < 7) ++res[6];
		else if(7 <= length[i][0] && length[i][0] < 8) ++res[7];
		else if(8 <= length[i][0] && length[i][0] < 9) ++res[8];
		else if(9 <= length[i][0] && length[i][0] < 10) ++res[9];

	}

	for(int i = 0 ; i < 10 ; ++i){

		fill(out , out + 5 , '\0');
		fill(out , out + 4 , ' ');

		if(!res[i]) out[3] = '0';
		else{

			for(int j = 3 ; j >= 0 && res[i] > 0; --j){

				out[j] = '0' + res[i] % 10;
				res[i] /= 10;

			}

		}

		cout << out;

	}

	cout << endl;

}
