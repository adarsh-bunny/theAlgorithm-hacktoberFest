// Problem Name-Trapping Rain water
// Given an array arr[] of N non-negative integers representing the height of blocks. If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season. 
// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends

class Solution{

    // Function to find the trapped water between the blocks.
    public:
    int trappingWater(int arr[], int n)
    {
        int maxright[n],maxleft=arr[0],water=0;
        maxright[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--)
        {
            maxright[i]=max(maxright[i+1],arr[i]);
        }
        
        for(int i=1;i<n-1;i++)
        {
            if(maxleft<arr[i])
                maxleft=arr[i];
            water=water+min(maxright[i],maxleft)-arr[i];
           
        }
        
       return water; 
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends