#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;


int main()
{
    int t,i,j,c,n,m;

    scanf("%d", &t);
    string outp = "";

    while (t--)
    {
        char inp[183][183];

        scanf("%d %d\n",&n,&m);

        for(i = 0; i < n ; i++)
        {
            scanf("%s",inp[i]);
        }

        for(i = 0; i < n; i++)
        {
            for(j = 0; j < m; j++)
            {
                if(j != 0)
                {
                    outp.append( " ");
                }
                if(inp[i][j] == '1')
                {
                    outp.append( "0");
                }
                else
                {
                    int buff = 0;
                    bool f = false;
                    for(c = 0; c <= n; c++)
                    {
                        if(inp[i][c] == '1')
                        {
                            int res = abs(j-c);
                            if(!f){
                                buff = res;
                                f = true;
                            }else if(res < buff){
                                buff = res;
                            }
                        }
                        if(c == n){
                            outp.append(std::to_string(buff));
                        }
                    }
                }
            }
            outp.append("\n");
        }
    }
    cout << outp << endl;
    return 0;
}
