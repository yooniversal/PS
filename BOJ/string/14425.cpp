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

struct Trie {
	bool finish;
	Trie* next[26];
	Trie() :finish(false) { memset(next, 0, sizeof(next)); }
	~Trie() {
		for (int i = 0; i < 26; i++)
			if (next[i]) delete next[i];
	}
	void insert(const string& key, int idx) {
		if (idx == key.size()) finish = true;
		else {
			int cur = key[idx] - 'a';
			//입력되지 않았다면
			if (next[cur] == NULL) next[cur] = new Trie();
			next[cur]->insert(key, idx + 1);
		}
	}
	//문자열이 끝나는 위치를 반환
	Trie* find(const string& key, int idx) {
		if (idx == key.size()) return this;
		int cur = key[idx] - 'a';
		//없는 경우
		if (next[cur] == NULL) return NULL;
		return next[cur]->find(key, idx + 1);
	}
};

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, ans=0;
	Trie* root = new Trie;
	cin >> n >> m;

	while (n--) {
		string s; cin >> s;
		root->insert(s, 0);
	}
	while (m--) {
		string s; cin >> s;
		if (root->find(s, 0) == NULL) continue;
		if (root->find(s, 0)->finish) {
			ans++;
			//cout << "s:"<<s << '\n';
		}
	}
	
	cout << ans;
	delete root;

	return 0;
}