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

#ifndef __PROG_H__ 
#define __PROG_H__

#include <cstring>
#include <iostream>
#include <ostream>
#include <fstream>


class Graph {

public:
	
    Graph();
    Graph(const char * fileName);
    ~Graph();

    void insert(char task[]);
    void add(char task[],char add[]);
    int search(char task[]);
    void increase();
    void display()const;
    int getSize()const;
    void writeOut(char file[]);
    void dft();

private:
    struct node {
        char * task;
	node * next;
	node(char temp[]){
            task = new char[strlen(temp)+1]; 
	    strcpy(task, temp);
	    next = NULL;
	}
        ~node() {
            if (task)
                delete task;
            
            delete next;
        }
    };
    node ** list;
	
    int cap;
    int size;

    void initializelist();
    
    /*
    struct stack {
        node * aNode;
        stack * next;
        stack(node * current) {
            aNode = current;
            next = NULL;
        }
    };
    stack * front;
    */
};

#endif
