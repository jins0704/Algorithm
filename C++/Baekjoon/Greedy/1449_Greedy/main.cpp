//
//  main.cpp
//  1449_Greedy
//
//  Created by 홍진석 on 2021/02/08.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,L,loc;
vector<int> v;
int sum,cnt;
bool taping[1001];
int main() {

    //물이 새는 곳의 개수와 테이프 길이 L이 주어진다.
    cin >> N >> L;
    
    //물이 새는 위치가 주어진다.
    for(int i=0; i<N; i++){
        cin >> loc;
        v.push_back(loc);
    }
    
    sort(v.begin(),v.end());
    
    
    for(int i=0; i<N; i++){
        if(taping[i] == false){
            taping[i] = true;
            for(int j=i; j<N; j++){
                if(j>i && v[j] <= v[i]-1+L){
                    taping[j] = true;
                }
            }
            
            cnt++;
        }
    }

    cout << cnt;
    return 0;
}
