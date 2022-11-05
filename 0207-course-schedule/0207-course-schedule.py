class Node:
    def __init__(self):
        self.indegree = 0
        self.outNodes = []

class Solution(object):
    def canFinish(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        """
        from collections import defaultdict, deque
        graph = defaultdict(Node)
        
        countEdges = 0
        for prereq in prerequisites:
            course, dependentCourse = prereq[0], prereq[1]
            graph[dependentCourse].outNodes.append(course)
            graph[course].indegree += 1
            countEdges +=1
            
        notDependentCourses = deque()
        for index, item in graph.items():
            if item.indegree == 0:
                notDependentCourses.append(index)
        
        removedEdges = 0
        while notDependentCourses:
            notDepCourse = notDependentCourses.pop()
            for outNode in graph[notDepCourse].outNodes:
                graph[outNode].indegree -= 1
                removedEdges += 1
                if graph[outNode].indegree == 0:
                    notDependentCourses.append(outNode)
        
        return (removedEdges == countEdges)
                
        