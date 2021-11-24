//
//  main.cpp
//  쿼드압축후세기
//
//  Created by 홍진석 on 2021/09/17.
//

#include <iostream>
#include <string>
#include <vector>
#define FOR(i,n) for(int i=0; i<n; i++)

using namespace std;
int oneCnt = 0;
int zeroCnt = 0;
void checkSquare(vector<vector<int>> &arr, int squareSize, int sx, int sy){
    int n = arr[sx][sy];
    bool poss = true;
    
    for(int i= sx; i < sx+squareSize; i++){
        for(int j= sy; j< sy+squareSize; j++){
            if(arr[i][j] != n){ poss = false; }
        }
        if(!poss){ break; }
    }
    
    if(poss) {
        if(n == 1) { oneCnt++; }
        else { zeroCnt++; }
    }
    else{
        checkSquare(arr, squareSize/2, sx, sy);
        checkSquare(arr, squareSize/2, sx+squareSize/2, sy);
        checkSquare(arr, squareSize/2, sx, sy+squareSize/2);
        checkSquare(arr, squareSize/2, sx+squareSize/2, sy+squareSize/2);
    }
}
vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;

    checkSquare(arr, int(arr.size()), 0, 0);
    
    answer.push_back(zeroCnt);
    answer.push_back(oneCnt);
    
    return answer;
}

int main() {
    vector<vector<int>> arr = {{1,1,1,1,1,1,1,1},{0,1,1,1,1,1,1,1},{0,0,0,0,1,1,1,1},{0,1,0,0,1,1,1,1},{0,0,0,0,0,0,1,1},{0,0,0,0,0,0,0,1},{0,0,0,0,1,0,0,1},{0,0,0,0,1,1,1,1}};
    solution(arr);
    return 0;
}

//특정 영역 s
//s 내부가 모두 같은 값이라면 수 하나로 압축
//아니라면 4개의 균일한 정사각형 영역으로 쪼갠뒤 각 정사각형에 대해 같은 압축 방식 시도


