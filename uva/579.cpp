#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	short hour , minute;
	float h_degree , m_degree , degree;

	while(scanf("%hd:%hd" , &hour , &minute)){
		//exit
		if(hour == 0 && minute == 0){
			return 0;
		}
		//zero
		h_degree = 0;
		m_degree = 0;
		//calculate
		h_degree = 30 * hour + 0.5 * minute;
		m_degree = 6 * minute;
		degree = m_degree - h_degree;
		if(degree < 0){
			degree += 360;
		}
		if(degree > 180){
			degree = 360 - degree;
		}
		//output
		printf("%.3f\n" , degree);
	}
}
