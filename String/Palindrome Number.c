bool isPalindrome(int x)
{
    char nn[100];

    sprintf(nn,"%d",x);

    int size = strlen(nn);

    for(int i = 0,j = size - 1;i < j;i++,j--)
    {
        if(nn[i] != nn[j]) return false;
    }

    return true;
}
