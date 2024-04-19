//20.12.1564 Indra Al Farizi
//20.12.1833 Baharuddin Purnomo Aji

#include <iostream>
#include <string.h>
#include<stdio.h>
#define n 300


using namespace std;
int i = 0;
char a;
int c = 0;
int pilih,ketemu;
string cari;

struct queue{
    int awal,akhir;
}queue;

struct waktu{
    string hari ;
    int tanggal ;
};
struct pulsa{
    int pul ;
};
struct billing
{
    string user;
    waktu w;
    pulsa p;
};

billing bill[10];



void pesan()
{
    cout<<endl;
    cout<<"------Data Kostumer------ "<<endl;
    cout<<"Nama : "; cin>>bill[i].user;
    cout<<"Hari : "; cin>>bill[i].w.hari;
    cout<<"Tanggal : "; cin>>bill[i].w.tanggal;
    cout<<"Pulsa : "; cin>>bill[i].p.pul;
    cout<<"===============================";
    cout<<endl;
    i++;
    for(int x=0;x<i-1;x++)
    {
        for(int y=x+1;y<i;y++)
        {
            if(bill[x].w.tanggal>bill[y].w.tanggal)
            {
                billing temp=bill[y];
                bill[y]=bill[x];
                bill[x]=temp;
            }
        }
    }
}
void search(){
    cout<<"\nInput Hari yang dicetak : ";
    cin>>cari;
    cout<<endl;

    ketemu=0;
    for(i=0; i<=7; i++)
    {
        if (bill[i].w.hari==cari)
        {
            ketemu=1;
            cout<<"-----------------"<<endl;
            cout<<"Hari : "<<bill[i].w.hari<<endl;
            cout<<"-----------------"<<endl;
            cout<<"Nama : "<<bill[i].user<<endl;
            cout<<"Tanggal : "<<bill[i].w.tanggal<<endl;
            cout<<"Pulsa : "<<bill[i].p.pul<<endl;
            cout<<"======================================="<<endl;
        }
    }

    if(ketemu==0)
    {
        cout<<"Data tidak ditemukan"<<endl;
    }
}

void init() {
    queue.awal = -1;
    queue.akhir = 0;
    cout << "Data berhasil di reset" << endl<< endl;
}


bool isFull() {
    if (queue.akhir == n-1){
        return true;
    } else {
        return false;
    }
}
bool isEmpty() {
    if (queue.akhir == 0){
        return true;
    }else {
        return false;
    }
}
void inqueue (){
    if (!isFull()) {
        bill[queue.akhir]= bill[c];
        ++queue.akhir;
        c++;
    } else {
        cout<<"-----------------"<<endl;
        cout << "Data penuh" ;
        cout<<"-----------------"<<endl;
    }
}

void dequeue () {
    if(!isEmpty()) {
        for(int i = queue.awal; i < queue.akhir;i++){
            bill[i] = bill[i+1];
        } queue.akhir--;
        cout << "Data berhasil dihapus" << endl;
        cout << endl;
    }else{
        cout<<"-----------------"<<endl;
        cout << "antrian kosong" << endl;
        cout<<"-----------------"<<endl;
    }
}

void stop(){
    cout<<"===== TERIMAKASIH !! ====="<<endl;}
void tampil() {
    if(!isEmpty()) {
        for(int i = 0; i < queue.akhir; i++) {
            cout<<"-----------------"<<endl;
            cout<<"Username : "<<bill[i].user<<endl;
            cout<<"-----------------"<<endl;
            cout<<"Hari : "<<bill[i].w.hari<<endl;
            cout<<"Tanggal : "<<bill[i].w.tanggal<<endl;
            cout<<"Pulsa : "<<bill[i].p.pul<<endl;
            cout<<"=============================="<< endl;}
    }else {
        cout<<"-----------------"<<endl;
        cout << "data kosong" <<endl;
        cout<<"-----------------"<<endl;
        cout << endl << endl;
    }
}

void menu(){
    cout<<"========================="<<endl;
    cout<<"=PROGRAM PEMBELIAN PULSA="<<endl;
    cout<<"========================="<<endl;
    cout<<"1. Pengisian Pulsa\n";
    cout<<"2. Cetak Pembeli\n";
    cout<<"3. Cetak Data Pembeli Sesuai Hari(Senin-Ahad)\n";
    cout<<"4. Hapus Data Pembeli\n";
    cout<<"5. Reset\n";
    cout<<"6. Exit\n";

    cout<<">>> "; cin>>pilih;
    if (pilih == 1)
    { pesan();
        inqueue(); }

    else if (pilih == 2)
    {  tampil();  }

    else if (pilih == 3)
    {  search(); }

    else if (pilih == 4)
    {  dequeue(); }

    else if (pilih == 5)
    {  init(); }

    else
    {
        stop();
    }
    cout << "\nmenu? y/n";
    cin >> a;
    if (a == 'y')
    {menu();}

}


int main(){
    menu();

}