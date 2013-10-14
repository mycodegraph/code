/**
C++ implementation of segment tree for calculating the minimum from a given array
@complexity: <preprocessng,query>::<O(N),O(log(N))>
**/
#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

/**Function to create the segment tree*/
int SegTree(int *seg, int *arr,int ind, int i, int j)
{
    int mid = i + (j-i)/2;
    int diff= j-i+1;

    if(diff == 1) seg[ind]=arr[i];
    else  seg[ind]=min(SegTree(seg, arr, 2*ind, i, mid), SegTree(seg, arr, 2*ind+1, mid+1,j));
}

/**Query function to find the minimum in a given range**/
int query(int *seg, int ind, int i, int j, int ri, int rf)
{
    /**For sure this condition will be satisfied for any proper supplied range**/
    if(ri == i && rf==j) return seg[ind];

    /**

    check for the following scenario
    0   1   2   3   4   5   6   7   8   9
 <---rf |<------------range---------------->| ri-->
    **/

    if(ri > j || rf < i) return -1;

    ///Calculating mid value
    int mid = i + (j-i)/2;

    int p1=-1,p2=-1;
    if(ri <= mid && mid <= rf)                          /// If ri and rf are on opposite sides of mid or both are equal to mid
    {
        int _mid=ri+(rf-ri)/2;
        p1 = query(seg, 2*ind, i, mid, ri, _mid);
        p2 = query(seg, 2*ind+1, mid+1, j, _mid+1, rf);
    }
    else if(ri <= mid && rf<=mid)                       /// If ri and rf are both on left side of mid
    {
        p1 = query(seg, 2*ind, i, mid, ri, rf);
    }
    else p2 = query(seg, 2*ind+1, mid+1, j, ri, rf);    ///if ri and rf are on right sie of mid

    if(p1 == -1) return p2;
    if(p2 == -1) return p1;
    if(p1 < p2) return p1;
    else return p2;
}

int main()
{
    int arr[]={4,19,2,7,13,8};              ///Dummy Array
    int N = sizeof(arr)/sizeof(arr[0]);     ///Calculating the size of array
    int sz = (1 << ((int)log2(N)+1))*2;     ///Calculating the size of Segment Tree array

    int seg[sz];                            ///Segment Tree

    memset(seg, 0, sizeof(int)*sz);
    /**Uncomment to print segment tree array**/
    //for(int i=0;i<2*N - 1;i++) cout<<seg[i]<<" ";

    SegTree(seg, arr, 1, 0, N-1);

    /**Uncomment to print segment tree array**/
    //for(int i=1;i<sz;i++) cout<<seg[i]<<"  ";

    int ri,rf;
    cin >>ri>>rf;                             ///Query Range starts from 0 to N(array size)
    if(ri>=0 && rf<N && ri <N && rf>=0)
    {
        int ind=query(seg,1,0,N-1,ri,rf);
        if(ind > 0) cout<<ind;                ///Prints the minimum value in the queried range
        else cout<<ind<<" \n";                ///For Debugging
    }
    else cout<<"Out of range\n";
}
