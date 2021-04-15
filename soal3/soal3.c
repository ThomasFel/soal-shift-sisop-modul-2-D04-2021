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

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("ERROR! Argumen salah!\n");
        return 1;
    }

    if (strcmp(argv[1], "-z") != 0 && strcmp(argv[1], "-x") != 0) {
        printf("ERROR! Mode salah!\n");
        return 1;
    }

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

    FILE *killer_prog = fopen("killer.sh", "w");

    if (strcmp(argv[1], "-z") == 0) {
        char *inputan = ""
        "#!/bin/bash\n"
        "killall -9 ./soal3\n"
        "rm $0\n";
        fprintf(killer_prog, inputan, sid);
    }

    if (strcmp(argv[1], "-x") == 0) {
        char *inputan = ""
        "#!/bin/bash\n"
        "kill %d\n"
        "rm $0\n";
        fprintf(killer_prog, inputan, getpid());
    }

    fclose(killer_prog);

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    while (1) {
        time_t rawtime = time(NULL);
        struct tm *timeinfo;
        char buffer[80];

        timeinfo = localtime(&rawtime);
        strftime(buffer, 80, "%Y-%m-%d_%X", timeinfo);

        pid_t child_id;
        child_id = fork();

        if (child_id == 0) {
            char *argv[] = {"mkdir", buffer, NULL};
            execv("/bin/mkdir", argv);
        }

        child_id = fork();

        if (child_id == 0) {
            for (int i = 0; i < 10; i++) {
                child_id = fork();
                
                if (child_id == 0) {
                    char buffer2[80], location[160], link[80];
                    rawtime = time(NULL);

                    timeinfo = localtime(&rawtime);
                    strftime(buffer2, 80, "%Y-%m-%d_%X", timeinfo);

                    sprintf(location, "%s/%s", buffer, buffer2);
                    sprintf(link, "https://picsum.photos/%ld", ((rawtime % 1000) + 50));

                    char *argv[] = {"wget", "-q", "-O", location, link, NULL};
                    execv("/bin/wget", argv);
                }

                sleep(5);
            }
            
            while (wait(NULL) > 0);

            child_id = fork();

            if (child_id == 0) {
                char message[80] = "Download Success", file_name[160], temp;
                
                for (int j = 0; j < strlen(message); j++) {
                    temp = message[j];
                    
                    if (temp == ' ') {
                        continue;
                    }

                    if (temp >= 'a' && temp <= 'z') {
                        temp += 5;

                        if (temp > 'z') {
                            temp = temp - 'z' + 'a' - 1;
                        }

                        message[j] = temp;
                    }

                    else if (temp >= 'A' && temp <= 'Z') {
                        temp += 5;

                        if (temp > 'Z') {
                            temp = temp - 'Z' + 'A' - 1;
                        }

                        message[j] = temp;
                    }
                }
                
                sprintf(file_name, "%s/%s", buffer, "status.txt");
                FILE *txt = fopen(file_name, "w");

                fputs(message, txt);
                fclose(txt);

                sprintf(file_name, "%s.zip", buffer);
                
                char *argv[] = {"zip", "-r", file_name, buffer, NULL};
                execv("/bin/zip", argv);
            }
                while (wait(NULL) != child_id);
                
                char *argv[] = {"rm", "-r", buffer, NULL};
                execv("/bin/rm", argv);
            }
            
        sleep(40);
    }
}