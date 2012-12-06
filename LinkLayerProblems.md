# ECE 356 Computer Network Architecture
# Assignment 3 - Link Layer Problems
Yang Su
December 5, 2012

## Problems

For Slotted ALOHA protocol, let N represents the number of nodes within the network, \\(p (0 < p <1)\\) represents the probability of transmitting a frame, and e represents the protocol efficiency. The delay of a packet is equal to the number of slots that the packet experiences. For example, if the packet from node 0 experiences the following time slots: E C E E S (E-empty, C-collision, S-successful), then the delay of this packet is 5. The average delay d is defined as the mean value of all the packets delays. For example, if a network has 3 nodes, and each node has only one packet to send. Node1’s packet delay is 5, node2’s packet delay is 3, node3’s packet delay is 4, then the average delay for this network is \\((5+3+4)/3=4\\).

### 1. If p = 0.25, N = 4, calculate the theoretical value of protocol efficiency e?
$$
\begin{align}
Efficiency &= N * p * (1-p)^{N-1} \\\\
           &= 4 * 0.25 * (0.75)^3\\\\
           &= 0.422\\\\
\end{align}
$$

#### 2. If let N be a fixed value, and let user define the packet transmission probability \\(p (0 < p <1)\\). Draw a rough graph that reflects the relationship between transmission probability p and the protocol efficiency e. Briefly explain your graph.
![](A3-2.png)

As the probability of transmission increases, the protocol efficiency approaches the maximum efficiency and then tapers off due to collisions.

#### 3. If let N be a fixed value, and let user define the packet transmission probability \\(p (0 < p <1)\\). Draw a graph that reflects the relationship between transmission probability p and the average packet delay d. Briefly explain your graph.
![](A3-3.png)
The average packet delay approaches infinity as the transmission probability approaches 0, when there's no packet transmitted, or 1, when packets are continuously transmitted and collide

#### 4. If let \\(p (0 < p <1)\\) be a fixed value, and let user define the number of nodes N. Draw a rough graph that reflects the relationship between the number of nodes N and the protocol efficiency e. Briefly explain your graph.
![](A3-4.png)
Limit of Efficiency for slotted ALOHA can be calculated as follows:
$$
\lim_{N \rightarrow \infty} N*p(1-p)^{N-1} = \frac {1} {e} = 0.37
$$

#### 5. If let \\(p (0 < p <1)\\) be a fixed value, and let user define the number of nodes N. Draw a graph that reflects the relationship between the number of nodes N and the average packet delay d. Briefly explain your graph.
![](A3-5.png)
As N grows and protocol efficiency stays roughly consistent, the chance of collision increases as more nodes can attempt communicate at the same time, thus increasing the average packet delay