//
//  main.swift
//  [1차]프렌즈블록
//
//  Created by 홍진석 on 2021/10/28.
//

import Foundation

struct point : Hashable {
    let x : Int
    let y : Int
}

func solution(_ m:Int, _ n:Int, _ board:[String]) -> Int {
    let dx = [1,1,0,0]
    let dy = [0,1,1,0]
    var newBoard = [[String.Element]]()
    var answer = 0
    for i in board { newBoard.append(Array(i)) }
    
    while(true) {
        var eraseMemeber = Set<point>()
        
        //지워질 칸 찾기
        for (idx,i) in newBoard.enumerated() {
            if idx == m-1 { break }
            for (idx2,j) in i.enumerated() {
                if idx2 == n-1 { break }
                if j == "." { continue }
                var erasePoss = true
                for d in 0..<3{
                    if j != newBoard[idx+dx[d]][idx2+dy[d]] { erasePoss = false; break; }
                }
                if erasePoss {
                    for d in 0..<4{ eraseMemeber.insert(point(x: idx+dx[d], y: idx2+dy[d])) }
                }
            }
        }
        
        if eraseMemeber.isEmpty { break }
        
        //카운트
        for point in eraseMemeber {
            newBoard[point.x][point.y] = "."
            answer += 1
        }
  
        //내리기
        var tempArr = [[String.Element]]()
        for a in 0..<n {
            var temp = [String.Element]()
            for b in 0..<m {
                if newBoard[b][a] != "."{
                    temp.append(newBoard[b][a])
                }
            }
            while(temp.count < m) { temp.insert(".", at: 0)}
            tempArr.append(temp)
        }
        
        for a in 0..<m {
            for b in 0..<n {
               newBoard[a][b] = tempArr[b][a]
            }
        }
    }
    
    return answer
}

print(solution(5, 6, ["AAAAAA", "BBAATB", "BBAATB", "JJJTAA", "JJJTAA"]))
