# RMS Scheduler

This is an RMS scheduler that I designed as a part of my project. This simulates an RMS scheduler
for a given set of Periodic, Aperiodic and Sporadic tasks.

# How to Compile and Run?

To compile just download this directory. Navigate to it and enter make



*****************************************************************************************
The sched.h file contains all the functions and structure declarations.
The struct.c file contains all the functions for priority queue
The sched.h file contains all the functions for the scheduling
The main.c is the driver function

The inputs are read from the file named periodic.txt. It is filled in the order

Initial job release  period  execution-time deadlin Task_ID

*****************************************************************************************
## The Output:

>0.000000 3 0.500000 3.000000
>0.000000 4 1.000000 4.000000
>0.000000 6 2.000000 6.000000
>Hyperperiod :: 12
>Job of Task 3 ---->{0.000000  0.500000}
>Job of Task 4 ---->{0.500000  1.400000}
>Job of Task 6 ---->{1.400000  2.999999}
>Job of Task 3 ---->{2.999999  3.499999}
>Job of Task 6 ---->{3.499999  3.999998}
>Job of Task 4 ---->{3.999998  5.999997}
>Job of Task 3 ---->{5.999997  6.499996}
>Job of Task 6 ---->{6.499996  7.999995}
>Job of Task 4 ---->{7.999995  8.899998}
>Job of Task 6 ---->{8.899998  8.999998}
>Job of Task 3 ---->{8.999998  9.500000}
>Job of Task 6 ---->{9.500000  11.900009}
>Job of Task 3 ---->{11.900009 ...

the id is not printed instead the period of the task is printed.

so the line Job of Task 6 ---->{1.400000  2.999999} means "The task with period 6 executed from t=1.4 to t=2.99999.


..................................................................................................................................................
update 1

a Deffered serever is added to the scheduling ::
the output of the program::
Periodic tasks:
0.000000 3 0.500000 3.000000
0.000000 5 1.000000 4.000000
0.000000 6 2.000000 6.000000
The aperiodic tasks:: 
3.000000 0.500000
5.000000 1.000000
ui= 0.700000
0.056828
Server budget:: 0.100000 Server Period:: 2
Hyperperiod :: 30
Job of Task 3 ---->{ 0.000000  0.500000}
Job of Task 5 ---->{0.500000  1.400000}
Job of Task 6 ---->{1.400000 2.999999}
Aperiodic job {2.999999 3.099999}
3.099999}				//ignore these lines in between aperiodic task execution
Aperiodic job {3.099999 3.199999}
Job of Task 3 ---->{3.199999  3.699999}
Job of Task 6 ---->{3.699999 3.999998}
Aperiodic job {3.999998 4.099998}
4.099998}
Aperiodic job {4.099998 4.199998}
Job of Task 5 ---->{4.999998 5.999997}
Aperiodic job {5.999997 6.099997}
6.099997}
Aperiodic job {6.099997 6.199996}
Job of Task 3 ---->{6.199996  6.699996}
Job of Task 6 ---->{6.699996 7.999995}
Aperiodic job {7.999995 8.099995}
8.099995}
Aperiodic job {8.099995 8.199995}
Job of Task 3 ---->{8.999998 9.900002}
Aperiodic job {9.900002 10.000002}
10.000002}
Aperiodic job {10.000002 10.100002}
Job of Task 5 ---->{10.100002 11.900009}
Aperiodic job {11.900009 12.000010}
12.000010}
Aperiodic job {12.000010 12.100010}
Job of Task 3 ---->{12.100010  12.600012}
Job of Task 6 ---->{12.600012 13.900017}
Aperiodic job {13.900017 14.000017}
14.000017}
Aperiodic job {14.000017 14.100018}
Job of Task 3 ---->{14.900021  15.400023}
Job of Task 5 ---->{15.400023 15.900024}
Aperiodic job {15.900024 16.000025}
16.000025}
Aperiodic job {16.000025 16.100025}
17.900032}
Aperiodic job {17.900032 18.000032}
18.000032}
Aperiodic job {18.000032 18.100033}
Job of Task 3 ---->{18.100033  18.600035}
Job of Task 6 ---->{18.600035 19.900040}
Aperiodic job {19.900040 20.000040}
20.000040}
Aperiodic job {20.000040 20.100040}
Job of Task 5 ---->{20.100040  20.900043}
Job of Task 3 ---->{20.900043  21.400045}
Job of Task 5 ---->{21.400045  21.500046}
Job of Task 6 ---->{21.500046 21.900047}
Aperiodic job {21.900047 22.000048}
22.000048}
Aperiodic job {22.000048 22.100048}
23.900055}
Aperiodic job {23.900055 24.000055}
24.000055}
Aperiodic job {24.000055 24.100056}
Job of Task 3 ---->{24.100056  24.600058}
Job of Task 6 ---->{24.600058  24.900059}
Job of Task 5 ---->{24.900059  25.800062}
Job of Task 6 ---->{25.800062 25.900063}
Aperiodic job {25.900063 26.000063}
26.000063}
Aperiodic job {26.000063 26.100063}
Job of Task 3 ---->{26.900066  27.400068}
Job of Task 6 ---->{27.400068 27.900070}
Aperiodic job {27.900070 28.000071}
28.000071}
Aperiodic job {28.000071 28.100071}
29.900078}
Aperiodic job {29.900078 30.000078}
...

