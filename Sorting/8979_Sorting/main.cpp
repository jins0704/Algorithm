//
//  main.cpp
//  8979_Sorting
//
//  Created by 홍진석 on 2021/01/26.
//

#include <iostream>
#include <vector>

using namespace std;

int N;
int goal;
int num,g,s,b;
int same;

struct country{
    int n = 0;
    int gold = 0;
    int silver  = 0;
    int bronze = 0;
};

vector<country> medalRank;

int main() {
    
    cin >> N >> goal;
    
    while(N--){
        cin >> num >> g >> s >> b;
        
        country c = country();
        c.n = num;
        c.gold = g;
        c.silver = s;
        c.bronze = b;
        
        if(medalRank.empty()){
            medalRank.push_back(c);
        }
        else{
            for(int i =0; i<medalRank.size(); i++){
                if(medalRank[i].gold < c.gold){
                    medalRank.insert(medalRank.begin()+i, c);
                    break;
                }
                else if(medalRank[i].gold == c.gold){
                    if(medalRank[i].silver < c.silver){
                        medalRank.insert(medalRank.begin()+i,c);
                        break;
                    }
                    else if(medalRank[i].silver == c.silver){
                        if(medalRank[i].bronze < c.bronze){
                            medalRank.insert(medalRank.begin()+i, c);
                            break;
                        }
                        else{
                            if(i+1 == medalRank.size()){
                                medalRank.push_back(c);
                                break;
                            }
                        }
                    }
                    else{
                        if(i+1 == medalRank.size()){
                        medalRank.push_back(c);
                        break;
                        }
                    }
                }
                else{
                    if(i+1 == medalRank.size()){
                        medalRank.push_back(c);
                        break;
                    }
                }
            }
        }
    }

    for(int i=0; i<medalRank.size(); i++){
        if(medalRank[i].n == goal){
            int g = i-1;
            while(g>-1){
                if(medalRank[i].gold == medalRank[g].gold){
                    if(medalRank[i].silver == medalRank[g].silver){
                        if(medalRank[i].bronze == medalRank[g].bronze){
                            same++;
                        }
                        else{
                            break;
                        }
                    }
                    else{
                        break;
                    }
                }
                else{
                    break;
                }
                g--;
            }
            cout << i+1-same;
            break;
        }
    }
    
    return 0;
}
