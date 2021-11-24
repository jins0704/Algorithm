//
//  main.cpp
//  14502_BFS
//
//  Created by 홍진석 on 2021/03/02.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int xx[4] = {-1,1,0,0};
int yy[4] = {0,0,-1,1};
int N,M,n;
int arr[8][8];
int check[8][8];
int zerocnt;
int maxSafeArea;

vector<pair<int, int>> virusStorage;
vector<pair<pair<int, int>, bool>> emptySpace;
queue<pair<int, int>> virus;
vector<pair<int, int>> newWall;

int spreadVirus(int makeVirusNum){
    //바이러스 때 번식할 때마다
    // 0-> 2  로 바꾼 개수
    
    while(!virus.empty()){
        
        unsigned long vsize = virus.size();
        
        for(int q=0; q < vsize; q++){
            
            int cx = virus.front().first;
            int cy = virus.front().second;
            
            virus.pop();
            
            for(int w =0; w<4; w++){
                
                int nx = cx + xx[w];
                int ny = cy + yy[w];
                
                if(nx >=0 && ny >=0 && nx < N && ny < M){
                    if(arr[nx][ny] == 0 && check[nx][ny] == 0){
                        check[nx][ny] = true;
                        makeVirusNum ++;
                        //cout << nx << " " << ny << " 퍼졌다";
                        virus.push(make_pair(nx, ny));
                    }
                }
            }
        }
    }
    
    return makeVirusNum;
}

int main() {
    
    cin >> N >> M;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
           
            cin >> n;
            
            arr[i][j] = n;
    
            if(n == 0){
                // 0인 공간
                emptySpace.push_back(make_pair(make_pair(i, j), false));
                zerocnt ++;
            }
            else if(n == 2){
                //바이러스 2인 공간
                virusStorage.push_back(make_pair(i, j));
            }
            else{
                //1 : 벽
            }
        }
    }
 
    
    for(int i=0; i<emptySpace.size()-2; i++){
        for(int j=i+1; j<emptySpace.size()-1; j++){
            for(int k=j+1; k<emptySpace.size(); k++){
                
                for(int u=0; u< virusStorage.size(); u++){
                    virus.push(make_pair(virusStorage[u].first, virusStorage[u].second));
                }
                arr[emptySpace[i].first.first][emptySpace[i].first.second] = 1;
                arr[emptySpace[j].first.first][emptySpace[j].first.second] = 1;
                arr[emptySpace[k].first.first][emptySpace[k].first.second] = 1;
                
                //cout << "벽 정보 " << endl;
                //cout << emptySpace[i].first.first << " " << emptySpace[i].first.second << endl;
                //cout << emptySpace[j].first.first << " " << emptySpace[j].first.second << endl;
                //cout << emptySpace[k].first.first << " " << emptySpace[k].first.second << endl;
                
                int areaNum = zerocnt - spreadVirus(0);
               
                if(maxSafeArea <= areaNum){
                    maxSafeArea = areaNum;
                }
                
                //cout << "바이러스 개수 " <<virus.size() << endl;
                //cout << spreadVirus(0) << endl;
                arr[emptySpace[i].first.first][emptySpace[i].first.second] = 0;
                arr[emptySpace[j].first.first][emptySpace[j].first.second] = 0;
                arr[emptySpace[k].first.first][emptySpace[k].first.second] = 0;
                
                for(int q=0; q<8; q++){
                    for(int w=0; w<8; w++){
                        check[q][w] = 0;
                    }
                }
                
            }
        }
    }
    
    //벽 3개 뺴기
    cout << maxSafeArea-3;
    
    return 0;
}
