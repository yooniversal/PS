#include <string>
#include <vector>
#include <iostream>
using namespace std;
typedef long long ll;
const int MAX = 360005;

class SumSeg {
private:
    vector<ll> tree;

    ll update(int start, int end, int node, int index, ll value) {
        if (index < start || end < index) return tree[node];
        if (start == end) return tree[node] += value;
        int mid = (start + end) / 2;
        ll leftValue = update(start, mid, 2 * node, index, value);
        ll rightValue = update(mid + 1, end, 2 * node + 1, index, value);
        return tree[node] = leftValue + rightValue;
    }

    ll _find(int start, int end, int node, int left, int right) {
        if (left > end || right < start) return 0;
        if (left <= start && end <= right) return tree[node];
        int mid = (start + end) / 2;
        return _find(start, mid, 2 * node, left, right) + _find(mid + 1, end, 2 * node + 1, left, right);
    }

public:
    SumSeg() {
        tree.resize(MAX * 4, 0);
    }
    ll update(int idx, ll val) { return update(0, MAX, 1, idx, val); }
    ll find(int l, int r) { return _find(0, MAX, 1, l, r); }
};

ll get_sec(const string& s) {
    return 1LL * 3600 * (stoi(s.substr(0, 2))) + 1LL * 60 * stoi(s.substr(3, 2)) + 1LL * stoi(s.substr(6, 2));
}

vector<int> SE[360005]; //start, end

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    SumSeg Seg;

    for (int i = 0; i < logs.size(); ++i) {
        SE[get_sec(logs[i].substr(0, 8))].push_back(1); //start
        SE[get_sec(logs[i].substr(9, 8))].push_back(-1); //end
    }

    ll END = get_sec(play_time), cur = 0;
    for (ll i = 0; i <= END; ++i) {
        for (auto& v : SE[i]) cur += v;
        Seg.update(i, cur);
    }

    ll mmax = -987654321, TIME = 0;
    END -= get_sec(adv_time);
    for (int i = 0; i <= END; ++i) {
        if (mmax < Seg.find(i, i + get_sec(adv_time) - 1)) {
            mmax = Seg.find(i, i + get_sec(adv_time) - 1);
            TIME = i;
        }
    }

    answer += ((TIME / 3600) / 10 + '0');
    answer += ((TIME / 3600) % 10 + '0');
    answer += ':';
    TIME %= 3600;

    answer += ((TIME / 60) / 10 + '0');
    answer += ((TIME / 60) % 10 + '0');
    answer += ':';
    TIME %= 60;

    answer += (TIME / 10 + '0');
    answer += (TIME % 10 + '0');

    return answer;
}