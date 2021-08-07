//
//  main.cpp
//  단어변환
//
//  Created by 홍진석 on 2021/08/07.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#define FOR(i,n) for(int i=0; i<(n); i++)

using namespace std;

bool canChange(string s, string word){
    int same = 0;
    FOR(i, s.size()){
        if(s[i] == word[i]) { same ++; }
    }
    return same == s.size()-1 ? true : false;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    bool check[51];
    
    FOR(i, words.size()){ check[i] = false; }
    
    queue<string> q;
    q.push(begin);
    
    while (!q.empty()) {
        int qsize = int(q.size());
        
        FOR(i, qsize){
            string s = q.front();
            q.pop();
            
            FOR(j, words.size()){
                if(!check[j] && canChange(s, words[j])){
                    check[j] = true;
                    if(words[j] == target) {return answer + 1; }
                    q.push(words[j]);
                }
            }
        }
        answer ++;
    }
    return 0;
}

int main() {

    vector<string> v;
    v.push_back("hot");
    v.push_back("dot");
    v.push_back("dog");
    v.push_back("lot");
    v.push_back("log");
    v.push_back("cog");
    
    
    cout << solution("hit", "cog", v);
    return 0;
}


//두 단어 : begin, target
//집합 : words

//begin -> target 변환 가장 짧은 과정
//한번에 한개의 알파벳만 바꾼다.
//words에 있는 단어로만 변환한다.


