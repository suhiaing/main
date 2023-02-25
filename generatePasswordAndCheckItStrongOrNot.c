//original project
#include <stdio.h>

#include <stdlib.h>

struct data{
    
      char password[50];
};

struct data db[5];

int strongPass=-1;

void myStrongPassword(char pass[50]);

int charCounting(char toCount[50]);

int once = -1;

void getRandomPassWord();

int main() {

    getRandomPassWord();
    
   for(int r=0;r<5;r++){
   
      strongPass=-1;

        while (strongPass == -1){
        
            myStrongPassword(db[r].password);

            if(strongPass == -1){
                
                once = r;

                getRandomPassWord();

            }else{

                printf("%s",db[r].password);

                printf("  >> Your password format for r:%d was valid and saved!\n",r);

            }

        }

    }

  return 0;

}
int charCounting(char toCount[50]){

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

void myStrongPassword(char arr[50]){

    int lastIndex=0;
    
    int special=0;
    
    int numberChar=0;
    
    int capChar=0;
    
    int smallChar=0;
    
    int pass_counter = charCounting(arr);
    
    while (strongPass == -1){
    
        if( lastIndex == pass_counter){
        
            strongPass=-1;
            
            break;
        }
        
         if(arr[lastIndex] > 32 && arr[lastIndex] < 48 ){
             
                special++;
                
        }else if(arr[lastIndex] > 90 && arr[lastIndex] < 97 ){
            
                special++;
            
        }else if(arr[lastIndex] > 122 && arr[lastIndex] < 127){
                
                special++;
        
        }else if(arr[lastIndex] > 57 && arr[lastIndex] < 65 ){
                
                special++;
            
        }else if(arr[lastIndex] > 47 && arr[lastIndex] < 58){
                
                numberChar++;
            
        }else if(arr[lastIndex] > 64 && arr[lastIndex] < 91){
                
                capChar++;
            
        }else if(arr[lastIndex] > 96 && arr[lastIndex] < 123){
                
                smallChar++;
                
        }
            
        lastIndex++;

        if( special > 0 && numberChar >0 && capChar > 0 && smallChar >0){
        
            strongPass = 1;
            
        }
    }
}
    

void getRandomPassWord(){

    if(once > -1){
    
       for(int j=0;j<10;j++){

            db[once].password[j] = rand()%127;

            if(db[once].password[j]<33){

                db[once].password[j]+=65;

            }

        } 
    }else{
        
        for(int i=0;i<5;i++){

            for(int j=0;j<10;j++){
    
                db[i].password[j] = rand()%127;
    
                if(db[i].password[j]<33){
    
                    db[i].password[j]+=65;
    
                }
    
            }
        
        }

    }

}
