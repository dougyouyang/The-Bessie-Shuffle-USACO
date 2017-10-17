//  Copyright © 2017 Dougy Ouyang. All rights reserved.

#include <iostream>

using namespace std;
int pattern[21][100001], patternow[100001], patternkeep[1000001], inipo[100001], pokeep[100001], ans[100001], s=0;

int power(int a)
{
    int n=1, i;
    for(i=1;i<=a;i++)
        n*=2;
    return n/2;
}

int main()
{
    int m, n, q, flip;
    int i, j;
    
    cin >> m >> n >> q;
    for(i=1;i<=m;i++)
        inipo[i]=i;
    flip=m-n+1;
    for(i=1;i<=n;i++){
        int input;
        cin >> input;
        input--;
        if(input==0)
            input=m;
        patternow[i]=input, pattern[1][input]=i;
    }
    for(i=n+1;i<=m;i++)
        patternow[i]=i-1, pattern[1][i-1]=inipo[i];
    
    for(i=2;i<=20;i++){
        for(j=1;j<=m;j++)
            pattern[i][patternow[j]]=pattern[i-1][j], patternkeep[j]=patternow[patternow[j]];
        for(j=1;j<=m;j++)
            patternow[j]=patternkeep[j];
    }
    i=20;
    while(i>0){
        if(flip/power(i)!=0){
            for(j=1;j<=m;j++)
                pokeep[j]=inipo[pattern[i][j]];
            for(j=1;j<=m;j++)
                inipo[j]=pokeep[j];
            flip-=power(i);
        }
        i--;
    }
    for(i=n;i<=m;i++)
        ans[++s]=inipo[i];
    for(i=1;i<n;i++)
        ans[++s]=inipo[i];
    
    for(i=1;i<=q;i++){
        int input;
        cin >> input;
        cout << ans[m-input+1] << endl;
    }
    
    return 0;
}
