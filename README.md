# Soal Shift Sisop 2021 Modul 2

Kelompok D-04
- Thomas Felix Brilliant (05111940000062)
- Muhammad Rizky Widodo (05111940000216)
- Fiodhy Ardito Narawangsa (05111940000218)

## SOAL 1 ##

### 1A ###

- <b>SOAL</b>

  Dikarenakan Stevany sangat menyukai huruf <b>Y</b>, Steven ingin nama folder-foldernya adalah <b>Musyik</b> untuk mp3, <b>Fylm</b> untuk mp4, dan <b>Pyoto</b> untuk jpg.
  
- <b>JAWABAN</b>
  
  Untuk no 1A pertama akan dilakukan <i>spawning process</i> untuk membuat folder-folder yang diinginkan dengan cara sebagai berikut:
  ```C
  child_id = fork();
    
  if(child_id < 0)
  {
      exit(EXIT_FAILURE);
  }

  if(child_id == 0)
  {
      //Buat Folder
      char *argv[] = {"mkdir","Musyik","Pyoto","Fylm",NULL};
      execv("/bin/mkdir",argv);
  }
  ```
   Di sini pertama akan melakukan fork kemudian di dalam fork tersebut <i>parent child process</i> akan membuat folder-folder yang diinginkan dengan perintah `execv` dengan parameter `argv` yang didalamnya terdapat perintah `mkdir` untuk membuat folder dengan nama yang diinginkan.

### 1B ###

- <b>SOAL</b>

  Untuk musik Steven <b>men-<i>download</i>-nya</b> dari link di bawah, film dari link di bawah lagi, dan foto dari link di bawah juga :).
  
- <b>JAWABAN</b>
  
  Untuk soal 1B didalam <i>parent process</i> akan melakukan <i>forking</i> lagi untuk melakukan download seperti berikut:
  ```C
  else
  {
      child_id_2 = fork();
      
      if(child_id_2 < 0)
      {
          exit(EXIT_FAILURE);
      }
      
      if(child_id_2 == 0)
      {
          child_id_3 = fork();
          
          if(child_id_3 < 0)
          {
              exit(EXIT_FAILURE);
          }
          
          if (child_id_3 == 0)
          {
              //Download Foto
              char *argv[] = {"wget","-q","--no-check-certificate","https://drive.google.com/uc?id=1FsrAzb9B5ixooGUs0dGiBr-rC7TS9wTD&export=download","-O","Foto_for_Stevany.zip",NULL};
              execv("/usr/bin/wget",argv);
          }
   }
   ```
   Di sini akan dilakukan <i>download</i> untuk setiap zip yang berbeda dengan cara yang sama yaitu dengan menggunakan perintah `wget`, program akan melakukan <i>spawning process</i> untuk setiap kali melakukan <i>download</i>.

### 1C ###

- <b>SOAL</b>

  Steven tidak ingin isi folder yang dibuatnya berisikan <i>zip</i>, sehingga perlu <b>meng-<i>extract</i>-nya</b> setelah di-<i>download</i>.
  
- <b>JAWABAN</b>
  
  Untuk soal 1C program akan melakukan <i>unzip</i> untuk setiap file zip yang telah di-<i>download</i> secara berurutan dengan cara sebagai berikut:
  ```C
  else
  {
      //unzip Foto
      while((wait(&status)) > 0);
      char *argv[] = {"unzip","-oq","Foto_for_Stevany.zip",NULL};
      execv("/usr/bin/unzip",argv);
  }
  ```
  Di sini program pertama-tama melakukan menunggu dulu <i>download</i> sebuah <i>file</i> zip selesai dengan fungsi `wait` yang ada di setiap <i>process</i> sehingga setiap kali program men-<i>download</i> akan ditunggu dulu hingga satu zip ter-<i>download</i> lalu file zip tersebut akan di-<i>unzip</i> dan kemudian akan lanjut ke <i>download</i> selanjutnya.

### 1D ###

- <b>SOAL</b>

  Memindahkan <i>file extract</i> tadi ke dalam folder yang telah dibuat (hanya <i>file</i> yang dimasukkan).
  
- <b>JAWABAN</b>
  
  Untuk soal 1D kita disuruh untuk memindahkan file dari hasil yang sudah di-<i>unzip</i> ke file-file yang sudah dibuat dengan cara berikut:
  ```C
  DIR *folder;
  struct dirent *file;
  chdir("./FOTO/");
  folder = opendir(".");
  
  if(folder)
  {
      while((file = readdir(folder)) != NULL)
      {
          child_id_9 = fork();
          
          if(child_id_9 == 0)
          {
              char *argv[] = {"mv", file->d_name, "../Pyoto/", NULL};
              execv("/bin/mv",argv);
          }
          
          else
          {
              while((wait(&status)) > 0);
          }
      }
      
      closedir(folder);
      chdir("../");
  }
  ```
  Pertama kita menggunakan <i>library</i> `<dirent.h>` yang di dalamnya terdapat fungsi `opendir` untuk membuka isi folder dan kemudian di-<i>looping</i> dengan parameter fungsi `readdir` untuk membaca isi folder sehingga <i>file-file</i> yang ada di dalam folder bisa dipindahkan. Kemudian setelah <i>file-file</i> didalam folder bisa terbaca selanjutnya dengan menggunakan perintah `mv` di dalam `execv` maka <i>file-file</i> tersebut akan dipindahkan ke <i>file</i> tujuan.

### 1E ###

- <b>SOAL</b>

  Untuk memudahkan Steven, ia ingin semua hal di atas berjalan <b>otomatis</b> 6 jam sebelum waktu ulang tahun Stevany.
  Setelah itu pada <b>waktu</b> ulang tahunnya Stevany, semua folder akan di-<i>zip</i> dengan nama <i>Lopyu_Stevany.zip</i> dan semua folder akan <b>di-<i>delete</i></b> (sehingga hanya menyisakan .zip).
  
- <b>JAWABAN</b>
  
  Untuk soal 1E disuruh untuk menjalankannya secara otomatis pada waktu yang telah ditentukan kemudian men-<i>zip</i> folder-folder yang telah dibuat dengan cara berikut ini:
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
  
  Pertama menggunakan template daemon dari github modul 2 agar program bisa berjalan di background. kemudian dengan menggunakan library `time.h`  untuk mengatur jadwalnya seperti berikut:
  ```C
  time_t jadwal = time(NULL);
  struct tm *waktu = localtime(&jadwal);
  int status;
  if(waktu->tm_mon == 3 && waktu->tm_mday == 9 && waktu->tm_hour == 16 && waktu->tm_min == 22 && waktu->tm_sec == 0 )
  ```
  
  Kemudian setelah ada penjadwalan seperti ini maka selanjutnya tinggal men-<i>zip</i> dan <i>remove</i> folder seperti perintah pada soal sesuai jadwal yang telah diinginkan sebagai berikut:
  ```C
  else if (waktu->tm_mon == 3 && waktu->tm_mday == 9 && waktu->tm_hour == 22 && waktu->tm_min == 22 && waktu->tm_sec == 0)
  {
       pid_t child_id_13;
       child_id_13 = fork();
       
       if(child_id_13 < 0)
       {
           exit(EXIT_FAILURE);
       }
       
       if(child_id_13 == 0)
       {
           char *argv[] = {"zip", "-qrm", "Lopyu_Stevany.zip", "Pyoto", "Musyik", "Fylm", NULL};
           execv("/usr/bin/zip", argv);
       }
    
       else
       {
           while((wait(&status)) > 0);
           char *argv[] = {"rm", "-r", "FOTO", "MUSIK", "FILM", NULL};
           execv("/bin/rm",argv);
       }
  }
  ```
    Di sini sesuai jadwal yang telah ditentukan pada `if` maka program akan men-<i>zip</i> folder-folder yang diinginkan kemudian akan menghapus folder sisanya yang tidak terpakai dengan perintah `zip` untuk menzip dan `rm` untuk menghapus.
    
    Error yang dialami dalam mengerjakan soal ini yaitu ketika melakukan process spawning karena bingung ketika meletakkan variabel `child_id` kemudian untuk <i>move file</i> yang mana terjadi beberapa error karena adanya kesalahan tujuan direktori.
  
 
## SOAL 2 ## 
 
### 2A ###

- <b>SOAL</b>

  Pertama-tama program perlu meng-<i>extract zip</i> yang diberikan ke dalam folder <b>"/home/[user]/modul2/petshop"</b>. Karena bos Loba teledor, dalam <i>zip</i> tersebut bisa berisi folder-folder yang tidak penting, maka program harus bisa membedakan <i>file</i> dan folder sehingga dapat memproses <i>file</i> yang seharusnya dikerjakan dan menghapus folder-folder yang tidak dibutuhkan.
  
- <b>JAWABAN</b>

  Pertama, menggunakan <i>template</i> Daemon bagian <i>Directory Listing</i> bawaan dari modul 2 yang nantinya akan dimodifikasi.
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
  #include <dirent.h>

  int main() {
      pid_t child_id, child_id2, child_id3, child_id4, child_id5, child_id6, child_id7;
      child_id = fork();

      if (child_id < 0) {
          exit(0);
      }
      
      if (child_id == 0) {
          
          . . .
      
      }
      
      . . .
      
  }
  ```
  Pada <i>code</i> di atas ditambahkan library `<dirent.h>` untuk memudahkan pembacaan <i>file</i> yang ada di dalam direktori.
  
  Setelah itu, <i>process</i> akan di-`fork` dan <i>child process</i> melakukan `execv()` terhadap perintah `unzip` dengan argumen <b>"/home/thomasfelix/modul2/pets.zip"</b>. sesuai posisi direktori <i>file</i> zip.
  ```C
  if (child_id == 0) {
      char *argv[] = {"unzip", "/home/thomasfelix/modul2/pets.zip", "*;*", "-d", "/home/thomasfelix/modul2/petshop", NULL};
      execv("/bin/unzip", argv);
  }
  
  while (wait(NULL) > 0);
  ```
  Lalu, dengan mode `-d` untuk mengarahkan hasil <i>unzip</i> ke direktori tertentu sesuai permintaan soal dan `*;*` untuk mencari <i>file</i> yang mengandung karakter `;` (karena format soal).
  
  Selanjutnya, terlebih dahulu membuka direktori hasil <i>unzip</i> berada dengan perintah `opendir()`.  Melakukan <i>looping</i> selama `readdir` bernilai benar untuk membaca semua <i>file</i> yang ada di dalam direktori. Kemudian, dirent di sini adalah struct, maka saat memanggilnya, digunakan perintah `dir->d_name` sebagai contoh.
  ```C
  DIR *dir = opendir("/home/thomasfelix/modul2/petshop");
  struct dirent *direntp;
    
  while((direntp = readdir(dir))) {
      if ((direntp->d_type == DT_DIR) && strcmp(direntp->d_name, ".") != 0 && strcmp(direntp->d_name, "..") != 0) {
          child_id2 = fork();

          if (child_id2 == 0) {
              char folder_name[300];

              sprintf(folder_name, "/home/thomasfelix/modul2/petshop/%s", direntp->d_name);

              char *argv[] = {"rm", "-r", folder_name, NULL};
              execv("/bin/rm", argv);
          }
      }
  }

  while (wait(NULL) > 0);
  ```
  - Perintah `direntp->d_type` digunakan untuk menampung tipe/jenis <i>file</i>. Dilakukan pengondisian jika di dalam direktori berisi folder dengan <i>compare</i> `DT_DIR`.
  - Perintah `direntp->d_name` digunakan untuk menampung nama <i>file</i> yang ada di dalam direktori. Dilakukan pengondisian dan <i>compare</i> dengan fungsi `strcmp` untuk penghapusan folder <i>file</i> di dalam hasil <i>unzip</i> selain folder yang ter-<i>hidden</i> dengan nama direktori <b>"."</b> dan <b>".."</b>.
  - <i>Process</i> di-`fork` dan <i>child process</i> melakukan `sprintf` untuk memasukkan nama <i>file</i> ke dalam variabel `folder_name`. Lalu `execv()` terhadap perintah `rm` dengan argumen `folder_name` untuk menghapus folder-folder tidak penting sesuai permintaan soal dan <i>command</i> `-r` untuk penghapusan secara rekursif.


### 2B ###

- <b>SOAL</b>

  Foto peliharaan perlu dikategorikan sesuai jenis peliharaan, maka kamu harus membuat folder untuk setiap jenis peliharaan yang ada dalam <i>zip</i>. Karena kamu tidak mungkin memeriksa satu per satu, maka program harus membuatkan folder-folder yang dibutuhkan sesuai dengan isi <i>zip</i>.

  Contoh: Jenis peliharaan kucing akan disimpan dalam <b>"/petshop/cat"</b>, jenis peliharaan kura-kura akan disimpan dalam <b>"/petshop/turtle"</b>.

- <b>JAWABAN</b>
  
  Sama seperti soal sebelumnya, menggunakan <i>Directory Listing</i> untuk membantu membuat folder sesuai kategori jenis hewannya. Pertama, deklarasikan variabel `folder` untuk menyimpan jenis-jenis hewan dalam <i>array of char</i> 2D (dalam C++ ini adalah <i>array of string</i>) dan `index` sebagai bantuan <i>indexing</i> pada `folder`.
  ```C
  DIR *dir2 = opendir("/home/thomasfelix/modul2/petshop");
  struct dirent *direntp2;

  char folder[100][200];
  int index = 0;

  while((direntp2 = readdir(dir2))) {
      if (direntp2->d_type == DT_REG) {
          char temp[200], temp2[200];

          memset(folder[index], 0, sizeof(folder[index]));
          memset(temp2, 0, sizeof(temp2));

          strcpy(temp, direntp2->d_name);

          int flag = 0;

          . . .
          
      }
  }
  ```
  - Perintah `direntp->d_type` digunakan untuk menampung tipe/jenis <i>file</i>. Dilakukan pengondisian jika di dalam direktori berisi file dengan <i>compare</i> `DT_REG`.
  - Mendeklarasikan variabel `temp` dan `temp2` untuk menyimpan sementara nama jenis hewan dari masing-masing <i>file</i> dan `flag` sebagai penanda untuk <i>looping</i> nanti.
  - Fungsi `memset` untuk memastikan bahwa seluruh isi dari `folder[index]` dan `temp2` bernilai 0 atau NULL.
  - Dengan fungsi `strcpy` memindah isi dari `direntp2->d_name` ke dalam variabel `temp`.
  
  Kemudian melakukan <i>looping</i> untuk mencari jenis hewan yang ada di dalam penamaan <i>file</i> foto.
  ```C
  for (int i = 0; i < strlen(temp); i++) {
      if (temp[i] == ';') {
          break;
      }

      temp2[i] = temp[i];
  }

  if (flag == 0) {
      strcpy(folder[index], temp2);
      index++;
  }

  for (int i = 0; i < index; i++) {
      if (strcmp(folder[i], temp) == 0) {
          flag = 1;
      }
  }
  ```
  Karena dalam penamaan file jenis hewan dipisahkan oleh karakter ";", maka <i>looping</i> akan berhenti ketika menemukan karakter ";" dan setiap <i>looping</i> itu akan memasukkan char satu per satu ke variabel `temp2`. Lalu jika `flag` sama dengan 0 untuk memindah `temp2` ke `folder[index]` dan meng-<i>increment</i> `index`. Dan terakhir me-<i>loop</i> untuk <i>compare</i> `folder` dengan `temp`.
  
  Setelah itu, <i>looping</i> untuk membuat folder sebanyak <i>file</i> foto yang ada.
  ```C
  for (int i = 0; i < index; i++) {
      child_id3 = fork();

      if (child_id3 == 0) {
          char folder_tujuan[250];
          sprintf(folder_tujuan, "/home/thomasfelix/modul2/petshop/%s", folder[i]);

          char *argv[] = {"mkdir", "-p", folder_tujuan, NULL};
          execv("/bin/mkdir", argv);
      }
  }
  
  while (wait(NULL) > 0);
  ```
  <i>Process</i> di-`fork` dan <i>child process</i> melakukan `sprintf` untuk memasukkan nama <i>file</i> ke dalam variabel `folder_tujuan`. Lalu `execv()` terhadap perintah `mkdir` dengan argumen `folder_tujuan` untuk membuat folder baru sesuai jenis hewan yang telah diambil dari penamaan nama <i>file</i> dan <i>command</i> `-p` untuk penanganan error yang akan diabaikan.

### 2C ###

- <b>SOAL</b>

  Setelah folder kategori berhasil dibuat, programmu akan memindahkan foto ke folder dengan kategori yang sesuai dan di-<i>rename</i> dengan nama peliharaan.
  
  Contoh: <b>"/petshop/cat/joni.jpg"</b>.
  
- <b>JAWABAN</b>
  
  Sama seperti soal sebelumnya, menggunakan <i>Directory Listing</i> untuk membantu memindah <i>file</i> ke folder sesuai kategori jenis hewannya. Pertama, deklarasikan variabel `file` untuk menyimpan nama <i>file</i> foto.
  ```C
  DIR *dir3 = opendir("/home/thomasfelix/modul2/petshop");
  struct dirent *direntp3;

  while((direntp3 = readdir(dir3))) {
      if (direntp3->d_type == DT_REG) {
          char file[200], nama[200], jenis[200], umur[200];
          char nama2[200], jenis2[200], umur2[200];

          memset(nama, 0, sizeof(nama));
          memset(jenis, 0, sizeof(jenis));
          memset(umur, 0, sizeof(umur));
          memset(nama2, 0, sizeof(nama2));
          memset(jenis2, 0, sizeof(jenis2));
          memset(umur2, 0, sizeof(umur2));

          strcpy(file, direntp3->d_name);
          
          int flag = 0, found = 0, found_two = 0;
          
          . . .
          
  }
  ```
  - Perintah `direntp->d_type` digunakan untuk menampung tipe/jenis <i>file</i>. Dilakukan pengondisian jika di dalam direktori berisi file dengan <i>compare</i> `DT_REG`.
  - Mendeklarasikan variabel `nama`, `jenis`, dan `umur` untuk menyimpan nama, jenis, dan umur hewan pertama dari masing-masing <i>file</i> dan `nama2`, `jenis2`, dan `umur2` untuk menyimpan nama, jenis, dan umur hewan kedua.
  - Variabel `flag` sebagai penanda untuk pengondisian dalam <i>looping</i> nanti yang membedakan nama, jenis, dan umur hewan, `found` untuk membantu <i>indexing</i> dalam <i>looping</i>, dan `found_two` sebagai variabel hewan kedua yang akan digunakan pada [soal.2d](#2d "Goto 2d").
  - Fungsi `memset` untuk memastikan bahwa seluruh isi dari `nama`, `jenis`, `umur`, `nama2`, `jenis2`, dan `umur2` bernilai 0 atau NULL.
  - Dengan fungsi `strcpy` memindah isi dari `direntp3->d_name` ke dalam variabel `file`.
  
  Kemudian melakukan <i>looping</i> untuk mencari jenis, nama, dan umur hewan pertama yang ada di dalam penamaan <i>file</i> foto.
  ```C
  for (int i = 0; i < strlen(file); i++) {
  if (flag == 0) {
      if (file[i] == ';') {
          flag++;
          found = i + 1;
          continue;
      }

      jenis[i] = file[i];
  }

  else if (flag == 1) {
      if (file[i] == ';') {
          flag++;
          found = i + 1;
          continue;
      }

      nama[i - found] = file[i];
  }

  else if (flag == 2) {
      if (file[i] == '_') {
          flag++;
          found = i + 1;
          continue;
      }

      else if ((file[i] == '.') && (file[i + 1] == 'j')) {
          break;
      }

      umur[i - found] = file[i];
  }
  
  . . .
  
  ```
  - Jika `flag` sama dengan 0, menjalankan loop `jenis`. Karena dalam penamaan file jenis hewan dipisahkan oleh karakter <b>";"</b>, maka <i>looping</i> akan memasukkan char satu per satu ke variabel `jenis` sampai menemukan <b>";"</b>. Lalu jika <i>loop</i> menemukan <b>";"</b>, `flag` di-<i>increment</i>, `found` ditambahkan dengan `i + 1`, dan <i>looping</i> di-<i>continue</i>, lanjut ke <i>loop</i> `nama`.
  - Jika `flag` sama dengan 1, menjalankan loop `nama`. Karena dalam penamaan file jenis hewan dipisahkan oleh karakter <b>";"</b>, maka <i>looping</i> akan memasukkan char satu per satu ke variabel `nama` sampai menemukan <b>";"</b>. Lalu jika <i>loop</i> menemukan <b>";"</b>, `flag` di-<i>increment</i>, `found` ditambahkan dengan `i + 1`, dan <i>looping</i> di-<i>continue</i>, lanjut ke <i>loop</i> `jenis`.
  - Jika `flag` sama dengan 2, menjalankan loop `umur`. Karena dalam penamaan file jenis hewan dipisahkan oleh karakter <b>"*_*"</b>, maka <i>looping</i> akan memasukkan char satu per satu ke variabel `umur` sampai menemukan <b>"*_*"</b> atau <b>"."</b> dan <b>"j"</b>. Lalu jika <i>loop</i> menemukan <b>"*_*"</b>, `flag` di-<i>increment</i>, `found` ditambahkan dengan `i + 1`, dan <i>looping</i> di-<i>continue</i>, lanjut ke <i>loop</i> `jenis2`, dan jika <i>loop</i> menemukan <b>"*.*"</b> dan <b>"j"</b> akan berhenti (menemukan <i>.jpg</i>).
  
  Setelah itu, membuat <i>child</i> baru untuk <i>copy file</i> foto ke foldernya masing-masing.
  ```C
  child_id4 = fork();
 
  if (child_id4 == 0) {
      char origin[450], goal[450];

      sprintf(origin, "/home/thomasfelix/modul2/petshop/%s", direntp3->d_name);
      sprintf(goal, "/home/thomasfelix/modul2/petshop/%s/%s", jenis, nama);

      char *argv[] = {"cp", "-r", origin, goal, NULL};
      execv("/bin/cp", argv);
  }

  while (wait(NULL) > 0);
  ```
  <i>Process</i> di-`fork` dan <i>child process</i> melakukan `sprintf` untuk memasukkan nama <i>file</i> ke dalam variabel `origin` serta memasukkan jenis dan nama hewan ke variabel `goal`. Lalu `execv()` terhadap perintah `cp` dengan argumen `origin` untuk <i>copy file</i> ke folder sesuai jenis hewan yang telah diambil dari penamaan nama <i>file</i>, kemudian penamaan <i>file</i> dengan nama hewan dan <i>command</i> `-r` untuk <i>copy</i> secara rekursif.

### 2D ###

- <b>SOAL</b>

  Karena dalam satu foto bisa terdapat lebih dari satu peliharaan, maka foto harus dipindah ke masing-masing kategori yang sesuai.
  
  Contoh: foto dengan nama <b>"dog;baro;1_cat;joni;2.jpg"</b> dipindah ke folder <b>"/petshop/cat/joni.jpg</b> dan <b>"/petshop/dog/baro.jpg</b>.
  
- <b>JAWABAN</b>
  
  Melanjutkan [soal.2c](#2c "Goto 2c"), di dalam <i>looping</i> melakukan input char satu per satu ke dalam nama, jenis, dan umur hewan kedua.
  ```C
  else if (flag == 3) {
      if (file[i] == ';') {
          flag++;
          found = i + 1;
          continue;
      }

      jenis2[i - found] = file[i];
  }

  else if (flag == 4) {
      if (file[i] == ';') {
          flag++;
          found = i + 1;
          continue;
      }

      nama2[i - found] = file[i];
  }

  else if (flag == 5) {
      if ((file[i] == '.') && (file[i + 1] == 'j')) {
          found_two = 1;
          break;
      }

      umur2[i - found] = file[i];
  }
  ```
  - Jika `flag` sama dengan 3, menjalankan loop `jenis2`. Karena dalam penamaan file jenis hewan dipisahkan oleh karakter <b>";"</b>, maka <i>looping</i> akan memasukkan char satu per satu ke variabel `jenis2` sampai menemukan <b>";"</b>. Lalu jika <i>loop</i> menemukan <b>";"</b>, `flag` di-<i>increment</i>, `found` ditambahkan dengan `i + 1`, dan <i>looping</i> di-<i>continue</i>, lanjut ke <i>loop</i> `nama2`.
  - Jika `flag` sama dengan 4, menjalankan loop `nama2`. Karena dalam penamaan file jenis hewan dipisahkan oleh karakter <b>";"</b>, maka <i>looping</i> akan memasukkan char satu per satu ke variabel `nama2` sampai menemukan <b>";"</b>. Lalu jika <i>loop</i> menemukan <b>";"</b>, `flag` di-<i>increment</i>, `found` ditambahkan dengan `i + 1`, dan <i>looping</i> di-<i>continue</i>, lanjut ke <i>loop</i> `jenis2`.
  - Jika `flag` sama dengan 5, menjalankan loop `umur2`. Karena dalam penamaan file jenis hewan dipisahkan oleh karakter <b>"*_*"</b>, maka <i>looping</i> akan memasukkan char satu per satu ke variabel `umur2` sampai menemukan atau <b>"."</b> dan <b>"j"</b>. Lalu jika <i>loop</i> menemukan <b>"*.*"</b> dan <b>"j"</b> akan berhenti (menemukan <i>.jpg</i>) dan variabel `found_two` menjadi 1.
  
  Setelah itu, membuat <i>child</i> baru untuk <i>copy file</i> foto hewan kedua ke foldernya masing-masing dengan pengondisian variabel `found_two` sama dengan 1.
  ```C
  if (found_two == 1) {
  child_id5 = fork();
 
  if (child_id5 == 0) {
      char origin[450], goal[450];

      sprintf(origin, "/home/thomasfelix/modul2/petshop/%s", direntp3->d_name);
      sprintf(goal, "/home/thomasfelix/modul2/petshop/%s/%s", jenis2, nama2);

      char *argv[] = {"cp", "-r", origin, goal, NULL};
      execv("/bin/cp", argv);
  }

  while (wait(NULL) > 0);
  
  . . .
  
  }
  ```
  <i>Process</i> di-`fork` dan <i>child process</i> melakukan `sprintf` untuk memasukkan nama <i>file</i> ke dalam variabel `origin` serta memasukkan jenis dan nama hewan ke variabel `goal`. Lalu `execv()` terhadap perintah `cp` dengan argumen `origin` untuk <i>copy file</i> ke folder sesuai jenis hewan kedua yang telah diambil dari penamaan nama <i>file</i>, kemudian penamaan <i>file</i> dengan nama hewan kedua dan <i>command</i> `-r` untuk <i>copy</i> secara rekursif.

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

  Setelah direktori telah terisi dengan 10 gambar, program tersebut akan membuat sebuah <i>file</i> "<i>status.txt</i>", di mana didalamnya berisi pesan <b>"Download Success"</b> yang terenkripsi dengan teknik <b>Caesar Cipher</b> dan dengan shift 5. Caesar Cipher adalah teknik enkripsi sederhana yang di mana dapat melakukan enkripsi string sesuai dengan shift/key yang kita tentukan. Misal huruf <b>"A"</b> akan dienkripsi dengan shift 4 maka akan menjadi <b>"E"</b>. Karena Ranora orangnya perfeksionis dan rapi, dia ingin setelah <i>file</i> tersebut dibuat, direktori akan di-<i>zip</i> dan direktori akan di-<i>delete</i>, sehingga menyisakan hanya <i>file zip</i> saja.
  
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

               if (message[j] > 'z') {
                   message[j] = message[j] - 'z' + 'a' - 1;
               }
           }

           else if (message[j] >= 'A' && message[j] <= 'Z') {
               message[j] += 5;

               if (message[j] > 'Z') {
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
  
  Lalu, <i>file killer.sh</i> diinputkan dengan string untuk melakukan proses `killall`sesuai dengan Session ID (`sid`) dari program utama. Hal ini dilakukan juga agar seluruh <i>child process</i> juga ikut di-`kill`. Setelah itu, program <b>"Killer"</b> akan menghapus dirinya sendiri.
  ```C
  char *inputan = ""
  "#!/bin/bash\n"
  "killall -9 ./soal3\n"
  "rm $0\n";
  fprintf(killer_prog, inputan, sid);
  ```
  `fork()` dijalankan sehingga <i>child process</i> akan melakukan `killall` dan <i>parent process</i> akan menunggu <i>child process</i> melakukan `rm`. String di-<i>write</i> ke dalam `killer_prog` dengan fungsi `fprintf()`.
  
  Lalu `killer_prog` akan ditutup koneksinya menggunakan `fclose()`.
  ```C
  fclose(killer_prog);
  ```

### 3E ###

- <b>SOAL</b>

  Pembimbing magang Ranora juga ingin nantinya program utama yang dibuat Ranora dapat dijalankan di dalam dua mode. Untuk mengaktifkan mode pertama, program harus dijalankan dengan argumen `-z`, dan ketika dijalankan dalam mode pertama dan program <b>Killer</b> dijalankan, program utama akan langsung menghentikan semua operasinya. Sedangkan untuk mengaktifkan mode kedua, program harus dijalankan dengan argumen `-x`, dan ketika dijalankan dalam mode kedua, program utama akan berhenti namun membiarkan proses di setiap direktori yang masih berjalan hingga selesai (direktori yang sudah dibuat akan men-<i>download</i> gambar sampai selesai dan membuat <i>file</i> `.txt`, lalu <i>zip</i> dan <i>delete</i> direktori).
  
- <b>JAWABAN</b>

  Untuk membuat mode, perlu menambahkan parameter pada `main()` untuk menerima argumen. Pertama membuat <i>file killer.sh</i>, kemudian mengecek argumen yang diinputkan pada terminal. Jika argumen `-z` akan langsung menghentikan semua operasi program utama, jika argumen `-x` hanya akan terminasi <i>parent process</i>, sedangkan <i>child process</i> akan ditunggu hingga selesai.
  ```C
  int main(int argc, char *argv[]) {
    
       // Jika banyaknya argumen salah
       if (argc != 2) {
           printf("ERROR! Argumen salah!\n");
           return 1;
       }

       // Jika argumen yang dimasukkan salah
       if (strcmp(argv[1], "-z") != 0 && strcmp(argv[1], "-x") != 0) {
           printf("ERROR! Mode salah!\n");
           return 1;
       }
    
    . . .
    
  }
  ```
  Banyaknya argumen akan dicek dan akan mengeluarkan output <b>"ERROR! Argumen salah!"</b>, sedangkan `argv[1]` juga akan dicek apakah sesuai dengan mode yang ada dan akan mengeluarkan output <b>"ERROR! Mode salah!"</b>.
  
  Lalu, menggunakan fungsi `strcmp` untuk membandingkan argumen dengan input di dalam pengondisian. Untuk argumen `-z` akan menggunakan perintah `killall -9 ./soal3` (sama dengan [soal.3d](#3d "Goto 3d")) dan argumen `-x` akan menggunakan perintah `kill getpid()` untuk `kill` Process ID yang dimiliki program utama.
  ```C
  if (strcmp(argv[1], "-z") == 0) {
      char *inputan = ""
      "#!/bin/bash\n"
      "killall -9 ./soal3\n"
      "rm $0\n";
      fprintf(killer_prog, inputan, sid);
  }

  else if (strcmp(argv[1], "-x") == 0) {
      char *inputan = ""
      "#!/bin/bash\n"
      "kill %d\n"
      "rm $0\n";
      fprintf(killer_prog, inputan, getpid());
  }
  ```
  Masing-masing mode akan di-<i>write</i> pada `killer_prog` dengan input yang telah dimasukkan melalui terminal. Terakhir, program <i>Killer.sh</i> akan di-<i>bash</i> dan me-<i>remove</i> dirinya sendiri.
