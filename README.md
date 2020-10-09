# RMS Scheduler

This is an RMS scheduler that I designed as a part of my project. This simulates an RMS scheduler
for a given set of Periodic, Aperiodic and Sporadic tasks.

# How to Compile and Run?

To compile just download this directory. Navigate to it and enter make



*****************************************************************************************
### Short Note on the code

The sched.h file contains all the functions and structure declarations.
The struct.c file contains all the functions for priority queue
The sched.h file contains all the functions for the scheduling
The main.c is the driver function

The inputs are read from the file named periodic.txt. It is filled in the order

Initial job release  period  execution-time deadlin Task_ID
***************************************************************************************

## The Output of the RMS Scheduler:

>0.000000 3 0.500000 3.000000<br />
>0.000000 4 1.000000 4.000000<br />
>0.000000 6 2.000000 6.000000<br />
>Hyperperiod :: 12<br />
>Job of Task 3 ---->{0.000000  0.500000}<br />
>Job of Task 4 ---->{0.500000  1.400000}<br />
>Job of Task 6 ---->{1.400000  2.999999}<br />
>Job of Task 3 ---->{2.999999  3.499999}<br />
>Job of Task 6 ---->{3.499999  3.999998}<br />
>Job of Task 4 ---->{3.999998  5.999997}<br />
>Job of Task 3 ---->{5.999997  6.499996}<br />
>Job of Task 6 ---->{6.499996  7.999995}<br />
>Job of Task 4 ---->{7.999995  8.899998}<br />
>Job of Task 6 ---->{8.899998  8.999998}<br />
>Job of Task 3 ---->{8.999998  9.500000}<br />
>Job of Task 6 ---->{9.500000  11.900009}<br />
>Job of Task 3 ---->{11.900009 ...<br />

the id is not printed instead the period of the task is printed.

so the line Job of Task 6 ---->{1.400000  2.999999} means "The task with period 6 executed from t=1.4 to t=2.99999.


..................................................................................................................................................
update 1

## A Deffered serever is added to the scheduling ::<br />

I updated the scheduling to a defferd scheduling

## The output of the DEffered Server Scheduler::<br />

>Periodic tasks:<br />
>0.000000 3 0.500000 3.000000<br />
>0.000000 5 1.000000 4.000000<br />
>0.000000 6 2.000000 6.000000<br />
>The aperiodic tasks::<br />
>3.000000 0.500000<br />
>5.000000 1.000000<br />
>ui= 0.700000<br />
>0.056828<br />
>Server budget:: 0.100000 Server Period:: 2<br />
>Hyperperiod :: 30<br />
>Job of Task 3 ---->{ 0.000000  0.500000}<br />
>Job of Task 5 ---->{0.500000  1.400000}<br />
>Job of Task 6 ---->{1.400000 2.999999}<br />
>Aperiodic job {2.999999 3.099999}
>Aperiodic job {3.099999 3.199999}<br />
>Job of Task 3 ---->{3.199999  3.699999}<br />
>Job of Task 6 ---->{3.699999 3.999998}<br />
>Aperiodic job {3.999998 4.099998}<br />
>Aperiodic job {4.099998 4.199998}<br />
>Job of Task 5 ---->{4.999998 5.999997}<br />
>Aperiodic job {5.999997 6.099997}<br />
>Aperiodic job {6.099997 6.199996}<br />
>Job of Task 3 ---->{6.199996  6.699996}<br />
>Job of Task 6 ---->{6.699996 7.999995}<br />
>Aperiodic job {7.999995 8.099995}<br />
>Aperiodic job {8.099995 8.199995}<br />
>Job of Task 3 ---->{8.999998 9.900002}<br />
>Aperiodic job {9.900002 10.000002}<br />
>Aperiodic job {10.000002 10.100002}<br />
>Job of Task 5 ---->{10.100002 11.900009}<br />
>Aperiodic job {11.900009 12.000010}<br />
>Aperiodic job {12.000010 12.100010}<br />
>Job of Task 3 ---->{12.100010  12.600012}<br />
>Job of Task 6 ---->{12.600012 13.900017}<br />
>Aperiodic job {13.900017 14.000017}<br />
>Aperiodic job {14.000017 14.100018}<br />
>Job of Task 3 ---->{14.900021  15.400023}<br />
>Job of Task 5 ---->{15.400023 15.900024}<br />
>Aperiodic job {15.900024 16.000025}<br />
>Aperiodic job {16.000025 16.100025}<br />
>Aperiodic job {17.900032 18.000032}<br />
>Aperiodic job {18.000032 18.100033}<br />
>Job of Task 3 ---->{18.100033  18.600035}<br />
>Job of Task 6 ---->{18.600035 19.900040}<br />
>Aperiodic job {19.900040 20.000040}<br />
>Aperiodic job {20.000040 20.100040}<br />
>Job of Task 5 ---->{20.100040  20.900043}<br />
>Job of Task 3 ---->{20.900043  21.400045}<br />
>Job of Task 5 ---->{21.400045  21.500046}<br />
>Job of Task 6 ---->{21.500046 21.900047}<br />
>Aperiodic job {21.900047 22.000048}<br />
>Aperiodic job {22.000048 22.100048}<br />
>Aperiodic job {23.900055 24.000055}<br />
>Aperiodic job {24.000055 24.100056}<br />
>Job of Task 3 ---->{24.100056  24.600058}<br />
>Job of Task 6 ---->{24.600058  24.900059}<br />
>Job of Task 5 ---->{24.900059  25.800062}<br />
>Job of Task 6 ---->{25.800062 25.900063}<br />
>Aperiodic job {25.900063 26.000063}<br />
>Aperiodic job {26.000063 26.100063}<br />
>Job of Task 3 ---->{26.900066  27.400068}<br />
>Job of Task 6 ---->{27.400068 27.900070}<br />
>Aperiodic job {27.900070 28.000071}<br />
>Aperiodic job {28.000071 28.100071}<br />
>Aperiodic job {29.900078 30.000078}<br />
...


