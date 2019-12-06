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
	vector <Shape*> shapes;   
	vector <string> parameters; 

	// present user with possible commands.
	cout << "Command list:\n"
		<< "addR(int X,  int Y, float height, float width)\n"
		<< "addS(int X, int Y, float edge)\n"
		<< "addC(int X, int Y, float radius\n"
		<< "move(int object-location, int new-X, int new-Y)\n"
		<< "scale(int object-location, float scale-X, float scale-Y)\n"
		<< "display()\n" << endl;


	while (userCommand.compare("exit") != 0)
	{
		cout << "Enter the command: ";
		getline(cin, userCommand);
		char* cstr = new char[userCommand.length() + 1];
		strcpy_s(cstr, userCommand.length() + 1, userCommand.c_str());


		// tokenizer for userCommand -> parameters vector.
		char* next_token;
		char* token = strtok_s(cstr, " ", &next_token);

		while (token != NULL)
		{
			parameters.push_back(token);
			token = strtok_s(NULL, " ", &next_token);
		}

		string command;
		// error handling for non valid cases.
		
		try
		{
			parameters.size() == 0 ? throw command : command = parameters[0];
			if (command != "addR" && command!= "addS" && command != "addC" 
				&& command != "scale" && command != "move" && command != "display")
			{
				throw command;
			}

			// alternatively, regex match case can be used to improve readability:

			/*
			#include <regex>

			regex expression("(add[R,S,C])|(scale)|(move)|(display)");

			if (!regex_match(command, expression))
			{
				throw command;
			}
			*/
			
		}
		catch (string e)
		{
			cout << "No compatable command entered, please check command list. \n" << endl;
		}

		// declaration for multi-use variables.
		int x, y;
		if (command.compare("addR") == 0) {
			try
			{
				// if user enters too many or too few paramaters, throw error.
				parameters.size() != 5 ? throw command:
				x = stoi(parameters[1].c_str());
				y = stoi(parameters[2].c_str());
				float h = stof(parameters[3].c_str());
				float w = stof(parameters[4].c_str());
				Rectangle* r = new Rectangle(x, y, h, w);
				shapes.push_back(r);
				// cout << overload.
				cout << r;
			}
			catch (string e)
			{
				parameters.size() > 5 ? cout << "too many parameters entered." << endl
					: cout << "too few parameters entered." << endl;
				cout << "proper use: " << "addR(int X,  int Y, float height, float width)\n" << endl;
			}

		}

		else if (command.compare("addS") == 0) {
			try
			{
				parameters.size() != 4 ? throw command :
				// get parameters
				x = stoi(parameters[1].c_str());
				y = stoi(parameters[2].c_str());
				float e = stof(parameters[3].c_str());
				Square* s = new Square(x, y, e);
				shapes.push_back(s);
				cout << s;
			}
			catch (string e)
			{
				parameters.size() > 4 ? cout << "too many parameters entered." << endl
					: cout << "too few parameters entered." << endl;
				cout << "proper use: " << "addS(int X, int Y, float edge)\n" << endl;
			}
			
		}

		if (command.compare("addC") == 0) {
			try
			{
				parameters.size() != 4 ? throw command :
				x = stoi(parameters[1].c_str());
				y = stoi(parameters[2].c_str());
				float r = stoi(parameters[3].c_str());
				Circle* c = new Circle(x, y, r);
				shapes.push_back(c);
				cout << c;
			}
			catch (string e)
			{
				parameters.size() > 4 ? cout << "too many parameters entered." << endl
					: cout << "too few parameters entered." << endl;
				cout << "proper use: " << "addC(int X, int Y, float radius\n" << endl;
			}		
		}

		else if (command.compare("scale") == 0) {
			int index = stoi(parameters[1].c_str());
			float scaleX = stof(parameters[2].c_str());
			float scaleY = stof(parameters[3].c_str());

			try
			{
				if (index - 1 <= -1 || index - 1 > shapes.size())
				{
					throw 0;
				}

				Shape* s = (shapes[index - 1]);
				// check the object type, then applying scale.
				if (dynamic_cast<Square*>(s) != NULL)
				{
					cout << "\nScaling object Square...\n";
					dynamic_cast<Square*>(s)->scale(scaleX, scaleY);
				}
				else if (dynamic_cast<Rectangle*>(s) != NULL) {
					cout << "\nScaling object Rectangle...\n";
					dynamic_cast<Rectangle*>(s)->scale(scaleX, scaleY);
				}
				else if (dynamic_cast<Circle*>(s) != NULL) {
					cout << "\nScaling object Circle...\n";
					dynamic_cast<Circle*>(s)->scale(scaleX, scaleY);
				}
				// output scaled object using standard toString method (without cout << overload).
				s->toString();
			}
			catch (int e)
			{
				cout << "scale function used was out of bounds! \n"
					<< "proper use: " 
					<< "scale(int object-location, float scale-X, float scale-Y)\n" << endl;
			}
		}
			
		else if (command.compare("move") == 0) {
			// move object at index 
			try
			{
				if (parameters.size() != 4)
				{
					parameters.size() > 4 ? cout << "too many parameters entered." << endl
						: cout << "too few parameters entered." << endl;
					throw 0;
				}

				
				int index = stoi(parameters[1].c_str());
				int newX = stoi(parameters[2].c_str());
				int newY = stoi(parameters[3].c_str());

				// ensure index is within bounds.
				if (index-1 <= -1 || index-1 > shapes.size())
				{
					cout << "object location invalid! \n" << endl;
					throw 0;
				}

				// downcast to enable moving of leftTop.
				Movable* m = dynamic_cast<Movable*>(shapes[index - 1]);
				// apply move.
				m->move(newX, newY);
				// tostring standard output.
				shapes[index - 1]->toString();

			}
			catch (int e)
			{
				cout << "Invalid use of move function! \n";
			}

			
		}

		else if (command.compare("display") == 0) {

			// basic handle for display with no object calls.
			if (shapes.size() == 0)
			{
				cout << "No shapes to display! \n" << endl;
			}

			for (int i = 0; i != shapes.size(); i++)
			{
				shapes[i]->toString();
			}
		}

		parameters.clear();
	}
	

	cout << "Press any key to continue...";
	std::getchar();
	return 0;
}