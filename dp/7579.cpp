//7579

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

typedef long long ll;
ll dp[101][10001];
ll cl;

//������ ���(M)���� ũ�ų� ������ ������ ��(value)�� ��ȯ
void getans(int N, ll M) {
	for (int i = 0; i <= cl; i++)
		for (int j = 1; j <= N; j++)
			if (dp[j][i] >= M) {
				cout << i;
				return;
			}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, cnt;
	ll M;

	cin >> N >> M;
	vector<pair<ll, ll>> app(N+1);	//first : weight, second : value

	for (int i = 1; i <= N; i++) {
		cin >> app[i].first;
	}
	for (int i = 1; i <= N; i++) {
		cin >> app[i].second;
		cl += app[i].second;
	}

	//process
	//kanpsack
	//���� ������ �� ������ weight�̶��, �̰� value �������� dp�� ����
	for(cnt=1; cnt<=N; cnt++) {
		for (int c = 0; c <= cl; c++) {
			if (c < app[cnt].second) dp[cnt][c] = dp[cnt - 1][c];
			else {
				if (dp[cnt - 1][c] < dp[cnt - 1][c - app[cnt].second] + app[cnt].first) dp[cnt][c] = dp[cnt - 1][c - app[cnt].second] + app[cnt].first;
				else dp[cnt][c] = dp[cnt - 1][c];
			}
		}
	}	

	getans(N, M);

	return 0;
}