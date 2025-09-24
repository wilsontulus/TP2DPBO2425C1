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

/* Deklarasi file header custom */
#include "header.hpp"

/* Main driver */

int main() {
    // Deklarasi variabel list produk yang tersedia
    list<Produk> listProduk;

    // Deklarasi variabel objek "Produk" sementara
    Produk tempProduk;

    // Isi dengan 5 data dummy terlebih dahulu
    listProduk.push_back(tempProduk.create(listProduk.size()+1, "HP Omen Gaming", "Laptop gaming pemula", "Laptop", "Portable", "HP", 700, 8, "Resmi"));

    listProduk.push_back(tempProduk.create(listProduk.size()+1, "Lenovo ThinkPad Yoga", "Laptop mahasiswa terbaik", "Laptop", "Portable", "Lenovo", 1800, 5, "Distributor"));

    listProduk.push_back(tempProduk.create(listProduk.size()+1, "Dell Optiplex AIO 9020", "PC tinggal pasang langsung beres", "AIO PC", "Desktop", "Dell", 1800, 15, "Distributor"));

    listProduk.push_back(tempProduk.create(listProduk.size()+1, "Samsung Galaxy Tab 11", "Tablet ternyaman di tangan mahasiswa", "Tablet", "Portable", "Samsung", 2500, 15, "Resmi"));

    listProduk.push_back(tempProduk.create(listProduk.size()+1, "ESP32-H2", "Komponen IoT termurah", "Microcontroller", "Embedded", "Espressif", 3, 100, "Toko"));

    // Variabel pilihan menu (angka)
    int choiceNum = -1;

    // Tampilkan menu hingga angka 0
    while (choiceNum != 0) {
        // Kumpulan menu
        cout << "Menu Pilihan: " << endl;
        cout << "1. Tambah Produk" << endl;
        cout << "2. Tampilkan List Produk" << endl;
        cout << "0. Keluar dari program" << endl << endl;
        cout << "Masukkan angka pilihan: ";

        // Minta input masukan menu
        cin >> choiceNum;

        // Variable untuk input
        int tempId, tempPrice, tempStock;
        string tempName, tempDesc, tempType, tempTargetInstallation, tempBrand, tempWarrantyMethod;

        // Variable untuk hitungan tampilan produk dan pilihan atribut update
        int tempSuccessfulQueries = 0, tempUpdateSelection = 0;

        // Variable untuk isi kolom tabel
        string tableColumnsStr[9] = {"ID", "Nama", "Deskripsi", "Tipe", "Target Instalasi", "Merek", "Harga", "Stok", "Garansi"};

        // Variable untuk panjang kolom tabel
        // Data tipe size_t digunakan untuk menyimpan panjang string
        size_t tableColumnLengths[9];
        for (int i = 0; i < 9; i++) { // Inisialisasi panjang kolom tabel
            tableColumnLengths[i] = 0;
        }

        // Pilihan menu
        switch(choiceNum) {
            case 1: // Tambah data baru.
                // Untuk nama dan deskripsi, getline digunakan untuk menerima spasi
                // cin.ignore() digunakan sebelum getline untuk mencegah double newline di beberapa sistem.

                // Kelas "Barang"
                cout << "Masukkan nama produk: ";
                cin.ignore();
                getline(cin, tempName);

                cout << "Masukkan deskripsi produk: ";
                cin.ignore();
                getline(cin, tempDesc);

                // Kelas "Tipe"

                cout << "Masukkan tipe produk: ";
                cin >>tempType;

                cout << "Masukkan target instalasi produk: ";
                cin >>tempTargetInstallation;

                cout << "Masukkan merek produk: ";
                cin >>tempBrand;

                // Kelas "Produk"
                cout << "Masukkan harga produk: ";
                cin >>tempPrice;

                cout << "Masukkan stok produk: ";
                cin >>tempStock;

                cout << "Masukkan metode garansi produk: ";
                cin >>tempWarrantyMethod;

                /* Set data sesuai input */

                // Tambahkan sebagai baris terakhir list
                listProduk.push_back(tempProduk.create(listProduk.size()+1, tempName, tempDesc, tempType, tempTargetInstallation, tempBrand, tempPrice, tempStock, tempWarrantyMethod));

                // Tampilkan bahwa proses penambahan produk baru sudah selesai
                cout << "Sukses menambahkan produk dengan ID " << listProduk.size() << endl;
                break;
            case 2: // Tampilkan seluruh list produk yang tersedia di listProduk
                if (listProduk.empty() == true) {
                    // Jika tidak ada barang tersedia, tampilkan bahwa tidak ada barang yang tersedia.
                    // Double newline untuk menyisakan ruang menu selanjutnya
                    cout << "List produk tidak tersedia." << endl;
                } else {
                    // Tentukan alignment text ke kiri untuk setw()
                    cout << left;

                    // Dapatkan panjang kolom terlebih dahulu
                    for (Produk iproduk : listProduk) {
                        // Kelas barang
                        tableColumnLengths[0] = max({tableColumnLengths[0], tableColumnsStr[0].length(), to_string(iproduk.getId()).length()});
                        tableColumnLengths[1] = max({tableColumnLengths[1], tableColumnsStr[1].length(), iproduk.getNama().length()});
                        tableColumnLengths[2] = max({tableColumnLengths[2], tableColumnsStr[2].length(), iproduk.getDeskripsi().length()});

                        // Kelas tipe
                        tableColumnLengths[3] = max({tableColumnLengths[3], tableColumnsStr[3].length(), iproduk.getTipe().length()});
                        tableColumnLengths[4] = max({tableColumnLengths[4], tableColumnsStr[4].length(), iproduk.getTargetInstalasi().length()});
                        tableColumnLengths[5] = max({tableColumnLengths[5], tableColumnsStr[5].length(), iproduk.getMerek().length()});

                        // Kelas produk
                        tableColumnLengths[6] = max({tableColumnLengths[6], tableColumnsStr[6].length(), to_string(iproduk.getHarga()).length()});
                        tableColumnLengths[7] = max({tableColumnLengths[7], tableColumnsStr[7].length(), to_string(iproduk.getStok()).length()});
                        tableColumnLengths[8] = max({tableColumnLengths[8], tableColumnsStr[8].length(), iproduk.getGaransi().length()});
                    }

                    // Tampilkan baris atas header tabel
                    cout << "+";
                    for (int i = 0; i <= 8; i++) {
                        cout << string(tableColumnLengths[i] + 2, '-') << "+";
                    }
                    cout << endl;

                    // Tampilkan isi header tabel
                    cout << "| ";
                    for (int i = 0; i <= 8; i++) {
                        cout << setw(tableColumnLengths[i]) << tableColumnsStr[i] << " | ";
                    }
                    cout << endl;

                    // Tampilkan baris bawah header / pemisah baris tabel
                    cout << "+";
                    for (int i = 0; i <= 8; i++) {
                        cout << string(tableColumnLengths[i] + 2, '-') << "+";
                    }
                    cout << endl;

                    // Tampilkan isi tabel
                    for (Produk iproduk : listProduk) {
                        cout << "| ";
                        // Kelas barang
                        cout << setw(tableColumnLengths[0]) << iproduk.getId() << " | ";
                        cout << setw(tableColumnLengths[1]) << iproduk.getNama() << " | ";
                        cout << setw(tableColumnLengths[2]) << iproduk.getDeskripsi() << " | ";

                        // Kelas tipe
                        cout << setw(tableColumnLengths[3]) << iproduk.getTipe() << " | ";
                        cout << setw(tableColumnLengths[4]) << iproduk.getTargetInstalasi() << " | ";
                        cout << setw(tableColumnLengths[5]) << iproduk.getMerek() << " | ";

                        // Kelas produk
                        cout << setw(tableColumnLengths[6]) << iproduk.getHarga() << " | ";
                        cout << setw(tableColumnLengths[7]) << iproduk.getStok() << " | ";
                        cout << setw(tableColumnLengths[8]) << iproduk.getGaransi() << " | ";
                        cout << endl;
                    }


                    // Tampilkan footer tabel
                    cout << "+";
                    for (int i = 0; i <= 8; i++) {
                        cout << string(tableColumnLengths[i] + 2, '-') << "+";
                    }
                    cout << endl;

                }

                break;
            case 0: // Keluar program
                cout << "Program selesai digunakan." << endl;
                break;

            default:
                cout << "Masukan harus sesuai dengan menu yang ditentukan (0-2)." << endl;
                break;
        }
    };

    // Selesai
    return 0;
}
