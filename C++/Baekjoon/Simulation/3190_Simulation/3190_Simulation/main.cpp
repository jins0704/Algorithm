//
//  main.cpp
//  3190_Simulation
//
//  Created by 홍진석 on 2021/05/02.
//

#include <iostream>
#include <queue>
using namespace std;

int N,K,L;
int a,b,c;
char d;
queue<pair<int, char>> moveInfo;
queue<pair<int, int>> snake;
//앞왼뒤오 순으로 정리
int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};

int arr[101][101];

//0,1,2,3
//뱀몸이면 2, 빈칸이면 0, 사과 있으면 1
void start(int startX, int startY){
    int currentX = startX;
    int currentY = startY; // 현재 머리 위치
    snake.push(make_pair(startX, startY));
    arr[currentX][currentY]= 2;
    int dc = 0;//현재 앞방향
    int currentTime = 0;//현재 시간
    bool finish = false;

    while(!finish){
        int nextTime = 0;
        char nextDirection = 'a';
        if(!moveInfo.empty()){
            nextTime = moveInfo.front().first;
            nextDirection = moveInfo.front().second;
            moveInfo.pop();
        }
        else{
            nextTime = 12345678;
        }
        
        while(currentTime < nextTime){//다음 명령시 까지

            currentX += dx[dc];
            currentY += dy[dc]; //머리 위치 이동
            
            currentTime ++;
    
            if(currentX < N && currentY < N && currentX >=0 &&currentY >=0 && arr[currentX][currentY] !=2){
                if(arr[currentX][currentY] == 0){
                    arr[snake.front().first][snake.front().second] = 0;
                    snake.pop();
                }
                snake.push(make_pair(currentX, currentY));
                arr[currentX][currentY] = 2; //앞으로 한칸이동
                
            }
            else{
                cout << currentTime << endl;
                finish = true;
                break;
            }
        }
        if(nextDirection == 'L'){
            dc += 1;
            if(dc >=4){
                dc = 0;
            }
        }else{
            dc += -1;
            if(dc < 0){
                dc = 3;
            }
        }
        
    }
}

int main() {
    cin >> N; //NxN
    cin >> K; //사과 갯수
    
    for(int i=0; i<K; i++){
        cin >> a >> b;
        arr[a-1][b-1] = 1;
    }//사과 위치 : 1
    cin >> L; //뱀의 변환 횟수
    for(int i=0; i<L; i++){
        cin >> c >> d;
        moveInfo.push(make_pair(c, d)); //queue에 변환 정보 넣기
    }
    
    start(0,0);
    
    return 0;
}
