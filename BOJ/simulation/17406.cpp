//17406
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 9901;

struct P {
	int r, c, s;
};

int n, m, k;
int order[6], ret = INF;
P query[6];

// ���簢�� ȸ�� & ���� ��ʿ��� �ּڰ� ���
void rotate(vvi& a, int r, int c, int s) {
	if (s == 0) return;

	// ���� ��� -> ���� �ϴ�
	for (int x = r - s; x <= r + s - 1; ++x)
		swap(a[x][c - s], a[x + 1][c - s]);
	// ���� �ϴ� -> ���� �ϴ�
	for (int y = c - s; y <= c + s - 1; ++y)
		swap(a[r + s][y], a[r + s][y + 1]);
	// ���� �ϴ� -> ���� ���
	for (int x = r + s; x >= r - s + 1; --x)
		swap(a[x][c + s], a[x - 1][c + s]);
	// ���� ��� -> ���� ���
	for (int y = c + s; y >= c - s + 2; --y)
		swap(a[r - s][y], a[r - s][y - 1]);

	rotate(a, r, c, s - 1);
}

void cal(vvi& a) {
	for (int i = 0; i < n; ++i) {
		int sum = 0;
		for (int j = 0; j < m; ++j) {
			sum += a[i][j];
		}
		ret = min(ret, sum);
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m >> k;
	vvi a(n, vi(m));
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		cin >> a[i][j];
	}

	for (int i = 0; i < k; ++i) {
		cin >> query[i].r >> query[i].c >> query[i].s;
		--query[i].r, --query[i].c;
	}

	for (int i = 0; i < 6; ++i) order[i] = i;

	// ��� ���� ��ȸ
	do {
		vvi tmp = a;
		for (int i = 0; i < k; ++i) {
			int o = order[i];
			rotate(tmp, query[o].r, query[o].c, query[o].s);
		}
		cal(tmp);
	} while (next_permutation(order, order + k));

	cout << ret << '\n';

	return 0;
}