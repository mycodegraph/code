#include<iostream>

using namespace std;
#define MAX 16
int arr[MAX];
int vec[MAX][MAX];

int fun(int i, int j, int flag)
{
    if(i > j) return 0;
    if(vec[i][j] != 0) return vec[i][j];

    int len=0;
    int _max=-1;
    for(int k=j-1;k>=0;k--)
    {
        if(arr[k]<arr[j]) len=fun(i,k,flag+1)+1;
        else if(flag==0) len=fun(i,k,flag+1)+1;
      //  cout<<endl;
        if(_max < len) _max=len;
       // cout<<i<<","<<k<<": "<<_max<<"\n";
    }
    vec[i][j]=_max;
    return _max;
}

int main()
{
    int temp[]={0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    for(int i=0;i<MAX;i++) {arr[i]=temp[i];vec[i][i]=1;}

    cout<<fun(0,MAX-1,0)<<endl;
}
