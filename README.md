# MINITALK
The purpose of this project is to code a small data exchange program using UNIX signals
## Roadmap Client
Arguments :
- First is the PID of the server
- Second is the message to send

Check Arguments :
- Arguments != 3
- PID isnt only numbers
- Message is NULL

Use atoi to get PID as a number

Printf the  client PID (using getpid()???)

Config the signals :
- ?

Send message :
- Understand kill() and usleep()
    - usleep() creates a delay of time that the program has to wait before continuing
    - usleep has milliseconds in args and sleep has seconds
    - int kill(pid_t pid, int sig);
    - The kill() function allows one process to send a signal to another process,       requesting that the receiving process perform a certain action in response to the signal
- Iterate through each caracter
    - a caracter is 8 bits long
    - set a variable n_bits = 8;
    - iterate on n_bits while decrementing
    - each time check the leftmost bit of the char
        - if == 1 ==> SIGUSR1
        - if == 0 ==> SIGUSR2
    - create a delay with usleep()
    - then shift the bits to the left for the next iteration (c <<= 1)


## BONUS
check if the signal was sent successfully :
    - int result = kill(target_pid, signal_number);
        - if resulat ==  0 ==> success
        - else error