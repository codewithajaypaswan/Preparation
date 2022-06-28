// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// Function to return maximum XOR subset in set[]

class Solution
{
    public:
    int maxSubarrayXOR(int arr[], int N)
    {
        int index = 0;
        for(int i=31; i>=0; i--) {
            int flag = 0, cur;
            for(int j=index; j<N; j++) {
                if(arr[j]&(1<<i)) {
                    flag = 1;
                    cur = j;
                    break;
                }
            }
            if(!flag) continue;
            for(int j=0; j<N; j++) {
                if(j != cur && (arr[j] & (1<<i))) {
                    arr[j] ^= arr[cur];
                }
            }
            swap(arr[cur], arr[index]);
            index++;
        }
        int ans = 0;
        for(int i=0; i<N; i++) ans ^= arr[i];
        return ans;
    }
};

// { Driver Code Starts.
int main()
{

    int t,n,a[100004],k;
    scanf("%d",&t);
    while(t--)
    {
        //cin>>n;
       scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        Solution obj;
        printf("%d\n",obj.maxSubarrayXOR(a,n));
       // cout<<bin(a,0,n-1,k)<<endl;
    }
}  // } Driver Code Ends