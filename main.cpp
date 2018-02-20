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

#include "LinkedSet.hpp"



//toLower the characters in the set
std::string toLower(std::string word){
    for(int i=0; i < word[i]; ++i){
        word[i]=tolower(word[i]);
    }
    return word;
}

//to clean set
std::string clean(std::string word){
    std::string punctuation = "!@#$%^()_-+={}[]:;\"\'`<>,.?/|\\";
    unsigned long int beg = word.find_first_of(punctuation);
    while(beg == 0){
        word = word.substr(1, word.length()-1);
        beg = word.find_first_of(punctuation);
    }
    unsigned long int end = word.find_last_of(punctuation);
    while(end == word.length()-1){
        word = word.substr(0, word.length()-1);
        end = word.find_last_of(punctuation);
    }
    return word;
}
// to display Set
void displaySet(LinkedSet<std::string>& set){
    std::cout << "The set contains " << set.getCurrentSize()
              << " items:" << std::endl;
    
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
    LinkedSet<std::string> checkerSet;
    LinkedSet<std::string> dictionarySet;

    while (answer == 'y' || answer =='Y'){

        std::ifstream toCheck,dictionaryCheck;

        std::string word,filename,filename2;
    
        std::cout<<"Insert the name of the dictionary you'd like to use: ";
        std::cin>>filename2;
        dictionaryCheck.open(filename2.c_str());
        
        //Error check the dictionary
        while(!dictionaryCheck){
            std::cerr<<"Failed to open "<<filename2<<std::endl;
            std::cout<<"Insert the name of better dictionary you want to use: ";
            std::cin>>filename2;
            dictionaryCheck.open(filename2.c_str());
        }
        //Unpacking
        while(dictionaryCheck>>word){
     //       word = clean(word);
       //     word = toLower(word);
            dictionarySet.add(word);
        }
        dictionaryCheck.close();
        //To enter the spell Checker file
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
            word = clean(word);
            word = toLower(word);
            checkerSet.add(word);
        }
        toCheck.close();
        
        //Difference of both
        std::cout<<"-------------------------"<<std::endl;
        LinkedSet<std::string> diff(checkerSet.difference(dictionarySet));

        std::cout<<std::endl;
        displaySet(diff);
        std::cout<<"-------------------------"<<std::endl;
        
        //Clearing
        checkerSet.clear();
        dictionarySet.clear();
        diff.clear();

        std::cout<<"\nWould you like to try different files 'y' or 'n': ";
        std::cin>>answer;
    }

    return EXIT_SUCCESS;
}


