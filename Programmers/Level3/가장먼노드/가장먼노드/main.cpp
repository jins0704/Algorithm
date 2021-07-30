//
//  main.cpp
//  가장먼노드
//
//  Created by 홍진석 on 2021/07/30.
//

#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    bool check[20001] = {0,};
    vector<int> arr[20001];
    
    for(int i=0; i<edge.size(); i++){
        arr[edge[i].at(0)].push_back(edge[i].at(1));
        arr[edge[i].at(1)].push_back(edge[i].at(0));
    }
    queue<int> q;
    q.push(1);
    
    while(!q.empty()){
        int qsize = int(q.size());
        int moveCnt = 0;
        for(int i=0; i<qsize; i++){
            int cPoint = q.front();
            check[cPoint] = true;
            q.pop();
            
            for(int i=0; i<arr[cPoint].size(); i++){
                if(!check[arr[cPoint][i]]){
                    moveCnt++;
                    if(moveCnt > 0){answer = moveCnt;}
                    q.push(arr[cPoint][i]);
                    check[arr[cPoint][i]] = true;
                }
            }
        }
    }
    return answer;
}

int main() {
    return 0;
}
