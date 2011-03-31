from collections import deque

tree = {'a': ['b', 'c'],
        'b': ['d', 'e'],
        'c': [],
        'd': ['f'],
        'e': [],
        'f': []}

def children(token, tree):
    "returns a list of every child"
    child_list = []
    to_crawl = deque([token])
    while to_crawl:
        current = to_crawl.popleft()
        child_list.append(current)
        node_children = tree[current]
        to_crawl.extend(node_children)
    return child_list

print children("f",tree)
