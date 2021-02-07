//
//  main.cpp
//  14503_Simulation
//
//  Created by 홍진석 on 2021/02/07.
//

#include <iostream>

using namespace std;
//세로 N, 가로 M 입력 3<= <=50
//지도의 각 칸은 r,c, 빈칸:0, 벽:1
//방향 d, 북:0,동:1,남:2,서:3
//왼쪽방향, 북->서, 동->북, 남->동. 서->남
//뒤방향, 남 서 북 동
//1. 현재 위치를 청소
//2.
//  a. 왼쪽 방향 청소안했으면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번
//  b. 왼쪽 방향에 청소했으면, 그 방향으로 회전하고 2번
//  c. 사방이 청소했던가 벽이면, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번
//  d. 사방이 청소했던가 벽이면, 뒤쪽 방향이 벽이면 작동 종료

int map[51][51];
int N,M;
int r,c,d,cnt;

//서0북1동2남3 순
int X[4] = {0,-1,0,1};
int Y[4] = {-1,0,1,0};
//남서북동
int backX[4] = {1,0,-1,0};
int backY[4] = {0,-1,0,1};


//왼쪽으로 돌기
int rotateLeft(int direction){
    if(direction == 0){ //북
        return 3;   //서
    }
    else if(direction ==1){ //동
        return 0;   //북
    }
    else if(direction ==2){ //남
        return 1;   //동
    }
    else{
        return 2;   //남
    }
}

void clean(int curX, int curY, int direction, int goOne){
    
        //1
        if(goOne==1){
            map[curX][curY] = 2;
            cnt ++;
        }
        
        //2.a
        if(map[curX+X[direction]][curY+Y[direction]]==0){
            //청소안했으면 왼쪽으로 가고 그쪽보기
            curX += X[direction];
            curY += Y[direction];
            
            direction = rotateLeft(direction);
            clean(curX, curY, direction,1);
            return;
        }
        
        int blockcheck = 0;
        
        //2.b
        for(int q = 0; q<4; q++){
            if(map[curX+X[q]][curY+Y[q]] != 0){
                blockcheck ++;
            }
        }
        
        if(blockcheck !=4 && map[curX+X[direction]][curY+Y[direction]]!=0){
            direction = rotateLeft(direction);
            
            clean(curX, curY, direction,0);
            return;
        }
        
        if(blockcheck ==4){
            if(map[curX+backX[direction]][curY+backY[direction]]!=1){
                curX += backX[direction];
                curY += backY[direction];
                
                clean(curX, curY, direction,0);
                return;
            }
            else{
                return;
            }
        }
}
int main() {

    cin >> N >> M;
    cin >> r >> c >> d;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map[i][j];
        }
    }
    
    clean(r,c,d,1);
    
    cout << cnt;
    
    return 0;
}
