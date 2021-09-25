//
//  main.swift
//  소수찾기
//
//  Created by 홍진석 on 2021/09/25.
//

import Foundation

var answer = Set<String>()

func isPrime(_ s : String) -> Bool {
    guard let num = Int(s) else { return false }
    let count = Int(sqrt(Double(num)))
    if num == 1 { return false }
    if count < 2 { return true }
    for i in 2 ... count{
        if num % i == 0 { return false }
    }
    return true
}

func dfs(_ arr : Array<Character>, _ size : Int, _ cnt : Int, _ s : inout String, _ set : inout Set<Int>) -> Void{
    if cnt == size {
        if !answer.contains(s){
            if isPrime(s){
                answer.update(with: s)
            }
        }
    }
    else{
        for i in 0..<arr.count{
            if !set.contains(i){
                if s.isEmpty && arr[i] == "0" { continue }
                s.append(arr[i])
                set.update(with: i)
                dfs(arr, size, cnt+1, &s, &set)
                s.removeLast()
                set.remove(i)
            }
        }
    }
}
func solution(_ numbers:String) -> Int {
    let arr = Array(numbers)
    var set = Set<Int>()
    for i in 1...numbers.count{
        var s : String = ""
        dfs(arr,i,0,&s,&set)
    }
    return answer.count
}

print(solution("011"))
