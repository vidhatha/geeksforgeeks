//
// Solution is not valid
//for all cases!
//
#include <iostream>
#include <vector>
using namespace std;

void coinchange(int N, vector<int> coins)
{
    //Types of coin denomonations
    int M = coins.size();
    
    //no of ways to make the coin change
    vector<vector<int> >noofways(M, vector<int>(N+1));
    
    //if we have N=0 (i.e 0 money)
    //we get achive it using one way with any
    //denomination i.e using no coin
    for(int i=0;i<M;i++)
        noofways[i][0] = 1;
    
    //no of ways of coin change if you 
    //have C=1(just one coin denomination)
    //is 1 for any N
    for(int j=0;j<=N;j++)
        noofways[0][j] = 1;    
    
    for(int i=1;i<M;i++)
    {
        for(int j=0;j<=N;j++)
        {
            if(j>=coins[i])
                noofways[i][j] = noofways[i-1][j] + noofways[i][j-coins[i]];
            else
                noofways[i][j] = noofways[i-1][j];
            //cout<<"N["<<i<<"]"<<"["<<j<<"]:"<<noofways[i][j]<<" ";
        }
        cout<<endl;
    }
    
    cout<<"No of ways for Coin Change: "<<noofways[M-1][N];
}

int main()
{
    int N = 5;
    vector<int> coins{1,2,3};
    coinchange(N,coins);
    return 0;
}
