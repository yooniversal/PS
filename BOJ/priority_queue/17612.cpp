//17612

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
#define INF 987654321
#define MAX 100001
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

struct info {
    int id, w, counter;
};

struct cmp {
    bool operator()(info& a, info& b) { 
        if (a.w == b.w) return a.counter > b.counter;
        return a.w > b.w;
    }
};

bool vcmp(info& a, info& b) { return a.w == b.w ? a.counter > b.counter : a.w < b.w; }

priority_queue<info, vector<info>, cmp> pq;
int cnt;
ll ret;
vector<info> v;

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int id, w; cin >> id >> w;
        //계산대가 찰 때까지
        if (i < k) {
            pq.push({ id, w, i+1 });
            continue;
        }
        else {
            pq.push({ id, w + pq.top().w , pq.top().counter });
            v.push_back(pq.top());
            pq.pop();
        }
    }
    //처리되지 않은 것들
    while (!pq.empty()) {
        v.push_back(pq.top());
        pq.pop();
    }

    sort(v.begin(), v.end(), vcmp);
    for (int i = 0; i < v.size(); i++) {
        ret += 1LL * (i + 1) * v[i].id;
    }

    cout << ret;

    return 0;
}