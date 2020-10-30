//9202
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 300001
#define MOD 1000000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

bool chk[MAX], used[5][5];
vector<string> m, words;
string retWORD;
int dx[] = { -1,-1,-1,0, 0,1,1,1 }, dy[] = { -1,0,1,-1,1,-1,0,1 };
int score, cnt;

struct Trie {
	bool finish;
	int word_index;
	Trie* next[26];
	Trie() :finish(false), word_index(-1) {
		memset(next, 0, sizeof(next));
	}
	~Trie() {
		for (int i = 0; i < 26; i++)
			if (next[i]) delete next[i];
	}
	void insert(const string& key, int idx, int tmp) {
		if (idx == key.size()) {
			bool isEnd = true;
			for (int i = 0; i < 26; i++)
				if (next[i] != NULL) {
					isEnd = false;
					break;
				}
			if (isEnd) {
				finish = true;
			}
			word_index = tmp;
		}
		else {
			int cur = key[idx] - 'A';
			if (next[cur] == NULL) {
				next[cur] = new Trie();
			}
			if (next[cur]->finish == true) next[cur]->finish = false;
			next[cur]->insert(key, idx + 1, tmp);
		}
	}
	//문자열이 끝나는 위치를 반환
	Trie* find(const string& key, int idx) {
		if (idx == key.size()) return this;
		int cur = key[idx] - 'A';
		if (next[cur] == NULL) return NULL;
		return next[cur]->find(key, idx + 1);
	}
};

bool OOB(int x, int y) {
	if (x < 0 || x >= 4 || y < 0 || y >= 4) return true;
	return false;
}

void solve(int x, int y, Trie* cur) {
	if (cur->word_index != -1) {
		if (!chk[cur->word_index]) {
			chk[cur->word_index] = true;
			if (words[cur->word_index].size() == 1 || words[cur->word_index].size() == 2) score += 0;
			else if (words[cur->word_index].size() == 3 || words[cur->word_index].size() == 4) score += 1;
			else if (words[cur->word_index].size() == 5) score += 2;
			else if (words[cur->word_index].size() == 6) score += 3;
			else if (words[cur->word_index].size() == 7) score += 5;
			else score += 11;
			++cnt;	

			if (retWORD.size() < words[cur->word_index].size()) retWORD = words[cur->word_index];
			else if (retWORD.size() == words[cur->word_index].size())
				retWORD = min(retWORD, words[cur->word_index]);
		}
	}

	for (int i = 0; i < 8; ++i) {
		int nx = x + dx[i], ny = y + dy[i];
		if (OOB(nx, ny)) continue;
		if (cur->next[m[nx][ny]-'A'] == NULL) continue;
		if (used[nx][ny]) continue;
		used[nx][ny] = true;
		solve(nx, ny, cur->next[m[nx][ny]-'A']);
		used[nx][ny] = false;
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	Trie* root = new Trie;
	int w; cin >> w;
	for (int i = 0; i < w; ++i) {
		string word; cin >> word;
		words.push_back(word);
		root->insert(word, 0, i);
	}

	int b; cin >> b;
	while (b--) {
		memset(chk, 0, sizeof(chk));
		memset(used, 0, sizeof(used));
		score = 0; retWORD = ""; cnt = 0;
		m.resize(4, "");
		for (int i = 0; i < 4; ++i) cin >> m[i];
		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 4; ++j) {
				if (root->next[m[i][j]-'A'] == NULL) continue;
				used[i][j] = true;
				solve(i, j, root->next[m[i][j]-'A']);
				used[i][j] = false;
			}

		cout << score << ' ' << retWORD << ' ' << cnt << '\n';
	}

	return 0;
}