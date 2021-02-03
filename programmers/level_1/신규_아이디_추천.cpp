#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    for (int i = 0; i < new_id.size(); ++i) {
        if ('A' <= new_id[i] && new_id[i] <= 'Z')
            new_id[i] = new_id[i] - 'A' + 'a';
    }

    string tmp = "";
    for (int i = 0; i < new_id.size(); ++i) {
        if (('a' <= new_id[i] && new_id[i] <= 'z') ||
            ('0' <= new_id[i] && new_id[i] <= '9') ||
            new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')
            tmp += new_id[i];
    }

    string tmp2 = "";
    tmp2 += tmp[0];
    for (int i = 1; i < tmp.size(); ++i) {
        if (tmp2.back() == '.' && tmp[i] == '.') continue;
        tmp2 += tmp[i];
    }

    if (tmp2.back() == '.') tmp2.pop_back();
    if (tmp2[0] == '.') tmp = tmp2.substr(1);
    else tmp = tmp2.substr(0);

    if (tmp.size() == 0) tmp += 'a';
    if (tmp.size() >= 16) tmp = tmp.substr(0, 15);
    if (tmp.back() == '.') tmp.pop_back();
    while (tmp.size() <= 2) {
        tmp += tmp.back();
    }

    return tmp;
}