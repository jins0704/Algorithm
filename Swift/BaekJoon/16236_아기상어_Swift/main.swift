//
//  main.swift
//  아기상어_Swift
//
//  Created by 홍진석 on 2021/11/13.
//

import Foundation

var sharkIdx = (0,0)
var sharkExp = 0
var sharkSize = 2 //init size = 2
var N = 0
var board = [[Int]]()

func solution() -> Int {
    N = Int(readLine()!)!
    var answer = 0
    
    for _ in 0..<N {
        let input = readLine()?.split(separator: " ").map{ Int($0)! }
        board.append(input!)
    }
    
    sharkIdx = findShark() // init loc
    
    while(true){
        let result = findFish(sharkIdx)
        if result>0 { answer += result }
        else { break }
    }
    
    return answer
}

func findShark() -> (Int,Int) {
    for (i,row) in board.enumerated() {
        for (j,element) in row.enumerated() {
            if element == 9 { return (i,j) }
        }
    }
    return (0,0)
}

func findFish(_ idx : (Int,Int)) -> Int {
    var queue = [idx]
    var fishes = [(Int,Int)]()
    let dir = [(-1,0),(1,0),(0,1),(0,-1)]
    var check = [[Bool]](repeating: [Bool](repeating: false, count: N), count: N)
    var cnt = 0
    check[idx.0][idx.1] = true
    
    while(!queue.isEmpty){
        var newQueue = [(Int,Int)]()
        
        for (element) in queue {
            let cloc = element
            for j in 0..<4{
                let nx = cloc.0 + dir[j].0
                let ny = cloc.1 + dir[j].1
                if (nx < 0) || (nx >= N) || (ny < 0) || (ny >= N) { continue }
                
                if !check[nx][ny] && board[nx][ny] <= sharkSize { //자신보다 작거나 같은 물고기 있는 칸만
                    check[nx][ny] = true
                    if board[nx][ny] < sharkSize && board[nx][ny] != 0 { fishes.append((nx,ny)) } //자신보다 작은 물고기만 먹는다
                    newQueue.append((nx,ny))
                }
            }
        }
        queue = newQueue
        cnt += 1

        if !fishes.isEmpty {
            fishes.sort { // 1순위 가장 위의 물고기 2순위 가장 왼쪽에 있는 물고기
                if $0.0 == $1.0 { return $0.1 < $1.1 }
                else { return $0.0 < $1.0 }
            }
            let eatFish = fishes[0]
            board[eatFish.0][eatFish.1] = 9  //물고기 먹고 상어 이동
            board[sharkIdx.0][sharkIdx.1] = 0
            sharkIdx = (eatFish.0,eatFish.1)
            sharkExp += 1
     
            if sharkExp == sharkSize { //상어 크기, 경험치
                sharkSize += 1
                sharkExp = 0
            }
            
            return cnt
        }
    }
    return 0
}

print(solution())


