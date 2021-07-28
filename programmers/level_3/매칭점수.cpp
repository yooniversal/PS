#include <string>
#include <map>
#include <vector>
#include <iostream>
using namespace std;

double score[21];
double result[21];
vector<string> string_adj[21];
vector<int> adj[21];
map<string, int> web;

int solution(string word, vector<string> pages) {
    int answer = 0;

    //대문자 -> 소문자
    for (int i = 0; i < word.size(); ++i)
        if ('A' <= word[i] && word[i] <= 'Z') word[i] = word[i] - 'A' + 'a';
    for (int i = 0; i < pages.size(); ++i)
        for (int j = 0; j < pages[i].size(); ++j)
            if ('A' <= pages[i][j] && pages[i][j] <= 'Z') pages[i][j] = pages[i][j] - 'A' + 'a';

    //매핑 + 기본점수 + 외부링크
    for (int i = 0; i < pages.size(); ++i) {
        bool mapping = false;
        for (int j = 0; j < pages[i].size(); ++j) {
            if (!mapping && pages[i][j] == 'm') {
                string cmp = "meta property=\"og:url\" content=";
                bool flag = true;
                for (int k = j, l = 0; l < cmp.size(); ++k, ++l)
                    if (pages[i][k] != cmp[l]) { flag = false; break; }
                if (flag) {
                    string ret = "";
                    int cur = j + 32;
                    while (pages[i][cur] != '>')
                        ret += pages[i][cur++];
                    ret.pop_back();
                    web[ret] = i + 1;
                    j = cur;
                    mapping = true;
                }
            }
            if (pages[i][j] == word[0]) {
                bool flag = true;
                if ('a' <= pages[i][j - 1] && pages[i][j - 1] <= 'z') {
                    if (!(pages[i][j - 2] == '/' && pages[i][j - 1] == 'n'))
                        continue;
                }
                for (int k = j, l = 0; l < word.size(); ++k, ++l)
                    if (pages[i][k] != word[l]) { flag = false; break; }
                if ('a' <= pages[i][j + word.size()] && pages[i][j + word.size()] <= 'z') continue;
                if (flag) {
                    j += word.size() - 1;
                    ++score[i + 1];
                }
            }
            if (pages[i][j] == 'a') {
                string cmp = "a href";
                bool flag = true;
                for (int k = j, l = 0; l < cmp.size(); ++k, ++l)
                    if (pages[i][k] != cmp[l]) { flag = false; break; }
                if (flag) {
                    string link = "";
                    int cur = j + 8;
                    while (pages[i][cur] != '>')
                        link += pages[i][cur++];
                    string_adj[i + 1].push_back(link);
                    j = cur;
                }
            }
        }
    }

    for (int i = 1; i <= pages.size(); ++i)
        for (string& next : string_adj[i])
            adj[i].push_back(web[next]);

    for (int i = 1; i <= pages.size(); ++i)
        result[i] += score[i];

    for (int i = 1; i <= pages.size(); ++i) {
        for (int& next : adj[i]) {
            result[next] += score[i] / (double)adj[i].size();
        }
    }

    double maxx = -1.0;
    for (int i = 1; i <= pages.size(); ++i) {
        if (maxx < result[i]) {
            maxx = result[i];
            answer = i - 1;
        }
    }

    return answer;
}