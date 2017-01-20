#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main()
 {
	//code
  int m,n;
  cin>>m>>n;

  string str1, str2;
  cin>>str1>>str2;

    vector<vector<int>> lcs(m+1,vector<int>(n+1));
  for(int i=0;i<m+1;i++) lcs[i][0] = 0;
  for(int j=0;j<n+1;j++) lcs[0][j] = 0;

  for(int i=1;i<m+1;i++)
  {
      for(int j=1;j<n+1;j++)
      {
          if(str1[i] == str2[j])
              lcs[i][j] = 1+lcs[i-1][j-1];
          else
              lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
      }
  }
  cout<<lcs[m][n]<<endl;

	return 0;
}
