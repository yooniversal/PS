#include <string>
#include <vector>
#include <iostream>

using namespace std;

int getTime(string a, string b) {
    int s = ((a[0] - '0') * 10 + (a[1] - '0')) * 60 + (a[3] - '0') * 10 + a[4] - '0';
    int e = 0;

    //끝나는 시간 :: 00:00
    if (b[0] == '0' && b[1] == '0' && b[3] == '0' && b[4] == '0')
        if (a[0] == '0' && a[1] == '0' && a[3] == '0' && a[4] == '0')
            return 0;
        else
            e = 24 * 60;
    else
        e = ((b[0] - '0') * 10 + (b[1] - '0')) * 60 + (b[3] - '0') * 10 + (b[4] - '0');

    return e - s;
}

bool chk(vector<string>& original, vector<string>& key) {
    if (original.size() >= key.size()) {
        for (int i = 0; i < original.size() - key.size() + 1; i++) {
            bool ret = true;
            for (int j = 0; j < key.size(); j++) {
                cout << original[i + j] << " " << key[j] << '\n';
                if (original[i + j] != key[j]) {
                    ret = false;
                    break;
                }
            }
            if (ret) return true;
        }
    }
    return false;
}

string solution(string m, vector<string> musicinfos) {
    vector<pair<string, int>> info;
    vector<string> key;
    for (int i = 0; i < m.size(); i++) {
        if (i < m.size() - 1 && ('A' <= m[i] && m[i] <= 'Z') && m[i + 1] == '#') {
            string s = ""; s += m[i]; s += m[i + 1];
            key.push_back(s);
            i++;
        }
        else {
            string s = ""; s += m[i];
            key.push_back(s);
        }
    }

    for (int i = 0; i < musicinfos.size(); i++) {
        int time = getTime(musicinfos[i].substr(0, 5), musicinfos[i].substr(6, 5));
        string title = ""; int melodyStart = -1;
        for (int t = 12; ; t++) {
            if (musicinfos[i][t] == ',') {
                melodyStart = t;
                break;
            }
            title += musicinfos[i][t];
        }

        vector<string> tmp;
        for (int t = melodyStart + 1; t < musicinfos[i].size(); t++) {
            if (i < musicinfos[i].size() - 1 && ('A' <= musicinfos[i][t] && musicinfos[i][t] <= 'Z') && musicinfos[i][t + 1] == '#') {
                string s = ""; s += musicinfos[i][t]; s += musicinfos[i][t + 1];
                tmp.push_back(s);
                t++;
            }
            else {
                string s = ""; s += musicinfos[i][t];
                tmp.push_back(s);
            }
        }

        vector<string> original;
        cout << "time:" << time << '\n';
        int len = tmp.size();
        for (int j = 0; j < time / len; j++)
            for (int k = 0; k < len; k++)
                original.push_back(tmp[k]);
        for (int j = 0; j < time % len; j++)
            original.push_back(tmp[j]);

        cout << "original:";
        for (int a = 0; a < original.size(); a++)
            cout << original[a];
        cout << '\n';


        if (chk(original, key)) {
            if (info.size() == 0)
                info.push_back({ title, original.size() });
            else if (info[0].second < original.size()) {
                info.clear();
                info.push_back({ title, original.size() });
            }
            else if (info[0].second == original.size())
                info.push_back({ title, original.size() });
        }

    }

    if (info.size() == 0) return "(None)";
    else return info[0].first;
}