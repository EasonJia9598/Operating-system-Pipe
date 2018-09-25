//
//  main.cpp
//  de
//
//  Created by WillJia on 2018-09-25.
//  Copyright © 2018 WillJia. All rights reserved.
//

#include <iostream>

#include <stdio.h>
int main(int argc, char *argv[]) {
    int a = 10;
    void *b = &a;
    *(int*)b = 2;
    printf("%d",a);
}
