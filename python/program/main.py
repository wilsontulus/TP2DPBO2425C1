# LICENSE: All Rights Reserved
# (c) 2025 Willsoon Tulus P. Simanjuntak
# (c) 2025 Universitas Pendidikan Indonesia
#
# Saya Willsoon Tulus Parluhutan Simanjuntak mengerjakan evaluasi
# Tugas Praktikum 2 dalam mata kuliah Desain Pemrograman
# Berorientasi Objek untuk keberkahanNya maka saya tidak
# melakukan kecurangan seperti yang telah dispesifikasikan.
# Aamiin.

# Deklarasi kelas objek Barang #
from produk import Produk

# Deklarasi fungsi utama (main) #

def main():
    # Deklarasi variabel list produk
    listProduk = []

    # Variabel pilihan menu (angka)
    choiceNum = -1

    # Isi dengan 5 data dummy terlebih dahulu
    listProduk.append(Produk().create(len(listProduk) + 1, "HP Omen Gaming", "Laptop gaming pemula", "Laptop", "Portable", "HP", 700, 8, "Resmi"))
    listProduk.append(Produk().create(len(listProduk) + 1, "Lenovo ThinkPad Yoga", "Laptop mahasiswa terbaik", "Laptop", "Portable", "Lenovo", 1800, 5, "Distributor"))
    listProduk.append(Produk().create(len(listProduk) + 1, "Dell Optiplex AIO 9020", "PC tinggal pasang langsung beres", "AIO PC", "Desktop", "Dell", 1800, 15, "Distributor"))
    listProduk.append(Produk().create(len(listProduk) + 1, "Samsung Galaxy Tab 11", "Tablet ternyaman di tangan mahasiswa", "Tablet", "Portable", "Samsung", 2500, 15, "Resmi"))
    listProduk.append(Produk().create(len(listProduk) + 1, "ESP32-H2", "Komponen IoT termurah", "Microcontroller", "Embedded", "Espressif", 3, 100, "Toko"))

    # Tampilan menu hingga angka 0
    while (choiceNum != 0):
        # Variable untuk isi kolom tabel
        tableColumnStr = ["ID", "Nama", "Deskripsi", "Tipe", "Target Instalasi", "Merek", "Harga", "Stok", "Garansi"]

        # Variable untuk panjang kolom tabel, serta inisialisasi jumlah huruf di masing-masing kolom header
        tableColumnLengths = []
        for cidx in range(len(tableColumnStr)):
            tableColumnLengths.append(len(tableColumnStr[cidx]))

        print("Menu Pilihan: ")
        print("1. Tambah Barang")
        print("2. Tampilkan List Barang")
        print("0. Keluar dari program")
        choiceNum = input("Masukkan pilihan: ")

        if (choiceNum.isdigit()):
            choiceNum = int(choiceNum)

            match choiceNum:
                case 1: # Tambah data baru
                    # Kelas "Barang"
                    tempName = input("Masukkan nama barang: ")
                    tempDesc = input("Masukkan deskripsi produk: ")

                    # Kelas "Tipe"
                    tempType = input("Masukkan tipe produk: ")
                    tempTargetInstallation = input("Masukkan target instalasi produk: ")
                    tempBrand = input("Masukkan merek produk: ")

                    # Kelas "Produk" - Sertakan error handling untuk inputan non-numerik
                    tempPrice = input("Masukkan harga produk: ")
                    if tempPrice.isdigit():
                        tempPrice = int(tempPrice)
                    else:
                        print("Masukan harus berupa angka.")
                        continue

                    tempStock = input("Masukkan stok produk: ")
                    if tempStock.isdigit():
                        tempStock = int(tempStock)
                    else:
                        print("Masukan harus berupa angka.")
                        continue

                    tempWarrantyMethod = input("Masukkan metode garansi produk: ")

                    # Masukkan variabel objek hasil inputan ke list
                    listProduk.append(Produk().create(len(listProduk) + 1, tempName, tempDesc, tempType, tempTargetInstallation, tempBrand, tempPrice, tempStock, tempWarrantyMethod))

                    # Tampilkan bahwa proses penambahan barang baru sudah selesai
                    print("Sukses menambahkan produk dengan ID", len(listProduk))
                case 2: # Tampilkan list
                    # Dapatkan panjang kolom terlebih dahulu
                    for produk in listProduk:
                        # Kelas Barang
                        tableColumnLengths[0] = max(tableColumnLengths[0], len(str(produk.getId())))
                        tableColumnLengths[1] = max(tableColumnLengths[1], len(produk.getNama()))
                        tableColumnLengths[2] = max(tableColumnLengths[2], len(produk.getDeskripsi()))

                        # Kelas Tipe
                        tableColumnLengths[3] = max(tableColumnLengths[3], len(produk.getTipe()))
                        tableColumnLengths[4] = max(tableColumnLengths[4], len(produk.getTargetInstalasi()))
                        tableColumnLengths[5] = max(tableColumnLengths[5], len(produk.getMerek()))

                        # Kelas Produk
                        tableColumnLengths[6] = max(tableColumnLengths[6], len(str(produk.getHarga())))
                        tableColumnLengths[7] = max(tableColumnLengths[7], len(str(produk.getStok())))
                        tableColumnLengths[8] = max(tableColumnLengths[8], len(produk.getGaransi()))

                    # Tampilkan baris atas header tabel
                    print("+", end="")
                    for i in range(0, 9):
                        print("-"*(tableColumnLengths[i]+2) + "+", end="")

                    print("")

                    # Tampilkan isi header tabel
                    print("| ", end="")
                    for i in range(0, 9):
                        # System.out.printf(tableColumnStr[i] + " ".repeat(tableColumnLengths[i] - tableColumnStr[i].length()) + " | ")
                        print(tableColumnStr[i], end="")
                        print(" "*(tableColumnLengths[i] - len(tableColumnStr[i])), end="")
                        print(" | ", end="")

                    print("")

                    # Tampilkan baris bawah header / pemisah baris tabel
                    print("+", end="")
                    for i in range(0, 9):
                        print("-"*(tableColumnLengths[i]+2) + "+", end="")

                    print("")

                    # Tampilkan isi tabel
                    for produk in listProduk:
                        print("| ", end="")
                        # Kelas barang
                        print(str(produk.getId()) + " "*(tableColumnLengths[0] - len(str(produk.getId()))) + " | ", end="")
                        print(produk.getNama() + " "*(tableColumnLengths[1] - len(produk.getNama())) + " | ", end="")
                        print(produk.getDeskripsi() + " "*(tableColumnLengths[2] - len(produk.getDeskripsi())) + " | ", end="")

                        # Kelas tipe
                        print(produk.getTipe() + " "*(tableColumnLengths[3] - len(produk.getTipe())) + " | ", end="")
                        print(produk.getTargetInstalasi() + " "*(tableColumnLengths[4] - len(produk.getTargetInstalasi())) + " | ", end="")
                        print(produk.getMerek() + " "*(tableColumnLengths[5] - len(produk.getMerek())) + " | ", end="")

                        # Kelas produk
                        print(str(produk.getHarga()) + " "*(tableColumnLengths[6] - len(str(produk.getHarga()))) + " | ", end="")
                        print(str(produk.getStok()) + " "*(tableColumnLengths[7] - len(str(produk.getStok()))) + " | ", end="")
                        print(produk.getGaransi() + " "*(tableColumnLengths[8] - len(produk.getGaransi())) + " | ", end="")

                        print("")

                    # Tampilkan footer tabel
                    print("+", end="")
                    for i in range(0, 9):
                        print("-"*(tableColumnLengths[i]+2) + "+", end="")

                    print("")
                case 0:
                    print("Program selesai digunakan.")
                case _:
                    print("Masukan harus sesuai dengan menu yang ditentukan (0-2).")
        else:
            print("Masukan harus berupa angka.")

# Eksekusi otomatis untuk main
if __name__ == "__main__":
    main()
