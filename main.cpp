#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include "PARENT.h"
#include "RELASI.h"
#include "CHILD.h"

using namespace std;

void menutambah();
void menutampilan();
void hapusdata();
void cari();
void edit();


List_parent L_P;
List_child L_C;
List_relasi L_R;

int main()
{
    createlist_parent(L_P);
    createList_child(L_C);
    createList_relasi(L_R);
    char pil;
    bool keluar;
    keluar = true;
    while (keluar == true)
    {
        system("cls");

        cout<<("================================")<<endl;
        cout<<("********************************")<<endl;
        cout<<("**  ------------------------  **")<<endl;
        cout<<("**  |                      |  **")<<endl;
        cout<<("**--|  RIWAYAT PENDIDIKAN  |--**")<<endl;
        cout<<("**  |                      |  **")<<endl;
        cout<<("**  ------------------------  **")<<endl;
        cout<<("********************************")<<endl;
        cout<<("================================")<<endl;
        cout<<("|          MENU UTAMA          |")<<endl;
        cout<<("================================")<<endl;
        cout<<("|| 1. TAMBAH DATA             ||")<<endl;
        cout<<("|| 2. LIHAT DATA              ||")<<endl;
        cout<<("|| 3. HAPUS DATA              ||")<<endl;
        cout<<("|| 4. CARI DATA               ||")<<endl;
        cout<<("|| 5. EDIT DATA               ||")<<endl;
        cout<<("|| 6. KELUAR                  ||")<<endl;
        cout<<("================================")<<endl;
        cout<<endl;
        cout<<("Masukan Pilihan Anda ?")<<endl;
        cin>>pil;
        system("cls");
        if(pil=='1')
        {
            menutambah();
        }
        else if(pil=='2')
        {
            menutampilan();
        }
        else if(pil =='3')
        {
            hapusdata();

        }
        else if( pil=='4')
        {
            cari();
        }
        else if (pil== '6')
        {
            keluar = false;
        }
        else if (pil=='5'){
            edit();
        }

    }
    return 0;

}

void menutambah()
{
    char pil;
    bool keluar;
    keluar = true;
    while (keluar == true)
    {
        system("cls");

        cout<<("================================")<<endl;
        cout<<("|         MENU TAMBAH          |")<<endl;
        cout<<("================================")<<endl;
        cout<<("| 1. DATA ORANG                |")<<endl;
        cout<<("| 2. DATA PENDIDIKAN           |")<<endl;
        cout<<("| 3. DATA RELASI               |")<<endl;
        cout<<("| 4. KEMBALI                   |")<<endl;
        cout<<("================================")<<endl;
        cout<<("Masukan Pilihan Anda ?")<<endl;
        cin >> pil;
        if(pil =='1')
        {
            infotype_parent p;
            adr_parent r;
            cout << "Masukkan Nama : ";
            cin >> p.nama;
            cout << "Masukkan Usia : ";
            cin >> p.usia;
            cout << "Masukkan ID : ";
            cin >> p.ID;
            cout << "Masukkan Jenis Kelamin : ";
            cin >> p.jnl_klmin;
            if(findElm_parent(L_P, p) == NULL)
            {
                r = alokasi_parrent(p);
                info(r).TotalRiwayat = 0;
                insertsorting_parent(L_P, r);

                cout <<"================================"<<endl;
                cout <<"|| BERHASIL MENAMBHAKAN ORANG ||"<<endl;
                cout <<"================================"<<endl;
            }
            else
            {
                cout <<"==========================="<<endl;
                cout <<"|| ID INI SUDAH TRDAFTAR ||"<<endl;
                cout <<"==========================="<<endl;
            }

            getch();
        }
        else if(pil == '2')
        {
            infotype_child x;
            cout << " Masukkan Jenjang : ";
            cin >> x.jenjang;
            insertLast_child(L_C, Alokasi_child(x));
            cout << "==================================="<<endl;
            cout << "| BERHASIL MENAMBAHKAN PENDIDIKAN |"<<endl;
            cout << "==================================="<<endl;
            getch();

        }
        else if(pil == '3')
        {
            printInfo_parent(L_P);
            infotype_child x;
            infotype_parent p;
            adr_relasi R;
            string id;
            cout << " Masukkan ID : ";
            cin >> id;
            p.ID = id;
            adr_parent Parent = findElm_parent(L_P, p);
            if(Parent != NULL)
            {
                Printinfo_child(L_C);
                string jenjang;
                cout << " Masukkan jenjang : ";
                cin >> jenjang;
                x.jenjang = jenjang;
                adr_child C = findElm_child(L_C, x);


                if(C != NULL)
                {
                    R = alokasi_relasi(C,Parent);
                    insertFirst_relasi(L_R, R);
                    info_(Parent).TotalRiwayat++;

                    cout << "========================"<<endl;
                    cout << "| BERHASIL MENAMBAHKAN |"<<endl;
                    cout << "========================"<<endl;
                }
                else
                {
                    cout << "================="<<endl;
                    cout << "| JENJANG SALAH | ";
                    cout << "================="<<endl;
                }
            }
            else
            {
                cout << "============"<<endl;
                cout << "| ID SALAH |"<<endl;
                cout << "============"<<endl;
            }
            getch();
        }
        else if(pil=='4')
        {
            keluar = false;
        }
    }
}


void menutampilan()
{
    char pil;
    bool keluar;
    keluar = true;
    while (keluar == true)
    {
        system("cls");
        cout<<("=========================================================================")<<endl;
        cout<<("|                          MENU TAMPILAN                                |")<<endl;
        cout<<("=========================================================================")<<endl;
        cout<<("| 1. DATA KESELURUHAN ORANG DAN DATA RIWAYAT PENDIDIKANYA               |")<<endl;
        cout<<("| 2. DATA RIWAYAT PENDIDIKAN YANG DIMILIKI ORANG TERTENTU               |")<<endl;
        cout<<("| 3. DATA ORANG YANG MEMILIKI RIWAYAT PENDIDIKAN TERTENTU               |")<<endl;
        cout<<("| 4. DATA PALING BANYAK RIWAYAT PENDIDIKANYA                            |")<<endl;
        cout<<("| 5. DATA PALING SEDIKIT RIWAYAT PENDIDIKANYA                           |")<<endl;
        cout<<("| 6. DATA ORANG                                                         |")<<endl;
        cout<<("| 7. DATA JENJANG PENDIDIKAN                                            |")<<endl;
        cout<<("| 8. KEMBALI                                                            |")<<endl;
        cout<<("=========================================================================")<<endl;
        cout<<("Masukan Pilihan Anda ?")<<endl;
        cin >> pil;
        if(pil=='8')
        {
            keluar = false;
        }
        else if(pil == '2')
        {
            adr_relasi P;
            infotype_parent a;
            cout << "Masukkan Nama : ";
            cin >> a.nama;
            P = FindNelmRP(L_R,a);
            if ( P == NULL)
            {
                cout<<"========================"<<endl;
                cout<<"| NAMA TIDAK DITEMUKAN |"<<endl;
                cout<<"========================"<<endl;
                getch();

            }
            else
            {
                while(P != NULL)
                {
                    if(info(parent(P)).nama==a.nama)
                    {
                        cout << "Nama = " << info_(parent(P)).nama
                             << " Jenis Kelamin = " << info_(parent(P)).jnl_klmin
                             << " ID = " << info_(parent(P)).ID
                             << " Usia = " << info_(parent(P)).usia
                             << " Total Riwayat = "<<info(parent(P)).TotalRiwayat
                             << " Jenjang = " << info(child(P)).jenjang << endl;
                    }
                    P = next(P);
                    getch();
                }
            }
        }
        else if(pil == '1')
        {
            printRelasi(L_R);
            getch();
        }
        else if(pil=='3')
        {
            adr_relasi P;
            infotype_child a;
            cout << "Masukkan jenjang : ";
            cin >> a.jenjang;
            P = FindNelmRC(L_R,a);
            if ( P == NULL)
            {
                cout<<"==========================="<<endl;
                cout<<"| JENJANG TIDAK DITEMUKAN |"<<endl;
                cout<<"==========================="<<endl;
                getch();

            }
            else
            {
                while(P != NULL)
                {
                    if(info(child(P)).jenjang == a.jenjang)
                    {
                        cout << "Nama = " << info_(parent(P)).nama
                             << " Jenis Kelamin = " << info_(parent(P)).jnl_klmin
                             << " ID = " << info_(parent(P)).ID
                             << " Usia = " << info_(parent(P)).usia
                             << " Total Riwayat = "<<info(parent(P)).TotalRiwayat
                             << " Jenjang = " << info(child(P)).jenjang << endl;
                    }
                    P = next(P);
                    getch();
                }
            }

        }
        else if (pil=='6')
        {
            printInfo_parent(L_P);
            getch();

        }
        else if (pil =='7')
        {
            Printinfo_child(L_C);
            getch();
        }
        else if (pil=='4')
        {
            MaxRiwayat(L_R);
            getch();
        }
        else if (pil=='5')
        {
            MinRiwayat(L_R);
            getch();
        }
    }
}



void hapusdata()
{
    char pil;
    bool keluar;
    keluar = true;
    while (keluar == true)
    {
        system("cls");
        cout<<("================================")<<endl;
        cout<<("|         MENU HAPUS           |")<<endl;
        cout<<("================================")<<endl;
        cout<<("| 1. DATA ORANG                |")<<endl;
        cout<<("| 2. DATA PENDIDIKAN           |")<<endl;
        cout<<("| 3. KEMBALI                   |")<<endl;
        cout<<("================================")<<endl;
        cout<<("Masukan Pilihan Anda ?")<<endl;
        cin >> pil;
        if(pil=='3')
        {
            keluar = false;
        }
        else if(pil=='1')
        {
            adr_parent P;
            adr_relasi R;
            infotype_parent x;
            cout << endl;
            cout << " Masukkan ID : "<<endl;
            cin >> x.ID;
            P = findElm_parent(L_P,x);
            if (P == NULL)
            {
                cout << "======================"<<endl;
                cout << "| ID TIDAK DITEMUKAN |"<<endl;
                cout << "======================"<<endl;
                getch();
            }
            else
            {
                R = findElm_RP(L_R,P);
                while (R != NULL)
                {
                    delData_Relasi(L_R,R);
                    R = findElm_RP(L_R,P);
                }
                delete_parent(L_P,P);
                cout<<"==========================="<<endl;
                cout<<"| BERHASIL MENGHAPUS DATA |"<<endl;
                cout<<"==========================="<<endl;
                getch();

            }
        }
        else if(pil == '2')
        {
            adr_child P;
            adr_relasi R;
            infotype_child x;
            cout << endl;
            cout << " MASUKAN JENJANG : "<<endl;
            cin >> x.jenjang;
            P = findElm_child(L_C,x);
            if (P == NULL)
            {
                cout << "======================"<<endl;
                cout << "| JENAJANG TIDAK DITEMUKAN |"<<endl;
                cout << "======================"<<endl;
                getch();
            }
            else
            {
                R = findElm_RC(L_R,P);
                while (R != NULL)
                {
                    info_(parent(R)).TotalRiwayat--;
                    delData_Relasi(L_R,R);
                    R = findElm_RC(L_R,P);
                }
                deletechild__(L_C,x);
                cout<<"==========================="<<endl;
                cout<<"| BERHASIL MENGHAPUS DATA |"<<endl;
                cout<<"==========================="<<endl;
                getch();

            }


        }
    }
}



void cari()
{
    char pil;
    bool keluar;
    keluar = true;
    while (keluar == true)
    {
        system("cls");
        cout<<("================================")<<endl;
        cout<<("|         MENU CARI            |")<<endl;
        cout<<("================================")<<endl;
        cout<<("| 1. DATA ORANG                |")<<endl;
        cout<<("| 2. DATA PENDIDIKAN           |")<<endl;
        cout<<("| 3. KEMBALI                   |")<<endl;
        cout<<("================================")<<endl;
        cout<<("Masukan Pilihan Anda ?")<<endl;
        cin >> pil;
        if(pil=='3')
        {
            keluar = false;
        }
        else if(pil == '1')
        {
            adr_parent P;
            infotype_parent a;
            cout << "Masukkan ID : ";
            cin >> a.ID;
            P = findElm_parent(L_P,a);
            if ( P == NULL)
            {
                cout<<"======================"<<endl;
                cout<<"| ID TIDAK DITEMUKAN |"<<endl;
                cout<<"======================"<<endl;
                getch();

            }
            else
            {
                cout << endl;
                cout<<" Nama               : " << info_(P).nama << endl;
                cout<<" Usia               : " << info_(P).usia<< endl;
                cout<<" ID                 : " << info_(P).ID << endl;
                cout<<" Jenis Kelamin      : " << info_(P).jnl_klmin << endl;
                getch();

            }
        }
        else if(pil=='2')
        {
            adr_child X;
            infotype_child b;
            cout << "Masukkan Jenjang : ";
            cin >> b.jenjang;
            X = findElm_child(L_C, b);
            if ( X == NULL)
            {
                cout<<"==========================="<<endl;
                cout<<"| JENJANG TIDAK DITEMUKAN |"<<endl;
                cout<<"==========================="<<endl;
                getch();

            }
            else
            {
                cout << endl;
                cout<<" Jenjang               : " << info(X).jenjang << endl;
                getch();

            }

        }

    }

}


void edit()
{
    char pil;
    bool keluar;
    keluar = true;
    while (keluar == true)
    {
        system("cls");
        cout<<("================================")<<endl;
        cout<<("|         MENU EDIT            |")<<endl;
        cout<<("================================")<<endl;
        cout<<("| 1. DATA ORANG                |")<<endl;
        cout<<("| 2. DATA PENDIDIKAN           |")<<endl;
        cout<<("| 3. KEMBALI                   |")<<endl;
        cout<<("================================")<<endl;
        cout<<("Masukan Pilihan Anda ?")<<endl;
        cin >> pil;
        if(pil=='3')
        {
            keluar = false;
        }
        else if(pil == '1')
        {
            adr_parent P;
            infotype_parent a;
            cout << "Masukkan ID : ";
            cin >> a.ID;
            P = findElm_parent(L_P,a);
            if ( P == NULL)
            {
                cout<<"======================"<<endl;
                cout<<"| ID TIDAK DITEMUKAN |"<<endl;
                cout<<"======================"<<endl;
                getch();

            }
            else{
                cout<<"========================"<<endl;
                cout<<"|   Pengeditan Data   |"<<endl;
                cout<<"========================"<<endl;
                if (P != NULL)
                {

                cout<<"Masukan Nama  = ";
                cin>>info_(P).nama;
                cout<<"Masukan Jenis Kelamin    = ";
                cin>>info_(P).jnl_klmin;
                cout<<"Masukan Umur = ";
                cin>>info_(P).usia;
                getch();
                cout<<"============================="<<endl;
                cout<<"|  BERHASIL MENGEDIT DATA   |"<<endl;
                cout<<"============================="<<endl;
                }
                getch();
            }
        }
        else if(pil=='2')
        {
            adr_child X;
            infotype_child b;
            cout << "Masukkan Jenjang : ";
            cin >> b.jenjang;
            X = findElm_child(L_C, b);
            if ( X == NULL)
            {
                cout<<"==========================="<<endl;
                cout<<"| JENJANG TIDAK DITEMUKAN |"<<endl;
                cout<<"==========================="<<endl;
                getch();

            }
            else
            {
                cout << endl;
                cout<<" Jenjang               : " << info(X).jenjang << endl;
                getch();

            }

        }

    }

}












