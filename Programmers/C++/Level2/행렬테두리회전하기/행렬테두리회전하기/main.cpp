//
//  main.cpp
//  행렬테두리회전하기
//
//  Created by 홍진석 on 2021/08/08.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int arr[101][101];

int moveQuery(vector<int> &query){
    int startX = query[0]-1; int endX = query[2]-1;
    int startY = query[1]-1; int endY = query[3]-1;
    int minimum = 123456789;
    int temp1 = 0; int temp2 = 0;
    temp1 = arr[startX][startY];
    
    for(int i = startY; i< endY; i++){  //시계 1
        temp2 = arr[startX][i+1];
        arr[startX][i+1] = temp1;
        temp1 = temp2;
        if(temp1 < minimum) { minimum = temp1; }
    }
    
    for(int i = startX; i< endX; i++){ // 시계 2
        temp2 = arr[i+1][endY];
        arr[i+1][endY] = temp1;
        temp1 = temp2;
        if(temp1 < minimum) { minimum = temp1; }
    }

    for(int i = endY-1; i>= startY; i--){ //시계 3
        temp2 = arr[endX][i];
        arr[endX][i] = temp1;
        temp1 = temp2;
        if(temp1 < minimum) { minimum = temp1; }
    }

    for(int i = endX-1; i>= startX; i--){ //시계 4
        temp2 = arr[i][startY];
        arr[i][startY] = temp1;
        temp1 = temp2;
        if(temp1 < minimum) { minimum = temp1; }
    }
    return minimum;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    int cnt = 1;
    for(int i=0; i<rows; i++){
        for(int j =0; j<columns; j++){
            arr[i][j] = cnt++;
        }
    }
    
    for(int i=0; i<queries.size(); i++){
        answer.push_back(moveQuery(queries[i]));
    }

    return answer;
}

int main() {
    vector<int> v1;
    v1.push_back(2);
    v1.push_back(2);
    v1.push_back(5);
    v1.push_back(4);
    
    vector<int> v2;
    v2.push_back(3);
    v2.push_back(3);
    v2.push_back(6);
    v2.push_back(6);
    
    vector<int> v3;
    v3.push_back(5);
    v3.push_back(1);
    v3.push_back(6);
    v3.push_back(3);
    vector<vector<int>> v4;
    v4.push_back(v1);
    v4.push_back(v2);
    v4.push_back(v3);
    solution(6, 6, v4);
    
    return 0;
}

//rows x columns 행렬
//테부리 부분에 있는 숫자들을 시계방향으로 회전
//2,2,5,4 -> 2행 2열 ~ 5행 4열
