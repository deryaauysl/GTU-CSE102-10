#include <stdio.h>
#include <string.h>

void int_to_binary(int decimal, char *binary)
{
    int i;
    for (i = 7; i >= 0; i--)
    {
        binary[i] = (decimal & 1) + '0';
        decimal >>= 1;
    }
    binary[8] = '\0';

    int j = 0;
    printf("Binary (inttobin)");
    for (j = 0; j < 8; j++)
    {
        printf("%c", binary[j]);
    }
    printf("\n");
}

int binary_to_int(const char *binary)
{
    int decimal = 0;
    int base = 1;
    int len = strlen(binary);
    int i = 0;

    for (i = len - 1; i >= 0; i--)
    {
        if (binary[i] == '1')
        {
            decimal += base;
        }
        base *= 2;
    }
    printf("Decimal (bintoint):%d \n", decimal);
    return decimal;
}

int main()
{
    char binary[9] = "11111111";
    int decimal = 255;

    int a = 3;

    a >>= 1;

    printf("%d\n", a);

    binary_to_int(binary);
    int_to_binary(decimal, binary);
}