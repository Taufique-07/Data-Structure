#include<iostream>

using namespace std;

int search(int a[],int num)
{
    int key;
    cout<< "Enter the key : ";
    cin>>key;
    for(int i=0; i<num; i++)
    {
        if(a[i]==key)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int num;
    cin>>num;

    int a[num];

    for(int i=0; i<num; i++)
    {
        cin>>a[i];
    }

    int count = search(a,num);
  if( count ==-1)
  {
      cout<< "This number is not placed in this array."<<endl;
  }
  else
  {
      cout<< "It's in "<<count<< "index"<<endl;
  }

}

