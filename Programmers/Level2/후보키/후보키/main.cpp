//
//  main.cpp
//  후보키
//
//  Created by 홍진석 on 2021/07/21.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
int sol;
vector<vector<int>> keys;

void checkKey(vector<int> &v, vector<vector<string>> &relation){
    set<string> s;
    for(int j=0; j<relation.size(); j++){
        string newkey = "";
        for(int i=0; i<v.size(); i++){
            newkey += relation[j][v[i]];
        }
        if(s.find(newkey) == s.end()){
            s.insert(newkey);
        }
        else{
            return;
        }
    }
    keys.push_back(v);
    sol++;
}

void dfs(int cnt, int size, vector<vector<string>> &relation, vector<int> &v){
    if(cnt == size){
        set<int> key;
        for(int i=0; i<v.size(); i++){
            key.insert(v[i]);
        }
        
        bool leastOK = true;
        for(int i=0; i<keys.size(); i++){
            int count = 0;
            for(int j = 0; j<keys[i].size(); j++){
                if(key.find(keys[i][j]) != key.end()){count ++;}
            }
            if(count == keys[i].size()){leastOK = false;}
        }

        if(leastOK){
            checkKey(v, relation);
        }
    }
    else{
        for(int i=0; i< int(relation[0].size()); i++){
            if(v.empty()){
                v.push_back(i);
                dfs(cnt+1, size, relation, v);
                v.pop_back();
            }
            else{
                if(v.back() < i){
                    v.push_back(i);
                    dfs(cnt+1, size, relation, v);
                    v.pop_back();
                }
            }
        }
    }
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    int attributeCnt = int(relation[0].size()); //attribute 개수
    vector<int> v;
    
    for(int i=1; i<=attributeCnt; i++){
        //후보키 개수
        dfs(0,i,relation,v);
    }
    answer = sol;
    cout << sol;
    return answer;
}
