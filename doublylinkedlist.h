//Cristian Silva
//ID# 006283655
//CSCI 311
//Project 1
//J. Challenger

/**
 * @file doublylinkedlist.h   Declaration of a Doublylinkedlist for music.
 *
 * @brief
 *    Implementation of Doublylinkedlist for music, where a the functions
 *    are called in Playlist.
 *
 * @author Cristian Silva
 * @date 2016
 */

#ifndef doublylinkedlist_h
#define doublylinkedlist_h

#include <string>
using std::string;
class DoublyLinkedList
{
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    bool empty();
    void append(const string& s);
    void insertBefore(const string& s);
    void insertAfter(const string& s);
    void remove(const string& s);
    void begin();
    void end();
    bool next();
    bool prev();
    bool find(const string& s);
    const string& getData();
    
private:
    
    class Node
    {
    public:
        Node (string* data,Node* prev, Node* next)
        {m_data= data; m_prev = prev; m_next = next;}
        Node* m_next;
        Node* m_prev;
        string* m_data;
       // ~Node();
    };
    Node* m_current;
    Node* m_head;
    Node* m_tail;
};


#endif /* doublylinkedlist_h */
