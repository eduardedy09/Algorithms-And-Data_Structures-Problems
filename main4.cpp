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

bool paranteze_bune(stiva* stv,char* lst,int n)
{

for(int i=0;i<n;i++)
{
    if(lst[i]=='(')
    {
        push(stv,lst[i]);
    }
    else if(lst[i]==')')
    {
        if(stv==NULL)
            return 0;
        else
            pop(stv);
    }
}
    return empty(stv);
}

int main()
{
    stiva* para=NULL;
    char par[]="()()(()()()(())";
    cout<<paranteze_bune(para,par,sizeof(par));
    return 0;
}
