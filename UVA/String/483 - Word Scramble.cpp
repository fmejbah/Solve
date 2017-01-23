#include <bits/stdc++.h>

void rev( char s[] )
{
    if(s[0]=='\0') return;
    rev(&s[1]);
    printf("%c", s[0]);
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    char s[200], c;

    while( scanf("%s", s) == 1 )
    {
        rev(s);
        c = getchar();
        if( c != EOF )
        printf("%c", c);
    }
}
