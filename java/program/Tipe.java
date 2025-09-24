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

/* Deklarasi kelas Tipe */

class Tipe extends Barang {
    // Deklarasi variabel objek
    private String tipe;
    private String target_instalasi;
    private String merek;

    // Konstruktor, objek baru selalu memiliki ID -1
    Tipe() {
        this.tipe = "";
        this.target_instalasi = "";
        this.merek = "";
    }

    // Fungsi setter untuk menentukan atribut tipe

    public void setTipe(String tipe) {
        this.tipe = tipe;
    }

    public void setTargetInstalasi(String target_instalasi) {
        this.target_instalasi = target_instalasi;
    }

    public void setMerek(String merek) {
        this.merek = merek;
    }

    // Fungsi getter untuk mendapatkan atribut tipe

    public String getTipe() {
        return this.tipe;
    }

    public String getTargetInstalasi() {
        return this.target_instalasi;
    }

    public String getMerek() {
        return this.merek;
    }
}
