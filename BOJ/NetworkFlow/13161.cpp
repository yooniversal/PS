//13161

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;
#define INF 1000000000
#define MAX 505
#define S MAX-2
#define E MAX-1
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int c[MAX][MAX], f[MAX][MAX];
int level[MAX];
int work[MAX];
vi adj[MAX];

//S~E �� level ����
//��� ����
bool bfs() {
	fill(level, level + MAX, -1);
	level[S] = 0;

	queue<int> q;
	q.push(S);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (auto& next : adj[cur]) {
			if (level[next] == -1 && c[cur][next] - f[cur][next] > 0) {
				level[next] = level[cur] + 1;
				q.push(next);
			}
		}
	}

	return level[E] != -1;
}

//��� cur~dest�� �ִ� ����
int dfs(int cur, int dest, int flow) {
	//��ǥ �������� �����ߴٸ� ������ ��ȯ
	if (cur == dest) return flow;

	for (int& i = work[cur]; i < adj[cur].size(); i++) {
		int next = adj[cur][i];
		//�ܿ� �뷮�� �����鼭 ���� ������ ���� ���̰� 1�� ��
		if (level[next] - level[cur] == 1 && c[cur][next] - f[cur][next] > 0) {
			int df = dfs(next, dest, min(c[cur][next] - f[cur][next], flow)); //������ ���鼭 �ִ� ���� ������
			//������ �����ϸ� �ٷ� ����
			if (df > 0) {
				f[cur][next] += df;
				f[next][cur] -= df;
				return df;
			}
		}
	}
	//��� ��ο��� ���� ����X
	return 0;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	//input
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int team; cin >> team;
		//c[][] = INF�� ���س��� ���� :
		//������ �ƹ��� ���Ƶ� �뷮�� ���� ���ϰ� ����
		//���������� Ư�� ��(A or B)�� ���������� �ǹ�

		//team A
		if (team == 1) {
			c[S][i] = INF; //Source -> �� ���
			adj[S].push_back(i);
			adj[i].push_back(S);
		}
		//team B
		else if (team == 2) {
			c[i][E] = INF; //�� ��� -> End
			adj[i].push_back(E);
			adj[E].push_back(i);
		}
	}
	//S, E�� ������ ��� ���� ���� �����ϵ��� ����
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> c[i][j];
			if (i != j) adj[i].push_back(j);
		}
	}

	int ret = 0;
	//S~E�� ��� ������ �����ϴٸ�
	while (bfs()) {
		fill(work, work + MAX, 0);
		while (1) {
			int flow = dfs(S, E, INF);
			if (flow == 0) break; //������ �� �̻� ������ Ż��
			ret += flow;
		}
	}
	cout << ret << '\n'; //�ִ� ���� ���

	//visited[i] = true�� i�� A�� ������ �ǹ�
	bool visited[MAX] = { false, };
	visited[S] = true;
	queue<int> q;
	q.push(S);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (auto& next : adj[cur]) {
			if (c[cur][next] - f[cur][next] > 0 && !visited[next]) {
				visited[next] = true;
				q.push(next);
			}
		}
	}

	//team A
	for (int i = 0; i < n; i++) {
		if (visited[i]) cout << i + 1 << " ";
	}
	cout << '\n';
	//team B
	for (int i = 0; i < n; i++) {
		if (!visited[i]) cout << i + 1 << " ";
	}
	cout << '\n';

	return 0;
}