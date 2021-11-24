//
//  main.cpp
//  1931_Greedy
//
//  Created by 홍진석 on 2021/02/11.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int fTime, eTime;
int cnt;
int finishTime;

vector<pair<int, int>> conf;

bool compare(pair<int, int> p1, pair<int, int> p2){
    if(p1.second != p2.second){
        return p1.second < p2.second;
    }
    else{
        return p1.first < p2.first;
    }
}

int main(int argc, const char * argv[]) {
    
    cin >> N;
    
    while(N--){
        cin >> fTime >> eTime;
        conf.push_back(make_pair(fTime, eTime));
    }
    
    sort(conf.begin(), conf.end(), compare);
 
    
    for(int i=0; i<conf.size(); i++){
        if(i==0){
            cnt++;
            finishTime = conf[i].second;
        }
        else{
            if(conf[i].first >= finishTime){
                finishTime = conf[i].second;
                cnt ++;
            }
        }
    }
    cout << cnt;
    return 0;
}
