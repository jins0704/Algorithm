//
//  main.cpp
//  21611_마법사상어와블리자드
//
//  Created by 홍진석 on 2021/09/28.
//

#include <iostream>
#include <vector>
#include <queue>
#define FOR(i,n) for(int i=0; i<n; i++)

using namespace std;

int dx[5] = {0,-1,1,0,0}; //위, 아래, 좌, 우
int dy[5] = {0,0,0,-1,1};
int N,M;
int d,s,center;
int sol[5];

vector<int> makeOneLine(vector<vector<int>> &arr){
    vector<int> line;
    int sx = N/2; int sy = N/2-1; //시작지점
    int idx = 1;
    if(arr[sx][sy]!=0){ line.push_back(arr[sx][sy]); }
    
    while(1){
        int target = center+idx;
        while(sx < target){//아래 이동
            if(arr[++sx][sy] != 0){
                line.push_back(arr[sx][sy]);
            }
        }
        while(sy < target){//오른쪽 이동
            if(arr[sx][++sy] != 0){
                line.push_back(arr[sx][sy]);
            }
        }
    
        target = center-idx;
        while(sx > target){//위 이동
            if(arr[--sx][sy] != 0){
                line.push_back(arr[sx][sy]);
            }
        }
        while(sy > target){//왼쪽 이동
            if(arr[sx][--sy] != 0){
                line.push_back(arr[sx][sy]);
            }
        }
        
        idx ++;
        if(sx == 0 && sy == 0){ break; }
        else{
            if(arr[sx][--sy] != 0){
                line.push_back(arr[sx][sy]);
            }
        }
    }

        
    return line;
}

deque<pair<int, int>> destroySame(vector<int> &line){
    deque<pair<int, int>> result;//숫자, 개수
    
    
    FOR(i, line.size()){
        if (result.empty()) { result.push_back(make_pair(line[i], 1)); }
        else{
            if(result.back().first == line[i]) { result.back().second++; }
            else{ result.push_back(make_pair(line[i], 1)); }
        }
    }
    
    bool check = true;
    while (check) {
        check = false;
        deque<pair<int, int>> temp;
        while(!result.empty()){
            if(result.front().second >= 4){
                sol[result.front().first] += result.front().second;
                check = true;
            }
            else{
                if(!temp.empty()){
                    if(temp.back().first == result.front().first){
                        temp.back().second += result.front().second;
                    }
                    else{ temp.push_back(make_pair(result.front().first, result.front().second)); }
                }
                else{ temp.push_back(make_pair(result.front().first, result.front().second)); }
            }
            result.pop_front();
        }
        result = temp;
    }

    return result;
}

vector<vector<int>> arrange(deque<int> &dq){

    int sx = N/2; int sy = N/2-1; //시작지점
    vector<vector<int>> newArr(N,vector<int>(N,0));
    int idx = 1;

    if(!dq.empty()){
        newArr[sx][sy] = dq.front();
        dq.pop_front();
    }
    if(dq.empty()){ return newArr; }
    
    while(1){
        int target = center+idx;
        while(sx < target){//아래 이동
            if(!dq.empty()){
                newArr[++sx][sy] = dq.front();
                dq.pop_front();
            }
            if(dq.empty()){ return newArr; }
        }

        while(sy < target){//오른쪽 이동
            if(!dq.empty()){
                newArr[sx][++sy] = dq.front();
                dq.pop_front();
            }
            if(dq.empty()){ return newArr; }
        }

        target = center-idx;
        while(sx > target){//위 이동
            if(!dq.empty()){
                newArr[--sx][sy] = dq.front();
                dq.pop_front();
            }
            if(dq.empty()){ return newArr; }
        }

        while(sy > target){//왼쪽 이동
            if(!dq.empty()){
                newArr[sx][--sy] = dq.front();
                dq.pop_front();
            }
            if(dq.empty()){ return newArr; }
        }
     
        idx ++;
        if(sx == 0 && sy == 0){ break; }
        else{
            if(!dq.empty()){
                newArr[sx][--sy] = dq.front();
                dq.pop_front();
            }
            if(dq.empty()){ return newArr; }
        }
    }

    return newArr;
}
int main() {
    cin >> N >> M;
    vector<vector<int>> arr(N,vector<int>(N,0));//배열 초기화
    FOR(i,N){ FOR(j,N){ cin >> arr[i][j]; }} //배열 만들기
    
    center = N/2; //중심
    
    FOR(i,M){
        cin >> d >> s;
        //1.블리자드 마법 : 구슬 폭파
        for(int j=1; j<=s; j++){
            arr[center+dx[d]*j][center+dy[d]*j] = 0;
        }
        //2. 자리 채워 한줄로

        vector<int> line = makeOneLine(arr);
        //3. 같은 구슬 폭파하기
        deque<pair<int, int>> dq = destroySame(line);
        deque<int> dq2;
        while (!dq.empty()) {
            dq2.push_back(dq.front().second);
            dq2.push_back(dq.front().first);
            dq.pop_front();
        }

        //4. 구슬 개수, 구슬번호 로 변화
        arr = arrange(dq2);
//        FOR(e, arr.size()){
//            FOR(r, arr.size()){
//                cout << arr[e][r] << " ";
//            }cout << endl;
//        }

    }
    cout << sol[1] + 2 * sol[2] + 3 * sol[3];
    return 0;
}

//블리자드 마법

//(폭발한 1번 구슬) + 2*(폭발한 2번 구슬 개수) + 3*(폭발한 3번 구슬 개수)

//구슬 파괴하기
//구슬 채우기
//(4개이상 연속 구슬 폭파하기) 없을때까지 반복
//구슬 개수, 구슬번호 로 변화
//FOR(i,N){ FOR(j,N){ cout << arr[i][j] << " "; }cout << endl;} //배열확인
