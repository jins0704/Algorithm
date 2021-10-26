//
//  main.swift
//  17404_RGB거리2_Swift
//
//  Created by 홍진석 on 2021/10/26.
//

import Foundation

func solution(){
    var ans = 1000000
    let N = Int(readLine()!)!
    var arr = Array(repeating: Array(repeating: 0, count: 3), count: N)
    for i in 0..<N {
        let input = readLine()!.split(separator: " ").map{ Int(String($0))!}
        for j in 0..<3 { arr[i][j] = input[j] }
    }
    
    var dp = Array(repeating: Array(repeating: 0, count: 3), count: N)
    
    for color in 0..<3 { //choose first color
        for i in 0..<3 { //init
            if i == color { dp[0][i] = arr[0][i] }
            else { dp[0][i] = 1000000}
        }
        
        for i in 1..<N {
            for j in 0..<3 {
                dp[i][j] = arr[i][j] + min(dp[i-1][(j+1)%3], dp[i-1][(j+2)%3])
            }
        }
        
        for i in 0..<3 {
            if i == color { continue }
            ans = min(ans, dp[N-1][i])
        }
    }
    
    print(ans)
}

solution()
