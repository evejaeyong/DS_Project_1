#include "Manager.h"
using namespace std;

Manager::Manager() {
    queue = new MemberQueue;
    list = new TermsLIST;
    BST = new NameBST;          //Member variable Dynamic allocation

    BST->setList(list);
    list->setBST(BST);          //Connect list and BST each other
}

Manager::~Manager() {
    delete queue;
    delete list;
    delete BST;                 //Dynamic allocation release
}

void Manager::run(const char* command) {
    // Open command & log file
    fcmd.open(command);
    flog.open("log.txt");
    if (!fcmd) {
        flog << "Fail to open command file" << endl;
        exit(-1);               //Program Exit
    }

    // Run command
    string cmd;                
    while (1) {
        fcmd >> cmd;                   //Receive commands
        if (cmd == "LOAD") LoadData();
        else if (cmd == "ADD") AddData();
        else if (cmd == "QPOP") PopData();
        else if (cmd == "SEARCH") SearchData();
        else if (cmd == "PRINT") PrintData();
        else if (cmd == "DELETE") DeleteData();
        else if (cmd == "EXIT") {
            PrintSuccess("EXIT");
            break;                      //Stop Receive commands
        }
        else {
            PrintErrorCode(1000);       //if invalid command, Print Error Code 1000
        }

    }

    fcmd.close();
    flog.close();                       //close file
    return;
}

void Manager::PrintSuccess(const char* cmd) {
    flog << "===== " << cmd << " =====\n";
    flog << "Success\n";
    flog << "===============\n\n";              //Print Success Messege at log.txt
}

void Manager::PrintErrorCode(int num) {
    flog << "===== ERROR =====\n";
    flog << num << endl;
    flog << "===============\n\n";              //Print Error Code at log file
}

// LOAD
void Manager::LoadData() {
    ifstream fdata;
    fdata.open("data.txt");                     //Open data file

    if (!fdata) {                               //if data file don't exist
        PrintErrorCode(100);                    //Print Error Code 100
    }
    else if (!queue->empty() || list->getHead() != NULL 
            || BST->getRoot() != NULL) {        //if data already exists
        PrintErrorCode(100);                    //Print Error Code 100
    }
    else {                                      //normal case
        string line;
        flog << "===== LOAD =====\n";
        while (getline(fdata, line)) {          //Get one line at data file
            int len = 0;
            string name, strage, date;
            int age;
            char type;

            while (line[len] != ' ') {          //Parsing name
                name.push_back(line[len++]);
            }
            len++;

            while (line[len] != ' ') {          //Parsing age
                strage.push_back(line[len++]);

            }
            age = stoi(strage);                 //string to int
            len++;

            while (line[len] != ' ') {          //Parsing date
                date.push_back(line[len++]);
            }
            len++;

            type = line[len];                   //Get type
            queue->push(name, age, date, type); //push at MemberQueue

            flog << line << "\n";               //Print One line at log file

        }
        flog << "===============\n\n";
        
    }
    fdata.close();
    
}

// ADD
void Manager::AddData() {
    string line;
    getline(fcmd, line);                //Get One line

    int len = 1;                        //Start from 1 to ignore blank characters
    string name, strage, date;
    int age;
    char type;

    while (line[len] != ' ') {          //Parsing name
        name.push_back(line[len++]);
        if (line[len] == NULL) {        //if have less data
            PrintErrorCode(200);        //Print Error Code 200
            return;
        }
    }
    len++;

    while (line[len] != ' ') {          //Parsing age
        strage.push_back(line[len++]);
        if (line[len] == NULL) {        //if have less data
            PrintErrorCode(200);        //Print Error Code 200
            return;
        }
    }
    age = stoi(strage);
    len++;

    while (line[len] != ' ') {          //Parsing date
        date.push_back(line[len++]);
        if (line[len] == NULL) {        //if have less data
            PrintErrorCode(200);        //Print Error Code 200
            return;
        }
    }
    len++;

    type = line[len++];                 //Get type
    if (type == NULL) {                 //if have less data
        PrintErrorCode(200);            //Print Error Code 200
        return;
    }

    queue->push(name, age, date, type); //push at MemberQueue

    flog << "===== ADD =====\n";
    flog << name << "/" << age << "/" << date << "/" << type << "\n";
    flog << "===============\n\n";      //Print Success Messege at log file
}

// QPOP
void Manager::PopData() {
    if (queue->empty()) PrintErrorCode(300);        //if MemberQueue is Empty Print Error Code 300
    else {
        while (!queue->empty()) {
            MemberQueueNode popNode = queue->pop(); //Get Data at MemberQueue
            list->insertData(popNode);              //Push at Termslist
            BST->insertData(popNode);               //Push at NameBST
        }
        PrintSuccess("QPOP");                       //Print Success Messege
    }
}

// SEARCH
void Manager::SearchData() {
    string name;
    fcmd >> name;                               //Get name at command file

    NameBSTNode* node = BST->searchData(name);
    if (node == NULL) {                         //if BST can't find same name
        PrintErrorCode(400);                    //Print Error Code 400
    }
    else {
        flog << "===== SEARCH =====\n";
        flog << node->getName() << "/" << node->getAge() << "/" << node->getStart().year << "-" << node->getStart().month << "-" << node->getStart().day
            << "/" << node->getEnd().year << "-" << node->getEnd().month << "-" << node->getEnd().day << "\n";
        flog << "===============\n\n";          //if Success, Print Success Messege And data
    }

}

// PRINT
void Manager::PrintData() {
    string type;
    fcmd >> type;               //Get Print type

    if ('A' <= type[0] && type[0] <= 'D') {         //if Print at TermsBST
        if (list->searchData(type[0]) == NULL) {    //if BST doesn't exist
            PrintErrorCode(500);                    //Print Error Code 500
            return;
        }

        flog << "===== PRINT =====\n";              //Print Success Messege
        flog << "Terms_BST " << type[0] << "\n";
        flog.close();                               //Close the log file to open it in the TermsBST class
        list->searchData(type[0])->getBST()->printData(list->searchData(type[0])->getBST()->getRoot());
    }
    else {
        if (BST->getRoot() == NULL) {               //if BST data doesn't exist
            PrintErrorCode(500);
            return;
        }
        flog << "===== PRINT =====\n";              //Print Success Messege
        flog << "Name_BST\n";
        flog.close();                               //Close the log file to open it in the NameBST class
        BST->printData(BST->getRoot());
    }
    flog.open("log.txt", ios::app);                 //Open the log file
    flog << "===============\n\n";
    return;
}

// DELETE
void Manager::DeleteData() {
    string st, data;
    fcmd >> st >> data;         //Get Data

    if (st == "DATE") {
        Day end;
        end.year = (data[0] - '0') * 1000 + (data[1] - '0') * 100 + (data[2] - '0') * 10 + (data[3] - '0');
        end.month = (data[5] - '0') * 10 + (data[6] - '0');
        end.day = (data[8] - '0') * 10 + (data[9] - '0');
        if (list->DeleteData(end) == true) {    //if Delete Data Success
            PrintSuccess("DELETE");
        }
        else PrintErrorCode(600);               //if don't exist Data, print error code
    }

    else if (st == "NAME") {
        if (BST->deleteData(data) == true) {    //if Delete Data Success
            PrintSuccess("DELETE");
        }
        else PrintErrorCode(600);               //if don't exist Data, print error code
    }

    return;
}
