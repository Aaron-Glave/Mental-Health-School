#include <stdio.h>
#include <string.h>
#include <stdlib.h>
bool read_line(char* line, int max_length) {
	fgets(line, max_length, stdin);
	if (line[strlen(line) - 1] == '\n') {
		line[strlen(line) - 1] = '\0';
		return true;
	}
	return false;
}
bool read_csv(char* store, FILE *csv_file, int max_length) {
	fgets(store, max_length, csv_file);
	if (store[strlen(store) - 1] == '\n') {
		store[strlen(store) - 1] = '\0';
		return true;
	}
	return false;
}