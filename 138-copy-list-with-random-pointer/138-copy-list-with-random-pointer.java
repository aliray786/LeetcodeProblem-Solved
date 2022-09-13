/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        if(head==null) return null;
        Node cur=head;
        while(cur!=null)
        {
            Node next=cur.next;
            cur.next=new Node(cur.val);
            cur.next.next=cur.next!=null?next:cur.next;
            cur=next;
        }
        cur=head;
        while(cur!=null)
        {
            if(cur.next!=null)
            {
                 cur.next.random=cur.random!=null?cur.random.next:cur.random;
            }
            cur=cur.next!=null?cur.next.next:cur.next;
        }
        Node copyHead=head.next;
        Node copy=copyHead;
        while(copy!=null && head!=null)
        {
            head.next=head.next!=null?head.next.next:head.next;
            copy.next=copy.next!=null?copy.next.next:copy.next;
            head=head.next;
            copy=copy.next;
        }
        return copyHead;
    }
}