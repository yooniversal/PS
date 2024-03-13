#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <algorithm>
#include <unordered_set>
using namespace std;

const int TEST_MODE = 0;

int N, M;
unordered_set<string> chk;

void FASTIO() {
    cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
}

void func(const string& s, char delimiter) {
    vector<string> ret;
    
    string tmp_str = "";
    for (int i=0; i<s.size(); i++) {
        if (s[i] == delimiter) {
            ret.push_back(tmp_str);
            tmp_str = "";
            continue;
        }
        tmp_str += s[i];
    }

    if (tmp_str.size() > 0) {
        ret.push_back(tmp_str);
    }

    for (auto& str : ret) {
        if (chk.find(str) == chk.end()) continue;
        chk.erase(str);
        N--;
    }
    cout << N << '\n';
}

int main() {
    FASTIO();
    
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        string s; cin >> s;
        chk.insert(s);
    }

    while (M--) {
        string s; cin >> s;
        func(s, ',');
    }

    return 0;
}