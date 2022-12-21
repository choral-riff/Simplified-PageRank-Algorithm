<h1> Simplified PageRank Algorithm in C++ </h1>

This is an implementation of the Simplified PageRank Algorithm in C++. It calculates the PageRank of a set of webpages after a specified number of power iterations.

<b>Data Structures</b>
The following data structures are used in this implementation:

<ol>
<li>
map&lt;string, map&lt;string, double&gt;&gt; adList: This is a container for the vertices and their rank. It maps a webpage to a map of its incoming links and their corresponding ranks.
</li>
<li>
set&lt;string&gt; websitesSet: This set stores the webpages and is mainly used to count the number of vertices.
</li>
<li>
vector&lt;string&gt; toVector: This vector stores the webpages with incoming links.
</li>
<li>
vector&lt;string&gt; fromVector: This vector stores the webpages with outgoing links.
</li>
<li>
map&lt;string, int&gt; outDegree: This map stores the outdegree of all the vertices (webpages).
</li>
<li>
map&lt;string, double&gt; rankMap: This map stores the rank of the webpages.
</li>
</ol>

Space Optimization
To save space, this implementation uses a map to store the adjacency list instead of a 2D array. This allows the algorithm to use only as much space as needed, rather than a fixed amount of space for the maximum number of vertices.

Additionally, the map&lt;string, map&lt;string, double&gt;&gt; adList data structure allows the algorithm to store only the necessary incoming links for each vertex, rather than a fixed number of links for all vertices. This helps to further optimize space usage.




