//
//  main.cpp
//  generateInputFiles
//
//  Created by WillJia on 2018-10-04.
//  Copyright © 2018 WillJia. All rights reserved.
//

#include <iostream>
#include <algorithm>    // std::sort
#include <fstream>
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
#include <ctime>

/************************************************************************
 
 Function:        generateInputFiles
 
 Description:     sleep 10 ms
 
 *************************************************************************/
void generateInputFiles(){
    printf("Genrate new 5 input_* files\n");
    
    srand((int)time(NULL));
    int index = 0 , count = 0;
    vector<int> array;
    
    int numbers[100];
    for (int i = 1; i < 101; i++) {
        numbers[i] = i;
    }
    
    while (true) {
        index = rand() % 100 + 1;
        if (numbers[index] != 0) {
            array.push_back(numbers[index]);
            numbers[index] = 0;
            count++;
        }
        if (count > 25) {
            break;
        }
    }
    
    sort(array.begin(), array.end());
    
    string values[5];
    int stringIndex = 0;
    
    for (int i = 1; i < 26 ;i++){
        
        values[stringIndex].append(to_string(array[i - 1]));
        values[stringIndex].append(" ");
        if (i % 5 == 0) {
            stringIndex++;
        }
        
    }
    
    for (int i = 0; i < 5; i++) {
        printf("%s \n" , values[i].c_str());
    }
    
    string path = "/Users/WillJia/Documents/Pipe/median/input_";
    for(int i = 1 ; i < 5 ; i++){
        ofstream myfile;
        myfile.open(path+to_string(i+1) + ".txt");
        myfile << values[i];
        myfile.close();
        
    }
    
    printf("\n");
    
}

int main(){
    generateInputFiles();
}
