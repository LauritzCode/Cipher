Cipher project:
My approach was to divide the program into clear and separate parts so each handled one specific task.

Starting with the CLI, I made sure it was only responsible for reading and validating the command-line arguments, deciding which cipher to use, and calling the correct function.
Therefore it doesnt handle any encryption itself, only the overall control flow.

For the Caesar cipher, I placed all the encryption and decryption logic in its own source file and declared the functions in a header file inside the include folder.
This is for the purpose of keeping this function reusable across the project. Same principle applies to the vigenere cipher.
This makes both ciphers independent and allows the main program to switch between them without any internal changes to their implementation.

An example of running the command:

.\cipher.exe caesar encrypt helloworld 3

Expected output: Encrypted message from helloworld to khoorzruog.

cipher type = caesar. Mode = encrypt. Message = helloworld. Shift = 3.

Options of running: Pick either caesar or vigenere. Thereafter pick either encrypt or decrypt, followed by the message and shift(caesar) or key(vigenere). 
