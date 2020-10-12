#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>
using namespace std;

deque<int> wait[11];

int toMin(string& s) {
    return ((s[0] - '0') * 10 + (s[1] - '0')) * 60 + (s[3] - '0') * 10 + (s[4] - '0');
}

string toHM(int t) {
    string ret;
    int h = t / 60;
    int m = t % 60;

    if (h == 0) ret += "00:";
    else if (h != 0 && h < 10) {
        ret += '0';
        ret += h + '0';
        ret += ':';
    }
    else ret += to_string(h) + ':';

    if (m == 0) ret += "00";
    else if (m < 10) {
        ret += '0';
        ret += m + '0';
    }
    else ret += to_string(m);

    return ret;
}

string solution(int n, int t, int m, vector<string> timetable) {
    vector<int> bus;
    int start = 540 - t; //9*60 - t
    for (int i = 0; i < n; ++i) {
        start += t;
        bus.push_back(start);
    }

    vector<int> person;
    for (int i = 0; i < timetable.size(); ++i)
        person.push_back(toMin(timetable[i]));
    sort(person.begin(), person.end());


    int pbus = 0;
    for (int i = 0; i < person.size(); ++i)
        if (person[i] <= bus[pbus]) wait[pbus].push_back(person[i]);
        else {
            if (pbus == bus.size() - 1) break;
            bool fin = false;
            while (person[i] > bus[++pbus])
                if (pbus == bus.size() - 1) {
                    fin = true;
                    break;
                }
            if (fin) break;
            wait[pbus].push_back(person[i]);
        }

    for (int i = 0; i < n - 1; ++i)
        if (wait[i].size() > m) {
            for (int j = 0; j < m; ++j) wait[i].pop_front();
            while (!wait[i].empty()) {
                wait[i + 1].push_front(wait[i].back());
                wait[i].pop_back();
            }
        }

    if (wait[n - 1].size() < m) {
        return toHM(bus[n - 1]);
    }
    else {
        vector<int> cur;
        while (!wait[n - 1].empty()) {
            cur.push_back(wait[n - 1].front());
            wait[n - 1].pop_front();
        }
        return toHM(cur[m - 1] - 1);
    }
}