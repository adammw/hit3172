#include <stdio.h>
#include <stdlib.h>
#include "config.h"

#include "Identifiable.h"
 
using namespace swinadventure;

int main (int argc, char *argv[])
{
  fprintf(stdout,"%s Version %d.%d\n",
            argv[0],
            SWINADVENTURE_VERSION_MAJOR,
            SWINADVENTURE_VERSION_MINOR);

  std::string idents[2] = {"gem", "ruby"};
  Identifiable* identObj = new Identifiable(idents, 2);

  return 0;
}
