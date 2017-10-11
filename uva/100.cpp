#include <iostream>
#include <cstdlib>

using namespace std;

class The_3n1_problem {
	private :
		int start , end;
	public :
		The_3n1_problem(int valve_1 , int valve_2) {
			set_start(valve_1);
			set_end(valve_2);
		};
		void set_start(int valve) {
			start = valve;
		};
		void set_end(int valve) {
			end = valve;
		};
		int get_start() {
			return start;
		};
		int get_end() {
			return end;
		};
		int algorithm(int n) {
			int count = 0;
			while(n != 1) {
				if(n % 2 == 1) {
					n = 3 * n + 1;
				}
				else {
					n /= 2;
				}
				count++;
			}
			count++;
			return count;
		};
};

int main() {
	int num;
	int buffer;
	int start , end;
	int max_cycle_length;

	while(cin >> start >> end) {
		max_cycle_length = 0;
		The_3n1_problem o(start , end);

		cout << o.get_start() << ' ' << o.get_end() << ' ';

		if(start > end) {
			buffer = start;
			start = end;
			end = buffer;
		}

		for(num = start ; num <= end ; num++) {
			if(max_cycle_length < o.algorithm(num)) {
				max_cycle_length = o.algorithm(num);
			}
		}

		cout << max_cycle_length << '\n';
	}

	return 0;
}
