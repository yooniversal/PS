#include <bits/stdc++.h>
using namespace std;

struct Trie {
	bool finish, WORDFIN;
	int SIZE;
	Trie* next[26];
	Trie() :finish(false), WORDFIN(false), SIZE(0) {
		memset(next, 0, sizeof(next));
	}
	~Trie() {
		for (int i = 0; i < 26; i++)
			if (next[i]) delete next[i];
	}
	void insert(const string& key, int idx) {
		if (idx == key.size()) {
			bool isEnd = true;
			for (int i = 0; i < 26; i++)
				if (next[i] != NULL) {
					isEnd = false;
					break;
				}
			if (isEnd) finish = true;
			WORDFIN = true;
			++SIZE;
		}
		else {
			int cur = key[idx] - 'a';
			if (next[cur] == NULL) {
				next[cur] = new Trie();
			}
			if (next[cur]->finish == true) next[cur]->finish = false;
			next[cur]->insert(key, idx + 1);
			++SIZE;
		}
	}
};

int solve(Trie* root, int cnt) {
	int ret = 0;
	if (root->finish || root->SIZE == 1) return cnt;
	if (root->WORDFIN) ret += cnt;

	for (int i = 0; i < 26; ++i)
		if (root->next[i] != NULL)
			ret += solve(root->next[i], cnt + 1);

	return ret;
}

int solution(vector<string> words) {
	Trie* root = new Trie();
	for (auto& w : words) root->insert(w, 0);
	return solve(root, 0);
}