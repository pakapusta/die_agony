## Die Agony

[Die Agony](https://www.janestreet.com/puzzles/die-agony-index/) is the name of the Jane Street puzzle from December of 2022. I saw an ad for the puzzle at the end of the Numberphile YouTube video and was immediately interested. I was solving it by hand and only sereval months later I found a [repository](https://github.com/gowen100/Jane-Street-Solutions) full of solutions of several Jane Street puzzles. I need to practice C language so I decided to rewrite python solution to C. Original python file, slightly modified with print statements to understand what's going on inside is part of this repo. I did't find any notion of licence in the original repo so I only hope it's not a problem to include original file here. I would like to shout out to the author of the original solution, especially the way author handled dice abstraction is extraordinary, at least to me, mere mortal.

Part of the repo is a Makefile, so simple *make* command should be sufficient to build this.

Other thing I was interested in was how fast could c solution be in comparison with numpy. And it seems pretty, pretty fast. Time taken to execute each solution is part of the code. Optimizing the code for fast execution was not my objective, I am pretty sure there are countless ways how to make this code execute much faster, my main objective was to practice C.

I struggled a lot with memory management, but at the end I think I managed:
```console
% valgrind ./solution
==20509== Memcheck, a memory error detector
==20509== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==20509== Using Valgrind-3.20.0 and LibVEX; rerun with -h for copyright info
==20509== Command: ./solution
==20509== 
Solution is 1935.
Dice is [9.000000, -9.000000, -3.000000, 9.000000, 5.000000, 7.000000]
Path is [0, 5, 23, -4, 32, 77, 23, 2, 42, 123, 33, 132, 240, 123, 81, 186, 42, 195, 357, 452, 592, 403, 337, 452, 620, 395, 317, 452, 704, 443, 353, 508, 732]
The solution took 46.982000 miliseconds to execute.
==20509== 
==20509== HEAP SUMMARY:
==20509==     in use at exit: 0 bytes in 0 blocks
==20509==   total heap usage: 2,084 allocs, 2,084 frees, 108,636 bytes allocated
==20509== 
==20509== All heap blocks were freed -- no leaks are possible
==20509== 
==20509== For lists of detected and suppressed errors, rerun with: -s
==20509== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
