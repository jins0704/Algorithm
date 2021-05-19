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

int N,C;
int n;
vector<int> house;

int main() {
    
    cin >> N >> C;
        
    for(int i=0; i<N; i++){
        cin >> n;
        house.push_back(n);
    }
    
    sort(house.begin(), house.end());
    int ans = 1;
    
    int cnt = 0;
    int low = 1; //최소거리
    int high = house[N-1] - house[0]; //최대거리
    int tmp;
    
    while(low <= high){
        vector<int> sol;
        cnt = 1;
        int mid = (low+high)/2;
        tmp = house[0];
        
        for(int i=0; i<N; i++){
            int d = house[i] - tmp;
            
            if(mid <= d){
                cout << house[i] << " ";
                cnt ++;//설치
                tmp = house[i];
                sol.push_back(i);
            }
        }
        cout << "설치끝"<< endl;
        if(cnt >= C){
            ans = mid;
            low = mid+1;
        
            cout <<"if "<< low << " " << high<< endl;
        }
        else{
            high = mid -1;
            //cout <<"else" << endl;
            cout <<"else "<< low << " " << high<< endl;
        }
    }
    
    cout << ans;
    return 0;
}
