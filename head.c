//file name and number of lines must be supplied as command line argument
 
#include<stdio.h>
#include<fcntl.h>
#include<error.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>
 
int main(int argc, char * argv[]){
    FILE *fp;             // file pointer
    char line[1000];
    int len  = 0;
    int cnt = 0; 
    if( argc < 3){
      
 
        printf("Insufficient Arguments!!!\n");
        printf("Please use \"program-name file-name N\" format.\n");
        return -1;
    }
 
    // open file
    fp = fopen(argv[1],"r");
 
    // checking for file is exist or not
    if( fp == NULL ){
        printf("\n%s file can not be opened !!!\n",argv[1]);
        return 1;   
    }
 
    // read lines from file one by one
    while(!feof(fp)){
	fgets(line, sizeof(line), fp);
        cnt++;
        if ( cnt > atoi(argv[2]) )
            break;
 
        printf("%s",line); 
	fflush(stdout);
    }
     
    // close file
    fclose(fp);
 
    return 0;
}



// output:-
//Terminal command : ./file1.txt 5
//this is line 1.
//this is line 2.
//this is line 3.
//this is line 4.
//this is line 5.
