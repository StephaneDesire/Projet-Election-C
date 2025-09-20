#ifndef MAIN_H
#define MAIN_H

int isString(char *chaine);
int createAdminAccount();
int createElectorAccount();
int createCandidate();
void createElection();
void vote(struct Candidate *candid_tab[numberOfCandidates],struct Elector *elect_tab[numberOfElectors]);
void printCandidate(struct Candidate *tab[numberOfCandidates],int number);
int saveAdmin(struct Administrator *admin);
int saveCandidate(struct Candidate *candid);


#endif