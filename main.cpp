#include <iostream>
#include <vector>
#include <utility>
#include <fstream>

using namespace std;

//------- Prototypes-------//
string printCabecalho();
bool ReadFile(string &path, vector <string> &textVector);
void OP1(vector<pair<string, vector<string>>> &AllPairs);
void OP2(vector<pair<string, vector<string>>> &AllPairs);
void OP3(vector<pair<string, vector<string>>> &AllPairs);
void OP4(vector<pair<string, vector <string>>> &AllPairs);
void OP5(vector<pair<string, vector <string>>> &AllPairs, const string &outputFilePath);
void RemoveDuplicates(vector<string> &word, const string &str);
//------- Prototypes-------//


int main(){
    string cabecalho = printCabecalho();
    cout<<cabecalho;

    vector<pair<string, vector<string>>> AllPairs;
    string outputFilePath = "./concatenation.txt";


    char option;
    while(option != '5'){
            cout<<"-------------------------------------------------"<<endl;
            cout<<"FILE MANIPULATOR HACK"<<endl;
            cout<<"Select an option:"<<endl;
            cout<<"1. Load a File. Enter filename..."<<endl;
            cout<<"2. Remove Words Containing a Substring"<<endl;
            cout<<"3. Remove all Repeated Words (keep the first one only)"<<endl;
            cout<<"4. Show Statistics"<<endl;
            cout<<"5. Save a file and exit"<<endl;
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Option: ";
            cin>>option;
            cout<<endl;



            if(option == '1'){
                OP1(AllPairs);
            }else if(option == '2'){
                OP2(AllPairs);
            }else if(option == '3'){
                OP3(AllPairs);
            }else if(option == '4'){
                OP4(AllPairs);
            }else if(option == '5'){
                OP5(AllPairs, outputFilePath);
            }
            else{
                cout<<"Invalid option"<<endl;
            }
    }
    return 0;
}

string printCabecalho(){
    string cabecalho;
    cout<<"==================================== C++ ========================================="<<endl;
    cout<<"| =========                     |"<<endl;
    cout<<"| \\      /  File                |   FILE MANIPULATOR HACK"<<endl;
    cout<<"|  \\    /   Manipulator         |   Version:  v1.0"<<endl;
    cout<<"|   \\  /    Hack                |"<<endl;
    cout<<"+---------------------------------------------------------------------------------"<<endl;
    cout<<"|"<<endl;
    cout<<"| Description: A C++ software to handle files."<<endl;
    cout<<"|"<<endl;
    cout<<"| Author: Ítalo"<<"\t\t\t"<<"student ID: 23150813"<<endl;
    cout<<"|"<<endl;
    cout<<"==================================== C++ ========================================="<<endl;

    return cabecalho;
}

void OP1(vector<pair<string, vector<string>>> &AllPairs){
    cout<<"************ LOAD A FILE ***********"<<endl;
    cout<<"Enter a path: ";
    string path;
    cin>>path;
    vector <string> textVector;

    if(!ReadFile(path, textVector)){
        cout<<"Error! File not found"<<endl;
    }else {
        AllPairs.push_back(make_pair(path, textVector));
    }

    cout<<"File successfully added into AllPairs"<<endl;
    cout<<endl;

    /*for (size_t i = 0; i<AllPairs.size(); i++) {
        cout << "File: "<< AllPairs.at(i).first << endl;
        for(size_t j = 0; j<AllPairs.at(i).second.size();j++){
            cout<< AllPairs.at(i).second.at(j) << endl;
        }
    }*/
}

void OP2(vector<pair<string, vector <string>>> &AllPairs){
    cout<<"************ REMOVE A WORD CONTAINING A SUBSTRING ***********"<<endl;
    cout<<"Enter a substring to remove all occurrences: ";
    string sub;
    cin>>sub;

    for (size_t i = 0; i < AllPairs.size(); i++) {
        vector <string> &word = AllPairs.at(i).second;
        for(size_t j = 0; j<word.size();){
            if(word.at(j).find(sub) != string::npos){
                word.erase(word.begin()+j);
            } else {
                j++; //incrementa apenas quando a palavra não é removida
            }
        }
    }

    cout<<"Words have been removed succesfully"<<endl;
    cout<<endl;
    
    /*for (size_t i = 0; i<AllPairs.size(); i++) {
        cout << "File: "<< AllPairs.at(i).first << endl;
        for(size_t j = 0; j<AllPairs.at(i).second.size();j++){
            cout<< AllPairs.at(i).second.at(j) << endl;
        }
    }*/
}

void OP3(vector<pair<string, vector <string>>> &AllPairs){
    cout<<"******* REMOVE ALL REPEATED WORDS (KEEP THE FIRST ONE ONLY) *******"<<endl;
    cout<<"Enter a string to remove: ";
    string str;
    cin>>str;

    for (size_t i = 0; i < AllPairs.size(); i++) {
        vector<string> &word = AllPairs.at(i).second;
        RemoveDuplicates(word, str); // Chame a função RemoveDuplicates para cada vetor de strings
    }

    cout<<"Words have been removed succesfully"<<endl;
    cout<<endl;
    
    /*for (size_t i = 0; i<AllPairs.size(); i++) {
        cout << "File: "<< AllPairs.at(i).first << endl;
        for(size_t j = 0; j<AllPairs.at(i).second.size();j++){
            cout<< AllPairs.at(i).second.at(j) << endl;
        }
    }*/
}

void OP4(vector<pair<string, vector <string>>> &AllPairs){
    cout<<"********************* STATS *********************"<<endl;
    cout<<"Statistics"<<endl;

    for (size_t i = 0; i<AllPairs.size(); i++) {
        cout << "File: "<< AllPairs.at(i).first << " has "<< AllPairs.at(i).second.size()<<" words."<<endl;
        }
    cout<<"*************************************************"<<endl;
}

void OP5(vector<pair<string, vector <string>>> &AllPairs, const string &outputFilePath){
    cout<<"***************** WRITING STATS*****************"<<endl;
    ofstream outputFile(outputFilePath);

    if(!outputFile.is_open()){
        cout<<"Error! Failed to save file."<<endl;
        return;
    }
    outputFile << "********************* STATS *********************" << endl;
    for (size_t i = 0; i < AllPairs.size(); i++) {
        outputFile << "File: " << AllPairs.at(i).first << " has " << AllPairs.at(i).second.size() << " words." << endl;  
    }
    outputFile << "*************************************************" << endl;

    outputFile.close();
    cout << "Data has been written to " << outputFilePath << endl;
}

bool ReadFile(string &path, vector <string> &textVector){

    ifstream file(path);

    if(!file.is_open()){
        return false;
    }

    string line;
    while(getline(file, line)){
        textVector.push_back(line);
    }

    file.close();

    return true;
}

void RemoveDuplicates(vector<string> &word, const string &str) {
    vector<string> uniqueWords; // um novo vetor para armazenar as palavras únicas
    bool firstOccurrenceFound = false;

    for (const string &w : word) {
        if (w == str) {
            if (!firstOccurrenceFound) {
                uniqueWords.push_back(w); // Mantenha a primeira ocorrência
                firstOccurrenceFound = true;
            }
        } else {
            uniqueWords.push_back(w); // Adicione todas as outras palavras
        }
    }

    word = uniqueWords; // Atualize o vetor original com as palavras únicas
}