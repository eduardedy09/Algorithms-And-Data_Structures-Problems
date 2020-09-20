#include <iostream>

using namespace std;

struct Nod
{
    int nr;
    Nod* urm;
};
void afisareLista(Nod* varf);


void inserareInceput(Nod* &varf,int val)
{
    Nod* elem=new Nod;
    elem->nr=val;
    elem->urm=varf;
    varf=elem;

}

void inserareFinal(Nod* &varf, int val)
{
    Nod *elem = new Nod;
    elem->nr = val;
    elem->urm = NULL;
    if (varf == NULL)
        varf = elem;
    else
    {
        Nod *nod_curent = varf;
        while (nod_curent->urm != NULL)
            nod_curent = nod_curent->urm;
        nod_curent->urm = elem;
    }
}
int pozitie(Nod* varf,int val)
{
    int i=0;
    while(varf!=NULL)
    {
        if(val<varf->nr)
        {
            break;
        }
        varf=varf->urm;
        i++;
    }
    if(varf==NULL)
        i=-1;
    return i;
}
void inserareInterior(Nod* &varf,int val,int poz)
{
    Nod *q=varf;
    for(int i=0;i<poz-1;i++)
    {
        q=q->urm;
    }
    Nod* p=new Nod;
    p->nr=val;
    p->urm=q->urm;
    q->urm=p;

}


void afisareLista(Nod* varf)
{
    if(varf==NULL)
        cout<<"Lista e goala";
    else
        while (varf != NULL)
        {
            cout << varf->nr <<"\n";
            varf = varf->urm;
        }
}

int main()
{
    Nod* lista=NULL;
    int nr_el,val;
    cout<<"NR EL = ";
    cin>>nr_el;
    for(int i=1;i<=nr_el;i++)
    {
        cout<<"Val "<<i<<" = ";
        cin>>val;
        if(i==0)
            inserareInceput(lista,val);
        else
        {
            int p=pozitie(lista,val);
            if(p==-1)
                inserareFinal(lista,val);
            else if(p==0)
                inserareInceput(lista,val);
            else
                inserareInterior(lista,val,p);
        }
    }
    afisareLista(lista);

    return 0;
}
