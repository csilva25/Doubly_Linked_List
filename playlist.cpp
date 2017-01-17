/**
 * @file playlist.cpp   Implementation of a Playlist for music.
 *
 * @brief
 *    Implementation of a Playlist for music. A doubly linked list is
 *    used to store the song names.
 *
 *    Note: main() is in this file.
 *
 * @author Judy Challinger & <Cristian Silva>
 * @date 2016
 */

#include <iostream>
#include <string>
#include <vector>

#include "playlist.h"
#include "doublylinkedlist.h"

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
// you may add more private functions for functional decomposition



/**
 * Process a playlist command.
 *
 * Gets an entire line from std::cin, extracts the first word as the command,
 * and calls the appropriate processing function. Invalid commands are
 * ignored.
 *
 * @return false if command is "quit", otherwise true
 */
bool Playlist::processCommand() {
    string command;
    cin >> command;
    cin.ignore();
    if (command == "appendSong")
    {
        getline(cin,command);
        dll.append(command);
        
        
        return true;
        
    }
   
    if (command == "insertBefore")
    {
        getline(cin,command);
        dll.insertBefore(command);
        return true;
        
    }
    
    if (command == "insertAfter")
    {
        getline(cin,command);
        dll.insertAfter(command);
        return true;
        
    }

    if (command == "gotoFirstSong")
    {
        dll.begin();
     
        return true;
    }
   
    if (command == "gotoLastSong")
    {
        dll.end();
        return true;
    }
    if (command == "playCurrent")
    {
        cout<<endl;
        cout <<"playing current: ";
        bool check = dll.empty();
        if (check == true)
        cout << dll.getData() <<endl;
        return true;
        
    }
    if (command == "removeSong")
    {
        getline(cin,command);
        dll.remove(command);
        return true;
        
    }
    if (command == "gotoSong")
    {
        getline(cin,command);
        dll.find(command);
        return true;
        
    }
      
    if (command == "nextSong")
    {
        dll.next();
        return true;
        
    }
    if (command == "prevSong")
    {
     
        dll.prev();
        return true;
    }
    
    if (command == "playForward")
    {
        cout<<endl;
         cout <<"playing forward: "<<endl;
        bool check = dll.empty();
        
        while (check == true)
        {
            cout << dll.getData() <<endl;
            check = dll.next();
        }
        return true;
    }
    if (command == "playReverse")
    {
        cout<<endl;
         cout <<"playing reverse: "<<endl;
        bool check =dll.empty();
        while (check ==  true)
        {
            cout << dll.getData() <<endl;
            check = dll.prev();
        }
        return true;
    }
     
    
    if (command == "quit")
    {
        return false;
        
    }
 
    return true;
}
/**
 * The Playlist main loop will process command lines until finished.
 */
void Playlist::mainLoop() {
   while (processCommand());         // process all commands
}

/**
 * The main entry point for the program.
 */
int main()
{
   Playlist myPlaylist;
   myPlaylist.mainLoop();
   return 0;
}

