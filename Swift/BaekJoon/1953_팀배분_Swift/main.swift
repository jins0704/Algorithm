//
//  main.swift
//  팀배분_Swift
//
//  Created by 홍진석 on 2021/11/12.
//

import Foundation

func solution(){
    let n = Int(readLine()!)!
    var check : [Int] = Array(repeating: 0, count: n+1)
    var hateData = [[Int]]()
    
    for _ in 0..<n {
        var info : [Int] = readLine()!.split(separator: " ").map{ Int($0)! }
        if info.count>=1 { info.removeFirst() }
        hateData.append(info)
    }
    
    var num = 1
    
    for i in 0..<hateData.count{
        if check[i+1] != 0 { continue }
        var queue = [i+1]
        check[i+1] = num
        while(!queue.isEmpty){
            let cx = queue.removeFirst()
            for j in hateData[cx-1] {
                if check[j] == 0 {
                    queue.append(j)
                    check[j] = -check[cx]
                }
            }
        }
        
        num = -num

    }
    
    let a = check.indices.filter { check[$0] == 1 }
    let b = check.indices.filter { check[$0] == -1 }
    print(a.count)
    for i in a { print(i, terminator:  " ") }
    print("")
    print(b.count)
    for i in b { print(i, terminator:  " ") }

}

solution()
