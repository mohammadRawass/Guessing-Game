#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <string>
#include <sstream>
using namespace std;


class HighScore {

private:
    int  scoreListEasy[6] = { 0,0,0,0,0,0 };
    int  scoreListMedium[6] = { 0,0,0,0,0,0 };
    int  scoreListHard[6] = { 0,0,0,0,0,0 };
    int  scoreNumbersEasy;
    int  scoreNumbersMedium;
    int  scoreNumbersHard;


public:
    HighScore() {
        scoreNumbersEasy = 0;
        scoreNumbersMedium = 0;
        scoreNumbersHard = 0;
    }

    void addScoreList(int difficulty, int score) {
        // sorting the score from the highest to lowest after adding the score accroding to the difficulty..
        switch (difficulty) {
        case(1):
            //when score is 0 or the score Numbers level Easy is 5 the switch will break because we have limited indexes number to store in
        { if (score == 0) {
            break;
        }
        else if (scoreNumbersEasy > 5) {
            fullArray(scoreListEasy, score);
        }
        else {

            scoreListEasy[scoreNumbersEasy] = score;
            //testing     cout<<" \n ######## "<<scoreListEasy[scoreNumbersEasy]<<scoreListEasy[scoreNumbersEasy+1]<<endl;
            sortingArray(scoreListEasy, scoreNumbersEasy);
            scoreNumbersEasy++;


        }break; }



        case(2):
        { if (score == 0) {
            break;
        }
        else if (scoreNumbersMedium > 5) {
            fullArray(scoreListMedium, score);

        }
        else {

            scoreListMedium[scoreNumbersMedium] = score;
            sortingArray(scoreListMedium, scoreNumbersMedium);
            scoreNumbersMedium++;

        }break;
        }
        case(3):
        {  if (score == 0) {
            break;
        }
        else if (scoreNumbersHard > 5) {
            fullArray(scoreListHard, score);
        }
        else {

            scoreListHard[scoreNumbersHard] = score;
            sortingArray(scoreListHard, scoreNumbersHard);
            scoreNumbersHard++;

        }break;
        }
        }//end switch

    } //end method

    void getScoreList(int difficulty) {      // method to return the list of score accroding to the difficulty
        // checking if the array was empty or not and return it..
        switch (difficulty) {
        case(1):

            toString(scoreListEasy, scoreNumbersEasy);

            break;


        case(2):
        {
            toString(scoreListMedium, scoreNumbersMedium);
            break; }





        case(3):

            toString(scoreListHard, scoreNumbersHard);
            break;






        }


        //end method
    }

    void sortingArray(int array[6], int scoreNumbers) // method sorts the array from highest score to lowest.
    {
        for (int i = 0; i < 6; i++) {
            for (int j = i; j < 6; j++) {
                int temp;
                if (array[i] < array[j]) {
                    temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;

                }
                // cout<<" \n ##"<<array[i];
            }
        }

    }
    void fullArray(int array[6], int score) // method sorts the array from highest score to lowest.
    {
        for (int i = 0; i < 6; i++) {
            if (array[i] < score) {
                array[i] = score;
                break;

            }
            // cout<<" \n ##"<<array[i];
        }

    }
    void toString(int array[6], int scoreNumbers)
    {
        if (array[0] > 0) {
            cout << array[0];
            for (int i = 1; i < scoreNumbers; i++) {

                cout << ",  " << array[i];

            }
            //cout<<" $ "<<scoreNumbers<<endl;
        }
        else {
            cout << "No Score Available Yet..." << endl;
        }

    }



    //end class
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Levels {

    /*in both game the chances
    easy : 6 , medium: 4 , hard: 2,

   and the score in both will be
   easy: (chance+1)*10, medium:(chance+1)*25, hard: (chance+1)*100..*/


   // methods for guessing random number accroding to type of difficulty
public:
    Levels() {

    }

    int levelEasyAlpha() {
        srand(time(0));
        char randomAlphabet = 'a' + (rand() % 26);   //Generating a random letter between 'a' to 'z'
        char rangeStart, rangeEnd;
        char userChoice;
        int chances = 6;

        // range will be 12 letters
        if (randomAlphabet >= 'a' && randomAlphabet <= 'f') {                   // declaring range which if was the  random letter between 'a' and 'f'
            rangeStart = 'a';
            rangeEnd = 'l';

        }
        else if (randomAlphabet >= 'u' && randomAlphabet <= 'z') {            // declaring range which if was the random letter between 'u' and 'z'
            rangeEnd = 'z';
            rangeStart = 'o';

        }
        else {
            rangeStart = (char)(randomAlphabet - 5);
            rangeEnd = (char)(randomAlphabet + 6);
        }



        cout << " Level (Easy) :\n" <<
            " ------------------------------------------------------\n" <<
            "  1.In this Guess game you must guess the vowel alphabet.\n" <<
            "  2.You are allowed to make one guess at a time.\n" <<
            "  3.Each game has #6 chances to guess the correct vowel.\n" <<
            "  4.Once you have used up all your chances, you lose the game.\n" <<
            "  5.You have #6 chances to guess the alphabet\n" <<
            "\t\t\tGood Luck!\n" <<
            "------------------------------------------------------\n" << endl;

        cout << "Guess a letter between (" << rangeStart << " - " << rangeEnd << ") :\n";


        while (chances != 0) {

            chances--;
            // check if the user enter a valid integer or out of range..
            userChoice = validLetterInput();

            // if the user guess match the random alphabet
            if (userChoice == randomAlphabet) {
                cout << "You Won! with " << chances << " chances left and you used " << (6 - chances) << endl;
                cout << "And your score is : " << (chances + 1) * 10 << endl;

                return (chances + 1) * 10;
            }

            else if (userChoice > rangeEnd || userChoice < rangeStart) {     // if the user guess was out of range

                cout << "Your guess was out of range! Chances left: " << chances << "\n";
                if (chances > 0) {
                    cout << "Guess a letter between (" << rangeStart << " - " << rangeEnd << ") :\n";
                }
            }


            else if (randomAlphabet - userChoice <= 3 && randomAlphabet - userChoice > 0) {     // if the user guess was less than 3 letter from down the random number
                cout << "Your guess was  low, But close! Chances left: " << chances << "\n";
            }

            else if (userChoice - randomAlphabet <= 3 && userChoice - randomAlphabet > 0) {     // if the user guess was less than 3 letter from above the random number
                cout << "Your guess was  high, But close! Chances left: " << chances << "\n";
            }

            else if (userChoice > randomAlphabet) {                                      // if the user guess was more than 3 letters from above the random number
                cout << "Your guess was too high! Chances left: " << chances << "\n";
            }

            else if (userChoice < randomAlphabet) {
                cout << "Your guess was too low! Chances left: " << chances << "\n";
            }               // if the user guess was more than 3 letters from down the random number



        }
        if (chances == 0)                                                           // if no chances left..
        {
            cout << "No chances left.  you lost \n" <<
                "Unfortunately, the right guess was # " << randomAlphabet << " # " << endl;
        }

        return 0;
        // end method
    }
    int levelMediumAlpha() {

        srand(time(0));
        char randomAlphabet = 'a' + (rand() % 26);   //Generating a random letter between 'a' to 'z'
        char rangeStart, rangeEnd;
        char userChoice;
        int chances = 4;

        // range will be 20 letters

        if (randomAlphabet >= 'a' && randomAlphabet <= 'j') {                   // declaring range which if was the  random letter between 'a' and 'j'
            rangeStart = 'a';
            rangeEnd = 't';

        }
        else if (randomAlphabet >= 'q' && randomAlphabet <= 'z') {           // declaring range which if was the  random letter between 'g' and 'z'
            rangeStart = 'g';
            rangeEnd = 'z';

        }
        else {
            rangeStart = (char)(randomAlphabet - 9);
            rangeEnd = (char)(randomAlphabet + 10);
        }


        cout << " Level (Medium) :\n" <<
            "------------------------------------------------------\n" <<
            "  1.In this Guess game you must guess the vowel alphabet.\n" <<
            "  2.You are allowed to make one guess at a time.\n" <<
            "  3.Each game has #4 chances to guess the correct vowel.\n" <<
            "  4.Once you have used up all your chances, you lose the game.\n" <<
            "  5.You have #4 chances to guess the alphabet\n" <<
            "\t\t\tGood Luck!\n" <<
            " ------------------------------------------------------\n";

        cout << "Guess a letter between (" << rangeStart << " - " << rangeEnd << ") :\n";

        // start guessing
        while (chances != 0) {
            chances--;
            userChoice = validLetterInput();
            // if the user guess match the random alphabet
            if (userChoice == randomAlphabet) {
                cout << "You Won! with " << chances << " chances left and you used " << (4 - chances) << endl;
                cout << "And your score is : " << (chances + 1) * 25 << endl;
                return(chances + 1) * 25;                                                  // return the score..
            }
            else if (userChoice > rangeEnd || userChoice < rangeStart) {     // if the user guess was out of the range

                cout << "Your guess was out of range! Chances left: " << chances << "\n";
                if (chances > 0) {
                    cout << "Guess a letter between (" << rangeStart << " - " << rangeEnd << ") :\n";
                }
            }

            else if (randomAlphabet - userChoice <= 3 && randomAlphabet - userChoice > 0)      // the user guess was less than 3 letter from down the random Alphabet
                cout << "Your guess was  low, But close! Chances left:" << chances << "\n";


            else if (userChoice - randomAlphabet <= 3 && userChoice - randomAlphabet > 0)      // the user guess was less than 3 letter from above the random Alphabet
                cout << "Your guess was  high, But close! Chances left: " << chances << "\n";


            else if (userChoice > randomAlphabet)                                       // the user guess was more than 3 letters from above the random Alphabet
                cout << "Your guess was too high! Chances left: " << chances << "\n";


            else if (userChoice < randomAlphabet)                                      // the user guess was more than 3 letters from down the random Alphabet
                cout << "Your guess was too Low!! Chances left: " << chances << "\n";



        }
        if (chances == 0) {                                                               // if no chances left..
            cout << "No chances left.  you lost\n" <<
                "Unfortunately, the right guess was # " << randomAlphabet << " # " << endl;
        }

        return 0;

        // end method
    }

    int levelHardAlpha() {

        srand(time(0));
        char randomAlphabet = 'a' + (rand() % 26);   //Generating a random letter between 'a' to 'z'
        char rangeStart = 'a', rangeEnd = 'z';
        char userChoice;
        int chances = 2;


        // range will be 26 letters

        cout << " Level (Hard) :\n" <<
            " ------------------------------------------------------\n" <<
            "  1.In this Guess game you must guess the vowel alphabet.\n" <<
            "  You are allowed to make one guess at a time.\n" <<
            "  3.Each game has #2 chances to guess the correct vowel.\n" <<
            "  4.Once you have used up all your chances, you lose the game.\n" <<
            " 5.You have #2 chances to guess the alphabet\n" <<
            "\t\t\tGood Luck!\n" <<
            "------------------------------------------------------\n" << endl;

        cout << "Guess a letter between (" << rangeStart << " - " << rangeEnd << ") :\n";

        while (chances != 0) {
            chances--;
            userChoice = validLetterInput();

            if (userChoice == randomAlphabet) {
                cout << "You Won! with " << chances << " chances left and you used " << (2 - chances) << endl;
                cout << "And your score is : " << (chances + 1) * 100 << endl;
                return(chances + 1) * 100;
            }

            else if (userChoice > randomAlphabet)           // the user guess was more than 3 letters from above the random Alphabet
                cout << "Your guess was too high! Chances left: " << chances << "\n";

            else if (userChoice < randomAlphabet)
                cout << "Your guess was too low! Chances left: " << chances << "\n";    // the user guess was more than 3 letters from down the random Alphabet



        }
        if (chances == 0)                                                                // if no chances left..
        {
            cout << "No chances left.  you lost\n" <<
                "Unfortunately, the right guess was # " << randomAlphabet << " # " << endl;
        }

        return 0;
        //end method
    }
    // methods for guessing random number accroding to type of difficulty

    int levelEasyNumber() {
        srand(time(0));
        int randomNumber = 1 + (rand() % 100);
        int rangeStart, rangeEnd, chances = 6, userChoice;

        if (randomNumber >= 1 && randomNumber <= 7) {              // declaring range if the random number was between "1" to "7"
            rangeStart = 1;
            rangeEnd = 15;
        }

        else if (randomNumber >= 93 && randomNumber <= 100) {         // declaring range if the random number was between "93" to "100"
            rangeStart = 86;
            rangeEnd = 100;
        }

        else {
            rangeStart = randomNumber - 7;
            rangeEnd = randomNumber + 7;
        }
        // range will be 15 numbers
        cout << " Level (Easy) :\n" <<
            " ------------------------------------------------------\n" <<
            "  1.In this Guess game you must guess the number.\n" <<
            "  2.You are allowed to make one guess at a time.\n" <<
            "   3.Each game has #6 chances to guess the correct number.\n" <<
            "   4.Once you have used up all your chances, you lose the game.\n" <<
            " 5 5.You have #6 chances to guess the Number.\n" <<
            "\t\t\tGood Luck!\n" <<
            "------------------------------------------------------\n" << endl;

        cout << "Guess a Number between (" << rangeStart << " - " << rangeEnd << ") :\n";



        while (chances != 0) {
            chances--;
            userChoice = validNumberInput();

            // if user guess the correct number
            if (userChoice == randomNumber) {
                cout << "You Won! with " << chances << " chances left and you used " << (6 - chances) << endl;
                cout << "And your score is : " << (chances + 1) * 10 << endl;

                // return a score multipy by 10 with the chances left
                return (chances + 1) * 10;
            }

            else if (userChoice > rangeEnd || userChoice < rangeStart) {     // if the user guess was out of range
                cout << "Your guess was out of range! Chances left: " << chances << "\n";
                if (chances > 0) {

                    cout << "Guess a Number between (" << rangeStart << " - " << rangeEnd << ") :\n";
                }
            }


            // the user guess was less than 3 number from down the random number
            else if (randomNumber - userChoice <= 3 && randomNumber - userChoice > 0)
                cout << "Your guess was  low, But close! Chances left: " << chances << "\n";

            // the user guess was less than 3 number from above the random number
            else if (userChoice - randomNumber <= 3 && userChoice - randomNumber > 0)
                cout << "Your guess was  high, But close! Chances left: " << chances << "\n";
            // the user guess was more than the random number
            else if (userChoice > randomNumber)
                cout << "Your guess was too high! Chances left: " << chances << "\n";
            // the user guess was less than the random number
            else if (userChoice < randomNumber)
                cout << "Your guess was too low! Chances left: " << chances << "\n";

        }
        // if no chances left..
        if (chances == 0)
        {
            cout << "No chances left.  you lost\n" <<
                "Unfortunately, the right guess was # " << randomNumber << " # " << endl;
        }


        return 0;
        //end method
    }

    int levelMediumNumber() {

        srand(time(0));
        int randomNumber = 1 + (rand() % 100);
        int rangeStart, rangeEnd, chances = 4, userChoice;

        if (randomNumber >= 1 && randomNumber <= 25) {       // declaring range if the random number was between "1" to "25"
            rangeStart = 1;
            rangeEnd = 50;
        }

        else if (randomNumber >= 75 && randomNumber <= 100) {   // declaring range if the random number was between "75" to "100"
            rangeStart = 50;
            rangeEnd = 100;
        }

        else {
            rangeStart = randomNumber - 24;
            rangeEnd = randomNumber + 25;
        }
        // range will be  50 numbers
        cout << " Level (Medium) :\n" <<
            " ------------------------------------------------------\n" <<
            "  1.In this Guess game you must guess the number.\n" <<
            "  2.You are allowed to make one guess at a time.\n" <<
            "   3.Each game has #4 chances to guess the correct number.\n" <<
            "   4.Once you have used up all your chances, you lose the game.\n" <<
            " 5 5.You have #4 chances to guess the Number.\n" <<
            "\t\t\tGood Luck!\n" <<
            "------------------------------------------------------\n" << endl;

        cout << "Guess a Number between (" << rangeStart << " - " << rangeEnd << ") :\n";


        while (chances != 0) {
            chances--;
            userChoice = validNumberInput();

            if (userChoice == randomNumber) {
                cout << "You Won! with " << chances << " chances left and you used " << (4 - chances) << endl;
                cout << "And your score is : " << (chances + 1) * 25 << endl;
                return (chances + 1) * 25;
            }
            else if (userChoice > rangeEnd || userChoice < rangeStart) {     // if the user guess was out of range
                cout << "Your guess was out of range! Chances left: " << chances << "\n";
                if (chances > 0) {
                    cout << "Guess a Number between (" << rangeStart << " - " << rangeEnd << ") :\n";
                }
            }

            else if (randomNumber - userChoice <= 3 && randomNumber - userChoice >
                0)      // the user guess was less than 3 numbers from down the random number
                cout << "Your guess was  low, But close! Chances left: " << chances << "\n";

            else if (userChoice - randomNumber <= 3 && userChoice - randomNumber > 0)      // the user guess was less than 3 numbers from above the random number
                cout << "Your guess was  high, But close! Chances left: " << chances << "\n";

            else if (userChoice > randomNumber)                                        // the user guess was more than 3 numbers from above the random number
                cout << "Your guess was too high! Chances left: " << chances << "\n";

            else if (userChoice < randomNumber)
                cout << "Your guess was too low! Chances left: " << chances << "\n";              // the user guess was more than 3 numbers from down the random number

        }

        if (chances == 0)                                                              // if no chances left..
        {
            cout << "No chances left.  you lost\n" <<
                "Unfortunately, the right guess was # " << randomNumber << " # " << endl;
        }

        return 0;
        //end method
    }

    int levelHardNumber() {

        srand(time(0));
        int randomNumber = 1 + (rand() % 100);
        int rangeStart = 1, rangeEnd = 100, chances = 2, userChoice;


        // the range will be 100 numbers
        cout << " Level (Hard) :\n" <<
            " ------------------------------------------------------\n" <<
            "  1.In this Guess game you must guess the number.\n" <<
            "  2.You are allowed to make one guess at a time.\n" <<
            "   3.Each game has #2 chances to guess the correct number.\n" <<
            "   4.Once you have used up all your chances, you lose the game.\n" <<
            " 5 5.You have #2 chances to guess the Number.\n" <<
            "\t\t\tGood Luck!\n" <<
            "------------------------------------------------------\n" << endl;

        cout << "Guess a Number between (" << rangeStart << " - " << rangeEnd << ") :\n";


        while (chances != 0) {
            chances--;
            userChoice = validNumberInput();

            if (userChoice == randomNumber) {
                cout << "You Won! with " << chances << " chances left and you used " << (4 - chances) << endl;
                cout << "And your score is : " << (chances + 1) * 100 << endl;
                return (chances + 1) * 100;
            }

            else if (userChoice > rangeEnd || userChoice < rangeStart) {     // if the user guess was out of range
                cout << "Your guess was out of range! Chances left: " << chances << "\n";
                if (chances > 0) {
                    cout << "Guess a Number between (" << rangeStart << " - " << rangeEnd << ") :\n";
                }
            }

            else if (userChoice > randomNumber)                                        // the user guess was more than 3 numbers from above the random number
                cout << "Your guess was too high! Chances left: " << chances << "\n";

            else if (userChoice < randomNumber)
                cout << "Your guess was too low! Chances left: " << chances << "\n"
                << endl;              // the user guess was more than 3 numbers from down the random number

        }

        if (chances == 0)                                                              // if no chances left..
        {
            cout << "No chances left.  you lost\n" <<
                "Unfortunately, the right guess was # " << randomNumber << " # " << endl;
        }




        return 0;
        //end method
    }

    // methods check input from user

    char validLetterInput() {                  // a method to check from user if he typed numbers or sympols..

        string userChoice1;
        cout << "Enter your Guess :\n>";
        cin >> userChoice1;
        char userChoice = tolower(userChoice1.at(0));
        //userChoice = userChoice.at(0);

        while (userChoice > 'z' || userChoice < 'a') {

            cout << "Error: Input must contain only letters." << endl;

            cout << "Enter only letters: \n>";
            cin >> userChoice1;
            userChoice = tolower(userChoice1.at(0));
        }






        return userChoice;  // return the value after the user typed a valid charecter.

        //end method
    }

    int validNumberInput() {      // a method to check from a user if he typed letters or sympols..

        string input; //just in case we will take the input as string
        int Guess = 0;
        bool validChoice = false;

        cout << "Enter your Guess :\n>";
        while (!validChoice) {
            cin >> input;
            /*try,catch as i learend to  predict and examine the user input if the user didnt follow the instructions.
            first we will try to transfer the user string input to an integer if possible ,
             if not the program will catch the invalid input as not possible to transfer it and will go back to the loop
             */
            try {
                stringstream ss(input);
                ss >> Guess;  // from string to int in case the input what we looking for as integer
                if (Guess >= 1) {
                    validChoice = true; // its a valid number as we asked for end the loop
                }
                else { // not a a valid number as we asked back to loop
                    cout << "Please enter a valid integer.\n>";
                }
            }
            catch (const int& invalid_argument) {
                cout << "Please enter an integer value.\n>";
            }
        }





        return Guess;          // return the value after the user typed a valid number.
        //end method
    }


    //end class
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class MenuMain {
private:
    const int EASY = 1;
    const int MEDIUM = 2;
    const int HARD = 3;
    string playerName;
    Levels levels;
    HighScore high_Score_Alphabet;
    HighScore high_Score_Number;


public:
    MenuMain(string playerName) {
        this->playerName = playerName;
        start();
    }

    void start() {
        // showing the user the main menu

        cout << "  --------MENU--------\n" <<
            "|1-Guess the Number  |\n" <<
            "|2-Guess the Alphabet|\n" <<
            "|3-high score        |\n" <<
            "|4-Credit            |\n" <<
            "|5-Exit              |\n" <<
            "----------------------" << endl;
        switch (validChoice(5)) {
        case(1): levelListNumber();
            break;
        case(2): levelListAlpha();
            break;
        case(3): printScore();
            break;
        case(4): credit();
            break;
        case(5): exitM();
            break;
        }
        //end method
    }
    void levelListNumber() {
        // showing the user the list
        cout << "_____Guess Number MENU_____\n" <<
            "|1-Easy                   |\n" <<
            "|2-Medium                 |\n" <<
            "|3-Hard                   |\n" <<
            "|4-Return to main menu    |\n" <<
            "___________________________\n" << endl;

        // storing the score accroding to the level and putting in player object

        switch (validChoice(4)) {

        case(1): high_Score_Number.addScoreList(EASY, levels.levelEasyNumber());

            break;


        case(2): high_Score_Number.addScoreList(MEDIUM, levels.levelMediumNumber());
            break;


        case(3): high_Score_Number.addScoreList(HARD, levels.levelHardNumber());
            break;


        case(4):

            start();

            break;

        }


        // redirecting the player to guess number menu after finishing the game

        levelListNumber();
        //endmethod

    }
    void levelListAlpha() {
        // showing the user the list
        cout << "_____Guess Alphabet MENU_____\n" <<
            "|1-Easy                   |\n" <<
            "|2-Medium                 |\n" <<
            "|3-Hard                   |\n" <<
            "|4-Return to main menu    |\n" <<
            "___________________________\n" << endl;


        // storing the score accroding to the level and putting in player object
        switch (validChoice(4)) {

        case(1): high_Score_Alphabet.addScoreList(EASY, levels.levelEasyAlpha());
            break;


        case(2): high_Score_Alphabet.addScoreList(MEDIUM, levels.levelMediumAlpha());
            break;


        case(3): high_Score_Alphabet.addScoreList(HARD, levels.levelHardAlpha());
            break;


        case(4):
            start();

            break;

        }

        // redirecting the player to Guess Letter MENU after finishing the game
        levelListAlpha();

        //end method
    }
    int exitM() {

        cout << "\tAre you sure ? \n" << endl;
        cout << "    1-Yes \t    2-No\n" << endl;

        switch (validChoice(2)) {

        case(1): {
            cout << "THANK YOU FOR PLAYING OUR GAME! \n  WE HOPE YOU ENJOYED.. :)";
            exit(0);
            break;
        }

        case(2): {
            start();
            break;
        }
        }
        return 0;
        // end method
    }

    int validChoice(int number) {
        string input; //just in case we will take the input as string
        int choice = 0;
        bool validChoice = false;

        cout << "Enter your choice:\n>";
        while (!validChoice) {
            cin >> input;
            /*try,catch as i learend to  predict and examine the user input if the user didnt follow the instructions.
            first we will try to transfer the user string input to an integer if possible ,
             if not the program will catch the invalid input as not possible to transfer it and will go back to the loop
             */
            try {
                stringstream ss(input);
                ss >> choice; // from string to int in case the input what we looking for as integer
                if (choice >= 1 && choice <= number) {
                    validChoice = true; // its a valid number as we asked for end the loop
                }
                else { // not a a valid number as we asked back to loop
                    cout << "Please enter a valid choice!.\n>";
                }
            }
            catch (const int& invalid_argument) {
                cout << "Please enter an integer value.\n>";
            }
        }


        return choice;
        // end method
    }

    void credit() {


        cout << "Our project is a mobile game called \"Guessing Game,\" developed by a team of six students.\n" <<
            "The game has two modes: guessing numbers and guessing alphabet letters.\n" <<
            "        Our objective is to provide an engaging and challenging gaming experience that is suitable for all ages.\n" <<
            "        Game Development Team:\n" <<
            " -Mousa Daoud     :  (210-201-935)\n" <<
            " -Habeeb Fayez    :  (210-209-439)\n" <<
            " -Muhammad Suayb  :  (210-209-337)\n" <<
            " -Mohammad Rawass :  (210-209-959)\n" <<
            " -Omar Hamdan     :  (210-209-386)\n" <<
            " -Basel Al Najjar :  (210-209-933)\n" <<
            " -Alihan Sakarya  :  (210-209-010)\n" <<

            " Doc.Prof:\n" <<
            " -Salim Jibran Danbatta\n" <<
            " Major :\n" <<
            " B.Sc Software engineering\n" <<

            " Copyright c 2023 by Guessing Game Team.\n" <<
            "         All rights reserved.\n" << endl;

        cout << "1-Return to Main Menu \n>" << endl;

        validChoice(1);

        start();
        //end method
    }

    void printScore() {


        cout << "Player name: " << playerName << "\n MODE: 1-Guessing NUMBER: " << endl;
        cout << "--------------------------" << endl;

        cout << "EASY: \n" << endl;
        high_Score_Number.getScoreList(EASY);
        cout << "\nMEDIUM:\n" << endl;
        high_Score_Number.getScoreList(MEDIUM);
        cout << "\nHARD: \n" << endl;
        high_Score_Number.getScoreList(HARD);
        cout << "\n--------------------------" << endl;
        cout << "2-Guessing Alphabet:" << endl;
        cout << "--------------------------" << endl;
        cout << "EASY: \n" << endl;
        high_Score_Alphabet.getScoreList(EASY);
        cout << "\nMEDIUM: \n" << endl;
        high_Score_Alphabet.getScoreList(MEDIUM);
        cout << "\nHARD: \n" << endl;
        high_Score_Alphabet.getScoreList(HARD);


        cout << "\n1-Return to Main Menu" << endl;

        if (validChoice(1) == 1);
        start();



        //end method
    }
    //end class
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Guessing_Game {


public:
    void printBox(string welcomeMessage) {
        for (int i = 1; i <= welcomeMessage.length(); i++) {
            cout << "|";
        }
        cout << "\n";
    }
    void printFirstMessage() {
        cout << "O--------------------------------O" << endl;
        cout << "|| Wellcome to our Guessing Game ||" << endl;
        cout << "O--------------------------------O" << endl;
        cout << "\n Please Enter your Name to start!:\n>";
    }

};




int main() {
    Guessing_Game Start;
    string name, welcomeMessage;

    Start.printFirstMessage();
    // recieve player name from user
    cin >> name;

    welcomeMessage = "* Wellcome #" + name + "# to our Guessing Game *";
    // print a box
    Start.printBox(welcomeMessage);
    cout << welcomeMessage << endl;
    Start.printBox(welcomeMessage);


    MenuMain startGame(name);


    return 0;
}