#include <iostream>
#define n 10
using namespace std;

int cari;
int nikDia;
struct pasien{
    string nama;
    int nik;
}Psn[n];

struct queue{
    int awal, akhir;
}Queue;

void deQueue();
void menu();
void inQueue();
void tampil();

void init(){
    Queue.awal = -1;
    Queue.akhir = -1;
    cout << "Data berhasil di reset" << endl << endl;
    menu();
}

bool isFull(){
    if(Queue.akhir == n - 1){
        return true;
    } else {
        return false;
    }
}

bool isEmpty(){
    if(Queue.akhir == -1){
        return true;
    }else {
        return false;
    }
}

void inQueue(){
    if(!isFull()){
        string nama;
        int nik;
        cout << "Masukkan nama pasien:";
        cin >> nama;
        cout << "Masukkan NIK pasien:";
        cin >> nik;
        Psn[Queue.akhir].nama = nama;
        Psn[Queue.akhir].nik = nik;
        ++Queue.akhir;
        cout << endl;
        menu();
    }else {
        cout << "Data penuh";
        menu();
    }
}

void sorting() {
    for(int i = Queue.awal; i < Queue.akhir; i++) {
        int temp;
        for(int j = i+1; j<Queue.akhir; j++)
        {
            if(Psn[j].nik <Psn[i].nik) {
                temp = Psn[i].nik;
                Psn[i].nik = Psn[j].nik;
                Psn[j].nik = temp;
            }
        }
        cout <<"Urut Dengan Urutan Nik Adalah\n";
        for(i = Queue.awal; i<Queue.akhir; i++) {
            cout <<Psn[i].nik<<"\t";
        }
    }
}

void sercing() {
    cout<<"Masukkan Antrian Pasien Yang Dicari : ";
    cin>>cari;
    int ketemu = 0;
    for (int i = Queue.awal; i <= Queue.akhir; ++i) {
        int nikDia = Psn[i].nik;

        if (nikDia == cari){
            ketemu = 1;
            cout<<"Data Pasien Ditemukan Pada Urutan ke-"<<i<<endl;
        }
    }
    if (ketemu == 0) {
        cout<<"Data Pasien Tidak Ditemukan "<<endl;
    }
}

void menu(){
    int pilih;
    cout << "1. masukkan data\n";
    cout << "2. Hapus satu data\n";
    cout << "3. Reset data\n";
    cout << "4. tampil data\n";
    cout << "5. Sorting data\n";
    cout << "6. Sercing data\n";
    cout << "Masukkan pilihan anda:";
    cin >> pilih;
    cout << endl;
    if(pilih == 1){
        inQueue();
    }else if(pilih == 2){
        deQueue();
    } else if(pilih == 3){
        init();
    }else if(pilih == 4){
        tampil();
    }else if(pilih == 5) {
        sorting();
    }else if (pilih == 6){
        sercing();
    }else {
        menu();
    }
}

void deQueue(){
    if(!isEmpty()){
        for(int i = Queue.awal; i < Queue.akhir; i++){
            Psn[i].nama = Psn[i+1].nama;
            Psn[i].nik= Psn[i+1].nik;
        }Queue.akhir--;
        cout << "Data berhasil dihapus" << endl;
        cout << endl;
        menu();
    }else{
        cout << "antrian kosong" << endl;
    }
}

void tampil(){
    if(!isEmpty()){
        for(int i = 0; i < Queue.akhir; i++){
            cout << "Nama Pasien: " << Psn[i].nama << endl;
            cout << "NIK : " << Psn[i].nik << endl;
            cout << endl;
        }
    }else {
        cout << "data kosong";
        cout << endl << endl;
    }
    menu();
}

int main(){
    menu();

    return 0;
}