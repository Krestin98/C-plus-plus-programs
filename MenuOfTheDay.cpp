/*Author: Krestin Ebraheem
Purpose: This program displays the menu items & their prices, based on the day the user enters */

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;

//creating struct

struct MenuItems
{
	string day = "";
	string name = "";
	int price = 0;
};


 int main()
{
	//Display menu	
	cout << "Menu of the day" << endl << endl;
	cout << "COMMAND MENU" << endl
		<< "Specify the day using the three - letter format" << endl
		<< "(mon, tue, wed, thu, fri, sat, sun)." << endl
		<< "Or, enter 'exit' to exit." << endl << endl;

	//vector of type struct to store file
	vector<MenuItems>store_file;
	
	string day;

	//Reading file
	ifstream input_file("menu.txt");
    
	//Read file and break it down in the stringstream (in order)
	//push items in vector
	if (input_file)
	{
		string line;
		istringstream ss;
		string price;

		   while (getline(input_file, line)) 
		{
			   MenuItems m_items;
			   ss.str(line);
			   
			 getline(ss, m_items.name, '\t');
			 ss >> m_items.price >> m_items.day;
	         store_file.push_back(m_items);
			 
			 //cout << m_items.name << "\t";
			 //cout << m_items.price << "\t";
			 //cout << m_items.day <<endl;

			 ss.clear();

		}
		  		
	}

		input_file.close(); //closing file


	  while (true)
	{
		 //User input
		cout << "Day:";
		getline(cin, day);
		
		//exit loop and menu
		if (day == "exit")

		{
			cout << "Bye!\n";
			break;
		}
		
		//range-based loop to check if the day is same as stored then print name and price
		//Displaying output and setting the format

	for (MenuItems x: store_file) {
		if (day == x.day)
			cout <<left << setw(20) << x.name 
				 <<right << setw(12) << x.price << "\n";
			
			//cout << x.name << "\t" << x.price << "\t "<< "\n";
	}
	   cout << endl;
		
	}
	return 0;
}

