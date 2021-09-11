//
//  main.cpp
//  KAKAO_2022Blind_5
//
//  Created by 홍진석 on 2021/09/11.
//

#include <iostream>
#include <string>
#include <vector>
#define FOR(i,n) for(int i=0; i<n; i++)

using namespace std;

vector<int> edge[18];
int check[18];
int maxValue;

void dfs(int cv, int sheep, int wolf, vector<int> &info, vector<vector<int>> &edges){
    int s = sheep;
    int w = wolf;
    if(!check[cv]){
        if(info[cv] == 0){
            s++;
            if(maxValue < s){
                maxValue = s;
            }
        }
        else{ w ++; }
        check[cv]++;
    }
    
    for (int i=0; i<edge[cv].size(); i++) {
        if(!check[edge[cv][i]]){
            cout << cv << "에서" << edge[cv][i] << endl;
            dfs(edge[cv][i], s, w, info, edges);
        }
    }
}
int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    
    FOR(i, edges.size()){
        edge[edges[i][0]].push_back(edges[i][1]);
    }
    if(edge[0].size() == 2){
        edge[edge[0][0]].push_back(edge[0][1]);
        edge[edge[0][1]].push_back(edge[0][0]);
    }
    
    dfs(0, 0, 0, info, edges);
    cout << endl;
    cout << maxValue << endl;
    return answer;
}

int main() {
    vector<int> info = {0,0,1,1,1,0,1,0,1,0,1,1};
    vector<vector<int>> edge = {{0,1},{1,2},{1,4},{0,8},{8,7},{9,10},{9,11},{4,3},{6,5},{4,6},{8,9}};
    solution(info, edge);
    return 0;
}
