import sys
import time
import csv
import os

import numpy as np

if(len(sys.argv) > 1):
    dim = int(sys.argv[1]); # this is a string!!!

    if(dim > 0):
        # creation matrix
        start = time.time()    
        matrix = [np.arange(0,dim)]
        for i in range(0,dim-1):
            matrix = np.concatenate((matrix, [np.arange(0,dim)]))
        end = time.time()
        tCreation = end - start
        print("Time to create a matrix {}X{} : {} ".format(dim, dim, tCreation))
        # calculate the square
        start = time.time()
        matrix_sq = np.dot(matrix, matrix)
        end = time.time()
        tCalculation = end - start
        print("Time to compute the square of a matrix {}X{} : {} ".format(dim, dim, tCalculation))
        # save results
        fileName = os.getcwd() + os.sep + 'benchmark_results.csv'
        f = open(fileName, 'a', newline='') # append mode, if file doesn't exist it will be created
        writer = csv.writer(f)
        row = ['np', dim, tCreation, tCalculation, tCreation + tCalculation]
        writer.writerow(row)
        f.close()
    else:
        print("The dimension should be greater than zero")
else:
    print("You should insert a dimension")

