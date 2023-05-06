import sys
import time
import csv
import os

if(len(sys.argv) > 1):
    dim = int(sys.argv[1]); # this is a string!!!

    if(dim > 0):
        # creation matrix
        start = time.time()
        matrix = list(list());
        for i in range(0, dim):
            vector = list();
            for j in range(0, dim):
                vector.append(i);
            matrix.append(vector);
        end = time.time()
        # print(matrix)
        tCreation = end - start
        print("Time to create a matrix {}X{} : {} ".format(dim, dim, tCreation))
        # calculate the square
        start = time.time()
        matrix_sq = list(list())
        for k in range(0,dim):
            vector = list()
            for i in range(0, dim):
                sum = 0
                for j in range(0, dim):
                    sum = sum + matrix[i][j]*matrix[j][i]
                vector.append(sum)
            matrix_sq.append(vector)
        end = time.time()
        tCalculation = end - start
        print("Time to compute the square of a matrix {}X{} : {} ".format(dim, dim, tCalculation))
        # debug print
        if(len(sys.argv) > 2):
            if(sys.argv[2] == "-d"):
                print(matrix_sq)
        # save results
        fileName = os.getcwd() + os.sep + 'benchmark_results.csv'
        f = open(fileName, 'a', newline='') # append mode, if file doesn't exist it will be created
        writer = csv.writer(f)
        row = ['py', dim, tCreation, tCalculation, tCreation + tCalculation]
        writer.writerow(row)
        f.close()
    else:
        print("The dimension should be greater than zero")
else:
    print("You should insert a dimension")

