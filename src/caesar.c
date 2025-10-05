#include <ctype.h>
void c_encrypt(char message[], int shift) {

  for (int i = 0; message[i] != '\0'; i++) {

    char ch = message[i];

    if (isalpha(ch)) {
      if (isupper(ch)) {
        ch = ((ch - 'A' + shift) % 26) + 'A';
      } else {
        ch = ((ch - 'a' + shift) % 26) + 'a';
      }
    }
    message[i] = ch;
  }
}

void c_decrypt(char message[], int shift) {
  for (int i = 0; message[i] != '\0'; i++) {

    char ch = message[i];

    if (isalpha(ch)) {
      if (isupper(ch)) {
        ch = ((ch - 'A' - shift) % 26) + 'A';
      } else {
        ch = ((ch - 'a' - shift) % 26) + 'a';
      }
    }
    message[i] = ch;
  }
}