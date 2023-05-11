#!/usr/bin/python3
# https://github.com/gowen100/Jane-Street-Solutions

import numpy as np
import time

start_time = time.time()

grid = np.array([
    [57,33,132,268,492,732],
    [81,123,240,443,353,508],
    [186,42,195,704,452,228],
    [-7,2,357,452,317,395],
    [5,23,-4,592,445,620],
    [0,77,32,403,337,452]])


def roll(die,i,j):
    # print("original die: {}".format(die))
    #['bot','frt','lft','rgt','bak','top']
    u = [5,1,3,4,6,2]
    d = [2,6,3,4,1,5]
    l = [3,2,6,1,5,4] 
    r = [4,2,1,6,5,3]
    if i==-1 and j==0:
        new_die = [die[i-1] for i in u]
        # print("rolled die in i==-1 and j==0: [up] {}".format(new_die))
        return new_die
    elif i == 1 and j==0:
        new_die = [die[i-1] for i in d]
        # print("rolled die in i==1 and j==0: [down] {}".format(new_die))
        return new_die
    elif i == 0 and j==1:
        new_die = [die[i-1] for i in l]
        # print("rolled die in i==0 and j==1: [left] {}".format(new_die))
        return new_die
    elif i == 0 and j==-1:
        new_die = [die[i-1] for i in r]
        # print("rolled die in i==0 and j==-1: [right] {}".format(new_die))
        return new_die

    
def neighbours(i,j,N):
    neighbours = [[i+x,j+y] for (x,y) in [(-1,0),(0,-1),(1,0),(0,1)] if i+x >= 0 and i+x < N and j+y >= 0 and j+y < N ]
    # print("neighbours: {}".format(neighbours))
    return neighbours


def solve_grid(board):
    dice = [0,0,0,0,0,0]
    N=6
    soln =[]
    brd = np.array(board)
    used = np.ones_like(brd)
    paths = [[dice,used,[0],5,0,0]] #dice,used,score,x,y,step
    
    while len(paths) > 0:
        d,u,score,x,y,step = paths.pop()
        # print("die: {}\n used: {}\n score: {}, x: {}, y: {}, step: {}".format(d, u, score, x, y, step))
        if x == 0 and y == 5:          
            soln = [brd,u,d,score]
        else:
            for a,b in neighbours(x,y,N):
                # print("a: {}, b: {}".format(a, b))
                new_d = roll(d,a-x,b-y)  
                # print("new_die: {}".format(new_d))
                new_u = np.array(u)
                if new_d[5] == 0: 
                    test = (brd[a,b]-score[-1])/(step+1)
                    if test != 0:
                        new_d[5]=test
                        new_u[a,b]=0
                        paths.append([new_d,new_u,score+[brd[a,b]],a,b,step+1])
                        # print("number of paths: {}".format(len(paths)))
                        # print("paths in new_d[5] == 0: {}".format(paths))

                elif new_d[5] == (brd[a,b]-score[-1])/(step+1):
                    new_u[a,b]=0
                    paths.append([new_d,new_u,score+[brd[a,b]],a,b,step+1])
                    # print("number of paths: {}".format(len(paths)))
                    # print("paths in new_d[5] == test: {}".format(paths))

    # print("end of solve function")
    return soln


a,b,d,s = solve_grid(grid)
print("Solution is {:.0f}.\nDice is {}.\nPath is {}".format(np.sum(a*b),np.array(d,dtype=int),s))

end_time = time.time()
elapsed_time = end_time - start_time
# print("Elapsed time: {} seconds".format( elapsed_time))
print("Elapsed time: {} miliseconds".format( elapsed_time * 1000))
