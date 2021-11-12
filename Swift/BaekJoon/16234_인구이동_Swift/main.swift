//
//  main.swift
//  인구이동_Swift
//
//  Created by 홍진석 on 2021/11/12.
//

import Foundation

var check = [[Bool]]()
var N = 0
var r = 0
var l = 0
var A : [[Int]] = [[Int]]()

func start(){
    let input = readLine()!.split(separator: " ").map{Int($0)}
    N = input[0]!
    l = input[1]!
    r = input[2]!
    
    //r행c열 A[r][c]명 살고 있다
    for _ in 0..<N {
        let inputRC : [Int] = readLine()!.split(separator: " ").map { Int($0)! }
        A.append(inputRC)
    }
    
    var possible = true
    var day = 0
    while(possible){
        check = Array(repeating: Array(repeating: false, count: N), count: N)
        var cycle = false
        for i in 0..<A.count{
            for j in 0..<A[i].count {
                if !check[i][j]{
                    if( movePopulation(i,j) ) { cycle = true }

                    
                }
            }
        }
        
        if !cycle { possible = false }
        else { day += 1 }
    }
    
    print(day)
}

func movePopulation(_ i : Int, _ j : Int) -> Bool {
    let dx = [1,-1,0,0]
    let dy = [0,0,-1,1]
    var queue = [(Int,Int)]()
    var union = [(Int,Int)]()
    var sum = 0
    queue.append((i,j))
    union.append((i,j))
    
    while(!queue.isEmpty){
        let qsize = queue.count
        for _ in 0..<qsize {
            let cx = queue.removeFirst()
            sum += A[cx.0][cx.1]
            check[cx.0][cx.1] = true
            
            for j in 0..<4{
                let nx = cx.0 + dx[j]
                let ny = cx.1 + dy[j]
                if nx < 0 || ny < 0 || nx >= N || ny >= N { continue }
                let sub = abs(A[cx.0][cx.1] - A[nx][ny])
                if !check[nx][ny] && sub >= l && sub <= r {// 1. 인구차이가 L명 이상, R명 이하라면, 국경선을 연다
                    check[nx][ny] = true
                    queue.append((nx,ny))
                    union.append((nx,ny))
                }
            }
        }
    }
    // 2. 인구이동 시작 - 연합
    if union.count >= 2 { //3. 각 칸의 인구수 - (연합의 인구수)/(연합을 이루는 칸의 개수)
        union.map { A[$0][$1] = sum/(union.count) }
        return true
    }
    return false
}

start()

