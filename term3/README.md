## Program
- 1. Graph traversals.
  - 1.1. Oriented graph, pseudograph.  Undirected graph, pseudograph.  Connectivity in neor.  graph, connectivity components. Weak and strong connectivity in the or. graph.  Components of weak, strong connectivity. 
  - 1.2. Deep crawl.  Vertex colors.  Entry and exit times.  The white paths lemma (with proof). 
  - 1.3. Checking the connectivity of an undirected graph.  Search for a cycle in an undirected and oriented graph.  Topological sorting.
  - 1.4. Finding components of strong connectivity.  Kosarayu algorithm with proof of correctness (concept).  Tarjan's algorithm without proof of correctness. 
  - 1.5. Components of edge disjointedness.  Bridges.  Search for bridges. 
  - 1.6. Components of vertex disjointedness.  Points of articulation.  Search for points of articulation. 
  - 1.7. Wave algorithm.  Breadth traversal (using a queue in a wave algorithm). 
  - 1.8. Criterion for the existence of an Eulerian path and cycle in an oriented and undirected graph.  Search for an Eulerian path and cycle.

- 2. Graph planarity 
  - 2.1. Euler's formula. The Portnyagin-Kuratovsky theorem. Wagner's theorem.
  - 2.2. Gamma algorithm. Contact vertex.
  - 2.3. The theorem on the correctness of the Gamma algorithm. The asymptotics of the algorithm. 

- 3. Shortest paths in a weighted graph.
  - 3.1. Dijkstra's algorithm.  Proof of correctness (with proof). Evaluation of the working time.  Tree of shortest paths. 
  - 3.2. Potentials.  The condition of applicability of Dijkstra's algorithm for modified edge lengths.  Potential π(v) = p(v, t).) = p(v) = p(v, t)., t). 
  - 3.3. Algorithm A*.  Monotonicity condition for heuristics.  Examples of heuristics.
  - 3.4. The Ford-Bellman algorithm.  Storage in the matrix: Dv) = p(v, t).k is equal to the length of the shortest path to the vertex v) = p(v, t). for exactly k edges (no more than k edges). Proof of correctness (complete).  Evaluation of the working time. 
  - 3.5. Restoring the path.  Detecting a negative weight cycle.  Search for the cycle itself. 
  - 3.6. Finding shortest paths taking into account negative weight cycles. 
  - 3.7. Floyd's algorithm.  Proof (concept).  Restoring the path. 
  - 3.8. Finding a negative weight cycle. 
  - 3.9. Johnson's algorithm.  Adding a dummy root and dummy edges to run the Ford-Bellman algorithm.

- 4. Spanning trees.
  - 4.1. Spanning tree.  Construction using a crawl in depth and in width. 
  - 4.2. Definition of the minimum spanning tree. 
  - 4.3. The section theorem.  Proof. 
  - 4.4. Prim's algorithm.  Analogy with Dijkstra's algorithm.  Estimation of running time for various queue implementations with priority: binary heap, Fibonacci heap (the latter without proof). 
  - 4.5. Prim's algorithm.  Proof of correctness using the section theorem. 
  - 4.6. Kruskal's algorithm.  Proof of correctness.  Evaluation of the working time. 
  - 4.7. The system of disjoint sets.  Heuristics of potentials without proof..  Heuristics of path compression without proof.  Almost constant running time (without proof). 
  - 4.8. Boruvka's algorithm.  Proof (complete).  Evaluation of the working time. 
  - 4.9. Approximation of the solution of the traveling salesman problem using a minimal spanning tree.

- 5. Streams in networks.
  - 5.1. Network definition.  Flow definition.  Physical meaning.  Analogy with Kirchhoff's laws.  Definition of the cut.  Concepts of flow through a cut. 
  - 5.2. Definition of the cut.  Concepts of flow through a cut.  Proof of the fact that the flow through any cut is the same. 
  - 5.3. The concept of a residual network.  The concept of a complementary path.  The need for the absence of a complementary path to maximize the flow. 
  - 5.4. The Ford-Fulkerson theorem. 
  - 5.5. The Ford-Fulkerson algorithm.  Search for the minimum cut.  An example of an integer network in which the algorithm runs for a long time. 
  - 5.6. The Edmonds-Karp algorithm.  Proof that the shortest distance in the residual network does not decrease. 
  - 5.7. General estimation of the operating time of the Edmonds-Karp algorithm.  (not strictly)
  - 5.8. Layered network.  The Dinitz algorithm.  Estimation of working time without proof.

- 6.	RMQ.  Sparse-table, a tree of segments.  LCA. Cartesian tree by implicit key. 
  - 6.1. RSQ and RMQ. Sparse-table.
  - 6.2. Tree of segments.  Processing requests from leaves.  Processing requests from the root. 
  - 6.3. The tree of segments.  Changing the value in the array, updating the tree of segments. Multiple operations. 
  - 6.4.	LCA. Binary lifting method. 
  - 6.5. Cartesian tree by implicit key.  Fast Array Interface:  Accessing an element at position i, Inserting an element at position i, Removing an element from position i, Concatenating two arrays, splitting an array into two.
