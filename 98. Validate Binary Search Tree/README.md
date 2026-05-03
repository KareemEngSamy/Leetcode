# 98. Validate Binary Search Tree

## Problem Statement

Given the root of a binary tree, determine if it is a valid Binary Search Tree (BST).

A valid BST must satisfy:

* Every node in the left subtree is strictly smaller than the current node.
* Every node in the right subtree is strictly greater than the current node.
* Both left and right subtrees must also be valid BSTs.

---

## Examples

**Input:** root = [2,1,3]
**Output:** true

**Input:** root = [5,1,4,null,null,3,6]
**Output:** false

---

## 💡 Approach: Range Validation with DFS

### Key Idea

A BST is not only about comparing a node with its direct parent.

Each node must stay within a valid range:

* Left subtree nodes must be within `(low, parent value)`
* Right subtree nodes must be within `(parent value, high)`

So instead of checking only immediate children, we recursively pass down the allowed value boundaries.

---

## Why This Works

At every node:

* If the node value is outside its allowed range → invalid BST.
* Otherwise:

  * Check left subtree with updated upper bound.
  * Check right subtree with updated lower bound.

This guarantees every node respects the BST property across the whole tree.

---

## Example Walkthrough

Tree:

```text
      5
     / \
    1   7
       / \
      4   8
```

Start with range `(-∞, +∞)`

* Node `5` → valid
* Left child `1` → must be in `(-∞, 5)` → valid
* Right child `7` → must be in `(5, +∞)` → valid
* Node `4` in right subtree → must be in `(5, 7)`

But `4 < 5`

So the tree is invalid.

---

## Complexity

**Time Complexity:** `O(n)`
Each node is visited once.

**Space Complexity:** `O(h)`
Where `h` is the tree height due to recursion stack.

* Worst case: `O(n)` for skewed tree
* Best case: `O(log n)` for balanced tree

---

## Code (C++)

```cpp
class Solution {
public:
    bool check(TreeNode* node, long long low, long long high) {
        if (node == nullptr) return true;

        if (node->val <= low || node->val >= high)
            return false;

        return check(node->left, low, node->val) &&
               check(node->right, node->val, high);
    }

    bool isValidBST(TreeNode* root) {
        return check(root, LLONG_MIN, LLONG_MAX);
    }
};
```
