#include<iostream>
#include<cstring>
#include<climits>
using namespace std;

/**
@brief:   This Function finds the maximum element from an unsorted Array of Integers.
@params:  Takes an integer array and size of that array
@returns: This Function rturns maximum element from the array
**/
int findMax(int *array, size_t _size)
{
    int _max=INT_MIN;
    for(int i=0;i<_size;i++) 
    {
      if(_max < array[i])
        _max = array[i];
    }

    return _max;
}

void printBarChart(int *arr, int _max)
{
    do
    {
        cout<<" ";
        for(int i=0;i<26;i++)
        {
            if(_max == arr[i]) cout<<"|"<<_max<<"|";
            else if(_max < arr[i]) cout<<"| |";
            else cout<<"   ";
        }
        cout<<endl;
    }while(_max--);
    cout<<"  ";for(int i=0;i<26;i++)cout<<(char)(i+'a')<<"  ";
}

int main()
{
  bool _break=false;
  char buff='\0';
  int arr[26];
  memset(arr,0,sizeof(arr));

  while(_break == false && cin >> buff) (buff >= 'a' && buff <= 'z')?(arr[buff-'a']++):(_break=true);

  printBarChart(arr,findMax(arr, 26));

  cout<<endl;

  cout<<"LETTER\t\tFrequency\n";
  for(int i=0;i<26;i++) cout<<(char)(i+'a')<<"\t\t"<<(int)arr[i]<<endl;

 //while(!(_break))(0)?_break=0:(_break=1);

}
