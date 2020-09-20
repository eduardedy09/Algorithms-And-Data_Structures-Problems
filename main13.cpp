#include <iostream>

using namespace std;

struct Nod {
    int nr;
    Nod *urm;
};

void inserareInceput(Nod *&varf, int val) {
    Nod *elem = new Nod;
    elem->nr = val;
    elem->urm = varf;
    varf = elem;
}

void inserareFinal(Nod *&varf, int val) {
    Nod *elem = new Nod;
    elem->nr = val;
    elem->urm = NULL;
    if (varf == NULL)
        varf = elem;
    else {
        Nod *nod_curent = varf;
        while (nod_curent->urm != NULL)
            nod_curent = nod_curent->urm;
        nod_curent->urm = elem;
    }
}

void inserareInterior(Nod *&varf, int val, int poz) {
    Nod *q = varf;
    for (int i = 0; i < poz - 1; i++) {
        q = q->urm;
    }
    Nod *p = new Nod;
    p->nr = val;
    p->urm = q->urm;
    q->urm = p;
}

void cautare_el_val(Nod *varf, int val) {
    int b = 0;
    while (varf != NULL && b == 0) {
        if (varf->nr == val) {
            b = 1;
            cout << "Element gasit\n";
        }
        varf = varf->urm;
    }
    if (b == 0)
        cout << "Elem nu exista in lista\n";
}

void cautare_el_poz(Nod *varf, int poz) {
    int i = 0;
    int c = 0;
    while (varf != NULL && i <= poz) {
        if (i == poz) {
            cout << "Poz exista\n";
            c = 1;
            break;
        }
        i++;

        varf = varf->urm;
    }
    if (c == 0) {
        cout << "Poz nu exista\n";
    }
}

void stergere_elem_val(Nod *&varf, int val) {
    if (varf->nr == val) {
        Nod *strg = varf;
        varf = varf->urm;
        delete strg;
        return;
    }

    Nod *elem = varf;
    while (elem->urm != NULL && elem->urm->nr != val)
        elem = elem->urm;

    if (elem->urm != NULL) {
        Nod *strg = elem->urm;

        elem->urm = elem->urm->urm;

        delete strg;
    }
}

void stergere_elem_poz(Nod *&varf, int poz) {
    Nod *elem = varf;
    if (poz == 0) {
        Nod *strg = varf;
        varf = varf->urm;
        delete strg;
    } else {
        int i = 0;
        while (elem->urm != NULL && i < poz) {
            elem = elem->urm;
            i++;
        }

        if (elem->urm != NULL) {
            Nod *strg = elem->urm;

            elem->urm = elem->urm->urm;

            delete strg;
        }

    }
}

void afisareLista(Nod *varf) {
    if (varf == NULL)
        cout << "Lista e goala";
    else
        while (varf != NULL) {
            cout << varf->nr << " ";
            varf = varf->urm;
        }
}

int main() {
 Nod *varf = NULL;

    int alegere;
    cout << "Optiuni :" << endl;
    cout << "1.Inserare inceput " << endl;
    cout << "2.Inserare final " << endl;
    cout << "3.Inserare interior " << endl;
    cout << "4.Cautare element dupa valoare  " << endl;
    cout << "5.Cautare pozitie " << endl;
    cout << "6.Stergere element dupa valoare " << endl;
    cout << "7.Stergere element de pe pozitie " << endl;
    cout << "0.EXIT" << endl;
    cout << "Alegeti ce doriti sa faceti cu lista :" << endl;;
    cin >> alegere;
    while (alegere!=0 && alegere < 8) {
        switch (alegere) {
            case 1: {
                int nr;
                cout << "Nr pe care doresti sa il inserezi : ";
                cin >> nr;
                inserareInceput(varf, nr);
                break;
            }
            case 2: {
                int nr;
                cout << "Nr pe care doresti sa il inserezi : ";
                cin >> nr;
                inserareFinal(varf, nr);
                break;
            }
            case 3: {
                int nr, poz;
                cout << "Nr pe care doresti sa il inserezi : ";
                cin >> nr;
                cout << "Pozitia pe care doresti sa inserezi numarul : ";
                cin >> poz;
                inserareInterior(varf, nr, poz);
                break;
            }
            case 4: {
                int nr;
                cout << "Elemntul pe care doresti sa il cauti : ";
                cin >> nr;
                cautare_el_val(varf, nr);
                break;
            }
            case 5: {
                int poz;
                cout << "Pozitia pe care doresti sa o cauti : ";
                cin >> poz;
                cautare_el_poz(varf, poz);
                break;

            }
            case 6: {
                int nr;
                cout << "Elementul pe care doresti sa il stergi";
                cin >> nr;
                stergere_elem_val(varf, nr);
                break;
            }
            case 7: {
                int poz;
                cout << "Pozitia elementului pe care doresti sa il stergi";
                cin >> poz;
                stergere_elem_poz(varf, poz);
                break;
            }
        }
        cout << "Optiuni :" << endl;
        cout << "1.Inserare inceput " << endl;
        cout << "2.Inserare final " << endl;
        cout << "3.Inserare interior " << endl;
        cout << "4.Cautare element dupa valoare  " << endl;
        cout << "5.Cautare pozitie " << endl;
        cout << "6.Stergere element dupa valoare " << endl;
        cout << "7.Stergere element de pe pozitie " << endl;
        cout << "0.EXIT" << endl;
        cout << "Alegeti ce doriti sa faceti cu lista :" << endl;;
        cin >> alegere;
    }
    afisareLista(varf);

    return 0;
}
