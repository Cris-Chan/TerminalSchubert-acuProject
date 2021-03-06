#include <iostream>
#include <vector>
#include "User.h"
#include <stack>
//#include "Story.h"
//#include "CoreMechanics.h"
//#include "User.h"
//#include "SpoofedTerminalObject.h"
using namespace std;

class CoreMechanics{
private:
    string directories[14];
//    string nakedPath;
    string dirPath;
    string commands[6];
    string currentDirLocation;
    int dirCount;
    User* gamePlayer;
    stack<string> dirStack;
    vector<string> captureableFiles;
    string objective;
    vector<string> majorDirs;
    bool finalSceneHappened;
    bool gameIsFinished;
public:
    CoreMechanics(User* player){
//        nakedPath = "~";
        gamePlayer = player;
        dirPath = "Schubert:~ philSchubertMacBook$ ";
        populateDir();
        populateCommands();
        dirCount = 14;
        currentDirLocation = "home";
        objective = "Look around Mr.Schubert's computer (sorry Mr.Schubert) and find where he stores all the grades!\n";
        majorDirs.push_back("home");
        majorDirs.push_back("desktop");
        majorDirs.push_back("downloads");
        majorDirs.push_back("documents");
        
        captureableFiles.push_back("communistActivationFile1.rus");
        captureableFiles.push_back("communistActivationFile3.rus");
        captureableFiles.push_back("communistActivationFile2.rus");
        captureableFiles.push_back("TerminalPassword.bat");
        
        finalSceneHappened = false;
        gameIsFinished = false;
    }
    
    void populateDir();
    void populateCommands();
    void passedCommand(string command) const;
    
    //GETTER
    bool gameIsFinishedGET()const{return gameIsFinished;}
    string dirPathGET()const{return dirPath;}
    string currentDirLocationGET()const{return currentDirLocation;}
    string objectiveGET()const{return objective;}
    bool finalSceneHappenedGET()const{return finalSceneHappened;}
    
    //SETTER
    void gameIsFinishedSET(bool input){gameIsFinished = input;}
    void dirPathSET(string value){dirPath = value;}
    void currentDirLocationSET(string value){currentDirLocation = value;}
    void objectiveSET(string value){objective = value;}
    void finalSceneHappenedSET(bool value){finalSceneHappened = value;}
    
    
    void printObjective()const{
        cout << "\nCurrent objective: " << objectiveGET() << endl;
    }
    
    
    void updateDirPath(){
        dirPath = "Schubert:" + currentDirLocation + " philSchubertMacBook$ ";
    }
    
    void clearScreen()const;
    void printTextAnimation(const string& message)const;
    void printTextAnimation(int speed, const string& message)const;
    
    
    void prompEnterToContinue()const{
        cout << "\n(press enter)\n";
        string nothing;
        getline(cin, nothing);
    }
    string getChoice()const;
    
    
    void animationLoading(int numberOfLoops)const;
    void animationLoading(int numberOfLoops, string passedText)const;
    
    
    //CONSOLE FUNCTIONS (most likely will be grouped into seperate function)----
    // will stay in core to be consistent with adventure game outline for now---
    
    void renderMajorDirs();
    void renderDirContents(string currentDir);
    void myTerminal()const;
    void beginTerminalLoop(string startingDir);
    void cd(string dir); // unfinished
    void ls()const; // unfinished
    void help()const; // unfinished
    void read(string filename); // unfinished
    void run(string exeName);
    bool isSupportedDir(string dir)const;
    bool isCaptureReady(string file)const;
    void startFinalScene();
    
};


