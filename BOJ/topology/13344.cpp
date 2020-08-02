//13344

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
#define MAXSIZE 50001

struct oper {
    int K, L;
};

typedef long long ll;
vector<int> node[MAXSIZE];
vector<oper> tmp;
vector<int> ans;
int degree[MAXSIZE], uni[MAXSIZE];
bool chk[MAXSIZE];

int find_parent(int a) {
    if (uni[a] == a) return a;
    return uni[a] = find_parent(uni[a]);
}

void make_union(int a, int b) {
    int pa = find_parent(a);
    int pb = find_parent(b);
    if (pa != pb) {
        if (pa < pb) uni[pb] = pa;
        else uni[pa] = pb;
    }
}

void topology(int n) {
    queue<int> q;

    //진입 차수가 0인 노드를 삽입
    for (int i = 0; i < n; i++)
        if (degree[i] == 0)
            q.push(i);

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        chk[cur] = true;
        ans.push_back(cur);

        //이웃된 노드의 간선을 모두 삭제
        for (auto& next : node[cur]) {
            if (!chk[next]) {
                //chk[next] = true;
                degree[next]--;
                //진입 차수가 0이면 큐에 삽입
                if (degree[next] == 0) {
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

    bool answer = true;
    int n, m;
    cin >> n >> m;

    //initilaize union
    for (int i = 1; i <= n; i++) uni[i] = i;

    for (int i = 0; i < m; i++) {
        int s, e; char op;
        cin >> s >> op >> e;
        if (op == '=') {
            make_union(s, e);
        }
        else {
            tmp.push_back({ s, e });
        }
    }

    //child's degree is -1
    int childs = 0;
    for (int i = 0; i < n; i++)
        if (find_parent(i) != i) {
            degree[i] = -1;
            chk[i] = true;
            childs++;
        }

    
    //K > L
    for (int i = 0; i < tmp.size(); i++) {
        int K = find_parent(tmp[i].K);
        int L = find_parent(tmp[i].L);

        if (find_parent(K) == find_parent(L)) answer = false;
        node[K].push_back(L);
        node[L].push_back(K);
        degree[L]++;
    }

    if (!answer) {
        cout << "inconsistent";
        return 0;
    }

    topology(n);
    if (ans.size() != n-childs) answer = false;

    //answer
    if (!answer) cout << "inconsistent";
    else cout << "consistent";

    return 0;
}