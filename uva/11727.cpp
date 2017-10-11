#include <iostream>

using namespace std;

int main(){
	short quantity;
	short CASE , employees;
	short least , most , l , m;
	short salaries[3] = {0};

	while(cin >> quantity){
		for(CASE = 1 ; CASE <= quantity ; CASE++){
			least = 10000;
			most = 0;
			for(employees = 0 ; employees < 3 ; employees++){
				cin >> salaries[employees];
				if(least > salaries[employees]){
					least = salaries[employees];
					l = employees;
				}
				if(most < salaries[employees]){
					most = salaries[employees];
					m = employees;
				}
			}
			for(employees = 0 ; employees < 3 ; employees++){
				if(employees != l && employees != m){
					cout << "Case " << CASE << ": " << salaries[employees] << '\n';
					break;
				}
			}
		}
	}

	return 0;
}
