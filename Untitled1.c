#include "stdio.h"
#include "stdlib.h"
#define SIZE 3
struct Users{
    char userName;
    char emailAddress[50];
    char passWord[50];
};
struct Users info[SIZE];

int emailChecking(char arr[50]);
int passChecking(char arr[50]);
void Register();
int main() {
    Register();
     return 0;
}


char standardEmail[10] = "@gmail.com";
int LogE =0;
int emailChecking(char arr[50]){
    int lastIndex=0;
  //lastIndex = charCounting(arr[50]);
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
    if(i < 9){
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
    if(symbolTest > 1 && numberTest > 1){
        if(captitalTest >1 && alphabetTest >1){
            LogP++;
            printf("Your passWord is available.\n");
        }else{
            printf("Invailded passWord(no captitalTest & alphabetTest)\n");
        }
    }else{
        printf("Invailded passWord2(no symbolTest and numberTest)\n");
        return 0;
    }
    return LogP;
}



void Register(){
    for(int i=0;i<SIZE;i++){
        int emailright=0;
         while(emailright<1){
            printf("Please enter your emailAddress.You can use letters, numbers & periods.\nEnter emailAddress for:%d:",i);
            fgets(info[i].emailAddress, 50,stdin);
            emailright = emailChecking(info[i].emailAddress);

        }
    }
}
