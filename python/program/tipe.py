# LICENSE: All Rights Reserved
# (c) 2025 Willsoon Tulus P. Simanjuntak
# (c) 2025 Universitas Pendidikan Indonesia
#
# Saya Willsoon Tulus Parluhutan Simanjuntak mengerjakan evaluasi
# Tugas Praktikum 2 dalam mata kuliah Desain Pemrograman
# Berorientasi Objek untuk keberkahanNya maka saya tidak
# melakukan kecurangan seperti yang telah dispesifikasikan.
# Aamiin.

from barang import Barang

# Deklarasi kelas objek Tipe #

class Tipe(Barang):

    # constructor untuk inisialisasi atribut

    def __init__(self):
        super().__init__()
        self._tipe = ""
        self._target_instalasi = ""
        self._merek = ""
        return None

    # Fungsi setter (write atribut)
    def setTipe(self, tipe: str) -> None:
        self._tipe = str(tipe)

    def setTargetInstalasi(self, target_instalasi: str) -> None:
        self._target_instalasi = str(target_instalasi)

    def setMerek(self, merek: str) -> None:
        self._merek = str(merek)

    # Fungsi getter (read atribut)
    def getTipe(self) -> str:
        return self._tipe

    def getTargetInstalasi(self) -> str:
        return self._target_instalasi

    def getMerek(self) -> str:
        return self._merek
