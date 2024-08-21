#include <stdio.h> 
#include <stdlib.h> 



struct MyStruct {
    int i; 
    double d; 
    char a[5];
};


int main() 
{
    int a = 0;
    int *b = &a;
    printf("address=%p, value=%d\n", b, *b);
    int *p = (int*)malloc(3*sizeof(int));
    printf("address=%p, value=%d\n", p, *p);


    MyStruct *p1 = (MyStruct*)calloc(4,sizeof(MyStruct));
    p1[0].i = 1; p1[0].d = 3.14159; p1[0].a[0] = 'a';
    
    return 0; 
}