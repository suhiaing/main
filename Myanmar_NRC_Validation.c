#include "stdio.h"
void nrc_validation(char nrc_toCheck[15]);
int charCounting(char toCount[50]);
int main(){
    char nrc[15] = "14/TCL(N)115930";
    nrc_validation(nrc);
    return 0;
}

int charCounting(char toCount[50]){
    int charCount = 0;
    
    while (toCount[charCount] != '\0') {
        
        charCount++;
        
    }

    return charCount;
    
}


void nrc_validation(char nrc_toCheck[15]){
    
    int nrc_right = 0;
    
    int nrc_counter = charCounting(nrc_toCheck);
    
    if(nrc_counter == 14 && nrc_toCheck[0] > '0'){
        
        char nrc_code_format_for_fourty[9] = "123456789";
        
        for(int i = 0;i<9; i++){//test for nrc code
            
            if(nrc_toCheck[0] == nrc_code_format_for_fourty[i]){
                
                if(nrc_toCheck[1] != '/'){//test for /
                    
                    break;
                    
                }
                
                if (nrc_toCheck[2] < 'A' || nrc_toCheck[2] > 'Z' || nrc_toCheck[3] < 'A' || nrc_toCheck[3] > 'Z' || nrc_toCheck[4] < 'A' || nrc_toCheck[4] > 'Z') {//test for character
                        
                    break;
                        
                }
                
                if(nrc_toCheck[5] != '(' ||nrc_toCheck[6] != 'N' ||nrc_toCheck[7] != ')'){//test for (N)
                        
                    break;
                }

                for(int d=8;d<14;d++){//test for deciaml
                                
                    if(nrc_toCheck[d] >= '0' && nrc_toCheck[d] <= '9'){
                                    
                        nrc_right++;
                                    
                    }else{
                        
                        break;
                        
                    }
                                
                }    

                break;//break for loop if found 123456789

            }
            
        }
        
    }else if(nrc_counter == 15 && nrc_toCheck[0] == '1'){
        
        if(nrc_toCheck[2] < '5'){//the biggest nrc code is 14
            
            char nrc_code_format_for_fifty[5] = "01234";
        
            for(int i = 0;i<5; i++){
              
                if(nrc_toCheck[0] == nrc_code_format_for_fifty[i]){//test for nrc code
                    
                    if(nrc_toCheck[2] != '/'){//test for /
                        
                        break;
                        
                    }
                    
                    if (nrc_toCheck[3] < 'A' || nrc_toCheck[3] > 'Z' || nrc_toCheck[4] < 'A' || nrc_toCheck[4] > 'Z' || nrc_toCheck[5] < 'A' || nrc_toCheck[5] > 'Z') {//test for character
                            
                        break;
                            
                    }
                    
                    if(nrc_toCheck[6] != '(' ||nrc_toCheck[7] != 'N' ||nrc_toCheck[8] != ')'){//test for (N)
                            
                        break;
                    }
    
                    for(int d=9;d<15;d++){//test for deciaml
                                    
                        if(nrc_toCheck[d] >= '0' && nrc_toCheck[d] <= '9'){
                                        
                            nrc_right++;
                                        
                        }else{
                            
                            break;
                            
                        }
                                    
                    }    
    
                break;//break for loop if found 01234
    
                }
                
            }
        
        }
     }
    
    
    if(nrc_right == 6){
                            
        printf("your nrc format is valid;");
    }else{
        
        printf("your nrc format is not valid;");
        
    }
    
}
