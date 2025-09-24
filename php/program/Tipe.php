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

/* Deklarasi kelas tipe */

class Tipe extends Barang {

    private $tipe = "";
    private $target_instalasi = "";
    private $merek = "";

    public function __construct() {
        $this->tipe = "";
        $this->target_instalasi = "";
        $this->merek = "";
    }

    // Fungsi setter untuk write atribut

    public function setTipe($tipe) {
        $this->tipe = $tipe;
    }

    public function setTargetInstalasi($target_instalasi) {
        $this->target_instalasi = $target_instalasi;
    }

    public function setMerek($merek) {
        $this->merek = $merek;
    }

    // Fungsi getter untuk read atribut

    public function getTipe() {
        return $this->tipe;
    }

    public function getTargetInstalasi() {
        return $this->target_instalasi;
    }

    public function getMerek() {
        return $this->merek;
    }
}

?>
