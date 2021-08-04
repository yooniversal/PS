#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct Trie {
    bool finish;
    int SIZE;
    Trie* next[26];
    Trie() :finish(false), SIZE(0) {
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
    //문자열이 끝나는 위치를 반환
    Trie* find(const string& key, int idx) {
        if (idx == key.size()) return this;
        int cur = key[idx] - 'a';
        if (next[cur] == NULL) return NULL;
        return next[cur]->find(key, idx + 1);
    }
};

Trie* root[10001];
Trie* reverse_root[10001];

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;

    for (int i = 0; i < words.size(); ++i) {
        if (root[words[i].size()] == NULL) root[words[i].size()] = new Trie;
        root[words[i].size()]->insert(words[i], 0);
        reverse(words[i].begin(), words[i].end());
        if (reverse_root[words[i].size()] == NULL) reverse_root[words[i].size()] = new Trie;
        reverse_root[words[i].size()]->insert(words[i], 0);
    }

    for (int i = 0; i < queries.size(); ++i) {
        string now;
        for (int j = 0; j < queries[i].size(); ++j)
            if (queries[i][j] != '?')
                now += queries[i][j];
        bool start = queries[i][0] == '?' ? false : true;
        if (start) {
            if (root[queries[i].size()] == NULL) {
                answer.push_back(0);
                continue;
            }
            if (!now.size()) {
                answer.push_back(root[queries[i].size()]->SIZE);
                continue;
            }

            Trie* cur = new Trie;
            cur = root[queries[i].size()]->find(now, 0);
            if (cur != NULL) answer.push_back(cur->SIZE);
            else answer.push_back(0);
        }
        else {
            if (reverse_root[queries[i].size()] == NULL) {
                answer.push_back(0);
                continue;
            }
            if (!now.size()) {
                answer.push_back(reverse_root[queries[i].size()]->SIZE);
                continue;
            }

            reverse(now.begin(), now.end());
            Trie* cur = new Trie;
            cur = reverse_root[queries[i].size()]->find(now, 0);
            if (cur != NULL) answer.push_back(cur->SIZE);
            else answer.push_back(0);
        }
    }

    return answer;
}