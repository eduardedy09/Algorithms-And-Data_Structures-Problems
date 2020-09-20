#include <iostream>

using namespace std;

// stiva=LIFO
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

int pop(stiva* &stv)
{
    int temp= stv->val;
    stv=stv->urm;
    return temp;
}
int peek(stiva *stv)
{
    return stv->val;
}

bool empty(stiva* stv)
{
    if(stv==NULL)
        return 1;
    else return 0;
}

int search(int a,stiva* stv)
{
 int dist=0;
 while(stv!=NULL)
 {
     if(stv->val==a)
        return dist;

     dist++;
     stv=stv->urm;
 }

 return -1;
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
    cout<<endl;
}
int main()
{
stiva* stv=NULL;

int e=0;
int v;
while(e==0)
    {


    cout<<"Meniu:"<<endl<<"1 introducere"<<endl<<"2 scoatere"<<endl<<"3 vezi ult element"<<endl<<"4 cautare el"<<endl<<"5 e goala?"<<endl<<"6 afisare"<<endl<<"7 iesire"<<endl<<"Optiune:";
    int a;
    cin>>a;
switch(a)
{
    case 1:{cout<<"Introduceti valoare",cin>>v;push(stv,v);}break;
    case 2:{cout<<"elem scos"<<pop(stv);}break;
    case 3:{cout<<peek(stv);}break;
    case 4:{cout<<"el cautat si dist:";cin>>v;cout<<search(v,stv)<<endl;}break;
    case 5:{cout<<empty(stv);}break;
    case 6:{afisare(stv);}; break;
    case 7:{e=1;}
    default:{}
}
    }



    return 0;
}
