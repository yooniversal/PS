//15973

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
#define MAX 701
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

struct range {
	int x1, x2, y1, y2;
};

int height(range A, range B) {
	if (A.y1 > B.y1) swap(A, B);

	if (B.y1 < A.y2) return 1;
	else if (B.y2 < A.y2) return 2;
	else if (A.y2 == B.y1) return 3;
	else return 4;
}

string width(range A, range B) {
	if (A.x1 > B.x1) swap(A, B);
	
	//겹칠때
	if (B.x1 < A.x2) {
		if (height(A, B) == 1) return "FACE";
		if (height(A, B) == 2) return "FACE";
		if (height(A, B) == 3) return "LINE";
		if (height(A, B) == 4) return "NULL";
	}
	//포함될때
	else if (B.x2 < A.x2) {
		if (height(A, B) == 1) return "FACE";
		if (height(A, B) == 2) return "FACE";
		if (height(A, B) == 3) return "LINE";
		if (height(A, B) == 4) return "NULL";
	}
	//일치할 때
	else if (A.x2 == B.x1) {
		if (height(A, B) == 1) return "LINE";
		if (height(A, B) == 2) return "LINE";
		if (height(A, B) == 3) return "POINT";
		if (height(A, B) == 4) return "NULL";
	}
	//닿지 않을 때
	else {
		return "NULL";
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<range> squ;
	for (int i = 0; i < 2; i++) {
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		squ.push_back({ x1, x2, y1, y2 });
	}

	cout << width(squ[0], squ[1]);

	return 0;
}