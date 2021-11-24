//
//  main.cpp
//  1593_문자해독
//
//  Created by 홍진석 on 2021/10/07.
//

#include <iostream>
#include <map>
#include <vector>

using namespace std;

string S,W;
int g,s;

int main() {
    cin >> g >> s;
    cin >> W;
    cin >> S;
    int answer = 0;
    map<char,int> m;
    
    for(int i=0; i<W.size(); i++){
        if(m.find(W[i]) == m.end()){
            m.insert(make_pair(W[i], 1));
        }
        else{ m[W[i]] ++; }
    }
    
    map<char,int> newMap;
    
    for(int i=0; i<g; i++){
        if(newMap.find(S[i]) == newMap.end()){
            newMap.insert(make_pair(S[i], 1));
        }
        else{ newMap[S[i]] ++; }
    }
    if(newMap == m) { answer ++; }
    
    int idx = 0;
    
    for(int i = g; i< S.size(); i++){
        newMap[S[idx]] --;
        if(newMap[S[idx]] <= 0) { newMap.erase(S[idx]); }
        
        if(newMap.find(S[i]) == newMap.end()){ newMap.insert(make_pair(S[i], 1)); }
        else{ newMap[S[i]] ++; }
        
        if(newMap == m) { answer ++; }
        idx++;
    }
    
    cout << answer;
    return 0;
}
