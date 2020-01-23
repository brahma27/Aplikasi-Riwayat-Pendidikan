#include "RELASI.h"
#include "PARENT.h"
#include "CHILD.h"

void createList_relasi(List_relasi &L)
{

    first(L) = NULL;
    last(L) = NULL;
}

void dealokasi_relasi(adr_relasi &P)
{
    delete P;
}

adr_relasi alokasi_relasi(adr_child C, adr_parent P)
{

    adr_relasi R = new elm_relasi;
    parent(R)    = P;
    child(R)  = C;
    next(R) = NULL;
    prev(R) = NULL;
    return R;

}

adr_relasi findElm_RP(List_relasi L, adr_parent x)
{
    adr_relasi P;
    bool cek;
    cek = false;
    if (first(L) != NULL)
    {
        P = first(L);
        while ((cek==false) && (P != NULL))
        {
            if (parent(P) == x)
            {
                cek = true;
            }
            else
            {
                P = next(P);
            }
        }
    }
    if (cek==true)
    {
        return P;
    }
    else
    {
        return NULL;
    }
}

adr_relasi findElm_RC(List_relasi L, adr_child y)
{
    adr_relasi P;
    bool cek;
    cek = false;
    if (first(L) != NULL)
    {
        P = first(L);
        while ((cek == false) && ( P != NULL))
        {
            if ( child(P) == y)
            {
                cek = true;
            }
            else
            {
                P = next(P);
            }
        }
    }
    if (cek==true)
    {
        return P;
    }
    else
    {
        return NULL;
    }
}

adr_relasi FindNelmRP(List_relasi L, infotype_parent Y)
{
    if(first(L) != NULL)
    {
        adr_relasi P = first(L);
        while(P != NULL && info(parent(P)).nama != Y.nama)
        {
            P = next(P);
        }
        return P;
    }

}


adr_relasi FindNelmRC(List_relasi L, infotype_child x)
{
    if(first(L) != NULL)
    {
        adr_relasi P = first(L);
        while(P != NULL && info(child(P)).jenjang != x.jenjang)
        {
            P = next(P);
        }
        return P;
    }
}

void insertLast_relasi(List_relasi &L, adr_relasi P)
{

    if(first(L)!=NULL && last(L)!=NULL)
    {
        prev(P)= last(L);
        next(last(L))= P;
        last(L) = P;
    }
    else
    {
        insertFirst_relasi(L,P);
    }
}

void insertFirst_relasi(List_relasi &L, adr_relasi P)
{

    if((first(L) != NULL) && ( last(L) != NULL))
    {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
    else
    {
        first(L) = P;
        last(L) = P;
    }
}

void insertAfter_relasi(List_relasi &L, adr_relasi Prec, adr_relasi P)
{

    if(Prec != NULL)
    {
        if((first(L) != NULL) && ( last(L) != NULL))
        {
            if(Prec == last(L))
            {
                insertLast_relasi(L,P);
            }
            else
            {
                next(P) = next(Prec);
                prev(P) = Prec;
                prev(next(Prec)) = P;
                next(Prec) = P;
            }
        }
        else if( first(L) == last(L))
        {
            insertFirst_relasi(L,P);
        }
    }
}


void deleteFirst_relasi(List_relasi &L, adr_relasi &P)
{

    P = first(L);
    if (first(L) != last(L))
    {
        first(L) = next(P);
        next(P) = NULL;
        prev(P) = NULL;

    }
    else
    {
        first(L) = NULL;
        last(L) = NULL;
    }

}

void deleteLast_relasi(List_relasi &L, adr_relasi &P)
{

    P = last(L);

    if (first(L) != last(L))
    {
        last(L) = prev(last(L));
        next(last(L)) = NULL;
        prev(P) = NULL;
    }
    else
    {
        deleteFirst_relasi(L,P);
    }
}

void deleteAfter_relasi(List_relasi &L, adr_relasi Prec, adr_relasi &P)
{

    if ((Prec != NULL) && (Prec != last(L)))
    {
        if ((Prec) == prev(last(L)))
        {
            deleteLast_relasi(L,P);
        }
        else
        {
            (first(L) != last(L));
            P = next(Prec);
            next(Prec) = next(P);
            prev(next(P)) = Prec;
            next(P) = NULL;
            prev(P) = NULL;
        }
    }
}

void printRelasi(List_relasi L)
{

    if(first(L) == NULL)
    {
        cout << "List kosong" << endl;
    }
    else
    {
        adr_relasi P = first(L);
        while(P != NULL)
        {
            cout << "Nama = " << info_(parent(P)).nama
                 << " Jenis Kelamin = " << info_(parent(P)).jnl_klmin
                 << " ID = " << info_(parent(P)).ID
                 << " Usia = " << info_(parent(P)).usia
                << " Total Riwayat = "<<info(parent(P)).TotalRiwayat
                 << " Jenjang = " << info(child(P)).jenjang << endl;
            P = next(P);
        }
    }
}

void delData_Relasi(List_relasi &L, adr_relasi &P)
{
    if(first(L)!=NULL)
    {
        if (first(L)==last(L))
        {
            P = first(L);
            first(L) = NULL;
            last(L) = NULL;
        }
        else if (last(L)==P)
        {
            deleteLast_relasi(L,P);
        }
        else if (first(L)==P)
        {
            deleteFirst_relasi(L,P);
        }
        else
        {
            next(prev(P)) = next(P);
            prev(next(P)) = prev(P);
            next(P) = NULL;
            prev(P) = NULL;
        }
        dealokasi_relasi(P);
    }
}
void MaxRiwayat(List_relasi R)
{
    if(first(R)!=NULL)
    {
        adr_relasi temp,P,Q;
        P = first(R);
        Q = first(R);
        int mx = 0;
        if(P!=NULL)
        {
            while(P!=NULL)
            {
                if(info_(parent(P)).TotalRiwayat>=mx)
                {
                    mx = info_(parent(P)).TotalRiwayat;
                }

                P = next(P);
            }
        }

        while(Q!=NULL)
        {
            if(info_(parent(Q)).TotalRiwayat == mx)
            {
//            system("cls");
                cout << "Nama = " << info_(parent(Q)).nama
                     << " Jenis Kelamin = " << info_(parent(Q)).jnl_klmin
                     << " ID = " << info_(parent(Q)).ID
                     << " Usia = " << info_(parent(Q)).usia
                     << " Total Riwayat Pendidikan = "<<info(parent(Q)).TotalRiwayat
                     << " Jenjang = " << info(child(Q)).jenjang<<endl;
            }
            Q = next(Q);
        }

    }

}

void MinRiwayat(List_relasi R)
{
    if(first(R)!=NULL)
    {
        adr_relasi temp,P,Q;
        P = first(R);
        Q = first(R);
        int mn = 99;
        if(P!=NULL)
        {
            while(P!=NULL)
            {
                if(info_(parent(P)).TotalRiwayat<=mn)
                {
                    mn = info_(parent(P)).TotalRiwayat;
                }

                P = next(P);
            }
        }
        while(Q!=NULL)
        {
            if(info_(parent(Q)).TotalRiwayat == mn)
            {
//            system("cls");
                cout << "Nama = " << info_(parent(Q)).nama
                     << " Jenis Kelamin = " << info_(parent(Q)).jnl_klmin
                     << " ID = " << info_(parent(Q)).ID
                     << " Usia = " << info_(parent(Q)).usia
                     << " Total Riwayat Pendidikan = "<<info(parent(Q)).TotalRiwayat
                     << " Jenjang = " << info(child(Q)).jenjang<<endl;
            }
            Q = next(Q);
        }
    }

}
