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

- <b>JAWABAN</b>

  Soal meminta untuk membuat program C berupa daemon yang akan berjalan tiap 40 detik dan akan melakukan `fork()` untuk melakukan `mkdir` dengan <i>timestamp</i> yang sesuai permintaan soal. Pertama, menggunakan <i>template</i> Daemon bawaan dari modul 2 yang nantinya akan dimodifikasi.
  ```C
  #include <sys/types.h>
  #include <sys/stat.h>
  #include <stdio.h>
  #include <stdlib.h>
  #include <fcntl.h>
  #include <errno.h>
  #include <unistd.h>
  #include <syslog.h>
  #include <string.h>
  #include <wait.h>
  #include <time.h>


  int main() {
    pid_t pid, sid;        // Variabel untuk menyimpan PID

    pid = fork();     // Menyimpan PID dari Child Process

    /* Keluar saat fork gagal
    * (nilai variabel pid < 0) */
    if (pid < 0) {
      exit(EXIT_FAILURE);
    }

    /* Keluar saat fork berhasil
    * (nilai variabel pid adalah PID dari child process) */
    if (pid > 0) {
      exit(EXIT_SUCCESS);
    }

    umask(0);

    sid = setsid();
    if (sid < 0) {
      exit(EXIT_FAILURE);
    }

    if ((chdir("/")) < 0) {
      exit(EXIT_FAILURE);
    }

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    while (1) {
      // Tulis program kalian di sini

      sleep(30);
    }
  }
  ```
  Di sini ketambahan library baru, yaitu `<wait.h>` untuk melakukan fungsi wait, dan `time.h` untuk manipulasi <i>date dan time</i>.
  
  Proses selanjutnya adalah melakukan pendeklarasian awal untuk memanipulasi <i>date</i> dan <i>time</i>-nya.
  ```C
  time_t rawtime = time(NULL);
  struct tm *timeinfo;
  char buffer[80];

  timeinfo = localtime(&rawtime);
  ```
  Variabel `rawtime` untuk menyimpan <i>timestamp</i> dalam format <b>Unix epoch</b>, variabel `timeinfo` untuk <i>timestamp</i> yang sudah terstruktur sesuai dengan `localtime`, dan variabel `buffer` sebagai <i>buffer</i> dari string hasil format variabel `timeinfo`.
  
  Kemudian <i>formatting</i> waktu `tm` menjadi string sesuai permintaan soal [YYYY-mm-dd_HH:ii:ss] ke dalam buffer `buffer` sebesar <b>80</b>. Di sini menggunakan `strftime`.
  ```C
  strftime(buffer, 80, "%Y-%m-%d_%X", timeinfo);
  ```
  
  Setelah itu, <i>process</i> akan di-`fork` dan <i>child process</i> melakukan `execv()` terhadap perintah `mkdir` dengan argumen `buffer`. <i>Parent process</i> tidak akan menunggu <i>child process</i> dan akan langsung `sleep` selama 40 detik.
  ```C
  pid_t child_id, child_id2, child_id3, child_id4;
  child_id = fork();

  // Child process 1
  if (child_id == 0) {
      char *argv[] = {"mkdir", buffer, NULL};
      execv("/bin/mkdir", argv);
  }
  
  ...
  
  sleep(40);
  ```
  Sebagai catatan, di sini sudah dilakukan pendeklarasian `child_id` sampai `child_id4` yang akan digunakan pada sub soal selanjutnya.
  
### 3B ###

- <b>SOAL</b>

  Setiap direktori yang sudah dibuat diisi dengan 10 gambar yang di-<i>download</i> dari https://picsum.photos/, di mana setiap gambar akan di-<i>download</i> setiap 5 detik. Setiap gambar yang di-<i>download</i> akan diberi nama dengan format <i>timestamp</i> [YYYY-mm-dd_HH:ii:ss] dan gambar tersebut berbentuk persegi dengan ukuran `(n % 1000) + 50 pixel` di mana <b>n</b> adalah detik <b>Epoch Unix</b>.

- <b>JAWABAN</b>
  
  Dari masing-masing folder yang telah dibuat, program akan melakukan `fork` lagi yang <i>child process</i>-nya akan <i>loop</i> sebanyak 10 kali, per loop akan melakukan `fork` kembali untuk mengunduh <i>file</i> di https://picsum.photos/. Kemudian, agar ukuran piksel sesuai dengan yang diminta, maka dapat diinputkan pada tautan tersebut, seperti contoh https://picsum.photos/200 yang mengunduh <i>file</i> dengan ukuran 200 × 200 piksel. Setelah itu, <i>loop</i> akan `sleep` selama 5 detik.
  ```C
  child_id2 = fork();
  
  // Child process 2
  if (child_id2 == 0) {
    for (int i = 0; i < 10; i++) {
    
    . . .
    
    sleep(5);
    }
  }
  ```
  <i>Child process</i> akan mengunduh 10 gambar setelah direktori dibuat. Tapi, program utamanya tidak akan menunggu <i>child process</i>-nya (mengunduh gambar) dan langsung `sleep` selama 40 detik selama 40 detik setelah fungsi `fork()` dijalankan.
  
  Pada masing-masing <i>loop</i> akan dibuat <i>child process</i> yang masing-masing mengunduh gambar dari <b><i>picsum photos</i></b> menggunakan `wget`.
  ```C
  child_id3 = fork();
                
  // Child process 3
  if (child_id3 == 0) {
      char buffer2[80], location[160], link[80];
      rawtime = time(NULL);

      timeinfo = localtime(&rawtime);
      strftime(buffer2, 80, "%Y-%m-%d_%X", timeinfo);

      sprintf(location, "%s/%s", buffer, buffer2);
      sprintf(link, "https://picsum.photos/%ld", ((rawtime % 1000) + 50));

      char *argv[] = {"wget", "-q", "-O", location, link, NULL};
      execv("/bin/wget", argv);
  }
  ```
  - Variabel `rawtime` digunakan untuk mengambil <b>Unix epoch</b> yang baru.
  - Variabel `timeinfo` untuk <i>timestamp</i> baru yang sudah terformat sesuai dengan `localtime`.
  - Variabel `buffer2` untuk menyimpan waktu saat ini yang sudah diformat menjadi string, variabel `location` untuk menyimpan lokasi output dari `wget`, dan variabel `link` untuk menyimpan alamat tempat mengunduh gambar dari <b><i>picsum photos</i></b>.
  
  Variabel `buffer2` akan diformat menggunakan `strftime()` berdasarkan nilai `timeinfo` yang baru. `location` akan diformat menjadi `buffer/buffer2` agar <i>file</i> yang telah diunduh masuk ke dalam folder yang diinginkan. `link` akan diformat sesuai dengan permintaan soal, yaitu `((rawtime % 1000) + 50)`, untuk mendapatkan foto dengan ukuran piksel tersebut, hanya perlu menambahkan nilai ke bagian paling belakang dari tautan https://picsum.photos/. `wget` akan dijalankan sesuai `location` dan `link` yang telah diformat tadi.

### 3C ###

- <b>SOAL</b>

  Setelah direktori telah terisi dengan 10 gambar, program tersebut akan membuat sebuah <i>file</i> "<i>status.txt</i>", di mana didalamnya berisi pesan <b>"Download Success"</b> yang terenkripsi dengan teknik <b>Caesar Cipher</b> dan dengan shift 5. Caesar Cipher adalah teknik enkripsi sederhana yang di mana dapat melakukan enkripsi string sesuai dengan shift/key yang kita tentukan. Misal huruf <b>"A"</b> akan dienkripsi dengan shift 4 maka akan menjadi "E". Karena Ranora orangnya perfeksionis dan rapi, dia ingin setelah <i>file</i> tersebut dibuat, direktori akan di-<i>zip</i> dan direktori akan di-<i>delete</i>, sehingga menyisakan hanya <i>file zip</i> saja.
  
- <b>JAWABAN</b>

  Pada bagian ini, setelah selesai <i>loop</i> untuk mengunduh 10 gambar, program akan melakukan `fork()` dan membuat sebuah <i>file</i> <i>status.txt</i> yang berisi enkripsi <b>"Download Success"</b> dengan teknik <b>Caesar Cipher</b> shift 5. Referensi tentang <i>source code</i> Caesar Cipher bisa dicari di internet.
  ```C
  while (wait(NULL) > 0);

  child_id4 = fork();
  
  // Child process 4
  if (child_id4 == 0) {
    char message[80] = "Download Success", file_name[160];
    
    for (int j = 0; j < strlen(message); j++) {
        if (message[j] >= 'a' && message[j] <= 'z') {
            message[j] += 5;

            if (temp > 'z') {
                message[j] = message[j] - 'z' + 'a' - 1;
            }
        }

        else if (message[j] >= 'A' && message[j] <= 'Z') {
            message[j] += 5;

            if (temp > 'Z') {
                message[j] = message[j] - 'Z' + 'A' - 1;
            }
        }
    }
    
    sprintf(file_name, "%s/%s", buffer, "status.txt");
    FILE *txt = fopen(file_name, "w");

    fputs(message, txt);
    fclose(txt);
                
    . . .
    
  }
  ```
  - Variabel `message` untuk menyimpan <b>"Download Success"</b> yang akan dienkripsi dan variabel `file_name` sebesar <b>160</b> menyimpan hasil enkripsi <b>Caesar Cipher</b>.
  - `sprintf` pertama untuk menulis string dengan format `buffer/status.txt` ke variabel `file_name`.
  - `txt` sebagai pointer ke <i>file</i>.
  - `fopen` digunakan untuk membuka <i>file</i> yang diinginkan, menggunakan command `W` untuk membuat <i>file</i> baru dan melakukan proses <i>writing</i>.
  - `fputs` digunakan untuk menyimpan string `message` ke dalam `txt`. 
  -  `fclose` digunakan untuk menutup koneksi dari `txt`.
  
  Selanjutnya, program akan melakukan `execv` dengan perintah `zip`. <i>Parent process</i> akan menunggu sampai seluruh unduhan `wget` selesai. Terakhir, <i>parent process</i> akan menunggu <i>child process</i> selesai dan menghapus direktori folder yang telah di-`zip`.
  ```C
  if (child_id4 == 0) {
    
    . . .

    sprintf(file_name, "%s.zip", buffer);

    char *argv[] = {"zip", "-r", file_name, buffer, NULL};
    execv("/bin/zip", argv);
  }
  
  while (wait(NULL) != child_id4);
            
  char *argv[] = {"rm", "-r", buffer, NULL};
  execv("/bin/rm", argv);
  ```
  <i>Command zip</i> `-r` digunakan agar zip direktori dilakukan secara rekursif dan `-q` agar output log dari <i>command</i> tidak dicetak. Sedangkan <i>Command remove</i> `-r` agar melakukan proses <i>remove</i> secara rekursif juga.

### 3D ###

- <b>SOAL</b>

  Untuk mempermudah pengendalian program, pembimbing magang Ranora ingin program tersebut akan men-<i>generate</i> sebuah program <b>"Killer"</b> yang <i>executable</i>, di mana program tersebut akan menterminasi semua proses program yang sedang berjalan dan akan menghapus dirinya sendiri setelah program dijalankan. Karena Ranora menyukai sesuatu hal yang baru, maka Ranora memiliki ide untuk program <b>"Killer"</b> yang dibuat nantinya harus merupakan program <b>Bash</b>.

- <b>JAWABAN</b>
  
  Setelah semua proses di atas, men-<i>generate</i> program <b>"Killer"</b> dengan <i>file</i> bernama <i>Killer.sh</i> dan penginputannya melalui program C yang telah dibuat. Program C ini akan melakukan `pkill` sesuai Session ID (`sid`) yang telah di-set dan melakukan `rm` terhadap <i>file</i> <b>"Killer"</b>.
  ```C
  FILE *killer_prog = fopen("killer.sh", "w");
  ```
  - `killer_prog` sebagai pointer ke <i>file</i>.
  - `fopen` digunakan untuk membuka <i>file</i> yang diinginkan, menggunakan command `W` untuk membuat <i>file</i> baru dan melakukan proses <i>writing</i>.
  
  Pendeklarasian di atas dilakukan sebelum <i>loop</i> utama daemon dan setelah mendapatkan Session ID (`sid`).
  
  Lalu, <i>file killer.sh</i> diinputkan dengan string untuk melakukan proses `pkill`sesuai dengan Session ID (`sid`) dari program utama. Hal ini dilakukan juga agar seluruh <i>child process</i> juga ikut di-`kill`. Setelah itu, program <b>"Killer"</b> akan menghapus dirinya sendiri.
  ```C
  char *inputan = ""
  "#!/bin/bash\n"
  "killall -9 ./soal3\n"
  "rm $0\n";
  fprintf(killer_prog, inputan, sid);
  ```
  `fork()` dijalankan sehingga <i>child process</i> akan melakukan `pkill` dan <i>parent process</i> akan menunggu <i>child process</i> melakukan `rm`. String di-<i>write</i> ke dalam `killer_prog` dengan fungsi `fprintf()`.
  
  Lalu `killer_prog` akan ditutup koneksinya menggunakan `fclose()`.
  ```C
  fclose(killer_prog);
  ```

### 3E ###

- <b>SOAL</b>

  Pembimbing magang Ranora juga ingin nantinya program utama yang dibuat Ranora dapat dijalankan di dalam dua mode. Untuk mengaktifkan mode pertama, program harus dijalankan dengan argumen `-z`, dan ketika dijalankan dalam mode pertama dan program <b>Killer</b> dijalankan, program utama akan langsung menghentikan semua operasinya. Sedangkan untuk mengaktifkan mode kedua, program harus dijalankan dengan argumen `-x`, dan ketika dijalankan dalam mode kedua, program utama akan berhenti namun membiarkan proses di setiap direktori yang masih berjalan hingga selesai (direktori yang sudah dibuat akan men-<i>download</i> gambar sampai selesai dan membuat <i>file</i> `.txt`, lalu <i>zip</i> dan <i>delete</i> direktori).
