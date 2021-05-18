//
//  main.cpp
//  2110_BinarySearch
//
//  Created by 홍진석 on 2021/05/18.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//N개의 집
//집 좌표 x1,...,xN
//공유기 C개 설치
//가장 인접한 두 공유기 사이의 거리를 가능한 크게 설치한다.
//C개의 공유기를 N개의 집에 적당히 설치해서 가장 인저한 두 공유기 사이의 거리 최대가 되게 하라

int N,C,n;
long long sol;
vector<long long> v;

void wifi(int startX, int endX, int wNum){
    
    if(wNum <=0){
        return;
    }

    long long distance = 0;
    long long maxDistance = 0;
    int maxX = 0;
   
    bool check = false;
    for(int i=startX+1; i<endX; i++){
        
        check = true;
        //cout << v[startX] << " " << v[i] << " " << v[endX] << endl;
        if(abs(v[i]-v[startX]) < v[endX] - v[i]){
            distance = abs(v[i]-v[startX]);
        }
        else{
            distance = v[endX] - v[i];
        }//탐색 지점의 두 공유기 최대 거리 확인
        
        if(maxDistance < distance){
            maxDistance = distance;
            maxX = i;
        }//사이의 가장 좋은 공유기 위치, 거리 찾음
    }

    if(!check){return;}
    
    if(wNum == 1){sol = maxDistance;}
    
    else if(wNum>1){
        wifi(startX, maxX,wNum-1);
        wifi(maxX, endX,wNum-1);
    }
}

int main() {
    
    cin >> N >> C;
        
    for(int i=0; i<N; i++){
        cin >> n;
        v.push_back(n);
    }
    
    sort(v.begin(), v.end());
    
//    for(int i=0; i<v.size(); i++){
//        cout << v.at(i) << endl;
//    }
    
    C--;//0 번째 설치
    C--;//가장 끝 번째 설치
    
    sol = v.at(v.size()-1) - v.at(0);
    
    wifi(0, int(v.size()-1),C);
    
    cout << sol;
    
    return 0;
}
