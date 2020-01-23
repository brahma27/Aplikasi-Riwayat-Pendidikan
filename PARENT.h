#ifndef PARENT_H_INCLUDED
#define PARENT_H_INCLUDED
#include <iostream>

using namespace std;

#define Nil NULL
#define first(L) L.first
#define next(P) P->next
#define info_(P) P->info

typedef struct elm_parent *adr_parent;

struct infotype_parent{
    string nama;
    string ID;
    string usia;
    string jnl_klmin;
    int TotalRiwayat;

};
struct elm_parent {
    infotype_parent info;
    adr_parent next;
};

struct List_parent {
    adr_parent first;
};

void createlist_parent(List_parent &L);
adr_parent alokasi_parrent(infotype_parent x);
void insertfirst_parent(List_parent &L, adr_parent P);
void insertlast_parent(List_parent &L, adr_parent P);
void insertAfter_parent(List_parent &L, adr_parent Prec, adr_parent p);
void delete_parent(List_parent &L, adr_parent &P);
void deleteLast_parent(List_parent &L, adr_parent &P);
void delete_first_parent(List_parent &L, adr_parent &P);
void deleteAfter_parent(List_parent &L, adr_parent &p);
void printInfo_parent(List_parent L);
adr_parent findElm_parent(List_parent L, infotype_parent x);
void insertsorting_parent(List_parent &L, adr_parent P);





#endif // PARENT_H_INCLUDED
