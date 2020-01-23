#include "PARENT.h"

void createlist_parent(List_parent &L){
    first(L) = NULL;
}


adr_parent alokasi_parrent(infotype_parent x) {
    adr_parent P = new elm_parent;
    info_(P) = x;
    info_(P).TotalRiwayat = 0;
    next(P) = NULL;
    return P;
}

void insertfirst_parent(List_parent &L, adr_parent P) {

     if(first(L) != NULL){
        next(P) = first(L);
        first(L) = P;
    }
    else {
        first(L) = P;
    }
}

void insertlast_parent(List_parent &L, adr_parent P) {
    if(first(L) != NULL){
        adr_parent Q = first(L);
        while(next(Q) != NULL){
            Q = next(Q);
        }
        next(Q) = P;
    }
    else {
        first(L) = P;

    }
}

void insertAfter_parent(List_parent &L,adr_parent P, adr_parent Prec ){
    if(next(Prec) != NULL)
    {
        next(P) = next(Prec);
        next(Prec) = P;
    }

}

void insertsorting_parent(List_parent &L, adr_parent P){
    if (first(L) != NULL){
            adr_parent q;
            q = first(L);
            while(next(q)!=NULL){
                q = next(q);
            }

        if(info_(P).nama <= info_(first(L)).nama){
            insertfirst_parent(L,P);
        }else if (info_(P).nama >= info_(q).nama){
            insertlast_parent(L,P);
        }else{
            adr_parent Q = first(L);
            while(info_(P).nama > info_(next(Q)).nama){
                Q =next(Q);
            }
            insertAfter_parent(L,Q,P);
        }
    }else{
        insertfirst_parent(L,P);
    }
}



void delete_first_parent(List_parent &L){
    adr_parent P;
    if(first(L) != NULL){
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
    }

}

void deleteLast_parent(List_parent &L){

    adr_parent Q;
    adr_parent P;
    if (first(L) != NULL){
        if(next(first(L))== NULL ){
            delete_first_parent(L);
        }else{
        P = first(L);
        Q = next(P);
        while(next(Q) != NULL){
            P = next(P);
            Q = next(Q);
        }
        next(P) = NULL;
     }
   }
}

void deleteAfter_parent(List_parent &L, adr_parent &p){
    adr_parent prec;
    if(first(L)!=NULL){
        if(next(prec)!=NULL){
            p=next(prec);
            next(prec)=next(p);
            next(p)=NULL;
            delete p;
        }
    }
}

void delete_parent(List_parent &L, adr_parent &P){
    if (first(L) != NULL) {
        adr_parent S;
        adr_parent Q;
        if (first(L) == P){
            delete_first_parent(L);
        }else if (next(P) == NULL) {
            deleteLast_parent(L);
        }else{
        S = first(L);
        Q = next(P);
        while(next(Q) != P){
            S = next(P);
            Q = next(Q);
        }
        deleteAfter_parent(L,S);
        }
    }
}

void printInfo_parent(List_parent L){
    if (first(L) == NULL){
        cout<<"================================"<<endl;
        cout<<"| DATA ORANG BELUM DITAMBAHKAN |"<<endl;
        cout<<"================================"<<endl;
    }
    else
    {
    adr_parent p = first(L);
    while (p != NULL){
        cout << " Nama = "<<info_(p).nama <<" ";
        cout << " Jenis kelamin = "<<info_(p).jnl_klmin <<" ";
        cout << " Umur = "<<info_(p).usia <<" ";
        cout << " ID = "<<info_(p).ID <<" ";
        cout << " Jumlah Riwayat Pendidikan = "<<info_(p).TotalRiwayat<<" ";
        cout<<endl;
        p = next(p);
    }
    cout << endl;
    }
}

adr_parent findElm_parent(List_parent L, infotype_parent x) {
{

  adr_parent P;

    if(first(L)!=NULL)
    {
        P = first(L);
        while( P != NULL && info_(P).ID != x.ID)
        {
            P = next(P);
        }
        if(P != NULL && info_(P).ID == x.ID)
        {
            return P;
        }
        else
        {
            return NULL;
        }
    }
    return NULL;
    }
}

