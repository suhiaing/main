#include "stdio.h"
#include "stdlib.h"
#define SIZE 5
// struct Users{
//     char emailAddress[30];
// };
// struct Users info[SIZE];

char standardEmail[30] = "@gmail.com";
int emailChecking(char arr[30]);
//void Register();
int main() {
    //Register();
    char arr[30] = "suhlaingthin@gmail.com";
    emailChecking(arr);

     return 0;
}

int Log =0;
int emailChecking(char arr[30]){
  int lastIndex=0;
    while(arr[lastIndex] != '\0'){
        lastIndex++;
    }
    lastIndex--;
    if(lastIndex < 13){
        printf("Invailded emailAddress.\n");
        return 0;
    }
    int atSignCheck =-1;
    int atSignCheck2 =-1;
    for(int j=0;j<lastIndex;j++){
        atSignCheck++;
        atSignCheck2++;
            if(arr[j] == '@'){
                break;
            }
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
    if(eISame < 9 ){
    printf("Invailded emailAddress\n");
    }
    Log =0;
    if(eISame == (lastIndex - atSignCheck2)){
        Log = 1;
        printf("your email is right\n");
    }
    return Log;
}

// void Register(){
//     for(int i=0;i<SIZE;i++){
//         int emailright=0;
//         while(emailright<1){
//             printf("Please enter your emailAddress.You can use letters, numbers & periods.\nEnter emailAddress:");
//             fgets(info[i].emailAddress, 30, stdin);
//             emailright = emailChecking(info[i].emailAddress);
//         }
//     }
// }
