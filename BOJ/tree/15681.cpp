//15681
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
#define MAXSIZE 100001
vector<int> node[MAXSIZE];
int dp[MAXSIZE];
bool chk[MAXSIZE];
int countnodes(int r) {
	if (dp[r]) return dp[r];
	int sum = 0;
	bool leaf = true;
	for (int i = 0; i < node[r].size(); i++) {
		int next = node[r][i];
		if (!chk[next]) {
			chk[next] = true;
			sum += countnodes(next);
			leaf = false;
		}
	}
	if (leaf) return 1;
	dp[r] = sum;
	return sum + 1;
}
int main() {
	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N, R, Q;
	cin >> N >> R >> Q;
	chk[R] = true;
	for (int i = 1; i <= N - 1; i++) {
		int s, e;
		cin >> s >> e;
		node[s].push_back(e);
		node[e].push_back(s);
	}
	countnodes(R);	//서브트리 노드개수 만들어주기
	for (int i = 0; i < Q; i++) {
		int query;
		cin >> query;
		cout << dp[query] + 1 << '\n';
	}
	return 0;
}