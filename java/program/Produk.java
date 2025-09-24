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

/* Deklarasi kelas Produk */

class Produk extends Tipe {
    // Deklarasi variabel objek
    private int harga;
    private int stok;
    private String garansi;

    // Konstruktor
    Produk() {
        super();
        this.harga = 0;
        this.stok = 0;
        this.garansi = "N/A";
    }

    // Fungsi setter untuk menentukan atribut produk

    public void setHarga(int harga) {
        this.harga = harga;
    }

    public void setStok(int stok) {
        this.stok = stok;
    }

    public void setGaransi(String garansi) {
        this.garansi = garansi;
    }

    // Fungsi getter+setter untuk membuat objek produk

    public Produk create(int id, String nama, String deskripsi, String tipe, String target_instalasi, String merek, int harga, int stok, String garansi) {
        // Set data barang/item
        this.setId(id);
        this.setNama(nama);
        this.setDeskripsi(deskripsi);

        // Set data tipe
        this.setTipe(tipe);
        this.setTargetInstalasi(target_instalasi);
        this.setMerek(merek);

        // Set data produk
        this.harga = harga;
        this.stok = stok;
        this.garansi = garansi;

        return this;
    }

    // Fungsi getter untuk mendapatkan atribut produk

    public int getHarga() {
        return this.harga;
    }

    public int getStok() {
        return this.stok;
    }

    public String getGaransi() {
        return this.garansi;
    }
}
