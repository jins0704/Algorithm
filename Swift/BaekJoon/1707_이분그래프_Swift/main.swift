//
//  main.swift
//  1707_이분그래프_Swift
//
//  Created by 홍진석 on 2021/10/26.
//

import Foundation

func checkBinaryGraph(_ edge : [Set<Int>]) -> Void {
    var check : Array<Int> = Array(repeating: 0, count: edge.count+1)
    var queue = Array<Int>()
    
    for i in 1..<edge.count{
        if check[i] != 0 { continue }
        check[i] = 1
        queue = [i]
        
        while(!queue.isEmpty){
            let cx = queue.removeFirst()
            
            for v in edge[cx]{
                if check[v] == 0 {
                    check[v] = -check[cx]
                    queue.append(v)
                }
                else {
                    if check[v] == check[cx] {
                        print("NO"); return
                    }
                }
            }
        }
    }
    print("YES")
}

func solution() -> Void {
    let K = Int(readLine()!)
    for _ in 0..<K! {
        let arr = readLine()!.split(separator: " ").map({ Int(String($0))! })
        let V = arr[0]; let E = arr[1]
     
        var edge : [Set<Int>] = Array(repeating: [], count: V + 1)

        for _ in 0..<E {
            let input = readLine()!.split(separator: " ").map({ Int(String($0))! })
            edge[input[0]].insert(input[1])
            edge[input[1]].insert(input[0])
        }
        
        checkBinaryGraph(edge)
    }
}

solution()
