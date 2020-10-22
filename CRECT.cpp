#include <stdio.h>
#include <algorithm>
#include <stack>
#include <string.h>
using namespace std;

#define maxN 500

char s[maxN][maxN];
int h[maxN];
long long num_rec[5][5][5];
int stk[maxN + 1];
long long F[maxN];
int m,n;

long long count_rec(char c1, char c2, char c3)
{
    if(num_rec[c1 - 'A'][c2 - 'A'][c3 - 'A'] != -1)
        return num_rec[c1 - 'A'][c2 - 'A'][c3 - 'A'];
    
    long long counter = 0;
    memset(h, 0, sizeof(h));
    for(int i = 0; i < m;i++)
    {
        for(int j = 0;j<n;j++)
        {
            if(s[i][j] == c1 || s[i][j] == c2 || s[i][j] == c3)
                h[j] += 1;
            else
                h[j] = 0;
        }
        int top = 0;
        stk[top] = n;
        F[n] = 0;
        for(int j = n - 1;j>=0;j--)
        {
            while(top > 0 && h[stk[top]] >= h[j]) top--;
            F[j] = h[j] * (stk[top] - j) + F[stk[top]];
            stk[++top] = j;
            counter  = counter + F[j];
        }
    }
    num_rec[c1 - 'A'][c2 - 'A'][c3 - 'A'] = counter;
    if(c1 == c2 && c2 != c3)
        num_rec[c3 - 'A'][c3 - 'A'][c1 - 'A'] = counter;
    return counter;
}

int main()
{
    scanf("%d%d",&m, &n);
    for(int i = 0;i < m;i++)
        scanf("%s", s[i]);
    memset(num_rec, 255, sizeof(num_rec));
    long long ans = 0;
    for(char c1 = 'A'; c1 < 'D';c1++)
    {
        for(char c2 = c1 + 1;c2 < 'E';c2++)
        {
            for(char c3 = c2 + 1; c3 < 'F';c3++)
            {
                ans = ans + count_rec(c1, c2, c3) - count_rec(c1, c1, c2) - count_rec(c1, c1, c3) - count_rec(c2, c2, c3) + count_rec(c1, c1, c1) + count_rec(c2, c2, c2) + count_rec(c3, c3, c3);
            }
        }
    }
    printf("%lld", ans);
}