/**
 * @file playlist.h   Declaration of a Playlist for music.
 *
 * @brief
 *    Implementation of Playlist for music, where a doubly linked list is
 *    used to store the song names.
 *
 * @author Judy Challinger & <Cristian Silva>
 * @date 2016
 */

#ifndef CSCI_311_PLAYLIST_H
#define CSCI_311_PLAYLIST_H

#include "doublylinkedlist.h"
using std::string;
class Playlist {
public:
   void mainLoop();// process commands until finished
    void print(){m_print();};
private:
   DoublyLinkedList dll;               // playlist stored in doubly linked list

   bool processCommand();              // read and process one playlist command

   // you may add more private functions for functional decomposition
    void m_print();
    int m_size;
};

#endif // CSCI_311_PLAYLIST_H