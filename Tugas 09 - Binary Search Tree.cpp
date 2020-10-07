#include <iostream>
#include <conio.h>
#include <cstdlib>

using namespace std;

struct node
{
char info;
struct node *left;
struct node *right;
} *root;

class BST
{
	public:
        void find(int, node **, node **);    
        void insert(node *, node *);
        void del(int);
        void case_a(node *,node *);
        void case_b(node *,node *);
        void case_c(node *,node *);
        void preorder(node *);
        void inorder(node *);
        void postorder(node *);
        void display(node *, int);
        
        BST()
        {
        	root = NULL;
        }
};

int main()
{
int pilih;
int num;
BST bst;
node *temp;

    do
    {
    	system("CLS");
    	
        cout << "1. Insert" << endl
	         << "2. Delete" << endl
	         << "3. Inorder" << endl
	         << "4. Preorder" << endl
	         << "5. Postorder" << endl
	         << "6. Display" << endl
	         << "7. Exit" << endl
	         << "Pilihan anda: ";
        cin >> pilih;

        switch (pilih)
        {
	        case 1:
	        {
				temp = new node;
				cout << "Masukkan huruf: ";
				cin >> temp -> info;
				bst.insert(root, temp);  
				break;      	
			}
	
	
	        case 2:
			{
	            if (root == NULL)
	            {
	                cout << "Tree is empty" << endl;
	                getch();
	                continue;
	            }
	
	            cout << "Enter the number to be deleted: ";
	            cin >> num;
	            bst.del(num);	
	            break;
			}
			
	        case 3:
	        {
	        	cout << "Inorder Traversal of BST:" << endl;
	            bst.inorder(root);
	            cout << endl;
	            getch();
	            break;
			}
	
			case 4:
			{
	            cout << "Preorder Traversal of BST:" << endl;
	            bst.preorder(root);
	            cout << endl;
	            getch();
	            break;
			}
	
	        case 5:
	        {
	            cout << "Postorder Traversal of BST:" << endl;
	            bst.postorder(root);
	            cout << endl;
	            getch();
	            break;
			}
			
	        case 6:
			{
		        cout << "Display BST:" << endl;
	            bst.display(root,1);
	            cout << endl;
	            getch();
	            break;
			}
	
	        case 7:
			{
				cout << "Exiting...";
				system("EXIT");
			}
        }
    }
    while (pilih != 7);
    
getch();
return 0;
}

void BST::find(int item, node **parent, node **posisi)
{
node *ptr;
node *ptrsave;

    if (root == NULL)
    {
        *posisi = NULL;
        *parent = NULL;
        return;
    }

    if (item == root -> info)
    {
        *posisi = root;
        *parent = NULL;
        return;
    }

    if (item < root -> info)
    {
        ptr = root -> left;
	}
	    else
		{
	        ptr = root -> right;			
		}

    ptrsave = root;

    while (ptr != NULL)
    {
        if (item == ptr -> info)
        {
            *posisi = ptr;
            *parent = ptrsave;
            return;
        }
        
        ptrsave = ptr;
        
        if (item < ptr -> info)
        {
        	ptr = ptr -> left;
		}
			else
			{
	    		ptr = ptr -> right;
	    	}
    }

    *posisi = NULL;
    *parent = ptrsave;
}

void BST::insert(node *tree, node *newnode)
{
    if (root == NULL)
    {
        root = new node;
        root -> info = newnode -> info;
        root -> left = NULL;
        root -> right = NULL;
        cout << "Root Node is added" << endl;
        getch();
        return;
    }

    if (tree -> info == newnode -> info)
    {
        cout << "Huruf sudah ada!" << endl;
        getch();
        return;
    }

    if (tree -> info > newnode -> info)
    {
        if (tree -> left != NULL)
        {
            insert(tree -> left, newnode);	
		}
			else
			{
	            tree -> left = newnode;
	            (tree -> left) -> left = NULL;
	            (tree -> left) -> right = NULL;
	            cout << "Data tersimpan dari kiri" << endl;
	            getch();
	            return;
		    }
    }
    	else
	    {
	        if (tree -> right != NULL)
	        {
	            insert(tree -> right, newnode);
	        }
		        else
		        {
		            tree -> right = newnode;
		            (tree -> right) -> left = NULL;
		            (tree -> right) -> right = NULL;
		            cout << "Data tersimpan dari kanan" << endl;
		            getch();
		            return;
		        }	
	    }
}

void BST::del(int item)
{
node *parent;
node *location;

    if (root == NULL)
    {
        cout << "Tree is empty" << endl;
        getch();
        return;
    }

    find(item, &parent, &location);

    if (location == NULL)
    {
        cout << "Huruf tidak ditemukan" << endl;
        getch();
        return;
    }

    if (location -> left == NULL && location -> right == NULL)
    {
        case_a(parent, location);    	
	}

    if (location->left != NULL && location -> right == NULL)
    {
        case_b(parent, location);   	
	}

    if (location->left == NULL && location -> right != NULL)
    {
        case_b(parent, location);    	
	}

    if (location->left != NULL && location -> right != NULL)
    {
        case_c(parent, location);    	
	}

    free(location);
}

void BST::case_a(node *parent, node *posisi)
{
    if (parent == NULL)
    {
        root = NULL;
    }
	    else
	    {
	        if (posisi == parent -> left)
	        {
	        	parent -> left = NULL;
			}
		        else
		        {
		        	parent -> right = NULL;
				}
	    }
}

void BST::case_b(node *parent, node *posisi)
{
node *child;

    if (posisi -> left != NULL)
	{
        child = posisi -> left;
	}
	    else
	    {
	    	child = posisi -> right;
		}

    if (parent == NULL)
    {
        root = child;
    }
	    else
	    {
	        if (posisi == parent -> left)
	        {
	            parent -> left = child;
	        }
		        else
		        {
		            parent -> right = child;
		        }
	    }
}

void BST::case_c(node *parent, node *posisi)
{
node *ptr;
node *ptrsave;
node *suc;
node *parsuc;

    ptrsave = posisi;
    ptr = posisi -> right;
    
    while (ptr -> left != NULL)
    {
        ptrsave = ptr;
        ptr = ptr->left;
    }
    
    suc = ptr;
    parsuc = ptrsave;

    if (suc -> left == NULL && suc -> right == NULL)
	{
        case_a(parsuc, suc);
	}
    	else
		{
        	case_b(parsuc, suc);
		}
		
    if (parent == NULL)
    {
        root = suc;
    }
	    else
	    {
	        if (posisi == parent -> left)
			{
	            parent -> left = suc;
	        }
				else
	            {
					parent -> right = suc;
				}
	    }

    suc -> left = posisi -> left;
    suc -> right = posisi -> right;
}

void BST::preorder(node *ptr)
{
    if (root == NULL)
    {
        cout << "Tree is empty" << endl;
        getch();
        return;
    }

    if (ptr != NULL)
    {
        cout << ptr -> info << "  ";
        preorder(ptr -> left);
        preorder(ptr -> right);
    }
}

void BST::inorder(node *ptr)
{
    if (root == NULL)
    {
        cout << "Tree is empty" << endl;
        getch();
        return;
    }
    
    if (ptr != NULL)
    {
        inorder(ptr -> left);
        cout << ptr -> info << "  ";
        inorder(ptr -> right);
    }
}

void BST::postorder(node *ptr)
{
    if (root == NULL)
    {
        cout << "Tree is empty" << endl;
        getch();
        return;
    }

    if (ptr != NULL)
    {
        postorder(ptr -> left);
        postorder(ptr -> right);
        cout << ptr -> info<<"  ";
    }
}

void BST::display(node *ptr, int level)
{
int i;

    if (ptr != NULL)
    {
        display(ptr -> right, level + 1);
        cout << endl;
        
        if (ptr == root)
        {
            cout << "Root->:  ";
            getch();
        }
			else
        	{
        	    for (i = 0; i < level; i++)
        	    {
        	        cout << "       ";
        	        getch();
        	    }
			}
			
        cout << ptr -> info;

        display(ptr -> left, level + 1);
    }
}
