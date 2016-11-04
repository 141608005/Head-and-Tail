/*****************************************************************************
 *   This file is part of HEADNTAIL.
 *
 *  HEADNTAIL is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Foobar is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with HEADNTAIL.  If not, see <http://www.gnu.org/licenses/>.
*****************************************************************************/

//file name and number of lines must be supplied as command line argument
#include<stdio.h>
#include<fcntl.h>
#include<error.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
int main(int argc, char * argv[]){
    int cnt = 0;
     FILE *fp;             // file pointer
    char line[1000], ch;
    if(argc > 1){
	if(strcmp(argv[1], "--help"))
		 printf("Usage:- \"head -option --number\" file_name.\n");
	exit(1);	
    }	
    if(argc < 4){
 		 printf("Usage:- \"head -option --number\" file_name.\n");
        return 1;
    }
    // open file
    fp = fopen(argv[3],"r");
    // checking for file is exist or not
    if( fp == NULL ){
        printf("\n%s file can not be opened !!!\n",argv[1]);
        return 1;   
    }
    // read lines from file one by one
    if(strcmp(argv[1], "-n") == 0){//lines
	    while(!feof(fp)){
			fgets(line, sizeof(line), fp);
	        cnt++;
	        if (cnt > atoi(argv[2]))
	            break;
	 		printf("%s",line); 
			fflush(stdout);
	    }
	}
	else if(strcmp(argv[1], "-c") == 0){//bytes
		cnt = 1;
		while(fread(&ch, 1, 1, fp)){
			if(cnt > atoi(argv[2]))
				break;
			printf("%c", ch);
			cnt++;
			
		}
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
  
