#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>

using namespace std;

/**Range Minimum Query using Sparse Table Method**/
int main()
{
    int vec[] ={2,6,7,6,7,8,8,4,3,6,7,8,10,6,7,8,9,3,6,7,8,7};
    int N = sizeof(vec)/sizeof(vec[0]);

    //Sparse Table
    int st[N][(int)log2(N)];
    memset(st, 0, sizeof(int)*N*(int)(log2(N)));

    for(int i=0;i<N;i++) st[i][0]=i;

    //Preprocessing step
    for(int j=1; (1<<j)<=N;j++)
    {
        for(int i=0;i+(1<<j)-1 < N;i++)
        {
            if(vec[st[i][j-1]] < vec[st[i+(1<<(j-1))][j-1]])
                st[i][j] = st[i][j-1];
            else
                st[i][j] = st[i+(1<<(j-1))][j-1];
        }
    }

    //===>> end of preprocessing step

    int r1,r2;
    cin >> r1>>r2;
    if(r1>=0 && r1<=N && r2>=0 && r2<=N)
    {
    /** This check if basically to counter the loagrithmic effects, hence may be missing out some point ex:
    0    1   | 2   3   4   5   6 |   7
             |<-------range----->|
        then k = log2(6-2+1) > 2 =>(rounding off)2;
        so st[r1][k]        =>  st[2][2] thus covering 2 3 4 5 (missing out 6 :( )
        that's why we also consider:
        st[r2-(1<<k)+1][k] =>   st[3][2] thus covering 3 4 5 6 (missing out 2);

        But this will cover the complete range.
    **/
        int k = (int)log2(r2-r1+1);
        if(vec[st[r1][k]] <= vec[st[r2-(1<<k)+1][k]] )
            cout<<vec[st[r1][k]]<<endl;
        else
            cout<<vec[st[r2-(1<<k)+1][k]]<<endl;
    }
    else cout<<"Out of Range\n";
   // for(int i=0;i<N;i++){for(int j=0;j<(int)(log2(N));j++)cout<<st[i][j]<<" "; cout<<endl;}
}
