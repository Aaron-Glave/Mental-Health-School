#include "Quizzer.h"
#include "..\Line_with_spaces.h"
#include "stdio.h"
#include <iostream>


int main(int argc, char* argv[]) {
	int num_right = 0;
	int num_questions = 6;
	Question Object_recocnition = Question("What factor might affect if object recognition is left intact when someone has prosopagnosia?", 4, 3,
		"Lesion shape",
		"Age",
		"Lesion size",
		"Gender");
	Question cognitive_neuroscience = Question(
		"Short Answer: Behavioral methods and fMRI are both methods used in cognitive neuroscience. "
		"Pick ONE of these and describe its advantages AND disadvantages", 1, 1,
		"Behavioral methods in cognitive neuroscience have strengths as well as weaknesses.\n"
		"Several strengths of behavioral methods include the ability to characterize internal representations qualitatively, being able to dissociate distinct mental phenomena, and the fact that these methods are cheap.\n"
		"Weaknesses of these methods include not having information or a relationship to the brain, as well as sparse data.\n"
		"Use of fMRI in cognitive neuroscience has advantages and disadvantages.\n"
		"The advantages of fMRI include the fact that it is noninvasive as well as it has the best spatial resolution available for studies.\n"
		"Some disadvantage of fMRI include reduced clarity on causal relationships, unclear bases of activity, higher price, and loud noises with machine use.");
	Question ERPs = Question("True / False (choose ONE): Event Related Potentials, or ERPs, typically detect stimuli slowly.", 2, 2,
		"True",
		"False");
	Question fuiform_face_area = Question("There is evidence that patients missing the fusiform face area cannot recognize faces, but can still recognize what?", 4, 2,
		"Animals",
		"Objects",
		"Scenes",
		"Emotion");
	Question opposie_syndrome = Question("What occurs in the 'opposite syndrome'?", 4, 3,
		"People can recongnize opposites but not similarities.",
		"People can recongnize objects but not faces.",
		"People can recognize faces but not objects.",
		//"People can’t focus on a face and object at the same time.​"
		"People can't focus on a face and object at the same time.");
	Question loud_noises = Question(
		//"If a person is uncomfortable with loud noises, which of these would NOT be a good choice for a test to study their brain activity?​
		"If a person is uncomfortable with loud noises, which of these would NOT be a good choich for a test to studay their brain activity?", 4, 4,
		"Behavioral",
		//"Electroencephalography​",
		"Electroencephalography",
		"Magnetoencephalography",
		"fMRI");

	Object_recocnition.run(&num_right);
	cognitive_neuroscience.arbitrary_answer(2, &num_right);
	ERPs.run(&num_right);
	fuiform_face_area.run(&num_right);
	opposie_syndrome.run(&num_right);
	loud_noises.run(&num_right);
	printf("You got %d of %d questions right.\nThat's %d%%.\n", num_right, num_questions, (int)(100 * (float)(num_right) / (float)num_questions));
	if (num_right == num_questions) printf("Perfect score!\n");
}