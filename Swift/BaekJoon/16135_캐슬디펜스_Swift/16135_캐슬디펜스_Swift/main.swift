//
//  main.swift
//  16135_캐슬디펜스_Swift
//
//  Created by 홍진석 on 2021/11/23.
//

import Foundation

struct enemy : Hashable{
    var x : Int
    var y : Int
}

func solution() -> Int {
    let NMD = readLine()!.split(separator: " ").map{ Int($0)! } //NxM
    let N = NMD[0]; let M = NMD[1]; let D = NMD[2] // N, M, D 정보
    var answer = 0
    
    //init Board
    var board = [[Int]]()
    for _ in 0..<N {
        let input = readLine()!.split(separator: " ").map{ Int($0)! }
        board.append(input)
    }
    
    //궁수 3명 배치 조합 찾기
    var archerInfo = [[Int]]()
    var archers = [Int]()
    combiArchor(M, &archerInfo, &archers)
    
    //궁수 조합에 따라 게임 시작
    for archers in archerInfo {
        answer = max(answer,gameStart(archers, board, D))
    }
    
    return answer
}

func combiArchor(_ M : Int, _ archerInfo : inout [[Int]], _ archers : inout [Int]) {
    if archers.count == 3 {
        archerInfo.append(archers)
    }
    else{
        for i in 0..<M {
            if archers.isEmpty || archers.last! < i {
                archers.append(i)
                combiArchor(M, &archerInfo, &archers)
                archers.removeLast()
            }
        }
    }
}

func gameStart(_ archers : [Int], _ board : [[Int]], _ D : Int) -> Int {
    var cnt = 0
    var moveCnt = 0
    var copyBoard = board
    let m = copyBoard.count
    let n = copyBoard[0].count
    
    while(true) {
        var enemies = Set<enemy>() //공격할 적 (같은 적이 여러 궁수 공격 가능하기에 Set)
        let dir = [(-1,0),(1,0),(0,1),(0,-1)]
        for archer in archers {
            var d = 0
            var check = [[Bool]](repeating: [Bool](repeating: false, count: n), count: m)
            var queue = [(m,archer)]
            var enemyCandidate = [(Int,Int)]()
            
            while(!queue.isEmpty){
                var newQueue = [(Int,Int)]()
                for (element) in queue {
                    for j in 0..<4{
                        let nx = element.0 + dir[j].0
                        let ny = element.1 + dir[j].1
       
                        if (nx < 0) || (nx >= m) || (ny < 0) || (ny >= n) { continue } //board범위 내에서만
                        if !check[nx][ny] {
                            check[nx][ny] = true
                            if copyBoard[nx][ny] == 1 { //적 발견 (일단 같은 턴에 최적의 적 찾을 수 있으므로 후보군에 넣어두기)
                                enemyCandidate.append((nx,ny))
                            }
                            else if copyBoard[nx][ny] == 0 { //이동
                                newQueue.append((nx,ny))
                            }
                        }
                    }
                }
                
                if !enemyCandidate.isEmpty{ //같은 턴 적들 중에서 가장 왼쪽 적 찾아서 공격할 적에 넣고 종료
                    enemyCandidate.sort { $0.1 < $1.1 }
                    enemies.insert(enemy(x: enemyCandidate[0].0, y: enemyCandidate[0].1))
                    break
                }
                queue = newQueue
                
                d += 1
                if d == D { break } //거리가 D이하인
            }
        }
    
        if moveCnt == m { break } //끝까지 내렸으면 게임 종료
        if enemies.isEmpty { //모든 적이 격자판에서 제외되면 게임오버
            moveCnt += 1
        }
        
        //공격받은 적은 게임에서 제외
        enemies.map { e in
            copyBoard[e.x][e.y] = 0
        }
        //궁수의 공격으로 제거할 수 있는 적의 최대 수 계산
        cnt += enemies.count
        
        //공격이 끝나면 적들 아래로 한 칸 이동
        copyBoard.removeLast()
        copyBoard.insert(Array(repeating: 0, count: board[0].count), at: 0)
    }
    
    //궁수의 공격으로 제거할 수 있는 적의 최대 수 계산
    return cnt
}

print(solution())
