//
//  NetworkResult.swift
//  Swift_For_RESTAPI
//
//  Created by 홍진석 on 2021/09/23.
//

import Foundation
import Alamofire

enum NetworkResult<T> {
    case success(T)
    case paramErr
    case authErr
    case serverErr
}
