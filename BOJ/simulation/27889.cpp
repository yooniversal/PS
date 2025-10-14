#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

int main() {
    FASTIO;

    string s; cin >> s;

    if (s == "NLCS") cout << "North London Collegiate School" << '\n';
    else if (s == "BHA") cout << "Branksome Hall Asia" << '\n';
    else if (s == "KIS") cout << "Korea International School" << '\n';
    else cout << "St. Johnsbury Academy" << '\n';

    return 0;
}