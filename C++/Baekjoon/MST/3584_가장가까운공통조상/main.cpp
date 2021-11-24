//
//  main.cpp
//  3584_가장가까운공통조상
//
//  Created by 홍진석 on 2021/10/07.
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--){
        int nodes = 0;
        cin >> nodes;
        int a = 0;
        int b = 0;
    
        vector<vector<int>> edge(nodes+1);
        for(int i=0; i < nodes-1; i++){
            cin >> a >> b;
            edge[b].push_back(a);
        }
       
        cin >> a >> b;
       
        set<int> parentOfA = {a};
        while (!edge[a].empty()) {
            parentOfA.insert(edge[a][0]);
            a = edge[a][0];
        }
        
        if(parentOfA.find(b) != parentOfA.end()){
            cout << b << endl;
        }
        else{
            while (!edge[b].empty()) {
                if(parentOfA.find(edge[b][0]) != parentOfA.end()){
                    cout << edge[b][0] << endl;
                    break;
                }
                b = edge[b][0];
            }
        }
    }
    return 0;
}
