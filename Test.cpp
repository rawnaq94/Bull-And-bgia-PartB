/**
 * A demo program for bull-pgia.
 * 
 * @author Erel Segal-Halevi
 * @since  2019-04
 */


#include <iostream>
using namespace std;

#include "play.hpp"
#include "DummyChoosers.hpp"
#include "DummyGuessers.hpp"
#include "SmartGuesser.hpp"
#include "badkan.hpp"
#define COMMA ,

using namespace bullpgia;

int main() {

	badkan::TestCase testcase;
	int grade=0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0) {

		// BASIC TESTS - DO NOT CHANGE
		ConstantChooser c1234{"1234"}, c12345{"12345"}, c9999{"9999"};
		ConstantGuesser g1234{"1234"}, g12345{"12345"}, g9999{"9999"};

		testcase.setname("Calculate bull and pgia")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","1234"), "4,0")         // 4 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1234","4321"), "0,4")        // 0 bull, 4 pgia
	        .CHECK_OUTPUT(calculateBullAndPgia("4","7654"), "0,1")          // 0 bull, 1 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("7777","77"), "2,0")        // 2 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("100","1"), "1,0")         // 1 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("10","10"), "2,0")        // 2 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("7","60"), "0,0")        // 0 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("111","111"), "3,0")    // 3 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("01","10"), "0,2")     // 0 bull, 2 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("123","137"), "1,1")  // 1 bull, 1 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("55","65"), "1,0")   // 1 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("5","0"), "0,0")    // 0 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("123456789","987654321"), "1,8")   // 1 bull, 8 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("156","615"), "0,3")              // 0 bull, 3 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("12","21"), "0,2")	            // 0 bull, 2 pgia
		;

		testcase.setname("Play with dummy choosers and guessers")
		.CHECK_EQUAL(play(c1234, g1234, 4, 100), 1)                  // guesser wins in one turn.
		.CHECK_EQUAL(play(c1234, g9999, 4, 100), 101)               // guesser loses by running out of turns .
		.CHECK_EQUAL(play(c1234, g12345, 4, 100), 101)             // guesser loses technically by making an illegal guess (too long).
		.CHECK_EQUAL(play(c12345, g1234, 4, 100), 0)              // chooser loses technically by choosing an illegal number (too long).	
		.CHECK_EQUAL(play(c1234, g9999, 4, 57), 58)            // guesser loses by running out of turns.	
	        ;

		testcase.setname("Play with smart guesser");
		RandomChooser randy;
		SmartGuesser smarty;
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(randy, smarty, 4, 100)<=100, true);  // smarty should always win in at most 10 turns!
		}
		
		
		RandomChooser randy1;
		SmartGuesser smarty1;
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(randy1, smarty1, 4, 100)>100, false);  // smarty should always win in at most 100 turns!
		}
				

    grade = testcase.grade();
	} else {
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: "  << grade << endl;
	return 0;
}

