
class Solution {
    struct Node
    {
        char c;
        string word;
        bool ends;
        Node *child[26];
        
    };
    Node *root=getNode('/');
    Node *getNode(char c)
    {
        Node *newNode=new Node;
        newNode->c=c;
        newNode->word="";
        newNode->ends=false;
        for(int i=0;i<26;i++)
        {
            newNode->child[i]=NULL;
        }
        return newNode;   
    }
    void insert(string word)
    {
        Node *currentNode=root;
        int index=0;
        for(auto char1:word)
        {
            index=char1-'a';
            if(currentNode->child[index]==NULL)   currentNode->child[index]=getNode(char1);
            currentNode=currentNode->child[index];
                     
        }
        currentNode->word=word;
        currentNode->ends+=1;
    }
    void dfs(vector<vector<char>>& board,vector<string>&ans,Node *cur,int i,int j,int r,int c)
    {
        int index=board[i][j]-'a';
        if(board[i][j]=='*' ) return;
        else if(cur->child[index]==NULL) return;
        cur=cur->child[index];
        if(cur->ends>0)
        {
            ans.push_back(cur->word);
            cur->ends-=1;
        }
        char currentChar=board[i][j];
        board[i][j]='*';
        if(i>0)
        {
            dfs(board,ans,cur,i-1,j,r,c);
        }
        if(j>0)
        {
            dfs(board,ans,cur,i,j-1,r,c);
        }
        if(i<r-1)
        {
            dfs(board,ans,cur,i+1,j,r,c);
        }
        if(j<c-1)
        {
            dfs(board,ans,cur,i,j+1,r,c);
        }
        board[i][j]=currentChar;
        
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string>ans;
        int r=board.size();
        int c=board[0].size();
        for(auto word:words)
            insert(word);
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                dfs(board,ans,root,i,j,r,c);
            }
        }
        return ans;
        
    }
};