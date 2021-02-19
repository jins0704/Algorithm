//
//  main.cpp
//  1715_Greedy
//
//  Created by 홍진석 on 2021/02/19.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N,n,sum,sum2;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    
    scanf("%d",&N);
    
    for(int i=0; i<N; i++){
        scanf("%d",&n);
        pq.push(n);
    }
    
    if(pq.size() == 1){
        printf("0");
    }
    
    else{
        while(!pq.empty()){
        
            int a = pq.top();
            pq.pop();
            
            int b = pq.top();
            pq.pop();
            
            sum += (a+b);
    
            if(pq.empty()){ break; }
            pq.push(a+b);
  
        }
        
        printf("%d",sum);
    }
    
    return 0;
}
