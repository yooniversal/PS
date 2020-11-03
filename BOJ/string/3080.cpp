//3080
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100005
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

struct Trie {
	bool finish;
	vector<pair<char, Trie*>> next;
	Trie() :finish(false) {}
	void insert(const string& key, int idx=0) {
		if (idx == key.size()) {
			if (next.size() == 0) finish = true;
			return;
		}
		else {
			int cur;
			if (isupper(key[idx])) cur = key[idx] - 'A';
			else cur = 26;

			bool exist = false;
			for (auto& p : next) {
				if (p.first == cur) {
					p.second->finish = false;
					p.second->insert(key, idx + 1);
					exist = true;
					break;
				}
			}
			if (!exist) {
				next.push_back({ cur, new Trie() });
				next.back().second->insert(key, idx + 1);
			}
		}
	}
};

ll pac[30];
ll ret = 1;

void solve(Trie* root) {
	for (auto& p : root->next)
		solve(p.second);

	ret *= pac[root->next.size()];
	ret %= MOD;
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

	pac[0] = pac[1] = 1;
	for (ll i = 2; i < 30; ++i) {
		pac[i] = pac[i - 1] * i;
		pac[i] %= MOD;
	}

	Trie* root = new Trie;
	int n; cin >> n;
	vector<string> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		a[i] += ' ';
	}

	for (int i = 0; i < n; ++i)
		root->insert(a[i]);

	solve(root);
	delete root;

	ret %= MOD;
	cout << ret;

    return 0;
}