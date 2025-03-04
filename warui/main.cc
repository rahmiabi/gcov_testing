#include <iostream>
#include <vector>
using namespace std;


// Function that will print "BAD INPUT" or whatever a user inputs as an error message
// then quits. Use this when checking input!
void die(const string &s = "BAD INPUT!") {
	cout << s << endl;
	exit(EXIT_FAILURE);
}

int main() {

	//If they want to translate a number below MIN or above MAX, die();
	const int MIN = 0;
	const int MAX = 1'009'999; // This is the highest number we can translate

	// Individual Digits        0       1      2      3      4     5      6       7        8       9
	vector<string> digits = { "ZERO", "ICHI", "NI", "SAN", "YON", "GO", "ROKU", "NANA", "HACHI", "KYUU" };
	// Powers of 10		        0        1       2      3
	vector<string> powers = { "JYUU", "HYAKU", "SEN", "MAN" };

	int start = 0;
	int end = 0;
	int step = 0;


	cout << "Please enter a number to start with: " << endl;
	cin >> start;
	if (!cin or start < MIN or start > MAX) {
		cout << "BAD INPUT!" << endl;
		return 1;
	}

	cout << "Please enter a number to end with: " << endl;
	cin >> end;
	if (!cin or end > MAX or end < start) {
		cout << "BAD INPUT!" << endl;
		return 1;
	}

	cout << "Please enter your step size: " << endl;
	cin >> step;
	if (!cin or step <= 0) {
		cout << "BAD INPUT!" << endl;;
		return 1;
	}

	if (!cin or step == 0 or start < MIN or end > MAX) {
		cout << "INPUT ERROR" << endl;
		return 1;
	}
	for (int i = start; i <= end; i += step) {
		/*
		string numbers;
		numbers.push_back(i);
		cout <(< numbers << endl;
		*/

		// make a while loop that gets each number and stores it in a string, then cout that string number, can get the size of it easy with string size.
		// while loopif (x < end) then % by 10 and then / it by 10
		// easy-peasy


		/*

				if (i < 10) {
					cout << i << digits.at(i) << endl;
					continue;
				} else if (i % 10 == 0) { //and !(i % 100 == 0)) {
					cout << i << powers.at(i % 10) << endl;
				} else if (i <= 19) {
					cout << i << powers.at(0) << " " << digits.at(i % 10) << endl;
				} else if (i % 10 == 0 and i % 100 == 0) {
					cout << i << digits.at(i % 10) << " " << powers.at(i / 10 and i % 10);
				} else if (!(i % 10 == 0 and i % 100 == 0) and !(i / 10 == 0 or i / 10 == 1)
					cout << i << powers.at(i / 100) << " " << digits.at(i / 100) << " " << powers.at(i / 100 - 1) << endl;
				else if (i / 100 and !(i % 100 == 0))
					cout << i << powers.at(i / 100) << " " << endl;
				else if (!(i % 10 == 0) and (i / 100) and !(i % 100 == 0) and !(i == i / 10 or i == 110)) {
					cout << i << digits.at(i % 10) << endl;
				}
			}

		*/


		if (i < 10) {
			cout << i << " " << digits.at(i) << endl;
		} else if (i == 10) {
			cout << i << " " << powers.at(0) << endl;
		} else if (i > 10 and i < 20) {
			cout /* << digits.at(i / 10) << " " */		 << i << " " << powers.at(0) << " " << digits.at(i % 10) << endl;
		} else if (i % 10 == 0 and i < 100) {
			/*((i / 10 and !i % 10) or i == 20)
			(i == 20 or i == 30 or i == 40 or i == 50 or i == 60 or i == 70 or i == 80 or i == 90)*/  // checks if its a ten's digit and outputs just the number of tens, ni jyuu or san jyuu
			cout  << i << " " << digits.at(i / 10) << " " << powers.at(0) /* << digits.at(i / 10) */		 << endl;
		} else if (i > 20 and i < 100) {
			cout  << i << " " <<  digits.at(i / 10) << " "  << powers.at(0) << " " << digits.at(i % 10) << endl;
			//100's



			//
		} else if (i == 100) {
			cout << i << " " << powers.at(1) << endl;// end of 100's
		}  else if (i == 300) {
			cout << i << " " << digits.at(3) << " " << "BYAKU" << endl;
		}  else if (i % 100 % 10 == 0 and i > 299 and i < 400) {
			cout << i << " " << digits.at(3) << " " << "BYAKU" << " " << digits.at(i  / 10 % 10) << " " << powers.at(i / 1000 % 10) << endl;
		}  else if (i == 600) {
			cout << i << " " << "ROPPYAKU" << endl;
		}  else if (i % 100 % 10 == 0 and i > 599 and i < 700) {
			cout << i << " " << "ROPPYAKU" << " " << digits.at(i  / 10 % 10) << " " << powers.at(i / 1000 % 10) << endl;
		}  else if (i == 800) {
			cout << i << " "  << "HAPPYAKU" << endl;
		}  else if (i % 100 % 10 == 0 and i > 799 and i < 900) {
			cout << i << " " << "HAPPYAKU" << " " << digits.at(i  / 10 % 10) << " " << powers.at(i / 1000 % 10) << endl;
		}  else if (i == 8600) {
			cout << i << " "  << "HASSEN" << " " << "ROPPYAKU" << endl;
		}  else if (i == 8610) {
			cout << i << " "  << "HASSEN" << " " << "ROPPYAKU" << " " << powers.at(0) << endl;
		}  else if (i % 100 % 10 == 0 and i > 8599 and i < 8700) {
			cout << i << " " << "HASSEN" << " " << "ROPPYAKU" << " " << digits.at(i / 10 % 10) << " " <<  powers.at(i / 10000 % 10) << endl;
		}  else if (i == 8800) {
			cout << i << " "  << "HASSEN" << " " << "HAPPYAKU" << endl;
		}  else if (i == 8810) {
			cout << i << " "  << "HASSEN" << " " << "HAPPYAKU" << " " << powers.at(0) << endl;
		}  else if (i % 100 % 10 == 0 and i > 8799 and i < 8900) {
			cout << i << " " << "HASSEN" << " " << "HAPPYAKU" << " " << digits.at(i / 10 % 10) << " " <<  powers.at(i / 10000 % 10) << endl;
		} else if (i % 100 == 0 and i < 1000 and i > 110 and !(i >= 300 and i < 400) and !(i >= 600 and i < 700) and !(i >= 800 and i < 900)) {
			cout << i << " " << digits.at(i / 100) << " " << powers.at(1) << endl;
		} else if (i % 100 % 10 == 0 and i < 1000 and i > 200 and !(i % 100 == 0)) {
			cout << i << " " << digits.at(i / 100) << " " << powers.at(1) << " " << digits.at(i / 10 % 10) <<  " " << powers.at(i / 1000 % 10) << endl; // handles 100 - 999 hundres only
		}  else if (i % 1000 < 11 and i > 7999 and i < 9000) {
			cout  << i << " "  << "HASSEN" << " " << digits.at(i / 100 % 10) << " " << powers.at(i / 100 % 10) << digits.at(i % 10) << endl;
		} else if (i % 1000 == 0 and i < 9000 and i > 7999) {
			cout << i << " " << "HASSEN" << endl;
		} else if (i % 1000 % 100 == 0 and i < 9000 and i > 7999) {
			cout << i << " " << "HASSEN" << " " << digits.at(i / 100 % 10) << " " << powers.at(1) << endl;
		} else if (i % 1000 % 100 % 10 == 0 and i < 9000 and i > 7999 and !(i % 100 == 0)) {
			cout << i << " " << "HASSEN" << " " << digits.at(i / 100 % 10) <<  " " << powers.at(1) << " " << powers.at(0) << endl; // handles 100 - 999 hundres only
		} else if (i % 1000 == 0 and i < 10000 and i > 1000) {
			cout << i << " " << digits.at(i / 1000) << " " << powers.at(2) << endl;
		} else if (i % 10000 % 1000 % 100 % 10 == 0 and i < 1000000 and i > 100000) {
			cout << i << " " << powers.at(0) << " " << powers.at(3) << " " << powers.at(0) << endl;

		}  else if (i > 8600 and i < 8620) {
			cout  << i << " "  << "HASSEN" << " " << "ROPPYAKU" << " " << powers.at(10000 % 10) << " " << digits.at(i % 10) << endl;
		}  else if (i > 8620 and i < 8700) {
			cout  << i << " "  << "HASSEN" << " " << "ROPPYAKU" << " " << digits.at(i / 10 % 10) << " " << powers.at(10000 % 10) << " " << digits.at(i % 10) << endl;
		}  else if (i > 8800 and i < 8820) {
			cout  << i << " "  << "HASSEN" << " " << "HAPPYAKU" << " " << powers.at(10000 % 10) << " " << digits.at(i % 10) << endl;
		}  else if (i > 8820 and i < 8900) {
			cout  << i << " "  << "HASSEN" << " " << "HAPPYAKU" << " " << digits.at(i / 10 % 10) << " " << powers.at(10000 % 10) << " " << digits.at(i % 10) << endl;
		}  else if (i > 8900 and i < 8920) {
			cout  << i << " "  << "HASSEN" << " " << digits.at(9) << " " << powers.at(1) << " " << digits.at(i % 10) << endl;
		}  else if (i > 8000 and i < 9000) {
			cout  << i << " "  << "HASSEN" << " " << digits.at(i / 100 % 10) << " " << powers.at(1) << " " << digits.at(i / 100 % 10) << " " << powers.at(1000 % 10) << " " << digits.at(i % 10) << endl;


//8000's

		} else if ((i % 1000 == 0 and i  % 100 == 0 or i % 1000 % 10) and i < 10000 and i > 1000) {
			cout << i << " " << digits.at(i / 1000) << " " << powers.at(2) << " " << digits.at(i / 100 % 10) <<  " " << powers.at(1) /*<< " " << digits.at(i / 10 % 10) << " " << powers.at(0)*/ << endl; // handles 100 - 999 hundres only
		} else if ((i % 1000 == 0 and i % 100 == 0 and i % 10 == 0 or i % 1000 % 10) and i < 10000 and i > 1000) {
			cout << i << " " << digits.at(i / 1000) << " " << powers.at(2) << " " << digits.at(i / 100 % 10) <<  " " << powers.at(1) << " " << digits.at(i / 10 % 10) << " " << powers.at(0) << endl; // handles 100 - 999 hundres only
		} else if ((i % 10000 == 0) and i < 100000 and i > 10000) {
			cout << i << " " << digits.at(i / 10000) << " " << powers.at(3) << endl;
		} else if ((i % 1000 % 100 == 0 or i % 1000 % 10 == 0) and i < 100000 and i > 10000) {
			cout << i << " " << digits.at(i / 10000) << " " << powers.at(3) << " " << digits.at(i / 1000 % 10) <<  " " << powers.at(2) << " " << digits.at(i / 100 % 10) << " " << powers.at(1) << " " << digits.at(i / 10 % 10) << " " << powers.at(0) << endl; // handles 100 - 999 hundres only
		} else if ((i % 1000 % 100 % 10 == 0 or i % 1000 % 10) and i < 100000 and i > 10000) {
			cout << i << " " << digits.at(i / 10000) << " " << powers.at(3) << " " << digits.at(i / 1000 % 10) <<  " " << powers.at(2) << " " << digits.at(i / 100 % 10) << " " << powers.at(1) << " " << digits.at(i / 10 % 10) << " " << powers.at(0) << " " << digits.at(i % 10) << endl; // handles 100 - 999 hundres only
			//
		} else if ((i % 100000 == 0) and i < 1000000 and i > 100000) {
			cout << i << " " << powers.at(0) << " " << powers.at(3) << endl;
		} else if ((i % 10000 % 1000 == 0 or i % 10000 % 100 == 0) and i < 100000 and i > 10000) {
			cout << i << " " << digits.at(i / 10000) << " " << powers.at(3) << " " << digits.at(i / 1000 % 10) <<  " " << powers.at(2) << " " << digits.at(i / 100 % 10) << " " << powers.at(1) << " " << digits.at(i / 10 % 10) << " " << powers.at(0) << endl; // handles 100 - 999 hundres only
		} else if ((i % 10000 % 1000 % 100 % 10 == 0 or i % 1000 % 10) and i < 100000 and i > 10000) {
			cout << i << " " << digits.at(i / 100000) << " " << powers.at(3) << " " << digits.at(i / 10000 % 10) <<  " " << powers.at(2) << " " << digits.at(i / 100 % 10) << " " << powers.at(1) << " " << digits.at(i / 10 % 10) << " " << powers.at(0) << " " << digits.at(i % 10) << endl; // handles 100 - 999 hundres only
		}
// space holder
		else if (i % 100 == 0 and i < 1000 and i > 100) {
			cout << i << " " << digits.at(i / 100) << " " << powers.at(1) << endl; // handles 1000 - 9999 hundres only
		} else if (i == 110) {
			cout << i << " " << powers.at(1) << " " << powers.at(i / 100 - 1) << endl;
		} else if (i == 100000) {
			cout << i << " " << powers.at(0) << " " << powers.at(3) << endl;
		} else if (i / 100 % 10 == 0 and i < 200 and !(i == 110)) {
			cout << i << " " << powers.at(1) << " " << digits.at(i / 10 % 10) << " " << powers.at(i / 100 - 1) << endl;
		}  else if (i > 100 and i < 110) {
			cout  << i << " "  << powers.at(1) << " " << digits.at(i % 10) << endl; //<< " " << powers.at(i / 100) << " " << digits.at(i % 100) << endl;
		}  else if (i > 110 and i < 120 and !(i % 10 == 0)) {
			cout  << i << " "  << powers.at(1) << " " << powers.at(0) << " " << digits.at(i % 10) << endl; //<< " " << powers.at(i / 100) << " " << digits.at(i % 100) << endl;

			cout << i << endl;
		}  else if (i > 120 and i < 200 and !(i % 10 == 0)) {
			cout  << i << " "  << powers.at(1) << " " << digits.at(i / 10 % 10) << " " << powers.at(i / 1000 % 10) << " " << digits.at(i % 10) << endl;
			//200's
			//	}  else if (i > 100 and i < 110) {
			//		cout  << i << " "  << powers.at(1) << " " << digits.at(i % 10) << endl; //<< " " << powers.at(i / 100) << " " << digits.at(i % 100) << endl;
			//	}  else if (i > 110 and i < 120 and !(i % 10 == 0)) {
			//		cout  << i << " "  << powers.at(1) << " " << powers.at(0) << " " << digits.at(i % 10) << endl; //<< " " << powers.at(i / 100) << " " << digits.at(i % 100) << endl;i
		}  else if (i > 300 and i < 400) {
			cout  << i << " "  << digits.at(i / 100 % 10) << " " << "BYAKU" << " " << digits.at(i / 10 % 10) << " " << powers.at(i / 1000 % 10) << " " << digits.at(i % 10) << endl;
		}  else if (i > 600 and i < 700) {
			cout  << i << " " << "ROPPYAKU" << " " << digits.at(i / 10 % 10) << " " << powers.at(i / 1000 % 10) << " " << digits.at(i % 10) << endl;
		}  else if (i > 800 and i < 900) {
			cout  << i << " " << "HAPPYAKU" << " " << digits.at(i / 10 % 10) << " " << powers.at(i / 1000 % 10) << " " << digits.at(i % 10) << endl;
		}  else if (i > 8600 and i < 8620) {
			cout  << i << " "  << "HASSEN" << " " << "ROPPYAKU" << " " << powers.at(10000 % 10) << " " << digits.at(i % 10) << endl;
		}  else if (i > 8620 and i < 8700) {
			cout  << i << " "  << "HASSEN" << " " << "ROPPYAKU" << " " << digits.at(i / 10 % 10) << " " << powers.at(10000 % 10) << " " << digits.at(i % 10) << endl;
		}  else if (i > 8800 and i < 8820) {
			cout  << i << " "  << "HASSEN" << " " << "HAPPYAKU" << " " << powers.at(10000 % 10) << " " << digits.at(i % 10) << endl;
		}  else if (i > 8820 and i < 8900) {
			cout  << i << " "  << "HASSEN" << " " << "HAPPYAKU" << " " << digits.at(i / 10 % 10) << " " << powers.at(10000 % 10) << " " << digits.at(i % 10) << endl;
		}  else if (i > 8900 and i < 8920) {
			cout  << i << " "  << "HASSEN" << " " << digits.at(9) << " " << powers.at(1) << " " << digits.at(i % 10) << endl;
		}  else if (i > 8000 and i < 9000) {
			cout  << i << " "  << "HASSEN" << " " << digits.at(i / 100 % 10) << " " << powers.at(1) << " " << digits.at(i / 100 % 10) << " " << powers.at(1000 % 10) << " " << digits.at(i % 10) << endl;

			//	}  else if (i > 200 and i < 220) {
			//		cout  << i << " "  << digits.at(i / 100 % 10) << " " << powers.at(1) << " " << digits.at(i / 10 % 10) << " " << powers.at(i / 1000 % 10) << " " << digits.at(i % 10) << endl;

		}  else if (i % 100 < 11 and i > 200 and i < 1000) {
			cout  << i << " "  << digits.at(i / 100 % 10) << " " << powers.at(1) << " " << powers.at(i / 1000 % 10) << " " << digits.at(i % 10) << endl;
		}  else if (i % 1000 < 11 and i > 1000 and i < 10000) {
			cout  << i << " "  << digits.at(i / 1000 % 10) << " " << powers.at(2) << " " << powers.at(i / 10000 % 10) << endl;
		}  else if (i % 10000 < 11 and i > 100000 and i < 100010) {
			cout  << i << " "  << powers.at(0) << " " << powers.at(3) << " " << digits.at(i % 10) << endl;
		}  else if (i % 10000 < 11 and i > 100000 and i < 100100) {
			cout  << i << " "  << powers.at(0) << " " << powers.at(3) << " " << digits.at(i / 10 % 10) << " " << powers.at(i / 10 % 10) << " " << digits.at(i % 10) << endl;

		}  else if (i > 220 and i < 1000) {
			cout  << i << " "  << digits.at(i / 100 % 10) << " " << powers.at(1) << " " << digits.at(i / 10 % 10) << " " << powers.at(i / 1000 % 10) << " " << digits.at(i % 10) << endl;
		}  else if (i > 1000 and i < 2000) {
			cout  << i << " "  << digits.at(i / 1000 % 10) << " " << powers.at(2) << " " << " " << powers.at(1) << " " << digits.at(i / 10 % 10) << " " << powers.at(10000 % 10) << " " << digits.at(i % 10) << endl;
		}  else if (i > 1000 and i < 10000) {
			cout  << i << " "  << digits.at(i / 1000 % 10) << " " << powers.at(2) << " " << digits.at(i / 100 % 10) << " " << powers.at(1) << " " << digits.at(i / 10 % 10) << " " << powers.at(10000 % 10) << " " << digits.at(i % 10) << endl;
		}  else if (i > 10000 and i < 100000) {
			cout  << i << " "  << digits.at(i / 10000 % 10) << " " << powers.at(3) << " " << digits.at(i / 1000 % 10) << " " << powers.at(2) << digits.at(i / 100 % 10) << " " << powers.at(1) << " " << digits.at(i / 10 % 10) << " " << powers.at(0) << " " << digits.at(i % 10) << endl;
		}  else if (i > 100000 and i < 1000000) {
			cout  << i << " "  << powers.at(0) << " " << powers.at(3) << " " << digits.at(i / 1000 % 10) << " " << powers.at(2) << digits.at(i / 100 % 10) << " " << powers.at(1) << " " << digits.at(i / 10 % 10) << " " << powers.at(0) << " " << digits.at(i % 10) << endl;
		}  else if (i > 100000 and i < 1000000) {
			cout  << i << " "  << powers.at(0) << " " << powers.at(3) << " " << digits.at(i / 1000 % 10) << " " << powers.at(2) << digits.at(i / 100 % 10) << " " << powers.at(1) << " " << digits.at(i / 10 % 10) << " " << powers.at(0) << " " << digits.at(i % 10) << endl;
		}



	}
}


// 		if (i / 1000) {
//		cout << i;
// 		}


// Prompt the user for the starting number and read it from cin
// Remember to vet their input

// Prompt the user for the ending number and read it from cin
// Remember to check for errors here too!

// Prompt the user with the step size and read it from cin
// Lots of errors here!


// Main part of the assignment:
// With the input you gathered, use the translations and the README to
// implement the assignment.

// PRO TIP: Start by outputting numbers 0 - 9
// For example, if you want to print out "ZERO" you can do this: cout << digits.at(0) << endl;
// For example, if you want to print out "ICHI" you can do this: cout << digits.at(1) << endl;
// For example, if you want to print out "NI"   you can do this: cout << digits.at(2) << endl;
// See if you can figure out a for loop that will let you do this without copy/pasting each line


