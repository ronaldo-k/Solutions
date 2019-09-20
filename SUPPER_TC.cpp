#include<stdio.h>
#include <algorithm>
using namespace std;
const int MAXN=112345,INF=1123456789;
int dp[MAXN],dpi[MAXN],v[MAXN];
int mk1[MAXN],mk2[MAXN],resp[MAXN],dpe[MAXN],dpd[MAXN];

int main()
{
	int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&v[i]);
    dp[0]=0;
    for(int i=1;i<=n;i++)dp[i]=INF;
    int mx=0;
    for(int i=0;i<n;i++)
    {
        int id=lower_bound(dp,dp+n+1,v[i])-dp;
        dp[id]=v[i];
        mk1[i]=id;
        mx=max(mx,id);
    }
    dpi[0]=-INF;
    for(int i=1;i<=n;i++)dpi[i]=INF;
    for(int i=n-1;i>=0;i--)
    {
        v[i]*=-1;
        int id=lower_bound(dpi,dpi+n+1,v[i])-dpi;
        //printf("%d %d %d\n",id,dpi[id],dp[id+1]);
        dpi[id]=v[i];
        mk2[i]=id;
    }

	printf("DPI:\n");

	for(int i = 0; i < n; i++) {
		printf("%d ", dp[i]);
	}

	printf("\nDPD:\n");

	for(int i = 0; i < n; i++) {
		printf("%d ", dpi[i]);
	}
}
