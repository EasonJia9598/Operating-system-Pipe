//
//  main.cpp
//  de
//
//  Created by WillJia on 2018-09-25.
//  Copyright © 2018 WillJia. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <string.h>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <array>
#include <ctime>


using namespace std;

int main(int argc, char *argv[]) {
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    int n = 0;
//    for (int i = 0; i < a.size(); i++) {
//        cout << "size "<<a.size() << endl;
//        cout << a[i] << " ";
//    }
//    cout << endl;
//
    while (true) {
        cin >> n;
        
        for (int i = 0; i < (int)a.size(); i++) {
            if (a[i] < n) {
                a.erase(a.begin()+i);
                i--;
            }
        }
        
        for (int i = 0; i < a.size(); i++) {
            //            cout << "size "<<a.size() << endl;
            cout << a[i] << " ";
        }
        cout << endl;
        cout << endl;
    }
  


//    a.erase(a.begin()+3);
//
//    for (int i = 0; i < a.size(); i++) {
//        cout << "size "<<a.size() << endl;
//        cout << a[i] << " ";
//    }
//
    

    
}
