//
//  main.cpp
//  11404_FloydWarshall
//
//  Created by 홍진석 on 2021/04/22.
//

#include <iostream>

using namespace std;

//n(2~100개) 도시
//m(1~100000개) 버스
//A->B로 가는데 필요한 최솟값

//첫번째 입력 : n
//둘째 입력 : m
//셋째줄 ~ m+2줄까지 입력 : 출발 도시 a, 도착 도시 b, 비용 c
//노선은 여러개 가능

int n,m;
int a,b,c;
int edge[101][101];

int main() {
    cin >> n;
    cin >> m;
    
    for(int i=0; i<m; i++){
        
        cin >> a >> b >> c;
        if(edge[a][b] != 0 && edge[a][b] > c){
            edge[a][b] = c;
        }
        else if(edge[a][b] == 0){
            edge[a][b] = c;
        }
        else{}
        
    }
    
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(i == j){continue;}
                if(edge[i][k] != 0 && edge[k][j] != 0){
                    if(edge[i][j] == 0){
                        edge[i][j] = edge[i][k] + edge[k][j];
                    }
                    else if(edge[i][j] !=0 && edge[i][k] + edge[k][j] < edge[i][j]){
                        edge[i][j] = edge[i][k] + edge[k][j];
                    }
                }
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout << edge[i][j] << " ";
        }cout << endl;
    }
    return 0;
}
