A C++ program to calculate Checksum.

Write a C/C++/Java program to implement checksum. 
The program at sender should first divide data into 16 bit datawords and then add them, wrap around any extra carry bits, find the one's complement of the sum (i.e calculate cheksum), append the checksum with data and send. 
The receiver program should add all the data received (along with the checksum) and check the result. If the result is all 1's accept the data otherwise it should detect error and discard the packet.


