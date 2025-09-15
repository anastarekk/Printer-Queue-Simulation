# Printer-Queue-Simulation
Printer Queue Management System implemented in C++ using a linked list–based queue data structure.

It simulates how print jobs are scheduled and executed based on their arrival time and execution duration.
The program reads printing jobs from a file (printer.txt), sorts them by arrival time (and duration if equal), and then processes them in order while calculating execution details and waiting times.


# Features

• Custom Queue Implementation: 

 Built from scratch using linked list nodes (no STL containers).

 Supports enqueue, dequeue, peek, display, and empty-check operations.

• Job Scheduling & Sorting: 

 Jobs are sorted by arrival time.

 If two jobs have the same arrival time, the shorter execution time is prioritized.

• Time Conversion:

 Arrival times in HH:MM format are converted to minutes for easier scheduling and comparison.

• Execution Simulation:

 Each job’s start time and waiting time are calculated.

 Jobs are executed sequentially, respecting their arrival time.

• Performance Metrics:

 Total printer occupation time.

 Average waiting time across all jobs.

 Detailed execution log for each job.

 # Example

 input:

 3
 
PC1 08:00 5

PC2 08:02 3

PC3 08:02 7

output:

Jobs Executed: 3

PC1 08:00 5 executed at 8:0 waiting time: 0

PC2 08:02 3 executed at 8:5 waiting time: 3

PC3 08:02 7 executed at 8:8 waiting time: 6

The printer was occupied for 15 minutes

Average waiting time for all jobs is 3 minutes

