#include <cstdio>
#include <cmath>
using namespace std;

int p , q , r , s , t , u;

double cal(double);

int main(){
	double L , R;

	while(scanf("%d %d %d %d %d %d" , &p , &q , &r , &s , &t , &u) != EOF){
		L= 0 ; R = 1;
		if(cal(0) < 0 || cal(1) > 0){printf("No solution\n");continue;}
		for(int i = 0 ; i < 50 ; i++){
			if(cal((double)(L + R) / 2) > 0){L = (L + R) / 2;}
			else{R = (L + R) / 2;}
		}
		printf("%.4lf\n" , L);
	}
}

double cal(double x){
	return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}
