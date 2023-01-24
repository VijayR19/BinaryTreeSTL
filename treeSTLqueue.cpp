#include<iostream>
#include<queue>
using namespace std;

class Node{
        public:
        Node* lchild;
        int data;
        Node* rchild;
};

class Tree{
private:
        Node* root;
public:
        Tree();
        ~Tree();
        void CreateTree();
        void preOrder(Node *p);
        void preOrder(){preOrder(root);} //passing Private parameter in COnstructor
        void Inorder(Node* p);
        void Inorder(){Inorder(root);}
        void postorder(Node* p);
        void postorder(){postorder(root);}
        void levelorder(Node* p);
        void levelorder(){levelorder(root);}
        int Height(Node* p);
        int Height(){return Height(root);} //if only root avaiable then the height = 0;

};

Tree::Tree(){
        root = nullptr;
}

Tree::~Tree(){
        //TODO
}

void Tree::CreateTree(){
        Node* p = nullptr;
        Node* t = nullptr;
        int x;
        queue<Node*>q;

        root = new Node;
        cout<<"Enter root data: "<<flush;
        cin>>x;
        root->data = x;
        root->lchild = nullptr;
        root->rchild = nullptr;
        q.emplace(root);

        while(!q.empty()){
                p = q.front();
                q.pop();

                cout<<"Enter left child data of "<<p->data<<": "<<flush;
                cin>>x;
                if(x != -1){
                        t = new Node;
                        t->data = x;
                        t->lchild = nullptr;
                        t->rchild = nullptr;
                        p->lchild = t;
                        q.emplace(t);
                }
                
                cout<<"Enter the right data of "<<p->data<<": "<<flush;
                cin>>x;
                if(x != -1){
                        t = new Node;
                        t->data = x;
                        t->lchild = nullptr;
                        t->rchild = nullptr;
                        p->rchild = t;
                        q.emplace(t);
                }
        }
}

void Tree::preOrder(Node* p){
        if(p){
                cout<<p->data<<", "<<flush;
                preOrder(p->lchild);
                preOrder(p->rchild);
        }
}

void Tree::Inorder(Node* p){
        if(p){
                Inorder(p->lchild);
                cout<<p->data<<", "<<flush;
                Inorder(p->rchild);
        }
}

void Tree::postorder(Node* p){
        if(p){
                postorder(p->lchild);
                postorder(p->rchild);
                cout<<p->data<<", "<<flush;
        }
}

void Tree::levelorder(Node* p){
        queue<Node*> q;
        cout<<root->data<<", "<<flush;
        q.emplace(root);

        while(!q.empty()){
                p = q.front();
                q.pop();

                if(p->lchild){
                        cout<<p->lchild->data<<", "<<flush;
                        q.emplace(p->lchild);
                }
                if(p->rchild){
                        cout<<p->rchild->data<<", "<<flush;
                        q.emplace(p->rchild);
                }
        }
}

int Tree::Height(Node *p){
        int l = 0;
        int r = 0;
        if(p == nullptr)
                return 0;
        
        l = Height(p->lchild);
        r = Height(p->rchild);

        if(l > r)
                return l+1;
        else
                return r+1;
}

int main()
{
        Tree bt;
        bt.CreateTree();
        cout<<endl;

        cout<<"Preorder: "<<flush;
        bt.preOrder();
        cout<<endl;

        cout<<"Inorder: "<<flush;
        bt.Inorder();
        cout<<endl;

        cout<<"PostOrder: "<<flush;
        bt.postorder();
        cout<<endl;

        cout<<"LevelOrder: "<<flush;
        bt.levelorder();
        cout<<endl;

        cout<<"Height: "<<bt.Height()<<endl;
        
        return 0;
}