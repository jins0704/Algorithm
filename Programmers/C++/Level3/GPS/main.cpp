//
//  main.cpp
//  GPS
//
//  Created by 홍진석 on 2021/10/29.
//

#include <iostream>
#include <vector>
#define FOR(i,n) for(int i=0; i<(n); i++)
#define INF 123456789

using namespace std;

int minvalue;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {

    vector<vector<int>> edge(n+1, vector<int>());
    vector<vector<int>> DP(k, vector<int>(n+1,INF));
    FOR(i, edge_list.size()) {// 모든 도로는 왕복 도로
        edge[edge_list[i][0]].push_back(edge_list[i][1]);
        edge[edge_list[i][1]].push_back(edge_list[i][0]);
    }
    
    DP[0][gps_log[0]] = 0;
    
    for(int i=1; i<k; i++) {//gps_log 2번째 자리부터 탐색
        for(int j=1; j<=n; j++){
            for(int k =0; k< edge[j].size(); k++){
                DP[i][j] = min(DP[i-1][j], min(DP[i-1][edge[j][k]], DP[i][j]));
            }
            DP[i][j] += (gps_log[i] == j) ? 0 : 1;
        }
    }
    int answer = DP[k-1][gps_log[k-1]];
    
    return answer >= INF ? -1 : answer;
}

int main(){
    vector<vector<int>> edge_list = {{1,2},{1,3},{2,3},{2,4},{3,4},{3,5},{4,6},{5,6},{5,7},{6,7}};
    vector<int> gps_log = {1,2,3,4,5,6,7};
    cout << solution(7, 10, edge_list, 6, gps_log);
    
    return 0;
}
