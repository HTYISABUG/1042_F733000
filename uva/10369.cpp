#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

struct line{

	int s;
	int t;
	double l;

};
vector<pair<int , int> > point;
vector<line> save;
bool connect[500];

void link();
bool cmp(line , line);

int main(){

	int i , j , k;
	int n , s , p , x , y;
	vector<int>lp;
	vector<double> len;

	while(cin >> n){

		for(i = 0 ; i < n ; ++i){

			fill(connect , connect + 500 , false);
			save.clear();
			point.clear();
			lp.clear();
			len.clear();

			cin >> s >> p;

			for(j = 0 ; j < p ; ++j){

				cin >> x >> y;
				point.push_back(make_pair(x , y));
				if((int)point.size() > 1) link();

			}

			sort(save.begin() , save.end() , cmp);

			connect[0] = true;
			lp.push_back(0);

			while((int)lp.size() != p){

				for(j = 0 ; j < (int)save.size() ; ++j){

					for(k = 0 ; k < (int)lp.size() ; ++k){

						if(save[j].s == lp[k] && !connect[save[j].t]){

							connect[save[j].t] = true;
							lp.push_back(save[j].t);
							len.push_back(save[j].l);
							j = (int)save.size();
							break;

						}
						if(save[j].t == lp[k] && !connect[save[j].s]){

							connect[save[j].s] = true;
							lp.push_back(save[j].s);
							len.push_back(save[j].l);
							j = (int)save.size();
							break;

						}

					}

				}

			}

			sort(len.begin() , len.end());

			printf("%.2lf\n" , len[(int)len.size()-s]);

		}

	}

	return 0;

}

void link(){

	line *n;

	for(int i = 0 ; i < (int)point.size() - 1 ; ++i){

		n = new line;
		n->s = i;
		n->t = point.size() - 1;
		n->l = sqrt(pow(point[i].first - point.back().first , 2) +pow(point[i].second - point.back().second , 2));
		save.push_back(*n);

	}

}

bool cmp(line a , line b){

	return a.l < b.l;

}
