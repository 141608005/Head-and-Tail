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




#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<error.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
int main(int argc, char *argv[]){
    FILE *fp;             // file pointer
    char line[1000], ch;
    int len  = 0;//contains total number of lines or total number of bytes
    int cnt = 0;
    if(argc > 1){
	if(strcmp(argv[1], "--help"))
		 printf("Usage:- \"tail -option --number\" file_name.\n");
	exit(1);	
    }	
 	if(argc < 4){
 		printf("Usage:- \"tail -option --number\" file_name.\n");
        return 1;
    }
    // open file
    fp = fopen(argv[3],"r");
    // checking for file is exist or not
    if( fp == NULL ){
        printf("\n%s file can not be opened !!!\n",argv[1]);
        return 1;   
    }
    if(strcmp(argv[1], "-n") == 0){//lines
	    while(!feof(fp)){//getting total number of lines of the file
			fgets(line, sizeof(line), fp);
	        len++;
	    }
	    fseek(fp, 0, 0);//go to the start of file
	  	cnt = 0;
	  	while(cnt != (len - atoi(argv[2]))){//skipping unnecessary lines
	  		fgets(line, sizeof(line), fp);
	  		if(feof(fp)){
	  			return 0;
	  		}
	  		cnt++;
	  	}
	  	while(!feof(fp)){//printing required lines
			fgets(line, sizeof(line), fp);
	       	printf("%s",line); 
	    }
	}
	else if(strcmp(argv[1], "-c") == 0){//bytes
		while(!feof(fp)){//getting total number of bytes of the file
			fread(&ch, 1, 1, fp);
	        len++;
	    }
	    fseek(fp, 0, 0);//go to the start of file
	  	cnt = 1;
	  	while(cnt != (len - atoi(argv[2]))){//skipping unnecessary lines
	  		fread(&ch, 1, 1, fp);
	  		if(feof(fp)){
	  			return 0;
	  		}
	  		cnt++;
	  	}
	  	while(fread(&ch, 1, 1, fp)){//printing required lines
			printf("%c",ch); 
	    }
	}
    // close file
    fclose(fp);
    return 0;
}
