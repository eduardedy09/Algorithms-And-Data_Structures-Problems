#include <iostream>

using namespace std;
struct Nod
{
    int nr;
    Nod* urm;
};


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
void afisareLista(Nod* varf)
{
    if(varf==NULL)
        cout<<"Lista e goala";
    else
        while (varf != NULL)
        {
            cout << varf->nr << "\n";
            varf = varf->urm;
        }
}
void nr_poz_medieA_neg(Nod* varf)
{
    int nr_poz=0,nr_neg=0,suma_neg=0;
    while(varf!=NULL)
    {
        if(varf->nr>=0)
            nr_poz++;
        else
        {
            suma_neg+=varf->nr;
            nr_neg++;
        }
        varf=varf->urm;
    }
    cout<<"NR POZ = "<<nr_poz<<"\nNR Neg = "<<nr_neg<<"\nMedie Ar nr neg= "<<suma_neg*1.00/nr_neg;
}
int main()
{
    Nod* lista=NULL;
    int i,n,val=0;
    cout<<"Nr de elem in lista: "; cin>>n;
    for(i=0;i<n;i++)
    {
        cout<<"Valoare bagata in lista: ";
        cin>>val;
        inserareFinal(lista,val);
    }
    afisareLista(lista);
    nr_poz_medieA_neg(lista);
    return 0;
}
