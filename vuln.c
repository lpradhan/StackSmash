//BEGIN:A program to illustrate buffer overflow vulnerability
//vuln.c
//  
//
//  Created by ligaj pradhan on 4/23/16.
//
//

#include <stdio.h>
#include <string.h>

//Usage: ./vuln ""

void func(char *str){
    char buffer[24];
    int *ret;

    /*    printf("Buffer = %p\n", buffer);
    ret = (int*) (buffer);
        
    while(1)
    {
      //int address = *ret;
      printf("%p\n", *ret);
      if(*ret == 0x400615)
      {
        printf("Hello");
        printf("Return address is stored at: %p. Value  = %p\n", ret, *ret);
        break;
      }
      ret = (int*) (((char*)ret) + 1);
      }*/

    ret = (int*) (buffer + 40);

    printf("\nCurrent return address: %p\n", *ret);
    
    *ret += (0x4005fe - 0x4005e8); 

    printf("Modified return address: %p\n", *ret);
    
    strcpy(buffer,str);
}


int main(int argc, char **argv){
    printf("Hello from C");
    int x;
    x = 0;
    func(argv[1]);
    x = 1;
    printf("x is 1");
    printf("x is 0\n");
}

//END
