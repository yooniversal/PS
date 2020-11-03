//5446
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
	bool finish, ban, wordfin;
	Trie* next[63];
	Trie() :finish(false), ban(false), wordfin(false) {
		memset(next, 0, sizeof(next));
	}
	~Trie() {
		for (int i = 0; i < 63; i++)
			if (next[i]) delete next[i];
	}
	void insert(const string& key, bool ban, int idx=0) {
		if (idx == key.size()) {
			bool isEnd = true;
			for (int i = 0; i < 63; i++)
				if (next[i] != NULL) {
					isEnd = false;
					break;
				}
			if (isEnd) finish = true;
			if (ban) this->ban = true;
			else this->wordfin = true;
		}
		else {
			int cur;
			if (isupper(key[idx])) cur = key[idx] - 'A';
			else if (islower(key[idx])) cur = key[idx] - 'a' + 26;
			else if ('0' <= key[idx] && key[idx] <= '9') cur = key[idx] - '0' + 52;
			else cur = 62;

			if (ban) this->ban = true;
			if (next[cur] == NULL) next[cur] = new Trie();
			if (next[cur]->finish == true) next[cur]->finish = false;
			next[cur]->insert(key, ban, idx + 1);
		}
	}
};

int ret;

void solve(Trie* root) {
	if (root->ban) {
		if (root->wordfin) ++ret;
		for (int i = 0; i < 63; ++i)
			if (root->next[i] != NULL)
				solve(root->next[i]);
	}
	else {
		for (int i = 0; i < 63; ++i)
			if (root->next[i] != NULL) {
				++ret;
				return;
			}
		if (root->wordfin) ++ret;
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		ret = 0;
		Trie* root = new Trie();

		//제거 대상 리스트
		int n1; cin >> n1;
		for (int i = 0; i < n1; ++i) {
			string s; cin >> s;
			root->insert(s, false);
		}

		//삭제 금지 리스트
		int n2; cin >> n2;
		for (int i = 0; i < n2; ++i) {
			string s; cin >> s;
			root->insert(s, true);
		}

		solve(root);
		cout << ret << '\n';

		delete root;
	}

	return 0;
}