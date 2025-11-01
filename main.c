#include <stdio.h>
#include <string.h>

#define CANDIDATE_COUNT 4
#define MAX_VOTERS 100

#define CANDIDATE1 "ALPHA"
#define CANDIDATE2 "BRAVO"
#define CANDIDATE3 "CHARLIE"
#define CANDIDATE4 "DELTA"

struct Voter {
    int id;
    char password[20];
    int hasVoted;
};

struct Voter voters[MAX_VOTERS];

int votesCount1 = 0, votesCount2 = 0, votesCount3 = 0, votesCount4 = 0, spoiledtvotes = 0;

void readVoterFile() {
    FILE *file = fopen("voters.txt", "r");
    if (!file) {
        printf("Error opening voters file.\n");
        return;
    }

    int i = 0;
    while (fscanf(file, "%d %s", &voters[i].id, voters[i].password) == 2) {
        voters[i].hasVoted = 0;
        i++;
        if (i >= MAX_VOTERS) {
            break;
        }
    }

    fclose(file);
}


int authenticateUser(int id, const char *password) {
    for (int i = 0; i < MAX_VOTERS; i++) {
        if (voters[i].id == id && strcmp(voters[i].password, password) == 0) {
            return 1;
        }
    }

    return 0; 
}

void castVote() {
    int id;
    char password[20];

    printf("\n\n ### Please enter your ID and Password ###\n");
    printf("ID: ");
    scanf("%d", &id);
    printf("Password: ");
    scanf("%s", password);

    readVoterFile(); 

    for (int i = 0; i < MAX_VOTERS; i++) {
        if (voters[i].id == id) {
            if (voters[i].hasVoted) {
                printf("\nYou have already voted. You cannot vote again.\n");
                return;
            }

            if (authenticateUser(id, password)) {
                printf("\n\n ### Please choose your Candidate ####\n\n");
                printf("\n 1. %s", CANDIDATE1);
                printf("\n 2. %s", CANDIDATE2);
                printf("\n 3. %s", CANDIDATE3);
                printf("\n 4. %s", CANDIDATE4);
                printf("\n 5. %s", "None of These");

                int choice;
                printf("\n\n Input your choice (1 - 4) : ");
                scanf("%d", &choice);

                switch (choice) {
                    case 1:
                        votesCount1++;
                        break;
                    case 2:
                        votesCount2++;
                        break;
                    case 3:
                        votesCount3++;
                        break;
                    case 4:
                        votesCount4++;
                        break;
                    case 5:
                        spoiledtvotes++;
                        break;
                    default:
                        printf("\n Error: Wrong Choice !! Please retry");
                        return;
                }

                voters[i].hasVoted = 1;

                printf("\nThanks for voting!!");
            } else {
                printf("\nIncorrect password. Access denied.\n");
            }

            return;
        }
    }

    printf("\nVoter not found. Please check your ID.\n");
}

void votesCount() {
    printf("\n\n .... Voting Statistics ....");
    printf("\n %s - %d ", CANDIDATE1, votesCount1);
    printf("\n %s - %d ", CANDIDATE2, votesCount2);
    printf("\n %s - %d ", CANDIDATE3, votesCount3);
    printf("\n %s - %d ", CANDIDATE4, votesCount4);
    printf("\n %s - %d ", "Spoiled Votes", spoiledtvotes);
}

void getLeadingCandidate() {
    printf("\n\n  .... Leading Candidate ....\n\n");
    if (votesCount1 > votesCount2 && votesCount1 > votesCount3 && votesCount1 > votesCount4)
        printf("%s", CANDIDATE1);
    else if (votesCount2 > votesCount3 && votesCount2 > votesCount4 && votesCount2 > votesCount1)
        printf("%s", CANDIDATE2);
    else if (votesCount3 > votesCount4 && votesCount3 > votesCount2 && votesCount3 > votesCount1)
        printf("%s", CANDIDATE3);
    else if (votesCount4 > votesCount1 && votesCount4 > votesCount2 && votesCount4 > votesCount3)
        printf("%s", CANDIDATE4);
    else
        printf("----- Warning !!! No-win situation----");
}

int main() {
    int choice;
    int totalVoters = 0;

    readVoterFile();

    for (int i = 0; i < MAX_VOTERS && voters[i].id != 0; i++) {
        totalVoters++;
    }

    do {
        printf("\n\n .... Welcome to Online Voting ....");
        printf("\n\n 1. Cast the Vote");
        printf("\n 2. Find Vote Count");
        printf("\n 3. Find leading Candidate");
        printf("\n 0. Exit");

        printf("\n\n Please enter your choice : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (totalVoters > 0) {
                    castVote();
                    totalVoters--;
                } else {
                    printf("\nAll votes have been cast. Exiting the voting system.\n");
                    choice = 0; 
                }
                break;
            case 2:
                votesCount();
                break;
            case 3:
                getLeadingCandidate();
                break;
            case 0:
                printf("Exiting the system");
                break;
            default:
                printf("\n Error: Invalid Choice");
        }
    } while (choice != 0);

    getchar();

    return 0;
}
