# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def mergeTwoLists(self, list1, list2):
        """
        :type list1: Optional[ListNode]
        :type list2: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        if(list1 == None and list2 == None):
            return
        elif(list1 and list2 == None):
            return list1
        elif(list2 and list1 == None):
            return list2
        newList = ListNode()
        head = newList
        while list1 and list2:
            if(list1.val > list2.val):
                newList.val = list2.val
                list2 = list2.next
                newList.next = ListNode(list1.val)
                newList = newList.next
            elif (list1.val == list2.val):
                newList.val = list1.val
                newList.next = ListNode(newList.val)
                newList = newList.next
                if(list1.next != None or list2.next != None):
                    newList.next = ListNode(list1.val)
                    newList = newList.next
                list1 = list1.next
                list2 = list2.next
            else:
                newList.val = list1.val
                newList.next = ListNode(list2.val)
                newList = newList.next
                list1 = list1.next
        
        while list2 != None:
            newList.val = list2.val
            if list2.next:
                newList.next = ListNode()
                newList = newList.next
            list2 = list2.next
        
        while list1 != None:
            newList.val = list1.val
            if list1.next:
                newList.next = ListNode()
                newList = newList.next
            list1 = list1.next
        
        return head
                
            
        