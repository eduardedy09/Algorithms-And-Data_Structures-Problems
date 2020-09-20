#include <iostream>

using namespace std;

struct stiva
{
    int val;
    stiva* urm;
};
void push(stiva* &stv,int val)
{
    if(stv==NULL)
    {
     stv=new stiva;
     stv->val=val;
     stv->urm=NULL;
    }
    else
    {
        stiva *temp=new stiva;
        temp->urm=stv;
        temp->val=val;
        stv=temp;
    }

}
int peek(stiva* stv)
{
    return stv->val;
}
int pop(stiva* &stv)
{
    int temp= stv->val;
    stv=stv->urm;
    return temp;
}

bool empty(stiva* stv)
{
    if(stv==NULL)
        return 1;
    else return 0;
}


void afisare(stiva* stv)
{
    stiva* stv2=stv;
    cout<<"\nlista:";
    while(stv2!=NULL)
    {
        cout<<stv2->val<<" ";
        stv2=stv2->urm;
    }
}
int pin_valid(int*perechi,int n)
{
    stiva* stv=NULL;
    if(n%2==1)
        return 0;
    for(int i=0;i<n;i++)
    {
        if(empty(stv)==1)
        {
            push(stv,perechi[i]);
        }
        else if(peek(stv)==perechi[i])
        {
            pop(stv);
        }
        else
        {
            push(stv,perechi[i]);
        }
        afisare(stv);
    }
    return empty(stv);

}
int main()
{
int perechi[]={1,2,1,2,};
cout<<"\nEste valid?:"<<pin_valid(perechi,sizeof(perechi)/sizeof(int));
    return 0;
}
