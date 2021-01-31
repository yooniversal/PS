//2503
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 1000001, INF = 1000000001, MOD = 1234567;

struct P {
	int v, s, b; //값, 스트라이크, 볼
};

int n;
vector<P> Case;

//서로 다른 정수만 체크
bool diff(int cur) {
	int h = cur / 100, t = (cur / 10) % 10, o = cur % 10; //백, 십, 일의자리
	if (h == t || h == o || t == o) return false;
	return true;
}

//모든 케이스를 통과하면 true 반환
bool solve(int cur) {
	int cur_digit[3] = { cur / 100, (cur / 10) % 10, cur % 10 }; //백, 십, 일의자리
	for (int i = 0; i < n; ++i) {
		P next = Case[i];
		int next_digit[3] = { next.v / 100, (next.v / 10) % 10, next.v % 10 }; //기준 백, 십, 일의자리
		int cur_s = 0, cur_b = 0; //실제 판단 값
		for (int j = 0; j < 3; ++j) {
			for (int k = 0; k < 3; ++k) {
				if (cur_digit[j] == next_digit[k]) {
					if (j == k) ++cur_s;
					else ++cur_b;
				}
			}
		}

		//기준 미충족
		if (!(cur_s == next.s && cur_b == next.b)) return false;
	}

	//모든 케이스 통과
	return true;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		int v, s, b; cin >> v >> s >> b;
		Case.push_back({ v,s,b });
	}

	int ret = 0;
	for (int i = 111; i <= 999; ++i) {
		//숫자 0이 들어가는 케이스 & 자릿수가 같은 경우 -> 제외
		if ((i / 10) % 10 == 0 || i % 10 == 0 || !diff(i)) continue;
		if (solve(i)) ++ret;
	}

	cout << ret << '\n';

	return 0;
}