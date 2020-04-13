#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "Car.h"
using namespace std;

const int NOTFOUND = -1;
//Test cases
/**Test Cases
Please select an option :

1. Show Current Inventory
2. Show Current Balance
3. Buy a Car
4. Sell a Car
5. Paint a Car
6. Load File
7. Save File
8. Quit Program
2

Showing Current Balance.
$10000.00

Please select an option :

1. Show Current Inventory
2. Show Current Balance
3. Buy a Car
4. Sell a Car
5. Paint a Car
6. Load File
7. Save File
8. Quit Program
3

Add a new car:
What is the name of the car you are buying ?
Honda
What color is the car ?
Blue
How much is the car worth ? (Be honest.)
5000
Please select an option :

1. Show Current Inventory
2. Show Current Balance
3. Buy a Car
4. Sell a Car
5. Paint a Car
6. Load File
7. Save File
8. Quit Program

Please select an option:

1. Show Current Inventory
2. Show Current Balance
3. Buy a Car
4. Sell a Car
5. Paint a Car
6. Load File
7. Save File
8. Quit Program
2

Showing Current Balance.
$10000.00

Please select an option:

1. Show Current Inventory
2. Show Current Balance
3. Buy a Car
4. Sell a Car
5. Paint a Car
6. Load File
7. Save File
8. Quit Program
3

Add a new car:
What is the name of the car you are buying?
Honda
What color is the car?
Blue
How much is the car worth? (Be honest.)
5000
Please select an option:

1. Show Current Inventory
2. Show Current Balance
3. Buy a Car
4. Sell a Car
5. Paint a Car
6. Load File
7. Save File
8. Quit Program


Please select an option:

1. Show Current Inventory
2. Show Current Balance
3. Buy a Car
4. Sell a Car
5. Paint a Car
6. Load File
7. Save File
8. Quit Program
2

Showing Current Balance.
$10000.00

Please select an option:

1. Show Current Inventory
2. Show Current Balance
3. Buy a Car
4. Sell a Car
5. Paint a Car
6. Load File
7. Save File
8. Quit Program
3

Add a new car:
What is the name of the car you are buying?
Honda
What color is the car?
Blue
How much is the car worth? (Be honest.)
5000
Please select an option:

1. Show Current Inventory
2. Show Current Balance
3. Buy a Car
4. Sell a Car
5. Paint a Car
6. Load File
7. Save File
8. Quit Program


/*

/** Searches for a car, returns -1 if not found in inventory,
otherwise returns location of car */
int findCar(vector <Car> &inventory, string name)
{
	for (int i = 0; i < inventory.size(); i++)
	{
		if (inventory[i].getName() == name) // Accesses each car in the inventory and compares to name_in
		{
			return i;
		}
	}
	return NOTFOUND;
}

/** lists the names of all car in the inventory */
void print(vector<Car> inventory)
{
	for (int i = 0; i < inventory.size(); i++)
	{
		cout << inventory[i].getName() << " " << inventory[i].getColor() << " " << inventory[i].getPrice() << endl;
	}
}

/**adds a car to the inventory if not already in it */
void addCar(vector<Car> &inventory, string newColor, double newPrice, string carToAdd, double &cash_balance)
{
	int found = findCar(inventory, carToAdd);
	if (cash_balance >= newPrice)
	{
		if (found == NOTFOUND)
		{
			Car newCar = Car(carToAdd, newColor, newPrice);
			inventory.push_back(newCar);
			cash_balance -= newPrice; // ERROR <-- Need to fix
		}
		else
		{
			cout << "You already own that car!\n"; 
		}
	}
	else
	{
		cout << "You have insufficient funds to buy this car.\n";
	}
	
}
/**removes a car from the inventory */
void removeCar(vector<Car> &inventory, string carToRemove, double &cash_balance)
{
	for (int i = 0; i < inventory.size(); i++)
	{
		if (carToRemove == inventory[i].getName())
		{
			cash_balance += inventory[i].getPrice();
			inventory.erase(inventory.begin() + i);
		}
	}
}
/** Loads info from old cars into new inventory */
void loadCar(vector<Car> &inventory, double &cash_balance)
{
	cout << "Give me the name of a file please: ";
	string file;
	cin >> file;
	ifstream input(file.c_str());

	double newPrice;
	input >> newPrice;
	newPrice += cash_balance;

	while (!input.eof())
	{
		string name, color;
		double price;
		input >> name >> color >> price;
		Car newcar = Car(name, color, price);
		inventory.push_back(newcar);
	}
	input.close();
}

/** Export a save file of the current car inventories */
void saveCar(vector<Car> inventory, double cash_balance)
{
	string saveFile;
	cout << "Please enter the name of the file you want to enter: " << endl;
	cin >> saveFile;
	ofstream out_file(saveFile);
	out_file << cash_balance << endl;
	for (int i = 0; i < inventory.size(); i++)
	{
		out_file << inventory[i].getName() << " ";
		out_file << inventory[i].getColor() << " ";
		out_file << inventory[i].getPrice() << endl;
		if (i != inventory.size() - 1)
		{
			cout << endl;


		}
		
	}
}


/** Paints the car a new color */
void paintCar(vector<Car> &inventory, string carToPaint, string changeColor)
{
	int found = findCar(inventory, carToPaint);
	if (found != NOTFOUND)
	{
		inventory[found].paint(changeColor);
	}
	else
	{
		cout << "You do not own that car.\n";
	}

}


//Prompt the user to select one of several operations
void menu()
{
	cout << "Please select an option: \n";
	cout << endl;
	cout << "1. Show Current Inventory\n";
	cout << "2. Show Current Balance\n";
	cout << "3. Buy a Car\n";
	cout << "4. Sell a Car\n";
	cout << "5. Paint a Car\n";
	cout << "6. Load File\n";
	cout << "7. Save File\n";
	cout << "8. Quit Program\n";
}



/*void buyCar(vector<string> currentInv, double cash_balance)
{
	cout << "Please enter the model you purchased.\n";
	string addCar;
	cin.ignore();
	getline(cin, addCar);

	int found = getName();

	if (found == addCar)
	{
		cout << "You already have this car!\n";
	}
	else
	{
		if (cash_balance >= getPrice());
		{
			currentInv.push_back(addCar);
			cout << "You added " << addCar << " to your inventory.\n";
			cash_balance -= getPrice();
		}
		else
		{
			cout << "You do not have enough money to buy this car!\n";
		}
	}

}

void sellCar(vector<string> currentInv, double cash_balance, string removeCar)
{
	for (int i = 0; i < currentInv.size(); i++)
	{
		if (currentInv[i] == removeCar)
		{
			currentInv.erase(currentInv.begin() + i);
		}
	}
	cash_balance += getPrice();
	cout << "Your current balance is now $ " << cash_balance << endl;
}
*/

int main()
{
	//Begin the program with a cash balance of $10,000.00
	double cash_balance = 10000.00;
	//Make a vector of cars as our inventory
	vector<Car> inventory;


	int selection;
	bool looper = true;
	do
	{
		//Display menu
		menu();
		cin >> selection;
		cout << endl;
		cin.ignore(1000, '\n');
		while (selection < 1 && selection > 8)
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cin >> selection;
		}
		if (selection == 1) 
		{
			cout << "Displaying current inventory.\n";
			for (int i = 0; i < inventory.size(); i++)
			{
				cout << inventory[i].toString() << endl;
			}

		}
		else if (selection == 2)
		{
			cout << "Showing Current Balance.\n";
			cout << fixed << setprecision(2) << "\$" << cash_balance << endl << endl;
		}
		else if (selection == 3)
		{
			cout << "Add a new car:\n";
			cout << "What is the name of the car you are buying?\n";
			string carToAdd;
			cin.sync();
			getline(cin, carToAdd);
			cout << "What color is the car?\n";
			string newColor;
			cin.sync(); // CHECK <--
			getline(cin, newColor);
			cout << "How much is the car worth? (Be honest.)\n";
			double newPrice;
			cin >> newPrice;

			addCar(inventory, newColor, newPrice, carToAdd, cash_balance);
		}
		else if (selection == 4)
		{
			cout << "Which car do you want to sell?\n";
			string carToRemove;
			getline(cin, carToRemove);
			removeCar(inventory, carToRemove, cash_balance);
		}
		else if (selection == 5)
		{
			cout << "Which car do you want to paint?\n";
			string carToPaint;
			cin.sync();
			getline(cin, carToPaint);

			cout << "What color do you want to paint the car?\n";
			string changeColor;
			cin.sync();
			getline(cin, changeColor);

			paintCar(inventory, carToPaint, changeColor); // ERROR <-- Doesn't change color

		}
		else if (selection == 6)
		{
			loadCar(inventory, cash_balance);
			cout << "Your cars have been loaded.\n";
		}
		else if (selection == 7)
		{
			saveCar(inventory, cash_balance);
			cout << "Your cars have been saved.\n";
		}
		else if (selection == 8)
		{
			cout << "Goodbye!\n";
			looper = false; //Change the looper to false to exit program.
		}
		else
		{
			cout << "Son, you betta choose a different option...\n\n"; //HAHA
		}

	} while (looper);

	system("pause");
	return 0;
}