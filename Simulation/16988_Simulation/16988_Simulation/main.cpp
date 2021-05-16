//
//  main.cpp
//  16988_Simulation
//
//  Created by 홍진석 on 2021/05/16.
//

#include <iostream>
#include <queue>
// Baduk2 - 양 선수가 돌을 2개씩 둔다.
// 상하좌우 인접한 같은 돌의 집합을 그룹이라 한다.
// 어느 그룹이 빈틈없이 에워싸여있다 - 그룹 내에 빈 칸과 인접해있는 돌이 하나도 없다.
// Baduk2에서는 모든 비어있는 칸에 돌을 둘 수 있다.

// 현재 판 위에 돌 2개를 두어 상대 돌을 최대한 많이 죽이게끔 하는 프로그램

// 입력
// N M 행렬 3~20
// 배열, 0 : 빈칸, 1 : 나의 돌, 2 : 상대의 돌

using namespace std;

int N,M;
int arr[21][21];
int check[21][21];
bool caseCheck[21][21];

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

vector<pair<int, vector<pair<int, int>>>> pq;
vector<pair<int, int>> caseXY;


void solution(int sx, int sy){
    
    queue<pair<int, int>> q;
    vector<pair<int, int>> needXY;
    bool zeroCheck[21][21];
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            zeroCheck[i][j] = false;
        }
    }
    int groupCnt = 1;
    int needCnt = 0;
    
    check[sx][sy] = 1;
    q.push(make_pair(sx, sy));
    
    while(!q.empty()){
        
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if(nx >=0 && ny >=0 && nx <N && ny <M){
                if(arr[nx][ny] == 2 && !check[nx][ny]){
                    check[nx][ny] = 1;
                    q.push(make_pair(nx, ny));
                    groupCnt ++;
                }
                else if(arr[nx][ny] == 0 && !zeroCheck[nx][ny]){
                    needXY.push_back(make_pair(nx, ny));
                    needCnt++;
                    zeroCheck[nx][ny] = true;
                }
            }
        }
    }
    if(needCnt <=2 && needCnt >0){
        pq.push_back(make_pair(groupCnt, needXY));
        for(int j=0; j<needXY.size(); j++){
            if(!caseCheck[needXY[j].first][needXY[j].second]){
                caseCheck[needXY[j].first][needXY[j].second] = true;
                caseXY.push_back(make_pair(needXY[j].first, needXY[j].second));
            }
        }
    }
}

int main() {
    cin >> N >> M;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j] == 2 && !check[i][j]){
                //그룹 주변 탐색
                solution(i,j);
            }
        }
    }
    
//    for(int i=0; i<pq.size(); i++){
//        cout << pq[i].first << endl;
//        for(int j=0; j<pq[i].second.size(); j++){
//            cout << "[" << pq[i].second.at(j).first << "," << pq[i].second.at(j).second << "] ";
//        }
//        cout << endl;
//    }
//    cout << "case "<<caseXY.size() << endl;
//    cout<< endl;
//
    int maxValue = 0;
    if (caseXY.size() == 1){
        for(int i=0; i<caseXY.size(); i++){
            //cout << i << " " << j << endl;
            int sum = 0;
            for(int k =0; k<pq.size(); k++){
                int c = 0;
                for(int l =0; l<pq[k].second.size(); l++){
                    if(pq[k].second.at(l).first == caseXY[i].first && pq[k].second.at(l).second == caseXY[i].second){
                        c++;
                    }
                }
                if(c == pq[k].second.size()){
                    sum += pq[k].first;
                }
            }
            if(maxValue < sum){
                maxValue = sum;
            }
        }
    }
    else if(caseXY.size() == 0){
        maxValue = 0;
    }
    else{
        for(int i=0; i<caseXY.size(); i++){
            for(int j=i+1; j<caseXY.size(); j++){
                //cout << i << " " << j << endl;
                int sum = 0;
                for(int k =0; k<pq.size(); k++){
                    int c = 0;
                    for(int l =0; l<pq[k].second.size(); l++){
                        if(pq[k].second.at(l).first == caseXY[i].first && pq[k].second.at(l).second == caseXY[i].second){
                            c++;
                        }
                        else if(pq[k].second.at(l).first == caseXY[j].first && pq[k].second.at(l).second == caseXY[j].second){
                            c++;
                        }
                    }
                    if(c == pq[k].second.size()){
                        sum += pq[k].first;
                    }
                }
                if(maxValue < sum){
                    maxValue = sum;
                }
            }
        }
    }
    
    cout << maxValue;
    
    return 0;
}
