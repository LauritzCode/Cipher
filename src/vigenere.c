#include <ctype.h>
#include <string.h>

void v_encrypt(char message[], const char key[]) {
  int key_len = strlen(key);

  for (int i = 0, j = 0; message[i] != '\0'; i++) {
    char ch = message[i];
    if (isalpha(ch)) {
      int shift = tolower(key[j % key_len] - 'a');
      if (isupper(ch)) {
        ch = ((ch - 'A' + shift) % 26) + 'A';
      } else {
        ch = ((ch - 'a' + shift) % 26) + 'a';
      }
      j++;
    }
    message[i] = ch;
  }
}

void v_decrypt(char message[], const char key[]) {
  int key_len = strlen(key);

  for (int i = 0, j = 0; message[i] != '\0'; i++) {

    int shift = tolower(key[j % key_len] - 'a');
    char ch = message[i];

    if (isalpha(ch)) {
      if (isupper(ch)) {
        ch = ((ch - 'A' - shift) % 26) + 'A';
      } else
        ch = ((ch - 'a' - shift) % 26) + 'a';
      j++;
    }
    message[i] = ch;
  }
}