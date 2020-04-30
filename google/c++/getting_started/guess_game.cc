#include <iostream>
#include <time.h>

using namespace std;

int generate_rnd() {
	int random_number;
	srand(time(NULL));
	random_number = rand() % 100 + 1;
        return random_number;
}

int main()
{	
	int expected = generate_rnd();
	int guess;
	do {
		cout <<"Enter your guess number: ";
		if( !(cin >> guess) ){
			cout << "You entered non-numeric." << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}
		if( guess > expected ) {
			cout <<"Too high\n";
		} else {
			cout <<"Too low\n";
		}
	} while(guess != expected);
	cout << "Congrats!\n";
	return 0;
}



