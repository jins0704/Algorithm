//
//  main.cpp
//  practice
//
//  Created by 홍진석 on 2020/07/26.
//  Copyright © 2020 홍진석. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<pair<int,int>> v;
int Rank[51];

int main(){
    int N,x,y;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> x >> y;
        v.push_back(pair<int,int>(x,y));
         Rank[i] =1;
    }
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            if(v.at(i).first < v.at(j).first && v.at(i).second < v.at(j).second){
                Rank[i] += 1;
            }
            if(v.at(i).first > v.at(j).first && v.at(i).second > v.at(j).second){
                Rank[j] += 1;
            }
        }
        cout << Rank[i] << " ";
    }
}
