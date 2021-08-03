//
//  main.cpp
//  KakaoInternship_2021_2
//
//  Created by 홍진석 on 2021/05/08.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(int i=0; i<places.size(); i++){
        bool impossible = false;
        for(int j=0; j<5; j++){
            for(int k=0; k<5; k++){
                
                if(places.at(i).at(j).at(k) == 'P'){//응시자라면 bfs로 거리 2까지 확인 하자
                    bool check[5][5];
                    for(int l =0; l<5; l++){
                        for(int m=0; m<5; m++){
                            check[l][m] = false;
                        }
                    }
                    queue<pair<int, int>> q;
                    q.push(make_pair(j, k));
                    int dist = 0;
                    bool noproblem = false;
                    
                    while (!q.empty()) {
                        dist++;
                        
                        if(dist >2){
                            noproblem = true;
                            
                            break;
                        }
                        unsigned long qsize=  q.size();
                        
                        for(unsigned l=0; l <qsize; l++){
                            int cx = q.front().first;
                            int cy = q.front().second;
                            check[cx][cy] = true;
                            q.pop();
                            
                            for(int m=0; m<4; m++){
                                int nx = cx + dx[m];
                                int ny = cy + dy[m];
                               
                                if(nx >=0 && ny >=0 && nx <5 && ny <5){//바운더리
                                    
                                    if(!check[nx][ny] && places.at(i).at(nx).at(ny) == 'O'){
                                        check[ny][ny] = true;
                                        q.push(make_pair(nx, ny));
                                    }
                                    else if(!check[nx][ny] && places.at(i).at(nx).at(ny) == 'P'){
                                        impossible = true;
                                        break;
                                    }
                                }
                            }
                            if(impossible){break;}
                        }
                        if(impossible){break;}
                    }
                    if(impossible){break;}
                }
                if(impossible){break;}
            }
            if(impossible){break;}
        }//각 place
        if(impossible){answer.push_back(0);}
        else{answer.push_back(1);}
    }//모든 place
    return answer;
}

int main() {
    vector<vector<string>> places;
    vector<string> place1;

    place1.push_back("PXOPX");
    place1.push_back("OXOXP");
    place1.push_back("OXPXX");
    place1.push_back("OXXXP");
    place1.push_back("POOXX");
    
    
    places.push_back(place1);
    
    solution(places);
    return 0;
}
