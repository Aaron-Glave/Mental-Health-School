#include "Quizzer.h"
#include "..\Line_with_spaces.h"
#include "stdio.h"
#include <iostream>


int main(int argc, char *argv[]) {
	int num_right = 0;
	int num_questions = 5;
	Question Colors_q_I_made = Question("What affects your sight?", 4, 3,
		"Just Light",
		"Which colors I can see",
		"Light AND colors",
		"None Of the above");
	Question brain_study = Question(
		"Which of these is NOT one of the main 3 reasons to study the brain?", 4, 4,
		"To understand identities",
		"To improve artificial intelligence",
		"To understand human knowledge",
		"To explore the past");
	Question humans_are_better = Question("Humans are better than machines than what?", 4, 1,
		"Pattern recognition",
		"Voice detection",
		"Artificial intelligence",
		"Staying the same");
	Question story = Question("Describe at least TWO methods that might be used to study brain 'machinery' in neuropsychology patients", 1, 1,
		"There are several methods that might be used to understand brain ‘machinery’ and understand certain functions.\n"
		"Neuropsychology patients may be used as subjects in different types of brain studies.\n"
		"These can include functional MRI (fMRI), neurophysiology studies, EEG, magnetoencephalography, and diffusion tractography.");
	Question bold = Question("In the acronym BOLD, the ‘B’ stands for....", 4, 3, "Bilirubin", "Bladder", "Blood", "Binding");
	
	Colors_q_I_made.run(&num_right);
	brain_study.run(&num_right);
	humans_are_better.run(&num_right);
	story.arbitrary_answer(2, &num_right);
	bold.run(&num_right);
	printf("You got %d of %d questions right.\nThat's %d%%.\n", num_right, num_questions, (int)(100*(float)(num_right)/(float)num_questions));
	if (num_right == num_questions) printf("Perfect score!\n");
	
}
