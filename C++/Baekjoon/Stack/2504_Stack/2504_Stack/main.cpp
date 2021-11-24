//
//  main.cpp
//  2504_Stack
//
//  Created by 홍진석 on 2021/08/10.
//

#include <iostream>
#include <vector>
#include <stack>
#include <map>
#define FOR(i,n) for(int i=0; i<(n); i++)
using namespace std;

int solution(string s){
    stack<pair<char,bool>> st;
    vector<int> values;
    int answer = 0;
    int stackValue = 1;
    
    map<char, pair<char,int>> m;
    m.insert(make_pair('(', make_pair(')', 2)));
    m.insert(make_pair('[', make_pair(']', 3)));
    m.insert(make_pair(')', make_pair('(', 2)));
    m.insert(make_pair(']', make_pair('[', 3)));
    
    FOR(i, s.size()){
        if(st.empty()){
            st.push(make_pair(s[i], true));
            stackValue *= m[s[i]].second;
        }
        else{
            if(s[i] == '(' || s[i] == '['){
                st.top().second = false;
                st.push(make_pair(s[i], true));
                stackValue *= m[s[i]].second;
            }
            else{
                char c = s[i];
                
                if(st.top().first != m[c].first) { return 0; }
                else{
                    bool meaningful = st.top().second;
                    st.pop();
                    if(meaningful){
                        answer += stackValue;
                    }
                    stackValue /= m[c].second;
                }
            }
        }
    }
    if(st.empty()) { return answer; }
    else { return 0; }
}

int main() {
    string s;
    cin >> s;
    
    cout << solution(s);
    return 0;
}

