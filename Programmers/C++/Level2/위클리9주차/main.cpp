//
//  main.cpp
//  위클리9주차
//
//  Created by 홍진석 on 2021/10/07.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void dfs(vector<vector<int>> &wire, vector<int> &sum, int child, int parent){
    bool leaf = true;
    for(int i=0; i<wire[child].size(); i++){
        if(wire[child][i] != parent){
            leaf = false;
            dfs(wire,sum,wire[child][i],child);
        }
    }
    
    if(parent != child){ sum[parent] += sum[child]; }
    
}
int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    vector<int> sum(n+1,1);
    vector<vector<int>> wire(n+1);
 
    for(int i=0; i<wires.size(); i++){
        wire[wires[i][0]].push_back(wires[i][1]);
        wire[wires[i][1]].push_back(wires[i][0]);
    }

    dfs(wire,sum,1,1);
    
    for(int i=1; i<sum.size(); i++){
        int a = abs(n-sum[i]);
        int b= n-a;
        answer = answer > abs(a-b) ? abs(a-b) : answer;
    }
    return answer;
}

int main(int argc, const char * argv[]) {
    //vector<vector<int>> wires = {{1,3},{2,3},{3,4},{4,5},{4,6},{4,7},{7,8},{7,9}};
    vector<vector<int>> wires = {{1,2},{2,3},{3,4}};
    cout << solution(4, wires);
    return 0;
}
