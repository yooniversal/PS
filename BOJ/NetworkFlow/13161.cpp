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

//S~E 각 level 설정
//경로 설정
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

//경로 cur~dest의 최대 유량
int dfs(int cur, int dest, int flow) {
	//목표 지점까지 도달했다면 유량을 반환
	if (cur == dest) return flow;

	for (int& i = work[cur]; i < adj[cur].size(); i++) {
		int next = adj[cur][i];
		//잔여 용량이 있으면서 인접 노드와의 레벨 차이가 1일 때
		if (level[next] - level[cur] == 1 && c[cur][next] - f[cur][next] > 0) {
			int df = dfs(next, dest, min(c[cur][next] - f[cur][next], flow)); //끝까지 돌면서 최대 유량 가져옴
			//유량이 존재하면 바로 종료
			if (df > 0) {
				f[cur][next] += df;
				f[next][cur] -= df;
				return df;
			}
		}
	}
	//모든 경로에서 유량 존재X
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
		//c[][] = INF로 정해놓는 이유 :
		//유량이 아무리 많아도 용량을 넘지 못하게 설정
		//최종적으로 특정 팀(A or B)에 속해있음을 의미

		//team A
		if (team == 1) {
			c[S][i] = INF; //Source -> 각 노드
			adj[S].push_back(i);
			adj[i].push_back(S);
		}
		//team B
		else if (team == 2) {
			c[i][E] = INF; //각 노드 -> End
			adj[i].push_back(E);
			adj[E].push_back(i);
		}
	}
	//S, E를 제외한 모든 노드는 서로 인접하도록 설정
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> c[i][j];
			if (i != j) adj[i].push_back(j);
		}
	}

	int ret = 0;
	//S~E의 경로 설정이 가능하다면
	while (bfs()) {
		fill(work, work + MAX, 0);
		while (1) {
			int flow = dfs(S, E, INF);
			if (flow == 0) break; //유량이 더 이상 없으면 탈출
			ret += flow;
		}
	}
	cout << ret << '\n'; //최대 유량 출력

	//visited[i] = true인 i는 A에 속함을 의미
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