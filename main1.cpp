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

bool nr_caractere_egale(stiva* stv,char* lst,int n)
{



    for(int i=0;i<6;i++)
    {
        cout<<lst[i]<<endl;
        if(stv==NULL)
        {
            push(stv,lst[i]);
        }
        else if(lst[i]==peek(stv))
        {
            push(stv,lst[i]);
        }
        else if(lst[i]!=peek(stv))
        {
            pop(stv);
        }
    }

    return empty(stv);
}

int main()
{
    stiva* stv=NULL;
    char caractere[]={'a','a','b','b','b','a'};
    cout<<sizeof(caractere)<<endl;
    cout<<nr_caractere_egale(stv,caractere,sizeof(caractere));


    return 0;
}
