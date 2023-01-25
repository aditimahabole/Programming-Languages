# -----------------------------------------------
# 
#        5
#      /   \
#    3      7
#  /   \      \
# 2     4------>8
# -----------------------------------------------
#   '5' : ['3','7'],
#   '3' : ['2', '4'],
#   '7' : ['8'],
#   '2' : [],
#   '4' : ['8'],
#   '8' : []
graph = {}
nodes = int(input("Enter number of nodes in graph : "))
for i in range(nodes):
    node = input("Enter Vertex : ")
    temp = []
    flag = 1
    while(flag):
        flag = input("Conection to add : ")
        if flag == '-1':
            break
        temp.append(flag)
    graph[node] = temp
print(graph)
visited = []
queue = []
def bfs(visited,graph,node):
    visited.append(node)
    queue.append(node)
    while queue:
        front = queue.pop(0)
        print(front , end = " ")
        for padosi in graph[front]:
            if padosi not in visited:
                visited.append(padosi)
                queue.append(padosi)
print("Showing BFS : \n")
bfs(visited,graph,'5')
#    5,3,7  
#    3,7,2,4 -->5
#    7,2,4,8 -->3
#    2,4,8   -->7
#    4,8     -->2
#     8      -->4
#     empty  -->8 
# -----------------------------------------------
