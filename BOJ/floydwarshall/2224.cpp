//2224
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000007
#define MAX 4000005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int d[100][100];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	//ios_base::sync_with_stdio(false);

	for (int i = 0; i < 100; ++i)
		for (int j = 0; j < 100; ++j)
			d[i][j] = INF;

	int n; cin >> n;
	while (n--) {
		char st, ed;
		scanf(" %c => %c", &st, &ed);
		d[st-'A'][ed-'A'] = 1;
	}
	
	for (int k = 0; k < 100; ++k)
		for (int i = 0; i < 100; ++i)
			for (int j = 0; j < 100; ++j)
				if (d[i][j] > d[i][k] + d[k][j])
					d[i][j] = d[i][k] + d[k][j];

	int cnt = 0;
	for (int i = 0; i < 100; ++i)
		for (int j = 0; j < 100; ++j)
			if (i != j && d[i][j] < 100)
				++cnt;

	cout << cnt << '\n';
	for (int i = 0; i < 100; ++i)
		for (int j = 0; j < 100; ++j)
			if (i != j && d[i][j] < 100)
				printf("%c => %c\n", i + 'A', j + 'A');

	return 0;
}