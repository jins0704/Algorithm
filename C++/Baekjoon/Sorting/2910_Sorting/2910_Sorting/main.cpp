//
//  main.cpp
//  2910_Sorting
//
//  Created by 홍진석 on 2021/07/26.
//

#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

//N개로 이루어진 수열, 숫자는 모두 C보다 작거나 같다
//자주 등장하는 빈도순대로 정렬한다.

int N,C;
int n;

map<int, pair<int,int>> m; // 숫자, 인덱스, 개수

bool cmp(const pair<int, pair<int,int>> &a, const pair<int, pair<int,int>> &b){
    if(a.second.second == b.second.second){
        return a.second.first < b.second.first;
    }
    else{
        return a.second.second > b.second.second;
    }
}

int main() {
    cin >> N >> C;
    int index = 0;
    for(int i=0; i<N; i++){
        cin >> n;
        if(m.find(n) != m.end()){m[n].second++;}
        else{
            m[n] = make_pair(index, 1);
        }
        index++;
    }
    
    vector<pair<int, pair<int, int>>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);
   
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[i].second.second; j++){
            printf("%d ", v[i].first);
        }
    }
    return 0;
}
