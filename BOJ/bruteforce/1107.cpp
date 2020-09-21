//1107
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 41
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

bool ban[10];
vi button;
int n, m;
int ret = INF;

void close(string N, int cur_digit, int target) {
	if (cur_digit == N.size()) return;

	int tmp = INF;
	for (int i = 0; i < button.size(); ++i) {
		tmp = target * 10 + button[i];
		if (abs(n - ret)+to_string(ret).size() > abs(n - tmp)+to_string(tmp).size()) ret = tmp;
		close(N, cur_digit + 1, tmp);
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a; cin >> a;
		ban[a] = true;
	}

	//사용 가능한 버튼들
	for (int i = 0; i < 10; ++i)
		if (!ban[i])
			button.push_back(i);

	//100에서 +-
	int sub = abs(n - 100);

	//숫자 자릿수 맞췄을 때
	string N = to_string(n);
	int sub2 = INF;
	if (m != 10) {
		close(N, 0, 0);
		sub2 = to_string(ret).size() + abs(n - ret);
	}

	//숫자 자릿수+1
	int sub3 = INF;
	if (button.size() >= 2)
		if (button[0] == 0) sub3 = button[1];
		else sub3 = button[0];
	else if (button.size() == 1) sub3 = button[0];

	if (m != 10)
		for (int i = 0; i < N.size(); ++i)
			sub3 = sub3 * 10 + button[0];

	sub3 = to_string(sub3).size() + abs(n - sub3);

	cout << min(sub, min(sub2, sub3));

	return 0;
}