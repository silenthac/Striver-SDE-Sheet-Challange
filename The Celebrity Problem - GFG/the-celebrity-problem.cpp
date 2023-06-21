//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int>pq;
        for(int  i=0;i<n;i++)
        {
            pq.push(i);
        }
        while(pq.size()>1)
        {
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            if(M[first][second]==0)
            {
                pq.push(first);
            }
            else
            {
                pq.push(second);
            }
        }
        
        int ind = pq.top();
        for(int i=0;i<n;i++)
        {
            
            if(i==ind)
            {
                continue;
            }
            if(M[i][ind]!=1||M[ind][i]!=0)
            return -1;
        }
        return ind;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends