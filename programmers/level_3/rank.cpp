#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <iostream>
#define MAX 101
using namespace std;
const int INF = 987654321;

int d[MAX][MAX];

int solution(int n, vector<vector<int>> results) {
	for (int i = 0; i < MAX; ++i)
		for (int j = 0; j < MAX; ++j)
			if (i != j)
				d[i][j] = INF;
			else d[i][j] = 0;

	for (int i = 0; i < results.size(); ++i) {
		int a = results[i][0], b = results[i][1];
		d[a][b] = 1;
	}

	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				if (d[i][j] > d[i][k] + d[k][j])
					d[i][j] = d[i][k] + d[k][j];

	int ret = 0;
	for (int i = 1; i <= n; ++i) {
		bool flag = true;
		for (int j = 1; j <= n; ++j)
			if (d[i][j] == INF && d[j][i] == INF) {
				flag = false;
				break;
			}
		if (flag) ++ret;
	}

	return ret;
}