#include <stdio.h>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

#define maxN 30000
#define ii pair<int, int>
#define fi first
#define se second
#define mp make_pair

int a[maxN];
int L[maxN];
int R[maxN];

void process()
{
    int n;
    scanf("%d", &n);
    stack<int> s1;
    s1.push(-1);
    for(int i = 0;i<n;i++)
    {
        scanf("%d", a + i);
        while(s1.size() > 1 && a[s1.top()] >= a[i]) s1.pop();
        L[i] = s1.top() + 1;
        s1.push(i);
    }

    stack<int> s2;
    s2.push(n);
    for(int i = n - 1;i>=0;i--)
    {
        while(s2.size() > 1 && a[s2.top()] >= a[i]) s2.pop();
        R[i] = s2.top() - 1;
        s2.push(i);
    }

    int ans = 0;
    int low, high;
    for(int i = 0;i<n;i++)
    {
        if(ans < a[i] * (R[i] - L[i] + 1))
        {
            ans = a[i] * (R[i] - L[i] + 1);
            low = L[i];
            high = R[i];
        }
    }

    printf("%d %d %d\n", ans, low + 1, high + 1);
}

int main()
{
    int test;
    scanf("%d", &test);
    while(test--)
    {
        process();
    }
    return 0;
}