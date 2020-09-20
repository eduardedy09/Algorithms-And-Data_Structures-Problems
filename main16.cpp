#include <iostream>

using namespace std;
struct Nod
{
    int nr;
    Nod* urm;
};
void inserare(Nod* &varf, int val)
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
void inserare_medii(Nod *varf){
    Nod *one = varf;
    Nod *two = varf->urm;
    while(two != nullptr)
    {
        int medie;
        medie = (one->nr + two->nr)/2;
        Nod *aux=new Nod;
        aux->nr = medie;
        aux->urm = two;
        one->urm = aux;
        one = two;
        two = two ->urm;
    }

}
int main()
{   Nod *varf = NULL;
    int nr_elemente;
    cout<<"numarul de elemente ale listei:";
    cin>>nr_elemente;
    for(int iterator = 0 ; iterator < nr_elemente ; iterator++)
    {
        int numar;
        cin>>numar;
        inserare(varf,numar);
    }
    inserare_medii(varf);
    afisareLista(varf);
    return 0;
}
