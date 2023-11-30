# MINITALK
## Kill() :
transmet un signal
## usleep() :
met un delay (usleep mini secs et sleep secs)
## Variables : signum, *info, *ucontent
### signum
Numero du signal, egal a SIGUSR1 ou SIGUSR2
### *info
Permet de recuperer le PID d'ou provient le signal recu
### *ucontent
Jsp on l'utilise pas
## Struct sigaction :
### .sa_sigaction
Fonction handler, elle va gerer le signal recu
### .sa_flags
Ce membre spécifie divers indicateurs de comportement du gestionnaire de signal. Dans votre exemple, SA_SIGINFO est utilisé comme drapeau dans sa_flags, indiquant que le gestionnaire de signal est de type sa_sigaction et non sa_handler. Cela permet l'utilisation d'informations supplémentaires fournies par siginfo_t.
## sigemptyset() :
 Cette fonction est utilisée pour initialiser un ensemble de signaux vide (sa_mask). Cela garantit que, par défaut, aucun signal n'est bloqué pendant l'exécution du gestionnaire de signal.
## sigaction() :
Utiliser pour definir le gestionnaire de signal de SIGUSR1 et SIGUSR2 comme etant handle_sigusr()
## Struct pid_t
Permet de recuperer le PID (Process ID), c'est un int 32 bytes
