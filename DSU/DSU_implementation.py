# implementation of disjoint-set data structure (very efficient!)
 
# each "set" is a tree, and the "set representative" is the tree root
# hence, two nodes are in the same set if root(u) == root(v)
# initially, everything is in its own set. hence parent(node) = node
 
parent = range(nn)
size = [1]*nn
 
# to find the root, start from the node and keep going to parent[node]. stop when parent[node] = node.
# in addition, we set "parent[node] = root(node)" so that next time we look for root(node), we'll get there in 1 step!
def root(node):
    if not parent[node] == node:
        parent[node] = root(parent[node])
    return parent[node]
 
# to merge the sets, we can simply do parent[root(u)] = root(v)
# to ensure that tree heights are O(log n), we make the root of the smaller tree a child of the root of the larger tree
# (since a node's root can't change > log n times)
def merge(uu, vv):
    root_uu, root_vv = root(uu), root(vv)
    assert root_uu != root_vv, (root_uu, root_vv)
    if size[root_uu] < size[root_vv]:
        parent[root_uu] = root_vv
        size[root_vv] += size[root_uu]
    else:
        parent[root_vv] = root_uu
        size[root_uu] += size[root_vv]
