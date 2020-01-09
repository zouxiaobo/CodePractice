# NOTICE
1. 每道题都要分析时间复杂度
2. 思考时间复杂度优化的其他方案
3. 不要仅满足于写出一个思路，而不去学习其他思路

### 题目描述
输入一个链表，输出该链表中倒数第k个结点。

****
** 以下代码均经测试通过,可直接运行 **   

### 思路
思路一:遍历链表，将结点存在vector即可
时间复杂度:O(n)
空间复杂度:O(n)

思路二:遍历两次
时间复杂度:O(n)
空间复杂度:O(1)

思路三:双指针，让一个指针先走k，然后另外一个指针开始走，当第一个指针到达结尾时，第二个指针就是倒数第k个结点
时间复杂度:O(n)
空间复杂度:O(1)
这个思路没想到

```
struct ListNode 
{
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(NULL){}
};

//思路一代码实现
ListNode* FindKthToTail(ListNode* pListHead,unsigned int k) 
{
    if(pListHead == NULL)
    {
        return pListHead;
    }

    vector<ListNode*> vecListNode;
    ListNode* pListTemp = pListHead;
    while(pListTemp != NULL)
    {
        vecListNode.push_back(pListTemp);
        pListTemp = pListTemp->next;
    }

    int iListSize = vecListNode.size();
    if(k > iListSize)
    {
        return NULL;
    }
    else if(k == 0)
    {
        return NULL;
    }
    else
    {
        return vecListNode[iListSize-k];
    }
}

//思路三代码实现
ListNode* FindKthToTail(ListNode* pListHead,unsigned int k) 
{
    if(pListHead == NULL || k == 0)
    {
        return NULL;
    }

    ListNode* pFastNode = pListHead;
    ListNode* pSlowNode = pListHead;
    int iCount = k-1;
    while(k != 0 && pFastNode != NULL)
    {
        pFastNode = pFastNode->next;
        k--;
    }

    if(k == 0 && pFastNode == NULL)
    {
        return pSlowNode;
    }
    else if(k > 0)
    {
        return NULL;
    }
    

    while(pFastNode != NULL)
    {
        pFastNode = pFastNode->next;
        pSlowNode = pSlowNode->next;
    }

    return pSlowNode;
}

```

### 总结
链表题注意双指针用法，一般都是快慢指针，特别注意判断next为空