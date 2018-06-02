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

void Graph::initializelist(){
    list = new node*[cap];
    for(int i = 0; i < cap; i++){
	list[i] = NULL;
    }
}

Graph::Graph():cap(11),size(0){
	initializelist();
}



Graph::Graph(const char * file):cap(11), size(0){
    ifstream in;
    char task[100];

    initializelist();

    in.open(file);
    if(!in){
	cerr << "fail to open " << file << " for input!" << endl;
	exit(1);
    }

    while(!in.eof()){
        node * current;
	while(in.peek() != ';'){
    	    in.getline(task, 100, '\n');
            insert(task);
	}
        for(int i = 0; i < size; i++){
            in.ignore(100, ';');
            while(in.peek() != ';' && !in.eof()){
                in.getline(task, 100, '\n');
                add(list[i]->task, task);
            }
        }
    }
    in.close();
}



Graph::~Graph(){
    for(int i = 0; i<cap; i++){
	node * head = list[i];
	node * current;
	while(head){
	    current = head->next;
	    head->next = NULL;
            delete head;
	    head = current;
	}
    }
    delete [] list;
}



void Graph::insert(char task[]){
    size++;
    if(size >= cap - 1){
        increase();
    }
	node * newNode = new node(task); 
    int i = 0;
    while(list[i]){
        i++;
    }
    list[i] = newNode;

}


void Graph::add(char task[], char add[]){
    int src = search(add);
    int des = search(task);

    if(des < 0){
        insert(task);
        des = search(task);
    }
    if(src < 0){
        insert(add);
        src = search(add);
    }
    char newTask[strlen(list[src]->task)];
    strcpy(newTask, list[src]->task);
    
    node * newNode = new node(newTask);
    newNode->next = list[des]->next;
    list[des]->next = newNode;
}

int Graph::search(char task[]) {
    int i = 0;
    for(char * find; i < size;i++){
        find = list[i]->task;
        if(strcmp(find, task) == 0){
            break;
        }
    }
    if(i >= size){
        return -1;
    }else{
        return i;
    }
}

void Graph::increase(){
    cap = cap * 2;
    node ** newlist = new node*[cap];
	for(int i = 0; i < cap/2; i++){
	    if(list[i]){
                newlist[i] = new node(list[i]->task);

                node * srcNode = list[i]->next;
                node * desNode = newlist[i];
                while(srcNode){
                    desNode->next = new node(srcNode->task);
                    desNode = desNode->next;
                    srcNode = srcNode->next;
                }
                desNode->next = NULL;

            }else{
                list[i] = NULL;
            }
	}
    list = newlist;
}

void Graph::display()const{ 
    node * current;
    cout << "\nTasks to accomplish: " << endl << endl;
    for(int i = 0; i < size - 1; i++){ 
	cout << i + 1; 
        for(current = list[i]; current; current=current->next){
            cout << "\t\t" << "->" << current->task << endl;
        }
        cout << endl << endl;
    }
    cout << endl << endl;
}

void Graph::dft() {
    node * current;
    
}

int Graph::getSize()const{
    return size;
}



void Graph::writeOut(char file[]){
    ofstream out;
    out.open(file);
    if(!out){ //checks for fail
        cerr << "failed to open " << file << endl;
        exit(1);
    }

    node * current;
    for(int i = 0; i < size; i++){
        out << list[i]->task << endl;
    }

    for(int i = 0; i < size;i++){
        out << ";" << endl;
        for(current = list[i]->next;current;current = current->next){
            out << current->task << endl;
        }
    }
    out << ";" << endl;
    out.close ();
}
