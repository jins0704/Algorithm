//
//  main.cpp
//  카카오프렌즈컬러링북
//
//  Created by 홍진석 on 2021/08/11.
//

#include <iostream>
#include <vector>
#include <queue>

#define FOR(i,n) for(int i=0; i<(n); i++)
using namespace std;

bool check[101][101];

int bfs(int sx, int sy, vector<vector<int>> &picture, int m, int n){
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    int cnt = 1;
    queue<pair<int, int>> q;
    q.push(make_pair(sx, sy));
    check[sx][sy] = true;
    
    
    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        FOR(i, 4){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx>=0 && ny >=0 && nx < m && ny < n){
                
                if(!check[nx][ny] && picture[nx][ny] == picture[sx][sy]){
                    check[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                    cnt ++;
                }
            }
        }
    }
    
    return cnt;
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    vector<int> answer(2);
    FOR(i, m){ FOR(j, n){ check[i][j] = false; }}
    
    FOR(i, m){
        FOR(j, n){
            if(picture[i][j] != 0 && !check[i][j]){
                int areaSize = bfs(i,j,picture,m,n);
                if(max_size_of_one_area < areaSize){
                    max_size_of_one_area = areaSize;
                }
                number_of_area ++;
                
            }
        }
    }
    
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
int main() {
    
    return 0;
}
//영역이 많으면 난이도가 높다
//영역 - 상하좌우로 연결된 같은 색상의 공간
//그림에 몇개의 영역과 가장 큰 영역의 넓이가 얼마인지 계산
//그림의 크기 m x n

