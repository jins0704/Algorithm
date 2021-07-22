//
//  main.cpp
//  12845_Greedy
//
//  Created by 홍진석 on 2021/07/22.
//

#include <iostream>
#include <vector>

using namespace std;

int n,ans;
int level;
vector<int> v;

int main() {
    cin >> n;
    
    int maxLevel = 0;
    
    for(int i=0; i<n; i++){
        cin >> level;
        if(maxLevel < level){maxLevel = level;}
        ans += level;
    }
    
    ans += maxLevel * (n-2);
    cout << ans;
    return 0;
}
