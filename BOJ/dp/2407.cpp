//2407
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define MAX 4000005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

string cache[105][105];

string add(const string& input1, const string& input2) {
	int ml = input1.size(), nl = input2.size();; 
	vi m(31,0), n(31,0), s(31,0);

	for (int i = 0; i < ml; i++)
		m[ml - i - 1] = input1[i] - '0';

	for (int i = 0; i < nl; i++)
		n[nl - i - 1] = input2[i] - '0';

	int maxx = max(ml, nl);

	int carry = 0;
	for (int i = 0; i < maxx; i++) {
		int tmp = m[i] + n[i] + carry;
		carry = tmp / 10;
		s[i] = tmp % 10;
	}

	if (carry > 0) {
		s[maxx] = carry;
		maxx++;
	}

	string ret;
	for (int i = 0; i < maxx; i++)
		ret += s[maxx - i - 1] + '0';
	return ret;
}

string f(int N, int M) {
    if (N == 1) return "1";
    if (M == 0 || M == N) return "1";
	string& ret = cache[N][M];
    if (ret != "-1") return ret;
    ret = add(f(N - 1, M - 1), f(N - 1, M));
    return ret;
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

	for (int i = 0; i < 105; ++i)
		for (int j = 0; j < 105; ++j)
			cache[i][j] = "-1";
	int N, R; cin >> N >> R;
    cout << f(N, R);

    return 0;
}