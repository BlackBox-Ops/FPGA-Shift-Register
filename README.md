# Eksplorasi Rangkaian Digital: Shift Register 💾

Repositori ini berisi eksperimen dan implementasi nyata dari berbagai jenis rangkaian **shift register**.  
Shift register adalah salah satu rangkaian fundamental dalam arsitektur sistem digital, terutama pada **memori, komunikasi data, dan pengolahan sinyal**.  

Fungsi utamanya adalah untuk **menyimpan** dan **menggeser bit data** secara berurutan sesuai sinyal clock.  

---

## 📑 Daftar Isi
1. [Shift Register Serial-In Serial-Out (SISO)](#1-rangkaian-shift-register-serial-in-serial-out-siso)  
2. [Shift Register Serial-In Parallel-Out (SIPO)](#2-rangkaian-shift-register-serial-in-parallel-out-sipo)  
3. [Shift Register Parallel-In Parallel-Out (PIPO)](#3-rangkaian-shift-register-parallel-in-parallel-out-pipo)  
4. [Shift Register Parallel-In Serial-Out (PISO)](#4-rangkaian-shift-register-parallel-in-serial-out-piso)  
5. [Shift Register Bidirectional](#5-rangkaian-shift-register-bidirectional)  
6. [Shift Register Universal](#6-rangkaian-shift-register-universal)  
7. [Tabel Logika Shift Register](#-tabel-logika-shift-register)  
8. [Aplikasi Nyata](#-aplikasi-nyata)  
9. [Referensi](#-referensi)  
10. [Lisensi](#-lisensi)  

---

## 0. Simulasi Shift Register SIPO dengan IC 74HC595
![74HC595](Docs/SIPO.png)

### Deskripsi

Pada bagian ini saya mengimplementasikan IC 74HC595 sebagai Serial-In Parallel-Out (SIPO) shift register menggunakan Arduino Uno.
Data dikirim secara serial (bit demi bit) melalui pin data dan clock, lalu setelah 8 bit penuh, hasilnya ditampilkan bersamaan melalui 8 output paralel yang dihubungkan ke LED.

### Tujuan eksperimen:
Memahami prinsip konversi data serial menjadi paralel.
Melihat bagaimana register dapat digunakan untuk ekspansi jumlah output Arduino dengan hanya beberapa pin kontrol.
Simulasi dilakukan pada platform Thinkercad, dan dapat diperluas ke implementasi nyata dengan Arduino + IC 74HC595.

Docs : https://www.tinkercad.com/things/hI911vPtwws-shift-register-sipo-and-siso?sharecode=i3ZuxDJhQGnT1vCE2rxtIZ61mJWZeT6Ig6DGM1tJlQg

## 1. Rangkaian Shift Register (Serial-In Serial-Out) **SISO**

### Deskripsi
- Data masuk **bit per bit** secara serial.  
- Data keluar juga **bit per bit** secara serial.  
- Terdiri dari satu input dan satu output.  
- Bisa digeser ke kanan (*shift right*) atau ke kiri (*shift left*).  

![Register_SISO](Docs/SISO.svg)

### Cara Kerja
Bayangkan sebuah lorong sempit hanya dengan **satu pintu masuk dan satu pintu keluar**.  
Setiap orang (bit data) masuk berurutan, lalu keluar berurutan juga.  


---

## 2. Rangkaian Shift Register (Serial-In Parallel-Out) **SIPO**

### Deskripsi
- Data masuk secara serial melalui satu jalur input.  
- Setelah semua bit masuk, hasilnya bisa dibaca sekaligus melalui beberapa jalur output paralel.  

![Register_SIPO](Docs/SIPO.svg)

### Cara Kerja
Seperti antrean: orang (bit data) masuk satu per satu. Setelah semua sudah di dalam, mereka bisa keluar bersamaan lewat pintu berbeda.  

**Aplikasi:** Mengubah data serial menjadi paralel, sering digunakan pada **decoder, driver LED display, atau komunikasi UART ke perangkat paralel**.  

---

## 3. Rangkaian Shift Register (Parallel-In Parallel-Out) **PIPO**

### Deskripsi
- Data dimasukkan sekaligus (paralel).  
- Data dikeluarkan juga sekaligus (paralel).  
- Fungsi utamanya adalah **penyimpanan sementara (buffer)**.  

![Register_PIPO](Docs/PIPO.svg)

### Cara Kerja
Seperti **kotak dengan banyak laci**: semua barang (bit) bisa dimasukkan bersamaan, dan bisa diambil bersamaan juga.  

**Aplikasi:** Sinkronisasi data, buffer sementara sebelum diproses.  

---

## 4. Rangkaian Shift Register (Parallel-In Serial-Out) **PISO**

### Deskripsi
- Data masuk paralel (semua bit sekaligus).  
- Data keluar serial (bit per bit).  

![Register_PISO](Docs/PISO.svg)

### Cara Kerja
Kebalikan dari SIPO. Semua orang (bit data) bisa masuk bersamaan, tapi keluar satu per satu lewat pintu tunggal.  

**Aplikasi:** Efisiensi transmisi data, misalnya mengirim data paralel lewat **satu jalur komunikasi tunggal**.  

---

## 5. Rangkaian Shift Register **Bidirectional**

### Deskripsi
- Data bisa digeser ke **kanan atau kiri** sesuai kontrol.  
- Fleksibel dalam pergeseran bit.  

![Biderectional](Docs/Biderectional.svg)

**Aplikasi:** Operasi aritmatika (perkalian/pembagian dengan basis 2), buffer data dua arah.  

---

## 6. Rangkaian Shift Register **Universal**

### Deskripsi
- Shift register paling fleksibel.  
- Mendukung semua mode: **SISO, SIPO, PISO, PIPO, serta shift kiri/kanan**.  
- Terdapat input kontrol tambahan untuk memilih mode.  

![Universal](Docs/Universal.svg)

**Aplikasi:** Digunakan dalam sistem kompleks seperti **CPU, register umum, hingga pengendali komunikasi**.  

---

## 🔢 Tabel Logika Shift Register

### 1. Serial-In Serial-Out (SISO)

| Clock | Input (Din) | Q0 (out) | Q1 | Q2 | Q3 |
|-------|-------------|----------|----|----|----|
| 0     | 1           | 1        | 0  | 0  | 0  |
| 1     | 0           | 0        | 1  | 0  | 0  |
| 2     | 1           | 1        | 0  | 1  | 0  |
| 3     | 1           | 1        | 1  | 0  | 1  |

---

### 2. Serial-In Parallel-Out (SIPO)

| Clock | Input (Din) | Q0 | Q1 | Q2 | Q3 (Parallel Out) |
|-------|-------------|----|----|----|-------------------|
| 0     | 1           | 1  | 0  | 0  | 0                 |
| 1     | 0           | 0  | 1  | 0  | 0                 |
| 2     | 1           | 1  | 0  | 1  | 0                 |
| 3     | 1           | 1  | 1  | 0  | 1                 |

---

### 3. Parallel-In Parallel-Out (PIPO)

| Load (Enable) | Input D0 | Input D1 | Input D2 | Input D3 | Q0 | Q1 | Q2 | Q3 |
|---------------|----------|----------|----------|----------|----|----|----|----|
| 1             | 1        | 0        | 1        | 1        | 1  | 0  | 1  | 1  |
| 0             | X        | X        | X        | X        | 1  | 0  | 1  | 1  |

> Saat `Load=1`, data langsung tersimpan di register.  
> Saat `Load=0`, output tetap (tidak berubah).

---

### 4. Parallel-In Serial-Out (PISO)

| Load | Input D0 | Input D1 | Input D2 | Input D3 | Serial Out (Q) |
|------|----------|----------|----------|----------|----------------|
| 1    | 1        | 0        | 1        | 1        | Ready to shift |
| 0    | X        | X        | X        | X        | 1 → 0 → 1 → 1 |

---

### 5. Bidirectional Shift Register

| Mode        | Clock | Din | Q0 | Q1 | Q2 | Q3 |
|-------------|-------|-----|----|----|----|----|
| Shift Left  | ↑     | 1   | 0  | 1  | 1  | 1  |
| Shift Right | ↑     | 0   | 0  | 0  | 1  | 1  |

> **Mode control** menentukan arah pergeseran.  

---

### 6. Universal Shift Register

| S1 | S0 | Operasi                        |
|----|----|--------------------------------|
| 0  | 0  | Tahan (No Change)              |
| 0  | 1  | Shift Kanan (Serial In Right)  |
| 1  | 0  | Shift Kiri (Serial In Left)    |
| 1  | 1  | Load Paralel (Parallel In)     |

> Universal register mendukung semua mode: SISO, SIPO, PISO, PIPO.  

---

## 📌 Aplikasi Nyata
Shift register banyak dipakai dalam:
- **Komunikasi data:** UART, SPI, I²C  
- **Driver tampilan:** IC 74HC595 untuk LED matrix atau 7-segmen  
- **Memori sementara:** buffer data, register di prosesor  
- **Sistem kontrol:** konversi data serial ↔ paralel  

---

## 📖 Referensi
- Floyd, T. L. *Digital Fundamentals*  
- Datasheet IC 74HC595, 74HC194  
- Modul Praktikum Sistem Digital  

---

## 📝 Lisensi
Proyek ini dirilis dengan lisensi **MIT**.  
Silakan digunakan, dimodifikasi, dan dikembangkan lebih lanjut untuk tujuan pembelajaran.  

---

