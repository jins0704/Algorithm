//
//  main.swift
//  11559_PuyoPuyo
//
//  Created by 홍진석 on 2021/11/22.
//

import Foundation

let xlimit = 12
let ylimit = 6

func solution() -> Int {
    var cnt = 0
    var top = 0
    var board : [[String.Element]] = []
    
    for _ in 0..<xlimit{
        let input = Array(readLine()!)
        board.append(input)
    }
    
    while(true){
       
        var check : [[Bool]] = Array(repeating: Array(repeating: false, count: ylimit), count: xlimit)
        var isBomb = false
        
        for i in top..<xlimit {
            for j in 0..<ylimit {
                if board[i][j] == "." { check[i][j] = true }
                if check[i][j] { continue }
                else { //뿌요 발견
                    if(bomb((i,j),&board,&check)){ isBomb = true }
                }
            }
        }
        
        if(isBomb) { //연쇄 작용했다면
            top = moveBoard(&board)//아래로 내리고 가장 위 뿌요 체크
            cnt += 1
        }
        else { break }
    }
    
    return cnt
}

func bomb(_ s : (Int,Int) , _ board : inout [[String.Element]], _ check : inout [[Bool]]) -> Bool {
    let color = board[s.0][s.1]
    let dir = [(-1,0),(1,0),(0,1),(0,-1)]
    var queue = [s]
    var union = [s]
    check[s.0][s.1] = true
    
    while(!queue.isEmpty){
        var newQueue = [(Int,Int)]()
        for (element) in queue {
            let c = element
            
            for (d) in dir {
                let nx = c.0 + d.0
                let ny = c.1 + d.1
                if(nx < 0) || (nx >= xlimit) || (ny < 0) || (ny >= ylimit) { continue }
                if(!check[nx][ny] && board[nx][ny] == color) {
                    union.append((nx,ny))
                    newQueue.append((nx,ny))
                    check[nx][ny] = true
                }
            }
        }
        queue = newQueue
    }
    
    if union.count >= 4 {
        union.map{ board[$0][$1] = "." }
        return true
    }
    return false
}

func moveBoard(_ board : inout [[String.Element]]) -> Int{
    var tempArr = [[String.Element]]()
    var top = xlimit
    
    for y in 0..<ylimit {
        var temp = [String.Element]()
        for x in 0..<xlimit { if board[x][y] != "."{ temp.append(board[x][y]) } }
        
        top = min(top,xlimit-temp.count) //시간 단축
        
        while(temp.count < xlimit) { temp.insert(".", at: 0)}
        tempArr.append(temp)
    }
    
    for x in 0..<xlimit {
        for y in 0..<ylimit {
            board[x][y] = tempArr[y][x]
        }
    }

    return top
}

print(solution())
