#include <stdio.h>
#include <math.h>

int BinaryToDecimal(long long n)
{
    int dec = 0, i = 0, rem;

    while (n != 0)
    {
        rem = n % 10;
        n /= 10;
        dec += rem * pow(2, i);
        ++i;
    }

    return dec;
}

long long OctalToDecimal(long long n)
{
    long long decimalNumber = 0, i = 0;

    while (n != 0)
    {
        decimalNumber += (n % 10) * pow(8, i);
        ++i;
        n /= 10;
    }

    i = 1;

    return decimalNumber;
}

// void HexadecimalToDecimal(char hexa[])
// {

// }

int main()
{
    while (1)
    {
        long long int n;
        int x, res;

        printf("Please Choose the Option from below\n1. Binary To Decimal\n2. Octal To Decimal\n3. Hexadecimal To Decimal\n4. Exit\n");
        scanf("%d", &x);

        switch (x)
        {
        case 1:
            printf("Enter the Binary Number\n");
            scanf("%ld", &n);

            res = BinaryToDecimal(n);
            printf("Decimal: %d", res);
            break;

        case 2:
            printf("Enter the Octal Number\n");
            scanf("%ld", &n);
            long long ff = OctalToDecimal(n);
            printf("Decimal Number: %ld", ff);
            break;

        case 4:
            printf("Exitting....");
            return 0;

        default:
            printf("\nPlease Choose the Valid Input.\n");
            break;
        }
    }

    return 0;
}