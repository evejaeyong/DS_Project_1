#include "Manager.h"
using namespace std;

Manager::Manager() {
    queue = new MemberQueue;
    list = new TermsLIST;
    BST = new NameBST;

    BST->setList(list);
    list->setBST(BST);
}

Manager::~Manager() {
    delete queue;
    delete list;
    delete BST;
}

void Manager::run(const char* command) {
    // Open command & log file
    fcmd.open(command);
    flog.open("log.txt");
    if (!fcmd) {
        flog << "Fail to open command file" << endl;
        exit(-1);
    }

    // Run command
    string cmd;
    while (1) {
        fcmd >> cmd;
        if (cmd == "LOAD") LoadData();
        else if (cmd == "ADD") AddData();
        else if (cmd == "QPOP") PopData();
        else if (cmd == "SEARCH") SearchData();
        else if (cmd == "PRINT") PrintData();
        else if (cmd == "DELETE") DeleteData();
        else if (cmd == "EXIT") {
            PrintSuccess(cmd.c_str());
            break;
        }
        else {
            PrintErrorCode(1000);
        }

    }

    fcmd.close();
    flog.close();
    return;
}

void Manager::PrintSuccess(const char* cmd) {
    flog << "===== " << cmd << " =====\n";
    flog << "Success\n";
    flog << "===============\n\n";
}

void Manager::PrintErrorCode(int num) {
    flog << "===== ERROR =====\n";
    flog << num << endl;
    flog << "===============\n\n";
}

// LOAD
void Manager::LoadData() {
    ifstream fdata;
    fdata.open("data.txt");

    if (!fdata) {
        PrintErrorCode(100);
    }
    else if (!queue->empty() || list->getHead() != NULL || BST->getRoot() != NULL) {
        PrintErrorCode(100);
    }
    else {
        string line;
        flog << "===== LOAD =====\n";
        while (getline(fdata, line)) {
            int len = 0;
            string name, strage, date;
            int age;
            char type;

            while (line[len] != ' ') {
                name.push_back(line[len++]);
            }
            len++;

            while (line[len] != ' ') {
                strage.push_back(line[len++]);

            }
            age = stoi(strage);
            len++;

            while (line[len] != ' ') {
                date.push_back(line[len++]);
            }
            len++;

            type = line[len];
            queue->push(name, age, date, type);

            flog << line << "\n";

        }
        flog << "===============\n\n";
    }
    fdata.close();
}

// ADD
void Manager::AddData() {
    string line;
    getline(fcmd, line);

    int len = 1;
    string name, strage, date;
    int age;
    char type;

    while (line[len] != ' ') {
        name.push_back(line[len++]);
        if (line[len] == NULL) {
            PrintErrorCode(200);
            return;
        }
    }
    len++;

    while (line[len] != ' ') {
        strage.push_back(line[len++]);
        if (line[len] == NULL) {
            PrintErrorCode(200);
            return;
        }
    }
    age = stoi(strage);
    len++;

    while (line[len] != ' ') {
        date.push_back(line[len++]);
        if (line[len] == NULL) {
            PrintErrorCode(200);
            return;
        }
    }
    len++;

    type = line[len];
    if (type == NULL) {
        PrintErrorCode(200);
        return;
    }

    queue->push(name, age, date, type);

    flog << "===== ADD =====\n";
    flog << name << "/" << age << "/" << date << "/" << type << "\n";
    flog << "===============\n\n";
}

// QPOP
void Manager::PopData() {
    if (queue->empty()) PrintErrorCode(300);
    else {
        while (!queue->empty()) {
            MemberQueueNode popNode = queue->pop();
            list->insertData(popNode);
            BST->insertData(popNode);
        }
        PrintSuccess("QPOP");
    }
}

// SEARCH
void Manager::SearchData() {
    string name;
    fcmd >> name;

    NameBSTNode* node = BST->searchData(name);
    if (node == NULL) {
        PrintErrorCode(400);
    }
    else {
        flog << "===== SEARCH =====\n";
        flog << node->getName() << "/" << node->getAge() << "/" << node->getStart().year << "-" << node->getStart().month << "-" << node->getStart().day
            << "/" << node->getEnd().year << "-" << node->getEnd().month << "-" << node->getEnd().day << "\n";
        flog << "===============\n\n";
    }

}

// PRINT
void Manager::PrintData() {
    string name;
    fcmd >> name;

    if ('A' <= name[0] && name[0] <= 'D') {
        if (list->searchData(name[0])->getBST()->getRoot() == NULL) {
            PrintErrorCode(500);
            return;
        }
        flog << "===== PRINT =====\n";
        flog << "Terms_BST " << name[0] << "\n";
        flog.close();
        list->searchData(name[0])->getBST()->printData(list->searchData(name[0])->getBST()->getRoot());
    }
    else {
        if (BST->getRoot() == NULL) {
            PrintErrorCode(500);
            return;
        }
        flog << "===== PRINT =====\n";
        flog << "Name_BST\n";
        flog.close();
        BST->printData(BST->getRoot());
    }
    flog.open("log.txt", ios::app);
    flog << "===============\n\n";
    return;
}

// DELETE
void Manager::DeleteData() {
    string st, data;
    fcmd >> st >> data;

    if (st == "DATE") {
        Day end;
        end.year = (data[0] - '0') * 1000 + (data[1] - '0') * 100 + (data[2] - '0') * 10 + (data[3] - '0');
        end.month = (data[5] - '0') * 10 + (data[6] - '0');
        end.day = (data[8] - '0') * 10 + (data[9] - '0');
        if (list->DeleteData(end) == true) {
            PrintSuccess("DELETE");
        }
        else PrintErrorCode(600);
    }

    else if (st == "NAME") {
        if (BST->deleteData(data) == true) {
            PrintSuccess("DELETE");
        }
        else PrintErrorCode(600);
    }

    return;
}
