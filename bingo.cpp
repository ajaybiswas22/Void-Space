#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#define N 5
#define N1 1
#define N2 25

int matcharray[12],cparray[N][N],carray[N][N],plarray[N][N];

using namespace std;
 
 void hplayer(int arr[][N]);
 void wait(int);
 
int main(void)
{  
  int len=N2-N1+1,r,temp,store,a,b;
  int num[len];
 int shuffle,big=0,loc=0,bingo=0,countermatch=0,bigrow=0,bigcol=0,locrow=0,loccol=0;
 int i,j,c,d,f,g,choice,h,inp;
 char choice2; 

srand( time(NULL) );  //seed rand()
  top:
  	system("cls");
  cout<<"\t\t\t\t\t\t\t\t\t BINGO GAME \n";
  
  for(i=0;i<5;i++)
  {
    for(j=0;j<5;j++) 
  	plarray[i][j]=0;
  }
  
  cout<<"Enter your Bingo Arrangement\n";
  
  for(i=0;i<N;i++)
   {
   	 for(j=0;j<N;j++) 
        {  
           abovea:
		  cin>>inp;
		  for(a=0;a<N;a++)
		  {
		  	for(b=0;b<N;b++)
		  	{
			  if(inp==plarray[a][b]||inp>25)
			  {
			  	cout<<" Try again\n";
			  	goto abovea;
			  }
		  	
		     }
           }
          	 plarray[i][j]=inp;
      }  
       
		cout<<"\n"; 
   }
   system("cls");
  	
	bingo=0;                           // Ensuring all value to 0 for playing again
    loc=0;
   big=0;
   bigrow=0;
   bigcol=0;
   locrow=0;
   loccol=0;
   choice=0;
   countermatch=0;
  
   
  // BINGO SHUFFLING ALGORITHM
   
 for( temp=0,i=N1; temp<len; i++,temp++ )
     
   num[temp] = i;
    
   
 //Fisher–Yates shuffle algorithm
    
for( i=len-1; i>0; i-- )
{
        r = rand()%i;
   
     temp = num[i];
       
 num[i] = num[r];
      
  num[r] = temp;
    
}
  i=0;
   for(a=0;a<N;a++)
{
     for( b=0;b<N;b++ )
    {
      carray[a][b]=num[i];
      i++;
    }
}


    for(i=0;i<N;i++)                  // Creating a copy of original computer bingo algorithm                
     {
       for(j=0;j<N;j++)
        cparray[i][j]=carray[i][j];
     }

   cout<<" Select who plays first 1. Human 2. Computer : ";
   cin>>choice;
     if(choice==1)
      hplayer(carray);
    
	 else
     {
       if(carray[N/2][N/2]!=100)
        {
         store=carray[N/2][N/2];
         cout<<"Comp = "<<carray[N/2][N/2]<<"\n";
         carray[N/2][N/2]=100;
        }
       else
        {
          for(i=0;i<N;i++)
          { 
            for(j=0;j<N;j++)
            {
            	 if(carray[i][j]!=100)
            	 {   
            	     store=carray[i][j];
            	 	 cout<<"Comp = "<<carray[i][j]<<"\n";
            	 	 carray[i][j]=100;
            	 	 goto down;
				 }
			}
		  }
        }
          down:
          	 
			   for(a=0;a<N;a++)                      // Human Bingo Algorithm getting comp input
     {
        for(b=0;b<N;b++)
         {
           if(plarray[a][b]==store)
             { 
               
			   plarray[a][b]=100;			   
               break;
             }
        
         }
     }
          	hplayer(carray);
 }
     // If choice was 1

   if(choice==1&&carray[N/2][N/2]!=100)
    { 
     store=carray[N/2][N/2];
     cout<<"Comp = "<<carray[N/2][N/2]<<"\n";
     carray[N/2][N/2]=100;
      
	  for(a=0;a<N;a++)                      // Human Bingo Algorithm getting comp input
     {
        for(b=0;b<N;b++)
         {
           if(plarray[a][b]==store)
             { 
               
			   plarray[a][b]=100;			   
               break;
             }
        
         }
     }
     hplayer(carray);
   
    }
   else if(choice==1&&carray[N/2][N/2]==100)
    {
         for(i=0;i<N;i++)
          { 
            for(j=0;j<N;j++)
            {
            	 if(carray[i][j]!=100)
            	 {
            	 	  store=carray[i][j];
					  cout<<"Comp = "<<carray[i][j]<<"\n";
            	 	 carray[i][j]=100;
            	 	goto out;
				 }
			}
		  }
       out:
       	 for(a=0;a<N;a++)                      // Human Bingo Algorithm getting comp input
     {
        for(b=0;b<N;b++)
         {
           if(plarray[a][b]==store)
             { 
               
			   plarray[a][b]=100;			   
               break;
             }
        
         }
     }
	   hplayer(carray);  
    }
      
        for(a=0;a<N;a++)                      // Human Bingo Algorithm getting comp input
     {
        for(b=0;b<N;b++)
         {
           if(plarray[a][b]==store)
             { 
               
			   plarray[a][b]=100;			   
               break;
             }
        
         }
     }
  
    // SCANNING FOR ELEMENTS 


   beg:
    for(c=0;c<N;c++)
     { 
       for(d=0;d<N;d++)
        {
          if(carray[c][d]==100)
            countermatch++;
        }
          matcharray[c]=countermatch;
          if(countermatch==5)
           bingo++;
          countermatch=0;
     }
    for(c=0;c<N;c++)
     {
      for(d=0;d<N;d++)
       { if(carray[d][c]==100)
          countermatch++;
       }
          matcharray[5+c]=countermatch;
           if(countermatch==5)
           bingo++;
          countermatch=0;
     }

    for(c=0,d=0;c<N,d<N;c++,d++)
       {
        if(carray[c][d]==100)
        countermatch++;
       }
     matcharray[10]=countermatch;
      if(countermatch==5)
      bingo++;
     countermatch=0;

    for(c=0,d=N-1;c<N,d>=0;c++,d--)
       {
        if(carray[c][d]==100)
        countermatch++;
       }
     matcharray[11]=countermatch;
      if(countermatch==5)
      bingo++;
     countermatch=0;

    // Finding Biggest set of rows, columns and Diagonals

  for(c=0;c<=11;c++)
    { 
        if(matcharray[c]>big&&matcharray[c]<5)
          {
            big=matcharray[c];
            loc=c;
          }
    }
    
    for(c=0;c<5;c++)
    { 
        if(matcharray[c]>bigrow&&matcharray[c]<5)
          {
            bigrow=matcharray[c];
            locrow=c;
          }
    }
    
    for(c=N;c<10;c++)
    { 
        if(matcharray[c]>bigcol&&matcharray[c]<5)
          {
            bigcol=matcharray[c];
            loccol=c;
          }
    }
     if(bingo>=5)
      {
        cout<<"\nComp Bingo\n";
        goto END;
      }
    
    bingo=0;            // Setting Bingo Back to Normal

                       //   Remove to check cout<<"loc ="<<loc<<" loc row = "<<locrow<<" loc col "<<loccol<<"\n";
                          
   // If the biggest collection is row wise
   
   if(loc>=0&&loc<N)
     {
	   if(carray[loc][loccol-N]!=100)
	      { 
	         store=carray[loc][loccol-N];
	         cout<<"Comp = "<<carray[loc][loccol-N]<<"\n";
	         carray[loc][loccol-N]=100;
		   } 
		else if(carray[loc][loccol-N]==100)
		  {
		  	 for(f=loc,g=0;g<N;g++)
		  	   {
		  	   	 if(carray[f][g]!=100)
		  	   	   { 
		  	   	     store=carray[f][g];
		  	   	     cout<<"Comp = "<<carray[f][g]<<"\n";
		  	   	     carray[f][g]=100;
		  	   	     break;
					}
			   }
		  }
	
	 }
	

   // If the biggest collection is column wise
    
    else if(loc>=N&&loc<(N*2))
       {
	   if(carray[locrow][loc-N]!=100)
	      { 
	         store=carray[locrow][loc-N];
	         cout<<"Comp = "<<carray[locrow][loc-N]<<"\n";
	         carray[locrow][loc-N]=100;
		   } 
		else if(carray[locrow][loc-N]==100)
		  {
		  	 for(f=0,g=loc-N;f<N;f++)
		  	   {
		  	   	 if(carray[f][g]!=100)
		  	   	   { 
		  	   	     store=carray[f][g];
		  	   	     cout<<"Comp = "<<carray[f][g]<<"\n";
		  	   	     carray[f][g]=100;
		  	   	     break;
					}
			   }
		  }

	 }

   // If the biggest collection is principal Diagonal wise

  else if(loc==10)
    {
      for(f=0,g=0;f<N;f++,g++)
        {
         if(carray[f][g]!=100)
          {
          	store=carray[f][g];
            cout<<"Comp = "<<carray[f][g]<<"\n";
            carray[f][g]=100;
           break; 
          }
        }
      
    } 

  // If the biggest collection is non principal Diagonal wise
  
  else if(loc==11)
    {
      for(f=0,g=N-1;f<N,g>=0;f++,g--)
        {
         if(carray[f][g]!=100)
          { 
            store=carray[f][g];
            cout<<"Comp = "<<carray[f][g]<<"\n";
            carray[f][g]=100;
            break;
          }
        }
        
    }  
    
    for(a=0;a<N;a++)                      // Human Bingo Algorithm getting comp input
     {
        for(b=0;b<N;b++)
         {
           if(plarray[a][b]==store)
             { 
               
			   plarray[a][b]=100;			   
               break;
             }
        
         }
     }
   
   //   Resetting all checking values to 0
   loc=0;
   big=0;
   bigrow=0;
   bigcol=0;
   locrow=0;
   loccol=0;
   
  hplayer(carray);
goto beg;
   // End of while loop

END:

       cout<<"\n";
for(i=0;i<N;i++)                  // Displaying a copy of original computer bingo algorithm                
     {
       for(j=0;j<N;j++)
       {
          if(cparray[i][j]<10)	
          cout<<" "<<cparray[i][j]<<" ";
          else
          cout<<cparray[i][j]<<" ";
       }
        cout<<"\n";
     }

       cout<<"\n";
for(i=0;i<N;i++)                  // Displaying original computer bingo algorithm                
{
       for(j=0;j<N;j++)
    {
	  if(carray[i][j]==100)
	  cout<<" X"<<" ";            // Displaying 'X' instead of 100 for marked ones
        else if(carray[i][j]<10)
        cout<<" "<<carray[i][j]<<" ";
        else 
        cout<<carray[i][j]<<" ";
    }
        cout<<"\n";
    
}

cout<<"\nPlay Again ? ( Y or N ) :";
cin>>choice2;
if(choice2=='Y'||choice2=='y')
goto top;

return 0;
}

void wait(int seconds)
{
	clock_t endwait;
	endwait=clock()+seconds*CLOCKS_PER_SEC;
	 while(clock()<endwait){}
	
}

 void hplayer(int arr[][N])
  { 
   int number,a,b,flag=0,pbingo,i,j,hbingo=0,hloc=0,hbig=0,hbigrow=0,hbigcol=0,hlocrow=0,hloccol=0,hcountermatch=0;
   int c,d,hmatcharray[12],timetowait=1;
   
   again:                   // If wrong number is input
   
   wait(timetowait);
   system("cls");
   cout<<"\n";
   for(i=0;i<N;i++)
   {
   	 for(j=0;j<N;j++)
   	 {
   	 	 if(plarray[i][j]==100)
   	 	 cout<<" X\t";
		 else if(plarray[i][j]<10)
		 cout<<" "<<plarray[i][j]<<"\t";
         else
		 cout<<plarray[i][j]<<"\t";
	 }
	 cout<<"\n\n\n\n";
   }	
   cout<<"\n";
   cout<<"Enter Number ";
   cin>>number;
   
   for(a=0;a<N;a++)                    // Computer Bingo algorithm
     {
        for(b=0;b<N;b++)
         {
           if(number==arr[a][b]&&number<=(N*N))
             { 
               
			   arr[a][b]=100;
			   flag=1;
               break;
             }
        
         }
     }
    
	 if(flag==0)
   {
   cout<<"Invalid! Again ";
   goto again;
   }
   
     for(a=0;a<N;a++)                      // Human Bingo Algorithm
     {
        for(b=0;b<N;b++)
         {
           if(plarray[a][b]==number)
             { 
               
			   plarray[a][b]=100;			   
               break;
             }
        
         }
     }
   
    for(c=0;c<N;c++)
     { 
       for(d=0;d<N;d++)
        {
          if(plarray[c][d]==100)
            hcountermatch++;
        }
          hmatcharray[c]=hcountermatch;
          if(hcountermatch==5)
           hbingo++;
          hcountermatch=0;
     }
    for(c=0;c<N;c++)
     {
      for(d=0;d<N;d++)
       { if(plarray[d][c]==100)
          hcountermatch++;
       }
          hmatcharray[5+c]=hcountermatch;
           if(hcountermatch==5)
           hbingo++;
          hcountermatch=0;
     }

    for(c=0,d=0;c<N,d<N;c++,d++)
       {
        if(plarray[c][d]==100)
        hcountermatch++;
       }
     hmatcharray[10]=hcountermatch;
      if(hcountermatch==5)
      hbingo++;
     hcountermatch=0;

    for(c=0,d=N-1;c<N,d>=0;c++,d--)
       {
        if(plarray[c][d]==100)
        hcountermatch++;
       }
     hmatcharray[11]=hcountermatch;
      if(hcountermatch==5)
	   hbingo++;
     hcountermatch=0;

    // Finding Biggest set of rows, columns and Diagonals

  for(c=0;c<=11;c++)
    { 
        if(hmatcharray[c]>hbig&&hmatcharray[c]<5)
          {
            hbig=hmatcharray[c];
            hloc=c;
          }
    }
    
    for(c=0;c<5;c++)
    { 
        if(hmatcharray[c]>hbigrow&&hmatcharray[c]<5)
          {
            hbigrow=hmatcharray[c];
            hlocrow=c;
          }
    }
    
    for(c=N;c<10;c++)
    { 
        if(hmatcharray[c]>hbigcol&&hmatcharray[c]<5)
          {
            hbigcol=hmatcharray[c];
            hloccol=c;
          }
    }
     if(hbingo>=5)
      {
        cout<<"\nPlayer Bingo\n";
      }
    
   	hbingo=0;                           // Ensuring all value to 0 for playing again
    hloc=0;
   hbig=0;
   hbigrow=0;
   hbigcol=0;
   hlocrow=0;
   hloccol=0;
   hcountermatch=0;
   
   flag=0;
   return;

  }
    
   
                 
