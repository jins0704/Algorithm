//
//  main.cpp
//  피로도
//
//  Created by 홍진석 on 2021/11/17.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;
int ans = 0;

void checkDungeons(vector<int> &v, vector<vector<int>> &dungeons, int k){
    int piro = k;
    int cnt = 0;
    for(auto i : v){
        int least = dungeons[i][0];
        int consume = dungeons[i][1];
        
        if(piro < least) { break; }
        piro -= consume;
        cnt ++;
    }
    ans = max(cnt, ans);
}

void makePermutation(int size, vector<int> &v, vector<bool> &check, vector<vector<int>> &dungeons, int k){
    if(size == v.size()){
        checkDungeons(v, dungeons, k);
    }
    
    else{
        for(int i=0; i<size; i++){
            if(!check[i]){
                v.push_back(i);
                check[i] = true;
                makePermutation(size, v, check, dungeons, k);
                v.pop_back();
                check[i] = false;
            }
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    vector<bool> check(dungeons.size(),false);
    vector<int> v;
    
    makePermutation(int(dungeons.size()), v, check, dungeons, k);
    
    return ans;
}
int main() {
    vector<vector<int>> dungeons = {{80,20},{50,40},{30,10}};
    cout << solution(80, dungeons);
    return 0;
}
