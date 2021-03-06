using namespace std;
#include <iostream>
#include <stdlib.h> //random
#include <ctype.h>
#include <string.h>
#include <time.h>

string rock = "ROCK";
string paper = "PAPER";
string scissors = "SCISSORS";
string userInput;
string cpuInput;

string verifyInput()
{
    cout << "Enter rock/paper/scissors: ";
    char userInput[256];
    cin.get(userInput, 256);
    for (int i = 0; i < strlen(userInput); i++)
        userInput[i] = toupper(userInput[i]);
    //cin >> userInput;
    //(toupper(userInput));
    if ((userInput != rock) && (userInput != paper) && (userInput != scissors))
    {
        cout << "Please enter acceptable input: rock, paper, scissors!";
    }
    return userInput;
}

//Picks a random number between 0-2, assigns rock/paper/scissors based on which random number is picked
string cpuRandom(int minRValue, int maxRValue)
{
    srand(time(0));
    static string cpuInput;
    int randomValue = rand() % maxRValue + minRValue;
    if (randomValue == 0)
    {
        cpuInput = "ROCK";
    }
    else if (randomValue == 1)
    {
        cpuInput = "PAPER";
    }
    else if (randomValue == 2)
    {
        cpuInput = "SCISSORS";
    }
    else
    {
        cpuInput = "";
    }
    return cpuInput;
}

//Checking if the user wins or not
int compete(string user, string cpu)
{
    if (user == cpu)
    {
        cout << "You chose " << user << ". CPU chose " << cpu << ". TIE!!";
    }
    else if ((user == rock) && (cpu == scissors))
    {
        cout << "You chose " << user << ". CPU chose " << cpu << ". You WIN!!";
    }
    else if ((user == scissors) && (cpu == paper))
    {
        cout << "You chose " << user << ". CPU chose " << cpu << ". You WIN!!";
    }
    else if ((user == paper) && (cpu == rock))
    {
        cout << "You chose " << user << ". CPU chose " << cpu << ". You WIN!!";
    }
    else
        cout << "You chose " << user << ". CPU chose " << cpu << ". You SUCK!!";
    return 0;
}

int main()
{
    string userInputCheck = verifyInput();  //Ask for input from user. Verify it matches rock,paper,scissors.
    string cpuInputCheck = cpuRandom(0, 3); //Random between 0-3
    if (userInputCheck != "")
    { //only do the compete function if there is a valid userInput
        int winLose = compete(userInputCheck, cpuInputCheck);
    }
}
