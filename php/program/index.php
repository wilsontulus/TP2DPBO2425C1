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

/* Deklarasi kelas barang dari file php */

require('Barang.php');
require('Tipe.php');
require('Produk.php');

/* Inisialisasi variabel sesi $SESSION */

session_start();

/* Buat data dummy terlebih dahulu jika belum ter-inisialisasi */

if (!isset($_SESSION['listProduk'])) {
    $_SESSION['listProduk'] = array();
    $_SESSION['listProduk'][] = new Produk()->create(count($_SESSION['listProduk'])+1, "HP Omen Gaming", "Laptop gaming pemula", "HP_Omen.png", "Laptop", "Portable", "HP", 700, 8, "Resmi");
    $_SESSION['listProduk'][] = new Produk()->create(count($_SESSION['listProduk'])+1, "Lenovo ThinkPad Yoga", "Laptop mahasiswa terbaik", "ThinkpadYoga.png", "Laptop", "Portable", "Lenovo", 1800, 5, "Distributor" );
    $_SESSION['listProduk'][] = new Produk()->create(count($_SESSION['listProduk'])+1, "Dell Optiplex AIO 9020", "PC tinggal pasang langsung beres", "OptiplexAIO.png", "AIO PC", "Desktop", "Dell", 1800, 15, "Distributor");
    $_SESSION['listProduk'][] = new Produk()->create(count($_SESSION['listProduk'])+1, "Samsung Galaxy Tab 11", "Tablet ternyaman di tangan mahasiswa", "GalaxyTab11.png", "Tablet", "Portable", "Samsung", 2500, 15, "Resmi");
    $_SESSION['listProduk'][] = new Produk()->create(count($_SESSION['listProduk'])+1, "ESP32-H2", "Komponen IoT termurah", "ESP32H2.png", "Microcontroller", "Embedded", "Espressif", 3, 100, "Toko");
}

/* Buat variabel untuk sesi berupa list produk */

$listProduk = $_SESSION['listProduk'];

/* Buat folder gambar dengan permission rwxrwxr-x jika belum tersedia */

if (!is_dir("images")) {
    mkdir("images", 0775, true);
}

/* Buat fungsi untuk menambahkan produk */

if (isset($_POST['submit'])) {
    // Kelas Barang
    $nama = $_POST['nama'];
    $deskripsi = $_POST['deskripsi'];
    $foto  = $_FILES['foto'];

    // Kelas Tipe
    $tipe = $_POST['tipe'];
    $target_instalasi = $_POST['target_instalasi'];
    $merek = $_POST['merek'];

    // Kelas Produk
    $harga = $_POST['harga'];
    $stok = $_POST['stok'];
    $garansi = $_POST['garansi'];

    // Proses file foto
    $direktori_foto = "images/" . basename($photo['name']);

    // Upload foto ke server
    move_uploaded_file($photo['tmp_name'], $direktori_foto);

    // Buat variabel sementara untuk objek Produk
    $tempBarang = new Produk()->create(count($listProduk)+1, $nama, $deskripsi, $foto, $tipe, $target_instalasi, $merek, $harga, $stok, $garansi);

    // Masukkan ke list produk
    $listProduk[] = $tempBarang;

    // Ubah list sesi menjadi list final setelah perubahan
    $_SESSION['listProduk'] = $listProduk;
}

?>

<!DOCTYPE html>

<html lang="id-ID">
    <head>
        <!-- Deskripsi dan metadata situs -->
        <title>Manajemen Toko Elektronik</title>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <meta name="author" content="wilson">
        <meta name="title" property="og:title" content="Toko Elektronik wilson">
        <meta name="keywords" content="toko, elektronik, electronics">
        <meta name="description" content="Sebuah situs toko elektronik.">

        <!-- Deklarasi stylesheet CSS -->
        <link rel="stylesheet" href="style.css">
    </head>
    <body>
        <div class="header">
            <div class="header-left">
                <h1> Manajemen Toko Elektronik </h1>
            </div>

            <div class="header-right">
                <img class="logo" src="images/logo.png" alt="Item icon" height="64">
            </div>

        </div>

        <div class="main">
            <header>
                <h1> List barang yang tercatat </h1>
            </header>

            <table class="products-list">
                <thead>
                    <tr>
                        <th>ID</th>
                        <th>Nama</th>
                        <th>Deskripsi</th>
                        <th>Tipe</th>
                        <th>Target Instalasi</th>
                        <th>Merek</th>
                        <th>Harga</th>
                        <th>Stok</th>
                        <th>Garansi</th>
                        <th>Foto</th>
                    </tr>
                </thead>

                <tbody>
                    <!-- Beritahu jika list tabel kosong -->
                    <?php if (count($listProduk) <= 0) {?>
                        <tr>
                            <td colspan="10" style="text-align: center;">List produk tidak tersedia.</td>
                        </tr>
                    <?php } else { ?>
                        <?php foreach($listProduk as $produk) { ?>
                            <tr>
                            <th><?php echo $produk->getId(); ?></th>
                            <th><?php echo $produk->getNama(); ?></th>
                            <th><?php echo $produk->getDeskripsi(); ?></th>
                            <th><?php echo $produk->getTipe(); ?></th>
                            <th><?php echo $produk->getTargetInstalasi(); ?></th>
                            <th><?php echo $produk->getMerek(); ?></th>
                            <th><?php echo $produk->getHarga(); ?></th>
                            <th><?php echo $produk->getStok(); ?></th>
                            <th><?php echo $produk->getGaransi(); ?></th>
                            <th><img src="images/<?php echo $produk->getFoto(); ?>" alt="<?php echo $produk->getNama(); ?>" width="40"></th>
                            </tr>
                        <?php }?>
                    <?php }?>
                </tbody>
            </table>
        </div>

        <div class="footer">
            <h3>Site made by wilson - UPI</h3>
        </div>
    </body>
</html>
