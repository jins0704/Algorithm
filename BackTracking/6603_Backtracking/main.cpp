//
//  main.cpp
//  6603_Backtracking
//
//  Created by 홍진석 on 2021/02/02.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int myLotto[10];
int check[50];
int k;
int num;

void makeLotto(int cnt, int nn){
    if(cnt == 6){
        for(int i=0; i<6; i++){
            cout << myLotto[i] << " ";
        }
        cout << endl;
    }
    else{
        for(int j=0; j<k; j++){
            if(check[j] == false){
                if(cnt >=1){
                    if(myLotto[cnt-1] > v[j]){
                        continue;
                    }
                }
                check[j] = true;
                myLotto[cnt] = v[j];
                makeLotto(cnt+1, nn);
                check[j] = false;
                
            }
        }
    }
}

int main() {
    
    while(1){
        
        cin >> k;
        
        if(k ==0){
            break;
        }
        
        for(int i=0; i<k; i++){
            cin >> num;
            v.push_back(num);
        }
        
        makeLotto(0,6);
        cout << endl;
        
        v.clear();
        
    }
    return 0;
}
