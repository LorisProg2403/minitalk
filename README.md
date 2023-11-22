# MINITALK
The purpose of this project is to code a small data exchange program using UNIX signals
## ROADMAP CLIENT
#### Arguments :
- First is the PID of the server
- Second is the message to send

#### Check Arguments :
- Arguments != 3
- PID isnt only numbers
- Message is NULL

#### Use atoi to get PID as a number

#### Printf the  client PID (using getpid()???)

#### Config the signals :
- this function is setting up signal handlers for SIGUSR1 and SIGUSR2, indicating that the sig_handler function should be called when these signals are received.
- Code sig_handler to write "Character has been sucessfully receoived if signum == SIGUSR2

#### Send message :
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

#### Do an infinit loop to keep the programming up
    - pause() is in

## ROADMAP SERVER

#### No arguments

#### Get pid :
- set pid with getpit()
- printf the server PID

#### Infinite loop :
- call config_signals

#### Config signals :
- same as the client
- call handle_sigsur

#### Handle sigsur
- use 2 static variables to keep tracks of the characters that is being build
    - int bit_itr
    - unsigned char c
- if bit_itr is lower than 0 it means we start a new char so we set it to 7
- if the signum == SIGUSR1 it means a '1' was sent and we need to add it to our char
    - c |= (1 << bit_itr), bit_itr is used to know where to put the 1
    - we dont have to check for SIGUSR2 because the zeros are set bey defaults, we only hav to replace some of them by ones
- if bit_itr is neg and c is not null it means we have char to print
    - we print it
    - set c to null
    - send a signal to indicate that the char has been readed
    ```
    if (kill(info->si_pid, SIGUSR2) == -1)
    handle_errors("Failed to send SIGUSR2")
    return ;
    ```
- if bit_itr isnt neg we sent a signal but this time with SIGUSR1
    
## BONUS
#### check if the signal was sent successfully :
    - int result = kill(target_pid, signal_number);
        - if resulat ==  0 ==> success
        - else error