#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<wait.h>


int main()
{
    pid_t child_id;
    pid_t child_id_2;
    pid_t child_id_3;
    pid_t child_id_4;
    pid_t child_id_5;
    pid_t child_id_6;
    int status;

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
        }
    }
}

