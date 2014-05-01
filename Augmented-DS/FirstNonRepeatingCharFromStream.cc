#include<iostream>
#include<algorithm>
#include<unistd.h>

using namespace std;
#define ALPHA   25

struct Node
{
    char c;
    Node *prev, *next;

    Node(char ch):c(ch),prev(NULL),next(NULL){}
};

Node *listHead=new Node('\0');
Node *tail=listHead;
bool IsPresent[ALPHA+1];
Node * CharAddr[ALPHA+1];

char  GetFirstChar(char ch)
{
    if(ch =='\0')
        return '\0';

    if(IsPresent[ch-'a'] == true)
    {
        if(CharAddr[ch-'a'] != NULL)
        {
            Node * temp=CharAddr[ch-'a'];

            if(temp->next == NULL)
                tail=temp->prev;

            if(temp->next != NULL)
                temp->next->prev=temp->prev;

            if(temp->prev != NULL)
                temp->prev->next = temp->next;

            delete temp;
            CharAddr[ch-'a']=NULL;
        }
    }
    else
    {
        tail->next = new Node(ch);
        tail->next->prev=tail;
        tail = tail->next;

        CharAddr[ch-'a']=tail;
        IsPresent[ch-'a']=true;
    }

    if(listHead->next != NULL)
        return listHead->next->c;
    else
        return '\0';
}
int main()
{
    char stream='b';
    char first;

    while((first=GetFirstChar(stream)) != '\0')
    {
        cout<<"Input Char: "<<stream<<" and First Character: "<<first<<endl;
        stream=(char)(rand()%ALPHA) +'a';

        sleep(1);
    }
}
