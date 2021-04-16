# Soal Shift Sisop 2021 Modul 2

Kelompok D-04
- Thomas Felix Brilliant (05111940000062)
- Muhammad Rizky Widodo (05111940000216)
- Fiodhy Ardito Narawangsa (05111940000218)

## SOAL 1 ##

### 1A ###

- <b>SOAL</b>

  Dikarenakan Stevany sangat menyukai huruf <b>Y</b>, Steven ingin nama folder-foldernya adalah <b>Musyik</b> untuk mp3, <b>Fylm</b> untuk mp4, dan <b>Pyoto</b> untuk jpg.

### 1B ###

- <b>SOAL</b>

  Untuk musik Steven <b>men-<i>download</i>-nya</b> dari link di bawah, film dari link di bawah lagi, dan foto dari link di bawah juga :).

### 1C ###

- <b>SOAL</b>

  Steven tidak ingin isi folder yang dibuatnya berisikan zip, sehingga perlu <b>meng-<i>extract</i>-nya</b> setelah di-<i>download</i>.

### 1D ###

- <b>SOAL</b>

  Serta memindahkannya ke dalam folder yang telah dibuat (hanya <i>file</i> yang dimasukkan).

### 1E ###

- <b>SOAL</b>

  Untuk memudahkan Steven, ia ingin semua hal di atas berjalan <b>otomatis</b> 6 jam sebelum waktu ulang tahun Stevany.
  Setelah itu pada <b>waktu</b> ulang tahunnya Stevany, semua folder akan di-<i>zip</i> dengan nama <i>Lopyu_Stevany.zip</i> dan semua folder akan <b>di-<i>delete</i></b> (sehingga hanya menyisakan .zip).
 
## SOAL 2 ## 
 
### 2A ###

- <b>SOAL</b>

  Pertama-tama program perlu mengextract <i>zip</i> yang diberikan ke dalam folder <b>"/home/[user]/modul2/petshop"</b>. Karena bos Loba teledor, dalam <i>zip</i> tersebut bisa berisi folder-folder yang tidak penting, maka program harus bisa membedakan <i>file</i> dan folder sehingga dapat memproses <i>file</i> yang seharusnya dikerjakan dan menghapus folder-folder yang tidak dibutuhkan.

### 2B ###

- <b>SOAL</b>

  Foto peliharaan perlu dikategorikan sesuai jenis peliharaan, maka kamu harus membuat folder untuk setiap jenis peliharaan yang ada dalam <i>zip</i>. Karena kamu tidak mungkin memeriksa satu per satu, maka program harus membuatkan folder-folder yang dibutuhkan sesuai dengan isi <i>zip</i>.

  Contoh: Jenis peliharaan kucing akan disimpan dalam <b>"/petshop/cat"</b>, jenis peliharaan kura-kura akan disimpan dalam <b>"/petshop/turtle"</b>.

### 2C ###

- <b>SOAL</b>

  Setelah folder kategori berhasil dibuat, programmu akan memindahkan foto ke folder dengan kategori yang sesuai dan di-<i>rename</i> dengan nama peliharaan.
  
  Contoh: <b>"/petshop/cat/joni.jpg"</b>.

### 2D ###

- <b>SOAL</b>

  Karena dalam satu foto bisa terdapat lebih dari satu peliharaan, maka foto harus dipindah ke masing-masing kategori yang sesuai.
  
  Contoh: foto dengan nama <b>"dog;baro;1_cat;joni;2.jpg"</b> dipindah ke folder <b>"/petshop/cat/joni.jpg</b> dan <b>"/petshop/dog/baro.jpg</b>.

### 2E ###

- <b>SOAL</b>

  Di setiap folder buatlah sebuah <i>file</i> <i>"keterangan.txt"</i> yang berisi nama dan umur semua peliharaan dalam folder tersebut. <b>Format harus sesuai contoh</b>.
  ```
    nama  : joni
    umur  : 3 tahun

    nama  : miko
    umur  : 2 tahun
  ```

  ## SOAL 3 ##
   Ranora adalah mahasiswa Teknik Informatika yang saat ini sedang menjalani magang di perusahan ternama yang bernama “FakeKos Corp.”, perusahaan yang bergerak dibidang keamanan data. Karena Ranora masih magang, maka beban tugasnya tidak sebesar beban tugas pekerja tetap perusahaan. Di hari pertama Ranora bekerja, pembimbing magang Ranora memberi tugas pertamanya untuk membuat sebuah program.<br/>
   <br/>
(a) Ranora harus membuat sebuah program C yang dimana setiap 40 detik membuat sebuah direktori dengan nama sesuai timestamp [YYYY-mm-dd_HH:ii:ss].<br/>
(b) Setiap direktori yang sudah dibuat diisi dengan 10 gambar yang didownload dari https://picsum.photos/, dimana setiap gambar akan didownload setiap 5 detik. Setiap gambar         yang didownload akan diberi nama dengan format timestamp [YYYY-mm-dd_HH:ii:ss] dan gambar tersebut berbentuk persegi dengan ukuran (n%1000) + 50 pixel dimana n adalah detik     Epoch Unix.<br/>
(c) Setelah direktori telah terisi dengan 10 gambar, program tersebut akan membuat sebuah file “status.txt”, dimana didalamnya berisi pesan “Download Success” yang terenkripsi       dengan teknik Caesar Cipher dan dengan shift 5. Caesar Cipher adalah Teknik enkripsi sederhana yang dimana dapat melakukan enkripsi string sesuai dengan shift/key yang kita     tentukan. Misal huruf “A” akan dienkripsi dengan shift 4 maka akan menjadi “E”. Karena Ranora orangnya perfeksionis dan rapi, dia ingin setelah file tersebut dibuat,             direktori akan di zip dan direktori akan didelete, sehingga menyisakan hanya file zip saja.<br/>
(d) Untuk mempermudah pengendalian program, pembimbing magang Ranora ingin program tersebut akan men-generate sebuah program “Killer” yang executable, dimana program tersebut       akan menterminasi semua proses program yang sedang berjalan dan akan menghapus dirinya sendiri setelah program dijalankan. Karena Ranora menyukai sesuatu hal yang baru,         maka Ranora memiliki ide untuk program “Killer” yang dibuat nantinya harus merupakan program bash.<br/>
(e) Pembimbing magang Ranora juga ingin nantinya program utama yang dibuat Ranora dapat dijalankan di dalam dua mode. Untuk mengaktifkan mode pertama, program harus dijalankan       dengan argumen -z, dan Ketika dijalankan dalam mode pertama, program utama akan langsung menghentikan semua operasinya Ketika program Killer dijalankan. Sedangkan untuk         mengaktifkan mode kedua, program harus dijalankan dengan argumen -x, dan Ketika dijalankan dalam mode kedua, program utama akan berhenti namun membiarkan proses di setiap       direktori yang masih berjalan hingga selesai (Direktori yang sudah dibuat akan mendownload gambar sampai selesai dan membuat file txt, lalu zip dan delete direktori).<br/>

  Note:
  - Tidak boleh menggunakan system() dan mkdir()
  - Program utama merupakan SEBUAH PROGRAM C
  - Wajib memuat algoritma Caesar Cipher pada program utama yang dibuat




