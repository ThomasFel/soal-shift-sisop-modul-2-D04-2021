#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <dirent.h>
#include <time.h>
#include <wait.h>
 
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
 
  if ((chdir("/home/fiodhy/Sisop/Praktikum/Modul2")) < 0) {
    exit(EXIT_FAILURE);
  }
 
  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);
 
  while (1) {
    time_t jadwal = time(NULL);
    struct tm *waktu = localtime(&jadwal);
    int status;
    if(waktu->tm_mon == 3 && waktu->tm_mday == 9 && waktu->tm_hour == 16 && waktu->tm_min == 22 && waktu->tm_sec == 0 )
    {
        pid_t child_id;
        pid_t child_id_2;
        pid_t child_id_3;
        pid_t child_id_4;
        pid_t child_id_5;
        pid_t child_id_6;
        pid_t child_id_7;
        pid_t child_id_8;
        pid_t child_id_9;
        pid_t child_id_10;
        pid_t child_id_11;
        pid_t child_id_12;
    
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
                else
                {
                    //unzip Foto
                    while((wait(&status)) > 0);
                    char *argv[] = {"unzip","-oq","Foto_for_Stevany.zip",NULL};
                    execv("/usr/bin/unzip",argv);
                }
            }
            else
            {
                while((wait(&status)) > 0);
                child_id_4 = fork();
                if(child_id_4 < 0)
                {
                    exit(EXIT_FAILURE);
                }
                if(child_id_4 == 0)
                {
                    child_id_5 = fork();
                    if(child_id_5 < 0)
                    {
                        exit(EXIT_FAILURE);
                    }
                    if(child_id_5 == 0)
                    {
                        //Download Musik
                        char *argv[] = {"wget","-q","--no-check-certificate","https://drive.google.com/uc?id=1ZG8nRBRPquhYXq_sISdsVcXx5VdEgi-J&export=download","-O","Musik_for_Stevany.zip",NULL};
                        execv("/usr/bin/wget",argv);
                    }
                    else
                    {
                        //Unzip Musik
                        while((wait(&status)) > 0);
                        char *argv[] = {"unzip","-oq","Musik_for_Stevany",NULL};
                        execv("/usr/bin/unzip",argv);
                    }
                }
                else
                {
                    while((wait(&status)) > 0);
                    child_id_6 = fork();
                    if(child_id_6 < 0)
                    {
                        exit(EXIT_FAILURE);
                    }
                    if(child_id_6 == 0)
                    {
                        child_id_7 = fork();
                        if(child_id_7 < 0)
                        {
                            exit(EXIT_FAILURE);
                        }
                        if(child_id_7 == 0)
                        {
                            //Download Film
                            char *argv[] = {"wget","-q","--no-check-certificate","https://drive.google.com/uc?id=1ktjGgDkL0nNpY-vT7rT7O6ZI47Ke9xcp&export=download","-O","Film_for_Stevany.zip",NULL};
                            execv("/usr/bin/wget",argv);
                        }
                        else
                        {
                            //Unzip Film
                            while((wait(&status)) > 0);
                            char *argv[] = {"unzip","-oq","Film_for_Stevany",NULL};
                            execv("/usr/bin/unzip",argv);   
                        }
                    }
                    else
                    {
                        while((wait(&status)) > 0);
                        child_id_8 = fork();
                        if(child_id_8 < 0)
                        {
                            exit(EXIT_FAILURE);
                        }
                        if(child_id_8 == 0)
                        {
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
                _exit(1);
                        }
                        else
                        {
                            while((wait(&status)) > 0);
                            child_id_10 = fork();
                            if(child_id_10 < 0)
                            {
                                exit(EXIT_FAILURE);
                            }
                            if(child_id_10 == 0)
                            {
                                DIR *folder;
                                struct dirent *file;
                                chdir("./MUSIK/");
                                folder = opendir(".");
                                if(folder)
                                {
                                    while((file = readdir(folder)) != NULL)
                                    {
                                        child_id_11 = fork();
                                        if(child_id_11 == 0)
                                        {   
                                            char *argv[] = {"mv", file->d_name, "../Musyik/", NULL};
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
                _exit(1);
                            }
                            else
                            {
                                while((wait(&status)) > 0);
                                DIR *folder;
                                struct dirent *file;
                                chdir("./FILM/");
                                folder = opendir(".");
                                if(folder)
                                {
                                    while((file = readdir(folder)) != NULL)
                                    {
                                        child_id_12 = fork();
                                        if(child_id_12 == 0)
                                        {
                                            char *argv[] = {"mv", file->d_name, "../Fylm/", NULL};
                                            execv("/bin/mv",argv);
                                        }
                                        else
                                        {
                                            while((wait(&status)) > 0);
                                        }
                                    }
                                    closedir(folder);
                                }
                				_exit(1);
                            }
                        }
                    }
                }
            }
        }   
    }
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
    sleep(1);
  }
}
