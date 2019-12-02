/* ------------------------------------------------------
CMP2801M: Advanced Programming
Driver program for assignment
Fall 2019

Written by Ayse Kucukyilmaz

This file is a representative test file.
During marking, we will use the exact same notation
as provided in the brief, so make sure
you follow that guideline. Also make sure that you don't
change the main body provided to you here.
Otherwise, your code may not pass the test cases...

GOOD LUCK!

------------------------------------------------------ */

#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Movable.h"

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string userCommand;
	vector <Shape*> shapes;     // this one will hold your shapes
	vector <string> parameters; // this one will hold parameters for the commands

	

	while (userCommand.compare("exit") != 0)
	{
		
		cout << "Enter the command: ";
		getline(cin, userCommand);
		char* cstr = new char[userCommand.length() + 1];
		strcpy_s(cstr, userCommand.length() + 1, userCommand.c_str());

		char* next_token;
		char* token = strtok_s(cstr, " ", &next_token);

		while (token!=NULL)
		{
			parameters.push_back(token);
			token = strtok_s(NULL , " " , &next_token);
		}
		
		// implement a string tokenizer to populate the parameters vector 
		// check function strtok_s

		// as a result of the process, parameters[0] should hold your command, followed by your parameters 
		string command = parameters[0];

		int x, y;
		// in the following code, consider checking for the arguments.
		// in case of too few arguments, you may remind the user the correct format

		if (command.compare("addR") == 0) {

			if (parameters.size()== 5) {

				x = stoi(parameters[1].c_str());
				y = stoi(parameters[2].c_str());
				int h = stoi(parameters[3].c_str());
				int w = stoi(parameters[4].c_str());
				Rectangle* r = new Rectangle(x, y, h, w);
				shapes.push_back(r);
				r->toString();
			}
			else {
				cout << "Requires x, y, height, width as paramaters. please retry." << endl;
			}





			// cout overload here; 
		}
		
		else if (command.compare("addS") == 0) {
			// get parameters
			x = stoi(parameters[1].c_str()); 
			y = stoi(parameters[2].c_str());
			int e = stoi(parameters[3].c_str());
			Square* s = new Square(x, y, e);
			shapes.push_back(s);
			s->toString();
			 // cout overload here;
		}
		
		if (command.compare("addC") == 0) {
			// get parameters
			x = stoi(parameters[1].c_str());
			y = stoi(parameters[2].c_str());
			int r = stoi(parameters[3].c_str());
			Circle* c = new Circle(x, y, r);
			shapes.push_back(c);
			c->toString();
			// cout << c->toString();

		}
		
		else if (command.compare("scale") == 0) {
			int index = stoi(parameters[1].c_str());
			int scaleX = stoi(parameters[2].c_str());
			int scaleY = stoi(parameters[3].c_str());

			if (index-1 >= 0)
			{
				Movable* m = dynamic_cast<Movable*>(shapes[index - 1]);
				 
				m->scale(scaleX, scaleY);
				shapes[index - 1]->toString();
			}
				
				
				
				

				



			// scale object at index... the scaling needs to be isotropic in case of circle and square 
			// you may want to check if the index exists or not!

			// Multiple inhertitance is tricky! The Shape class does nto have a scale function, the Movable does!
			// As a result all your derived classes have scale functions... 
			// You may need to use type casting wisely to use polymorphic functionality!

		}
		
		else if (command.compare("move") == 0) {
			// move object at index 
			int shapeNo= stoi(parameters[1].c_str());
			int newX = stoi(parameters[2].c_str());
			int newY = stoi(parameters[3].c_str());
			// you may want to check if the index exists or not!

			// Study the following code. A Shape object is not Movable, but all derived classes are...
			// you can't automatically type cast from a Shape to a Movable, but you can force a downcasting
			Movable* m = dynamic_cast<Movable*>(shapes[shapeNo - 1]);
			m->move(newX, newY);
			
			shapes[shapeNo - 1]->toString();
		}
		else if (command.compare("display") == 0) {

			for (int i = 0; i != shapes.size(); i++)
			{
				shapes[i]->toString();
			}
			// this is not given in our example, but why don't you implement a display function which shows all objects stored in shapes?
		}
		/*
		// do any necessary postprocessing at the end of each loop...
		// yes, there is some necessary postprocessing...
		cout << endl << endl;
		*/
		parameters.clear();
	}

	cout << "Press any key to continue...";
	std::getchar();

	return 0;
}