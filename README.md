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

## Delete node operation
For the sake of completeness, the delete operation has been developed and will be described shortly.
This operation led to a rewiring process of the application and the introduction of smart pointers.
This decision has been taken during the final phases of the project, and in order to integrate it in the project, the development has shifted into a separate git branch called feature.
The process had three different steps:  
1. Strangulation: the existing features have been reduced or temporarily dropped to assist the rewiring. This step terminated when the smart pointers integrated into the project and a subset of operation worked as expected.  
2. Restoration: the most demanding operations have been rewritten, such as the edge inserting and deleting.  
3. Optimization: on the memory management and  further validations.  

The migration took several days, but has been successfully completed and, after it, the user is able to delete a node and thereby all the existing edges towards it will fall. This seems obvious, however the smart pointers helped to release the memory and let us to avoid the growth of dangling pointers (pointers to memory area freed).  


## Build and execution
**Preconditions:** static libraries https://github.com/Salvatore-tech/CppUtils put in the same parent directory of the project.  
The executable file is placed under PROJECT_ROOT/build.  
Perhaps, we can build project, by running cmake inside the PROJECT_ROOT to generate the Makefile and finally run make. 
Then we can run the executable HashGraph. Additionally, we can pass a parameter as command line argument to specify the hashing strategy we want to use between linear probing and double hashing (by default it uses the first one).  
Ex.  
    1. ./HashGraph  
    2. ./HashGraph linear    
    3. ./HashGraph double  

First of all, it will look for the input file under PROJECT_ROOT/resources called input0_2_1.txt  and populate the data structure accordingly.  
Then the user can choose one of the following operations from the menu:  
1) Display graph 
2) Add an edge between two nodes 
3) Remove an edge between two nodes 
4) Find an edge between two nodes 
5) Depth first search 
6) Delete a node 
0) Exit 

