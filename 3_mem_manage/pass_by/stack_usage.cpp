#include <stdio.h>
    
void CallByValue(long i)
{
    long j = 1; 
    printf ("call-by-value: \t\t%p\n",&j);
}

void CallByPolonger(long *i)
{
    long j = 1; 
    printf ("call-by-polonger: \t%p\n",&j);
}

void CallByReference(long &i)
{
    long j = 1; 
    printf ("call-by-reference: \t%p\n",&j);
}

int main()
{
    long i = 0;
    printf ("stack bottom: \t\t%p\n",&i);
    
    CallByValue(i);

    CallByPolonger(&i);

    CallByReference(i);

    return 0;
}
