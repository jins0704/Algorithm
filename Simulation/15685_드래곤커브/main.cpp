//
//  main.cpp
//  15685_드래곤커브
//
//  Created by 홍진석 on 2021/10/02.
//

#include <iostream>
#include <set>
#include <vector>

using namespace std;

int N;
int x,y,d,g;
int cx, cy;
//0: 우,   1: 위,   2: 좌,   3:밑
int dy[4] = {0,-1,0,1};
int dx[4] = {1,0,-1,0};
int answer;

vector<int> drawLine(int d, vector<int> &step){
    vector<int> newStep = step;
    int c;

    for(int i= 0; i<step.size(); i++){
        c = step[step.size()-1-i];
        if(c == 1){ newStep.push_back(2); }
        else if(c==3){ newStep.push_back(0); }
        else if(c== 2){ newStep.push_back(3); }
        else if(c== 0){ newStep.push_back(1); }
    }
    
    return newStep;
}
int main() {
    
    cin >> N;//1. 드래곤 커브의 개수 N
    set<pair<int, int>> curve;
    
    while(N--){
        cin >> x >> y >> d >> g; //2. N개의 줄에 커브 정보 x,y,d,g
        vector<int> step = {d};
        //1세대 시작 방향 (d)
        if(g >= 1){
            while(g--){
                step = drawLine(d, step);
            }
        }
        
        curve.insert(make_pair(y, x));
        for(int i=0; i<step.size(); i++){
            y += dy[step[i]];
            x += dx[step[i]];
            curve.insert(make_pair(y, x));
        }
    }
    
    for(int i=0; i<= 99; i++){
        for(int j=0; j<=99; j++){
            if(curve.find(make_pair(i, j)) != curve.end()){
                if(curve.find(make_pair(i+1, j)) != curve.end()){
                    if(curve.find(make_pair(i, j+1)) != curve.end()){
                        if(curve.find(make_pair(i+1, j+1)) != curve.end()){
                            answer ++;
                        }
                    }
                }
            }
        }
    }
    
    cout << answer << endl;
    return 0;
}

//for(int i =0; i<newStep.size(); i++){
//    cout << newStep[i] << " ";
//}cout << endl;
