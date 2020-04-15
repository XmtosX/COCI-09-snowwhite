#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
const int N=3e5+5;
int n,m,c,a[N],sq=300,l,r,cnt[10004],ans[10004];
pair<pair<int,int>, int> p[N];
bool cmp (pair<pair<int,int>,int> p1, pair<pair<int,int>,int> p2)
{
    if (p1.F.F/sq==p2.F.F/sq)
        return p1.F.S<p2.F.S;
    return p1.F.F<p2.F.F;
}
int main()
{
    scanf("%d%d",&n,&c);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&m);
    for (int i=0;i<m;i++)
    {
        scanf("%d%d",&p[i].F.F,&p[i].F.S);
        p[i].F.F--;
        p[i].F.S--;
        p[i].S=i;
    }
    sort(p,p+m,cmp);
    cnt[a[0]]++;
    for (int q=0;q<m;q++)
    {
        int L=p[q].F.F;
        int R=p[q].F.S;
        int idx=p[q].S;
        while (l>L)
        {
            l--;
            cnt[a[l]]++;
        }
        while (l<L)
        {
            cnt[a[l]]--;
            l++;
        }
        while (r<R)
        {
            r++;
            cnt[a[r]]++;
        }
        while (r>R)
        {
            cnt[a[r]]--;
            r--;
        }
        int cur=0;
        for (int i=0;i<30;i++)
        {
            int x= (rand()%(r-l+1));
            x+=l;
            if (cnt[a[x]]>(r-l+1)/2)
            {
                cur=a[x];
                break;
            }
        }
        if (cur)
            ans[idx]=cur;
    }
    for (int i=0;i<m;i++)
    {
        if (ans[i])
            printf("yes %d\n",ans[i]);
        else
            printf("no\n");
    }
    return 0;
}
