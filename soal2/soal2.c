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
    pid_t child_id, child_id2;
    child_id = fork();

    if (child_id < 0) {
        exit(0);
    }

    if (child_id == 0) {
        char *argv[] = {"unzip", "/home/thomasfelix/modul2/pets.zip", "*;*", "-d", "/home/thomasfelix/modul2/petshop", NULL};
        execv("/bin/unzip", argv);
    }

    while (wait(NULL) > 0);

    DIR *dir = opendir("/home/thomasfelix/modul2/petshop");
    struct dirent *direntp;

    while((direntp = readdir(dir)) != NULL) {
        if ((direntp->d_type == DT_DIR) && strcmp(direntp->d_name, ".") != 0 && strcmp(direntp->d_name, "..") != 0) {
            child_id2 = fork();

            if (child_id2 < 0) {
                exit(0);
            }

            if (child_id2 == 0) {
                char folder_name[300];
                
                sprintf(folder_name, "/home/thomasfelix/modul2/petshop/%s", direntp->d_name);
                
                char *argv[] = {"rm", "-r", folder_name, NULL};
                execv("/bin/rm", argv);
            }
        }
    }
}
