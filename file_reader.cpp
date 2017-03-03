#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

int tagInVector(vector<string>, string);

int main()
{
    vector<string> test;
    
    vector<string> uniqueTags;
    vector<int> tagUsage;
//    ifstream file("Items.xml");
    ifstream file("test.txt");
    string line;
    int longestString = 0;
    
    while (getline(file, line))
    {
        static string tag;
        static bool addToString = 0;
        
        for (int i = 0; i < line.length(); i++)
        {
            if (static_cast<char>(line[i]) == '<')
            {
                   addToString = 1;
                   continue;
            } else if (static_cast<char>(line[i]) == '>')
            {
                   addToString = 0;
                   static int location = tagInVector(uniqueTags, line);
                   cout << " " << location << " ";
                   
                   for (int o = 0; o < uniqueTags.size(); o++)
                   {
                       cout << uniqueTags[o] << endl;
                   };
                   
                   if (location < 0)
                   {
                         uniqueTags.push_back(tag);
                         cout << "New Tag Found: " << tag << endl;
                         tagUsage.push_back(1);
                         if (tag.length() > longestString)
                         {
                              longestString = tag.length();
                         };
                   } else
                   {
                         tagUsage[location]++;
                   };
                   tag = "";
                   
                   continue;
            } else
            {
                  if (addToString)
                  {
                      tag += line[i];
                      continue;
                  };
            };
        };
    };
    
    cout << "Operation complete." << endl;
    
    cout << "Unique Tags:" << endl;
    for (int i = 0; i < uniqueTags.size(); i++)
    {
        cout << setw(longestString + 1) << left << uniqueTags[i] << "= " << tagUsage[i] << endl;
    };
    
    system("pause");
    
    return 0;
};

int tagInVector(vector<string> v, string s)
{
     int output = -1;
     int i;
     for (i = 0; i < v.size(); i++)
     {
     
         if (v[i] == s)
         {
            output = i;
         };
     };
     return output;
};
