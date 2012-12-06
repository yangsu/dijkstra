# ECE 356 Computer Network Architecture
# Assignment 3 - Negative Weight Discussion
Yang Su
December 5, 2012

## Dijkstra’s Algorithm for Directed Negative Weighted Graph

| Step | N’ | D(B), p(B) | D(C), p(C) | D(D), p(D) |
| :-: | :-: | :-: | :-: | :-: | :-: |
| 1 | A | 1, A | 0, A | 99, A |
| 2 | A, C | 1, A | **0, A** | 99, A |
| 3 | A, C, B | 1, A | 0, A | **99, A** |
| 4 | A, C, B, D | **-201, A D B** | 0, A | 99, A |

## Questions

### 1. Does the result calculated from Dijkstra’s algorithm really represent the shortest path from node A to each other node in the graph?

No. The shortest path from A -> C has a cost of 0 but it's actually -200.

### 2. Explain in details about how the **negative** weight influences the output.

Dijkstra’s algorithm is greedy and once it finalizes the weight for a particular node, it assumes that that's the best answer. However, negative edges that are not visited yet may have an impact on the path and turn out to be the optimal path instead.

### 3. Imagine there are **negative** weight lines in an **undirected** graph, what influences will the negative weight have then?

If the graph is undirected, then all paths in the graph will have a cost of negative infinity as the algorithm will continue to follow the cycles until all the weights are set to negative infinity.