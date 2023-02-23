import os
import datetime

def create_directory(directory):
    if not os.path.exists(directory):
        os.makedirs(directory)
        print("Directory created")
    else:
        print("Directory already exists")

def create_file(file_name):
    if not os.path.exists(file_name):
        with open(file_name, "w") as f:
            f.write("")
        print("File created")
    else:
        print("File already exists")

for year in range(2015, datetime.datetime.now().year+1):
    dir_level1="AdventOfCode_PY/PY_Advent_of_code_"+str(year)
    create_directory(dir_level1)
    for date in range(1,25+1):
        dir_level2=dir_level1+"/PY_Advent_of_code_"+str(year)+"_"+str(date)
        create_directory(dir_level2)
        #open this dir and add an empty file
        RootFile=dir_level2+"/PY_Advent_of_code_"+str(year)+"_"+str(date)
        create_file(RootFile+"PuzzleInput.txt")
        create_file(RootFile+"output.py")