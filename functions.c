#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "main.h"
#include "structures.c"
#include <stdbool.h>


int isString(char *chaine){
  bool isString=false;
   int i=0;
   int len = strlen(chaine);
   for(i=0;i<len;i++){
    if(isalpha(chaine[i])){
        isString=true;
    }
   }
   return isString;

}


/* Operations related to administrator*/
int createAdminAccount(){
    char *confirmation;
    struct Administrator *admin;
    struct Administrator administrator;
    admin = &administrator;
    printf("Welcome \n");
    printf("Please enter your lastname \n");
    scanf("%s",admin->lastName);
    if(!isString(admin->lastName)){
        printf("The lastName must be a string \n Please enter your lastName");
        scanf("%s",admin->lastName);
    }
    printf("PLease enter your firstname\n");
    scanf("%s",admin->firstName);
    if(!isString(admin->firstName)){
        printf("The lastName must be a string \n Please enter your lastName");
        scanf("%s",admin->firstName);
    }
    printf("Please enter your age\n");
    scanf("%d",&admin->age);
    
   if(admin->age<0){
    printf("Your age muste be positive \n");
    scanf("%d",&admin->age);
   }
   else if(admin->age <18 || admin->age>70){
    printf("You can't be an administrator \n");
    return 1;
   }
   else{

    printf("PLease enter a password\n");
    scanf("%s",admin->password);
    printf("Please confirm password \n");
    scanf("%s",confirmation);
    if(strcmp(confirmation,admin->password )!=0){
        printf("Password error \n PLease enter the same password \n");
         scanf("%s",confirmation);
    }
   }
return 0;
    
}

int saveAdmin(struct Administrator *admin){
    FILE *file;
    file = fopen("Administrator.txt",'w');
    if(file==NULL){
        printf("File Creation failed \n");
        return 1;
    }
    else{
        fprintf(file,"lastName: %s   firstName : %s   age: %d    password: %s" ,admin->lastName,admin->firstName, admin->age, admin->password);
        printf("Administrator saved \n");
        return 0;
    }
}


/*Operations related to Electors*/

int createElectorAccount(){
    bool voted;
    char *confirmation;
    struct Elector *elect;
    struct Elector elector;
    elect = &elector;
    printf("Welcome \n");
    printf("Please enter your lastname \n");
    scanf("%s",elect->lastName);
    if(!isString(elect->lastName)){
        printf("The lastName must be a string \n Please enter your lastName");
        scanf("%s",elect->lastName);
    }
    printf("PLease enter your firstname\n");
    scanf("%s",elect->firstName);
    if(!isString(elect->firstName)){
        printf("The lastName must be a string \n Please enter your lastName");
        scanf("%s",elect->firstName);
    }
    printf("Please enter your age\n");
    scanf("%d",&elect->age);

    
   if(elect->age<0){
    printf("Your age muste be positive \n");
    scanf("%d",&elect->age);
   }
   else if(elect->age <18 || elect->age>70){
    printf("You can't be an elector \n");
    return 1;
   }
   else{

    printf("PLease enter a password\n");
    scanf("%s",elect->password);
    printf("Please confirm password \n");
    scanf("%s",confirmation);
    if(strcmp(confirmation,elect->password )!=0){
        printf("Password error \n PLease enter the same password \n");
         scanf("%s",confirmation);
    }
   }
return 0;
    
}

int saveElect(struct Elector *elect){
    FILE *file;
    file = fopen("Elector.txt",'w');
    if(file==NULL){
        printf("File Creation failed \n");
        return 1;
    }
    else{
        fprintf(file,"lastName: %s   firstName : %s   age: %d    password: %s   voted: %d" ,elect->lastName,elect->firstName, elect->age, elect->password,elect->voted);
        printf("Elector saved \n");
        return 0;
    }
}


/*Operations related to Candidates*/

int createCandidate(){
  
    struct Candidate *candid;
    struct Candidate candidate;
    candid=&candidate;

    printf("Please specify the candidate's number");
    scanf("%d",candid->number);

    printf("PLease enter the candidate's lastName \n");
    scanf("%s" ,candid->lastName);
    if(!isString(candid->lastName)){
        printf("The candidate lastName must be a string \n PLease enter the candidate's lastname \n");
        scanf("%s" ,candid->lastName);
    }

    printf("Please enter the candidate's firstName\n");
    scanf("%s",candid->firstName);
    if(!isString(candid->firstName)){
        printf("The candidate firstName must be a string \n PLease enter the candidate's lastname \n");
        scanf("%s" ,candid->firstName);
    }

   
    printf("Please enter the candidate's age \n");
    scanf("%d",&candid->age);
    
    if(candid->age<0){
        printf("The age must be positive \n Please enter the candidate's age \n");
        scanf("%d",&candid->age);
    }

   else if(candid->age <18 || candid->age>70){
    printf("You can't be an elector \n");
    return 1;
   }
   else{
   candid->numberOfVotes=0;
   }
return 0;
}