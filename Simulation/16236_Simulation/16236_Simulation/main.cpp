//
//  main.cpp
//  16236_Simulation
//
//  Created by 홍진석 on 2021/05/03.
//

#include <iostream>
#include <queue>
using namespace std;

//자신보다 큰 물고기가 있으면 못지나감.
//크기가 더 작은 물고기만 먹을 수 있다.
//크기가 같으면 못 먹지만 지나갈 수는 있다.

//더이상 먹을 수 있는 물고기가 없다면 엄마 상어에게 도움요청
//먹을 수 있는 물고기가 1마리라면 먹으러 간다
//몇초동안 도움없이 물고기를 먹을 수 있는지 구하시오

//0: 빈칸
//9 아기상어 위치

struct cmp{
    bool operator()(pair<int,int> &x, pair<int,int> &y){
        if(x.first == y.first){
            return x.second > y.second;
        }
        else{
            return x.first > y.first;
        }
    }
};

priority_queue<pair<int, int>,vector<pair<int, int>>,cmp> q;

int N, fishCnt,n;
int sharkSize = 2; //처음 아기상어 크기 : 2
int area[21][21]; //한칸에는 최대 한마리
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};//1초에 상하좌우로 이동
bool check[21][21];
int totalTime;

void start(){
    int exp = 0; //먹은 수
    bool finish = false;
    int subtime =0;
    
    int startx = q.top().first;
    int starty = q.top().second;
    int cc = 0;
    while(1){

        if(!finish){
            subtime++; //1초 증가
            cc++;
        }
        unsigned long qsize = q.size();
        if(cc >=600){
            break;
        }
        bool newStart = false;
        
        queue<pair<int, int>> tempQ;
        priority_queue<pair<int, int>,vector<pair<int, int>>,cmp> findFish;
        
        for(unsigned w = 0; w<qsize; w++){
            if(newStart){
                break;
            }
            
            int cx = q.top().first;
            int cy = q.top().second;;
            q.pop();
            
            check[cx][cy] = true;
            
            
            for(int i=0; i<4; i++){
                int nx = cx + dx[i];
                int ny = cy + dy[i]; //거리가 같다면 1순위 : 가장 위, 2 순위 가장 왼쪽 물고기 먹는다.
                //cout << cx <<" " << cy << " " << "    " <<nx << " " << ny << endl;
          
                if(nx >=0 && ny >=0 && nx <N && ny <N){//기본조건
                  
                    if(area[nx][ny]<sharkSize && area[nx][ny] >= 1 && area[nx][ny]<=6){//먹을 수 있을 때
                        findFish.push(make_pair(nx, ny));
                    }
                    else if(area[nx][ny] == sharkSize || area[nx][ny] == 0 ){
                        if(!check[nx][ny]){ //지나갈 수 있을 때
                            tempQ.push(make_pair(nx, ny));
                            check[nx][ny] = true;
                        }
                    }
                }
            }
        
        }
        while (!tempQ.empty()) {
            q.push(make_pair(tempQ.front().first, tempQ.front().second));
            tempQ.pop();
        }
        
        if(!findFish.empty()){
            int sx = findFish.top().first;
            int sy = findFish.top().second;
            area[sx][sy] = 9;
            area[startx][starty] = 0;
            startx = sx;
            starty = sy;
            exp++;
            fishCnt--;
            newStart = true;
            totalTime += subtime;
            subtime = 0;
            
            if(fishCnt == 0){
                finish = true;
                return;
            }
            if(exp == sharkSize){
                sharkSize++;
                exp = 0; //자신의 크기와 같은 수의 물고기를 먹을 때마다 크기 1 증가
            }
            while(!q.empty()){
                q.pop(); //큐 초기화
            }
            while(!tempQ.empty()){
                tempQ.pop();
            }
            
            for(int r = 0; r < N; r++){
                for(int t =0; t<N; t++){
                    check[r][t] = false; //왔던길 확인 취소
                }
            }
            cc = 0;
            q.push(make_pair(sx, sy)); //새로 시작
            //out << sx << " " << sy << "에서 시작 " << totalTime << " 경과 "<<endl;
        }
    }
    
}

int main() {
    
    cin >> N;
    //NxN 크기에 물고기 M마리 상어 1마리
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> n;
            area[i][j] = n;
            if(n>=1 && n<=6){//1,2,3,4,5,6 : 물고기 크기
                fishCnt++;
            }
            else if(n==9){
                q.push(make_pair(i, j));
            }
        }
    }
    
    start(); //지나가야하는 칸의 개수는 최솟값 BFS로 하자
    
    cout <<totalTime;
    return 0;
}
