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
        char *argv[] = {"unzip", "/home/thomasfelix/modul2/pets.zip", "*;*", "-d", "/home/thomasfelix/modul2/petshop", NULL};
        execv("/bin/unzip", argv);
    }
 
    while (wait(NULL) > 0);
 
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
        }
    }
    
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
            }
 
            child_id4 = fork();
 
            if (child_id4 == 0) {
                char origin[450], goal[450];
                
                sprintf(origin, "/home/thomasfelix/modul2/petshop/%s", direntp3->d_name);
                sprintf(goal, "/home/thomasfelix/modul2/petshop/%s/%s", jenis, nama);
 
                char *argv[] = {"cp", "-r", origin, goal, NULL};
                execv("/bin/cp", argv);
            }
 
            while (wait(NULL) > 0);
 
            char keterangan[250];
            sprintf(keterangan, "/home/thomasfelix/modul2/petshop/%s/%s", jenis, "keterangan.txt");
            FILE *txt = fopen(keterangan, "a+");
 
            fprintf(txt, "nama : %s\n", nama);
            fprintf(txt, "umur : %s tahun\n\n", umur);
 
            fclose(txt);
            
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
 
                char keterangan[250];
                sprintf(keterangan, "/home/thomasfelix/modul2/petshop/%s/%s", jenis2, "keterangan.txt");
                FILE *txt = fopen(keterangan, "a+");
 
                fprintf(txt, "nama : %s\n", nama2);
                fprintf(txt, "umur : %s tahun\n\n", umur2);
 
                fclose(txt);
            }
 
            child_id6 = fork();
 
            if (child_id6 == 0) {
                char del[450];
 
                sprintf(del, "/home/thomasfelix/modul2/petshop/%s", direntp3->d_name);
                
                char *argv[] = {"rm", "-r", del, NULL};
                execv("/bin/rm", argv);
            }
 
            while (wait(NULL) > 0);
        }
    }
}
