//
//  main.cpp
//  1697_BFS_DFS
//
//  Created by 홍진석 on 2021/02/28.
//

#include <iostream>
#include <queue>

using namespace std;

//수빈이는 N, 동생은 K 에 있다.
//수빈이의 현재 위치 X
//걷는다면 X-1 or X+1
//순간이동을 한다면 2*X

//동생을 찾을 수 있는 가장 빠른 시간?

int N, K;

queue<int> q;

int check[100001];

void findSister(int c){
    
    int cnt = 0;
    bool finish = false;
    
    if(c == K){
        cout << 0 << endl;
        return;
    }
    
    q.push(c);
    
    while(!q.empty()) {
        
        unsigned long qsize= q.size();
        
        for(int i=0; i< qsize; i++){
            
            int n = q.front();
            q.pop();
            
            check[n] = true;
            
            if(n-1 >=0 && check[n-1] == false){
                q.push(n-1);
            }
            if(n+1 <= 100000 && check[n+1] == false){
                q.push(n+1);
            }
            if(n*2 <= 100000 && check[n*2] == false){
                q.push(n*2);
            }
            if(n-1 == K || n+1 == K || n*2 == K){
                finish = true;
                break;
            }
        }
        
        cnt++;
        
        if(finish){break;}
    }
    
    cout << cnt;
}
int main() {
    
    cin >> N >> K;
    
    findSister(N);
    
    return 0;
}
