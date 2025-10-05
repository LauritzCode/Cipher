#include "caesar.h"
#include "vigenere.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

  if (argc < 4) {
    printf("Usage:\n");
    printf("  Caesar:   %s caesar <encrypt|decrypt> <message> <shift>\n",
           argv[0]);
    printf("  Vigenere: %s vigenere <encrypt|decrypt> <message> <key>\n",
           argv[0]);
    return 1;
  }

  char *cipher = argv[1];
  char *mode = argv[2];
  char *message = argv[3];

  char buffer[200];

  strncpy(buffer, message, sizeof(buffer));
  buffer[sizeof(buffer) - 1] = '\0';

  if (strcmp(cipher, "caesar") == 0) {
    if (argc != 5) {
      printf("Please select all the parameters: <encrypt|decrypt> <message> "
             "<shift>");
      return 1;
    }

    int shift = atoi(argv[4]);

    if (strcmp(mode, "encrypt") == 0) {
      c_encrypt(buffer, shift);
      printf("Encrypted message from %s to %s.\n", message, buffer);
    } else if (strcmp(mode, "decrypt") == 0) {
      c_decrypt(buffer, shift);
      printf("Decrypted message from %s, to %s.\n", message, buffer);
    } else
      printf("Please select the appropriate mode.\n");
    return 1;
  } else if (strcmp(cipher, "vigenere") == 0) {
    if (argc != 5) {
      printf("Please select all the parameters: <encrypt|decrypt> <message> "
             "<key>\n");
      return 1;
    }
    char *key = argv[4];
    if (strcmp(mode, "encrypt") == 0) {

      v_encrypt(buffer, key);
      printf("Encrypted message from %s , to %s\n", message, buffer);
    } else if (strcmp(mode, "decrypt") == 0) {
      v_decrypt(buffer, key);
      printf("Decrypted message from %s , to %s\n", message, buffer);
    } else
      printf("Please select the appropriate parameters.");
    return 1;
  } else {
    printf("Invalid cipher.");
    return 1;
  }
}