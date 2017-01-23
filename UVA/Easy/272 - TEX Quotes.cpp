#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n = 1;
    char c;
    while( ( c = getchar() ) != EOF )
    {
        if( c == '"' )
        {
            if(n&1)
                cout << "``";
            else
                cout << "''";
            n++;
        }
        else
            cout << c;
    }
    return 0;
}
