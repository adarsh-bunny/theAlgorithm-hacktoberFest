#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    
    int maxSubarraySum(int arr[], int n)
    {
        //O(n2) approach
        // int maxsum=arr[0];
        // for(int j=0;j<n;j++)
        // {
        //     int currsum=0;
        
        //     for(int i=j;i<n;i++)
        //     {
        //         currsum=currsum+arr[i];
        //         if(currsum>maxsum)
        //         {
        //             maxsum=currsum;
        //         }
        //     }
        // }
        
         // Now implementing O(n) approach
        
        
        int maxsum=arr[0];
        int res=arr[0];
        for(int i=1;i<n;i++)
        {
            maxsum=max(arr[i],arr[i]+maxsum);
            res=max(res,maxsum);
            
        }

        
      return res; 
    }
    
   
    
};

// { Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}