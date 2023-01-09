# Cpp-Graph_duality
A program to check whether an undirected graph is bipartite.
The graph file has the following form:
- Each edge is given on a separate line; two vertices are given,
which are connected by an edge.
- There may be empty lines in the file.
- There may be additional (redundant) whitespace characters in the line.

The program writes to the output file the given graph and a message, whether it is a bipartite graph or not. If it is a bipartite graph, the program prints vertices from both groups. The program is run from the command line with using the following switches (the order of switches is arbitrary):
- \-i input file with the edges of the graph
- \-o output file with results


Pointers are used to create the list of the graph vertexes, list of the graph edges and the queue required for the BFS algorithm, which is used to check the duality.

Comments compatible with the doxygen tool are added to generate documentation. Documentation in Polish in the doc folder.