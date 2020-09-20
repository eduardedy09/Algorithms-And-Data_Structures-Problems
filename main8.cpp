#include <iostream>

using namespace std;

struct coada {
    int val;
    coada *urm;
};


void push(coada *&Varf, coada *&Coad, int val) {
    coada *temp = new coada;
    if (Varf == NULL) {
        temp->val = val;
        temp->urm = NULL;
        Coad = temp;
        Varf = temp;
    } else {
        Coad->urm = temp;
        temp->val = val;
        temp->urm = NULL;
        Coad = temp;
    }
}


int pop(coada *&Varf) {

    int a = Varf->val;
    Varf = Varf->urm;
    return a;
}

int peek(coada *Varf) {
    return Varf->val;
}

bool empty(coada *Varf) {
    if (Varf == NULL)
        return 1;
    else return 0;
}

int search(coada *Varf, int vl) {
    coada *temp = Varf;
    int d = 0;
    while (temp != NULL) {
        if (temp->val == vl)
            return d;

        d++;
        temp = temp->urm;
    }
    return -1;
}

void afisare(coada *Varf) {
    coada *t = Varf;
    cout << endl << "Coada: ";
    while (t != NULL) {
        cout << t->val << " ";
        t = t->urm;
    }
    cout << endl;
}

int main() {
    coada *Varf = NULL;
    coada *Coada = NULL;

    int alegere;
    cout << endl;
    cout << "Optiuni :" << endl;
    cout << "1.Inserare inceput " << endl;
    cout << "2.Afisarea elementului din varf " << endl;
    cout << "3.Scoaterea si afisarea elementului din varf " << endl;
    cout << "4.Verificarea stivei, daca este goala sau nu  " << endl;
    cout << "5.Cautare  " << endl;
    cout << "0.EXIT" << endl;
    cout << "Alegeti ce doriti sa faceti :" << endl;
    cin >> alegere;
    while (alegere != 0 && alegere < 6) {
        switch (alegere) {
            case 1: {
                int a;
                cout << "Caracterul pe care doresti sa il inserezi: ";
                cin >> a;
                push(Varf, Coada, a);
                afisare(Varf);
                break;
            }
            case 2: {
                cout << peek(Varf);
                afisare(Varf);
                break;
            }
            case 3: {
                cout << pop(Varf);
                afisare(Varf);
                break;
            }
            case 4: {
                cout << empty(Varf);
                afisare(Varf);
                break;
            }
            case 5: {
                int a;
                cout << "Caracterul pe care doresti sa il cauti: ";
                cin >> a;
                cout << search(Varf, a);
            }
        }
        cout<<endl;
        cout << "Optiuni :" << endl;
        cout << "1.Inserare inceput " << endl;
        cout << "2.Afisarea elementului din varf " << endl;
        cout << "3.Scoaterea si afisarea elementului din varf " << endl;
        cout << "4.Verificarea stivei, daca este goala sau nu( Afiseaza 1 daca este goala, respectiv 0 daca nu )  "
             << endl;
        cout << "5.Cautare  " << endl;
        cout << "0.EXIT" << endl;
        cout << "Alegeti ce doriti sa faceti :" << endl;
        cin >> alegere;
    }

    return 0;
}
