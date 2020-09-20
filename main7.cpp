#include <iostream>

using namespace std;

struct stiv {
    char val;
    stiv *urm;
};

void push(stiv *&st, char val) {
    if (st == NULL) {
        st = new stiv;
        st->val = val;
        st->urm = NULL;
    } else {
        stiv *temp = new stiv;
        temp->urm = st;
        temp->val = val;
        st = temp;
    }

}

char peek(stiv *st) {
    return st->val;
}

char pop(stiv *&st) {
    char temp = st->val;
    st = st->urm;
    return temp;
}

bool empty(stiv *st) {
    if (st == NULL)
        return 1;
    else return 0;
}

int search(int a, stiv *st) {
    int dist = 0;
    while (st != NULL) {
        if (st->val == a)
            return dist;

        dist++;
        st = st->urm;
    }

    return -1;
}

void afisare(stiv *st) {
    stiv *st2 = st;
    cout << "\nLista:";
    while (st2 != NULL) {
        cout << st2->val << " ";
        st2 = st2->urm;
    }
    cout << endl;
}

int main() {
    stiv *stv = NULL;
    int alegere;
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
                char a;
                cout << "Caracterul pe care doresti sa il inserezi: ";
                cin >> a;
                push(stv, a);
                afisare(stv);
                break;
            }
            case 2: {
                cout << peek(stv);
                afisare(stv);
                break;
            }
            case 3: {
                cout << pop(stv);
                afisare(stv);
                break;
            }
            case 4: {
                cout << empty(stv);
                afisare(stv);
                break;
            }
            case 5: {
                char a;
                cout << "Caracterul pe care doresti sa il cauti: ";
                cin >> a;
                cout << search(a, stv);
            }
        }
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
