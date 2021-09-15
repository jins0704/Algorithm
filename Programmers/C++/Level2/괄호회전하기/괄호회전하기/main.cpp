//
//  main.cpp
//  괄호회전하기
//
//  Created by 홍진석 on 2021/09/15.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stack>
#define FOR(i,n) for(int i=0; i<n; i++)

using namespace std;

void setMap(map<char,char> &m){
    m.insert(make_pair('{', '}'));
    m.insert(make_pair('[', ']'));
    m.insert(make_pair('(', ')'));
    m.insert(make_pair('}', '{'));
    m.insert(make_pair(']', '['));
    m.insert(make_pair(')', '('));
}

int solution(string s) {
    map<char, char> m;
    setMap(m);
    
    int answer = 0;
    
    FOR(i, s.size()){
        stack<char> st;
        FOR(i, s.size()){
            if(s[i] == '{' || s[i] == '(' || s[i] == '['){
                st.push(s[i]);
            }
            
            else{
                if(st.empty()) {
                    st.push(s[i]);
                    break; }
                else{
                    if(m[s[i]] == st.top()){ st.pop(); }
                    else{
                        s.push_back(s[i]);
                        break;
                    }
                }
            }
        }
        if(st.empty()) { answer ++;}
        char temp = s.front();
        s = s.substr(1,-1);
        s += temp;
    }
    
    return answer;
}

int main() {

    cout << solution("[](){}");
    return 0;
}
