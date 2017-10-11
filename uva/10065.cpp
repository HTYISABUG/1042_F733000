#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Vec2{
	public:
		Vec2(double x , double y){vec = make_pair(x , y);}

		double x(){return vec.first;}

		double y(){return vec.second;}

		double length(){return sqrt(pow(vec.first , 2) + pow(vec.second , 2));}

		double cross(Vec2 v){
			return vec.first * v.y() - vec.second * v.x();
		}

	private:
		pair<double , double> vec;
};

class Point2{
	public:
		Point2(){}

		Point2(double x , double y){pos = make_pair(x , y);}

		double x(){return pos.first;}

		double y(){return pos.second;}

		Vec2 operator-(Point2 p){
			return Vec2(pos.first - p.x() , pos.second - p.y());
		}

	private:
		pair<double , double> pos;
};

vector<Point2> save;

bool cmp_origin(Point2 a , Point2 b){
	return (a.y() < b.y()) || (a.y() == b.y() && a.x() < b.x());
}

bool cmp_angle(Point2 a , Point2 b){
	double cro = (a-save[0]).cross(b-save[0]);

	return cro > 0 || (!cro && (a-save[0]).length() < (b-save[0]).length());
}

int main(){
	int n , x , y , p , c = 0;
	Point2 ans[200];

	while(cin >> n){
		if(!n) break;
		save.clear();
		++c;

		for(int i = 0 ; i < n ; ++i){
			cin >> x >> y;
			save.push_back(Point2(x , y));
		}

		double real = 0;
		for(int i = 2 ; i < (int)save.size() ; ++i)
			real += (save[i-1] - save[0]).cross(save[i] - save[0]);
		real /= 2;
		real < 0 ? real *= -1 : real = real;

		sort(save.begin() , save.end() , cmp_origin);
		sort(save.begin() + 1 , save.end() , cmp_angle);
		save.push_back(save[0]);

		p = 0;
		for(int i = 0 ; i < (int)save.size() ; ++i){
			while(p >= 2 && (ans[p-1]-ans[p-2]).cross(save[i]-ans[p-2]) <= 0){
				--p;
			}
			ans[p++] = save[i];
		}

		--p;
		double A = 0;
		for(int i = 2 ; i < p ; ++i)
			A += (ans[i-1] - ans[0]).cross(ans[i] - ans[0]);
		A /= 2;

		cout << "Tile #" << c << endl;
		printf("Wasted Space = %.2lf " , 100 - real / A * 100);
		cout << '%' << endl << endl;
	}

	return 0;
}
