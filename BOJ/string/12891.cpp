#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 1e9;
const int MOD = 1000000007;

int main() {
    FASTIO;

    int n, s; cin >> n >> s;
    string dna; cin >> dna;
    int a, c, g, t; cin >> a >> c >> g >> t;
    int curA=0, curG=0, curC=0, curT=0;

    int ret = 0;

    for (int i=0; i<s; i++) {
        if (dna[i] == 'A') curA++;
        else if (dna[i] == 'G') curG++;
        else if (dna[i] == 'C') curC++;
        else curT++;
    }
    if (curA >= a && curG >= g && curC >= c && curT >= t) ret++;
    
    for (int i=s; i<dna.size(); i++) {
        if (dna[i-s] == 'A') curA--;
        else if (dna[i-s] == 'G') curG--;
        else if (dna[i-s] == 'C') curC--;
        else curT--;

        if (dna[i] == 'A') curA++;
        else if (dna[i] == 'G') curG++;
        else if (dna[i] == 'C') curC++;
        else curT++;

        if (curA >= a && curG >= g && curC >= c && curT >= t) ret++;
    }

    cout << ret << '\n';

    return 0;
}