#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    char c;
    while( ( c = getchar() ) != EOF )
    {
        if( c != '\n' )
            printf("%c", c-7);
        else
            cout << '\n';
    }
    return 0;
}
