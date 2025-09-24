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

/* Deklarasi kelas Barang */

class Barang {
    // Deklarasi variabel kelas objek
    private int id;
    private String nama;
    private String deskripsi;

    // Konstruktor, objek baru selalu memiliki ID -1
    Barang() {
        this.id = -1;
        this.nama = "";
        this.deskripsi = "";
    }

    // Fungsi setter untuk menentukan atribut barang

    public void setId(int id) {
        this.id = id;
    }

    public void setNama(String nama) {
        this.nama = nama;
    }

    public void setDeskripsi(String deskripsi) {
        this.deskripsi = deskripsi;
    }

    // Fungsi getter untuk mendapatkan atribut barang

    public int getId() {
        return this.id;
    }

    public String getNama() {
        return this.nama;
    }

    public String getDeskripsi() {
        return this.deskripsi;
    }
}
