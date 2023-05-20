#include <stdio.h>

int main()
{
    int k;
    int flag;
    int vet[5];

    scanf("%d",&k);

    for (int i = 0;i < 5;i++)
        scanf("%d",&vet[i]);

    for (int i = 0;i < 5;i++)
    {
        if(vet[i] == k)
        {
            flag = i;
            break;
        }
    }

    printf("%d",flag);

    return 0;
}