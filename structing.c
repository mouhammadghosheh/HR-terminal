#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//struct intializing
typedef struct recommender {
    char firstName[20];
    char lastName[20];
    char email[20];
    

}Recommender;

typedef struct developer {
    char firstName[20];
    char lastName[20];
    char Major[20];
    struct recommender *OtherRecommender1, *OtherRecommender2;
      struct developer *FirstRecommeder, *SecondRecommender;
}Developer;

//function intializing
void printCandidates(Developer*[]);
void intialize_Others(Developer*);
void intialize_Insiders(Developer*);
void printWorkers(Developer* []);
int checkIfThere(Developer* [] , char* []);
void InsertNewCandidate(int ,  Developer*);

void HireCandidate(Developer* [], Developer* [] , int);

int main() {
    int i = 0;  //array index
    int Employee_index = 0;
    const int N = 20;
    int choice;
    Developer *employees[N], *candidates[N];
  
for(int j = 0; j < N-1; ++j){ //malloc for the arrays
        employees[j] = (Developer*)malloc(sizeof(Developer));
       candidates[j] = (Developer*)malloc(sizeof(Developer));
       
   }
    employees[19]  = '\0';
    candidates[19] = '\0';

    for (int j = 0; j < 1; ++j) { //main menu
        
    
   printf("Welcome, what do you want to do?\n1. Print candidates.\n"
          "2. Print workers.\n"
          "3. Insert new Candidate.\n"
          "4. Hire candidate.\n"
          "5. Exit.\n");
   scanf("%d",&choice);

   if(choice == 1){
       printCandidates(candidates);
       j=-1;
   }
    if(choice == 2){
        printWorkers(employees);
        j=-1;
    }
    if(choice == 3){
        InsertNewCandidate(i, candidates[i]);

        j=-1;
        i++;
    }
    if(choice == 4){
        HireCandidate(candidates,employees,Employee_index);
        Employee_index++;
        j=-1;
    }
    if(choice == 5){
        for(int k = 0; k < 19;k++){
            free(candidates[k]);
            free(employees[k]);
        }
        return 0;
    }
        
    }


}
//this function checks if the entered name is in the candidate array and then puts it in the employees 
//then removes it ftom the original array
void HireCandidate(Developer* candidate[], Developer* employee[],int j) {
    int i =0;
   
    char First_Name [20];
    char Last_Name [20];
    printf("Please enter the First name of the candidate to hire him (Warning: Names are case sensetive): ");
    scanf("%s",First_Name);
    printf("Please enter the last name of that candidate: ");
    scanf("%s",Last_Name);
    while(candidate[i] != NULL){
        if(strcmp(First_Name,candidate[i]->firstName) == 0)
        if(checkIfThere(employee,First_Name) == 1)
            if(strcmp(Last_Name,candidate[i]->lastName) == 0){
                
                employee[j] = candidate[i];
                candidate[i] = NULL;   
            }
            i++;
    }
}

//this function checks if there already is a candidate of the same name in the employee array
int checkIfThere(Developer* employee[] , char* first[]){
    int i = 0;
    int flag = 1;
    while(employee[i] != NULL){
        if(strcmp(employee[i] -> firstName , first) == 0){
            flag = 0;
        }
        i++;
    }
    return flag;
}

//this function inserts a new candidate through an algorithm of questions for the user to specify that candidate
void InsertNewCandidate(int index,  Developer* p) {
    int x = 0;
 p -> OtherRecommender1 = (Developer*)malloc(sizeof(Recommender));
        p -> OtherRecommender2 = (Developer*)malloc(sizeof(Recommender));
          p -> FirstRecommeder = (Developer*)malloc(sizeof(Developer));
            p -> SecondRecommender = (Developer*)malloc(sizeof(Developer));
    char answer[20];
 printf("Please enter the candidate's first name\n");
    scanf(" %[^\n]s" , p -> firstName);
   
 printf("Please enter the candidate's last name\n");
        scanf(" %[^\n]s" , p -> lastName);
 printf("Please enter the candidate's major\n");
        scanf(" %[^\n]s" , p -> Major);
 printf("Are there any recommenders?\n");
        scanf(" %[^\n]s" , &answer);
        
        if(strcmp(answer,"yes") == 0){
            printf("Are the recommenders working in the company?\n");
                scanf(" %[^\n]s", &answer);
                    if(strcmp(answer,"yes") == 0){
                        intialize_Insiders(p);
            
 printf("Are there any other recommenders from outside the company?\n");
scanf(" %[^\n]s", &answer);
                    if(strcmp(answer,"yes") == 0)
                        intialize_Others(p);

}
   else if(strcmp(answer,"no") == 0){
       intialize_Others(p);
    }
}

return;

}
//this function is used to print all the workers with all their requiered info
void printWorkers(Developer* p[]) {
 int i = 0;
    while(p[i] != NULL){
        if(strcmp(p[i] -> firstName,"") ==0)
        break;
        printf("Worker No.%d Info:\nFirst Name: %s\nLast Name:%s\n",i+1,p[i] -> firstName, p[i]->lastName);

        i++;
        
    }
    
}
//this function is used to print all the candidates with all their requiered info
void printCandidates( Developer* p[]) {
    int i = 0;
    while(p[i] != NULL){
        if(strcmp(p[i] -> firstName,"") ==0)
        break;
        printf("Candidate No.%d Info:\nFirst Name:%s\nLast Name:%s\nMajor:%s\nFirst Recommender Name (From the company): %s %s\nMajor: %s\n",i+1,p[i]->firstName,
        p[i] -> lastName,p[i] -> Major, p[i] -> FirstRecommeder -> firstName,p[i] -> FirstRecommeder -> lastName,p[i] -> FirstRecommeder -> Major);
        printf("Second Recommender Name (From the company): %s %s\nMajor: %s\n", p[i] -> SecondRecommender -> firstName,p[i] -> FirstRecommeder -> lastName
    , p[i] -> SecondRecommender -> Major);
    printf("Third Recommender Name (Outside the company): %s %s\nEmail: %s\n",p[i]->OtherRecommender1->firstName,p[i]->OtherRecommender1->lastName
    ,p[i]->OtherRecommender1->email);
    printf("Fourth Recommender Name (Outside the company): %s %s\nEmail: %s\n",p[i]->OtherRecommender2->firstName,p[i]->OtherRecommender2->lastName
    ,p[i]->OtherRecommender2->email);
    i++;
    }
}
//this private function is used to intilize recommenders from outside the company
void intialize_Others(Developer* p){
    printf("Please enter the candidate's first recommender's first name\n");
        scanf(" %[^\n]s" , p -> OtherRecommender1 -> firstName);
       
    
    printf("Please enter the candidate's first recommender's Last name:\n");
            scanf(" %[^\n]s" , p -> OtherRecommender1 -> lastName);

    printf("Please enter the candidate's first recommender's email\n");
            scanf(" %[^\n]s" , p -> OtherRecommender1 -> email);
            
    printf("Please enter the candidate's second recommender's first name\n"); 
        scanf(" %[^\n]s" , p -> OtherRecommender2 -> firstName);
    printf("Please enter the candidate's second recommender's Last name\n"); 
        scanf(" %[^\n]s" , p -> OtherRecommender1 -> lastName);
        
        printf("Please enter the candidate's second recommender's email\n");
            scanf(" %[^\n]s" , p -> OtherRecommender2 -> email);
}
//this private function is used to intilize recommenders from inside the company
void intialize_Insiders(Developer* p){
    printf("Please enter the candidate's first recommender's first name\n");
        scanf(" %[^\n]s" , p -> FirstRecommeder -> firstName);
       
    
    printf("Please enter the candidate's first recommender's Last name:\n");
            scanf(" %[^\n]s" , p -> FirstRecommeder -> lastName);
 printf("Please enter the candidate's first recommender's Major:\n");
            scanf(" %[^\n]s" , p -> FirstRecommeder -> Major);
printf("Please enter the candidate's second recommender's first name\n"); 
        scanf(" %[^\n]s" , p -> SecondRecommender -> firstName);
printf("Please enter the candidate's second recommender's Last name\n"); 
        scanf(" %[^\n]s" , p -> SecondRecommender -> lastName);
        printf("Please enter the candidate's second recommender's Major\n"); 
        scanf(" %[^\n]s" , p -> SecondRecommender -> Major);
}



