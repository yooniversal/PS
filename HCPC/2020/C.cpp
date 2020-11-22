#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 10000001
#define MOD 1000000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

struct T{
	string a;
	int i;
	bool operator<(T& t) {
		return a < t.a;
	}
};

struct P{
	int a, i; //사전, 순서
};

int n;
vector<T> a;
vector<P> info;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i].a;
		a[i].i = i;
	}
	sort(a.begin(), a.end());
	info.resize(n);
	for (int i = 0; i < n; ++i) {
		info[i].i = i;
		info[a[i].i].a = i;
	}
	
	vi target;
	target.push_back(info[0].a);
	for (int i = 1; i < n; ++i) {
		if (target.back() < info[i].a)
			target.push_back(info[i].a);
		else {
			auto it = lower_bound(target.begin(), target.end(), info[i].a);
			*it = info[i].a;
		}
	}
	cout << target.size();

	return 0;
}