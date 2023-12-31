import re
from exceptions import InputError, InvalidEdges, VertexError, NonexistentVertexError, EdgeError, NonexistentEdgeError
from directed_graph import DirectedGraph
from external_functions import read_graph, generate_random_graph, print_graph


class UI:
    def __init__(self):
        vertices = []
        edges = []
        self.__g = DirectedGraph(vertices, edges)

    @staticmethod
    def print_main_menu():
        print("""Choose one of the following operations:
1. Read a graph from a file (and overwrite the current graph).
2. Generate a random graph with a given number of vertices and edges (and overwrite the current graph).
3. Add a vertex to the current graph.
4. Remove a vertex from the current graph.
5. Add an edge to the current graph.
6. Remove an edge from the current graph.
7. Update the cost of an edge of the current graph.
8. Check if an edge exists in the current graph.
9. Print the number of vertices of the current graph.
10. Print the vertices of the current graph.
11. Print the in-degree of a vertex.
12. Print the out-degree of a vertex.
13. Print the inbound neighbors of a given vertex.
14. Print the outbound neighbors of a given vertex.
15. Display the current graph on the console.
16. Write the representation of the current graph as a list of edges in graph_modif.txt.
17. Copy the graph.
18. Shortest path between two given vertices using BFS.
19. Bellman Ford Algorithm for two given vertices.
20. Check if the given graph is a DAG and do topo sort.
21. Find highest cost path between two given vertices in a DAG.
22. Exit.
""")

    @staticmethod
    def get_option():
        while True:
            try:
                cmd = input(">>> ")
                if not cmd.isdigit():
                    raise InputError
                num = int(cmd)
                if num < 1 or num > 22:
                    raise InputError
                break
            except InputError:
                print("Invalid input.")
        return int(cmd)

    def read(self):
        print(
            "Please type the name of the file (input.txt, graph1k.txt, graph10k.txt, graph100k.txt, graph1m.txt, graph_modif.txt:")
        while True:
            try:
                file_path = input(">>> ")

                if not re.match(
                        "(^graph_modif.txt$)|(^input.txt$)|(^graph1k.txt$)|(^graph10k.txt$)|(^graph100k.txt)|(^graph1m.txt$)",
                        file_path):
                    raise InputError
                break
            except InputError:
                print("Invalid input.")
        self.__g = read_graph(file_path)
        print("Graph read successfully.")

    # @staticmethod
    def generate(self):
        l = []
        while True:
            try:
                print("Please type the number of vertices:")
                n = input(">>> ")

                if not n.isnumeric():
                    raise InputError

                n = int(n)

                if n < 0 or n > 1000000:
                    raise InputError

                l.append(n)
                break
            except InputError:
                print("Invalid number.")

        while True:
            try:
                print("Please type the number of edges:")
                m = input(">>> ")

                if not m.isnumeric():
                    raise InputError

                m = int(m)

                if m < 0 or m > 1000000000000:
                    raise InputError

                l.append(m)
                break
            except InputError:
                print("Invalid number.")

        while True:
            try:
                print(
                    "Please type the name of the file in which you would like the graph to be saved (random_graph1.txt or random_graph2.txt):")
                file_path = input(">>> ")

                if not re.match("(^random_graph1.txt$)|(^random_graph2.txt$)", file_path):
                    raise InputError

                l.append(file_path)
                break
            except InputError:
                print("Invalid input.")

        try:
            self.__g = generate_random_graph(l[0], l[1], l[2])
            print("Generation done.")
        except InvalidEdges:
            print("The number of edges must be smaller or equal to the number of vertices squared (m <= n^2).")

    def add_vertex(self):
        print("Please provide the new vertex:")
        vertex = input(">>> ")

        try:
            self.__g.add_vertex(vertex)
            print("Vertex added successfully.")
        except VertexError:
            print("The vertex you provided already exists in the graph.")

    def remove_vertex(self):
        print("Please provide the vertex:")
        vertex = input(">>> ")

        try:
            self.__g.remove_vertex(vertex)
            print("Vertex deleted successfully.")
        except NonexistentVertexError:
            print("The vertex you provided does not exist in the graph.")

    def add_edge(self):
        print("Please provide the source:")
        x = input(">>> ")

        print("Please provide the target:")
        y = input(">>> ")

        print("Please provide the cost:")
        while True:
            try:
                c = input(">>> ")

                if not c.isnumeric():
                    raise InputError

                c = int(c)
                break
            except InputError:
                print("Invalid cost. Please provide an integer.")

        try:
            self.__g.add_edge(x, y, c)
            print("Edge added successfully.")
        except NonexistentVertexError:
            print("At least one of the vertices you provided are not in the graph.")
        except EdgeError:
            print("The edge already exists in the graph.")

    def remove_edge(self):
        print("Please provide the source:")
        x = input(">>> ")

        print("Please provide the target:")
        y = input(">>> ")

        try:
            self.__g.remove_edge(x, y)
            print("Edge removed successfully.")
        except NonexistentVertexError:
            print("The vertices you provided do not exist.")
        except NonexistentEdgeError:
            print("The edge you provided does not exist.")

    def update_edge(self):
        print("Please provide the source:")
        x = input(">>> ")

        print("Please provide the target:")
        y = input(">>> ")

        print("Please provide the new cost:")
        while True:
            try:
                c = input(">>> ")

                if not c.isnumeric() and c[0] != "-":
                    raise InputError

                c = int(c)
                break
            except InputError:
                print("Invalid cost. Please provide an integer.")

        try:
            self.__g.update_edge(x, y, c)
            print("Edge updated successfully.")
        except NonexistentVertexError:
            print("At least one of the vertices you provided are not in the graph.")
        except NonexistentEdgeError:
            print("The edge does not exist in the graph.")

    def is_edge(self):
        print("Please provide the source:")
        x = input(">>> ")

        print("Please provide the target:")
        y = input(">>> ")

        try:
            result = self.__g.is_edge(x, y)
            if result:
                print(f"There is an edge between {x} and {y}.")
            else:
                print(f"There is no edge between {x} and {y}.")
        except NonexistentVertexError:
            print("At least one of the vertices you provided are not in the graph.")

    def number_vertices(self):
        print(self.__g.get_number_of_vertices())

    def vertices(self):
        print(self.__g.parse_vertices())

    def in_degree(self):
        print("Please provide the vertex:")
        vertex = input(">>> ")

        try:
            print(self.__g.in_degree(vertex))
        except NonexistentVertexError:
            print("The vertex you provided is not in the graph.")

    def out_degree(self):
        print("Please provide the vertex:")
        vertex = input(">>> ")

        try:
            print(self.__g.out_degree(vertex))
        except NonexistentVertexError:
            print("The vertex you provided is not in the graph.")

    def inbound(self):
        print("Please provide the vertex:")
        vertex = input(">>> ")

        try:
            if vertex not in self.__g.parse_vertices():
                raise NonexistentVertexError
            print(self.__g.parse_inbound(vertex))
        except NonexistentVertexError:
            print("The vertex you provided is not in the graph.")

    def outbound(self):
        print("Please provide the vertex:")
        vertex = input(">>> ")

        try:
            if vertex not in self.__g.parse_vertices():
                raise NonexistentVertexError
            print(self.__g.parse_outbound(vertex))
        except NonexistentVertexError:
            print("The vertex you provided is not in the graph.")

    def print_file(self):
        print_graph(self.__g, True)

    def print_console(self):
        print_graph(self.__g, False)

    def copy(self):
        G = self.__g.copy()
        print("Graph copied successfully.")

    def shortest_path(self):
        try:
            source = input("Source: ")
            destination = input("Destination: ")
            try:
                path, length = self.__g.bfs(source, destination)
                print("Length of the path: ", length)
                print("Path ", path)
            except:
                print("There is not a path between these vertices")
        except NonexistentVertexError:
            print("The vertex you provided is not in the graph.")

    def bellman_ford_algo(self):
        try:
            source = input("Source: ")
            destination = input("Destination: ")
            self.__g.find_lowest_cost_walk(source, destination)
        except NonexistentVertexError:
            print("The vertex you provided is not in the graph.")

    def check_dag_and_do_topo_sort(self):
        sorted_vertices = self.__g.is_dag_and_topological_sort()
        if sorted_vertices:
            print("Topologically sorted vertices:", sorted_vertices)
        else:
            print("The graph is not a DAG.")

    def find_highest_cost_path_in_dag(self):
        try:
            source = input("Source: ")
            destination = input("Destination: ")
            path, max_cost_path = self.__g.highest_cost_path(source, destination)
            if path:
                print("Highest cost path:", path)
                print("cost: ", max_cost_path)
            else:
                print("There is no path between the start and end vertices.")
        except NonexistentVertexError:
            print("The vertex you provided is not in the graph.")

    def start(self):
        while True:
            self.print_main_menu()
            option = self.get_option()
            if option == 1:
                self.read()
            elif option == 2:
                self.generate()
            elif option == 3:
                self.add_vertex()
            elif option == 4:
                self.remove_vertex()
            elif option == 5:
                self.add_edge()
            elif option == 6:
                self.remove_edge()
            elif option == 7:
                self.update_edge()
            elif option == 8:
                self.is_edge()
            elif option == 9:
                self.number_vertices()
            elif option == 10:
                self.vertices()
            elif option == 11:
                self.in_degree()
            elif option == 12:
                self.out_degree()
            elif option == 13:
                self.inbound()
            elif option == 14:
                self.outbound()
            elif option == 15:
                self.print_console()
            elif option == 16:
                self.print_file()
            elif option == 17:
                self.copy()
            elif option == 18:
                self.shortest_path()
            elif option == 19:
                self.bellman_ford_algo()
            elif option == 20:
                self.check_dag_and_do_topo_sort()
            elif option == 21:
                self.find_highest_cost_path_in_dag()
            else:
                break
