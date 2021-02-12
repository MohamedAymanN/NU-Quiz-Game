#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

//IMPORTANT REMARk!!!: if u want to add more questions just add them in Round 2 text file and change to QUESTION_NUMBER to the required Number

//Definition for no of questions in round 2
#define QUESTION_NUMBER 11

//To Store Console Title
char windowTitle[500];

//To Store User Name
char name[20];

//Struct for storing the questions
typedef struct Question{
    char* question;
    char* choiceA;
    char* choiceB;
    char* choiceC;
    char* choiceD;
    char* correctChoice;
}QuestStruct;

//Array of Question struct
QuestStruct Round2[QUESTION_NUMBER];

//Function for maximizing the console window
void MaximizeOutputWindow(void)
{
    GetConsoleTitleA( windowTitle, 500 );

    HWND consoleInst = FindWindowA( NULL, windowTitle );
    ShowWindow(consoleInst, SW_MAXIMIZE);
}

//Function for restoring the console window
void RestoreOutputWindow(void)
{
    GetConsoleTitleA( windowTitle, 500 );

    HWND consoleInst = FindWindowA( NULL, windowTitle );
    ShowWindow(consoleInst, SW_RESTORE);
}

//Function responsible for Intro Script
void CreateIntroScript(){
    printf(" _________  ___  ___  _______           ________   ___  ___          ________  ___  ___  ___  ________          ________  ________  _____ ______   _______    \n");
    printf("|\\\\___   ___\\\\  \\|\\  \\|\\  ___ \\         |\\   ___  \\|\\  \\|\\  \\        |\\   __  \\|\\  \\|\\  \\|\\  \\|\\_____  \\        |\\   ____\\|\\   __  \\|\\   _ \\  _   \\|\\  ___ \\     \n");
    printf("\\|___ \\  \\_\\ \\  \\\\\\  \\ \\   __/|        \\ \\  \\\\ \\  \\ \\  \\\\\\  \\       \\ \\  \\|\\  \\ \\  \\\\\\  \\ \\  \\\\|___/  /|       \\ \\  \\___|\\ \\  \\|\\  \\ \\  \\\\\\__\\ \\  \\ \\   __/|    \n");
    printf("     \\ \\  \\ \\ \\   __  \\ \\  \\_|/__       \\ \\  \\\\ \\  \\ \\  \\\\\\  \\       \\ \\  \\\\\\  \\ \\  \\\\\\  \\ \\  \\   /  / /        \\ \\  \\  __\\ \\   __  \\ \\  \\\\|__| \\  \\ \\  \\_|/__  \n");
    printf("      \\ \\  \\ \\ \\  \\ \\  \\ \\  \\_|\\ \\       \\ \\  \\\\ \\  \\ \\  \\\\\\  \\       \\ \\  \\\\\\  \\ \\  \\\\\\  \\ \\  \\ /  /_/__        \\ \\  \\|\\  \\ \\  \\ \\  \\ \\  \\    \\ \\  \\ \\  \\_|\\ \\ \n");
    printf("       \\ \\__\\ \\ \\__\\ \\__\\ \\_______\\       \\ \\__\\\\ \\__\\ \\_______\\       \\ \\_____  \\ \\_______\\ \\__\\\\________\\       \\ \\_______\\ \\__\\ \\__\\ \\__\\    \\ \\__\\ \\_______\\ \n");
    printf("        \\|__|  \\|__|\\|__|\\|_______|        \\|__| \\|__|\\|_______|        \\|___| \\__\\|_______|\\|__|\\|_______|        \\|_______|\\|__|\\|__|\\|__|     \\|__|\\|_______| \n");
    printf("                                                                              \\|__|                                                                             \n");

    printf("\n ---> Hello and Welcome to the first ever NU QUIZ GAME!!!\n ---> Please Enter Your Name To Begin\n ---> Name: ");
    scanf("%s",&name);
    printf(" ---> Welcome %s to the Game the rules are as follows:\n ---> You will face 2 Rounds: 1) The first round is the warm-up round, you MUST solve 2 out of the 3 questions to qualify to the next round");
    printf("                                                                                                      2) The second round is the round were you will be answered automatically and reward with $100,000 per right answer\n\n");
    printf(" ---> You will be victorious when you pile 1 million dollars\n ---> And for Each Question there is 4 choices for you to choose from smartly A,B,C,D\n");
}

void CreateEndScript(){
    printf("You Have Won Congratulations!!!!\n");
    Sleep(500);
    printf(" .----------------. .----------------. .-----------------..-----------------..----------------. .----------------. \n");
    Sleep(500);
    printf("| .--------------. | .--------------. | .--------------. | .--------------. | .--------------. | .--------------. |\n");
    Sleep(500);
    printf("| | _____  _____ | | |     _____    | | | ____  _____  | | | ____  _____  | | |  _________   | | |  _______     | |\n");
    Sleep(500);
    printf("| ||_   _||_   _|| | |    |_   _|   | | ||_   \|_   _|  | | ||_   \|_   _|  | | | |_   ___  |  | | | |_   __ \\    | |\n");
    Sleep(500);
    printf("| |  | | /\\ | |  | | |      | |     | | |  |   \\ | |   | | |  |   \\ | |   | | |   | |_  \\_|  | | |   | |__) |   | |\n");
    Sleep(500);
    printf("| |  | |/  \\| |  | | |      | |     | | |  | |\\ \\| |   | | |  | |\\ \\| |   | | |   |  _|  _   | | |   |  __ /    | |\n");
    Sleep(500);
    printf("| |  |   /\\   |  | | |     _| |_    | | | _| |_\\   |_  | | | _| |_\\   |_  | | |  _| |___/ |  | | |  _| |  \\ \\_  | |\n");
    Sleep(500);
    printf("| |  |__/  \\__|  | | |    |_____|   | | ||_____|\\____| | | ||_____|\\____| | | | |_________|  | | | |____| |___| | |\n");
    Sleep(500);
    printf("| |              | | |              | | |              | | |              | | |              | | |              | |\n");
    Sleep(500);
    printf("| '--------------' | '--------------' | '--------------' | '--------------' | '--------------' | '--------------' |\n");
    Sleep(500);
    printf(" '----------------' '----------------' '----------------' '----------------' '----------------' '----------------' \n");
}

//Function Responsible for creating round 2 questions
void CreateRound2(){
    FILE *round2File;
    round2File=fopen("files/questions/Round 2.txt","r");
    char line[128];
    int questionNo=0;
    while ( fgets(line, sizeof line, round2File) != NULL ){
        int counter=0;
        char *p,answer;
        char *quest[6];
        p = strtok (line,",:");
        while (p!= NULL)
        {
        quest[counter++]=p;
        p = strtok (NULL, ",:");
        }
        Round2[questionNo].question=strdup(quest[0]);
        Round2[questionNo].choiceA=strdup(quest[1]);
        Round2[questionNo].choiceB=strdup(quest[2]);
        Round2[questionNo].choiceC=strdup(quest[3]);
        Round2[questionNo].choiceD=strdup(quest[4]);
        Round2[questionNo].correctChoice=strdup(quest[5]);
        questionNo++;
    }
    fclose(round2File);
}

void AddHighscore(int round2score){
    FILE* playercoreFile;
    playercoreFile=fopen("files/scores/Player Scores.txt","a");
    fprintf(playercoreFile,"%s %d\n",name,round2score);
    fclose(playercoreFile);
}

int main()
{
    //Maximizing Window
    MaximizeOutputWindow();

    //Game Introduction Script Function Call
    CreateIntroScript();

    //Round 1
    FILE *round1File;
    round1File=fopen("files/questions/Round 1.txt","r");
    char line[128];
    int questCounter=1,score=0;
    printf(" ---> \t\t*** Round 1 Starting... ***\n");

    //Looping on the file line by line and splitting the line at the commas and adding the words to quest array
    while ( fgets(line, sizeof line, round1File) != NULL ){
        int counter=0;
        char *p,answer;

        //Array to store the questions and the choices
        char *quest[6];

        //strtok splits the line at the "," and extracts a token from it
        p = strtok (line,",:");
        while (p!= NULL) {
            quest[counter++] = p;
            p = strtok (NULL, ",:");
        }

        //Round 1 Questions Script
        printf(" ---> Question %d: %s\n",questCounter++, quest[0]);
        printf(" ---> A)%s\tB)%s\n ---> C)%s\tD)%s\n", quest[1], quest[2], quest[3], quest[4]);
        printf("Choice: ");

        //Taking the users answer
        scanf("\n%c",&answer);
        if(answer == quest[5][0] || answer == tolower(quest[5][0])){
            score++;
            printf("Correct Answer\n");
        }else{
            printf("Wrong Answer\n");
        }
    }
    fclose(round1File);

    //Checking if he solved 2 correct answers to proceed to the next round
    if(score < 2){
        printf(" ---> Sorry but you did not pass the first Round :(");
        return 0;
    }else{
        printf(" ---> WOHOOO you have came a long way, Brace Yourself for Round 2\n");
    }
    //Creating Round2 Questions
    CreateRound2();

    int round2score=0, idx=0, questionNo = 1;
    char answer;
    printf(" ---> \t\t*** Round 2 Starting... ***\n");

    //Main loop for Round 2
    while(round2score < 1000000){
        //Round 2 Questions Script
        printf(" ---> Question %d: %s\n",questionNo,Round2[idx].question);
        printf(" ---> A)%s\tB)%s\n ---> C)%s\tD)%s\n",Round2[idx].choiceA,Round2[idx].choiceB,Round2[idx].choiceC,Round2[idx].choiceD);
        printf("Choice: ");
        scanf("\n%c",&answer);

        //Checking if the answer is correct then increment the score by 1e5
        if(answer == Round2[idx].correctChoice[0] || answer == tolower(Round2[idx].correctChoice[0])){
            round2score += 100000;
            printf("Correct Answer\n");
        }else{
            printf("Wrong Answer\n");
        }

        //Asking MidGame if he wants to terminate
        if(round2score == 500000){
            printf("Do You Wish to continue or leave with %d $ (y/n)\n",round2score);
            char proceed;
            scanf("\n%c", &proceed);
            if(proceed == 'n'){
                printf("Thanks for participating in the NU QUIZ\n");
                AddHighscore(round2score);
                exit(0);
            }
        }


        //Checking if reached the final question then reset the questions index
        if(idx == QUESTION_NUMBER-1){
            idx = 0;
        }else{
            idx++;
        }
        questionNo++;
    }
    //End Game Script Function Call
    CreateEndScript();

    //Opening PlayerScore file and appending the score
    AddHighscore(round2score);

    //Restoring the console window
    RestoreOutputWindow();
    return 0;
}
