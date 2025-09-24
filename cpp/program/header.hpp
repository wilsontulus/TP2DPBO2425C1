/*
 * LICENSE: All Rights Reserved
 * (c) 2025 Willsoon Tulus P. Simanjuntak
 * (c) 2025 Universitas Pendidikan Indonesia
 *
 * Saya Willsoon Tulus Parluhutan Simanjuntak mengerjakan evaluasi
 * Tugas Praktikum 2 dalam mata kuliah Desain Pemrograman
 * Berorientasi Objek untuk keberkahanNya maka saya tidak
 * melakukan kecurangan seperti yang telah dispesifikasikan.
 * Aamiin.
 */

/* Deklarasi header */
#include <bits/stdc++.h>

/* Deklarasi tipe namespace */

using namespace std;

/* Deklarasi kelas */

// Kelas "Barang" atau juga disebut dengan "Item"
class Barang {
    // Kelas private untuk variabel objek barang
    private:
        int id;
        string nama;
        string deskripsi;

    // Kelas public untuk fungsi dari objek barang
    public:
        // Konstruktor
        Barang();

        // Fungsi setter (write)
        void setId(int id);
        void setNama(string nama);
        void setDeskripsi(string deskripsi);
        void clear();

        // Fungsi getter (read)
        int getId();
        string getNama();
        string getDeskripsi();

        // Destruktor
        ~Barang();
};

// Kelas "Tipe"
class Tipe : public Barang {
    // Kelas private untuk variabel objek tipe
    private:
        string tipe;
        string target_instalasi;
        string merek;

        // Kelas public untuk fungsi dari objek tipe
    public:
        // Konstruktor
        Tipe();

        // Fungsi setter (write)
        void setTipe(string tipe);
        void setTargetInstalasi(string target_instalasi);
        void setMerek(string merek);

        // Fungsi getter (read)
        string getTipe();
        string getTargetInstalasi();
        string getMerek();

        // Destruktor
        ~Tipe();
};

// Kelas "Produk"
class Produk : public Tipe {
    // Kelas public untuk variabel objek Produk
    private:
        int harga;
        int stok;
        string garansi;

        // Kelas public untuk fungsi dari objek Produk
    public:
        // Konstruktor
        Produk();

        // Fungsi setter (write)
        void setHarga(int harga);
        void setStok(int stok);
        void setGaransi(string garansi);
        Produk create(int id, string nama, string deskripsi, string tipe, string target_instalasi, string merek, int harga, int stok, string garansi);

        // Fungsi getter (read)
        int getHarga();
        int getStok();
        string getGaransi();

        // Destruktor
        ~Produk();
};
