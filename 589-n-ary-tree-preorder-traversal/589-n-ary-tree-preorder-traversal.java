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
    List<Integer>ans;
    void bfs(Node root)
    {
        if(root==null) return;
        ans.add(root.val);
        for(Node node:root.children)
        {
            bfs(node);
        }
        return;
        
    }
    public List<Integer> preorder(Node root) {
        ans=new ArrayList<>();
        bfs(root);
        return ans;
    }
}