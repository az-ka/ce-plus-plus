#include <iostream>
#define n 10 //batas dari penggunaan queue / strack
using namespace std;

int awal=-1;
int akhir=-1;

//STRUCT
struct pasien{	//Ini adalah bagian penggunaan struct
    string nama, pasien;
    string nik;
    int  penyakit;
    int otg;
    string cari;
//ARRAY DALAM STRUCT
}Psn[n];	//ini nama object structnya serta [n] adalah array di dalam struct

struct queue{	//penggunaan struct untuk queue
    int awal, akhir;
}Queue;	//nama object dari struct queue

// di bawah ini adalah fungsi atau bisa di sebut prototype fungsi dari program queue ini

void deQueue();
void menu();
void inQueue();
void tampil();

void reset(){
    Queue.awal = -1;
    Queue.akhir = -1;
    cout << "Data berhasil di reset" << endl << endl;
    menu();
}

bool isFull(){	//pengecekan antrian sudah penuh bisa menggunakan fungsi isFull
    if(Queue.akhir == n - 1){
        return true;
    } else {
        return false;
    }
}

bool isEmpty(){	//pengecekan antrian apakah masih kosong bisa menggunakan fungsi isEmpty
    if(Queue.akhir == -1){
        return true;
    }else {
        return false;
    }
}
//SEARCHING
void cari (){	//mencari data mahasiswa
    string nik;
    string cari;

    cout<<"Nik yang dicari: ";
    cin>>cari;
    Psn[Queue.akhir].cari = cari;

    if(cari != nik) {

        cout<<"Nik ditemukan ";
    }
    else{
        cout<<"Nik tidak ditemukan ";
    }
    menu();
    cout<<"====================================="<<endl;
}

void inQueue(){	//fungsi queue yang berguna untuk memasukan beberapa data kedalam program queue ini
    if(!isFull()){
        string nama, pasien;
        string nik;
        int penyakit ;
        int otg;
        string program;

        cout<<"====================================="<<endl;
        cout<<"        INPUT DATA DI BAWAH INI      "<<endl;
        cout<<"====================================="<<endl;
        cout<<"Masukkan Nama Pasien : ";
        cin>>nama pasien;
        Psn[Queue.akhir].pasien = pasien;

        cout<<"Masukkan NIk pasien  : ";
        cin>>nik;
        Psn[Queue.akhir].nik = nik;

        cout<<"Masukkan Status Pasen       : ";
        cin>>nik;
        Psn[Queue.akhir].nik = nik;
        cout<<"====================================="<<endl;
        cout<<"DARURAT"<<endl;
        cout<<"====================================="<<endl;
        cout<<"\n1 : MERAH";
        cout<<"\n2 : KUNING";
        cout<<"\n3 : HIJAU";
        cout<<"\n4 : BIRU";
        cout<<"====================================="<<endl;
        cout<<"kamar Inap           : ";
        cin>>inap;
        Psn[Queue.akhir].inap = inap;

        if(inap==1 || inap==2)
        {biaya_ditanggung bpjs=120000;}
        else if(inap==3 || inap==4)
        {biaya_mandiri=15000;}

        cout<<"Masukkan Jumlah Dirawat     : ";
        cin>>dirawat;
        Psn[Queue.akhir].dirawat = dirawat;
        cout<<endl;
        total=dirawat*biaya_dirawat;
        Psn[Queue.akhir].total = total;

        ++Queue.akhir;
        cout << endl;
        menu();
        cout<<"====================================="<<endl;
    }else {
        cout << "Data penuh";
        menu();	//Jika data sudah penuh maka akan kembali ke menu
    }
}

void menu(){	//fungsi untuk memilih menu di program ini
    int pilih;
    cout<<"\n====================================="<<endl;
    cout<<"   PROGRAM PENDATAAN PASIEN COVID-19  "<<endl;
    cout<<"====================================="<<endl;
    cout<<"1. Masukkan Data Pasien\n";
    cout<<"2. Hapus Satu Data Pasien\n";
    cout<<"3. Reset Data Pasien\n";
    cout<<"4. Tampil Data Pasien\n";
    cout<<"5. Cari Data Pasien\n";
    cout<<"6. Exit Program\n";
    cout<<"====================================="<<endl;
    cout<<"Masukkan pilihan anda:";
    cin >> pilih;
    cout << endl;
    if(pilih == 1){
        inQueue();
    }else if(pilih == 2){
        deQueue();
    } else if(pilih == 3){
        reset();
    }else if(pilih == 4){
        tampil();
    }else if(pilih == 5){
        cari();
    }else if (pilih == 6){
    }else{
        menu();
    }
}

void deQueue(){	//fungsi queue untuk menghapus data
    if(!isEmpty()){ //fungsi pengecekan kosong tidaknya data
        for(int i = Queue.awal; i < Queue.akhir; i++){ //perulangan
            Psn[i].nama pasien = Psn[i+1].nama pasien; //perintah untuk menghapus data secara menaik sesuai urutan nomor antrian
            Psn[i].nik = Psn[i+1].nik; //sama
        }Queue.akhir--; //pengurangan data secara menurun
        cout << "Data berhasil dihapus" << endl; //output hasil
        cout << endl;
        menu(); //kembali ke pilihan menu
    }else{
        cout << "antrian kosong" << endl; //kondisi kedua ketika data antrian kosong
    }
}

//SORTING
void tampil(){	//fungsi queue untuk menampilkan / output dari data yang ada di dalam program queue ini
    if(!isEmpty()){
        for(int i = 0; i < Queue.akhir; i++){
            cout<<"================================"<<endl;
            cout<<"         DATA PASIEN         "<<endl;
            cout<<"\n 	NO. Antrian : [" << i+1 << "]"; //bisa dikatakan sorting
            cout<<"\n================================"<<endl;
            cout << "Nama PASIEN   : " << Psn[i].nama pasien << endl;
            cout << "NIK PASIEN    : " << Psn[i].nik << endl;
            cout << "Darurat          : " << Psn[i].darurat << endl;
            cout << "Jumlah Dirawat       : " << Psn[i].inap << endl;
            cout<<"================================"<<endl;
            cout<< 	"TOTAL BAYAR      : "<< Psn[i].total<<endl;
            cout<<"================================"<<endl;
            cout << endl;
        }
    }else {
        cout << "data kosong";
        cout << endl << endl;
    }
    menu();
}

int main(){	//fungsi utama
    menu();	//akan memanggil ke bagian fungsi menu

    return 0;
}