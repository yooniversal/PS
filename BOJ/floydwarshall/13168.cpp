//2629
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

double d[105][105];
double d2[105][105]; //≥ª¿œ∑Œ
map<string, int> city;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 0; i < 105; ++i)
		for (int j = 0; j < 105; ++j)
			if (i != j) {
				d[i][j] = INF;
				d2[i][j] = INF;
			}

	int n, r; cin >> n >> r;
	for (int i = 1; i <= n; ++i) {
		string s; cin >> s;
		city[s] = i;
	}
	int m; cin >> m;
	vi target;
	for (int i = 0; i < m; ++i) {
		string s; cin >> s;
		target.push_back(city[s]);
	}
	int k; cin >> k;
	for (int i = 0; i < k; ++i) {
		string type, s, e; double cost;
		cin >> type >> s >> e >> cost;
		int sn = city[s], en = city[e];
		d[sn][en] = min(d[sn][en], cost);
		d[en][sn] = min(d[en][sn], cost);
		if (type == "Mugunghwa" || type == "ITX-Saemaeul" || type == "ITX-Cheongchun") {
			d2[sn][en] = 0;
			d2[en][sn] = 0;
		}
		else if (type == "S-Train" || type == "V-Train") {
			d2[sn][en] = min(d2[sn][en], cost / 2);
			d2[en][sn] = min(d2[en][sn], cost / 2);
		}
		else {
			d2[sn][en] = min(d2[sn][en], cost);
			d2[en][sn] = min(d2[en][sn], cost);
		}
	}

	for(int k=1; k<=n; ++k)
		for(int i=1; i<= n; ++i)
			for (int j = 1; j <= n; ++j) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				d2[i][j] = min(d2[i][j], d2[i][k] + d2[k][j]);
			}

	double r1 = 0, r2 = r;
	for (int i = 0; i < target.size()-1; ++i) {
		r1 += d[target[i]][target[i + 1]];
		r2 += d2[target[i]][target[i + 1]];
	}
	if (r1 <= r2) cout << "No";
	else cout << "Yes";

	return 0;
}