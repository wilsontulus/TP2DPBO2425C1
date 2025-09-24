<?php

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

/* Deklarasi kelas produk */

class Produk extends Tipe {

    private $harga = -1;
    private $stok = -1;
    private $garansi = "";

    public function __construct() {
        $this->harga = -1;
        $this->stok = -1;
        $this->garansi = "N/A";
    }

    // Fungsi setter untuk write atribut

    public function setHarga($harga) {
        $this->harga = $harga;
    }

    public function setStok($stok) {
        $this->stok = $stok;
    }

    public function setGaransi($garansi) {
        $this->garansi = $garansi;
    }

    // Fungsi setter/getter untuk objek baru

    public function create($id, $nama, $deskripsi, $foto, $tipe, $target_instalasi, $merek, $harga, $stok, $garansi) {
        $this->setId($id);
        $this->setNama($nama);
        $this->setDeskripsi($deskripsi);
        $this->setFoto($foto);
        $this->setTipe($tipe);
        $this->setTargetInstalasi($target_instalasi);
        $this->setMerek($merek);
        $this->harga = $harga;
        $this->stok = $stok;
        $this->garansi = $garansi;
        return $this;
    }

    // Fungsi getter untuk read atribut

    public function getHarga() {
        return $this->harga;
    }

    public function getStok() {
        return $this->stok;
    }

    public function getGaransi() {
        return $this->garansi;
    }
}

?>
