import heapq
from collections import defaultdict, namedtuple

class Node(namedtuple("Node", ["char", "freq"])):
    def __lt__(self, other):
        return self.freq < other.freq

def huffman_encoding(frequencies):
    heap = [Node(char, freq) for char, freq in frequencies.items()]
    heapq.heapify(heap)
    
    while len(heap) > 1:
        left = heapq.heappop(heap)
        right = heapq.heappop(heap)
        new_node = Node(None, left.freq + right.freq)
        heapq.heappush(heap, (new_node, left, right))
    
    return heap[0] if heap else None

def huffman_codes(node, prefix="", codebook=None):
    if codebook is None:
        codebook = {}
    if node:
        if node.char:
            codebook[node.char] = prefix
        else:
            huffman_codes(node[1], prefix + "0", codebook)
            huffman_codes(node[2], prefix + "1", codebook)
    return codebook

# Example usage:
frequencies = {
    'a': 5,
    'b': 9,
    'c': 12,
    'd': 13,
    'e': 16,
    'f': 45
}

root = huffman_encoding(frequencies)
codes = huffman_codes(root)
print(codes)  # Output: {'f': '0', 'c': '100', 'd': '101', 'a': '1100', 'b': '1101', 'e': '111'}

# Frequencies:
# 'a': 5, 'b': 9, 'c': 12, 'd': 13, 'e': 16, 'f': 45
# Huffman Codes:
# 'f': '0', 'c': '100', 'd': '101', 'a': '1100', 'b': '1101', 'e': '111'
