#include <stdio.h>
#include <sys/wait.h>
#include<sys/types.h>
#include <unistd.h>
#include<string.h>
int main(void){
    char command[BUFSIZ];
    int st;
    pid_t pid;

for(;;)
{
    printf("enter the command: ");
if(fgets(command,sizeof(command),stdin)==NULL){
    printf("\n");
    return 0;
}

command[strlen(command)-1]='\0';
if (pid=fork()==0)
if(command != NULL){
execlp(command,command,0);
continue;
}
while(wait(&st)!=pid)
continue;
 
printf("\n");
}
}
