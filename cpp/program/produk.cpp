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

/* Deklarasi header custom */
#include "header.hpp"

/* Deklarasi kelas */

// Deklarasi konstruktor, inisialisasi atribut angka menjadi -1
Produk::Produk() {
    this->harga = -1;
    this->stok = -1;
    this->garansi = "N/A";
};

// Fungsi setter untuk membuat produk baru

Produk Produk::create(int id, string nama, string deskripsi, string tipe, string target_instalasi, string merek, int harga, int stok, string garansi) {
    // Set data barang/item
    this->setId(id);
    this->setNama(nama);
    this->setDeskripsi(deskripsi);

    // Set data tipe
    this->setTipe(tipe);
    this->setTargetInstalasi(target_instalasi);
    this->setMerek(merek);

    // Set data produk
    this->harga = harga;
    this->stok = stok;
    this->garansi = garansi;
    return *this;
}

// Fungsi setter untuk menentukan harga dari suatu produk
void Produk::setHarga(int harga) {
    this->harga = harga;
};

// Fungsi setter untuk menentukan stok dari suatu produk
void Produk::setStok(int stok) {
    this->stok = stok;
};

// Fungsi setter untuk menentukan metode garansi dari suatu produk
void Produk::setGaransi(string garansi) {
    this->garansi = garansi;
};

// Fungsi getter untuk mendapatkan harga dari suatu produk
int Produk::getHarga() {
    return harga;
};

// Fungsi getter untuk mendapatkan stok dari suatu produk
int Produk::getStok() {
    return stok;
};

// Fungsi getter untuk mendapatkan metode garansi dari suatu produk
string Produk::getGaransi() {
    return garansi;
};

// Deklarasi destruktor
Produk::~Produk() {
    this->harga = -1;
    this->stok = -1;
    this->garansi = "";
};
