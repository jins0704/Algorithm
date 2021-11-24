//
//  main.cpp
//  9095_DP
//
//  Created by 홍진석 on 2020/08/17.
//  Copyright © 2020 홍진석. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;
queue<int> q;
int arr[1000];
int cnt;
void sum123(int index, int sum, int num){
    if(sum == num){
        for(int i=0; i<index; i++){
            cout << arr[i] <<" ";
        }
        cout<<endl;
        return;
    }
    if(sum+1<=num){
        arr[index] = 1;
        sum123(index+1,sum+1,num);

    }
    if(sum+2<=num){
        arr[index] = 2;
        sum123(index+1,sum+2,num);
    }
    if(sum+3<=num){
        arr[index] = 3;
        sum123(index+1,sum+3,num);
    }
}

int main() {
    int T;
    int n;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        q.push(n);
    }
    while(!q.empty()){
        int num = q.front();
        q.pop();
        sum123(0,0,num);
    }
    return 0;
}
/*
 #include <iostream>
 #include <queue>

 using namespace std;
 queue<int> q;

 int cnt;
 void sum123(int sum, int num){
     if(sum == num){
         cnt++;
         return;
     }
     if(sum+1<=num){
         sum123(sum+1,num);
     }
     if(sum+2<=num){
         sum123(sum+2,num);
     }
     if(sum+3<=num){
         sum123(sum+3,num);
     }
 }

 int main() {
     int T;
     int n;
     scanf("%d",&T);
     while(T--){
         scanf("%d",&n);
         q.push(n);
     }
     while(!q.empty()){
         int num = q.front();
         q.pop();
         sum123(0,num);
         printf("%d\n",cnt);
         cnt=0;
     }
     return 0;
 }

 */
