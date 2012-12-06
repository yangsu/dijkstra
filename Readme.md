# Computer Network Architecture
# Assignment 3 ECE 356
Yang Su
December 5, 2012

## Dijkstra’s Routing Algorithm

### How to run
```bash
g++ dijkstra.cpp -o dijkstra && ./dijkstra
```

### Output
```
Shortest path to A : [ O A ]  Cost: 2
Shortest path to B : [ O A B ]  Cost: 4
Shortest path to C : [ O C ]  Cost: 4
Shortest path to D : [ O A B D ]  Cost: 8
Shortest path to E : [ O A B E ]  Cost: 7
Shortest path to F : [ O A F ]  Cost: 14
Shortest path to T : [ O A B D T ]  Cost: 13
```

### References
http://en.wikipedia.org/wiki/Dijkstra's_algorithm