//2606

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, a, b, cnt;
int chk[1001];
vector<vector<int>> E;

void dfs(int cur) {

	//�湮�� ��� ǥ��
	chk[cur] = 1;

	//���� ����
	//�ش� ��忡�� ������ ���� ���� ���
	for (int i = 0; i < E[cur].size(); i++) {
		if (chk[E[cur][i]] == 0) break;
		if (i == E[cur].size() - 1) {
			return;
		}
	}

	//Ž��
	for (int i = 0; i < E[cur].size(); i++)
		if (chk[E[cur][i]] == 0) {
			dfs(E[cur][i]);
		}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	E.resize(N + 1);

	//���� �Է�
	while (M--) {
		cin >> a >> b;
		E[a].push_back(b);
		E[b].push_back(a);
	}

	for (int i = 1; i <= N; i++)
		sort(E[i].begin(), E[i].end());

	//1�� ��ǻ�Ϳ��� �����̹Ƿ� ���ڿ� 1�� �־��ش�
	dfs(1);

	//�湮�� ��带 ����
	for (int i = 0; i <= N; i++)
		if (chk[i] == 1) cnt++;

	//1�� ��ǻ�ʹ� �����ؾ� �ϹǷ� -1
	cout << cnt - 1;

	return 0;
}