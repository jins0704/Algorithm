//
//  main.cpp
//  18809_Simulation
//
//  Created by 홍진석 on 2021/05/10.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N,M,G,R,a;
int area[101][101];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int maxValue;
vector<pair<int, int>> yellowArea;

void play(bool checkGreen[],vector<int> seedArea){
    int copyArea[101][101];
    bool checkArea[101][101];
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            copyArea[i][j] = area[i][j];
            checkArea[i][j] = false;
        }
    }
    queue<pair<int, int>> seed;

    for(int i=0; i<seedArea.size(); i++){
        int yellowIndex = seedArea.at(i);
        
        if(checkGreen[i]){
            copyArea[yellowArea.at(yellowIndex).first][yellowArea.at(yellowIndex).second] = 3;
            seed.push(make_pair(yellowArea.at(yellowIndex).first, yellowArea.at(yellowIndex).second));
        }
        else{
            copyArea[yellowArea.at(yellowIndex).first][yellowArea.at(yellowIndex).second] = 4;
            seed.push(make_pair(yellowArea.at(yellowIndex).first, yellowArea.at(yellowIndex).second));
        }
    }
    //그린은 3, 레드는 4로 배열에 초기화 완료, 큐에도 전부 집어넣음
    int time = 0;
    int flower = 0;
    while(!seed.empty()){
        int seedSize = (int)seed.size();
        vector<pair<pair<int,int>,int>> changingSeed;
        
        for(int i=0; i<seedSize; i++){//각 시간대 씨앗 퍼진다
            int cx = seed.front().first;
            int cy = seed.front().second;
            checkArea[cx][cy] = true;
            seed.pop();
            
            for(int j =0; j<4; j++){
                int nx = cx + dx[j];
                int ny = cy + dy[j];
                
                if(nx >=0 && ny >=0 && nx <N && ny <M && !checkArea[nx][ny]){

                    if(copyArea[nx][ny] == 1 || copyArea[nx][ny] == 2){ //퍼진다.
                        copyArea[nx][ny] = copyArea[cx][cy];
                        changingSeed.push_back(make_pair(make_pair(nx, ny),0));
                    }
                    else if(copyArea[cx][cy] != copyArea[nx][ny] && (copyArea[nx][ny] == 3 || copyArea[nx][ny] == 4)){
                        for(int k =0; k<changingSeed.size(); k++){
                            if(changingSeed.at(k).first.first == nx && changingSeed.at(k).first.second == ny){
                                changingSeed.at(k).second = 1;
                            }
                        }
                    }
                }
            }
        }
        for(int i =0; i< changingSeed.size(); i++){
            checkArea[changingSeed.at(i).first.first][changingSeed.at(i).first.second] = true;
            if(changingSeed.at(i).second == 1){
                copyArea[changingSeed.at(i).first.first][changingSeed.at(i).first.second] = 5;
                flower++;
            }
            else{
                seed.push(make_pair(changingSeed.at(i).first.first, changingSeed.at(i).first.second));
            }
        }
            
        time ++;
    }

    if(maxValue < flower){
        maxValue = flower;
    }
}
void pickGreenRed(int greenCnt, vector<int> seedArea, vector<int> greenArea){
    if(greenCnt == 0){
        //greenArea에는 seedArea의 인덱스가 들어있습니다.
        //seedArea에는 yellowArea의 인덱스가 들어있습니다.
        bool checkGreen[10];
        for(int j=0; j<10; j++){checkGreen[j] = false;}
        
        for(int j = 0; j< greenArea.size(); j++){
            int seedIndex = greenArea[j];
            checkGreen[seedIndex] = true;
        }
        
        play(checkGreen,seedArea);
    
    }
    else{
        int smallest = greenArea.empty() ? 0 : greenArea.back() + 1;
        
        for(int i=smallest; i<seedArea.size(); i++){
            greenArea.push_back(i);
            pickGreenRed(greenCnt-1, seedArea, greenArea);
            greenArea.pop_back();
        }
    }
}
void pick(int seedNum, vector<int> seedArea){
    if(seedNum == 0){
        
        //각 인덱스가 yellowArea에서 뽑힐 인덱스 저장
        vector<int> greenArea;
        pickGreenRed(G, seedArea, greenArea);
    }
    else{
        int smallest = seedArea.empty() ? 0 : seedArea.back() + 1;
        
        for(int i=smallest; i<yellowArea.size(); i++){
            seedArea.push_back(i);
            pick(seedNum-1, seedArea);
            seedArea.pop_back();
        }
    }
}

int main() {
    
    cin >> N >> M >> G >> R;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> a;
            area[i][j] = a;
            if(a == 2){yellowArea.push_back(make_pair(i, j));}
        }
    }
    
    vector<int> seedArea; //황색 토양 인덱스로 받을거임
    
    pick(G+R, seedArea);
    cout << maxValue;
    return 0;
}
