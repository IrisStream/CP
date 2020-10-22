#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stack>
using namespace std;

#define maxN 1010

int h[maxN][maxN];
int a[maxN];
int L[maxN];
int R[maxN];
int stk[maxN];

int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    for(int i = 0;i<m;i++)
    {
        for(int j = 0;j<n;j++)
        {
            scanf("%d",&h[i][j]);
        }
    }

    int ans = 1;
    for(int i = 0;i < m;i++)
    {
        int cur = 1;
        for(int j = 1;j < n;j++)
        {
            if(h[i][j] >= h[i][j-1])
                cur++;
            else
            {
                ans = max(ans, cur);
                cur = 1;
            }
        }
        ans = max(ans, cur);
    }

    for(int j = 0;j<n;j++)
    {
        int cur = 1;
        for(int i = 1;i < m;i++)
        {
            if(h[i][j] >=h[i-1][j])
                cur++;
            else
            {
                ans = max(ans, cur);
                cur = 1;
            }
        }
        ans = max(ans, cur);
    }
    
    memset(a, 0, sizeof(a));

    for(int i = 1; i<m;i++)
    {
        for(int j = 1;j<n;j++)
        {
            if(h[i][j] >= h[i][j-1] && h[i][j] >= h[i-1][j] && h[i-1][j] >= h[i-1][j-1] && h[i][j-1] >= h[i-1][j-1])
                a[j] += 1;
            else 
                a[j] = 0;
        }
        int top = 0;
        stk[top] = 0;
        for(int j = 1;j < n;j++)
        {
            while(top > 0 && a[stk[top]] >= a[j]) top--;
            L[j] = stk[top] + 1;
            stk[++top] = j;
        }

        top = 0;
        stk[top] = n;
        for(int j = n - 1;j >= 1;j--)
        {
            while(top > 0 && a[stk[top]] >= a[j]) top--;
            R[j] = stk[top] - 1;
            stk[++top] = j;
        }

        for(int j = 1;j < n;j++)
        {
            ans = max(ans, (a[j]+1) * (R[j] - L[j] + 2));
        }
    }
    printf("%d", ans);

    return 0;
}