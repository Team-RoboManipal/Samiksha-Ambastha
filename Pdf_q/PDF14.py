class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
class linked:
    def __init__(self):
        self.head = None
    def insert(self, data):
        if self.head is None:
            self.head = Node(data)
        else:
            current = self.head
            while current.next:
                current = current.next
            current.next = Node(data)
    def delete(self, data):
        if self.head is None:
            return

        if self.head.data == data:
            self.head = self.head.next
            return
        current = self.head
        while current.next:
            if current.next.data == data:
                current.next = current.next.next
                return
            current = current.next
    def traverse(self):
        current = self.head
        while current:
            print(current.data,end=" ")
            current = current.next
        print()
list1 = linked()
list1.insert(10)
list1.insert(20)
list1.insert(30)
list1.traverse()
list1.delete(20)
list1.traverse()
