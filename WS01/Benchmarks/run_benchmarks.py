import os
import csv
import pandas as pd
import matplotlib.pyplot as plt

cPath = os.getcwd() + os.sep + 'c' + os.sep
cppPath = os.getcwd() + os.sep + 'cpp' + os.sep
blitzPath = os.getcwd() + os.sep + 'blitz' + os.sep
pyPath = os.getcwd() + os.sep + 'python' + os.sep
npPath = os.getcwd() + os.sep + 'numpy' + os.sep

# build c/cpp executables
if(os.name == 'nt'):
    os.chdir(cPath)
    os.system(cPath + "build_windows.bat")
    os.chdir(cppPath)
    os.system(cppPath + "build_windows.bat")
    os.chdir(blitzPath)
    os.system(blitzPath + "build_windows.bat")
    cExecutable = 'matrix_square.exe'
    cppExecutable = 'matrix_square.exe'
    blitzExecutable = 'matrix_square.exe'
elif(os.name == 'posix'):
    cExecutable = os.getcwd + os.sep + 'c' + os.sep + 'matrix_square.exe'
    cppExecutable = os.getcwd + os.sep + 'cpp' + os.sep + 'matrix_square.exe'

pyExecutable = pyPath + 'matrix_square.py'
npExecutable = npPath + 'matrix_square.py'

executableList = [cExecutable, cppExecutable, blitzExecutable, pyExecutable, npExecutable]

# remove old benchmarks results
pathList = [cPath, cppPath, blitzPath, pyPath, npPath]
for path in pathList:
    benchmarkFile = path + 'benchmark_results.csv'
    if(os.path.exists(benchmarkFile)):
        os.remove(benchmarkFile)

cTuple = (cPath, cExecutable, 'c')
cppTuple = (cppPath, cppExecutable, 'cpp')
blitzTuple = (blitzPath, blitzExecutable, 'blitz') 
pyTuple = (pyPath, npExecutable, 'py')
npTuple = (npPath, npExecutable, 'np')
# set of tests
cBased = [cTuple, cppTuple, blitzTuple]
pyBased = [pyTuple, npTuple]
noLibs = [cTuple, cppTuple, pyTuple]
withLibs = [blitzTuple, npTuple]
all = [cTuple, cppTuple, blitzTuple, pyTuple, npTuple]

# test
#testLanguages = [blitzTuple]
testLanguages = withLibs

# Plots
printTotals = True
printCreations = True
printComputations = True

# run benchmark test
def make_test(start, end):
    step = start
    for i in range(start, end, step):
        for language in testLanguages:
            path = language[0]
            exe = language[1]
            input = ' ' + str(i)
            os.chdir(path)
            os.system(exe + input)      

make_test(10, 100)
make_test(100, 1000)
#make_test(1000, 10000)

# plot results
languages = list()
creations = list()
computations = list()
dimensions = list()
totals = list()
for test in testLanguages:
    path = test[0]
    resultFile = open(path + 'benchmark_results.csv', 'r')
    lines = csv.reader(resultFile, delimiter=',')
    dimension = list()
    creation = list()
    computation = list()
    total = list()
    language = test[2]
    for row in lines:
        dimension.append(float(row[1]))
        creation.append(float(row[2]))
        computation.append(float(row[3]))     
        total.append(float(row[4]))      

    dimensions.append(dimension)
    creations.append(creation)
    computations.append(computation)
    languages.append(language)
    totals.append(total)

    plt.plot(dimension, creation, label='creation')
    plt.plot(dimension, computation, label='computation')
    plt.title(language + ' time')
    plt.xlabel('dim')
    plt.ylabel('time (s)')
    plt.legend()
    plt.grid()
    plt.show()


if(printCreations):
    for i in range(len(creations)):
        plt.plot(dimensions[i], creations[i], label=languages[i])
    plt.title('creation time')
    plt.xlabel('dim')
    plt.ylabel('time (s)')
    plt.legend()
    plt.grid()
    plt.show()

if(printComputations):
    for i in range(len(computations)):
        plt.plot(dimensions[i], computations[i], label=languages[i])
    plt.title('computation time')
    plt.xlabel('dim')
    plt.ylabel('time (s)')
    plt.legend()
    plt.grid()
    plt.show()

if(printTotals):
    for i in range(len(totals)):
        plt.plot(dimensions[i], totals[i], label=languages[i])
    plt.title('total time')
    plt.xlabel('dim')
    plt.ylabel('time (s)')
    plt.legend()
    plt.grid()
    plt.show()


