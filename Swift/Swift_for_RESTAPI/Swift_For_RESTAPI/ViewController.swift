//
//  ViewController.swift
//  Swift_For_RESTAPI
//
//  Created by 홍진석 on 2021/09/23.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        start()
    }

    func start(){
        let p : Problem = Problem(problem: 1)
        APIService.shared.startService(problem: p) { response in
            guard let result = response as? NetworkResult<Any> else { return }
            
            switch result {
            case .success(let data):
                guard let startResponse = data as? StartResponse else { return }
                print(startResponse)
            case .authErr, .paramErr, .serverErr : print("") }
        }
    }
}

