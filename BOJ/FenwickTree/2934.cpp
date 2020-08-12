//2934

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
#define MAXSIZE 100001
typedef long long ll;

ll tree[MAXSIZE];

void update(int i, ll diff) {
    //i~100000 ������Ʈ
    while (i < MAXSIZE) {
        tree[i] += diff;
        i += (i & -i);
    }
}

ll sum(int i) {
    ll ans = 0;
    //1~i ��
    while (i > 0) {
        ans += tree[i];
        i -= (i & -i);
    }
    return ans;
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N; cin >> N;
    
    while (N--) {
        int L, R; cin >> L >> R;
        ll lh = sum(L), rh = sum(R);
        
        //L, R ��ġ���� �������� ��ŭ ����ؾ� �Ѵ�
        cout << lh + rh << '\n';

        //�� �� ������ �������� �κ��� 0�� �ȴ�
        update(L, -lh); update(L + 1, lh);
        update(R, -rh); update(R + 1, rh);

        //�� �� ������ ������ �������� �� ĭ �� ��������
        update(L + 1, 1); update(R, -1);
    }

    return 0;
}