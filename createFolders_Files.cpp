#include <bits/stdc++.h>
#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>
#include <string>
#include <fstream>
#include <ctime>

void create_dir(const std::string& path){
    const char* dir_name = path.c_str();
    if (mkdir(dir_name, 0777) == -1)
        std::cerr<<"Error :  "<< strerror(errno)<<"\n";
 
    else
        std::cout<<"Directory created\n";
}
void create_files(const std::string& dir_level2,const int& year, const int& date){
    std::string dir_level3a=dir_level2+"/CPP_Advent_of_code"+std::to_string(year)+"_"+std::to_string(date)+"output.cpp";
    std::ofstream file(dir_level3a);
    file<<"#include <stdio.h>\n#include <iostream>\n#include <vector>\n#include<fstream>\n";
    file.close();
    std::cout<<"File created\n";
    std::cout << "File created : " << dir_level3a << std::endl;

    std::string dir_level3b=dir_level2+"/CPP_Advent_of_code"+std::to_string(year)+"_"+std::to_string(date)+"PuzzleInput.txt";
    std::ofstream file1(dir_level3b);
    file1.close();
    std::cout<<"File created\n";
    std::cout << "File created : " << dir_level3b << std::endl;
}
int get_current_year(){
    time_t current_time;
    current_time = time(NULL);
    int currentYear = 1970 + current_time / 31537970; 
    return currentYear;
}

int main(){
    const int CurrenYear = get_current_year();
    for (int year=2015; year<=CurrenYear; year++){
        std::string dir_level1="AdventOfCode_CPP/CPP_Advent_of_code_"+std::to_string(year);
        create_dir(dir_level1);
        for(int date=1;date<=25;date++){
            std::string dir_level2 = dir_level1+"/CPP_Advent_of_code_"+std::to_string(year)+"_"+std::to_string(date);
            create_dir(dir_level2);
            create_files(dir_level2,year,date);
        }
    }
}