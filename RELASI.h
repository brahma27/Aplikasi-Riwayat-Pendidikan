#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include <iostream>

using namespace std;

#include "PARENT.h"
#include "CHILD.h"
#define Nil NULL
#define next(P) P->next
#define prev(P) P->prev
#define first(L) L.first
#define last(L) L.last
#define parent(P) P->parent
#define child(P) P->child


typedef struct elm_relasi *adr_relasi;

struct elm_relasi {
    adr_relasi next;
    adr_parent parent;
    adr_child child;
    adr_relasi prev;

};

struct List_relasi {
    adr_relasi first;
    adr_relasi last;
};

void createList_relasi(List_relasi &L);
void dealokasi_relasi(adr_relasi &P);
adr_relasi alokasi_relasi(adr_child C, adr_parent P);
void printInfo_relasi(List_relasi L);
void insertLast_relasi(List_relasi &L, adr_relasi P);
void insertFirst_relasi(List_relasi &L, adr_relasi P);
adr_relasi findElm_RP(List_relasi L, adr_parent x);
adr_relasi findElm_RC(List_relasi L, adr_child y);
void insertAfter_relasi(List_relasi &L, adr_relasi Prec, adr_relasi P);
void deleteLast_relasi(List_relasi &L, adr_relasi &P);
void deleteAfter_relasi(List_relasi &L, adr_relasi Prec, adr_relasi &P);
void deleteFirst_relasi(List_relasi &L, adr_relasi &P);
void printRelasi(List_relasi L);
void printTest(List_parent LP, List_relasi LR);
adr_relasi FindNelmRC(List_relasi L, infotype_child x);
adr_relasi FindNelmRP(List_relasi L, infotype_parent Y);
void delData_Relasi(List_relasi &L, adr_relasi &P);
void MaxRiwayat(List_relasi R);
void MinRiwayat(List_relasi R);


#endif // RELASI_H_INCLUDED
