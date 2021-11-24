//
//  main.cpp
//  2740_분할정복
//
//  Created by 홍진석 on 2020/08/17.
//  Copyright © 2020 홍진석. All rights reserved.
//

#include <iostream>

using namespace std;

int A[101][101];
int B[101][101];
int x,y;
int q,w;

int main() {
    cin >> x >> y;
    int temp,temp2;
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            cin >> temp;
            A[i][j] = temp;
        }
    }
    cin >> q >> w;
    for(int k=0; k<q; k++){
        for(int o=0; o<w; o++){
            cin >> temp2;
            B[k][o] = temp2;
        }
    }
    for(int i=0; i<x; i++){
        for(int j=0; j<w; j++){
            int temp = 0;
            for(int k=0; k<q; k++){
                temp += A[i][k] * B[k][j];
            }
            cout << temp << " ";
        }
        cout <<endl;
        
    }
    return 0;
}
