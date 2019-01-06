//
// pq.cpp
//
// Your Name: Kara Wolley


#include <string>
#include <iostream>
#include "pq.h"
using namespace std;

// initialize queue as heap with string
pq* init_priority_queue() {
  pq* queue = new pq;
  queue -> next = nullptr;
  queue -> priority = 0;
  queue -> text = "";
  return queue;
}

// peek will "view" the highest priority however no changes are made
// also called head 
string peek(pq* &queue) {
  return(queue -> text); // return the highest priority string
}

void insert(pq* &queue, string text, float priority) {
  // create new node with info in it
  pq* tmp = init_priority_queue();
  tmp ->priority = priority;
  tmp ->text = text;

  if (queue ->priority == 0){
    queue -> priority = priority;
    queue -> text = text;
    return;
  }
  pq* cursor = queue;
  // if the top of queue is < priority
  if (cursor -> priority < priority){
    // insert new node beofre top
    tmp -> next = cursor;
    queue = tmp;
    return;
  }
  // traverse through list
  while (cursor -> next != nullptr && cursor -> next ->priority >= priority){
    cursor = cursor -> next;
  }
  tmp -> next = cursor -> next;
  cursor -> next = tmp ;
  return;
}

// remove the highest priority and returns it
string remove(pq* &queue) {
  pq* cursor = queue;
  while (cursor -> next != NULL){
    cout<<cursor -> text << ": " << cursor -> priority << endl;
    cursor = cursor -> next;
  }
  pq* tmp = queue;
  queue = queue -> next;
  //cout << tmp -> text << endl;
  return tmp -> text; // TODO
}


