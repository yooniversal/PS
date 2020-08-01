#include <string>
#include <vector>
#include <iostream>
#define MAXSIZE 2100000000

using namespace std;

//up-down
int alphabet(char c) {
    if (c > 'N') return ('N' - 'A') - (c - 'N') + 1;
    else return c - 'A' + 1;
}

int right(string name, int start) {
    int ans = 0;
    //첫번째 문자가 A
    if (name[start] == 'A') {
        bool allA = true;
        for (auto& a : name) {
            if (a != 'A') allA = false;
        }
        if (allA) return ans;
    }
    //첫번째 문자가 A가 아님
    else {
        ans += alphabet(name[start]) - 1;
    }

    for (int i = start + 1; i < name.size(); i++) {
        if (name[i] != 'A') ans += alphabet(name[i]);
        else {
            bool fin = true;
            for (int j = i + 1; j < name.size(); j++) {
                if (name[j] != 'A') {
                    ans += alphabet(name[i]);
                    fin = false;
                    break;
                }
            }
            if (fin) {
                for (int j = 0; j < start; j++) {
                    if (name[j] != 'A') {
                        ans += alphabet(name[i]);
                        fin = false;
                        break;
                    }
                }
                if (fin) return ans;
            }
        }
    }

    for (int i = 0; i < start; i++) {
        if (name[i] != 'A') ans += alphabet(name[i]);
        else {
            bool fin = true;
            for (int j = i + 1; j < start; j++) {
                if (name[j] != 'A') {
                    ans += alphabet(name[i]);
                    fin = false;
                    break;
                }
            }
            if (fin) return ans;
        }
    }

    return ans;
}

int left(string name, int start) {
    int ans = 0;
    //Start 문자가 A
    if (name[start] == 'A') {
        bool allA = true;
        for (auto& a : name) {
            if (a != 'A') allA = false;
        }
        if (allA) return ans;
    }
    //Start 문자가 A가 아님
    else {
        ans += alphabet(name[start]) - 1;
    }

    for (int i = start - 1; i >= 0; i--) {
        if (name[i] != 'A') ans += alphabet(name[i]);
        else {
            bool fin = true;
            for (int j = i - 1; j >= 0; j--) {
                if (name[j] != 'A') {
                    ans += alphabet(name[i]);
                    fin = false;
                    break;
                }
            }
            if (fin) {
                for (int j = name.size() - 1; j >= start + 1; j--) {
                    if (name[j] != 'A') {
                        ans += alphabet(name[i]);
                        fin = false;
                        break;
                    }
                }
                if (fin) return ans;
            }
        }
    }

    for (int i = name.size() - 1; i >= start + 1; i--) {
        if (name[i] != 'A') ans += alphabet(name[i]);
        else {
            bool fin = true;
            for (int j = i - 1; j >= start + 1; j--) {
                if (name[j] != 'A') {
                    ans += alphabet(name[i]);
                    fin = false;
                    break;
                }
            }
            if (fin) return ans;
        }
    }

    return ans;
}

int startdis(int start, int size) {
    int mid = size / 2 + 1;
    if (size % 2) {
        if (start <= mid) return start - 1;
        else return (mid - 1) - (start - mid) + 1;
    }
    else {
        if (start <= mid) return start - 1;
        else return (mid - 1) - (start - mid);
    }
}

int solution(string name) {
    int answer = MAXSIZE;
    for (int i = 0; i < name.size(); i++) {
        answer = min(answer, min(right(name, i), left(name, i)) + startdis(i + 1, name.size()));
    }

    return answer;
}