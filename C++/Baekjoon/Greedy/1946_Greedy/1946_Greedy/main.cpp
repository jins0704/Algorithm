//
//  main.cpp
//  1946_Greedy
//
//  Created by 홍진석 on 2021/02/20.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T,N;

struct person {
    int sScore; //서류성적
    int mScore; //면접 성적
};

vector<person> v;

bool compare(person a, person b){
    if(a.sScore == b.sScore){
        return a.mScore < b.mScore;
    }
    else{
        return a.sScore < b.sScore;
    }
}
int main() {

    cin >> T;
    
    while(T--){
        
        cin >> N;
        
        int cnt = 1;
        
        while(N--){
            person p;
            cin >> p.sScore >> p.mScore;
            v.push_back(p);
        }
     
        sort(v.begin(), v.end(), compare);
        
        int deadline = v[0].mScore;
        
        for(int i=1; i<v.size(); i++){
            if(v[i-1].sScore == v[i].sScore){
                cnt ++;
                if(deadline < v[i].mScore){
                    deadline = v[i].mScore;
                }
            }
            else{
                if(deadline >= v[i].mScore){
                    cnt++;
                    deadline = v[i].mScore;
                }
            }
        }
        
        cout << cnt << endl;
        v.clear();
    }
    return 0;
}
