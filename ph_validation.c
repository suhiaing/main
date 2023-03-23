#include "stdio.h"
unsigned long long int ph_no = 0;

int ph_validatin_for_int(unsigned long long int ph_toCheck);

int main(){
    printf("Enter your ph: ");
    scanf("%llu",&ph_no);

	
	int ph_checked = ph_validatin_for_int(ph_no);

	printf("ph checked is %d",ph_checked);

	return 0;
}

int ph_validatin_for_int(unsigned long long int ph_toCheck){
	
	int ph_right = 0;	
	
	if((ph_toCheck / 1000000000) == 959){
		
		ph_right =1;
		
	}	
	
	return ph_right;
}
