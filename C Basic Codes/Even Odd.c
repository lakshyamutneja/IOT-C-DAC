//
//  Even Odd.c
//  CDAC C LANGUAGE
//
//  Created by Lakshya Mutneja on 28/05/19.
//  Copyright © 2019 Lakshya Mutneja. All rights reserved.
//

#include <stdio.h>
int main()
{
    int number;
    
    printf("Enter an integer: ");
    scanf("%d", &number);
    
    // True if the number is perfectly divisible by 2
    if(number % 2 == 0)
        printf("%d is even.", number);
    else
        printf("%d is odd.", number);
    
    return 0;
}

