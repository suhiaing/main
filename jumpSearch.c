#include<stdio.h>
#include<math.h>
//min(step,size);
int min(int a, int b){

    if(b>a){

        return a;//step

    }else{

        return b;//size

    }

}

int jumpSearch(int arr[], int size, int key){

    if(arr[0]==key){

        return 0;

    }else if(arr[size-1]==key){

        return size-1;

    }else if(arr[size-1]<key){

        return -1;

    }

    int step = (size/2);

    int previous = 0;


    while(arr[min(step, size)-1] < key){

        previous = step;

        step+=(size/2);

        if(step > size){
            step = size-step;
        }
        if(previous >= size){

            return -1;

        }
    }

    if(arr[min(step,size)-1] == key){

        return step-1;

    }
        int step2 = (step/2);

        while(step2 > (size/2)/2){
            step2 /= 2;//4
        }

        int previous2 =0;

        while(arr[min(step,step2)-1]<key){
        previous2 = step2;//4
        if(step2 > step){
            step = step2-step;
        }
        step2 +=4;//4

    }
        while (arr[previous2] < key){//8

    	    previous2++;

    	}


        	if (arr[previous2] == key){

    		    return previous2;
        }

    return -1;

}



int main(){

    int arr[]= {12,23,34,45,56,67,78,89,98,100,101,102,104,107,108,111,809};

    int size = sizeof(arr)/sizeof(arr[0]);

    int toFind=809;

    int indexNumber = jumpSearch(arr,size,toFind);

    if(indexNumber !=-1){

        printf("we found\n");

        printf("found at data:%d at indexNo:%d",arr[indexNumber],indexNumber);

    }else{

        printf("Not Found");

    }

    return 0;
}
