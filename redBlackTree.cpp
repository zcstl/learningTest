/***
 *from wikipedia
 *annotated by zcszcs
 *
 *
 * ***/
#define BLACK 1
#define RED 0

using namespace std;

class bst {
	private:
		struct Node 
		{
			int value;
			bool color;
			Node *leftTree, *rightTree, *parent; //
			
			Node() 
			{
				color = RED;
				leftTree = NULL;
				rightTree = NULL;
				parent = NULL;
				value = 0;
			}

			Node* grandparent()
			{
				if(parent == NULL)
				{
					return NULL;
				}
				return parent->parent;
			}

			Node* uncle() 
			{
				if(grandparent(） == NULL)
				{
					return NULL;
				}
				if(parent == grandparent()->rightTree)
					return grandparent()->leftTree;
				else
					return grandparent()->rightTree;
			}

			Node* sibling() 
			{
				if(parent->leftTree == this)
					return parent->rightTree;
				else
					return parent->leftTree;
			}
		};
	//右旋转,p为中间node
	void rotate_right(Node *p)
	{
		Node *gp = p->grandparent();
		Node *fa = p->parent;
		Node *y = p->rightTree;

		fa->leftTree = y;
		//red black tree的节点定义含有parent指针,不同于BST
		if(y != NIL)
			y->parent = fa;
		p->rightTree = fa;
		fa->parent = p;

		if(root == fa)
			root = p;
		//fa为root的话,gp为NULL
		p->parent = gp;

		if(gp != NULL)
		{
			if(gp->leftTree == fa)
				gp->leftTree = p;
			else
				gp->rightTree = p;
		}

	}

	void rotate_left(Node *p)
	{
		if(p->parent == NULL)
		{
			root = p;
			return;
		}
		Node *gp = p->grandparent();
		Node *fa = p->parent;
		Node *y = p->leftTree;

		fa->rightTree = y;

		if(y != NIL)
			y->parent = fa;
			p->leftTree = fa;
			fa->parent = p;

		if(root == fa)
			root = p;
		p->parent = gp;

		if(gp != NULL)
		{
			if(gp->leftTree == fa)
				gp->leftTree = p;
			else
				gp->rightTree = p;
		}
	}

	//中序遍历
	void inorder(Node *p)
	{
		if(p == NIL)
			return;

		if(p->leftTree)
			inorder(p->leftTree);

		//这句cout在上句前,为先序遍历
		//在下句后,为后序遍历
		cout << p->value << " ";

		if(p->rightTree)
			inorder(p->rightTree);
	}

	string outputColor (bool color)
	{
	//1 True , 0 FALSE
		return color ? "BLACK" : "RED";
	}
	
	//返回P的最小值,若无左子树,则为其本身
	Node* getSmallestChild(Node *p)
	{
		if(p->leftTree == NIL)
			return p;
		return getSmallestChild(p->leftTree);
	}

	//常规BST方式找到要删除的节点(该节点的左节点定为NIL)
	//调用delete_one_child,以满足RBT定义的方式删除节点
	bool delete_child(Node *p, int data)
	{
		if(p->value > data)
		{
			if(p->leftTree == NIL)
				return false;		
			return delete_child(p->leftTree, data);
		}
		else if(p->value < data)
		{
			if(p->rightTree == NIL)
				return false;
			return delete_child(p->rightTree, data);
		} else if(p->value == data)
		{
			if(p->rightTree == NIL)
			{
				delete_one_child (p);
				return true;
			}
			Node *smallest = getSmallestChild(p->rightTree);
			swap(p->value, smallest->value);
			delete_one_child (smallest);
			return true;
		}		
	}

	//删除节点P,且满足RBT定义
	//P的左节点为NIL
	void delete_one_child(Node *p)
	{
		//若P左子树不为NIL,说明P为原待删除节点(且没有右子树,故没有swap)
		/*****
		 *若左右子树均为NIL,其child为NIL,对case3的影响???
		 *貌似没有影响,应为child节点在以后的case里可为NIL
		 * ****/
		Node *child = p->leftTree == NIL ? p->rightTree : p->leftTree;
		//case1: p为root且子节点都为NIL
		if(p->parent == NULL && p->leftTree == NIL && p->rightTree == NIL)
		{
			p = NULL;
		root = p;
		return;
		}
		//case1: P为root,且左子树不为NIL,右子树为NIL(若右子树不为NIL,则p定不为root)
		if(p->parent == NULL)
		{
			delete  p;
			child->parent = NULL;
			root = child;
			root->color = BLACK;
			return;
		}

		//case1: 把child变为fa的子树,替代p
		//如果p黑c红,c改为黑,恢复平衡
		//如果p红,直接删掉
		//否则,pc均为黑,调用delete_case,进入case2
		if(p->parent->leftTree == p)
		{
			p->parent->leftTree = child;
		} else 
		{
			p->parent->rightTree = child;
		}
		child->parent = p->parent;

		if(p->color == BLACK)
		{
			if(child->color == RED)
			{
			child->color = BLACK;
			} else
				delete_case (child);
		}

		delete p;
	}

	//p和其唯一的非NIL
	void delete_case(Node *p)
	{
		//p为root
		if(p->parent == NULL)
		{
			p->color = BLACK;
			return;
		}
		//case2
		if(p->sibling()->color == RED) 
		{
			p->parent->color = RED;
			p->sibling()->color = BLACK;
			if(p == p->parent->leftTree)
				rotate_left(p->sibling());
			else
				rotate_right(p->sibling());
		}
		//case3
		if(p->parent->color == BLACK && p->sibling()->color == BLACK
			&& p->sibling()->leftTree->color == BLACK && p->sibling()->rightTree->color == BLACK)
		{
			p->sibling()->color = RED;
			delete_case(p->parent);
			//case4
		} else if(p->parent->color == RED && p->sibling()->color == BLACK
			&& p->sibling()->leftTree->color == BLACK && p->sibling()->rightTree->color == BLACK) 
		{
			p->sibling()->color = RED;
			p->parent->color = BLACK;
		} else {
			if(p->sibling()->color == BLACK)
			{	
				//case5
				if(p == p->parent->leftTree && p->sibling()->leftTree->color == RED
					&& p->sibling()->rightTree->color == BLACK) 
				{
					p->sibling()->color = RED;
					p->sibling()->leftTree->color = BLACK;
					rotate_right(p->sibling()->leftTree);
				} else if(p == p->parent->rightTree && p->sibling()->leftTree->color == BLACK
					&& p->sibling()->rightTree->color == RED)
				{	
					//case5
					p->sibling()->color = RED;
					p->sibling()->rightTree->color = BLACK;
					rotate_left(p->sibling()->rightTree);
				}
			}
			//case6
			p->sibling()->color = p->parent->color;
			p->parent->color = BLACK;
			if(p == p->parent->leftTree)
			{
				p->sibling()->rightTree->color = BLACK;
				rotate_left(p->sibling());
			} else
			{
				p->sibling()->leftTree->color = BLACK;
				rotate_right(p->sibling());
			}
		}
	}

	/****
	 *按照BST找到插入位置(子节点都为NIL),然后调用insert_case插入,以满足RBT的定义
	 *该函数考虑了插入元素与T中的值相等的情况
	 *若相等,则当做小于处理
	 * ***/
	void insert(Node *p, int data)
	{
		if(p->value >= data)
		{
			if(p->leftTree != NIL)
				insert(p->leftTree, data);
			else
		{
			Node *tmp = new Node();
			tmp->value = data;
			tmp->leftTree = tmp->rightTree = NIL;
			tmp->parent = p;
			p->leftTree = tmp;
			insert_case (tmp);
		}
		}
		else
		{
			if(p->rightTree != NIL)
				insert(p->rightTree, data);
			else
			{
				Node *tmp = new Node();
				tmp->value = data;
				tmp->leftTree = tmp->rightTree = NIL;
				tmp->parent = p;
				p->rightTree = tmp;
				insert_case (tmp);
			}
		}
	}


	void insert_case(Node *p)
	{
		//case1  为root
		//此if在该cpp中的意义?insert()就就已经表明P非root
		if(p->parent == NULL)
		{
			root = p;
			p->color = BLACK;
			return;
		}
		
		if(p->parent->color == RED)
		{	
			//case3
			if(p->uncle()->color == RED)
			{
				p->parent->color = p->uncle()->color = BLACK;
				p->grandparent()->color = RED;
				insert_case(p->grandparent());
			}
			else 
			{
				//case4
				if(p->parent->rightTree == p && p->grandparent()->leftTree == p->parent) 
				{
					//bug
					rotate_left (p);
					rotate_right (p);
					p->color = BLACK;
					p->leftTree->color = p->rightTree->color = RED;
				} 
				else if(p->parent->leftTree == p && p->grandparent()->rightTree == p->parent) 
				{
					//bug
					rotate_right (p);
					rotate_left (p);
					p->color = BLACK;
					p->leftTree->color = p->rightTree->color = RED;
				}
				//case5
				else if(p->parent->leftTree == p && p->grandparent()->leftTree == p->parent) 
				{
					p->parent->color = BLACK;
					p->grandparent()->color = RED;
					rotate_right(p->parent);
				} else if(p->parent->rightTree == p && p->grandparent()->rightTree == p->parent) 
				{
					p->parent->color = BLACK;
					p->grandparent()->color = RED;
					rotate_left(p->parent);
				}
			}
		}
		//case2  父节点为黑,新节点默认为红
}

	//删除T
	void DeleteTree(Node *p)
	{
		if(!p || p == NIL)
			return;
		DeleteTree(p->leftTree);
		DeleteTree(p->rightTree);
		delete p;
	}

	public:

	bst()
	{
		//?
		NIL = new Node();
		NIL->color = BLACK;
		root = NULL;
	}

	~bst()
	{
		if (root)
			DeleteTree (root);
		delete NIL;
	}

	void inorder() 
	{
		if(root == NULL)
			return;
		inorder (root);
		cout << endl;
	}

	void insert (int x)
	{
		if(root == NULL){
			root = new Node();
			root->color = BLACK;
			root->leftTree = root->rightTree = NIL;
			root->value = x;
		} else {
			insert(root, x);
		}
	}

	bool delete_value (int data)
	{
		return delete_child(root, data);
	}

	private:
		Node *root, *NIL;
};
