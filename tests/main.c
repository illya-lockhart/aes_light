#include <stdio.h>

#include "aes_light.h"
#include "tests.h"

int main()
{
  // Build our working buffers for trying a bunch of different keys
  aes_working_buffer buff_1;
  aes_working_buffer buff_2;
  aes_working_buffer buff_3;
  aes_working_buffer buff_4;
  aes_working_buffer buff_5;
  aes_working_buffer buff_6;

  aes_working_buffer *aes[6];
  aes[0] = &buff_1;
  aes[1] = &buff_2;
  aes[2] = &buff_3;
  aes[3] = &buff_4;
  aes[4] = &buff_5;
  aes[5] = &buff_6;

  printf("Running Aes Tests\n");
  printf(" * Aes key expansion testing\n");

  uint32_t err = 0;
  for(uint32_t i = 0; i < 6; i++)
    {
      err += test_expansion_key(aes[i], i);
    }
  if(err != 0)
    {
      printf(" * Failed expansion key tests\n");
      return -1;
    }
}
