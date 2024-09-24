#pragma once
#include <stdarg.h>
#include <ctime>
#include "Safety.h"
class QAnswer {
public:
	char* answer;
	QAnswer(const char* text);
	QAnswer();
	~QAnswer();
	void set_correct(char* text);
	void operator = (char* text);
};

class Question {
public:
	QAnswer answers[5];
	int num_answers;
	int right;
	const char* question;
	Question(const char * c_question, int c_num_anwers, int c_right, ...);
	void run(int* num_right);
	bool is_right(char* guess);
	bool is_right_number(int guess);
	void arbitrary_answer(int num_sentences, int* num_right);
	void ask();
};
