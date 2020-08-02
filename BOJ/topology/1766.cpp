//1766

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
#define MAXSIZE 32001

typedef long long ll;
vector<int> node[MAXSIZE];
vector<int> ans;
int degree[MAXSIZE];
bool chk[MAXSIZE];

void topology(int n) {
    priority_queue<int, vector<int>, greater<int>> q;

    //진입 차수가 0인 노드를 삽입
    for (int i = 1; i <= n; i++) {
        if (!degree[i]) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int cur = q.top(); q.pop();
        chk[cur] = true;
        ans.push_back(cur);

        //이웃된 노드의 간선을 모두 삭제
        for (auto& next : node[cur]) {
            if (!chk[next]) {
                degree[next]--;
                //진입 차수가 0이면 큐에 삽입
                if (!degree[next]) {
                    q.push(next);
                }
            }
        }
    }
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);


    int n, m;
    cin >> n >> m;

    while (m--) {
        int s, e;
        cin >> s >> e;
        node[s].push_back(e);
        node[e].push_back(s);
        degree[e]++;
    }

    topology(n);

    //answer
    for (auto& a : ans) cout << a << " ";

    return 0;
}