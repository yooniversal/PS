#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <iostream>
using namespace std;

bool used[27];
bool chk[1001];
bool flag = false;
queue<int> blank;

//first:: -1:invalid 0:초기화 1:규칙2로 점프 2:else
//second:: 이동할 인덱스 
pair<int, int> rule1(string& s, int cur){
	if(cur==0 || cur==s.size()-1) return {2, -1};
	if(chk[cur] || chk[cur-1]) return {2, -1};
	char target = s[cur];
	cout <<"rule1 cur:"<<cur << " target:"<<target<<'\n';
	vector<int> tmp;
	tmp.push_back(cur);
	int B=0, S=0; //연속 대문자 갯수, 연속 소문자 갯수 
	for(int i=cur+1; i<s.size(); ++i){
		if(isupper(s[i])){
			if(isupper(s[i-1])) blank.push(i); 
			++B; S=0; 
		}
		else if(islower(s[i])){
			if(used[target-'a']) return {-1, -1};
			if(target == s[i]){
				if(B>=2 && S==0) return {2, -1}; //규칙 1에 해당되지 않음 : aBBBBa 
				if(S>=1) return {-1, -1}; //소문자가 연속이라면 
				++S; B=0;
				tmp.push_back(i);
			}
			else {
				for(auto& next : tmp) s[next] = '.'; 
				used[target-'a'] = true;
				return {1, i-1};//소문자가 1개일 때 : AbA 
			}
		}
	}
	if(B>0 && S==0){
		for(auto& next : tmp) {
			s[next] = '.';
			chk[next] = true;
		}
	}
	return {2, -1};
}

//-1:invalid 1:pass
int rule2(string& s, int cur){
	if(chk[cur]) return 1;
	char target = s[cur];
	cout << "rule2 cur:"<<cur<<" target:"<<target<<'\n';
	char rule1_CHAR = 'N';
	for(int i=cur+2; i<s.size(); ++i){
		if(islower(s[i])){
			if(used[target-'a']) return -1;
			if(islower(s[i-1])) return -1;
			if(s[i] == target){
				used[target-'a'] = true;
				chk[cur] = chk[i] = true;
				s[cur] = ' ';
				return 1;
			}
			else{
				if(rule1_CHAR == 'N') rule1_CHAR = s[i];
				else if(rule1_CHAR != s[i]) return -1;
			}
		}
	}
	return -1;
}

string solution(string sentence) {
    string answer = "";
    
    memset(used, 0, sizeof(used));
    memset(chk, 0, sizeof(chk));
    while(!blank.empty()) blank.pop();
    flag = false;
    for(int i=0; i<sentence.size(); ++i){
    	//소문자
		if(islower(sentence[i])){
	    	//규칙 1 체크
			if(!flag){
				auto ret1 = rule1(sentence, i);
				if(i==7) cout << "iret:"<<ret1.first << ' ' << ret1.second<<'\n';
				if(ret1.first == -1) return "invalid";
				if(ret1.first == 0){
					i=ret1.second;
					continue;
				}
				else if(ret1.first == 1){
					i=ret1.second;
					flag = true;
					continue;
				}
			}
			//규칙 2 체크
			int ret2 = rule2(sentence, i);
			if(ret2 == -1) return "invalid";
		}
		//대문자
		else if(isupper(sentence[i])){
			if(isupper(sentence[i-1])) blank.push(i);
		} 
		//대소문자 외 ('.' 제외) 
		else if(sentence[i] != '.') return "3invalid"; 
    }
    
    cout << "sentence:"<<sentence<<'\n';
    
    int bidx = 1024; //공백 인덱스
    if(!blank.empty()){
        bidx = blank.front(); blank.pop();
    }
    //cout <<"bidx:"<<bidx<<'\n';
    for(int i=0; i<sentence.size(); ++i){
        if(sentence[i] == '.') continue;
        if(sentence[i] == ' '){
            if(i==0 || i==sentence.size()-1 || sentence[i-1] == ' ') continue;
        }
        if(islower(sentence[i])) continue;
        if(i == bidx) {
            answer += ' ';
            if(!blank.empty()) {bidx=blank.front(); blank.pop();}
        }
        answer += sentence[i];
    }
    
    return answer;
}

int main() {
	vector<string> testcase; 
	testcase.push_back("HaEaLaLaObWORLDb"); //HELLO WORLD //HELLO W O R L D
	testcase.push_back("SpIpGpOpNpGJqOqA"); //SIGONG JOA //SIGONG J O A
	testcase.push_back("A"); //A 
	testcase.push_back("HELLOWORLD"); //HELLOWORLD  //H E L L O W O R L D
	testcase.push_back("aHbEbLbLbOacWdOdRdLdDc"); //HELLO WORLD
	testcase.push_back("HaEaLaLObWORLDb"); //HELL O WORLD //HELL O W O R L D
	testcase.push_back("AAA"); //AAA //A A A
	testcase.push_back("aHELLOWORLDa"); //HELLOWORLD 
	testcase.push_back("AAAaBaAbBBBBbCcBdBdBdBcCeBfBeGgGGjGjGRvRvRvRvRvR"); //AA ABA BBBB C BBBB C BB GG GGG RRRRRR **
	testcase.push_back("aIaAM"); //I AM 
	testcase.push_back("bAaOb"); //AO 
	testcase.push_back("AxAxAxAoBoBoB"); //invalid 
	testcase.push_back("a"); //invalid 
	testcase.push_back("Aa"); //invalid 
	testcase.push_back("aA"); //invalid 
	testcase.push_back("HaEaLaLaOWaOaRaLaD"); //invalid 
	testcase.push_back("abHELLObaWORLD"); //invalid 
	testcase.push_back("aHELLOa bWORLDb"); //invalid 
	testcase.push_back("TxTxTxbAb"); //invalid 
	testcase.push_back("bTxTxTaTxTbkABaCDk"); //invalid 
	testcase.push_back("baHELLOabWORLD"); //invalid 
	testcase.push_back("AxAxAxABcBcBcB"); //AAAA BBBB
	testcase.push_back("A B"); //invalid
	testcase.push_back("oBBoA"); //BB A 
	testcase.push_back("AxAxAxA"); //AAAA 
	testcase.push_back("HaEaLaLaObWORLDbSpIpGpOpNpGJqOqAdGcWcFcDdeGfWfLeoBBoAAAAxAxAxAA"); //HELLO WORLD SIGONG J O A GWFD GWL BB AAA AAAA A
	testcase.push_back("aBcAadDeEdvAvlElmEEEEm"); //BA DE A E EEEE
	testcase.push_back("AcAcABaBaB"); //A A AB B B 
	testcase.push_back("aGbWbFbDakGnWnLk"); //GWFD GWL
	testcase.push_back("aCaCa"); //invalid 
	for (int i = 0; i < testcase.size(); ++i) { cout << '[' << solution(testcase[i]) << ']' << '\n'; }
	return 0; 
}
