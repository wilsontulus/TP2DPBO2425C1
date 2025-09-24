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

/* Deklarasi library */

import java.util.ArrayList;
import java.util.Scanner;

/* Deklarasi "kelas" fungsi utama */

public class Main {
    public static void main(String[] args) {
        /* Deklarasi variabel list produk */
        ArrayList<Produk> listProduk = new ArrayList<Produk>();

        // Isi dengan 5 data dummy terlebih dahulu
        listProduk.add(new Produk().create(listProduk.size()+1, "HP Omen Gaming", "Laptop gaming pemula", "Laptop", "Portable", "HP", 700, 8, "Resmi"));
        listProduk.add(new Produk().create(listProduk.size()+1, "Lenovo ThinkPad Yoga", "Laptop mahasiswa terbaik", "Laptop", "Portable", "Lenovo", 1800, 5, "Distributor"));
        listProduk.add(new Produk().create(listProduk.size()+1, "Dell Optiplex AIO 9020", "PC tinggal pasang langsung beres", "AIO PC", "Desktop", "Dell", 1800, 15, "Distributor"));
        listProduk.add(new Produk().create(listProduk.size()+1, "Samsung Galaxy Tab 11", "Tablet ternyaman di tangan mahasiswa", "Tablet", "Portable", "Samsung", 2500, 15, "Resmi"));
        listProduk.add(new Produk().create(listProduk.size()+1, "ESP32-H2", "Komponen IoT termurah", "Microcontroller", "Embedded", "Espressif", 3, 100, "Toko"));

        /* Deklarasi variabel angka pilihan menu */
        int choiceNum = -1;

        /* Deklarasi objek untuk input CLI */
        Scanner input = new Scanner(System.in);

        // Tampilkan menu hingga angka 0
        while (choiceNum != 0)
        {
            System.out.println("Menu Pilihan: ");
            System.out.println("1. Tambah Produk");
            System.out.println("2. Tampilkan List Produk");
            System.out.println("0. Keluar dari program");

            // Minta masukan input pilihan, dengan error handling jika bukan bilangan integer
            try {
                System.out.printf("Masukkan pilihan: ");
                choiceNum = input.nextInt();
                input.nextLine();
            } catch (Exception errorMsg) {
                System.out.println("Masukan harus berupa angka.");
                input.nextLine();
                continue;
            }


            // Variable untuk input
            int tempPrice, tempStock;
            String tempName, tempDesc, tempType, tempTargetInstallation, tempBrand, tempWarrantyMethod;

            // Variable untuk isi kolom tabel
            String tableColumnStr[] = {"ID", "Nama", "Deskripsi", "Tipe", "Target Instalasi", "Merek", "Harga", "Stok", "Garansi"};

            // Variable untuk panjang kolom tabel
            int tableColumnLengths[] = new int[9];

            switch(choiceNum) {
                case 1: // Tambah data baru.
                    // Untuk nama dan deskripsi, getline digunakan untuk menerima spasi

                    // Kelas "Barang"
                    System.out.printf("Masukkan nama produk: ");
                    tempName = input.nextLine();

                    System.out.printf("Masukkan deskripsi produk: ");
                    tempDesc = input.nextLine();

                    // Kelas "Tipe"

                    System.out.printf("Masukkan tipe produk: ");
                    tempType = input.nextLine();

                    System.out.printf("Masukkan target instalasi produk: ");
                    tempTargetInstallation = input.nextLine();

                    System.out.printf("Masukkan merek produk: ");
                    tempBrand = input.nextLine();

                    // Kelas "Produk"

                    System.out.printf("Masukkan harga produk: ");
                    tempPrice = input.nextInt();

                    System.out.printf("Masukkan stok produk: ");
                    tempStock = input.nextInt();

                    System.out.printf("Masukkan metode garansi produk: ");
                    tempWarrantyMethod = input.nextLine();

                    // Inisialisasi variabel sementara sesuai input
                    Produk tempProduk = new Produk().create(listProduk.size()+1, tempName, tempDesc, tempType, tempTargetInstallation, tempBrand, tempPrice, tempStock, tempWarrantyMethod);

                    // Masukkan variabel objek hasil inputan ke list
                    listProduk.add(tempProduk);
                    
                    // Tampilkan bahwa proses penambahan produk baru sudah selesai
                    System.out.println("Sukses menambahkan produk dengan ID " + listProduk.size());

                    break;
                case 2: // Tampilkan list
                    // Jika tidak ada barang tersedia, tampilkan bahwa tidak ada barang yang tersedia.
                    // Double newline untuk menyisakan ruang menu selanjutnya
                    if (listProduk.size() <= 0) {
                        System.out.println("List produk tidak tersedia.\n");
                    } else {
                        // Dapatkan panjang kolom terlebih dahulu
                        for (int i = 0; i < listProduk.size(); i++) {
                            // Kelas barang
                            tableColumnLengths[0] = Math.max(tableColumnLengths[0], Math.max(tableColumnStr[0].length(), String.valueOf(listProduk.get(i).getId()).length()));
                            tableColumnLengths[1] = Math.max(tableColumnLengths[1], Math.max(tableColumnStr[1].length(), listProduk.get(i).getNama().length()));
                            tableColumnLengths[2] = Math.max(tableColumnLengths[2], Math.max(tableColumnStr[2].length(), listProduk.get(i).getDeskripsi().length()));

                            // Kelas tipe
                            tableColumnLengths[3] = Math.max(tableColumnLengths[3], Math.max(tableColumnStr[3].length(), listProduk.get(i).getTipe().length()));
                            tableColumnLengths[4] = Math.max(tableColumnLengths[4], Math.max(tableColumnStr[4].length(), listProduk.get(i).getTargetInstalasi().length()));
                            tableColumnLengths[5] = Math.max(tableColumnLengths[5], Math.max(tableColumnStr[5].length(), listProduk.get(i).getMerek().length()));

                            // Kelas produk

                            tableColumnLengths[6] = Math.max(tableColumnLengths[6], Math.max(tableColumnStr[6].length(), String.valueOf(listProduk.get(i).getHarga()).length()));
                            tableColumnLengths[7] = Math.max(tableColumnLengths[7], Math.max(tableColumnStr[7].length(), String.valueOf(listProduk.get(i).getStok()).length()));
                            tableColumnLengths[8] = Math.max(tableColumnLengths[8], Math.max(tableColumnStr[8].length(), listProduk.get(i).getGaransi().length()));
                        }

                        // Tampilkan baris atas header tabel
                        System.out.printf("+");
                        for (int i = 0; i <= 8; i++) {
                            System.out.printf("-".repeat(tableColumnLengths[i] + 2) + "+");
                        }
                        System.out.printf("\n");

                        // Tampilkan isi header tabel
                        System.out.printf("| ");
                        for (int i = 0; i <= 8; i++) {
                            System.out.printf(tableColumnStr[i] + " ".repeat(tableColumnLengths[i] - tableColumnStr[i].length()) + " | ");
                        }
                        System.out.printf("\n");

                        // Tampilkan baris bawah header / pemisah baris tabel
                        System.out.printf("+");
                        for (int i = 0; i <= 8; i++) {
                            System.out.printf("-".repeat(tableColumnLengths[i] + 2) + "+");
                        }
                        System.out.printf("\n");
                        
                        // Tampilkan isi tabel
                        for (int i = 0; i < listProduk.size(); i++) {
                            System.out.printf("| ");
                            // Kelas barang
                            System.out.printf(String.valueOf(listProduk.get(i).getId()) + " ".repeat(tableColumnLengths[0] - String.valueOf(listProduk.get(i).getId()).length()) + " | ");
                            System.out.printf(listProduk.get(i).getNama() + " ".repeat(tableColumnLengths[1] - listProduk.get(i).getNama().length()) + " | ");
                            System.out.printf(listProduk.get(i).getDeskripsi() + " ".repeat(tableColumnLengths[2] - listProduk.get(i).getDeskripsi().length()) + " | ");

                            // Kelas tipe
                            System.out.printf(listProduk.get(i).getTipe() + " ".repeat(tableColumnLengths[3] - listProduk.get(i).getTipe().length()) + " | ");
                            System.out.printf(listProduk.get(i).getTargetInstalasi() + " ".repeat(tableColumnLengths[4] - listProduk.get(i).getTargetInstalasi().length()) + " | ");
                            System.out.printf(listProduk.get(i).getMerek() + " ".repeat(tableColumnLengths[5] - listProduk.get(i).getMerek().length()) + " | ");

                            // Kelas produk
                            System.out.printf(String.valueOf(listProduk.get(i).getHarga()) + " ".repeat(tableColumnLengths[6] - String.valueOf(listProduk.get(i).getHarga()).length()) + " | ");
                            System.out.printf(String.valueOf(listProduk.get(i).getStok()) + " ".repeat(tableColumnLengths[7] - String.valueOf(listProduk.get(i).getStok()).length()) + " | ");
                            System.out.printf(listProduk.get(i).getGaransi() + " ".repeat(tableColumnLengths[8] - listProduk.get(i).getGaransi().length()) + " | ");
                            System.out.printf("\n");
                        }
                        
                        // Tampilkan footer tabel
                        System.out.printf("+");
                        for (int i = 0; i <= 8; i++) {
                            System.out.printf("-".repeat(tableColumnLengths[i] + 2) + "+");
                        }
                        System.out.printf("\n");
                    };
                    break;
                case 0: // Sambutan keluar program
                    System.out.println("Program selesai digunakan.");
                    break;
                default: // Peringatkan jika diluar pilihan
                    System.out.println("Masukan harus sesuai dengan menu yang ditentukan (0-2).");
                    break;
            }
        }

        /* Selesai */
        input.close();
    }
}
