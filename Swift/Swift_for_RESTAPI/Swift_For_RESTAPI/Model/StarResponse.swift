//
//  StarResponse.swift
//  Swift_For_RESTAPI
//
//  Created by 홍진석 on 2021/09/23.
//

import Foundation

struct StartResponse : Codable {
    let auth_key: String
    let problem: Int?
    let time : Int?
}
