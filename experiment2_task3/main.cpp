#include <iostream>
using namespace std;

class BST
{
    int data;
    BST *left, *right;

public:
    // Default constructor.
    BST();

    // Parameterized constructor.
    BST(int);

    // Insert function.
    BST *Insert(BST *, int);

    // Inorder traversal.
    void Inorder(BST *);
    int Count(BST *);
};

// Default Constructor definition.
BST ::BST()
    : data(0), left(NULL), right(NULL)
{
}

// Parameterized Constructor definition.
BST ::BST(int value)
{
    data = value;
    left = right = NULL;
}

// Insert function definition.
BST *BST ::Insert(BST *root, int value)
{
    if (!root)
    {
        // Insert the first node, if root is NULL.
        return new BST(value);
    }

    // Insert data.
    if (value > root->data)
    {
        // Insert right node data, if the 'value'
        // to be inserted is greater than 'root' node data.

        // Process right nodes.
        root->right = Insert(root->right, value);
    }
    else if (value < root->data)
    {
        // Insert left node data, if the 'value'
        // to be inserted is smaller than 'root' node data.

        // Process left nodes.
        root->left = Insert(root->left, value);
    }

    // Return 'root' node, after insertion.
    return root;
}

// Inorder traversal function.
// This gives data in sorted order.
void BST ::Inorder(BST *root)
{
    if (!root)
    {
        return;
    }
    Inorder(root->left);
    cout << root->data << endl;
    Inorder(root->right);
}
int BST ::Count(BST *root)
{

    if (root == NULL)
    {
        return 0;
    }

    int leftvalue = Count(root->left);
    int rightValue = Count(root->right);
    if (leftvalue > rightValue)
    {
        return leftvalue + 1;
    }

    return rightValue + 1;
}

int main()
{
    int c;

    cin >> c;
    for (int i = 0; i < c; i++)
    {
        BST b,
            *root = NULL;
        bool first = false;
        int a;
        while (cin >> a)
        {
            if (!first)
            {

                root = b.Insert(root, a);
            }
            else
            {
                b.Insert(root, a);
            }

            char ch = getchar(); //通过getchar()来判断最后输入回车符结束
            if (ch == '\n')
                break;
        }

        cout << b.Count(root) << endl;
    }

    return 0;
}
