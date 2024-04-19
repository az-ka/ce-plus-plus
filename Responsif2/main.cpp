#include <iostream>

using namespace std;

//Tipe Data
int maxAntrian = 10, antrianDepan=0, antrianBelakang=0;
string antrianPasien[10], antrianPasienNik[10];
string str;
string nik;
char temp;
string cari;
int ketemu = 0;

//Bolean Penuh Jika Antrian Belakang Sama Dengan Max Antrian Berarti True Jika Tidak False
bool penuh() {
    if(antrianBelakang == maxAntrian) {
        return true;
    } else {
        return false;
    }
}
//Bolean Kosong Jika antrianBelakang Memiliki Nilai 0 Maka True Jika Tidak Berarti False
bool kosong() {
    if (antrianBelakang == 0) {
        return true;
    } else{
        return false;
    }
}

//Menambahkan Atau Menginputkan Data Pasien
void menambahAntrian(string data, string nik) {
    if (penuh()) {
        cout<<"Antrian Sedang Penuh"<<endl;
    } else{
        if (kosong()){
            antrianPasien[0] = data;
            antrianPasienNik[0] = nik;
            antrianDepan++;
            antrianBelakang++;
        } else{
            antrianPasien[antrianBelakang] = data;
            antrianBelakang++;
        }
    }
}

// Memangil Antiran Terdepan
void panggilAntrian() {
    if (kosong()){
        cout<<"Antrian Sudah Dipanggil "<<endl;
    } else{
        for (int i = 0; i < 10; ++i) {
            antrianPasien[i] = antrianPasien[i+1];
        }
    }
}

//Mengapus Data
void hapusAntrian() {
    if (kosong()){
        cout<<"Antrian Sedang Kosong "<<endl;
    }else{
        for (int i = 0; i < maxAntrian; ++i) {
            antrianPasien[i]="";
        }
    }
}

void  menampilkan(){
    cout<<"Data Antrian Rumah Sakit Kurniawan "<<endl;
    if (kosong()) {
        cout<<"Antrian Sedang Kosong ";
    } else {
        for (int i = 0; i < maxAntrian; ++i) {
            if (antrianPasien[i]!=""){
                cout<<i+1<<"."<<antrianPasien[i]<<" Dengan Nik -"<<antrianPasienNik[i]<<endl;
            } else{
                cout<<i+1<<"."<<"Antrian Sedang Kosong"<<endl;
            }
        }
    }
    cout<<"\n"<<endl;
}

void selectionSort() {

    str = antrianPasien[0];

    int len = str.length();
    cout << "\n Sebelum sorting: " << str;

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
}

void search() {
    cout<<"Masukkan Data Pasien Yang Ingin Dicari = ";
    cin>>cari;
    for (int i = 0; i < 10; ++i) {
        if (antrianPasien[i] == cari) {
            ketemu=1;
            cout<<"Data Pasien Ditemukan Antrian Nomer = "<<i+1<<endl;
        }
    }
    if (ketemu == 0) {
        cout<<"Data Pasien Tidak Ditemukan "<<endl;
    }
}

int main() {
    int pilih;
    string data, next;
    cout<<"Selamat Datang Di Rumah Sakit Kurnia "<<endl;
    cout<<"Silangkan Mengantri Dengan Tertip "<<endl;
    cout<<"Menu=============================="<<endl;
    cout<<"1. Masukkan Nama Antrian Pasien "<<endl;
    cout<<"2. Panggil Antrian "<<endl;
    cout<<"3. Menampilkan Antrian Pasien "<<endl;
    cout<<"4. Menghapus Antrian Pasien "<<endl;
    cout<<"5. Selection Sort "<<endl;
    cout<<"6. Search "<<endl;


    do {
        cout<<"Silahkan Masukkan Pilihan = ";
        cin>>pilih;
        switch (pilih) {
            case 1:
                cout<<"Masukkan Nama Pasien  = ";
                cin>>data;
                cout<<"Silahkan Masukkan Nik Pasein = ";
                cin>>nik;
                menambahAntrian(data, nik);
                break;
            case 2:
                panggilAntrian();
                break;
            case 3:
                menampilkan();
                break;
            case 4:
                hapusAntrian();
                break;
            case 5:
                selectionSort();
                break;
            case 6:
                search();
                break;
            default:
                cout<<"Yang Anda Masukkan Salah "<<endl;
        }
        cout<<"Masih Ada Pasien Yang Belum Mengantri? (y/n)= ";//y untuk memasukan data dan n utuk program selanjutnya
        cin>>next;
    } while (next=="y");

    return 0;
}