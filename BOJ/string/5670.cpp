//5670

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

int ans;
bool prevfin;

struct Trie {
    bool finish[26];
    int kind;
    Trie* next[26];
    Trie() : kind(0) { 
        memset(next, 0, sizeof(next));
        memset(finish, false, sizeof(finish));
    }
    ~Trie() {
        for (int i = 0; i < 26; i++)
            if (next[i]) delete next[i];
    }
    void insert(const string& key, int idx) {
        if (idx == key.size()) return;
        else {
            int cur = key[idx] - 'a';
            //입력되지 않았다면
            if (next[cur] == NULL) {
                next[cur] = new Trie();
                kind++;
            }
            if (idx == key.size() - 1) finish[cur] = true;
            next[cur]->insert(key, idx + 1);
        }
    }
    //문자열이 끝나는 위치를 반환
    Trie* find(const string& key, int idx) {
        if (idx == key.size()) {
            return this;
        }
        int cur = key[idx] - 'a';

        if (next[cur] == NULL) return NULL; 
        if (kind >= 2) ans++; //종류 2개 이상
        else if (prevfin) ans++; //이전에 finish가 있다면
        
        if (finish[cur]) prevfin = true;
        else prevfin = false;

        return next[cur]->find(key, idx + 1);
    }
};

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	//ios_base::sync_with_stdio(false);

    int n;
    while (scanf("%d", &n) > 0) {
        ans = 0; prevfin = false;
        Trie* root = new Trie;
        vector<string> tmp;
        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            root->insert(s, 0);
            tmp.push_back(s);
        }

        for (int i = 0; i < n; i++) {
            prevfin = false;
            root->find(tmp[i], 0);
            if (root->kind == 1) ans++;
        }

        printf("%.2lf\n", (double)ans / (double)n);

        delete root;
    }

	return 0;
}