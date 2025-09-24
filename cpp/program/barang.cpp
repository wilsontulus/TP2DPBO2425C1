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

// Deklarasi konstruktor, selalu dari ID -1
// untuk menandakan barang yang belum diisi
Barang::Barang() {
    this->id = -1;
};

// Fungsi setter untuk menentukan ID barang
void Barang::setId(int id) {
    this->id = id;
};

// Fungsi setter untuk menentukan nama barang
void Barang::setNama(string nama) {
    this->nama = nama;
};

// Fungsi setter untuk menentukan deskripsi barang
void Barang::setDeskripsi(string deskripsi) {
    this->deskripsi = deskripsi;
};

// Fungsi getter untuk mendapatkan ID barang
int Barang::getId() {
    return id;
};

// Fungsi getter untuk mendapatkan nama barang
string Barang::getNama() {
    return nama;
};

// Fungsi getter untuk mendapatkan deskripsi barang
string Barang::getDeskripsi() {
    return deskripsi;
};

// Deklarasi destruktor
Barang::~Barang() {
    this->id = -1;
    this->nama = "";
    this->deskripsi = "";
};
