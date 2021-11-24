//
//  main.cpp
//  빛의경로사이클
//
//  Created by 홍진석 on 2021/09/14.
//

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

#define FOR(i,n) for(int i=0; i<(n); i++)

using namespace std;

int check[501][501][4];
//k = 0,1,2,3 보는 방향 오, 왼, 아래, 위

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int sol = 0;

int rotation(int k, char c){
    if(c == 'S'){
        if(k == 0) { return 0; }
        else if( k== 1) { return 1; }
        else if( k== 2) { return 2; }
        else { return 3; }
    }
    else if (c == 'L'){
        if(k == 0) { return 3; }
        else if( k== 1) { return 2; }
        else if( k== 2) { return 0; }
        else { return 1; }
    }
    else { // R인 경우
        if(k == 0) { return 2; }
        else if( k== 1) { return 3; }
        else if( k== 2) { return 1; }
        else { return 0; }
    }
}
void moveLight(vector<string> &grid, int i, int j, int k, int cnt){
    check[i][j][k] = 1; //들어온 것 확인
    k = rotation(k,grid[i][j]); //방향 회전

    if(i+dx[k] < 0){ i = int(grid.size())-1; }
    else if(i+dx[k] >= grid.size()){ i = 0; }
    else{ i = i+dx[k]; } //x옮기기
    
    if(j+dy[k] < 0){ j = int(grid[0].size())-1; }
    else if(j+dy[k] >= grid[0].size()){ j = 0; }
    else{ j = j+dy[k]; } //y옮기기
  
    if(!check[i][j][k]){
        moveLight(grid, i, j, k, cnt+1);
    }
    else{
        sol = cnt;
        return;
    }
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    
    FOR(i, grid.size()){
        FOR(j, grid[i].size()){//각 좌판
            FOR(k,4){
                if(!check[i][j][k]){
                    moveLight(grid,i,j,k,1);
                    answer.push_back(sol);
                    sol = 0;
                }
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}

int main() {
    vector<string> grid = {"R","R"};
    solution(grid);
    return 0;
}
