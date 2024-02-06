# How much memory of the phone is actually avaiable via termux? 
- cat /proc/meminfo 

MemTotal:        3831756 kB ~ 4GB
MemFree:           65924 kB
MemAvailable:    1491556 kB 

- ram_test.c:
filled 3085352960 b ~ 2.87 GB
then android killed the termux process


# How to use adreno device via opencl?

- checked .so files in /system/vendor/lib/ and /system/vendor/lib64/
- found libOpenCL.so in both folders, stackoverflow comment says snapdragon uses 64bit version
- clone openCL-Headers from https://github.com/KhronosGroup/OpenCL-Headers
- tried compiling against those headers + libOpenCL.so, have to check opencl version on adreno 506 gpu
- SOLUTION: https://developer.qualcomm.com/qfile/33472/80-nb295-11_c.pdf
