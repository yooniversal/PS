//16357
//non-complete

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
#define INF 1000000001
#define MAX 100001
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

struct Square {
	int y1, y2, num;

	Square(int a, int b, int c) : y1(a), y2(b), num(c) {}
};

struct Line {
	int y, num, start;

	Line(int c, int d, int e) : y(c), num(d), start(e) {}
	bool operator<(Line& L) {
		if (y != L.y) return y > L.y;
		return start > L.start;
	}
};

bool chk[MAX];
vi idx;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	vector<Line> l;
	vector<Square> squ;
	for (int i = 0; i < n; i++) {
		int ux, uy, vx, vy; cin >> ux >> uy >> vx >> vy;
		l.push_back(Line(uy, i, 1));
		l.push_back(Line(vy, i, 0));
		squ.push_back(Square(vy, uy, i));
	}
	sort(l.begin(), l.end());

	//첫 스위핑
	int ret1 = 0, cur = 0;
	int h = INF;
	for (int i = 0; i < l.size(); i++) {
		if (l[i].start) {
			cur++;
			if (ret1 < cur) {
				ret1 = cur;
				h = l[i].y;
			}
		}
		else 
			cur--;
	}

	for (int i = 0; i < squ.size(); i++) {
		if (squ[i].y1 <= h && h <= squ[i].y2)
			idx.push_back(squ[i].num);
	}

	//처음에 처리된 사각형은 체크해놓기
	for (int i = 0; i < idx.size(); i++)
		chk[idx[i]] = true;

	cur = 0;

	//두번째 스위핑
	int ret2 = 0;
	for (int i = 0; i < l.size(); i++) {
		if (chk[l[i].num]) continue;
		if (l[i].start) {
			cur++;
			ret2 = max(ret2, cur);
		}
		else {
			cur--;
		}
	}

	cout << ret1 + ret2;

	return 0;
}