//
//  main.cpp
//  11403_FloydWarshall
//
//  Created by 홍진석 on 2021/04/22.
//

#include <iostream>

using namespace std;

int N;
int edge[101][101];

int main() {
    
    cin >> N;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> edge[i][j];
        }
    }
    
    for(int k=0; k<N; k++){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(edge[i][k] == 1 && edge[k][j] == 1){
                    edge[i][j] = 1;
                }
            }
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << edge[i][j] << " ";
        }cout << endl;
    }
    return 0;
}
