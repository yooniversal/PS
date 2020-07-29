//5052

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

typedef long long ll;

bool ans;

struct Trie {
	bool finish;
	Trie* next[10];
	Trie() :finish(false) { memset(next, 0, sizeof(next)); }
	~Trie() {
		for (int i = 0; i < 10; i++)
			if (next[i]) delete next[i];
	}
	void insert(string key, int idx) {
		if (idx == key.size()) {
			bool isEnd = true;
			for (int i = 0; i < 10; i++)
				if (next[i] != NULL) {
					isEnd = false;
					break;
				}
			if(isEnd) finish = true;
		}
		else {
			int cur = key[idx] - '0';
			//입력되지 않았다면
			if (next[cur] == NULL) {
				next[cur] = new Trie();
			}
			if (next[cur]->finish == true) next[cur]->finish = false;
			next[cur]->insert(key, idx+1);
		}
	}
	//문자열이 끝나는 위치를 반환
	Trie* find(string key, int idx) {
		if (idx == key.size()) return this;
		int cur = key[idx] - '0';
		if (next[cur] == NULL) return NULL;
		return next[cur]->find(key, idx+1);
	}
};

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		Trie* root = new Trie;
		vector<string> tmp;
		int n; cin >> n;
		while(n--) {
			string s; cin >> s;
			tmp.push_back(s);
			root->insert(s, 0);
		}

		//answer
		bool ans = true;
		for (int i = 0; i < tmp.size(); i++) {
			if (root->find(tmp[i], 0)->finish == false) {
				ans = false;
				break;
			}
		}
		if (ans) cout << "YES" << '\n';
		else cout << "NO" << '\n';

		delete root;
	}

	return 0;
}