//Cristian Silva
//ID# 006283655
//CSCI 311
//Project 1
//J. Challenger

#include "doublylinkedlist.h"
#include <iostream>
#include <string>
#include <vector>

using std::endl;
using std::cout;
/**
 *  @file doublylinkedlist.cpp  Implementation of functions to be called in Playlist.cpp.
 *
 *  @brief 
 * 	Implementation of functions to be called in playlist.cpp. Functions created
 *  	in this file is to help implement a playlist.
 * 
 * @auther Cristian Silva
 * @date 2016
 */

/**
 * Here is the function that constructs the member variables to be used
 * and referenced throughout the doublylinkedlist.cpp. 
 */
DoublyLinkedList::DoublyLinkedList()
{
    m_current = NULL;
    m_head = NULL;
    m_tail = NULL;
}
/**
 * The destructor function here is made to delete every node
 * in the linked list when it is done executing.
 */
DoublyLinkedList::~DoublyLinkedList()
{
	Node* ptr = m_head;
    while(ptr !=NULL)
    {
        Node* temp = ptr;
        ptr = ptr->m_next;
	delete temp->m_data;
        delete temp;
    }
    
}

 /**
  * Empty function checks if there is no nodes in the linked list
  * and returns false if this is true 
  *
  * @Note 
  *	It returns false so it is easier to understand in playlist.cpp.
  *
  */

bool DoublyLinkedList::empty()
{
if (m_head == NULL)
    return false;
else return true;
}

/**
 * Inserts new song inputted by playlist and puts it to the back of the linked list.
 */

void DoublyLinkedList::append(const string& song)
{
    string* m_data = new string (song); // casting song title to a type string and setting to the string data variable
    if (m_head == NULL)
    {
        m_head = new Node (m_data,NULL,NULL); //new node
        m_current = m_head;
        m_tail = m_current;
    }
    else
    {
        Node* temp = m_head;
        while (temp->m_next!=NULL) //traveling throught the linked list to find NULL
            temp = temp->m_next;
        
        temp->m_next = new Node(m_data,temp,NULL); //inserting at NULL
        m_current = temp->m_next;
        m_tail = m_current; // since at null, last node is tail
       
        
    }
    
    
}

 /**
  * Inserts song inputted by playlist and puts it prior to the current song.
  */

void DoublyLinkedList::insertBefore(const string& song)
{
    Node* ptr = m_head;
    
    string* m_data = new string (song);
    if (m_head == NULL) //safty: if the list is empty
    {
        append(song);
        return;
    }
    if (m_head == m_current)
    {
        m_head = new Node (m_data,NULL,m_head);
        m_current->m_prev = m_head;
        m_current = m_head;
        return;
    }
    
    
    while (ptr->m_next != m_current) //travels through the list to find current node
    {
        ptr = ptr->m_next;
    }
    ptr->m_next = new Node (m_data, ptr, ptr->m_next);
    m_current->m_prev = ptr->m_next;
    m_current = ptr->m_next;
    
    
}

 /**
  * Inserts song inputted by playlist and puts it after the current song.
  */
void DoublyLinkedList::insertAfter(const string& song)
{
    string* m_data = new string (song);
    Node *temp = m_head;
    
    if (m_head == NULL) //safty: if the list is empty
    {
        append(song);
        return;
    }
    
    
    while (temp!=NULL && temp != m_current)
        temp = temp->m_next;
    temp->m_next = new Node (m_data, temp, temp->m_next);
    
    if (temp->m_next->m_next != NULL) //this if statement was an outcome of many visial helps
        temp->m_next->m_next->m_prev = temp->m_next; //writing this prev function was the most difficult
    else m_tail=temp->m_next; //this is there is no node after so its tails
    
    m_current = temp->m_next;
    
}

 /**
  *  This funtion makes the first node in the linked list
  *  the current node.
  */
void DoublyLinkedList::begin()
{
    if (m_head == NULL)
        return;
    
    m_current = m_head;
    
}

 /**
  *  This funtion makes the last node in the linked list
  *  the current node.
  */

void DoublyLinkedList::end()
{
    if (m_tail==NULL)
        return;
    m_current = m_tail;
    
 
}
 /**
  *  This funtion returns the string in the current node.
  * 
  */
const string& DoublyLinkedList::getData()
{
    return *(m_current->m_data);
}
 /**
  *  This funtion removes the current node
  *  the current node.
  *
  * @Note
  * 	If the node being removed is at the end of the linked list,
  * 	the previous node is the new current node.
  *	
  * 	If the node being removed is in the begining or middle of 
  *	the linked list, then the next node is the new current node.
  */

void DoublyLinkedList::remove(const string &song)
{
    string* m_data = new string (song);
    Node* ptr =  m_head;
    Node* temp = m_head;
    
    if (m_head == NULL)
        return;
    
        
    
    if (*(m_head->m_data) == *m_data) //if the first song is a match and theres only one
    {
        m_head = m_head->m_next;
        m_current = m_head;
        if (m_head!=NULL) //this if statement is if there is more than one node
        m_head->m_prev = NULL;
        delete temp;
        
        
        
        return;
    }
    
    while (ptr!=NULL && *(ptr->m_data) != *m_data) //im moving the ptr without changing current yet
        ptr=ptr->m_next;
    
     if (ptr->m_next == NULL && *(ptr->m_data) == *m_data) //this is if the match is at the end
    {
        temp = ptr;
        ptr=ptr->m_prev;
        ptr->m_next = NULL;
        m_current = ptr;
        m_tail = ptr;
        
        
        delete temp;
        
    }
    else //if code is if the match is in the middle
    {
        temp = ptr;
        ptr->m_prev->m_next = ptr->m_next;
        ptr->m_next->m_prev = ptr->m_prev;
        ptr = ptr->m_next;
        m_current = ptr;
        delete temp;
    }
   
}

/**
 * This function finds the song that is sent from playlist.cpp.
 * I do this by traversing throught the linked list, comparing the 
 * string from playlist to the string at each node, until there is
 * a match.
 */


bool DoublyLinkedList::find(const string &song)
{
     Node* ptr = m_head;
    string* m_data = new string (song);
    if (m_head==NULL || m_current == NULL) //if list empty
        return false;
    
    while ( ptr != NULL && *(ptr->m_data) != *m_data) //check if theres a match
         ptr=ptr->m_next; //travel through linked list
    
    m_current = ptr;
    return true;
}
/*
 * This fuction moves the current postion to the next node.
 *
 * @Note
 *     I use the current and next member veriables.
 */

bool DoublyLinkedList::next()
{
    if (m_head == NULL || m_current==NULL)
        return false;
    
    if (m_current->m_next != NULL)
    {
        m_current = m_current->m_next;
        return true;
    }
    else return false;
}
/*
 * This function moves the current postion to the previous node.
 */
bool DoublyLinkedList::prev()
{
    if (m_tail == NULL || m_head ==NULL || m_current ==NULL)
        return false;
    if (m_current->m_prev != NULL )
    {
        m_current = m_current->m_prev;
        return true;
    }
     return false;
}






