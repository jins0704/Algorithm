//
//  main.swift
//  후보키_Swift

import Foundation

var result = [[Int]]()
func candidateKey(_ i : Int, _ Arr : Array<Int>, _ Check : Array<Bool>) {
    var arr = Arr
    var check = Check
    if arr.count == i {
        result.append(arr)
    }
    else{
        for idx in 0..<check.count {
            if !check[idx] {
                if !arr.isEmpty && arr[arr.count-1] > idx { continue }
                arr.append(idx)
                check[idx] = true
                candidateKey(i, arr, check)
                check[idx] = false
                arr.removeLast()
            }
        }
    }
}
func solution(_ relation:[[String]]) -> Int {
    let attributeSize = relation[0].count
    var keyArr = [Set<Int>]()

    for i in 1...attributeSize {//attribute 개수)
        candidateKey(i,Array<Int>(),Array<Bool>(repeating: false, count: attributeSize))
        var uniqueCandidateKey = Set<Int>()
        
        for j in result {
            var uniqueKey = Set<String>()
            var check = true
            for r in relation {
                var s = ""
                for k in j { s += r[k] }
                if(uniqueKey.contains(s)) { check = false }
                else {uniqueKey.insert(s)}
            }
            if(check) {
                for k in j { uniqueCandidateKey.insert(k) }
            }
            
            if uniqueCandidateKey.count == 0 { continue }
            
            var unique = true
            for k in keyArr{
                if k.isSubset(of: uniqueCandidateKey) {
                    unique = false; break;
                }
            }
            if unique { keyArr.append(uniqueCandidateKey) }
            uniqueCandidateKey.removeAll()
        }
        result.removeAll()
    }
    
    return keyArr.count
}

var relation : [[String]] = [["100","ryan","music","2"],["200","apeach","math","2"],["300","tube","computer","3"],["400","con","computer","4"],["500","muzi","music","3"],["600","apeach","music","2"]]

print(solution(relation))

