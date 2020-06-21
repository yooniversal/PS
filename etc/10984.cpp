//10984

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	//ios_base::sync_with_stdio(false);

	int t, n, grade, sumgrade=0, tmp;
	double score, sum = 0.0;

	cin >> t;
	while (t--) {
		cin >> n;
		while (n--) {
			cin >> grade >> score;
			sum += (double)grade * score;
			sumgrade += grade;
		}

		tmp = (int)((sum / sumgrade) * 100);
		printf("%d %.1lf\n", sumgrade, (double)(tmp / 100.0));

		tmp = sumgrade = 0;
		sum = 0.0;
	}

	return 0;
}