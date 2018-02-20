//
//  MainClear.cpp
//  Project3CS2Trial
//
//  Created by Rudolf Musika on 2/18/18.
//  Copyright © 2018 Rudolf Musika. All rights reserved.
//

// clearing errors
//#include <iostream>     // std::cout
//#include <fstream>      // std::fstream
//
//int main () {
//    char buffer [80];
//    std::fstream myfile;
//
//    myfile.open ("test.txt",std::fstream::in);
//
//    myfile << "test";
//    if (myfile.fail())
//    {
//        std::cout << "Error writing to test.txt\n";
//        myfile.clear();
//    }
//
//    myfile.getline (buffer,80);
//    std::cout << buffer << " successfully read from file.\n";

#include<iostream>
#include<fstream>
#include<string>

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
    
    std::ifstream infile;
    std::string filename;
    LinkedSet<std::string> checkerSet;
    LinkedSet<std::string> diff;

    std::cout<<"Insert the file name you'd like to use: ";
    std::cin>>filename;
    infile.open(filename.c_str());
//    To Error check the file type
    while(!infile){
        std::cerr<<"Failed to open "<<filename<<std::endl;
        std::cout<<"Insert the name of the file you'd like to spell check: ";
        std::cin>>filename;
        infile.open(filename.c_str());
    }
    if(infile.fail()){
        std::cerr<<"Error Opening File"<<std::endl;
        exit(1);
    }
    std::string x;
    

    
    infile >> x;
    while(infile>>x){
        toLower(x);
        checkerSet.add(x);
    }

    displaySet(checkerSet);
    
    
    return 0;
}
    
//    fstream ofs;
//
//    int main(){
//        ofs.open("test.txt",std::ios::out |std::ios::trunc);
//        ofs<<"Your content here";
//        ofs.close(); //Using microsoft incremental linker version 14
//        return 0;
//
//    }
//
//    return 0;
//}

