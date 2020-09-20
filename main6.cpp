#include <iostream>

using namespace std;

struct stiva
{
    char val;
    stiva* urm;
};
void push(stiva* &stv,char val)
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
char peek(stiva* stv)
{
    return stv->val;
}
char pop(stiva* &stv)
{
    char temp= stv->val;
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

int polonez(stiva* stv,char*v,int n)
{
    for(int i=0;i<n-1;i++)
    {
        int temp=v[i]-'0';
        if(sizeof(int)==sizeof(temp))
            cout<<"nr"<<endl;
    }
}
int main()
{
    stiva* stv=NULL;
    char v[]="2 3 5";
    cout<<sizeof(v)<<endl;
    polonez(stv,v,sizeof(v));
    return 0;
}
