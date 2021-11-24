//
//  main.cpp
//  방문길이
//
//  Created by 홍진석 on 2021/10/08.
//
#include <string>
#include <iostream>
#include <set>

using namespace std;
int dx[4] = {-1,1,0,0}; // UDRL
int dy[4] = {0,0,1,-1};

int getCommand(char c){
    if(c == 'U'){ return 0;}
    else if(c == 'D'){ return 1;}
    else if(c == 'R'){ return 2;}
    else if(c == 'L'){ return 3;}
    else { return -1; }
}

int solution(string dirs) {
    int cx = 0;
    int cy = 0;
    set<pair<pair<int,int>,pair<int,int>>> road;

    for(int i=0; i<dirs.size(); i++){
        int command = getCommand(dirs[i]);
        int nx = cx + dx[command];
        int ny = cy + dy[command];
        
        if(nx > 5 || ny > 5 || nx < -5 || ny <-5) {continue;}
        road.insert(make_pair(make_pair(cx,cy),make_pair(nx,ny)));
        road.insert(make_pair(make_pair(nx,ny),make_pair(cx,cy)));
        cx = nx;
        cy = ny;
    }

    return int(road.size()/2);
}
