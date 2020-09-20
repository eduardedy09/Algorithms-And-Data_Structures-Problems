#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct avl {
    int d;
    struct avl *l;
    struct avl *r;
}*r;
class arbore_avl {
public:
    static int inaltime(avl *);
    static int diferenta(avl *);
    static avl *rotatiedd(avl *);
    static avl *rotatiess(avl *);
    static avl *rotatiesd(avl*);
    static avl *rotatieds(avl *);
    static avl * balans(avl *);
    static avl * inserare(avl*, int);
    static void afisare(avl*, int);
    static void inorder(avl *);
    static void preorder(avl *);
    static void postorder(avl*);
    arbore_avl() {
        r = NULL;
    }
};
int arbore_avl::inaltime(avl *t) {
    int h = 0;
    if (t != NULL) {
        int l_height = inaltime(t->l);
        int r_height = inaltime(t->r);
        int max_height = max(l_height, r_height);
        h = max_height + 1;
    }
    return h;
}
int arbore_avl::diferenta(avl *t) {
    int l_height = inaltime(t->l);
    int r_height = inaltime(t->r);
    int b_factor = l_height - r_height;
    return b_factor;
}
avl *arbore_avl::rotatiedd(avl *parent) {
    avl *t;
    t = parent->r;
    parent->r = t->l;
    t->l = parent;
    cout<<"Right-Right Rotation";
    return t;
}
avl *arbore_avl::rotatiess(avl *parent) {
    avl *t;
    t = parent->l;
    parent->l = t->r;
    t->r = parent;
    cout<<"Left-Left Rotation";
    return t;
}
avl *arbore_avl::rotatiesd(avl *parent) {
    avl *t;
    t = parent->l;
    parent->l = rotatiedd(t);
    cout<<"Left-Right Rotation";
    return rotatiess(parent);
}
avl *arbore_avl::rotatieds(avl *parent) {
    avl *t;
    t = parent->r;
    parent->r = rotatiess(t);
    cout<<"Right-Left Rotation";
    return rotatiedd(parent);
}
avl *arbore_avl::balans(avl *t) {
    int bal_factor = diferenta(t);
    if (bal_factor > 1) {
        if (diferenta(t->l) > 0)
            t = rotatiess(t);
        else
            t = rotatiesd(t);
    } else if (bal_factor < -1) {
        if (diferenta(t->r) > 0)
            t = rotatieds(t);
        else
            t = rotatiedd(t);
    }
    return t;
}
avl *arbore_avl::inserare(avl *r, int v) {
    if (r == NULL) {
        r = new avl;
        r->d = v;
        r->l = NULL;
        r->r = NULL;
        return r;
    } else if (v< r->d) {
        r->l = inserare(r->l, v);
        r = balans(r);
    } else if (v >= r->d) {
        r->r = inserare(r->r, v);
        r = balans(r);
    } return r;
}
void arbore_avl::afisare(avl *p, int l) {
    int i;
    if (p != NULL) {
        afisare(p->r, l + 1);
        cout<<" ";
        if (p == r)
            cout << "Root -> ";
        for (i = 0; i < l&& p != r; i++)
            cout << " ";
        cout << p->d;
        afisare(p->l, l + 1);
    }
}
void arbore_avl::inorder(avl *t) {
    if (t == NULL)
        return;
    inorder(t->l);
    cout << t->d << " ";
    inorder(t->r);
}
void arbore_avl::preorder(avl *t) {
    if (t == NULL)
        return;
    cout << t->d << " ";
    preorder(t->l);
    preorder(t->r);
}
void arbore_avl::postorder(avl *t) {
    if (t == NULL)
        return;
    postorder(t ->l);
    postorder(t ->r);
    cout << t->d << " ";
}
int main() {
    int c, i;
    arbore_avl avl;
    while (1) {
        cout << "1.Insert Element into the tree" << endl;
        cout << "2.show Balanced AVL Tree" << endl;
        cout << "3.InOrder traversal" << endl;
        cout << "4.PreOrder traversal" << endl;
        cout << "5.PostOrder traversal" << endl;
        cout << "6.Exit" << endl;
        cout << "Enter your Choice: ";
        cin >> c;
        switch (c) {
            case 1:
                cout << "Enter value to be inserted: ";
                cin >> i;
                r = avl.inserare(r, i);
                break;
            case 2:
                if (r == NULL) {
                    cout << "Tree is Empty" << endl;
                    continue;
                }
                cout << "Balanced AVL Tree:" << endl;
                avl.afisare(r, 1);
                cout<<endl;
                break;
            case 3:
                cout << "Inorder Traversal:" << endl;
                avl.inorder(r);
                cout << endl;
                break;
            case 4:
                cout << "Preorder Traversal:" << endl;
                avl.preorder(r);
                cout << endl;
                break;
            case 5:
                cout << "Postorder Traversal:" << endl;
                avl.postorder(r);
                cout << endl;
                break;
            case 6:
                exit(1);
                break;
            default:
                cout << "Wrong Choice" << endl;
        }
    }
    return 0;
}