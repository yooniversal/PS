//5533

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <queue>
#include <cmath>
#include <algorithm>
#include <functional>
using namespace std;

int p[201][201];
int m[201][201];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	for(int j=0; j<t; j++)
		for (int i = 0; i < 3; i++) {
			cin >> p[j][i];
			m[j][i] = p[j][i];
			for(int k=0; k<j; k++)
				if (p[j][i] == p[k][i]) {
					m[j][i] = 0;
					m[k][i] = 0;
				}
		}

	for (int i = 0; i < t; i++)
		cout << m[i][0] + m[i][1] + m[i][2] << '\n';


	return 0;
}