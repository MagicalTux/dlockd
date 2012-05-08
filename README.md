# Distributed lock manager

This daemon will manage lock between servers. Only exclusive locks are
possible, but the requestor may choose either to get the lock or fail
immediately, or wait for the lock to be available.

Each instance of dlockd will connect to all the other dlockd daemons, and will
exchange lock information in realtime.
