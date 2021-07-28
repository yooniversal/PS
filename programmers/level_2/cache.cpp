#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct data {
    string s;
    int cnt;
    data(string s, int cnt = 0) : s(s), cnt(cnt) {}
};

vector<data> cache;

void tolow(string& s) {
    for (int i = 0; i < s.size(); i++)
        if ('A' <= s[i] && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
}

bool exist(string s) {
    for (int i = 0; i < cache.size(); i++)
        if (cache[i].s == s) {
            cache[i].cnt++;
            data d = cache[i];

            bool after = false;
            for (int j = 0; j < cache.size(); j++) {
                if (after) cache[j - 1] = cache[j];
                else if (j == i) after = true;
            }
            cache[cache.size() - 1] = d;

            return true;
        }

    return false;
}

void LRU(string s) {
    int MIN = 0;

    bool after = false;
    for (int i = 0; i < cache.size(); i++) {
        if (after) cache[i - 1] = cache[i];
        else if (i == MIN) after = true;
    }
    cache[cache.size() - 1] = data(s);

}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;

    //모두 소문자로 변경
    for (int i = 0; i < cities.size(); i++)
        tolow(cities[i]);

    for (int i = 0; i < cities.size(); i++) {
        //cache hit
        if (exist(cities[i])) answer++;
        //cache miss
        else {
            answer += 5;
            if (cache.size() < cacheSize)
                cache.push_back(data(cities[i]));
            else if (cacheSize) {
                LRU(cities[i]);
            }
        }
    }

    return answer;
}