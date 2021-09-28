//
//  main.cpp
//  21610_마법사상어와비바라기
//
//  Created by 홍진석 on 2021/09/28.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int dx[9] = {0,0,-1,-1,-1,0,1,1,1};
int dy[9] = {0,-1,-1,0,1,1,1,0,-1};
int N,M;
int w,d,s;
vector<vector<int>> arr(51);

void initCloud(set<pair<int, int>> &cloud){
    cloud.insert(make_pair(N-1, 0));
    cloud.insert(make_pair(N-1, 1));
    cloud.insert(make_pair(N-2, 0));
    cloud.insert(make_pair(N-2, 1));
}

void operateCloud(set<pair<int, int>> &cloud, int d, int s){
    //모든 구름들 방향 di칸으로 si칸 이동시키기
    set<pair<int, int>> newCloud;
    for(auto c : cloud){
        c.first += (dx[d] * s)%N;
        c.second += (dy[d] * s)%N;
        
        if(c.first < 0) { c.first += N; }
        else if(c.first >= N) { c.first -= N; }

        if(c.second < 0) { c.second += N; }
        else if(c.second >= N) { c.second -= N; }

        //물의 양 1 증가
        arr[c.first][c.second] ++;
        newCloud.insert(make_pair(c.first, c.second));
    }
    cloud = newCloud;
    
    //물복사 버그 마법
    for(auto c : cloud){
        int cnt = 0;
        if(c.first-1 >= 0 && c.second-1 >= 0 && arr[c.first-1][c.second-1] > 0) { cnt ++; } //왼쪽위
        if(c.first-1 >= 0 && c.second+1 < N && arr[c.first-1][c.second+1] > 0) { cnt ++; } //오른쪽위
        if(c.first+1 < N && c.second-1 >= 0 && arr[c.first+1][c.second-1] > 0) { cnt ++; } //왼쪽아래
        if(c.first+1 < N && c.second+1 < N && arr[c.first+1][c.second+1] > 0) { cnt ++; } //오른쪽아래
        arr[c.first][c.second] += cnt;
    }
}

void makeCloud(set<pair<int, int>> &cloud){
    set<pair<int, int>> newCloud;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(arr[i][j] >= 2){
                if(cloud.find(make_pair(i, j)) == cloud.end()){
                    arr[i][j] -= 2;
                    newCloud.insert(make_pair(i, j));
                }
            }
        }
    }
    
    cloud = newCloud;
}

int main() {
    set<pair<int, int>> cloud;
    cin >> N >> M;
    
    for(int i=0; i<N; i++){  //(0~N-1)(0~N-1) 이차원 배열
        for(int j=0; j<N; j++){
            cin >> w;
            arr[i].push_back(w);
        }
    }
    
    initCloud(cloud);
    for(int i=0; i<M; i++){
        cin >> d >> s;
        operateCloud(cloud,d,s);
        makeCloud(cloud);

    }
    
    int sum = 0;
    
    for (int i=0; i<N;  i++) {
        for(int j=0; j<N; j++){
            sum += arr[i][j];
        }
    }
    
    cout << sum << endl;
    return 0;
}
