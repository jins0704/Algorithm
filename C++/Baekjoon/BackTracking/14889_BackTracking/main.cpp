//
//  main.cpp
//  14889_BackTracking
//
//  Created by 홍진석 on 2020/08/23.
//  Copyright © 2020 홍진석. All rights reserved.
//

#include <iostream>

using namespace std;

int N;
int arr[21][21];
bool check[11];
int memeber[11];
int member2[11];
int minn= 10000;

void maketeam(int start,int index){
    memeber[index] = start;
    check[start] = true;
    
    if(index == N/2){
        int cnt2=1;
        int sum=0;
        int sum2=0;
        int gap =0;
       
        for(int w=1; w<=N; w++){
            if(check[w]==false){
                member2[cnt2] = w;
                cnt2 ++;
            }
        }
        for(int j=1; j<=N/2; j++){
            for(int q=1; q<=N/2; q++){
                int p1 = memeber[j];
                int p2 = memeber[q];
                sum += arr[p1][p2];
                
                int p3 = member2[j];
                int p4 = member2[q];
               
                sum2 += arr[p3][p4];
            }
            
        }
        
        gap = abs(sum - sum2);
        
        if(gap <= minn) minn = gap;
    
        return;
    }
    
    for(int i=1; i<=N; i++){
        if(check[i]== false && i>start){
            maketeam(i,index+1);
            check[i]= false;
        }
    }
    
}
int main() {
    cin >> N;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> arr[i][j];
        }
    }
    maketeam(1,1);
    
    cout << minn ;
    return 0;
}
