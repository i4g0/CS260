/*
 * ARIS BLOMS
 *************************************************
 * This is the implemetation of the code.
 * It holds all of the function definitions.
 *
 * 
 * File OUTPUT: data.dat
 * topicName;websiteAddr;summary;review;rating;
 * topicName;websiteAddr;summary;review;rating;
 * \n at the end of the file.
 *************************************************
*/  

#include "prog4.hpp"
using namespace std;

website::~website() {
    if (this->topicName)
        delete[] this->topicName;
    if (this->websiteAddr)
        delete[] this->websiteAddr;
    if (this->summary)
        delete[] this->summary;
    if (this->review)
        delete[] this->review;
}

tree::tree() : size(0) {
}

tree::tree(char * filename) : size(0) {
    
}

tree::~tree() {
}

website::website() {
    topicName = NULL;
    websiteAddr = NULL;
    summary = NULL;
    review = NULL;
    return;
}

website::website(char* topicName, char* websiteAddr, char* summary, char *review, uint8_t rating) {
    setTopicName(topicName);
    setWebsiteAddr(websiteAddr);
    setSummary(summary);
    setReview(review);
    setRating(rating); 
}
char* website::getKeyword() {
    return keyword;
}
char* website::getTopicName() {
    return topicName;
}

char* website::getWebsiteAddr() {
    return websiteAddr;
}

char* website::getSummary() {
    return summary;
}

char* website::getReview() {
    return review;
}

uint8_t website::getRating() {
    return rating;
}

void website::setTopicName(char* name) {
    topicName = name;
}

void website::setWebsiteAddr(char* web) {
    websiteAddr = web;
}

void website::setSummary(char* sum) {
    summary = sum;
}

void website::setReview(char* rev) {
    review = rev;
}

void website::setRating(uint8_t num) {
    rating = num;
}

void website::printWebsite(int IDval) {
    cout << "\t" << IDval << getKeyword() <<
        getTopicName() << 
        "\n\t" << getWebsiteAddr() <<
        "\n\t" << getSummary() << "\n\t" <<
        getReview() << "\n\t" << 
        getRating() << endl;
}

void tree::displayInOrder(leaf *current, int& IDval) {
    if (current == NULL)
        return;
    if (current->left)
        return displayInOrder(current->left, IDval);
    current->favorited.printWebsite(IDval);
    IDval++;
    if (current->right)
        return displayInOrder(current->right, IDval);
}


int tree::calculateIndex(char* key) const {
    char * c = key;
    int total = 0;

    while (*c) {
        total += *c; //adds ascii values together
        c++;
    }

    return total%CAPACITY; // sum of the values modulo CAPACITY
}

int tree::getSize() const {
    return size;
}

void tree::insert(website& aWebsite) {
   char *key;
   key = aWebsite.getTopicName();
   int index = calculateIndex(key);

   leaf * newNode = new leaf(aWebsite);
   assert(newNode);
   size++;
}

bool tree::remove(char * key) {
    int index = calculateIndex(key);
    char *name;
}

bool tree::retrieve(char* key, website output[], int& num_found) {
} 

bool tree::display(char * key) {
}

void tree::displayAll() {
    int IDval = 0;
    cout << "Website data:\n\tTopic:\n\tURL:\n\tSummary:\n\tReview:\n\tRating (0 - 5 Stars):\n" << endl;
    displayInOrder(root, IDval);
}

bool tree::writeOut(char * filename) {
}
