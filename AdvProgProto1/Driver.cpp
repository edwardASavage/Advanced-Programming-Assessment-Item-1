#include "Shape.h"

#include "Circle.h"

#include "Rectangle.h"

#include "Square.h"

#include "Movable.h"

#include <string>

using namespace std;

int main() {
	string userCommand;
	vector < Shape* > shapes; // this one will hold your shapes
	vector < string > parameters; // this one will hold parameters for the commands

	try {
		while (userCommand.compare("exit") != 0) {

			cout << "Enter the command: ";
			getline(cin, userCommand);
			char* cstr = new char[userCommand.length() + 1];
			strcpy_s(cstr, userCommand.length() + 1, userCommand.c_str());

			//tokenizer
			char* next_token;
			char* token = strtok_s(cstr, " ", &next_token);

			while (token != NULL) {
				parameters.push_back(token);
				token = strtok_s(NULL, " ", &next_token);
			}


			// error checking for null params.
			if (parameters.empty()) { throw 4; }

			string command = parameters[0];


			// x and y coord for all commands.
			int x, y;
			// command functions
			{
				if (command.compare("addR") == 0) {

					if (parameters.size() == 5) {

						x = stoi(parameters[1].c_str());
						y = stoi(parameters[2].c_str());
						int h = stoi(parameters[3].c_str());
						int w = stoi(parameters[4].c_str());
						Rectangle* r = new Rectangle(x, y, h, w);
						shapes.push_back(r);
						// operator << overload
						cout << r;
					}
					else { throw 0; }
				} 
				
				
				else if (command.compare("addS") == 0) {
					// set parameters

					if (parameters.size() == 4) {
						x = stoi(parameters[1].c_str());
						y = stoi(parameters[2].c_str());
						int e = stoi(parameters[3].c_str());
						Square* s = new Square(x, y, e);
						shapes.push_back(s);
						cout << s;
					}
					else { throw 1; }
				}
	

				else if (command.compare("addC") == 0) {
					// set parameters
					if (parameters.size() == 4) {
						x = stoi(parameters[1].c_str());
						y = stoi(parameters[2].c_str());
						int r = stoi(parameters[3].c_str());
						Circle* c = new Circle(x, y, r);
						shapes.push_back(c);
						c->toString();
						cout << c;
					}
					else { throw 2; }
				}
	

				else if (command.compare("scale") == 0) {
					int index = stoi(parameters[1].c_str());
					float scaleX = stoi(parameters[2].c_str());
					float scaleY = stoi(parameters[3].c_str());

					int error = 0;
					Shape* s = (shapes[index - 1]);
					// error checking for bounds.
					if (index-1 < 0 || index-1 > shapes.size()) {throw 3;}

					if (dynamic_cast <Square*> (s) != NULL) {
						cout << "Scaling object Square...\n";
						dynamic_cast <Square*> (s)->scale(scaleX, scaleY);
					}
					else if (dynamic_cast <Rectangle*> (s) != NULL) {
						cout << "Scaling object Rectangle...\n";
						dynamic_cast <Rectangle*> (s)->scale(scaleX, scaleY);
					}
					else {
						cout << "Scaling object Circle....\n";
						dynamic_cast <Circle*> (s)->scale(scaleX, scaleY);
					}

					cout << shapes[index - 1];
				}
				else if (command.compare("move") == 0) {
					// move object at index 
					int shapeNo = stoi(parameters[1].c_str());
					int newX = stoi(parameters[2].c_str());
					int newY = stoi(parameters[3].c_str());
					// you may want to check if the index exists or not!

					// Study the following code. A Shape object is not Movable, but all derived classes are...
					// you can't automatically type cast from a Shape to a Movable, but you can force a downcasting
					Movable* m = dynamic_cast <Movable*> (shapes[shapeNo - 1]);

					m->move(newX, newY);

					shapes[shapeNo - 1]->toString();
				}
				else if (command.compare("display") == 0) {

					for (int i = 0; i != shapes.size(); i++) {
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

			cout << "Press any key to exit...";
			std::getchar();
			return 0;

		}
	}
	// catch block for all given integer throws.
	catch (int e) {
		if (e==0)
		{
			cout << "Invalid parameters! Required: (int X-coord, int Y-coord, int height, int width)." << endl;
		}
		if (e == 1) {
			cout << "Invalid parameters! Required: (int X-coord, int Y-coord, int edge)." << endl;
		}
		if (e == 2) {
			cout << "Invalid parameters! Required:  (int X-coord, int Y-coord, float radius)." << endl;
		}
		if (e == 3)
		{
			cout << "object at index does not exist!" << endl;
		}
		if (e == 4)
		{
			cout << "No function specified. function(parameters) options are:\n"
				<<"\naddR(int X-coord, int Y-coord, int height, int width)\n"
				<<"\naddS(int X-coord, int Y-coord, int edge)\n"
				<<"\naddC(int X-coord, int Y-coord, float radius)\n"
				<<"\nscale(int index, float scale-X-coord, float scale-Y-coord)\n"
				<<"\nmove(int new-X-coord, int new-Y-coord)" << endl;
		}
	}
	catch (...) {
		cout << "DEFAULT EXCEPTION";
	}
}