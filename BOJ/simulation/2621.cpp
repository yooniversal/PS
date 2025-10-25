#include <bits/stdc++.h>

using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;

const int INF = 987654321;
const int MOD = 1000000007;

bool isStraight(vi& numbers) {
    int prev = numbers[0];
    for (int i=1; i<5; i++) {
        if (numbers[i] != prev + 1) return false;
        prev = numbers[i];
    }
    return true;
}

bool isFlush(vector<char>& types) {
    for (int i=1; i<5; i++) {
        if (types[i] != types[0]) return false;
    }
    return true;
}

int getFourCardScore(vi& numbers) {
    map<int, int> cnt;
    for (auto& n : numbers) cnt[n]++;
    for (auto& n : numbers) {
        if (cnt[n] == 4) return n + 800;
    }
    return -1;
}

int getFullHouseScore(vi& numbers) {
    int threeN = -1, twoN = -1;
    for (int i=0; i<numbers.size();) {
        int cnt = upper_bound(numbers.begin(), numbers.end(), numbers[i])
                - lower_bound(numbers.begin(), numbers.end(), numbers[i]);
        if (cnt == 2) twoN = numbers[i];
        else if (cnt == 3) threeN = numbers[i];
        i += cnt;
    }
    if (twoN == -1 || threeN == -1) return -1;

    return threeN*10 + twoN + 700;
}

int getThreeNumberScore(vi& numbers) {
    int threeN = -1;
    for (int i=0; i<numbers.size(); i++) {
        int cnt = upper_bound(numbers.begin(), numbers.end(), numbers[i])
                - lower_bound(numbers.begin(), numbers.end(), numbers[i]);
        if (cnt == 3) threeN = numbers[i];
    }
    if (threeN == -1) return -1;

    return threeN + 400;
}

int getTwoPairScore(vi& numbers) {
    int ret = 0;
    int twoCnt = 0;
    for (int i=0; i<numbers.size();) {
        int cnt = upper_bound(numbers.begin(), numbers.end(), numbers[i])
                - lower_bound(numbers.begin(), numbers.end(), numbers[i]);
        if (cnt == 2) {
            if (ret == 0) ret += numbers[i];
            else ret += numbers[i]*10;
            twoCnt++;
        }
        i += cnt;
    }
    if (twoCnt != 2) return -1;

    return ret + 300;
}

int getOnePairScore(vi& numbers) {
    int twoN = -1;
    for (int i=0; i<numbers.size(); i++) {
        int cnt = upper_bound(numbers.begin(), numbers.end(), numbers[i])
                - lower_bound(numbers.begin(), numbers.end(), numbers[i]);
        if (cnt == 2) twoN = numbers[i];
    }
    if (twoN == -1) return -1;

    return twoN + 200;
}

int getScore(vector<pair<char, int>> cards, vi& numbers, vector<char>& types) {
    sort(numbers.begin(), numbers.end());

    int fourCardScore = getFourCardScore(numbers);
    int fullHouseScore = getFullHouseScore(numbers);
    int threeNumberScore = getThreeNumberScore(numbers);
    int twoPairScore = getTwoPairScore(numbers);
    int onePairScore = getOnePairScore(numbers);

    if (isStraight(numbers) && isFlush(types)) {
        return numbers[numbers.size()-1] + 900;
    } else if (fourCardScore != -1) {
        return fourCardScore;
    } else if (fullHouseScore != -1) {
        return fullHouseScore;
    } else if (isFlush(types)) {
        return numbers[numbers.size()-1] + 600;
    } else if (isStraight(numbers)) {
        return numbers[numbers.size()-1] + 500;
    } else if (threeNumberScore != -1) {
        return threeNumberScore;
    } else if (twoPairScore != -1) {
        return twoPairScore;
    } else if (onePairScore != -1) {
        return onePairScore;
    }

    return numbers[numbers.size()-1] + 100;
}

int main() {
    FASTIO;

    vector<pair<char, int>> cards(5);
    vector<char> types(5);
    vi numbers(5);
    for (int i=0; i<5; i++) {
        char type; int number; cin >> type >> number;
        types[i] = type;
        numbers[i] = number;
        cards[i] = {type, number};
    }
    
    cout << getScore(cards, numbers, types) << '\n';

    return 0;
}