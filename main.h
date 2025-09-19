#ifndef MAIN_H
#define MAIN_H

int isString(char *chaine);
int createAdminAccount();
int createElectorAccount();
int createCandidator();
void createElection();
void vote();
void printCandidate(int number);
int saveAdmin(struct Administrator *admin);


#endif