#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Movable.h"
#include <typeinfo>

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

		while (token != NULL)
		{
			parameters.push_back(token);
			token = strtok_s(NULL, " ", &next_token);
		}

		string command;
		try
		{
			parameters.size() == 0 ? throw command : command = parameters[0];
		}
		catch (string e)
		{
			command = e;
			cout << "No compatable command entered" << endl;
		}
		
		// implement a string tokenizer to populate the parameters vector 
		// check function strtok_s

		// as a result of the process, parameters[0] should hold your command, followed by your parameters 
		

		int x, y;
		// in the following code, consider checking for the arguments.
		// in case of too few arguments, you may remind the user the correct format

		if (command.compare("addR") == 0) {

			if (parameters.size() == 5) {

				x = stoi(parameters[1].c_str());
				y = stoi(parameters[2].c_str());
				int h = stoi(parameters[3].c_str());
				int w = stoi(parameters[4].c_str());
				Rectangle* r = new Rectangle(x, y, h, w);
				shapes.push_back(r);

				cout << r;
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
			cout << s;
		}

		if (command.compare("addC") == 0) {
			// get parameters
			x = stoi(parameters[1].c_str());
			y = stoi(parameters[2].c_str());
			int r = stoi(parameters[3].c_str());
			Circle* c = new Circle(x, y, r);
			shapes.push_back(c);
			cout << c;

		}

		else if (command.compare("scale") == 0) {
			int index = stoi(parameters[1].c_str());
			float scaleX = stof(parameters[2].c_str());
			float scaleY = stof(parameters[3].c_str());
				Shape* s = (shapes[index - 1]);

				if (dynamic_cast<Square*>(s) != NULL)
				{
					cout << "Scaling object Square...\n";
					dynamic_cast<Square*>(s)->scale(scaleX, scaleY);
				}
				else if (dynamic_cast<Rectangle*>(s) != NULL) {
					cout << "Scaling object Rectangle...\n";
					dynamic_cast<Rectangle*>(s)->scale(scaleX, scaleY);
				}
				else if (dynamic_cast<Circle*>(s) != NULL) {
					cout << "Scaling object Circle...\n";
					dynamic_cast<Circle*>(s)->scale(scaleX, scaleY);
				}

				// check what type of shape, then scale

				s->toString();
			}
			

		

		else if (command.compare("move") == 0) {
			// move object at index 
			int shapeNo = stoi(parameters[1].c_str());
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
	
	for (int i = 0; i != shapes.size(); i++)
	{
		delete shapes[i];
	}

	cout << "Press any key to continue...";
	std::getchar();
	return 0;
}