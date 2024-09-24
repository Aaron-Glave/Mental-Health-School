#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <time.h>
#include <string.h>
#include "..\Safety.h"
#include "Quizzer.h"
#include "..\Line_with_spaces.h"
//#define _CRT_SECURE_NO_WARNINGS prevents warnings for using non-Microsoft functions
#pragma warning(disable:4996)

QAnswer::QAnswer(const char* text) {
	answer = new char[strlen(text) + 1];
	strcpy(answer, text);
	printf("%s\n", answer);
}
QAnswer::QAnswer() {
	answer = NULL;
}

void QAnswer::set_correct(char* text) {
	if (answer == NULL) {
		size_t size = strlen(text);
		answer = new(char[size + 1]);
		strcpy(answer, text);
	}
}

void QAnswer::operator = (char* text) {
	set_correct(text);
}
QAnswer::~QAnswer() {
if (answer != NULL) delete[] answer;
}

Question::Question(const char *c_question, int c_num_answers, int c_right, ...) {
	num_answers = c_num_answers;
	right = c_right;
	question = c_question;
	va_list quiz;
	va_start(quiz, c_num_answers);
	for (int answer = 0; answer < num_answers && answer < 5; answer++) {
		answers[answer] = va_arg(quiz, char*);
	}
	va_end(quiz);
}

void Question::ask() {
	printf("%s\n", question);
}

//When you call this, the first answer is the whole list of possible answers.
//It should be the 4th arg to the constructor.
void Question::arbitrary_answer(int num_sentences, int *num_right) {
	ask();
	char answer[1000];

	if (!read_line(answer, sizeof(answer)-1)) {
		clearinput();
	}
	int num_sentcences_entered = 0;
	for (int i = 0; i < strlen(answer); i++) {
		if (answer[i] == '.' || answer[i] == '!') {
			num_sentcences_entered++;
		}
	}
	if (num_sentcences_entered >= num_sentences) {
		(*num_right)++;
	}
	printf("%s\n", answers[0].answer);
}

void Question::run(int *num_right) {
	char guess[100];
	int seconds = 0;
	time_t Start;
	time_t Now;
	Start = clock();
	Now = clock();
	ask();
	for (int i = 0; i < num_answers; i++) {
		printf("%d: %s\n", i + 1, answers[i].answer);
	}
	bool end_of_line = false;
	end_of_line = read_line(guess);
	if (end_of_line == false) {
		clearinput();
	}
	Now = clock();
	seconds = (int)((Now - Start) / CLOCKS_PER_SEC);
	printf("%d Seconds\n", seconds);
	bool correct = false;
	if (seconds < 100) {
		if (is_right(guess)) {
			correct = true;
		}
		size_t length = strlen(guess);
		bool is_int = true;
		for (size_t i = 0; i < length; i++) {
			if (!(guess[i] >= '0' && guess[i] <= '9')) {
				is_int = false;
				break;
			}
		}
		if (is_int) {
			if (right == atoi(guess)) correct = true;
		}
		if (correct) {
			printf("Correct!\n");
			(*num_right)++;
		}
		else {
			printf("Wrong. The correct answer is %s\n", answers[right - 1].answer);
			return;
		}
	}
	else {
		printf("Too late. The correct answer is %s\n", answers[right - 1].answer);
		return;
	}
}
bool Question::is_right(char* guess) {
	if (strcmp(guess, answers[right - 1].answer) == 0) return true;
	return false;
}
bool Question::is_right_number(int guess) {
	return guess == right;
}

//I accept the ...s to be Questions
/*
int runquiz(int num_qs, ...) {
	Question* current;
	va_list quiz;
	va_start(quiz, num_qs);
	for (int i = 0; i < num_qs; i++) {
		current = va_arg(quiz, Question*);
		if (current != NULL) {
			current->run();
		}
	}
	
	_sleep(2000);
	return 0;
}
*/