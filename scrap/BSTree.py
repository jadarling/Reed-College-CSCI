class BSTNode:
    def __init__(self, k, v):
        self.key = k
        self.value = v
        self.left = None
        self.right = None

class BSTree:
    def __init__(self):
        self.root = None

    def is_empty(self):
        return (self.root is None)

    def get_value(self, k):
        n = self.root
        while n is not None:
            if k == n.key:
                return n.value
            elif k < n.key:
                n = n.left
            else:
                n = n.right
        return None

    def set_value(self, k, v):
        p = None
        n = self.root

        while n is not None:
            p = n
            if k == n.key:
                n.value = v
                return
            elif k < n.key:
                n = n.left
            else:
                n = n.right

        e = BSTNode(k, v)
        if p is None:
            self.root = e
        elif k < p.key:
            p.left = e
        else:
            p.right = e

    def min_key(self):
        if self.root is None:
            return None
        else:
            n = self.root
            while n.left is not None:
                n = n.left
            return n.key

    def size(self): 

        def subtree_size(n):
            if n is None:
                return 0
            else:
                return 1 + subtree_size(n.left) + subtree_size(n.right)

        return subtree_size(self.root)

    def as_list(self):

        def subtree_list(n):
            if n is None:
                return []
            else:
                return subtree_list(n.left) + [(n.key, n.value)] + subtree_list(n.right)

        return subtree_list(self.root)

    def as_string(self):
        kvs = self.as_list()
        if len(kvs) == 0:
            return "{}"
        else:
            s = "{"
            for kv in kvs[:-1]:
                s += repr(kv[0]) + ": " + repr(kv[1]) + ", " 
            kv = kvs[-1]
            s += repr(kv[0]) + ": " + repr(kv[1]) + "}"
            return s

    def __repr__(self):
        return self.as_string()

    __str__ = __repr__

    def __bool__(self):
        return not self.is_empty()

    def __contains__(self, k):
        return (self.get_value(k) is not None)

    def __len__(self):
        return self.size()

    def __getitem__(self, k):
        return self.get_value(k)

    def __setitem__(self, k, v):
        return self.set_value(k, v)

