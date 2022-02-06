# HashGraph
The data structure implemented allows **to store a directed graph into an hash table.** Each node of the graph with the adjacency list is put in a different hash table's cell.
The algorithm reads the data from a input file and the user should be able to perform the following operations:
- Show the graph 
- Add an edge between two nodes
- Remove an edge between two nodes
- Find an edge
- Depth First Search
- Delete a node

## Input file format 
The input file must be a .txt file and the data to insert into the graph are integers. The first row, as the following ones, contains two numbers separeted by a space which represents the number of nodes and the number of edges.
Then, the edges are listed accordingly by specifying the source and the target node.

### Example 
<img src="https://github.com/Salvatore-tech/HashGraph/blob/master/resources/input_graph.png" width="400" height="400">

The input file that represents this graph, can be found under resources/input0_2_1.txt 

It's assumed that the number of nodes is  0 <= N <= 1000 and the number of edges is 0 <= M <= 1000.

