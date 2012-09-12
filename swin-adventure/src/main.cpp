#include <stdio.h>
#include <stdlib.h>
#include "config.h"
 
int main (int argc, char *argv[])
{
  fprintf(stdout,"%s Version %d.%d\n",
            argv[0],
            SWINADVENTURE_VERSION_MAJOR,
            SWINADVENTURE_VERSION_MINOR);
  return 0;
}