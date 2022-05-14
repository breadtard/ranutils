#include <stdio.h>
#include <unistd.h> // crypt()
#include <string.h> // strcat(), strncpy()
#include <stdlib.h> // calloc()

char *tripcode(char *code) {

	char *saltprep = calloc(255, sizeof(char));
	strcat(saltprep, code);
	strcat(saltprep, "H..");

	// Get the second and third chars of the saltprep to use as salt
	char *salt = calloc(2, sizeof(char));
	strncpy(salt, saltprep + 1, 2);

	// Replace certain characters in the salt with a corresponding letter
	static char saltreplacefrom[13] = ":;<=>?@[\\]^_`";
	static char saltreplaceto[13] = "ABCDEFGabcdef";

	for (char replacex = 0; replacex < 13; replacex++) {
		if (salt[0] == saltreplacefrom[replacex]) {
			salt[0] = saltreplaceto[replacex];
		}
		if (salt[1] == saltreplacefrom[replacex]) {
			salt[1] = saltreplaceto[replacex];
		}
	}

	char *crypted = crypt(code, salt);
	// Get the last ten characters of the crypted code
	char *crypted_trimmed = calloc(10, sizeof(char));
	strncpy(crypted_trimmed, crypted + 3, 10);

	// Return
	return crypted_trimmed; 
}

int main (int argc, const char* argv[]) {
	if (argc > 1) {
		for (int x = 1; x < argc; x++) {
			char *tripped = tripcode(argv[x]);
			printf("%s: %s\n", argv[x], tripped);
        }
    }
	return 0;
}

