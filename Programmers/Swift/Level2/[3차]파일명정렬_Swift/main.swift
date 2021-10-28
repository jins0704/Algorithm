//
//  main.swift
//  [3차]파일명정렬_Swift
//
//  Created by 홍진석 on 2021/10/21.
//

import Foundation

struct fileInfo {
    var name : String
    var idx : Int
    var HEAD : String
    var NUMBER : Int
}

func solution(_ files:[String]) -> [String] {
    
    var fileData : [fileInfo] = []
    
    for i in 0..<files.count {
        var str = Array(files[i])
        var index = 0
        var headCheck = false
        var numCheck = false
        
        while(index < str.count){
            if(!headCheck){
                if str[index].isNumber {
                    str.insert("~", at: index)
                    index += 1
                    headCheck = true
                }
            }
            else if(!numCheck){
                if !str[index].isNumber {
                    str.insert("~", at: index)
                    index += 1
                    numCheck = true
                }
            }
            index += 1
        }
        
        let s = String(str).split(separator: "~")
        fileData.append(fileInfo(name: files[i], idx: i, HEAD: String(s[0].lowercased()), NUMBER: Int(s[1])!))
    }
    
    fileData.sort { a, b in
        if a.HEAD == b.HEAD {
            if a.NUMBER == b.NUMBER { return a.idx < b.idx }
            else{ return a.NUMBER < b.NUMBER }
        }
        else{ return a.HEAD < b.HEAD }
    }
    
    return fileData.map({$0.name})
}

