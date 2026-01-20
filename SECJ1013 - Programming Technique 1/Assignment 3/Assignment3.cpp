//MURSYIDAH BINTI JAHIDI (A25CS0286)
//BALQIS BATRISYA BINTI JALALUDDIN (A25CS0196)
//9 JANUARY 2026
//SET 1

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int ROW = 12;
const int COL = 7;

void displayLine(ofstream &outFile);
int findIndWinner(int sumParticipant[], int SIZE);
int findTeamWinner(int sumTeam[], int SIZE);

int main(){

    int marks[ROW][COL];
    int sumParticipant[ROW] = {0};
    int sumTeam[3] = {0};
    ofstream outFile("output.txt");
    ifstream inFile("input.txt");

    if (!inFile.is_open()){
        cout << "Sorry, input file does not exist !" << endl;
        system("pause");
        exit(1);
    }

    while(!inFile.eof()){

        for(int i = 0; i < ROW; i++){

            for(int j = 0; j < COL; j++){
                inFile >> marks[i][j];
            }

            for(int k = 2; k < COL; k++){
                sumParticipant[i] += marks[i][k];
            }

            int teamIndex = marks[i][0] - 1;
            sumTeam[teamIndex] += sumParticipant[i];
        }

        displayLine(outFile);
        outFile << left;
        outFile << setw(7) << "Id" << setw(7) << "E1" 
                << setw(7) << "E2" << setw(7) << "E3" 
                << setw(7) << "E4"  << setw(7) << "E5"
                << setw(7) << "Total" << endl;
        displayLine(outFile);

        for(int m = 0; m < 3; m++){
            outFile << "TEAM " << (m + 1) << endl;

            for(int i = 0; i < ROW; i++){
                if(marks[i][0] == (m + 1)){
                    outFile << setw(7) << marks[i][1];
                    for(int j = 2; j < COL; j++){
                    outFile << setw(7) << marks[i][j];
                    }
                    outFile << setw(7) << sumParticipant[i] << endl;
                }
            }

            outFile << setw(42) << "TOTAL" << setw(7) << sumTeam[m] << endl;

            displayLine(outFile);
        }

        int indWinner = findIndWinner(sumParticipant, ROW);
        int teamWinner = findTeamWinner(sumTeam, 3);

        outFile << endl << "Winner for Individual Category: " << marks[indWinner][1] 
        << " (Team " << marks[indWinner][0] << ")" << endl;

        outFile << "Winner for Group Category: Team " << (teamWinner + 1)
        << " (Score = " << sumTeam[teamWinner] << ")" << endl;

        inFile.close();
        outFile.close();
    } 
        return 0;
    
}

void displayLine(ofstream &outFile){
    for(int i = 0; i < 52; i++){
        outFile << "-";
    }
    outFile << endl;
}

int findIndWinner(int sumParticipant[], int SIZE){
    int highest = 0;
    int index = 0;

    for(int i = 0; i < SIZE; i++){
        if(sumParticipant[i] > highest){
            highest = sumParticipant[i];
            index = i;
        }
    }
    return index;
}

int findTeamWinner(int sumTeam[], int SIZE){
    int max = 0;
    int maxIndex = 0;

    for(int i = 0; i < SIZE; i++){
        if(sumTeam[i] > max){
            max = sumTeam[i];
            maxIndex = i;
        }
    }
    return maxIndex;
}

