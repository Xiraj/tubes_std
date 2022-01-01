#include "tubes.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

int main(){
    List L;
    parent P;
    infotypeCh C;
    adrParent S, precPr;
    adrChild J, precCh;

    int pilihan, x;
    string yesOrno;

    create_List(L);

    pilihan = selectMenu();

    while (pilihan != 0) {
        switch (pilihan){
            case 1:
                {
                string input;
                cout << "Masukkan Kelas : ";
                cin >> input;
                P.kelas = input;
                newElm_Parent(P, S);
                inserLast_Parent(L, S);
                cout << "===========================" << endl;
                cout << "Kelas Berhasil Ditambah" << endl;
                cout << "===========================" << endl;
                while (yesOrno != "y"){
                    cout << "Kembali Ke Menu Utama (y/n): "; cin >> yesOrno;
                    if (yesOrno == "y"){
                        break;
                    }
                }
                cout << endl;
                yesOrno = "n";
                system("cls");
                break;
                }

            case 2:
                {
                string nama_lengkap, nim, email, jurusan_mhs, fakultas_mhs, kelas;
                cout << "Masukkan Nama Kelas : ";
                cin >> kelas;
                S = search_Parent(L, kelas);
                if (S != NULL){
                    cout << "Masukkan Data Mahsiswa baru" << endl;
                    cout << "Nama Lengkap : ";
                    cin >> nama_lengkap;
                    cout << "NIM : ";
                    cin >> nim;
                    cout << "Email : ";
                    cin >> email;
                    cout << "Jurusan : ";
                    cin >> jurusan_mhs;
                    cout << "Fakultas : ";
                    cin >> fakultas_mhs;
                    C.nama_Lengkap = nama_lengkap;
                    C.nim = nim;
                    C.email = email;
                    C.jurusan_mhs = jurusan_mhs;
                    C.fakultas_mhs = fakultas_mhs;

                    newElm_Child(C,J);
                    insertNew_Child(L,S,J);
                    cout << "===============================" << endl;
                    cout << "Mahasiswa Berhasil Di Tambah" << endl;
                    cout << "===============================" << endl;
                } else if (S == NULL){
                    cout << "===============================" << endl;
                    cout << "Mahasiswa Tidak Ditemukan" << endl;
                    cout << "===============================" << endl;
                }
                while (yesOrno != "y"){
                    cout << "Kembali Ke Menu Utama (y/n): "; cin >> yesOrno;
                    if (yesOrno == "y"){
                        break;
                    }
                }
                cout << endl;
                yesOrno = "n";
                system("cls");
                break;
                }

            case 3:
                {
                showData_Parent(L);
                while (yesOrno != "y"){
                    cout << "Kembali Ke Menu Utama (y/n): "; cin >> yesOrno;
                    if (yesOrno == "y"){
                        break;
                    }
                }
                cout << endl;
                yesOrno = "n";
                system("cls");
                break;
                }

            case 4:
                {
                showData_Child(L);
                while (yesOrno != "y"){
                    cout << "Kembali Ke Menu Utama (y/n): "; cin >> yesOrno;
                    if (yesOrno == "y"){
                        break;
                    }
                }
                cout << endl;
                yesOrno = "n";
                system("cls");
                break;
                }

            case 5:
                {
                string kelas;
                cout << "Masukkan Kelas yang ingin dihapus : ";
                cin >> kelas;
                adrParent p;
                p = first(L);
                if (p == NULL){
                    cout << "===================================" << endl;
                    cout << "Kelas Tidak Ditemukan" << endl;
                    cout << "===================================" << endl;
                }else if (info(p).kelas == kelas){
                    deleteFirst_Parent(L);
                    cout << "===================================" << endl;
                    cout << "Kelas:  " << info(p).kelas << " Berhasil Dihapus" << endl;
                    cout << "===================================" << endl;
                }else if (next(p)!=NULL){
                    precPr = searchBefore_Parent(L, kelas);
                    deleteAfter_Parent(precPr, S);
                    cout << "===================================" << endl;
                    cout << "Kelas " << info(p).kelas << " Berhasil DiHapus" << endl;
                    cout << "===================================" << endl;
                }else{
                    cout << "===================================" << endl;
                    cout << "Kelas " << kelas << " TIDAK DI TEMUKAN" << endl;
                    cout << "===================================" << endl;
                }
                while (yesOrno != "y"){
                    cout << "Kembali Ke Menu Utama (y/n): "; cin >> yesOrno;
                    if (yesOrno == "y"){
                        break;
                    }
                }
                cout << endl;
                yesOrno = "n";
                system("cls");
                break;
                }

            case 6:
                {
                string kelas, nim;
                cout << "Masukkan Kelas: ";
                cin >> kelas;
                cout << "Masukkan Nim Yang Ingin Di Hapus : ";
                cin >> nim;
                adrChild c;
                adrParent P;
                P = first(L);
                if (P == NULL){
                    cout << "======================" << endl;
                    cout << "Kelas Tidak Ada" << endl;
                    cout << "======================" << endl;
                }
                while (P != NULL){
                    adrChild Q = nextChild(P);
                    if (info(P).kelas == kelas){
                        if (info(Q).nim==nim){
                            deleteFirst_Child(L, P, J);
                            cout << "======================" << endl;
                            cout << "Nama : " << info(Q).nama_Lengkap << endl;
                            cout << "nim  : " << info(Q).nim << endl;
                            cout << "Tanggal Lahir  : " << info(Q).email << endl;
                            cout << "Tempat Lahir  : " << info(Q).jurusan_mhs << endl;
                            cout << "fakultas_mhs  : " << info(Q).fakultas_mhs << endl;
                            cout << "======================" << endl;
                            cout << "DATA BERHASIL DIHAPUS" << endl;
                            cout << "======================" << endl;
                        }else if (next(Q)!= NULL){
                            precCh = searchBefore_Child(L, kelas, nim);
                            deleteAfter_Child(L, precCh, J);
                            cout << "======================" << endl;
                            cout << "Nama : " << info(Q).nama_Lengkap << endl;
                            cout << "nim  : " << info(Q).nim << endl;
                            cout << "Tanggal Lahir  : " << info(Q).email << endl;
                            cout << "Tempat Lahir  : " << info(Q).jurusan_mhs << endl;
                            cout << "fakultas_mhs  : " << info(Q).fakultas_mhs << endl;
                            cout << "======================" << endl;
                            cout << "DATA BERHASIL DIHAPUS" << endl;
                            cout << "======================" << endl;
                        }else{
                            cout << "nim TIDAK DITEMUKAN" << endl;
                        }
                    }

                    P = next(P);

                }
            }

            case 7:
                {
                string nim;
                cout << "Masukkan NIM Yang Ingin Di Cari: ";
                cin >> nim;
                cari_Child(L, nim);
                while (yesOrno != "y"){
                    cout << "Kembali Ke Menu Utama (y/n): "; cin >> yesOrno;
                    if (yesOrno == "y"){
                        break;
                    }
                }
                cout << endl;
                yesOrno = "n";
                system("cls");
                break;
                }
        }
        pilihan = selectMenu();
    }

    cout << "ANDA TELAH KELUAR DARI PROGRAM DAFTAR MAHASISWA" << endl << endl;
    return 0;
}
