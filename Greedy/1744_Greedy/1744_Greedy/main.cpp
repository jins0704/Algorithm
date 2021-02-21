//
//  main.cpp
//  1744_Greedy
//
//  Created by 홍진석 on 2021/02/21.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

priority_queue<int,vector<int>,greater<int>> pqG;
priority_queue<int,vector<int>,less<int>> pqL;

// 길이 : N, 수열의 합 구하기
// 두 수를 묶으면 서로 곱한 후 더한다.
// 최대값 구하기

int N,num,sum;
int a,b,cnt,zerocnt;

int main() {
    
    cin >> N;
    
    while(N--){
        cin >> num;
        if(num >0){
            pqL.push(num);
        }
        else if(num ==0){
            //zerocnt에 0 개수
            zerocnt ++;
        }
        else{
            pqG.push(num);
        }
    }
    //양수는 모두 처리
    while(!pqL.empty()){
        a = pqL.top(); pqL.pop();
        
        if(!pqL.empty()){
            b = pqL.top(); pqL.pop();
            
            if(a == 1 || b== 1){
                sum += a+b;
            }
            else{
                sum += a*b;
            }
        }
        else{sum += a;}
    }
    
    while (!pqG.empty()) {
        a= pqG.top(); pqG.pop();
        
        if(!pqG.empty()){
            b = pqG.top(); pqG.pop();
            sum += a*b;
        }
        else{
            if(zerocnt ==0){
                sum += a;
            }
        }
    }
    
    cout << sum;
    
    return 0;
}
