//
//  main.swift
//  Swift_for_Collection
//
//  Created by 홍진석 on 2021/09/22.
//

import Foundation

var s : Set = ["A"] //Set
s.insert("b")

var m = Dictionary<String, Int>() //Map
m.updateValue(200, forKey: "A")
m.updateValue(100, forKey: "B")

if m["A"] == nil{ print("no") }
else{ print("yes") }

typealias peoeple = (String,Int) //Pair
var b = [1,2,3,4,53,2,1]
var c : [peoeple] = []
b.sort()
c.append(contentsOf: [("sdf",245),("22f",24),("22f",24)])

print(c.sorted{ a, b in  //Custom Sort
    if a.0 == b.0 { return a.1 > b.1 }
    else{ return a.0 < b.0 }
})

for (n,m) in c.enumerated() { //FOR 반복
    print("\(n) and \(m.0) and \(m.1)")
}

var mapInArray = Dictionary<String,[(Int,Int)]>() //map 안에 배열
mapInArray.updateValue([], forKey: "A")
mapInArray["A"]?.append((1,2))

var pq = PriorityQueue<Int>() { //Priority Queue
    return $0 <= $1
}
pq.push(3)
pq.push(4)
pq.push(1)
while(!pq.isEmpty()){
    print(pq.pop()!)
}
