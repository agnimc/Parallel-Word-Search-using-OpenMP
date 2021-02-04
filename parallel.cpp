//Parallel Code
#include <stdlib.h>
#include<bits/stdc++.h>
#include <omp.h>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int find_all(string sen, string word_to_search) {
int count = 0;
// Used to split string around spaces.
istringstream ss(sen);
// Traverse through all words
do {
// Read a word
string word;
ss >> word;
if(word == word_to_search){
count++;
}
} while (ss);
return count;
}
int display(string path,string word_to_search) {
int totalCount = 0;
string line;
int count = 1;
ifstream myfile(path);
if (myfile.is_open()) {
while (getline(myfile, line)) {
totalCount += find_all(line, word_to_search);
count++;
}
}
else {
cout << "File not open\n" << endl;
}
return totalCount;
}

int main() {
string Path = "";
string word_to_search = "";
cout<< "Enter a word to search: ";
cin >> word_to_search;
double time = omp_get_wtime();
#pragma omp parallel for
for(int i = 1; i <= 5; i++)
{
string npath = "File" + to_string(i) + ".txt";
//#pragma omp critical
cout<< "Total Count is " + to_string(display(npath, word_to_search)) << " from file"+to_string(i)<<endl;
}
time = omp_get_wtime() - time;
cout << "Time is " + to_string(time);
return 0;
}
