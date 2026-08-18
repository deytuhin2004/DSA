class Solution:
    def middleNode(self, head):
        steps = 0
        traversal = head
        while traversal.next:
            traversal = traversal.next
            steps += 1
        for i in range(-(-steps // 2)):
            head = head.next
        return head