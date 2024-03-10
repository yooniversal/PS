#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
const int INF = 987654321;
typedef pair<int, int> ii;

string s;
vector<ii> a;
bool chk[105];
set<string> str_set;

void findBrackets() {
    stack<int> st;
    for (int i=0; i<s.size(); i++) {
        if (s[i] == '(') {
            st.push(i);
            continue;
        }
        if (s[i] == ')') {
            int open_idx = st.top(); st.pop();
            a.push_back({open_idx, i});
        }
    }
}

void add_str() {
    string ret = "";
    for (int i=0; i<s.size(); i++) {
        if (chk[i]) continue;
        ret += s[i];
    }
    str_set.insert(ret);
}

void dfs(int cur, int cnt) {
    if (cur >= a.size()) return;

    // cur번째 괄호 제거
    chk[a[cur].first] = true;
    chk[a[cur].second] = true;
    add_str();

    dfs(cur+1, cnt+1);

    // cur번째 괄호 제거X
    chk[a[cur].first] = false;
    chk[a[cur].second] = false;
    if(cnt > 0) add_str();

    dfs(cur+1, cnt);
}

void FASTIO() {
    cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
}

int main() {
    FASTIO();

    cin >> s;
    findBrackets();
    dfs(0, 0);

    set<string>::iterator iter;
    for (iter = str_set.begin(); iter != str_set.end(); iter++) {
        cout << *iter << '\n';
    }
    
    return 0;
}