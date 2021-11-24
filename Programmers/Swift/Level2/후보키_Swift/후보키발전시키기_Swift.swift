//
//  main.swift
//  test
//
//  Created by 홍진석 on 2021/11/24.
//

import Foundation

var result = [[Int]]()

func combination(_ i : Int, _ attLen : Int, _ attCombi : inout [Int]) {
    if attCombi.count == i {
        result.append(attCombi)
    }
    else{
        for idx in 0..<attLen {
            if !attCombi.isEmpty && attCombi.last! < idx { continue }
            attCombi.append(idx)
            combination(i, attLen, &attCombi)
            attCombi.removeLast()
        }
    }
}

func solution(_ relation:[[String]]) -> Int {
    let attLen = relation[0].count
    var keys = [Set<Int>]()

    for i in 1...attLen {
        var attCombi = [Int]()
        
        result = [[Int]]()
        combination(i, attLen, &attCombi)
        
        loop : for j in result {
            var uniqueKey = Set<String>()
            var uniqueCandidateKey = Set<Int>()
            
            for r in relation {
                let s = r.enumerated().filter { j.contains($0.offset) }.map { $0.element }.reduce("") { $0 + $1 }
                if(uniqueKey.contains(s)) { continue loop }
                else {uniqueKey.insert(s)}
            }
            
            j.map { uniqueCandidateKey.insert($0) }
            if uniqueCandidateKey.count == 0 { continue }
            
            for k in keys{
                if k.isSubset(of: uniqueCandidateKey) { continue loop }
            }
            
            keys.append(uniqueCandidateKey)
        }
    }
    
    return keys.count
}

