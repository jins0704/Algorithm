#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//성에 몰려오는 적을 잡는 턴 방식
//각 턴마다 적 하나를 공격할 수 있고 동시에 공격한다.
//같은 적이 여러 궁수에게 공격당할 수 있다.
//공격받은 적은 게임에서 제외된다.
//궁수의 공격이 끝나면 적이 아래로 한칸 이동한다.
//성이 있는 칸으로 이동한 경우에는 게임에서 제외된다.

int N, M, D, a;
int area[16][16];
int initArea[16][16];
int catchEnemy;
int a1,a2,a3;
int maxValue;
int dx[4] = {0,-1,1,0};
int dy[4] = {1,0,0,-1};

struct cmp{//거리가 D 이하인 적 중 가장 가까운 적을 공격한다.//거리가 같다면 왼쪽 순으로 적을 공격한다.
    bool operator()(pair<int,int> &x, pair<int,int> &y){
        if(x.second == y.second){
            return x.first < y.first;
        }
        return x.second > y.second;
    }
};

int enemyCnt;

void start(int loc1, int loc2, int loc3){
    
    int myenemyCnt = enemyCnt;
    
    for(int i=0; i<=N; i++){
        for(int j=0; j<M; j++){
            area[i][j] = initArea[i][j];
        }
    }

    vector<pair<int, int>> archorLoc;
    
    area[N][loc1] = 2;
    area[N][loc2] = 2;
    area[N][loc3] = 2; //궁수있는 성은 2, 각 칸에는 최대 한명의 궁수만
    archorLoc.push_back(make_pair(N, loc1));
    archorLoc.push_back(make_pair(N, loc2));
    archorLoc.push_back(make_pair(N, loc3));
    
    
    
    while(myenemyCnt>0){ //모든 적이 격자판에서 제외되면 게임이 끝난다.
        queue<pair<int, int>> GoAttackEnemy; //모든 궁수 공격확정 적
    
        for(int i=0; i<3; i++){ //각 궁수마다 한번씩
            //cout << archorLoc[i].first << " " << archorLoc[i].second << " 궁수 적 찾습니다." << endl;
            priority_queue<pair<int, int>,vector<pair<int, int>>,cmp> wantedAttackEnemy; //궁수마다 공격대상 적
            
            bool check[16][16];
            
            for(int j=0; j<=N; j++){
                for(int k=0; k<M; k++){
                    check[j][k] = 0;
                }
            }
            
            queue<pair<int, int>> q;
            q.push(make_pair(archorLoc[i].first, archorLoc[i].second));
            
            int dist = 0;
            bool wantedFind = false;
            
            while(!q.empty()){
                
                dist ++;
                if(dist > D || wantedFind){//더 멀리 있을때 궁수타임 끝
                    while(!q.empty()){
                        q.pop();
                    }
                    //cout << "거리 초과로 다음 궁수로 넘어갑니다 " << endl;
                    break;
                }
                
                unsigned long qsize = q.size();
                
                for(unsigned j=0; j<qsize; j++){
                    int cx = q.front().first;
                    int cy = q.front().second;
                    q.pop();
                    
                    for(int k=0; k<4; k++){
                        int nx = cx + dx[k];
                        int ny = cy + dy[k];
                        
                        //cout << nx << " " << ny << endl;
                        if(nx >= 0 && ny >=0 && nx < N && ny < M){
                            if(!check[nx][ny] && area[nx][ny] == 0){
                                q.push(make_pair(nx, ny)); //다음칸 이동
                                check[nx][ny] = true;
                                //cout << nx << " " << ny << "칸 확인, 현재 거리: " << dist << endl;
                            }
                            
                            else if(!check[nx][ny] && area[nx][ny] == 1){
                                wantedAttackEnemy.push(make_pair(nx, ny));
                                //cout << nx << " "<< ny << " " << "적 발견 " << dist <<endl;
                                wantedFind = true;
                            }
                        }
                    }
                }
            }
            
            //각 궁수 턴 끝남
            //공격대상중에 베스트 선정, 공격확정에 넣기
            if(!wantedAttackEnemy.empty()){
                GoAttackEnemy.push(make_pair(wantedAttackEnemy.top().first, wantedAttackEnemy.top().second));
               // cout << wantedAttackEnemy.top().first << " "<< wantedAttackEnemy.top().second << " " << "베스트 죽이기 적 발견" << endl;
            }
        }
        
        //모든 궁수 턴 끝남
        //cout << "모든 궁수 턴 끝남" << endl;
        while(!GoAttackEnemy.empty()){
            if(area[GoAttackEnemy.front().first][GoAttackEnemy.front().second] != 0){
                area[GoAttackEnemy.front().first][GoAttackEnemy.front().second] = 0;
                catchEnemy++;
                myenemyCnt--;
            }
            GoAttackEnemy.pop();
        }
        
        //모든 적 밑으로 한칸 이동
        for(int r = N-1; r>=0; r--){
            for(int e = M-1; e >=0; e--){
                
                if(area[r][e] == 1){
                    if(r == N-1){
                        area[r][e] = 0;
                        myenemyCnt --;
                    }
                    else{
                        area[r+1][e] = 1;
                        area[r][e] = 0;
                    }
                }
            }
        }
        for(int r = 0; r<M; r++){
            area[0][r] = 0;
        }
        
        if(myenemyCnt == 0){
            break;
        }
        //cout << "남은 적 " << myenemyCnt << " 잡은 마리"<< catchEnemy << endl;
    }
}

int main() {
    
    cin >> N >> M >> D; //행, 열, 공격거리제한
    
    for(int i=0; i<=N; i++){
        for(int j=0; j<M; j++){
            if(i==N){
                initArea[i][j] = 3; //빈 성은 3 //N 행의 모든 칸에는 성이 있다.
            }
            else{
                cin >> a;
                initArea[i][j] = a;
                if(a == 1){
                    enemyCnt++;
                }
            }
        }
    }

    for(int i=0; i<M-2; i++){
        for(int j=i+1; j<M-1; j++){
            for(int k= j+1; k<M; k++){
                catchEnemy = 0;
                //cout << i << " " << j << " " << k << " 궁수시작합니다" << endl;
                start(i,j,k);//궁수 3명
                //cout << catchEnemy << " 잡은 적 " << endl;
                if(maxValue < catchEnemy){
                    maxValue = catchEnemy;
                }
            }
        }
    }
    //궁수의 공격으로 제거할 수 있는 적의 최대 수를 출력
    cout << maxValue;
    return 0;
}
