#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int data[2][10];
int testnum,result[100];
void initial();
void readfile();
void outputfile();


int main()
{
  
  readfile();
  
  outputfile();
}

void initial()
{
	for (int k=0;k<10;k++)
	  data[0][k]=data[1][k]=0;
}

void readfile()
{
  FILE* fptr;
  char tempstr[50];
  int n1,n2;
  float index1,index2;
  
  fptr=stdin;
  if (fptr==NULL)
    {
       printf("error");
       exit(0);
    }
  fscanf(fptr,"%s",tempstr);
  testnum=atoi(tempstr);
     for (int i=0;i<testnum;i++)
      {
        initial();
		fscanf(fptr,"%s",tempstr);
        n1=atoi(tempstr);
        fscanf(fptr,"%s",tempstr);
        n2=atoi(tempstr);
        index1=index2=0;
		for (int j=0;j<n1;j++)
          {
          	fscanf(fptr,"%s",tempstr);
          	data[0][atoi(tempstr)]=1;
		  }
		for (int k=0;k<n2;k++)
		  {
		  	fscanf(fptr,"%s",tempstr);
		  	data[1][atoi(tempstr)]=1;
		  }
		for (int j=0;j<10;j++)
		  {
		  	if (data[1][j]==1 && data[0][j]==1)
		  	  {
		  	  	index1++;
		  	  	index2++;
			  }
			else if (data[0][j]==1 || data [1][j]==1)
			  index2++;
		  }
        if ((index1/index2)>0.5)
          result[i]=1;
        else result[i]=0;
		
      }
    fclose(fptr);
} 


void outputfile()
{
     FILE* fptr;
     fptr=stdout;
     for (int i=0;i<testnum;i++)
       fprintf(fptr,"%d\n",result[i]);
     fclose(fptr);
}
