#include <string>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;

    map<string, string> m;
    vector<pair<char, string>> ret; //command, id
    for (int i = 0; i < record.size(); i++) {
        if (record[i][0] == 'E') {
            string id = "";
            for (int j = 6; ; j++) {
                if (record[i][j] == ' ') break;
                id += record[i][j];
            }
            string name = "";
            for (int j = record[i].size() - 1; ; j--) {
                if (record[i][j] == ' ') break;
                name = record[i][j] + name;
            }
            m[id] = name;
            ret.push_back({ record[i][0], id });
        }
        else if (record[i][0] == 'L') {
            string id = "";
            for (int j = 6; j < record[i].size(); j++) {
                if (record[i][j] == ' ') break;
                id += record[i][j];
            }
            ret.push_back({ record[i][0], id });
        }
        else if (record[i][0] == 'C') {
            string id = "";
            for (int j = 7; ; j++) {
                if (record[i][j] == ' ') break;
                id += record[i][j];
            }
            string name = "";
            for (int j = record[i].size() - 1; ; j--) {
                if (record[i][j] == ' ') break;
                name = record[i][j] + name;
            }
            m[id] = name;
        }
    }

    for (int i = 0; i < ret.size(); i++) {
        if (ret[i].first == 'E')
            answer.push_back(m[ret[i].second] + "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.");
        if (ret[i].first == 'L')
            answer.push_back(m[ret[i].second] + "´ÔÀÌ ³ª°¬½À´Ï´Ù.");
    }

    return answer;
}