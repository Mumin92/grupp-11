//written by Team 11
//Granell, Alexander
//Säll, Erik

#include <iostream>
#include <string>
#include <vector>
#include <random>
using namespace std;

bool playAgain();
void beginGame();
void winMessage();
void guessNumbers();
void checkNumber(int guess);
void getName();
int getInputInt();
int random(int from, int thru);

string name;
int hiddenNumber;
int guessedTimes;
vector<int> guesses;

int main() {
	getName();

	while (true)
	{
		beginGame();

		guessNumbers();

		winMessage();

		if (!playAgain())
			break;
	}

	return 0;
}

bool playAgain() {
	cout << "Want to play again? y/n" << endl;

	string answer;
	cin >> answer;

	if (answer == "y")
		return true;
	else
		return false;
}

void beginGame() {
	hiddenNumber = random(0, 100);
	guessedTimes = 0;
	guesses = {};
}

void winMessage() {
	cout << "Congratulations " << name << "! You won the game!" << endl;
	cout << "You guessed " << guessedTimes << " times.";
}

void guessNumbers() {
	int guess = -1; //hiddenNumber will never be -1

	while (guess != hiddenNumber) {
		cout << "Please guess a number between 0-100" << endl;
		guess = getInputInt();

		checkNumber(guess);

		guessedTimes++;
	}
}

void checkNumber(int guess) {
	if (std::find(guesses.begin(), guesses.end(), guess) != guesses.end()) {
		cout << "You've already guessed that number!" << endl;
	}
	else {
		guesses.push_back(guess);

		if (guess > hiddenNumber) {
			cout << "Too high!" << endl;
		}
		else if (guess < hiddenNumber) {
			cout << "Too low!" << endl;
		}
	}
}

void getName() {
	string name;
	cout << "Please enter your name : ";
	cin >> name;
}

int getInputInt() {
	int result;
	while (!(cin >> result) || (result >= 0 && result <= 100)) {
		cout << "OOPS! Wrong input! Please enter a NUMBER between 0-100" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return result;
}

int random(int from, int thru) {
	static std::random_device rd;
	static std::mt19937 eng(rd());
	std::uniform_int_distribution<> distr(from, thru);
	return distr(eng);
}