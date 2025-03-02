#include "/public/read.h"
#include <gtest/gtest.h>
#include <sys/types.h>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// DO NOT TOUCH THESE OR YOU WILL HAVE A BAD TIME!
unordered_map<string, string> eTranslations = { {"SAYONARA", "GOODBYE"}, {"KONNICHIWA", "HELLO"}, {"ARIGATO", "THANKS"},
	{"WATASHI", "I"}, {"SUSHI", "SUSHI"}, {"UWU", "UWU"}, {"SENPAI", "SENIOR"}
}; // Japanese to English */
unordered_map<string, string> jTranslations = { {"GOODBYE", "SAYONARA"}, {"HELLO", "KONNICHIWA"}, {"THANKS", "ARIGATO"},
	{"I", "WATASHI"}, {"SUSHI", "SUSHI"}, {"UWU", "UWU"}, {"SENIOR", "SENPAI"}
}; // English to Japanese */

vector<string> digits = { "ZERO", "ICHI", "NI", "SAN", "YON", "GO", "ROKU", "NANA",
                          "HACHI", "KYUU"
                        };
vector<string> powers = { "EMPTY", "JYUU", "HYAKU", "SEN", "MAN" };

unordered_set<string> dict_db;

unordered_map<string, string> samplesentences;



const int MIN = 0;
const int MAX = 1'009'999;

// Reaper mains understand
void die(const string &s = "BAD INPUT!") {
	cout << s << endl;
	exit(EXIT_FAILURE);
}
// for test cases: true = English to Japanese. false = Japanese to English
string translator(bool flag, const string &key) {
	string rev;
	if (flag) {
	rev = (jTranslations.contains(key)) ? jTranslations.at(key) : "NOT FOUND";
	}
	else if (!flag) {
	rev = (eTranslations.contains(key)) ? eTranslations.at(key) : "NOT FOUND";
	}
	return rev;
}
/*
string translator2(bool flag, const int &key) {
	if (flag) return digits.at(key);
	else if (!flag) return powers.at(key);
}
*/
string warui(int i) {
	//maybe try using a vector. % by 10 then store, / by 10. repeat. use pushfront.
	/*
	if (i < MIN or i > MAX) //return "BAD INPUT!";
	string retVal;
	i = 10203;
	int x = 1;
	//retVal += to_string(x) + " ";
//	return digits.at(0);
	vector<string> nums;
	while (true) {
	x = i % 10;
	nums.insert(nums.begin(), powers.at(x));
	i = i / 10;
	if (i <= 0) break;
	}
	for (auto &c : nums) {japnsentence 
		cout << c;
		return c;
	}
	cout << endl;*/
	if (i < MIN or i > MAX) return "BAD INPUT!";
	string retVal;
	int x = i;
	retVal += to_string(x) + " ";
	if (x >= 1'000'000) {
		int millis = x / 1'000'000;
		if (millis == 1) retVal += powers.at(2) + " " + powers.at(4);
		else retVal += digits.at(millis) + " " + powers.at(4);
		x -= millis * 1'000'000;
		if (x) retVal += " ";
	}
	if (x >= 100'000) {
		int hunThous = x / 100'000;
		if (hunThous == 1) retVal += "JUU " + powers.at(4);
		else retVal += (digits.at(hunThous) + " " + powers.at(4));
		x -= hunThous * 100'000;
		if (x) retVal += " ";
	}
	if (x >= 10'000) {
		int tenThous = x / 10'000;
		if (tenThous <= 10) retVal += digits.at(tenThous);
		else if (tenThous > 10 and tenThous < 20) {
			retVal += powers.at(1);
			retVal += " ";
			retVal += digits.at((tenThous % 10));
		}
		else if (tenThous >= 20 and tenThous < 100) {
			retVal += digits.at(tenThous / 10);
			retVal += " ";
			retVal += powers.at(1);
			retVal += " ";
			retVal += digits.at((tenThous % 10));
		}
		else if (tenThous == 100) retVal += powers.at(2);
		retVal += (" " + powers.at(3));
		x -= tenThous * 10'000;
		if (x) retVal += " ";
	}
	if (x >= 1'000) {
		int thous = x / 1'000;
		if (thous < 1 or thous > 9) {
			cout << "BAD INPUT!" << endl;
			exit(EXIT_FAILURE);
		}
		if (thous == 1) retVal += powers.at(3);
		else if (thous == 3) retVal += "SAN ZEN";
		else if (thous == 8) retVal += "HASSEN";
		else retVal += (digits.at(thous) + " SEN");
		x -= thous * 1'000;
		if (x) retVal += " ";
	}
	if (x >= 100) {
		int hundreds = x / 100;
		if (hundreds < 1 or hundreds > 10) die();
		if (hundreds == 1) retVal += powers.at(2);
		else if (hundreds == 3) retVal += "SAN BYAKU";
		else if (hundreds == 6) retVal += "ROPPYAKU";
		else if (hundreds == 8) retVal += "HAPPYAKU";
		else retVal += (digits.at(hundreds) + " HYAKU");
		x -= hundreds * 100;
		if (x) retVal += " ";
	}
	if (x >= 10) {
		int tens = x / 10;
		if (tens < 1 or tens > 9) {
			die();
		}
		if (tens == 1) retVal += powers.at(1);
		else {
			retVal += digits.at(tens);
			retVal += " ";
			retVal += powers.at(1);
		}
		x -= tens * 10;
		if (x) retVal += " ";
	}
	if (i == 0) retVal += digits.at(i);
	else if (x > 0 and x < 10) retVal += digits.at(x);
	retVal += "\n";
	return retVal;


}

void FillDict() {
	ifstream ins("/usr/share/dict/words");
	while (ins) {
		string temp = readline(ins);
		dict_db.insert(temp);
	}
}
void PrintDict() {
	for (auto i = dict_db.begin(); i != dict_db.end(); i++) {
		cout << *i << endl;
	}
}
void FindInDict(string &str) {
	if (dict_db.count(str)) {
		cout << "Found it with count" << endl;
	}
}

string uppercase(const string &s) {
	string retVal;
	for (const char &c : s) retVal += toupper(c);
	return retVal;
}
string lowercase(const string &s) {
	string retVal;
	for (const char &c : s) retVal += tolower(c);
	return retVal;
}


// TESTS
// TODO: Make 7 test cases for each one
TEST(EnglToJapnTranslator, GoodTests) {
	EXPECT_EQ(translator(true, "GOODBYE"), "SAYONARA");
	EXPECT_EQ(translator(true, "HELLO"), "KONNICHIWA");
	EXPECT_EQ(translator(true, "THANKS"), "ARIGATO");
	EXPECT_EQ(translator(true, "I"), "WATASHI");
	EXPECT_EQ(translator(true, "SUSHI"), "SUSHI");
	EXPECT_EQ(translator(true, "UWU"), "UWU");
	EXPECT_EQ(translator(true, "SENIOR"), "SENPAI");
}

TEST(JapnToEnglTranslator, GoodTests) {
	EXPECT_EQ(translator(false, "UWU"), "UWU");
	EXPECT_EQ(translator(false, "SAYONARA"), "GOODBYE");
	EXPECT_EQ(translator(false, "KONNICHIWA"), "HELLO");
	EXPECT_EQ(translator(false, "ARIGATO"), "THANKS");
	EXPECT_EQ(translator(false, "WATASHI"), "ME");
	EXPECT_EQ(translator(false, "SUSHI"), "SUSHI");
	EXPECT_EQ(translator(false, "SENPAI"), "SENIOR");
}

TEST(EnglToJapnTranslator, BadTests) {
	EXPECT_EQ(translator(true, "SAYARA"), "NOT FOUND");
	EXPECT_EQ(translator(true, "Jeepers"), "NOT FOUND");
	EXPECT_EQ(translator(true, "Frick"), "NOT FOUND");
	EXPECT_EQ(translator(true, "HALP"), "NOT FOUND");
	EXPECT_EQ(translator(true, "OWKEMmmmmmmm"), "NOT FOUND");
	EXPECT_EQ(translator(true, "ASdow"), "NOT FOUND");
	EXPECT_EQ(translator(true, "ASODWE"), "NOT FOUND");
}

TEST(JapnToEnglTranslator, BadTests) {
	EXPECT_EQ(translator(false, "HERSHEY"), "NOT FOUND");
	EXPECT_EQ(translator(false, "Chihapouse"), "NOT FOUND");
	EXPECT_EQ(translator(false, "Henry"), "NOT FOUND");
	EXPECT_EQ(translator(false, "Bad Test"), "NOT FOUND");
	EXPECT_EQ(translator(false, "Polisci"), "NOT FOUND");
	EXPECT_EQ(translator(false, "San Bernando"), "NOT FOUND");
	EXPECT_EQ(translator(false, "I AM ATOMIC"), "NOT FOUND");
}

TEST(Warui, GoodTests) {
	EXPECT_EQ(warui(100000), "100000 JUU MAN\n");
	EXPECT_EQ(warui(9), "9 KYUU\n");
	EXPECT_EQ(warui(3), "3 SAN\n");
	EXPECT_EQ(warui(1), "1 ICHI\n");
	EXPECT_EQ(warui(2), "2 NI\n");
	EXPECT_EQ(warui(40000), "40000 YON SEN\n");
	EXPECT_EQ(warui(67), "67 ROKU JYUU NANA\n");
}

TEST(Warui, BadTests) {
	EXPECT_EQ(warui(-1), "BAD INPUT!");
	EXPECT_EQ(warui(1000000000), "BAD INPUT!");
	EXPECT_EQ(warui(-3204), "BAD INPUT!");
	EXPECT_EQ(warui(-23), "BAD INPUT!");
	EXPECT_EQ(warui(1023231333), "BAD INPUT!");
	EXPECT_EQ(warui(-1021000002), "BAD INPUT!");
	EXPECT_EQ(warui(1232323232), "BAD INPUT!");

}

TEST(Warui, EdgeTests) {
	EXPECT_EQ(warui(326), "326 SAN BYAKU NI JYUU ROKU\n");
	EXPECT_EQ(warui(3026), "3026 SAN ZEN NI JYUU ROKU\n");
	EXPECT_EQ(warui(8927), "8927 HASSEN KYUU HYAKU NI JYUU NANA\n");
	EXPECT_EQ(warui(2982), "2982 NI SEN KYUU HYAKU HACHI JYUU NI\n");
	EXPECT_EQ(warui(8325), "8325 HASSEN SAN BYAKU NI JYUU GO\n");
	EXPECT_EQ(warui(3679), "3679 SAN ZEN ROPPYAKU NANA JYUU KYUU\n");
	EXPECT_EQ(warui(5890), "5890 GO SEN HAPPYAKU KYUU JYUU\n");

}


int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv); // DO NOT TOUCH THIS!
	enum choices{TESTS = 1, WARUI, ENGLTOJAPN, JAPNTOENGL, AUTOTRANS, INSERT, QUIT = 7};
	//Inputs all the words.
	FillDict();
	string etoJ;
	string jtoE;
	string samples;
	string engl;
	string japn;
	string sample;
	string sampleoutput;
	int counter1 = 0;
	ifstream insMih("Mihongo.txt");
	while (insMih) { // do this again for mihongo.txt. read everything from nihongo, then everything from mihongo.
	
		string s = readline(insMih);
		if (!insMih) break;
		if (s.at(0) == '=') {
			if (counter1 == 0) etoJ = s;
			else if (counter1 == 1) jtoE = s;
			else if (counter1 == 2) samples = s;
			else die();
			counter1++;
		}
		else if (counter1 == 1) {
			string engl = s;
			string japn = readline(insMih);
			if (!insMih) break;
			engl = uppercase(engl);
			japn = uppercase(japn);
			jTranslations[engl] = japn;
		}
		else if (counter1 == 2) {
			string japn = s;
			string engl = readline(insMih);
			if (!insMih) break;
			engl = uppercase(engl);
			japn = uppercase(japn);
			eTranslations[japn] = engl;
		}
		else if (counter1 == 3) {
			string sent = s;
			string sent1 = readline(insMih);
			if (!insMih) break;
			sent = uppercase(sent);
			sent1 = uppercase(sent1);
			samplesentences[sent] = sent1;
		}
	}
	string filename;
	cout << "Please enter the name of your Japanese-English dictionary (/public/nihongo.txt): \n";
	cin >> filename;
	ifstream ins(filename);
	int counter = 0;
//	string s = readline(ins);
	string ws;
	while (ins) { // do this again for mihongo.txt. read everything from nihongo, then everything from mihongo.
	
		string s = readline(ins);
		if (!ins) break;
		if (s.at(0) == '=') {
			if (counter == 0) etoJ = s;
			else if (counter == 1) jtoE = s;
			else if (counter == 2) samples = s;
			else die();
			counter++;
		}
		else if (counter == 1) {
			string engl = s;
			string japn = readline(ins);
			if (!ins) break;
			engl = uppercase(engl);
			japn = uppercase(japn);
			jTranslations[engl] = japn;
		}
		else if (counter == 2) {
			string japn = s;
			string engl = readline(ins);
			if (!ins) break;
			engl = uppercase(engl);
			japn = uppercase(japn);
			eTranslations[japn] = engl;
		//	cout << japn << "/" << engl << "---" << endl;
		}
		else if (counter == 3) {
			string sent = s;
			string sent1 = readline(ins);
			if (!ins) break;
			sent = uppercase(sent);
			sent1 = uppercase(sent1);
			samplesentences[sent] = sent1;
		}
	}
	//end of translation input
	//return RUN_ALL_TESTS();
	string test = "helloThere";
	int i = 0;
	
	while (true) {
	int choice = read("Please enter an option:\n1) Run all tests\n2) Translate Number\n3) English to Japanese\n4) Japanese to English\n5) Auto Translate\n6) Add to Dictionary\n7) Quit\n");
	// Warui #2.1: Warui Part One (MUST BE A FUNCTION) and all tests written
	//
	if (choice == TESTS) return RUN_ALL_TESTS();
	if (choice == WARUI) {
		cout << "Please enter a number to translate between 0 and 1009999:" << endl;
		cin >> i;
		if (!cin or i < 0) die();
		cout << warui(i);
		exit(EXIT_SUCCESS);
			//cout << warui(8) << "S" << endl;
	//	cout << uppercase(test);

	}
	if (choice == ENGLTOJAPN) {
		string EnglSent = readline("Please enter a sentence to translate into Japanese:\n");
	//	EnglSent = uppercase(EnglSent);
		for (char c : EnglSent) if (isdigit(c)) die();
		if (EnglSent == "QUIT") exit(EXIT_SUCCESS);
		string japnsentence;
		istringstream iss (EnglSent);
		while (iss) {
			string temp;
			iss >> temp;
			if (!iss) break;
			string tempLow = lowercase(temp);
			//if (!dict_db.contains(tempLow) and !eTranslations.contains(tempLow)) cout << "Invalid Word!" << endl;
			temp = uppercase(temp);
			if (!jTranslations.contains(temp)) cout << "<missing> ";
			else japnsentence += translator(true, temp) + " ";
//			japnsentence + " ";
		}
		cout << japnsentence << endl;
		exit(EXIT_SUCCESS);
		
	}
	if (choice == JAPNTOENGL) {
		string japnsentence = readline("Please enter a sentence to translate into English:\n");
	//	EnglSent = uppercase(EnglSent);
		for (char c : japnsentence) if (isdigit(c)) die();
		if (japnsentence == "QUIT") exit(EXIT_SUCCESS);
		string EnglSent;
		istringstream iss (japnsentence);
		while (iss) {
			string temp;
			iss >> temp;
			if (!iss) break;
			//if (!dict_db.contains(temp)) cout << "F1";
			temp = uppercase(temp);
			if (!eTranslations.contains(temp)) EnglSent += "<missing> ";
	   	//	cout << temp << " is not in the dictionary. \n";
		//	string trans = readline("Please enter the translation into the database\n");
		//	trans = uppercase(trans);
	//		jTranslations.insert({temp, trans});
		//	eTranslations.insert({trans,temp});
		//	exit(EXIT_SUCCESS);
			else EnglSent += translator(false, temp) + " ";
//			japnsentence + " ";
		}
		cout << EnglSent << endl;
		exit(EXIT_SUCCESS);
		
	}
	if (choice == AUTOTRANS) {
		int counterengl = 0;
		int countwords = 0;
		string sentencetrans;
		string sentence = readline("Please enter a sentence to auto translate: \n");
		string sentence1 = sentence;
		istringstream iss (sentence);
		while (iss) {
			vector<string> vec;
			string word;
			iss >> word;
			if (!iss) break;
			countwords++;
			word = lowercase(word);
			if (dict_db.contains(word)) counterengl++;
			word = uppercase(word);
		}
			stringstream iss2 (sentence1);
			while (iss2) {
			string help;
			iss2 >> help;
			if (!iss2) break;
			help = uppercase(help);
		//	cout << help << endl;
			if (counterengl >= countwords / 2 ) {
				if (!jTranslations.contains(help)) sentencetrans += "<missing> ";
				else sentencetrans += translator(true,help) + " ";
				}
			else if (counterengl < countwords / 2) {
				if (!eTranslations.contains(help)) sentencetrans += "<missing> ";
				else sentencetrans += translator(false,help) + " ";
				}
			}
			cout << sentencetrans << endl;
			break;
		}
	if (choice == INSERT) {
		unordered_map<string,string> inertedtranslations;
		while (true) {
			string insert = read("Give me a word in English (QUIT to quit):\n");
		//	if (insert == "QUIT") break;
			string insertjapn = read("Give me the same word in Japanese (QUIT to quit):\n");
			if (insert == "QUIT") break;
			if (insertjapn == "QUIT") break;
			eTranslations[insertjapn] = insert;
			jTranslations[insert] = insertjapn;
			inertedtranslations[insert] = insertjapn;
			}
		string file1 = read("Please enter a file you want to write to: \n");
		ofstream outusr(file1);
		for (const auto &s : inertedtranslations) outusr << s.first << endl << s.second << endl << endl;
		outusr << jtoE << endl;
		for (const auto &s : jTranslations) {
			eTranslations[s.second] = s.first;
			outusr << s.first << endl << s.second << endl << endl;
		}
		outusr << etoJ << endl;
		for (const auto &s : eTranslations) {
		//	string s1 = uppercase(s.second), s2 = uppercase(s.first);
			jTranslations[s.second] = s.first;
			outusr << s.first << endl << s.second << endl << endl;
		} 
		outusr << samples << endl;
		for (const auto &s : samplesentences) {
		outusr << s.first<< endl << s.second << endl << endl;
			}
		}
		break;
		

	if (choice == QUIT) { 
		ofstream outs2("Mihongo.txt", ofstream::out);
		outs2 << jtoE << endl;
		for (const auto &s : jTranslations) {
			eTranslations[s.second] = s.first;
			outs2 << s.first << endl << s.second << endl << endl;
		}
		outs2 << etoJ << endl;
		for (const auto &s : eTranslations) {
		//	string s1 = uppercase(s.second), s2 = uppercase(s.first);
			jTranslations[s.second] = s.first;
			outs2 << s.first << endl << s.second << endl << endl;
		} 
		outs2 << samples << endl;
		for (const auto &s : samplesentences) {
		outs2 << s.first<< endl << s.second << endl << endl;
			}
		}
		break;
	}
	// Warui #2.2: Read from dictionary and write to file the translations
	// Warui #2.3: Translate sentences and auto detect translation done
	// for autodetect count how many words it'll get turned into for one or the other, translate to one with the most.
	
}
