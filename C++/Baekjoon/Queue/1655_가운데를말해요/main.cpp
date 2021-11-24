//
//  main.cpp
//  1655_가운데를말해요
//
//  Created by 홍진석 on 2021/11/18.
//

#include <iostream>
#include <queue>
#include <math.h>
using namespace std;
priority_queue<int,vector<int>, greater<>> big;
priority_queue<int,vector<int>, less<>> small;

int a;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    int temp = 0;
    cin >> n;

    int cnt = 0;
    int first = 0;

    for(int i=0; i<n; i++){
        cin >> a;
        cnt ++;
        if(cnt == 1) {
            first = a;
            cout << first << endl;
        }
        else if(cnt == 2){
            if(a >= first) { big.push(a); small.push(first); }
            else { big.push(first); small.push(a); }
            cout << small.top() << endl;
        }

        else{
            //위치에 맞게 넣기
            if(a <= small.top()) { small.push(a); }
            else { big.push(a); }
            
            //양쪽 크기 잘 맞추기
            if(small.size() - big.size() == 2) {
                temp = small.top();
                small.pop();
                big.push(temp);
                
            }
            else if(big.size() - small.size() == 2){
                temp = big.top();
                big.pop();
                small.push(temp);
            }
            
            if(cnt%2 == 0) {
                cout << min(small.top(), big.top()) << '\n';
            }
            else{
                int sol = big.size() > small.size() ? big.top() : small.top();
                cout << sol << '\n';
            }
        }
    }
    
    return 0;
}
