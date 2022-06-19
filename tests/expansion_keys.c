#include "tests.h"
#include <string.h>
#include <stdio.h>

// The expanded key is very long so we use two chars to represent each byte and
// it's much easier to just take each byte and then compare the strings
typedef struct test_input_output
{
  aes_128_key input_key;
  const char *output_round_keys;
} test_input_output;

static test_input_output test_data_1
  = {{
       0x00,
       0x00,
       0x00,
       0x00,
       0x00,
       0x00,
       0x00,
       0x00,
       0x00,
       0x00,
       0x00,
       0x00,
       0x00,
       0x00,
       0x00,
       0x00,
     },
     "00000000000000000000000000000000626363636263636362636363626363639b9898c9"
     "f9fbfbaa9b9898c9f9fbfbaa90973450696ccffaf2f457330b0fac99ee06da7b876a1581"
     "759e42b27e91ee2b7f2e2b88f8443e098dda7cbbf34b9290ec614b851425758c99ff0937"
     "6ab49ba7217517873550620bacaf6b3cc61bf09b0ef903333ba9613897060a04511dfa9f"
     "b1d4d8e28a7db9da1d7bb3de4c664941b4ef5bcb3e92e21123e951cf6f8f188e"};

uint32_t test_expansion_key(aes_working_buffer *buff, uint32_t i)
{
  if(i > 0)
    return 0;
  printf("\t Testing expansion key %d", i);

  memcpy(buff->encryption_key, &test_data_1.input_key,
         sizeof(test_data_1.input_key));
  buff->encryption_key_size = sizeof(test_data_1.input_key);
  aes_init_round_keys(buff);

  // Turn each byte into a string of length 2
  for(uint32_t i = 0; i < buff->encryption_key_size; i++)
    {
      char res[3];
      sprintf(res, "%#02hx", *(buff->round_keys->x + i));
      res[2] = '\0';

      char expected[3];
      memcpy(expected, test_data_1.output_round_keys + 2 * i, 2);
      expected[2] = '\0';

      if(strcmp(res, expected))
        {
          printf("\tFailed : %s didn't match expected %s\n", res, expected);
          return 1;
        }
    }
  printf("\t Success\n");
  return 0;
}
