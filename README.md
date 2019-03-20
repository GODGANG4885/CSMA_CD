# CSMA_CD
CSMA/CD (Carrier Sense Multiple Access/ Collision Detection) is a media-access control method widely used in Ethernet technology/LANs.
Consider a scenario where there are ‘n’ stations on a link and all are waiting to transfer data through that channel. In this case all ‘n’ stations would want to access the link/channel to transfer their own data.Problem arises when more than one station transmits the data at the moment. In this case, there will be collisions in the data from different stations.

CSMA/CD is one such technique where different stations that follow this protocol agree on some terms and collision detection measures for effective transmission. This protocol decides which station will transmit when so that data reaches the destination without corruption.

How CSMA/CD works?

Step 1: Check if the sender is ready for transmitting data packets.
Step 2: Check if the transmission link is idle?
Sender has to keep on checking if the transmission link/medium is idle. For this it continously senses transmissions from other nodes. Sender sends dummy data on the link.If it does not receive any collision signal, this means the link is idle at the moment.If it senses that the carrier is free and there are no collisions, it sends the data. Otherwise it refrains from sending data.
Step 3: Transmit the data & check for collisions.
Sender transmits its data on the link. CSMA/CD does not use ‘acknowledgement’ system. It checks for the successful and unsuccessful transmissions through collision signals. During transmission, if collision signal is received by the node, transmission is stopped. The station then transmits a jam signal onto the link and waits for random time interval before it resends the frame. After some random time, it again attempts to transfer the data and repeats above process.
Step 4: If no collision was detected in propagation, the sender completes its frame transmission and resets the counters.
