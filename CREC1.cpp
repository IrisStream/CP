#include <stdio.h>
#include <algorithm>
#include <stack>
#include <string>
#include <iostream>
using namespace std;

#define maxN 1000

int a[maxN];
int rec[maxN + 1];

int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    long long ans = 0;
    for(int i = 0;i < m;i++)
    {
        string s1;
        cin >> s1;
        for(int j = 0;j < s1.size();j++)
        {
            if(s1[j] == '0')
                a[j] = 0;
            else
                a[j] = a[j] + 1;
        }

        stack<int> s;
        s.push(n);
        for(int j = n - 1;j>=0;j--)
        {
            while(s.size() > 1 && a[s.top()] >=a[j]) s.pop();
            rec[j] = (s.top() - j) * a[j] + rec[s.top()];
            ans = ans + rec[j];
            s.push(j);
        }
    }
    printf("%lld\n", ans);
    return 0;
}