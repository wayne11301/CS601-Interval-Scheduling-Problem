//
//  Name: Yi-Nong Wei, Vijayalaxmi Patil
//

#include <sstream>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstring>
#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct JobDetails {

    int jobindex;
    int starttime;
    int endtime;

    JobDetails(int i, int start, int end) {
        jobindex = i;
        starttime = start;
        endtime = end;

    }
};

bool sortedjobs(JobDetails j1, JobDetails j2)
{
    return(j1.endtime < j2.endtime);
}


int main(int argc, const char* argv[]) {

    ifstream inFile;
    string inFileName;
    string command, finput, sinput, line;
    int numofjobs = 0;
    vector<pair<string, string>> tempjob;

    // char * dir = getcwd(NULL, 0); // Platform-dependent, see reference link below
    // printf("Current dir: %s", dir);

    cout << "Enter name of Input file; press return." << endl;
    cin >> inFileName;
    inFile.open(inFileName.c_str());

    if (!inFile)
    {
        cout << "File not found." << endl;
        exit(2);
    }

    inFile >> command;
    numofjobs = stoi(command);
    inFile.ignore();
    while (getline(inFile, line, '\n')) {//!inFile.eof() &&
        stringstream ss(line);
        getline(ss, sinput, ',');
        getline(ss, finput, ',');
        tempjob.push_back(make_pair(sinput, finput));
    }

    // JobDetails jobs[numofjobs];

    vector<JobDetails> jobs{};

    for (int i = 0; i < tempjob.size(); i++)
    {
        //cout << tempjob[i].first << " " << tempjob[i].second << endl;
        int jindex = i + 1;
        int jfirst = stoi(tempjob[i].first);
        int jsecond = stoi(tempjob[i].second);
        jobs.emplace_back(JobDetails(jindex, jfirst, jsecond));

    }

    int jobsize = jobs.size();                         // sizeof(jobs)/sizeof(jobs[0]);

/*    cout<<"before sort"<<endl;
   for(int i = 0; i < jobsize; i++)
    {
        cout << jobs[i].jobindex << " " << jobs[i].starttime << " " << jobs[i].endtime << endl;

    }*/

    sort(jobs.begin(), jobs.end(), sortedjobs);

    /*   cout<<"after sort"<<endl;
       for(int i = 0; i < jobsize; i++)
       {
           cout << jobs[i].jobindex << " " << jobs[i].starttime << " " << jobs[i].endtime << endl;

       }*/

    int x = 0;

    cout << "Jobs selected are " << jobs[x].jobindex << " ";
    for (int y = 1; y < jobsize; y++)
    {
        //  cout<<"job compare: "<<jobs[x].endtime<<" "<<jobs[y].starttime<<endl;
        if (jobs[x].endtime <= jobs[y].starttime)
        {
            cout << jobs[y].jobindex << " ";
            x = y;

        }
    }
    cout << endl;

    return 0;
}
