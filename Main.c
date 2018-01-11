#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

int main()
{
  while (1)
  {
    char cmd[255];
    char **arguments = (char**) malloc(sizeof(char*));
    int i = 1;
    int ac = 0;
    int c = 0;
    char program[255];
    signal(SIGINT,SIG_IGN);
    printf ("Enter the command> ");
    while ((c != '\n' && c != EOF) && (scanf("%s", cmd)))
    {
      /*printf ("%s\n", cmd);*/
      if (!ac)
      {
        ac = 1;
        *arguments = cmd;
        strcpy(program, cmd);
      } else
      {
        *(arguments + i) = cmd;
        i++;
      }
      c = getchar();
    }
    if (c == EOF)
    {
      printf ("Termination!\n");
      exit(0);
    }
    *(arguments + i) = NULL;
    pid_t pid = fork();
    if(pid==0)
    {

     if(execvp(program, arguments)!=0)
      {
      }
      exit(1);
    } 
    int k;
    wait(&k);
  }
}
