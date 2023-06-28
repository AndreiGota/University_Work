from copy import deepcopy
from exceptions import VertexError, NonexistentVertexError, EdgeError, NonexistentEdgeError
from collections import deque


class DirectedGraph:
    """
    CONSTRUCTOR
    """

    def __init__(self, vertices, edges):
        self.__vertices = []
        self.__edges = []
        self.__costs = {}
        self.__outbound = {}
        self.__inbound = {}

        for vertex in vertices:
            self.add_vertex(vertex)

        for edge in edges:
            self.add_edge(edge[0], edge[1], edge[2])

    """
    GETTERS
    """

    @property
    def edges(self):
        return self.__edges

    @property
    def costs(self):
        return self.__costs

    def get_number_of_vertices(self):
        return len(self.__vertices)

    def get_number_of_edges(self):
        return len(self.__edges)

    """
    ITERATORS
    """

    def parse_vertices(self):
        return [vertex for vertex in self.__vertices]

    def parse_edges(self):
        return [edge for edge in self.__edges]

    def parse_inbound(self, x):
        return [y for y in self.__inbound[x]]

    def parse_outbound(self, x):
        return [y for y in self.__outbound[x]]

    """
    FUNCTIONALITIES
    """

    def add_vertex(self, x):
        """
        Adds a vertex to the graph. If the vertex already exists in the graph, VertexError will be raised.
        Runtime: O(n), where n is the number of vertices (because of validation)
        :param x: integer (vertex)
        """
        if x in self.parse_vertices():
            raise VertexError
        self.__vertices.append(x)
        self.__outbound[x] = []
        self.__inbound[x] = []

    def add_vertex_valid(self, x):
        """
        Adds a vertex to the graph. If the vertex already exists in the graph, VertexError will be raised.
        Runtime: O(1)
        :param x: integer (vertex)
        """
        self.__vertices.append(x)
        self.__outbound[x] = []
        self.__inbound[x] = []

    def remove_vertex(self, x):
        """
        Removes a vertex from the graph. All edges containing x as the origin or target vertex, The outbound and inbound
        lists of x will be deleted (using self.remove_edge()). If x is not a vertex, an error will be raised.
        Runtime: O(max(n, m)), where n is the number of vertices and m the number of edges
        :param x: integer (vertex)
        """
        if x not in self.parse_vertices():
            raise NonexistentVertexError

        for edge in self.parse_edges():
            if edge[0] == x or edge[1] == x:
                self.remove_edge(edge[0], edge[1])
        del self.__outbound[x]
        del self.__inbound[x]
        self.__vertices.remove(x)

    def add_edge(self, x, y, c):
        """
        Adds an edge to the graph. If x or y are not vertices or the edge already exists in the graph, an error will be
        raised.
        Runtime: O(max(n, m)), where n is the number of vertices and m the number of edges (because of validation)
        :param x: integer (vertex)
        :param y: integer (vertex)
        :param c: integer
        """
        if x not in self.parse_vertices():
            raise NonexistentVertexError
        if y not in self.parse_vertices():
            raise NonexistentVertexError
        if (x, y) in self.parse_edges():
            raise EdgeError
        self.__edges.append((x, y))
        self.__outbound[x].append(y)
        self.__inbound[y].append(x)
        self.__costs[(x, y)] = c

    def add_edge_valid(self, x, y, c):
        """
        Adds an edge to the graph. If x or y are not vertices or the edge already exists in the graph, an error will be
        raised.
        Runtime: O(1)
        :param x: integer (vertex)
        :param y: integer (vertex)
        :param c: integer
        """
        self.__edges.append((x, y))
        self.__outbound[x].append(y)
        self.__inbound[y].append(x)
        self.__costs[(x, y)] = c

    def remove_edge(self, x, y):
        """
        Removes a given edge from the graph. Its cost, y as the outbound of x and x as the inbound of y will be deleted.
        If x or y are not vertices or (x, y) is not an edge, an error will be raised.
        Runtime: O(m), where m is the number of edges
        :param x:
        :param y:
        :return:
        """
        if x not in self.parse_vertices():
            raise NonexistentVertexError
        if y not in self.parse_vertices():
            raise NonexistentVertexError
        if (x, y) not in self.parse_edges():
            raise NonexistentEdgeError

        self.__edges.remove((x, y))
        del self.__costs[(x, y)]
        self.__outbound[x].remove(y)
        self.__inbound[y].remove(x)

    def update_edge(self, x, y, new_cost):
        """
        Updates the cost of an edge. If there is no x or y vertex or no (x, y) edge, an error is raised.
        Runtime: O(1)
        :param x: integer (vertex)
        :param y: integer (vertex)
        :param new_cost: integer
        """
        if x not in self.parse_vertices():
            raise NonexistentVertexError
        if y not in self.parse_vertices():
            raise NonexistentVertexError
        if (x, y) not in self.parse_edges():
            raise NonexistentEdgeError

        self.__costs[(x, y)] = new_cost

    def is_edge(self, x, y):
        """
        Checks if there is an edge in the graph that has the origin x and the target y (returns True if it finds the
        given edge, False otherwise). If x or y are not vertices, an error is raised.
        Runtime: O(deg(x) + deg(y)), where deg(i) = the degree of vertex i
        :param x: integer (vertex)
        :param y: integer (vertex)
        :return: boolean
        """
        if x not in self.parse_vertices():
            raise NonexistentVertexError
        if y not in self.parse_vertices():
            raise NonexistentVertexError

        if y in self.__outbound[x] and x in self.__inbound[y]:
            return True
        return False

    def in_degree(self, x):
        """
        Returns the in degree of a vertex x. If x is not a vertex, an error is raised.
        Runtime: O(1)
        :param x: integer (vertex)
        :return: integer
        """
        if x not in self.parse_vertices():
            raise NonexistentVertexError

        return len(self.__inbound[x])

    def out_degree(self, x):
        """
        Returns the out degree of a vertex x. If x is not a vertex, an error is raised.
        Runtime: O(1)
        :param x: integer (vertex)
        :return: integer
        """
        if x not in self.parse_vertices():
            raise NonexistentVertexError

        return len(self.__outbound[x])

    def copy(self):
        """
        Returns a deepcopy of the graph.
        Runtime: O(1)
        :return: DirectedGraph object
        """
        return deepcopy(self)

    def bfs(self, start_vertex, end_vertex):
        # check if start and end vertices exist in the graph
        if start_vertex not in self.parse_vertices():
            raise NonexistentVertexError

        if end_vertex not in self.parse_vertices():
            raise NonexistentVertexError

        # initialize a set to keep track of visited vertices
        visited = set()
        # initialize a queue to store vertices to visit
        queue = deque([(start_vertex, [start_vertex])])

        # perform BFS until the end vertex is found or the queue is empty
        while queue:
            # get the next vertex from the queue
            current_vertex, path_so_far = queue.popleft()

            # if the current vertex is the end vertex, return the path to it and the length
            if current_vertex == end_vertex:
                return path_so_far, len(path_so_far) - 1

            # if the current vertex has already been visited, skip it
            if current_vertex in visited:
                continue

            # add current vertex to the visited set
            visited.add(current_vertex)

            # add all unvisited neighbors of the current vertex to the queue
            for neighbor in self.__outbound[current_vertex]:
                if neighbor not in visited:
                    new_path = path_so_far + [neighbor]
                    queue.append((neighbor, new_path))

        # if the end vertex was not found, return None
        return None

    def find_lowest_cost_walk(self, start, end):
        """
        Finds the lowest cost walk between the start and end vertices using the Bellman-Ford algorithm.
        If there are negative cost cycles accessible from the start vertex, it prints an error message.
        :param start: integer (vertex)
        :param end: integer (vertex)
        """

        # Check for validation
        if start not in self.parse_vertices():
            raise NonexistentVertexError
        if end not in self.parse_vertices():
            raise NonexistentVertexError

        # Step 1: Initialization
        distances = {vertex: float('inf') for vertex in self.parse_vertices()}
        distances[start] = 0

        # Step 2: Relax edges repeatedly
        for _ in range(self.get_number_of_vertices() - 1):
            for edge in self.parse_edges():
                source, target = edge[0], edge[1]
                cost = self.costs[edge]
                if distances[source] != float('inf') and distances[source] + cost < distances[target]:
                    distances[target] = distances[source] + cost

        # Step 3: Check for negative cost cycles
        for edge in self.parse_edges():
            source, target = edge[0], edge[1]
            cost = self.costs[edge]
            if distances[source] != float('inf') and distances[source] + cost < distances[target]:
                print("Negative cost cycle detected. No lowest cost walk exists.")
                return

        # Step 4: Check if a path exists from start to end
        if distances[end] == float('inf'):
            print("No path exists from the start vertex to the end vertex.")
        else:
            print(f"Lowest cost walk from {start} to {end}:")
            path = self._reconstruct_path(distances, start, end)
            print(" -> ".join(str(vertex) for vertex in path))
            print("min cost", distances[end])

    def _reconstruct_path(self, distances, start, end):
        """
        Reconstructs the lowest cost path from the start vertex to the end vertex based on the computed distances.
        :param distances: dictionary of vertex distances
        :param start: integer (start vertex)
        :param end: integer (end vertex)
        :return: list of vertices representing the lowest cost path
        """
        path = [end]
        while end != start:
            for edge in self.parse_edges():
                source, target = edge[0], edge[1]
                cost = self.costs[edge]
                if distances[source] != float('inf') and distances[source] + cost == distances[end]:
                    path.insert(0, source)
                    end = source
                    break
        return path

    def is_dag_and_topological_sort(self):
        """
        Verifies if the graph is a DAG and performs a topological sorting of the activities.
        :return: A list containing the topologically sorted vertices if the graph is a DAG,
                 otherwise returns an empty list.
        """
        sorted_vertices = []
        predecessor_count = {}

        for vertex in self.parse_vertices():
            predecessor_count[vertex] = self.in_degree(vertex)

        queue = [vertex for vertex in self.parse_vertices() if predecessor_count[vertex] == 0]

        while queue:
            current_vertex = queue.pop(0)
            sorted_vertices.append(current_vertex)

            for neighbor in self.parse_outbound(current_vertex):
                predecessor_count[neighbor] -= 1
                if predecessor_count[neighbor] == 0:
                    queue.append(neighbor)

        if len(sorted_vertices) != self.get_number_of_vertices():
            # The graph has a cycle, not a DAG
            return []

        return sorted_vertices

    def highest_cost_path(self, start_vertex, end_vertex):
        """
        Finds the highest cost path between two given vertices in a DAG.
        :param start_vertex: The starting vertex.
        :param end_vertex: The ending vertex.
        :return: The highest cost path as a list of vertices, or an empty list if no path exists.
        """
        if start_vertex not in self.parse_vertices() or end_vertex not in self.parse_vertices():
            raise NonexistentVertexError

        if not self.is_dag_and_topological_sort():
            # The graph is not a DAG
            return [], 0

        max_costs = {}
        predecessors = {}
        topological_order = self.is_dag_and_topological_sort()

        for vertex in self.parse_vertices():
            max_costs[vertex] = float("-inf")
            predecessors[vertex] = None

        max_costs[start_vertex] = 0

        for vertex in topological_order:
            if vertex == end_vertex:
                # Reached the end vertex
                break

            if max_costs[vertex] != float("-inf"):
                for neighbor in self.parse_outbound(vertex):
                    cost = self.costs[(vertex, neighbor)]
                    if max_costs[vertex] + cost > max_costs[neighbor]:
                        max_costs[neighbor] = max_costs[vertex] + cost
                        predecessors[neighbor] = vertex

        if max_costs[end_vertex] == float("-inf"):
            # There is no path between the start and end vertices
            return [], max_costs[end_vertex]

        # Reconstruct the highest cost path
        path = [end_vertex]
        current_vertex = end_vertex

        while current_vertex != start_vertex:
            current_vertex = predecessors[current_vertex]
            path.insert(0, current_vertex)

        return path, max_costs[end_vertex]



