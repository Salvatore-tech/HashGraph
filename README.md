# HashGraph
The data structure implemented allows **to store a directed graph into an hash table.** Each node of the graph with the adjacency list is put in a different hash table's cell.
The algorithm reads the data from a input file and the user should be able to perform the following operations:
- Add an edge between two existing nodes
- Remove an edge 
- Find an edge
- Depth First Search

## Input file format 
The input file must be a .txt file and the data to insert into the graph are integers. The first row, as the following ones, contains two numbers separeted by a space which represents the number of nodes and the number of edges.
Then, the edges are listed accordingly by specifying the source and the target node.

### Example 
![alt text](https://github.com/Salvatore-tech/HashGraph/blob/master/resources/graph_exemple.png)  

3 5  (Three nodes with five edges)  
1 2  (Edge from 1 to 2)  
1 3  (Edge from 1 to 3)  
2 3  (Edge from 2 to 3)  
3 1  (Edge from 3 to 1)  
3 2  (Edge from 3 to 2)  

It's assumed that the number of nodes is  0 <= N <= 1000 and the number of edges is 0 <= M <= 1000.

