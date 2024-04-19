#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

struct hello {
    char nama[100];
};


int main() {
    struct hello hello;
    cout<<"Program Hello World \n"<<endl;

    char cari;
    string str;
    char temp;
    int tot=0;
    int max = 4;
    int top = -1;
    string tim[max];
    string next;

    do {
        system("cls");
        if(top == max - 1) {
            cout<<"Kelompok Sudah Penuh"<<endl;
        } else {
            top++;
            cout<<"Masukkan Nama Anggota Kelompok: ";
            cin>>tim[top];
            cout<<"Nama Anggota "<<tim[top]<<" Berhasil Ditambahkan"<<endl;
        }
        cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
        cout<<"Tim Hello World Saat Ini Adalah : "<<endl;
        for (int i = 0; i <= top; i++) {
            cout<<i+1<<". "<<tim[i]<<endl;
        }
        cout<<"Masih Ada Tim Yang Belum Dimasukkan? (y/n)= ";
        cin>>next;
    } while (next == "y");
    cout<<"Data Kelompok Selesai Ditambahkan"<<endl;
    cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
    cout<<"Tim Hello World Saat Ini Telah Lengkap : "<<endl;
    cout<<"Tahap Selanjutnya Silahkan Mengikuti Prosedur Program : "<<endl;
    cout<<endl;

    cout<<"Ketikan Data = ";
    cin>>hello.nama,sizeof(hello.nama);
    for(int i=0; i<=hello.nama[i]; i++) {
        cout<<"\ndata ke -"<<i+1<<" "<<hello.nama[i];
    }

    str = hello.nama;
    int len = str.length();
    cout << "\n Sebelum sorting: " << str << " \n";

    for (int i = 0; i < len; i++){

        for (int j = 0; j < len - 1; j++){
            if (str[j] > str[j + 1]){
                temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }

    cout << "\n Setelah sorting: " << str << " \n";

    cout<<"\nMasukkan data yang ingin anda cari : ";cin>>cari;
    for(int i=0;i<=hello.nama[i];i++){
        if(hello.nama[i]==cari){
            cout<<"Data "<<cari<<" ditemukan pada urutan ke-"<<i+1<<endl;
            tot+=1;
        }
    }
    if(tot!=0){
        cout<<"Data "<<cari<<" berjumlah "<<tot;
    }
    else{
        cout<<"Data tidak ditemukan!!!";
    }


    getch();
}
