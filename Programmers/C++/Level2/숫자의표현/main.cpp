//
//  main.cpp
//  숫자의표현
//
//  Created by 홍진석 on 2021/10/08.
//

#include <string>
#include <vector>
#include <iostream>
using namespace std;

int cnt;

void dfs(int n, int sum, int last){
    if(sum >= n) {
        if(sum == n ) { cnt+=1; }
        return;
    }
    
    else{
        last++;
        dfs(n,sum+last,last);
    }
}

int solution(int n) {
    int answer = 0;
    for(int i=1; i<=n; i++){
        dfs(n,i,i);
    }
    return cnt;
}
