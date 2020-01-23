#include "CHILD.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

adr_child Alokasi_child(infotype_child x)
{
   adr_child P = new Elm_child;
    info(P) = x;
    info(P).TotalRiwayat = 0;
    next(P) = NULL;
    return P;
}

void createList_child(List_child &L)
{
    first(L) = NULL;
}

void Printinfo_child(List_child L)
{
    if(first(L) == NULL)
    {
        cout<<"=================================="<<endl;
        cout<<"| DATA JENJANG BELUM DITAMBAHKAN |"<<endl;
        cout<<"=================================="<<endl;
    }
    else
    {
        adr_child P = first(L);
        while(next(P) != first(L))
        {
            cout <<"jenjang       = "<<info(P).jenjang << " ";
            cout <<"TOTAL RIWAYAT        = "<<info(P).TotalRiwayat << " ";
            cout<<endl;
            P = next(P);
        }
         cout <<"jenjang       = "<<info(P).jenjang << " ";

    }

}

void insertFirst_child(List_child &L, adr_child p)
{
    adr_child q = NULL;
    q = first(L);
    if(first(L) == NULL)
    {
        first(L) = p;
        next(p) = first(L);
    }
    else
    {
        while (next(q) != first(L))
        {
            q = next(q);
        }
        next(p) = first(L);
        next(q) = p;
        first(L) = p;
    }

}

void insertAfter_child(List_child &L, adr_child Prec, adr_child p)
{
    if(first(L) == NULL)
    {
        insertFirst_child(L,p);
    }
    else if(next(Prec)==first(L))
    {
        insertLast_child(L,p);
    }
    else
    {

        next(p) = next(Prec);
        next(Prec) = p;
    }


}
void insertLast_child(List_child &L, adr_child p)
{
    adr_child q = NULL;
    q = first(L);
    if(first(L) == NULL)
    {
        insertFirst_child(L,p);
    }
    else
    {
        while (next(q) != first(L))
        {
            q = next(q);
        }
        next(q) = p;
        next(p) = first(L);
    }



}
void DeleteFirst_child(List_child &L, adr_child &P)
{
    if(first(L) != NULL)
    {
        if (next(first(L)== first(L))){
            P = first(L);
            first(L)= NULL;

        }
        else
        {
            adr_child q = first(L);
            while(next(q) != first(L))
            {
                q = next(q);
            }
            P = first(L);
            next(P) = NULL;
            first(L) = next(P);
            next(P) = NULL;
        }

    }
}

void DeleteLast_child(List_child &L, adr_child &p)
{
    adr_child q;
    if(first(L) != NULL)
    {
        if(next(first(L)) == first(L))
        {
            DeleteFirst_child(L,p);
        }
        else
        {
            q = first(L);
            p = first(L);
            while (next(p) != first(L))
            {
                q = p;
                p = next(p);
            }
            next(q) = first(L);
            next(p) = NULL;
        }
    }
    else
    {
        p = first(L);
    }
}
void DeleteAfter_child(List_child &L, adr_child Prec, adr_child &P)
{
    if(first(L) != NULL)
    {
        if(next(Prec)==first(L))
        {
            DeleteLast_child(L,P);
        }
        else if(next(first(L))==first(L))
        {
            DeleteFirst_child(L,P);
        }
        else
        {
            P = next(Prec);
            next(Prec) = next(P);
            next(P) = NULL;
        }
    }
}


adr_child findElm_child(List_child L, infotype_child x)
{
    adr_child P;

    if(first(L)!=NULL)
    {
        P = first(L);
        while(next(P)!=first(L) && info(P).jenjang != x.jenjang)
        {
            P = next(P);
        }
        if(info(P).jenjang == x.jenjang)
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

void deletechild__(List_child &L, infotype_child x)
{
    adr_child q,p;
    p = findElm_child(L,x);
    if(p == NULL)
    {
        cout<<" JENJANG TIDAK ADA "<<endl;
    }
    else
    {
       if (p == first(L))
        {
            DeleteFirst_child(L,p);
            getch();
        }
        else if (next(p) == first(L))
        {
            DeleteLast_child(L,p);
        }
        else
        {
            q = first(L);
            while (next(q) != p)
            {
                q = next(q);
            }
            DeleteAfter_child(L,q,p);
        }
    }
}


