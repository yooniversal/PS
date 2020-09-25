//15686
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100001
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int a[51][51];
int n, m;
vi chicken, house;

int dist(int a, int b) {
	return abs(a / n - b / n) + abs(a % n - b % n);
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j];
			if (a[i][j] == 1) house.push_back(i * n + j);
			if (a[i][j] == 2) chicken.push_back(i * n + j);
		}

	string ci; //chkicken index
	for (int i = 0; i < chicken.size(); ++i)
		if (i < m) ci += '1';
		else ci += '0';
	reverse(ci.begin(), ci.end());

	int ret = INF;
	do {
		int tmp2 = 0; //치킨 거리 합
		for (int i = 0; i < house.size(); ++i) {
			int tmp = INF; //한 집에서의 치킨 거리
			for (int j = 0; j < chicken.size(); ++j) {
				if (ci[j] == '0') continue;
				tmp = min(tmp, dist(house[i], chicken[j]));
			}
			tmp2 += tmp;
		}
		ret = min(ret, tmp2);

	} while (next_permutation(ci.begin(), ci.end()));
	
	cout << ret;

	return 0;
}