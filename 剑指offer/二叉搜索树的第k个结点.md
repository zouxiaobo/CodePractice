# NOTICE
1. 每道题都要分析时间复杂度
2. 思考时间复杂度优化的其他方案
3. 不要仅满足于写出一个思路，而不去学习其他思路

### 题目描述
给定一棵二叉搜索树，请找出其中的第k小的结点。例如， （5，3，7，2，4，6，8）    中，按结点数值大小顺序第三小结点的值为4。


****
** 以下代码均经测试通过,可直接运行 **   

### 思路

```
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

TreeNode* KthNode(TreeNode* pRoot, int k)
{
    
}
```

### 总结
