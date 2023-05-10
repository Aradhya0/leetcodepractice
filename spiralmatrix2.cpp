class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
      int top=0;
      int left=0;
      int bottom=n-1;
      int right=n-1;
      int counter=1;
    vector<vector<int>>  ans(n,vector<int>(n,0));
    int dir=0;
      while(top<=bottom && left<=right)
      {
          if(dir==0)
          {
              for(int i=left;i<=right;i++)
              {
                  ans[top][i]=counter;
                  counter++;
              }
              dir=1;
              top++;
          }
          else if(dir==1)
          {
              for(int i=top;i<=bottom;i++)
              {
                  ans[i][right]=counter;
                  counter++;
              }
              right--;
              dir=2;
          }
          else if(dir==2)
          {
              for(int i=right;i>=left;i--)
              {
                  ans[bottom][i]=counter;
                  counter++;
              }
              bottom--;
              dir=3;
          }
          else if(dir==3)
          {
              for(int i=bottom;i>=top;i--)
              {
                  ans[i][left]=counter;
                  counter++;
              }
              left++;
              dir=0;
          }
          dir%=4;
      }
      return ans;

    }
};
