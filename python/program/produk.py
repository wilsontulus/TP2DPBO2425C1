# LICENSE: All Rights Reserved
# (c) 2025 Willsoon Tulus P. Simanjuntak
# (c) 2025 Universitas Pendidikan Indonesia
#
# Saya Willsoon Tulus Parluhutan Simanjuntak mengerjakan evaluasi
# Tugas Praktikum 2 dalam mata kuliah Desain Pemrograman
# Berorientasi Objek untuk keberkahanNya maka saya tidak
# melakukan kecurangan seperti yang telah dispesifikasikan.
# Aamiin.

from tipe import Tipe

# Deklarasi kelas objek Tipe #


class Produk(Tipe):

    # constructor untuk inisialisasi atribut

    def __init__(self):
        super().__init__()
        self._harga = 0
        self._stok = 0
        self._garansi = "N/A"
        return None

    # Fungsi setter (write atribut)
    def setHarga(self, harga: int) -> None:
        self._harga = str(harga)

    def setStok(self, stok: int) -> None:
        self._stok = str(stok)

    def setGaransi(self, garansi: str) -> None:
        self._garansi = str(garansi)

    def create(self, id: int, nama: str, deskripsi: str,
               tipe: str, target_instalasi: str, merek: str,
               harga: int, stok: int, garansi: str) -> None:
        # Kelas Barang
        self.setId(id)
        self.setNama(nama)
        self.setDeskripsi(deskripsi)

        # Kelas Tipe
        self.setTipe(tipe)
        self.setTargetInstalasi(target_instalasi)
        self.setMerek(merek)

        # Kelas Produk
        self._harga = harga
        self._stok = stok
        self._garansi = garansi
        return self

    # Fungsi getter (read atribut)
    def getHarga(self) -> int:
        return self._harga

    def getStok(self) -> int:
        return self._stok

    def getGaransi(self) -> str:
        return self._garansi
