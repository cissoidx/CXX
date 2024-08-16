#include <stdio.h>
    
void CallByValue(long double i)
{
    int j = 1; 
    printf ("call-by-value: \t\t%p\n",&j);
}

void CallByPointer(long double *i)
{
    int j = 1; 
    printf ("call-by-pointer: \t%p\n",&j);
}

void CallByReference(long double &i)
{
    int j = 1; 
    printf ("call-by-reference: \t%p\n",&j);
}

int main()
{
    long double i = 0;
    printf ("stack bottom: \t\t%p\n",&i);
    
    CallByValue(i);

    CallByPointer(&i);

    CallByReference(i);

    return 0;
}
