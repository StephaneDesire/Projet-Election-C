#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const int numberOfCandidates=2;
const int numberOfElectors=5;
const struct Candidate *candid_tab[numberOfCandidates];
const struct Elector *elect_tab[numberOfElectors];
int elector_position=0;

struct Administrator{
    char *firstName;
    char *lastName;
    int age;
    char *password;
};

struct Candidate{
    int number;
    char *firstName;
    char *lastName;
    int age;
    int numberOfVotes;
};

struct Elector{
    char *firstName;
    char *lastName;
    int age;
    char *password;
    bool voted;
};


struct Election{
    struct Administrator admin;
    struct Candidate *candidates[numberOfCandidates];
    struct Elector *electors[numberOfElectors];
};