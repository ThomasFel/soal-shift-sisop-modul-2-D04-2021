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

  Steven tidak ingin isi folder yang dibuatnya berisikan <i>zip</i>, sehingga perlu <b>meng-<i>extract</i>-nya</b> setelah di-<i>download</i>.

### 1D ###

- <b>SOAL</b>

  Memindahkan <i>file extract</i> tadi ke dalam folder yang telah dibuat (hanya <i>file</i> yang dimasukkan).

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

### 3A ###

- <b>SOAL</b>

  Ranora harus membuat sebuah program C yang di mana setiap 40 detik membuat sebuah direktori dengan nama sesuai <i>timestamp</i> [YYYY-mm-dd_HH:ii:ss].
  
### 3B ###

- <b>SOAL</b>

  Setiap direktori yang sudah dibuat diisi dengan 10 gambar yang di-<i>download</i> dari https://picsum.photos/, di mana setiap gambar akan di-<i>download</i> setiap 5 detik. Setiap gambar yang di-<i>download</i> akan diberi nama dengan format <i>timestamp</i> [YYYY-mm-dd_HH:ii:ss] dan gambar tersebut berbentuk persegi dengan ukuran `(n % 1000) + 50 pixel` dimana <b>n</b> adalah detik <b>Epoch Unix</b>.

### 3C ###

- <b>SOAL</b>

  Setelah direktori telah terisi dengan 10 gambar, program tersebut akan membuat sebuah file "<i>status.txt</i>", di mana didalamnya berisi pesan <b>"Download Success"</b> yang terenkripsi dengan teknik <b>Caesar Cipher</b> dan dengan shift 5. Caesar Cipher adalah teknik enkripsi sederhana yang di mana dapat melakukan enkripsi string sesuai dengan shift/key yang kita tentukan. Misal huruf <b>"A"</b> akan dienkripsi dengan shift 4 maka akan menjadi "E". Karena Ranora orangnya perfeksionis dan rapi, dia ingin setelah <i>file</i> tersebut dibuat, direktori akan di-<i>zip</i> dan direktori akan di-<i>delete</i>, sehingga menyisakan hanya <i>file zip</i> saja.

### 3D ###

- <b>SOAL</b>

  Untuk mempermudah pengendalian program, pembimbing magang Ranora ingin program tersebut akan men-<i>generate</i> sebuah program <b>"Killer"</b> yang <i>executable</i>, di mana program tersebut akan menterminasi semua proses program yang sedang berjalan dan akan menghapus dirinya sendiri setelah program dijalankan. Karena Ranora menyukai sesuatu hal yang baru, maka Ranora memiliki ide untuk program <b>"Killer"</b> yang dibuat nantinya harus merupakan program <b>Bash</b>.

### 3E ###

- <b>SOAL</b>

  Pembimbing magang Ranora juga ingin nantinya program utama yang dibuat Ranora dapat dijalankan di dalam dua mode. Untuk mengaktifkan mode pertama, program harus dijalankan dengan argumen `-z`, dan ketika dijalankan dalam mode pertama dan program <b>Killer</b> dijalankan, program utama akan langsung menghentikan semua operasinya. Sedangkan untuk mengaktifkan mode kedua, program harus dijalankan dengan argumen `-x`, dan ketika dijalankan dalam mode kedua, program utama akan berhenti namun membiarkan proses di setiap direktori yang masih berjalan hingga selesai (direktori yang sudah dibuat akan men-<i>download</i> gambar sampai selesai dan membuat <i>file</i> `.txt`, lalu <i>zip</i> dan <i>delete</i> direktori).
