#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
typedef long long ll;

map<ll, ll> uni;

ll find(ll n) {
    if (uni[n] == 0) return n;
    return uni[n] = find(uni[n]);
}

void make_union(ll a, ll b) {
    ll pa = find(a), pb = find(b);
    if (pa > pb) {
        uni[b] = pa;
    }
    else
        uni[a] = pb;
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    answer.resize(room_number.size(), 0);

    for (int i = 0; i < room_number.size(); ++i) {
        if (find(room_number[i]) == room_number[i]) {
            answer[i] = room_number[i];
            make_union(room_number[i], room_number[i] + 1);
        }
        else {
            answer[i] = find(room_number[i]);
            make_union(find(room_number[i]), find(room_number[i]) + 1);
        }
    }

    return answer;
}