/** @file
 *
 *  @course CS1521
 *  @section 3
 *  @term Spring 2018
 *
 *  Testing the Spell Checker.
 *
 *  Adapted from pages 29,30,115 in Carrano 7e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *
 * @author Rudolf Musika
 *
 *  @date 10 Feb 2018
 *
 *  @version 7.0 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <stdio.h>

#include "LinkedSet.hpp"


//toLower the characters in the set
void toLower(std::string& word){
    for(int i=0; i < word[i]; ++i){
        word[i]=tolower(word[i]);
    }
}

//to clean set
void clean(std::string& word){
    std::string punctuation = "!@#$%^()_-+={}[]:;\"\'`<>,.?/|\\";
    unsigned long int beg = word.find_first_not_of(punctuation);
    unsigned long int end = word.find_last_not_of(punctuation);
    word = word.substr(beg,end-beg+1);
}
// to display Set
void displaySet(LinkedSet<std::string>& set){
    
    std::vector<std::string> setItems=set.toVector();
    
    int numberOfEntries = (int)setItems.size();
    
    for (int i(0); i< numberOfEntries;++i){
        std::cout<<(setItems[i])<< " ";
    }
    std::cout<<std::endl
    << std::endl;
}

int main() {
    
    char answer = 'y';
    
    while (answer == 'y' || answer =='Y'){
        
        std::ifstream toCheck,dictionaryCheck;
        std::ofstream outFile;
        std::string word,filename;
        
        LinkedSet<std::string> checkerSet;

        
        std::cout << "Enter the name of the file to spellcheck: ";
        std::cin >> filename;
        toCheck.open(filename.c_str());
        
        //To Error check the file type
        while(!toCheck){
            std::cerr<<"Failed to open "<<filename<<std::endl;
            std::cout<<"Insert the name of the file you'd like to spell check: ";
            std::cin>>filename;
            toCheck.open(filename.c_str());
        }
        //Cleaning and changing from Caps & Unpacking
        while(toCheck>>word){
            clean(word);
            toLower(word);
            checkerSet.add(word);
        }
        toCheck.close();
        
        displaySet(checkerSet);
        
        outFile.open(filename.c_str());
        while(!outFile){
            std::cerr<<"Failed to open "<<filename<<std::endl;
            std::cout<<"Insert the name of the file you'd like to spell check: ";
            std::cin>>filename;
            outFile.open(filename.c_str());
        }
        
        outFile<<"hello Hey";
//        if( remove( filename.c_str()) != 0 )
//            perror( "Error deleting file" );
//        else
//            puts( "\nFile successfully deleted" );
//        outFile.close(); //Using microsoft incremental linker version 14
        
        std::cout<<"\nWould you like to try different files 'y' or 'n': ";
        std::cin>>answer;
        
    }
    
    return 0;
}



