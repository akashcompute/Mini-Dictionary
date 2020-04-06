/*-------------- Mini Dictionary --------------
_______________ By: Akash Kumar _____________
_________________ 11702349 __________________
___________________ K17DQ ___________________
______ Lovely Professional University _______
---------------------------------------------*/

#include <iostream>
#include <fstream>
#include <process.h>
#include <conio.h>
#include <string.h>
#include <unistd.h>
using namespace std;
//============================================================================================
	//structure to store words
struct dictionary
{
	char word[50],mean[100];
}stud;
//=============================================================================================
	//  FUNCTION TO ADD A WORD 
		void insert()
		{
			ofstream fp;
			int n;
   				fp.open("dictionary.txt", ios::app);
   				if(!fp)
   					cout<<"\nFile does not exits.";
   				else
   				{
 			cout<<"\n\t--->Enter the word : ";
 			fflush(stdin);					//to clear out standard inputs
 			gets(stud.word);
 			cout<<"\nEnter it's meaning : ";
 			fflush(stdin);					//to clear out standard inputs
 			gets(stud.mean);
 					}
 			fp.write((char *) &stud, sizeof(stud));
			fp.close();
				}
//====================================================================================
		//to display the words present
		void disp()
		{
					int j=0;
					ifstream fp;
 					fp.open("dictionary.txt",ios::in);
   					if (!fp)
    					cout<<"\nFile does not exits.\n";
   					else
   					{
 						ifstream fp1;
  						fp1.open("dictionary.txt",ios::in);
  						cout<<"\n\t******************** Words Present in Dictionary ********************\n";
 						while (fp1.read((char *)&stud,sizeof(stud)))
 						{
							cout<<"\t"<<j+1<<"->"<<stud.word<<" ";
    						j++;
    					}
    					fp1.close();
    				}
    				fp.close();
    		}
//====================================================================================
	//    FUNCTION TO SEARCH the MEANING
void search()
{
	int n;
					ifstream fp2;
					int avlid=1;
					char wordcpy[50];
					cout<<"\nEnter the word to find meaning : ";
 					cin>>wordcpy;
  					fp2.open("dictionary.txt",ios::in);
  					if (!fp2)
    					cout<<"\nFile does not exits.\n";
  					else
					{
						while (fp2.read((char *)&stud,sizeof(stud)))
  						{
  							if (strcmp(stud.word,wordcpy)==0)
   							{
   								avlid=0;
   								cout<<"\n\t-->Meaning of the word : "<<stud.word<<"\n"<<stud.mean<<"\n";
  							}
  						}//while loop closed
  					}
  					if (avlid == 1)
  					{
 	 	 				cout<<"\nWord not available in dictionary.\n";
 	 	 				ofstream fp;
 						fp.open("dictionary.txt",ios::app);
   						if (!fp)
    						cout<<"\nFile does not exits.\n";
   						else
   						{
 	 	 					strcpy(wordcpy,stud.word);
 							cout<<"\nEnter meaning of word "<<wordcpy<<" : ";
 							fflush(stdin);					//to clear out standard inputs
 							gets(stud.mean);
 						}
 							fp.write((char *) &stud, sizeof(stud));
							fp.close();
 							cout<<"\n*****  Word successfully added to dictionary  *****\n\n";
 					}
 					fp2.close();
}
//====================================================================================
	// MAIN PROGRAM
main()
{
	system("color 0E");
	char user1[50]="akash123",pass1[]="password";
	char user[20],pass[9];
	cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t   Enter username : ";
	cin>>user;
	cout<<"\n\t\t\t\t\t   Enter password : ";
	for(int i=0;i<8;i++)
	{
		pass[i]=getch();
		cout<<"*";
	}
	if(strcmp(pass1,pass)==0 && strcmp(user1,user)==0)
	{
 		int c, emp,n;
 		do
 		{	
 			system("cls");
		 	printf("\n\n\n\t\t\t\t  -------------- Mini Dictionary --------------\n");
			printf("\t\t\t\t  _______________ By: Akash Kumar _____________\n");
			printf("\t\t\t\t  _________________ 11702349 __________________\n");
			printf("\t\t\t\t  ___________________ K17DQ ___________________\n");
			printf("\t\t\t\t  _______ Lovely Professional University ______\n");
			printf("\t\t\t\t  ---------------------------------------------");
			cout<<"\n\tPress Enter to continue...";
  			getche();	
			system("cls");											//Menu driven program
 			cout<<"\n\n\n\t\t\t\t\t\tDate :"<<__DATE__;
  			cout<<"\n\t\t\t\t\t\tTime :"<<__TIME__;
  			cout<<"\n\n\t*********************************  Welcome to Mini Dictionary  *******************************";
  			cout<<"\n\t\t\tPress 1 to Add a word in dictionary.";
			cout<<"\n\t\t\tPress 2 to Search the meaning of a word.";
			cout<<"\n\t\t\tPress 3 to display all the words prersent in dictionary.";
			cout<<"\n\t\t\tPress 0 to Exit";
  			cout<<"\n\t**********************************************************************************************\n";
  			cout<<"\nEnter your choice : ";
  			cin>>c;
  			cout<<"\n";
  			switch (c)
  			{
  			case 1:
  				cout<<"\n\t****************************** Welcome to add a word **********************************";
 				insert();
   			break;
  			case 2:
  				search();
	   	 	break;
	   	 	case 3:
	   	 		disp();
	   	 		cout<<"\n\n\tPress Enter to continue...";
  				getche();
	   	 	break;
  			case 0:
   				{
					cout<<"\n\n\t\tClosing..........."; sleep(1);
					cout<<"\n\t\t\t\t\t\t............Closing\n"; sleep(1);
					cout<<"\n\t\t\t\t*************** THANK YOU ***************\n"; sleep(1); exit(0);
				}	
   			break;
  			default:
 	  			cout<<"\n**************** Your choice is wrong ****************\nPlease try again...\n";
   			break;
  			}
 		}while (c != 0);
	}
	else if(strcmp(pass1,pass)!=0 || strcmp(user1,user)!=0)
		cout<<"\n\n\t\tSorry wrong username or password.";
	getch();
}
