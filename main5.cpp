#include <iostream>

using namespace std;

struct stiva
{
    int val;
    stiva* urm;
};



void push(stiva* &Fata,stiva* &Spate,int val)
{
    stiva* temp=new stiva;
    if(Fata==NULL)
    {
        temp->val=val;
        temp->urm=NULL;
        Spate=temp;
        Fata=temp;
    }
    else
        {
        Spate->urm=temp;
        temp->val=val;
        temp->urm=NULL;
        Spate=temp;
        }
}

int pop(stiva* &Fata,stiva* &Spate)
{

    int a = Fata->val;
    if(Fata==Spate)
    {
        Spate=NULL;
        Fata=NULL;

    }
    else
    {
 Fata=Fata->urm;

    }

    return a;

}
int peek(stiva* Fata)
{
    return Fata->val;
}

bool empty(stiva*Fata)
{
    if(Fata==NULL)
        return 1;
    else return 0;
}

int search(stiva *Fata,int vl)
{
    stiva* temp=Fata;
    int d=0;
    while(temp!=NULL)
    {
        if(temp->val==vl)
            return d;

        d++;
        temp=temp->urm;
    }
    return -1;
}
void afisare(stiva* Fata)
{   stiva* t=Fata;
cout<<endl<<"coada= ";
    while(t!=NULL)
    {
        cout<<t->val<<" ";
    t=t->urm;
    }
    cout<<endl;
}
int main()
{
stiva* Fata=NULL;
stiva* Spate=NULL;

int e=0;
int v;
while(e==0)
    {


    cout<<"Meniu:"<<endl<<"1 introducere"<<endl<<"2 scoatere"<<endl<<"3 vezi ult element"<<endl<<"4 cautare el"<<endl<<"5 e goala?"<<endl<<"6 afisare"<<endl<<"7 iesire"<<endl<<"Optiune:";
    int a;
    cin>>a;
switch(a)
{
    case 1:{cout<<"Introduceti valoare",cin>>v;push(Fata,Spate,v);}break;
    case 2:{cout<<"elem scos"<<pop(Fata,Spate);}break;
    case 3:{cout<<peek(Fata);}break;
    case 4:{cout<<"el cautat si dist:";cin>>v;cout<<search(Fata,v)<<endl;}break;
    case 5:{cout<<empty(Fata);}break;
    case 6:{afisare(Fata);}; break;
    case 7:{e=1;}
    default:{}
}
    }


    return 0;
}
