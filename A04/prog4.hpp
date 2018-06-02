/*
 ************************************************************
 * This program is a database for storing favorite websites
 * that you want to bookmark.  
 *
 * Name: Aris Bloms
 * CS260 PCC
 * Date: Nov. 7
 * Assignment 3
 *
 * class website 
 *      contains all the website data
 *
 * class tree
 *      contains the tree
 *
 *      class leaf
 *          contains the storage of the websites
 *
 ************************************************************
*/ 

#ifndef __PROG_4__
#define __PROG_4__

#include<iostream>
#include<iomanip> 
#include<cassert>
#include<cstring>
#include<fstream>


const static int CAPACITY = 11;
const int MAX = 256;

class website {
    char * topicName; // website topic
    char * keyword; // NEW!!!!
    char * websiteAddr; // URL
    char * summary; // summary of the website
    char * review; // review of the website
    uint8_t rating; // 0 to five star rating
    
public:
    website();
    website(char* topicName, char* websiteAddr, char* summary, char *review, uint8_t rating); // creates a website
    ~website();                // website destructor

    char* getTopicName();   //returns topicName
    char* getKeyword();
    char* getWebsiteAddr(); //returns websiteAddr
    char* getSummary();     //returns summary
    char* getReview();      //returns review
    uint8_t getRating();    //returns rating

    void setTopicName(char *);      //sets topicName
    void setWebsiteAddr(char *);    //sets websiteAddr
    void setSummary(char*);         //sets summary
    void setReview(char*);          //sets review
    void setRating(uint8_t);        //sets rating
    void printWebsite(int);
}; // end of website class

class tree {
private: // still only in tree
    struct leaf { 
        website favorited;
        leaf * left;
        leaf * right;

        leaf() {                  // leaf default constructor
            left = NULL;
            right = NULL;
        }
        
        leaf(website& aWebsite) { // leaf constructor
            favorited = aWebsite;
            left = NULL;
            right = NULL;
        }
        ~leaf() {                 // leaf destructor
            delete left;
            delete right;
        }
    }; // end of leaf struct
    
    leaf * root;
    int size;
    // from Li's code
    void insert(node*& root, const website&);
    bool retrieve(node * root, char * key, website&) const;
    bool remove(node*& root, char * key);    
    void deleteNode(node *& target);        
    void display(node * root) const;
    void writeOut(ofstream& out, node * root);                
    void destroyTable(node*& root);                    
    void copyTable(node*& newRoot, node * root);
    
    int calculateIndex(char * key) const; // creates index    
    bool retrieve(char*, website[], int&);//retrieves a website
    void displayInOrder(leaf*, int&);
    
    // ethan functions
    leaf postOrder();
    leaf preOrder();

public: // tree public functions
    tree();
    tree(char * filename);     //loads file
    ~tree();                   //destructor

    void insert(website&);          //inserts a website
    bool remove(char* key);         //removes a website
    void displayAll(void);    //displays all websites
    bool display(char * key);       //displays a website
    int getSize(void) const;        //returns size
    bool writeOut(char * filename); //writes to file
};




#endif
