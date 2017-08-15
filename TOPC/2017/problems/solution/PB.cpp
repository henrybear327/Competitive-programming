#include <cstdlib>
#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

void bubblesort(int *poker, int n);
int PAIR(int array[]);  
int EQUAL(int array[]);
int OUT(int i, int j); 

  
int main(int argc, char *argv[])
{
    int poker[6];
    
    int n = 6;
    int case_num;

    char out[10][12] = {"single","one pair","two pairs", "three pairs", "one triple", "two triples", "tiki", "tiki pair", "full house"};
    
    cin >> case_num;
    for (int num=0; num<case_num; num++)
	{
	  for(int i=0;i<6;i++)
        cin >> poker[i];
      
      bubblesort((int*)poker, n);               
      int pair = PAIR(poker);
      int equal = EQUAL(poker);
      int score = OUT(pair, equal);
      if (num != case_num-1) 
		 cout << out[score] <<"\n";
	  else 
		 cout << out[score];
    }
     
    return 0;
}
 
/******************************************************************************/
void bubblesort(int *poker, int n)
{
    int i, j, temp;
    for (i = n - 1; i > 0; i--)
    {
        for (j = 0; j <= i - 1; j++)
        {
            if (poker[j] < poker[j + 1])
            {
                temp = poker[j];
                poker[j] = poker[j + 1];
                poker[j + 1] = temp;
            }
        }
    }
}
 
int PAIR(int array[])   //count the number of pairs
{  
  int P=0;     
  for(int i=0; i < 6; i++)
   for(int j=i+1; j < 6; j++)
    if((array[i]-array[j])==0)P++;
    return(P);
}    

int EQUAL(int array[])  //check the maximal equal numbers
{
 int cur_count=0, max_count=0;     
  for(int i=0; i < 6; i++) {
    if(array[i] == array[i+1]) 
	  cur_count++;
	else  {
	  if (cur_count > max_count) max_count = cur_count;
	  cur_count = 0;
   }
  }
  if (cur_count > max_count)  max_count = cur_count;  
  return (max_count+1);
}

  
   
int OUT(int i, int j)
{
    int o = 0;  //default single
    
    switch(i){
    case 1: o = 1; break; // one pair
    case 2: o = 2; break; // two pairs
    case 3: if (j == 3) o = 4; //one triple 
            else o = 3;  //three pairs
            break;
    case 4: o = 8; break;  //full house
    case 6: if (j == 4) o = 6; //tiki
            else o = 5;  //two triples
            break;
    case 7: o = 7; break; //tiki pair
    }  
          
    return(o);
}
