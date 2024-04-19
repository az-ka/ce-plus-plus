#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct hello {//struct bernama hello
    char nama[100];//memiliki variabel bertipe data char yaitu nama dengan elemet array 100
};
struct link{
    int data;
    struct link *next;
}linklistket;

int main() {
	linklistket.data=4;
    linklistket.next=(link*)malloc(sizeof(link));//alokasikan memori untuk ditunjuk oleh next
    linklistket.next->data=1;

    struct hello hello;//object struct hello
    cout<<"Program Hello World \n"<<endl;

    char cari;//tipe data char bernama cari
    string str;//tipe data string bernama str atau sorting
    char temp;//tipe data char dengan temp penyimpanan
    int tot=0;// dengan tipe data integer total atau jumlah yang nantinya jumlah dari nilai indeks yang dicari
    int max = 4;// tipe data integer dengan nama max = 4 untuk menemukan batas maksimal dari data yang dimasukan
    int top = -1;//tipe  data integer dengan nama top untuk sebagai fungsi dari pop dari data
    string tim[max]; // tipe data string  dengan nama memasukan atau biasa disebut push
    string next;// fungsi opsi y atau n

    do {
        system("cls");
        printf("Batas list maksimal  : %d\n", linklistket.data);
        printf("list penambahan  : %d\n", linklistket.next->data);
        if(top == max - 1) {//jika pada tumpukan atas melebihi batas maksimum data yang dimasukan akan muncul keluaran
            cout<<"Kelompok Sudah Penuh"<<endl;
        } else {
            top++;
            cout<<"Masukkan Nama Anggota Kelompok: ";
            cin>>tim[top];
            cout<<"Nama Anggota "<<tim[top]<<" Berhasil Ditambahkan"<<endl;//setiap data yang ditambahkan maka akan tampil ditumpukan atas
        }
        cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
        cout<<"Tim Hello World Saat Ini Adalah : "<<endl;
        for (int i = 0; i <= top; i++) {//data prose perulangan dari data yang dimasukan masuk kedalam tumpukan atas
            cout<<i+1<<". "<<tim[i]<<endl;
        }
        cout<<"Masih Ada Tim Yang Belum Dimasukkan? (y/n)= ";//y untuk memasukan data dan n utuk program selanjutnya
        cin>>next;
    } while (next == "y");
    cout<<"Data Kelompok Selesai Ditambahkan"<<endl;
    cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
    cout<<"Tim Hello World Saat Ini Telah Lengkap : "<<endl;
    cout<<"Tahap Selanjutnya Silahkan Mengikuti Prosedur Program : "<<endl;
    cout<<endl;

    cout<<"Ketikan Data = ";
    cin>>hello.nama,sizeof(hello.nama); // memanggil objek hello dengan menampilkan perkata
    for(int i=0; i<=hello.nama[i]; i++) {//perulangan dengan menampilkan data perhuruf dengan baris
        cout<<"\ndata ke -"<<i+1<<" "<<hello.nama[i];
    }

    str = hello.nama;//sorting nama
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
    for(int i=0;i<=hello.nama[i];i++){//perulangan utuk huruf yang akan di searching
        if(hello.nama[i]==cari){//jika nama yang akan di cari
            cout<<"Data "<<cari<<" ditemukan pada urutan ke-"<<i+1<<endl;
            tot+=1;//jumlah dari indeks yang dicari
        }
    }
    if(tot!=0){//jika nilai jumlah dari indeks tidak = 0
        cout<<"Data "<<cari<<" berjumlah "<<tot;//muncul keluaran
    }
    else{//jika tidak
        cout<<"Data tidak ditemukan!!!";
    }


    getch();
}