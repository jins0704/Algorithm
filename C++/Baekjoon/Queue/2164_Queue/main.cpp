//
//  main.cpp
//  2164_Queue
//
//  Created by 홍진석 on 2021/01/26.
//

#include <iostream>
#include <queue>

using namespace std;
int cnt = 0;
deque<int> q;

int N;

int main() {
    cin >> N;
    for(int i=1; i<= N; i++){
        q.push_back(N-i+1);
    }
    while(q.size() >= 1){
        if(cnt%2 ==0){
            q.pop_back();
            cnt++;
            
        }else{
            int k = q.back();
            q.pop_back();
            q.push_front(k);
            cnt++;
        }
    }
    
    cout << q.front();
    return 0;
}

