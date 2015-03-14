#include <stdio.h>
#include <string.h>


int main(int argc, char * argv[])
{
    int sum=0;
    int i, len;

    len=strlen(argv[1]);

    printf("arg: %s\n", argv[1]);
    printf("len: %d\n", len);

    for (i=0;i<len;i++)
    {
        sum ^= argv[1][i];
    }
    printf("Sum: 0x%02x\n", sum);
    return 0;
}
