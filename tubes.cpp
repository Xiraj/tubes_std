#include "tubes.h"

void create_List(List &ListChild){
    first(ListChild) = NULL;
}

void newElm_Parent(parent info, adrParent &S){
    S = new elmParent;
    info(S) = info;
    next(S) = NULL;
    nextChild(S) = NULL;
}

void newElm_Child(infotypeCh info, adrChild &J){
    J = new elmChild;
    info(J) = info;
    next(J) = NULL;
}

void insertNew_Child(List &ListParent, adrParent S, adrChild J){
    if (nextChild(S) == NULL) {
        nextChild(S) = J;
    } else {
        adrChild P = nextChild(S);
        while (next(P) != NULL){
            P = next(P);
        }
        next(P) = J;
    }
}

void inserLast_Parent(List &ListParent, adrParent S){ //tambah kelas
    if (first(ListParent) == NULL) {
        first(ListParent) = S;
    } else {
        adrParent P = first(ListParent);
        while (next(P) != NULL){
            P = next(P);
        }
        next(P) = S;
    }
}

void deleteFirst_Child(List &ListParent, adrParent &S, adrChild &J){ //delete data mahasiswa
    adrChild P = nextChild(S);
    J = nextChild(S);
    if (next(P) == NULL) {
        nextChild(S) = NULL;
    } else {
        nextChild(S) = next(P);
        next(P) = NULL;
    }
}

void deleteAfter_Child(List &ListChild, adrChild Prec, adrChild &J){ //delete data mahasiswa
    J = next(Prec);
    next(Prec) = next(J);
    next(J) = NULL;
}

adrChild searchBefore_Child(List ListParent, string nim, string ID){ //mencari data mahasiswa
    adrParent R = first(ListParent);
    while (R != NULL){
        if (info(R).kelas == nim){
            adrChild P = next(nextChild(R));
            adrChild Q = nextChild(R);
            while(next(P) != NULL){
                if (info(P).nim == ID){
                    return Q;
                }
                Q = P;
                P = next(P);
            }
            return Q;
        }
        R = next(R);
    }
}

void deleteFirst_Parent(List &ListParent){ //delete kelas
    adrParent P;
    if (first(ListParent)==NULL){
        cout<< "LIST KOSONG"<<endl;
    }else{
        P = first(ListParent);
        first(ListParent) = next(P);
        next(P) = NULL;
    }
}

void deleteAfter_Parent(adrParent Prec, adrParent P){ //delete kelas
    P = next(Prec);
    next(Prec) = next(P);
    next(P) = NULL;
}

adrParent searchBefore_Parent(List ListParent, string kelas){ //mencari kelas
    adrParent P = next(first(ListParent));
    adrParent Q = first(ListParent);
    while (next(P) != NULL) {
        if (info(P).kelas == kelas){
            return Q;
        }
        Q = P;
        P = next(P);
    }
    return Q;
}

void showData_Parent(List ListParent){ //menampilkan kelas
    int i = 1;
    if (first(ListParent) == NULL) {
        cout << "LIST KOSONG" << endl<<endl;
    } else {
        adrParent P = first(ListParent);
        while (P != NULL){
            adrChild Q = nextChild(P);
            cout << i << ". "<< info(P).kelas << endl;
            i++;
            P = next(P);
        }
    }
    cout << endl;
}

void showData_Child(List ListParent){ //menampilkan data mahasiswa
    string input;
    int i = 1;
    if (first(ListParent) == NULL) {
        cout << "LIST KOSONG" << endl<<endl;
    } else {
        adrParent P = first(ListParent);
        cout << "List kelas :" << endl;
        while (P != NULL){
            cout << i << ". "<< info(P).kelas << endl;
            i++;
            P = next(P);
        }
        cout << "Masukkan Kelas mahasiswa yang ingin ditampilkan : ";
        cin >> input;
        P = first(ListParent);
        while (P != NULL){
            adrChild Q = nextChild(P);
            if (info(P).kelas == input){
                while(Q != NULL){
                cout << "Nama lengkap : " << info(Q).nama_Lengkap << endl;
                cout << "NIM  : " << info(Q).nim << endl;
                cout << "Email  : " << info(Q).email << endl;
                cout << "Jurusan  : " << info(Q).jurusan_mhs << endl;
                cout << "Fakultas  : " << info(Q).fakultas_mhs;
                cout << endl;
                Q = next(Q);
                }
            }
            P = next(P);
        }
    }
}

adrParent search_Parent(List ListChild, string kelas){ //mencari kelas
    adrParent P = first(ListChild);
    while (P != NULL) {
        if (info(P).kelas == kelas){
            return P;
        }
        P = next(P);
    }
    return NULL;
}

adrChild search_Child(List ListParent, string nim){ //mencari data mahasiswa
    adrParent P = first(ListParent);
    while (P != NULL) {
        adrChild Q = nextChild(P);
        while(Q != NULL){
          if (info(Q).nim == nim){
            return Q;
          }
          Q = next(Q);
        }
        P = next(P);
    }
    return NULL;
}

void cari_Child(List ListParent, string nim){ //mencari data mahasiswa
  adrParent P = first(ListParent);
  adrChild C = search_Child(ListParent, nim);
  if (first(ListParent) == NULL){
    cout << "==================================" << endl;
    cout << "| Mahasiswa tidak dapat ditemukan |" << endl;
    cout << "==================================" << endl;
  }else if(P != NULL){
    P = first(ListParent);
    while(P != NULL){
      adrChild Q = nextChild(P);
        while(Q != NULL){
          if (info(Q).nim == nim && C != NULL){
              if(C != NULL){
                  cout << "==================================" << endl;
                  cout << "Nama lengkap   : " << info(Q).nama_Lengkap << endl;
                  cout << "NIM    : " << info(Q).nim << endl;
                  cout << "Email    : " << info(Q).email << endl;
                  cout << "Jurusan  : " << info(Q).jurusan_mhs << endl;
                  cout << "Fakultas  : " << info(Q).fakultas_mhs << endl;
                  cout << "==================================" << endl;
              }
          } else if(C == NULL) {
              cout << "==================================" << endl;
              cout << " NIM Tidak Dapat Ditemukan" << endl;
              cout << "==================================" << endl;
          }
          cout << endl;
          Q = next(Q);
        }
      P = next(P);
    }
  }
}
int selectMenu() {
    cout << "----------------------------------------------------------" << endl;
    cout << "\tPROGRAM DATA MAHASISWA" << endl;
    cout << "----------------------------------------------------------" << endl;

    cout << "1. Tambah Kelas\n";
    cout << "2. Tambah Mahasiswa\n";
    cout << "3. Menampilkan Kelas\n";
    cout << "4. Menampilkan Mahasiswa\n";
    cout << "5. Delete Kelas\n";
    cout << "6. Delete Mahasiswa\n";
    cout << "7. Cari Mahasiswa\n";
    cout << "0. Keluar" << endl << endl;
    cout << "Pilihan menu : " ;
    int input;
    cin >> input;
    cout << endl;

    return input;
}
