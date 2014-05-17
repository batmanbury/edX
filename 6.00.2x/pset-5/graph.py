# MIT 6.00.2x
# Problem Set 5
# Graph optimization
#
# A set of data structures to represent graphs
#

class Node(object):
    def __init__(self, name):
        self.name = str(name)
    def getName(self):
        return self.name
    def __str__(self):
        return self.name
    def __repr__(self):
        return self.name
    def __eq__(self, other):
        return self.name == other.name
    def __ne__(self, other):
        return not self.__eq__(other)
    def __hash__(self):
        # Override the default hash method
        return self.name.__hash__()

class Edge(object):
    def __init__(self, src, dest):
        self.src = src
        self.dest = dest
    def getSource(self):
        return self.src
    def getDestination(self):
        return self.dest
    def __str__(self):
        return '{0}->{1}'.format(self.src, self.dest)

class WeightedEdge(Edge):
    def __init__(self, src, dest, distance, outdoor):
        Edge.__init__(self, src, dest)
        self.distance = distance
        self.outdoor = outdoor
    def getTotalDistance(self):
        return self.distance
    def getOutdoorDistance(self):
        return self.outdoor
    def __str__(self):
        return str(self.src) + '->' + str(self.dest) + ' (' + str(self.distance) + ', ' + str(self.outdoor) + ')'

class Digraph(object):
    """
    A directed graph
    """
    def __init__(self):
        # Entries into a set must be hashable
        # Lookups are O(1) as opposed to the O(n) of a list
        # See http://docs.python.org/2/library/stdtypes.html#set-types-set-frozenset
        self.nodes = set([])
        self.edges = {}
    def addNode(self, node):
        if node in self.nodes:
            # Warn about duplicate nodes
            raise ValueError('Duplicate node')
        else:
            self.nodes.add(node)
            self.edges[node] = {}
    def addEdge(self, edge):
        src = edge.getSource()
        dest = edge.getDestination()
        if not(src in self.nodes and dest in self.nodes):
            raise ValueError('Node not in graph')
        self.edges[src].append(dest)
    def childrenOf(self, node):
        """Returns children of node"""
        return self.edges[node]
    def hasNode(self, node):
        return node in self.nodes
    def __str__(self):
        res = ''
        for k in self.edges:
            for d in self.edges[str(k)]:
                res = '{0}{1}->{2}\n'.format(res, k, d)
        return res[:-1]

class WeightedDigraph(Digraph):
    """A weighted, directed graph"""
    def __init__(self):
        Digraph.__init__(self)
    def addEdge(self, edge):
        src = edge.getSource()
        dest = edge.getDestination()
        distance = edge.getTotalDistance()
        outdoor = edge.getOutdoorDistance()
        if not(src in self.nodes and dest in self.nodes):
            raise ValueError('Node not in graph')
        self.edges[src][dest] = (distance, outdoor)
    def childrenOf(self, node):
        return [n for n in self.edges[node]]
    def __str__(self):
        result = ''
        for e in self.edges:
            for s,d in self.edges[e].items():
                result += '{0}->{1} ({2}, {3})\n'.format(e, s, float(d[0]), float(d[1]))
        return result[:-1]
