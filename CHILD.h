#ifndef CHILD_H_INCLUDED
#define CHILD_H_INCLUDED
#include <iostream>

using namespace std;

#define Nil NULL
#define first(L) L.first
#define next(P) P->next
#define info(P) P->info


struct infotype_child{
    string jenjang;
    int TotalRiwayat;
};

typedef struct Elm_child *adr_child;


struct Elm_child{
    infotype_child info;
    adr_child next;
};

struct List_child{
    adr_child first;
};

void Printinfo_child(List_child L);
adr_child Alokasi_child(infotype_child x);
void isEmpty(List_child L);
void createList_child(List_child &L);
void insertFirst_child(List_child &L, adr_child P);
void insertAfter_child(List_child &L, adr_child Prec, adr_child P);
void insertLast_child(List_child &L, adr_child P);
void DeleteFirst_child(List_child &L, adr_child &P);
void DeleteLast_child(List_child &L, adr_child &P);
void DeleteAfter_child(List_child &L, adr_child Prec, adr_child &P);
adr_child findElm_child(List_child L, infotype_child x);
void deletechild__(List_child &L, infotype_child x);




#endif // CHILD_H_INCLUDED
