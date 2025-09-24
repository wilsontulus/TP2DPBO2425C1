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

// Deklarasi konstruktor, kosongkan karena tidak ada angka
Tipe::Tipe() {};

// Fungsi setter untuk menentukan nama dari suatu tipe (tipe dari sebuah barang)
void Tipe::setTipe(string tipe) {
    this->tipe = tipe;
};

// Fungsi setter untuk menentukan target instalasi dari tipe yang ditentukan
void Tipe::setTargetInstalasi(string target_instalasi) {
    this->target_instalasi = target_instalasi;
};

// Fungsi setter untuk menentukan merek
void Tipe::setMerek(string merek) {
    this->merek = merek;
};

// Fungsi getter untuk mendapatkan nama dari suatu tipe (tipe dari sebuah barang)
string Tipe::getTipe() {
    return tipe;
};

// Fungsi getter untuk mendapatkan target instalasi dari tipe yang ditentukan
string Tipe::getTargetInstalasi() {
    return target_instalasi;
};

// Fungsi getter untuk mendapatkan merek yang ditentukan
string Tipe::getMerek() {
    return merek;
};

// Deklarasi destruktor
Tipe::~Tipe() {
    this->tipe = "";
    this->target_instalasi = "";
    this->merek = "";
};
