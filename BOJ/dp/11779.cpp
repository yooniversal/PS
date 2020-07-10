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
int d[1001];						//start���� �� index��° ������ �Ÿ�
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
	d[start] = 0;	//���� �ڸ��� �Ÿ� 0
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });
	while (!pq.empty()) {
		//�ּ� �Ÿ��� ���� ������ Ž��
		int dist = -pq.top().first;	//start~cur �Ÿ�
		int cur = pq.top().second;
		pq.pop();
		
		if (cur == e) break;
		if (dist > d[cur]) continue;

		for (int i = 0; i < map[cur].size(); i++) {
			int Next = map[cur][i].first;
			int Ndist = map[cur][i].second;
			if (d[Next] > dist + Ndist) {
				d[Next] = dist + Ndist;				//���� �Ÿ����� ���İ��°� �� ������ ������Ʈ
				pq.push({ -d[Next], Next });		//�ּ� ���� ���� ����ġ�� ������ ����
				ans[Next] = cur;					//��� ������ ���� ���� ��ġ�� ����
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