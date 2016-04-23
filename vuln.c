//BEGIN:A program to illustrate buffer overflow vulnerability
//vuln.c
//  
//
//  Created by ligaj pradhan on 4/23/16.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void func(char *str){
    char buffer[24];
    int *ret;
    strcpy(buffer,str);
}

void function(){
    char buffer1[4];
    int *ret;
    ret =(int*) ( buffer1+8);
    (*ret) += 8;
}

void main(){
    int x = 0;
    function();
    x = 1;
    printf("%d\n",x);
}

/*
int main(int argc, char **argv){
    printf("Hello from C");
    int x;
    x = 0;
    func(argv[1]);
    x = 1;
    printf("x is 1");
    printf("x is 0");
}
 */

//END
