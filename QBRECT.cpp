#include <stdio.h>
#include <algorithm>
#include <stack>
using namespace std;

#define maxN 1000
int a[maxN];
int L[maxN];
int R[maxN];

int main()
{
    int m,n;
    int ans = 0;
    scanf("%d%d",&m, &n);
    for(int i = 0;i < m;i++)
    {
        for(int j = 0;j < n;j++)
        {
            int tmp;
            scanf("%d",&tmp);
            if(tmp == 1)
                a[j] = a[j] + 1;
            else
                a[j] = 0;
            
        }

        stack<int> s1;
        s1.push(-1);
        for(int j = 0;j < n;j++)
        {
            while(s1.size() > 1 && a[s1.top()] >= a[j]) s1.pop();
            L[j] = s1.top() + 1;
            s1.push(j);
        }

        stack<int> s2;
        s2.push(n);
        for(int j = n - 1;j >= 0;j--)
        {
            while(s2.size() > 1 && a[s2.top()] >= a[j]) s2.pop();
            R[j] = s2.top() - 1;
            s2.push(j);
        }
        
        for(int j = 0;j < n;j++)
        {
            ans = max(ans, a[j] * (R[j] - L[j] + 1));
        }
    }
    printf("%d", ans);
    return 0;
}