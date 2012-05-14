# Basics

Each connected node will connect to *all* other nodes available on the network.

A local cache file is kept to ease reconnect, but nodes not seen for more than
24 hours are automatically forgotten. When daemon starts, all nodes in cache
file are considered "seen" starting the instant the daemon started to avoid
unwanted cache flush.

Each node will attempt to keep a connection to every single other node on the
network. Not connected nodes are considered temporarily down, but are still
counted in the lock acquiring algo.

Because all nodes are connected to each other, no relaying of inter-node
messages is required.

## Lock acquiring

Obtaining a lock is possible only if half of the "up" nodes have replied to the
lock request. A client wanting to acquire a lock will first check its local
database, then it will query all the other nodes to request authorization. Each
node receiving the lock request will check their own internal lock database,
and reply to confirm to requesting node if the lock could be obtained or not.

As soon as at least 50%+1 of the known nodes have replied OK, the node will
confirm to its client that the lock could be obtained.

If two nodes are requesting the same lock at the same time, only one will be
able to get 50%+1 of the locks. If one node gets a refusal before getting 50%+1
acceptation, it will immediately release its lock and retry after a random
amount of time (1ms~50ms).

If the node's local database already contains a lock with the same name, the
node will request a queued lock, with a sequence ID matching the next free ID
in its local database. Same rule apply to acquiring the sequence ID.

Each lock request also comes with a unique UUID used to identify it. Any change
in a lock request will require a new ID. Aborted locks must be notified to
all nodes.

When a lock refuses a lock, it will transmit the ID of the winning lock. If
more than 50%+1 nodes reply to a node with the same ID, it will release its own
lock and notify other nodes that this other ID won the lock.

