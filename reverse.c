/*copy a file onto another reversing each line*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#define N 20

 void reverse();
 char buffer[N];
 FILE *fp;
 FILE *infp;

/*
	main function opens both files and checks them
	then it uses fgets to go line by line and reverse each string
	by calling the reverse function */

 int main(int argc, char *argv[])
{

 	fp=fopen("temp.txt","r"); /*open the first text file and check it*/
 	if(fp==(FILE*)NULL)
	{
 		printf("Cannot open the designated file\n");
 		return;
	}

 	infp=fopen("temp2.txt","w"); /*open the second text file and check it*/
 	if(infp==(FILE*)NULL)
	{
 		printf("No designated data in file\n");
 		return;
	}
 
	while(fgets(buffer,N,fp))
	{
 		fgets(buffer,N,fp);
 		reverse(&buffer[0],&buffer[strlen(buffer)-1]);
 		fprintf(infp,"%s",buffer);
	}
 
	fclose(fp);
 	fclose(infp); 
}
 
/*
	The reverse function takes the head and the tail in the buffer
	and switches them, then decrements the tail and increments the 
	tail until they are the same or swap places. */

 void reverse(char *head, char *end)
{
  	char temp;
  	if(head>=end)
	{
  		return;
	}

 	 temp=*head;
 	 *head=*end;
 	 *end=temp;
 	 reverse(head+1,end-1);
  
 	return;
}
