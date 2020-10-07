#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

//Data structure used: Linear Single Linked List

/*VARIABLES & STRUCTS*/
//Fragger-type composition
struct fraggerData
{
	string name;
	string skill;
	int armor;
	int speed;
	int fragPts;				//Frag specific
	struct fraggerData *link;
} *dataF, *firstF = NULL, *lastF = NULL, *deleteF, *positionF, *tempF;

//Support-type composition
struct supportData
{
	string name;
	string skill;
	int armor;
	int speed;
	int killPts;				//Support and Tank specific
	int healPts;				//Support specific
	struct supportData *link;
} *dataS, *firstS = NULL, *lastS = NULL, *deleteS, *positionS, *tempS;

//Tank-type composition
struct tankData
{
	string name;
	string skill;
	int armor;
	int speed;
	int killPts;				//Support and Tank specific
	int dmgRed;					//Tank specific
	struct tankData *link;
} *dataT, *firstT = NULL, *lastT = NULL, *deleteT, *positionT, *tempT;

int counterF = 0;
int counterS = 0;
int counterT = 0;
int anticountF = 1;
int anticountS = 1;
int anticountT = 1;

string type;

int choiceMain;
int choiceSub;

/*FRAGGER FUNCTIONS -- ALL FUNCTIONS FOR FRAGGER-TYPE HEROES*/
//Fragger-type hero creation
int fraggerCreate()
{
	dataF = new (fraggerData);
	
	cout << "Your hero name: ";
	cin >> dataF -> name;
	
	cout << "Your hero skill: ";
	cin >> dataF -> skill;
	
	cout << "Your armor points: 1 (Fragger-type trait)" << endl;
	dataF -> armor = 1;
	
	cout << "Your speed points: ";
	cin >> dataF -> speed;
	dataF -> speed = dataF -> speed + 3;
	
	cout << "Your FRAG points: ";
	cin >> dataF -> fragPts;
	
	dataF -> link = NULL;
}

//Place as last entry in list of FRAGGER-type heroes
int fraggerAdd()
{
	fraggerCreate();
	
	if (firstF == NULL)
	{
		firstF = dataF;
		lastF = dataF;
		lastF -> link = NULL;
	}
		else
		{
			lastF -> link = dataF;
		}
		
	lastF = dataF;
	lastF -> link = NULL;
}

//Delete the selected FRAGGER-type hero
int fraggerDelete()
{
int numberF;
			
	cout << endl << endl
		 << "Select the queue number of the hero you want to delete: ";
	cin >> numberF;
	
	if (firstF == NULL)
	{
		cout << "There are no heroes of Fragger-type created yet";
		return 0;
	}
		else
		{
			if (numberF == 1)
			{
				tempF = firstF;
				firstF = firstF -> link;
				delete(tempF);
			}
				else if (numberF == anticountF)
				{
					positionF = firstF;
					
					for (int i = 0; i <= numberF; i++)
					{
						positionF = positionF -> link;
					}
					
					tempF = positionF -> link;
					positionF -> link = tempF -> link;
					delete(tempF);
				}
				
				else if (numberF == counterF)
				{
					tempF = firstF;
					
					while (tempF -> link != lastF)
					{
						tempF = tempF -> link;
					}
					
					lastF = tempF;
					tempF = lastF -> link;
					lastF -> link = NULL;
				}
		}
		
	counterF--;
}

//Display all FRAGGER-type heroes created
int fraggerView()
{
	system("CLS");
	
	cout << "Fragger-type hero list" << endl
		 << "============================================================================================" << endl
		 << "|No.	|Name		|Speed		|Armor		|Frag		|Skill		|" << endl
		 << "============================================================================================" << endl;
		 
	if (firstF == NULL)
	{
		cout << "There are no heroes of Fragger-type created yet";
		return 0;
	}
		else
		{			
			positionF = firstF;
			
			while (positionF != NULL)
			{
				cout << "|" << anticountF++ << "\t|" << positionF -> name << "\t\t|" 
					 << positionF -> speed << "\t\t|" << positionF -> armor << "\t\t|" 
					 << positionF -> fragPts << "\t\t|" << positionF -> skill << endl;
					 
				positionF = positionF -> link;
			}		
		}
	
	anticountF = 1;
}

/*SUPPORT FUNCTIONS -- ALL FUNCTIONS FOR SUPPORT-TYPE HEROES*/
//Support-type hero creation
int supportCreate()
{
	dataS = new (supportData);
	
	cout << "Your hero name: ";
	cin >> dataS -> name;
	
	cout << "Your hero skill: ";
	cin >> dataS -> skill;
	
	cout << "Your armor points: ";
	cin >> dataS -> armor;
	dataS -> armor = dataS -> armor + 2;
	
	cout << "Your speed points: ";
	cin >> dataS -> speed;
	dataS -> speed = dataS -> speed + 2;
	
	cout << "Your KILL points: ";
	cin >> dataS -> killPts;
	
	cout << "Your HEAL points: ";
	cin >> dataS -> healPts;
	
	dataS -> link = NULL;
}

//Place as last entry in list of SUPPORT-type heroes
int supportAdd()
{
	supportCreate();
	
	if (firstS == NULL)
	{
		firstS = dataS;
		lastS = dataS;
		lastS -> link = NULL;
	}
		else
		{
			lastS -> link = dataS;
		}

	lastS = dataS;
	lastS -> link = NULL;
}

//Delete the selected SUPPORT-type hero
int supportDelete()
{
int numberS;
			
	cout << endl << endl
		 << "Select the queue number of the hero you want to delete: ";
	cin >> numberS;
	
	if (firstS == NULL)
	{
		cout << "There are no heroes of Support-type created yet";
		return 0;
	}
		else
		{
			if (numberS == 1)
			{
				tempS = firstS;
				firstS = firstS -> link;
				delete(tempS);
			}
				else if (numberS == anticountS)
				{
					positionS = firstS;
					
					for (int i = 0; i <= numberS; i++)
					{
						positionS = positionS -> link;
					}
					
					tempS = positionS -> link;
					positionS -> link = tempS -> link;
					delete(tempS);
				}
				
				else if (numberS == counterS)
				{
					tempS = firstS;
					
					while (tempS -> link != lastS)
					{
						tempS = tempS -> link;
					}
					
					lastS = tempS;
					tempS = lastS -> link;
					lastS -> link = NULL;
				}
		}
		
	counterS--;
}

//Display all FRAGGER-type heroes created
int supportView()
{
	system("CLS");
	
	cout << "Support-type hero list" << endl
		 << "============================================================================================" << endl
		 << "|No.	|Name		|Speed		|Armor		|Kill		|Heal		|Skill		|" << endl
		 << "============================================================================================" << endl;
		 
	if (firstS == NULL)
	{
		cout << "There are no heroes of Support-type created yet";
		return 0;
	}
		else
		{
			positionS = firstS;
			
			while (positionS != NULL)
			{
				cout << "|" << anticountS << "\t|" << positionS -> name << "\t\t|" 
					 << positionS -> speed << "\t\t|" << positionS -> armor << "\t\t|" 
					 << positionS -> killPts << "\t\t|" << positionS -> healPts << "\t\t|"
					 << positionS -> skill << endl;
					 
				positionS = positionS -> link;
			}				
		}
		
	anticountS = 1;
}

/*TANK FUNCTIONS -- ALL FUNCTIONS FOR TANK-TYPE HEROES*/
//Tank-type hero creation
int tankCreate()
{
	dataT = new (tankData);
	
	cout << "Your hero name: ";
	cin >> dataT -> name;
	
	cout << "Your hero skill: ";
	cin >> dataT -> skill;
	
	cout << "Your armor points: ";
	cin >> dataT -> armor;
	dataT -> armor = dataT -> armor + 3;
	
	cout << "Your speed points: 1 (Tank-type trait)" << endl;
	dataT -> speed = 1;
	
	cout << "Your KILL points: ";
	cin >> dataT -> killPts;
	
	cout << "Your DAMAGE TOLERANCE points: ";
	cin >> dataT -> dmgRed;
	
	dataT -> link = NULL;
}

//Place as last entry in list of TANK-type heroes
int tankAdd()
{
	tankCreate();
	
	if (firstT == NULL)
	{
		firstT = dataT;
		lastT = dataT;
		lastT -> link = NULL;
	}
		else
		{
			lastT -> link = dataT;
		}

	lastT = dataT;
	lastT -> link = NULL;
}

//Delete the selected TANK-type hero
int tankDelete()
{
int numberT;
			
	cout << endl << endl
		 << "Select the queue number of the hero you want to delete: ";
	cin >> numberT;
	
	if (firstT == NULL)
	{
		cout << "There are no heroes of Tank-type created yet";
		return 0;
	}
		else
		{
			if (numberT == 1)
			{
				tempT = firstT;
				firstT = firstT -> link;
				delete(tempT);
			}
				else if (numberT == anticountT)
				{
					positionT = firstT;
					
					for (int i = 0; i <= numberT; i++)
					{
						positionT = positionT -> link;
					}
					
					tempT = positionT -> link;
					positionT -> link = tempT -> link;
					delete(tempT);
				}
				
				else if (numberT == counterT)
				{
					tempT = firstT;
					
					while (tempT -> link != lastT)
					{
						tempT = tempT -> link;
					}
					
					lastT = tempT;
					tempT = lastT -> link;
					lastT -> link = NULL;
				}
		}
		
	counterT--;
}

//Display all FRAGGER-type heroes created
int tankView()
{
	system("CLS");
	
	cout << "Tank-type hero list" << endl
		 << "========================================================================================================================" << endl
		 << "|No.	|Name		|Speed		|Armor		|Kill		|Damage Tolerance		|Skill		|" << endl
		 << "========================================================================================================================" << endl;
		 
	if (firstT == NULL)
	{
		cout << "There are no heroes of Tank-type created yet";
		return 0;
	}
		else
		{
			positionT = firstT;
			
			while (positionT != NULL)
			{
				cout << "|" << anticountT << "\t|" << positionT -> name << "\t\t|" 
					 << positionT -> speed << "\t\t|" << positionT -> armor << "\t\t|" 
					 << positionT -> killPts << "\t\t|" << positionT -> dmgRed << "\t\t|" 
					 << positionT -> skill << endl;
					 
				positionT = positionT -> link;
			}				
		}
		
	anticountT = 1;
}

//Main Program
int main()
{
	do
	{
		system("CLS");
		
		cout << "DOTA Hero Creation - Main Menu" << endl
			 << "==============================" << endl
			 << "1. Create hero" << endl
			 << "2. Update hero" << endl
			 << "3. Delete hero" << endl
			 << "4. View hero" << endl
			 << "5. Exit" << endl
			 << "Choice >> ";
		cin >> choiceMain;
		cout << endl;
		
		switch (choiceMain)
		{
			case 1:
			{
				do
				{
					cout << "Your hero type: ";
					cin >> type;
					cout << endl;
				}
				while (type != "Fragger" && type != "fragger" &&
					   type != "Support" && type != "support" &&
					   type != "Tank" && type != "tank");
					   
				if (type == "Fragger" || type == "fragger")
				{
					fraggerAdd();
					counterF++;
				}
					else if (type == "Support" || type == "support")
					{
						supportAdd();
						counterS++;
					}
					
					else if (type == "Tank" || type == "tank")
					{
						tankAdd();
						counterT++;
					}
					
				cout << endl;
				cout << "Hero created!";
				getch();
				break;
			}
			
			case 2:
			{
				do
				{
					system ("CLS");
					
					cout << "Choose hero type to update" << endl
						 << "==========================" << endl
						 << "1. Fragger" << endl
						 << "2. Support" << endl
						 << "3. Tank" << endl
						 << "4. Back to Main Menu" << endl
						 << "Choice >> ";
					cin >> choiceSub;
					
					switch (choiceSub)
					{
						case 1:
						{
							//fraggerView();
							//fraggerUpdate();
							break;
						}
						
						case 2:
						{
							//supportView();
							//supportUpdate();
							break;
						}
						
						case 3:
						{
							//tankView();
							//tankUpdate();
							break;
						}
						
						default:
						{
							cout << "Wrong input";
						}
					}
				}
				while (choiceSub != 4);
				break;				
			}
			
			case 3:
			{
				do
				{
					system ("CLS");
					
					cout << "Choose hero type to delete" << endl
						 << "==========================" << endl
						 << "1. Fragger" << endl
						 << "2. Support" << endl
						 << "3. Tank" << endl
						 << "4. Back to Main Menu" << endl
						 << "Choice >> ";
					cin >> choiceSub;
					
					switch (choiceSub)
					{
						case 1:
						{
							fraggerView();
							fraggerDelete();							
							cout << endl << "Hero deleted!";
							break;
						}
						
						case 2:
						{
							supportView();
							supportDelete();
							cout << endl << "Hero deleted!";
							break;
						}
						
						case 3:
						{
							tankView();
							tankDelete();
							cout << endl << "Hero deleted!";							
							break;
						}
						
						default:
						{
							cout << "Wrong input";
						}
					}
				}
				while (choiceSub != 4);
				break;				
			}
			
			case 4:
			{
				do
				{
					system ("CLS");
					
					cout << "Choose hero type to display" << endl
						 << "===========================" << endl
						 << "1. Fragger" << endl
						 << "2. Support" << endl
						 << "3. Tank" << endl
						 << "4. Back to Main Menu" << endl
						 << "Choice >> ";
					cin >> choiceSub;
					
					switch (choiceSub)
					{
						case 1:
						{
							fraggerView();
							getch();
							break;
						}
						
						case 2:
						{
							supportView();
							getch();
							break;
						}
						
						case 3:
						{
							tankView();
							getch();
							break;
						}
						
						default:
						{
							cout << "Wrong input";
						}
					}
				}
				while (choiceSub != 4);
				break;
			}
			
			case 5:
			{
				cout << "Exiting...";
				system("EXIT");
			}
			
			default:
			{
				cout << "Wrong input";
			}
		}
	}
	while (choiceMain != 5);

getch();
return 0;
}
