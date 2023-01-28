
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define SIZE 5
struct Users{
    char name[50];
    int age;
    int id;
    char emailAddress[50];
    char passWord[50];
};

struct Users info[SIZE];
int indeX=0;
int emailChecking(char arr[50]);
int passChecking(char arr[50]);
int eTaken(char arr[50]);
int NTaken(char arr[50]);
int nNotFound=0;
int emailright=0;
int eNotFound=0;
int passRight=0;
void Register();
void recordingAllDataToFile();
int globalIndex =0;
void loadingAllDataFromFile();
void printingAllData();
void lobby();
int main() {
    loadingAllDataFromFile();
    printingAllData();
    lobby();
     return 0;
}


void loadingAllDataFromFile(){
    FILE *fptr = fopen("dipDB.txt","r");
    if(fptr == NULL){
        printf("Error at loading!\n");
    }else{
        for(int gcc=0; gcc<SIZE ; gcc++){
            fscanf(fptr,"%d%d%s%s%s",&info[gcc].id , &info[gcc].age, &info[gcc].name,&info[gcc].emailAddress,&info[gcc].passWord);
            if(info[gcc].name[0] == '\0'){
                break;
            }
            globalIndex++;
        }
    }
}

void printingAllData(){
    loadingAllDataFromFile();
    for(int gcc=0; gcc<globalIndex ; gcc++ ){
        printf("id:%d - name:%s - age:%d - email:%s - password:%s\n",info[gcc].id,info[gcc].name , info[gcc].age , info[gcc].emailAddress , info[gcc].passWord);
        if(info[gcc].name[0] == '\0'){
            break;
        }
    }
}

void lobby(){
    int lob=0;
    printf("This is Lobby Sector!\n");
    printf("Press 1 to Register:\n");
    printf("Press 2 to Login:\n");
    printf("Press 3 to Exit:");

    scanf(" %d",&lob);

    if(lob == 1){
        Register();
    } else if(lob == 2){
        login();
    } else if(lob == 3){
        recordingAllDataToFile();
        exit(1);
    } else{
        printf("Invalid Option!\n");
        lobby();
    }

    printingAllData();
    exit(1);
}

int NFound =-1;
int NTaken(char arr[50]){
    int sameCount=0;
    int userInputArrIndex = 0;
    while(arr[userInputArrIndex] != '\0'){
        userInputArrIndex++;
    }
    userInputArrIndex--;
    for(int i=0; i<SIZE ; i++){
        int infoIndex = 0;
        while(info[i].name[infoIndex] != '\0'){
            infoIndex++;
        }
        infoIndex--;
        if( infoIndex == userInputArrIndex){
            for(int j=0; j<infoIndex ; j++){
                if( info[i].name[j] != arr[j]){
                    break;
                } else{
                    sameCount++;
                }
            }
        }
        if( userInputArrIndex == sameCount){
             NFound = i;
            if(NFound == indeX){
                return 10;
            }else{
                printf("BUT Your name is Found at I:%d!!!\n",i);
                return 0;
            }
        }else{
            printf("Not same at I%d\n",i);
        }
    }
}


char standardEmail[10] = "@gmail.com";
int LogE =0;
int emailChecking(char arr[50]){
    int lastIndex=0;
    while(arr[lastIndex] != '\0'){
        lastIndex++;
    }
    lastIndex--;
    if(lastIndex < 13){
        printf("Invailded emailAddress.Too short.\n");
        return 0;
    }
    int atSignCheck =-1;
    int atSignCheck2 =-1;
    int symbolTest =0;
    for(int j=0;j<lastIndex;j++){
        atSignCheck++;
        atSignCheck2++;

        if(arr[j] == '@'){
           break;
        }else if(arr[j] > 32 && arr[j] < 48 ){
            symbolTest++;
        }else if(arr[j] > 90 && arr[j] < 97 ){
            symbolTest++;
        }else if(arr[j] > 122 && arr[j] < 127){
            symbolTest++;
        }else if(arr[j] > 57 && arr[j] < 65 ){
            symbolTest++;
        }
    }
    if(symbolTest>0){
        printf("Noo!! special characters are in your email.Invailded emailAddress.\n");
        return 0;
    }
    int eISame =0;
    for(int n=0;n<(lastIndex-atSignCheck2);n++){
        if(arr[atSignCheck] == standardEmail[n]){
            atSignCheck++;
            eISame++;
        }else{
            break;
        }
    }
        LogE =0;
    if(eISame < 9){
        printf("Invailded emailAddress.Not correct at 'user123@gmail.com' \n");
        return 0;
    }else if(eISame == (lastIndex - atSignCheck2)){
        LogE = 1;
        printf("Your email is available.\n");
    }
    return LogE;
}


int eFound =-1;
int eTaken(char arr[50]){
    int sameCount=0;
    int userInputArrIndex = 0;
    while(arr[userInputArrIndex] != '\0'){
        userInputArrIndex++;
    }
    userInputArrIndex--;
    for(int i=0; i<SIZE ; i++){
        int infoIndex = 0;
        while(info[i].emailAddress[infoIndex] != '\0'){
            infoIndex++;
        }
        infoIndex--;
        if( infoIndex == userInputArrIndex){
            for(int j=0; j<infoIndex ; j++){
                if( info[i].emailAddress[j] != arr[j]){
                    break;
                } else{
                    sameCount++;
                }
            }
        }
        if( userInputArrIndex == sameCount){
             eFound = i;
            if(eFound == indeX){
                return 10;
            }else{
                printf("BUT Your input is Found at I:%d!!!\n",i);
                return 0;
            }
        }else{
            printf("Not same at I%d\n",i);
        }
    }
}


int LogP =0;
int passChecking(char arr[50]){
    int i=0;
    int captitalTest =0;
    int alphabetTest =0;
    int symbolTest =0;
    int numberTest =0;
  //lastIndex = charCounting(arr[50]);
    while(arr[i] != '\0'){
        i++;
    }
    if(i < 7){
        printf("Invailded passWord1");
        return 0;
    }else{
        for(int lastIndex=0;lastIndex<i;lastIndex++){
            if(arr[lastIndex] > 32 && arr[lastIndex] < 48 ){
                symbolTest++;
            }else if(arr[lastIndex] > 90 && arr[lastIndex] < 97 ){
                symbolTest++;
            }else if(arr[lastIndex] > 122 && arr[lastIndex] < 127){
                symbolTest++;
            }else if(arr[lastIndex] > 57 && arr[lastIndex] < 65 ){
                symbolTest++;
            }else if(arr[lastIndex] > 47 && arr[lastIndex] < 58){
                numberTest++;
            }else if(arr[lastIndex] > 64 && arr[lastIndex] < 91){
                captitalTest++;
            }else if(arr[lastIndex] > 96 && arr[lastIndex] < 123){
                alphabetTest++;
            }
        }
    }
    LogP =0;
    if(symbolTest > 0 && numberTest > 0){
        if(captitalTest >0 && alphabetTest >0){
            LogP++;
            printf("Your passWord is available.\n");
        }else{
            printf("Invailded passWord(no capitalTest & alphabetTest)\n");
        }
    }else{
        printf("Invailded passWord2(no symbolTest and numberTest)\n");
        return 0;
    }
    return LogP;
}


int eLogFound =0;
void myStrCmp(char userInputChar[50]){
    eLogFound =0;
    int sameCount=0;
    int sec = charCounting(userInputChar);

    for(int i=0; i<SIZE ; i++){
        int first = charCounting(info[i].emailAddress);

        if( first == sec){

                for(int gcc=0; gcc<first ; gcc++){

                    if( info[i].emailAddress[gcc] != userInputChar[gcc]){

                        break;
                    } else{
                        sameCount++;

                    }

                }

        }
        if( sec == sameCount){
            eLogFound = i;
            break;
        }

    }

}

int charCounting(char toCount[50]){ // toCount[50] = {'w','i','n','@'gmail.com,'\0' , '\0'}
    int charCount = 0;
    for(int gcc=0; gcc<50 ; gcc++){

        if( toCount[gcc] == '\0'){
            break;
        } else{
            charCount++;
        }
    }
    return charCount;
}

void login(){
    char lEmail[50];
    int found  = -1;
    printf("This is login form:\n");

    printf("Enter your email to login:");
    fgets(lEmail, 30, stdin);

    eLogFound = -1;
    myStrCmp(lEmail);

    if(eLogFound != -1){

        printf("Welcome Sir: %s\n",info[eFound].name);

    } else{
        printf("Invalid email:\n");
        login();
    }
}


void Register(){
    indeX =globalIndex;
    do{
        info[indeX].id = indeX;
        //age generator
        info[indeX].age = rand()%65;
        if(info[indeX].age < 8){
            info[indeX].age += 10;
        }
        nNotFound=0;
        while(nNotFound != 10){
            printf("Enter Your UserName.Please don't use space...\nEnter Your UserName for Id %d:",indeX);
            //input is copied form stack overflow..sorry
            //fgets(info[indeX].name, 50, stdin);
            //if((strlen(info[indeX].name) > 0) && (info[indeX].name[strlen (info[indeX].name) - 1] == '\n')){
             //   info[indeX].name[strlen (info[indeX].name) - 1] = '\0';
            //}
            scanf("%s",&info[indeX].name);
            nNotFound = NTaken(info[indeX].name);
        }
        emailright=0;
        eNotFound=0;
        while(emailright!=1 && eNotFound != 10 ){
            printf("Please enter your emailAddress.You can use letters, numbers & periods.\nEnter emailAddress for Id %d:",indeX);
            scanf("%s",&info[indeX].emailAddress);
            emailright = emailChecking(info[indeX].emailAddress);
            if(emailright == 1){
                eNotFound = eTaken(info[indeX].emailAddress);
                if(eNotFound != 10){
                    while(eNotFound != 10){
                        printf("Please enter your emailAddress.You can use letters, numbers & periods.\nEnter emailAddress for Id %d:",indeX);
                        scanf("%s",&info[indeX].emailAddress);
                        emailright = emailChecking(info[indeX].emailAddress);
                        eNotFound = eTaken(info[indeX].emailAddress);
                    }
                }
            }
        }
        passRight =0;
        while(passRight != 1){
            printf("Please enter your passWord.\nYour passWord must have less than 8.Please Make your passWord strong.\nEnter passWord for Id %d:",indeX);
            scanf("%s",&info[indeX].passWord);
            passRight = passChecking(info[indeX].passWord);
        }
    }while(indeX < 0);
    recordingAllDataToFile();
    printingAllData();
}


 void recordingAllDataToFile(){
     FILE *fptr = fopen("dipDB.txt","w");
     if(fptr == NULL){
         printf("Error at recordingAllDataToFile fun():\n");
     } else{
        for(int gcc=0; gcc<SIZE; gcc++){
            fprintf(fptr , "%d %d %s %s %s\n",info[gcc].id , info[gcc].age , info[gcc].name , info[gcc].emailAddress  , info[gcc].passWord);
        }
        printf("Recording all data to dipDB.txt is complete!\n");
    }
     fclose(fptr);
}
