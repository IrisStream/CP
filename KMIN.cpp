#include <stdio.h>
#include <algorithm>
#include <deque>
using namespace std;

#define ii pair<int,int>
#define fi first
#define se second
#define mp make_pair

void process()
{
    int n,k;
    scanf("%d%d",&n,&k);
    deque<ii> dq;
    for(int i = 0;i<n;i++){
        int cur;
        scanf("%d",&cur);
        while(!dq.empty() && dq.back().se >= cur) dq.pop_back();
        dq.push_back(mp(i, cur));
        if(i >= k && dq.front().fi <= i - k)
            dq.pop_front();
        if(i >= k - 1)
            printf("%d ", dq.front().se);
    }
    printf("\n");
}

int main()
{
    int test;
    scanf("%d", &test);
    while(test--)
        process();
    return 0;
}
