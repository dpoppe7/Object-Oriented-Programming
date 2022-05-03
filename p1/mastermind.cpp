#include <iostream>
#include <vector>
#include <random>

using std::cout;
using std::cin;
using std::vector;
using std::endl;
std::random_device rd;
std::default_random_engine engine(rd());

class Game {
private:
    int pegs;
    int colors;
    vector<int> secret;
    int guessNum = 0;
    int right, wrong;
public:
    void setData(int P, int C);
    void inRange(void);
    void printPlaying(void);

    vector<int> getCombination(vector<int>);
    void setSecret(vector<int>);
    void setRandomSecret(void);

    bool validateInput(vector<int>);
    bool exception(vector<int>);
    bool checkGuess(vector<int>);

    void printWin(void);
    void printEvaluateGuess(void);
    void printSurrender(void);

    void printInvalid(void);
    void printVector(vector<int>);
    void printGuess(vector<int>);
};

void Game::setData(int P, int C) {
    pegs = P;
    colors = C;
}

void Game::inRange(void) {
    if (pegs < 2) pegs = 2;
    if (pegs > 8) pegs = 8;
    if (colors < 6) colors = 6;
    if (colors > 20) colors = 20;
}

void Game::printPlaying(void){
    cout << "Playing Mastermind with " << pegs << " pegs and "
         << colors << " possible colors." << endl;
}

vector<int> Game::getCombination(vector<int> myVector){
    int value;
    int temp = pegs;
    while (temp) {
        cin >> value;
        myVector.push_back(value);
        temp--;
    }
    return myVector;
}

void Game::setSecret(vector<int> myVector){
    secret = myVector;
}

void Game::setRandomSecret() {
    std::uniform_int_distribution<int> random(1, colors);
    int number;
    int temp = pegs;
    while (temp) {
        number = random(engine);
        secret.push_back(number);
        temp--;
    }
}

bool Game::validateInput(vector<int> userInput){
    if(exception(userInput)){       //If userInput are all zeroes
        return true;
    }

    for (int i : userInput){
        if (!(i >= 1 && i <= colors)) {
            return false;
        }
    }
    return true;
}

bool Game::exception(vector<int> vector){
    int counter = 0;
    for (int e : vector){
        if (e == 0) {
            counter++;
        }
    }
    //All elements in vector are 0
    if (counter == pegs) {
        return  true;
    }
    return false;
}

void Game::printInvalid(void){
    cout << "Numbers must be between 1 and " << colors << ".\n" << endl;
}

void Game::printVector(vector<int> vector){
    for (int i = 0; i < vector.size(); i++){
        //print last element without a trailing space
        if (i == vector.size() - 1) {
            cout << vector[i];
        }
        else{
            cout << vector[i] << " ";
        }
    }
}

void Game::printGuess(vector<int> guess){
    cout << "Guess " << guessNum << ": ";
    printVector(guess);
    cout << endl;
}

bool Game::checkGuess(vector<int> guess){
    vector<int> temp_secret = secret;
    right = 0;
    wrong = 0;
    guessNum++; //increment guess number

    if(exception(guess)){
        return false;
    }

    //compare if guess and secret match in the right order
    for (int i = 0; i < guess.size(); i++){
        if (guess[i] == temp_secret[i]){
            guess[i] = 0;
            temp_secret[i] = 0;
            right++;
        }
    }
    //Look for other pairs other than 0
    //Compare each element of guess to each element of secret, not backwards
    for (int i = 0; i < guess.size(); i++){
        for (int j = 0; j < temp_secret.size(); j++){
            if ((guess[i] == temp_secret[j]) && (guess[i] != 0 && temp_secret[j] != 0)){
                guess[i] = 0;
                temp_secret[j] = 0;
                wrong++;
            }
        }
    }

    if (right == pegs){   //All numbers are correct
        return true;
    }
    return false;
}

void Game::printWin(void) {
    cout << "You won!\n";
    if(guessNum == 1){
        cout << "It took you 1 guess." << endl;
    }
    else{
        cout << "It took you " << guessNum << " guesses." << endl;
    }
}

void Game::printEvaluateGuess(void) {
    cout << right << " Right place" << endl;
    cout << wrong << " Wrong place\n" << endl;
}

void Game::printSurrender(void){
    cout << "You lost.\nThe secret was ";
    printVector(secret);
    cout << "." << endl;
}

int main() {
    Game game;

    int P, C; //pegs and colors
    cin >> P >> C;
    game.setData(P, C);

    game.inRange();
    game.printPlaying();

    vector<int> combination; //Empty vector

    //Get combination: Secret
    vector<int> secret;
    bool pass = false;
    while (!pass){
        secret = game.getCombination(combination);
        bool validSecret = game.validateInput(secret);

        if (!validSecret){
            game.printInvalid();
        }
        else{
            if (game.exception(secret)){
                cout << "Using random secret.\n" << endl;
                game.setRandomSecret();
            }
            else {
                cout << "Using given secret.\n" << endl;
                game.setSecret(secret);
            }
            pass = true;
        }
    }

    //Get combination: Guess
    vector<int> guess;
    bool validInput;
    bool done = false;
    while (!done){
        guess = game.getCombination(combination);
        validInput = game.validateInput(guess);

        if (!validInput) {              //Invalid input
            game.printInvalid();
        }
        else {                          //Valid input
            bool isCorrect = game.checkGuess(guess);

            //Print "Guess num: guess"
            game.printGuess(guess);

            if (isCorrect){
                game.printWin();
                done = true;
            }
            else{
                if (game.exception(guess)){ //Check for Exception
                    game.printSurrender();
                    done = true;
                }
                else{
                    game.printEvaluateGuess();
                }
            }
        }
    }

    return 0;
}