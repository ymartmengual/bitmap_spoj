#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cctype>

using namespace std;

bool EsCeroUno( char cadena[182], int m)
{
    for( int x = 0; x < m; x++ )
    {
        if( cadena[x] < '0' || cadena[x] > '1' )
            return false;
    }

    return true;
}

bool EsUnNumero(const string& cadena)
{
    for(char c : cadena )
    {
        if( !std::isdigit(c) )
            return false;
    }
    return true;
}

bool CreateBitmapSize(int &n, int &m){
    std::string mm,nn;
    std::getline(std::cin, mm);
    size_t pos = 0;
    char ch = ' ';

    if(std::count(mm.begin(), mm.end(), ch) != 1)
        return false;

    pos = mm.find(ch);
    nn = mm.substr(0, pos);
    mm.erase(0, pos + sizeof(ch));

    if(!EsUnNumero(nn) && !EsUnNumero(mm))
        return false;

    n = stoi(nn);
    m = stoi(mm);

    return true;
}

int main()
{
    int t,i,j,c;
    int n = 0;
    int m = 0;
    char input[182][182];

    if(scanf("%d", &t) != 1)
        return 0;

    while(t--)
    {
        printf("\n");
        CreateBitmapSize(n, m);

        while (!(1 <= n && n <= 182 && 1 <= m && m <= 182)) {
            if(CreateBitmapSize(n, m))
                break;
        }

        for(i = 0; i < n ; i++)
        {
            scanf("%s",input[i]);

            while(!EsCeroUno(input[i], m)){
                scanf("%s",input[i]);
            }
        }

        for(i = 0; i < n; i++)
        {
            for(j = 0; j < m; j++)
            {
                if(j != 0)
                {
                    printf(" ");
                }
                if(input[i][j] == '1')
                {
                    printf("0");
                }
                else
                {
                    int buff = 0;
                    bool f = false;
                    for(c = 0; c <= n; c++)
                    {
                        if(input[i][c] == '1')
                        {
                            int res = abs(j-c);
                            if(!f){
                                buff = res;
                                f = true;
                            }else if(res < buff){
                                buff = res;
                            }
                        }
                        if(c == n)
                            printf("%d",buff);
                    }
                }
            }
            printf("\n");
        }
    }
    return 0;
}
