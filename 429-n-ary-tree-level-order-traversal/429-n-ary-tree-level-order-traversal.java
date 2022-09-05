/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    public List<List<Integer>> levelOrder(Node root) {
        List<List<Integer>> ans=new ArrayList<>();
        if(root==null) return ans;
        Queue<Node>q=new LinkedList<>();
        q.add(root);
        while(!q.isEmpty())
        {
            int s=q.size();
            List<Integer>l1=new ArrayList<>();
            while(s>0)
            {
                s--;
                Node front=q.poll();
                l1.add(front.val);
                for(int i=0;i<front.children.size();i++)
                {
                    if(front.children.get(i)!=null)
                    {
                        q.add(front.children.get(i));
                    }
                }
            }
            ans.add(l1);
        }
        return ans;
    }
}