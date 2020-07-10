//11779

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
using namespace std;
#define INF 987654321

vector<pair<int, int>> map[1001];
int d[1001];						//start에서 각 index번째 노드까지 거리
int num, edge, e;
int ans[1001];
stack<int> answer;

void ansprt(int n) {
	if (d[n] != 0) {
		answer.push(ans[n]);
		ansprt(ans[n]);
	}
	else {
		cout << answer.size() << '\n';
		while (!answer.empty()) {
			cout << answer.top() << " ";
			answer.pop();
		}
	}
}

void daik(int start) {
	d[start] = 0;	//같은 자리는 거리 0
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });
	while (!pq.empty()) {
		//최소 거리를 갖는 노드부터 탐색
		int dist = -pq.top().first;	//start~cur 거리
		int cur = pq.top().second;
		pq.pop();
		
		if (cur == e) break;
		if (dist > d[cur]) continue;

		for (int i = 0; i < map[cur].size(); i++) {
			int Next = map[cur][i].first;
			int Ndist = map[cur][i].second;
			if (d[Next] > dist + Ndist) {
				d[Next] = dist + Ndist;				//기존 거리보다 거쳐가는게 더 빠르면 업데이트
				pq.push({ -d[Next], Next });		//최소 힙을 위해 가중치를 음수로 설정
				ans[Next] = cur;					//경로 추적을 위해 이전 위치를 저장
			}
		}
	}
	answer.push(e);
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int fir, sec, dist;
	cin >> num >> edge;

	for (int i = 1; i <= num; i++) d[i] = INF;

	for (int i = 0; i < edge; i++) {
		cin >> fir >> sec >> dist;
		map[fir].push_back({ sec, dist });
	}

	int s;
	cin >> s >> e;

	daik(s);
	
	cout << d[e] << '\n';
	ansprt(e);

	return 0;
}