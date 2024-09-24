#pragma once
#include <stdlib.h>
#include <stdio.h>
bool read_line(char* line, int max_length = 100);
bool read_csv(char* store, FILE* csv_file, int max_length);