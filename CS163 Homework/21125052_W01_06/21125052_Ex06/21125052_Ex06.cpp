#include <iostream>
using namespace std;
int main()
{
    int n; cin>>n;
    int a[3];
    for (int i=0; i<n;++i)
    {
        cin >>a[0] >>a[1]>>a[2];
        int sum=a[0]+a[1]+a[2];
        if (sum%9==0)
        {
            int t=sum/9;
            if (a[0]>=t && a[1]>=t && a[2]>=t)
            cout <<"YES" <<endl;
            else cout <<"NO" <<endl;
        }
        else cout <<"NO" <<endl;
    }
    return 0;
}