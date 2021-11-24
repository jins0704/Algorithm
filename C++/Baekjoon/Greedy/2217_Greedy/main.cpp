//
//  main.cpp
//  2217_Greedy
//
//  Created by 홍진석 on 2020/09/04.
//  Copyright © 2020 홍진석. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> vc;
int N,k,n;

int mina;
int temp;
int main(int argc, const char * argv[]) {
    scanf("%d",&N);
    temp = N;
    for(int j =0; j<N; j++){
        scanf("%d",&n);
        vc.push_back(n);
    }
    sort(vc.begin(),vc.end());
    for(int i=0; i<vc.size(); i++){
        
        if(vc[i]*N>mina){
            mina = vc[i]*N;
            if(N<1){
                break;
            }
        }
        N--;
    }
    cout << mina;
    return 0;
}
