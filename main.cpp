/* 
 * Name: Aris Bloms
 * CS260
 * Project: 5
 * Date: Dec, 3
 * The goal of this program is to create a SIMPLE directed 
 *   graph abstraction using an adjacency graph (an array of 
 *   vertices where each element has a vertex and a head 
 *   pointer to a LLL of edges for adjacent vertices).
 *
 * FILE:
 * 1st
 * -> (edge)
 * -> (edge)
 *  ;
 *  2nd 
 *  -> (edge)
 *  ;
 *  3rd
 *  ;
 *
*/ 

#include "prog5.h"

using namespace std;

void menu(void) {
    cout << "\nWelcome to the Wedding planner!\n\t[A] to add a "     << "new set of tasks.\n\t[N] to add a new step to a" <<
        "current task\n\t[D] to display.\n\t[W] to write" << 
        " to a file.\n\t[Q] to quit." << endl;
}

int main() {
    //Graph graph;
    
    char filename[100];
    strcpy(filename, "file.txt");
    Graph graph(filename);

    char task[100], add[100];
    char ans = ' ';
    do {
        menu();
        cin >> ans;

        switch(toupper(ans)) {
            case('A'):
                cin.clear();
                cin.ignore(100, '\n');
                cout << "New list of tasks created. First " <<
                    "task : ";
                cin.getline(task, 100);
                graph.insert(task);
                break;

            case('N'):
                cin.clear();
                cin.ignore(100, '\n');
                
                cout << "Task to add on to : ";
                cin.getline(task, 100);

                cout << "Name of new task : ";
                cin.getline(add, 100);

                graph.add(task, add);
                break;

            case('D'):
                cin.clear();
                cin.ignore(100, '\n');
                
                graph.display();
                break;

            case('G'): // depth first traversal
                graph.dft();
                break;

            case('W'):
                cin.clear();
                cin.ignore(100, '\n');
                
                graph.writeOut(filename);
                break;
            case('Q'):
                break;
            default:
                cout << "Sorry, I didn't understand. Try "
                    << "again.\n";
                break;
        }


    } while (toupper(ans) != 'Q');
}
