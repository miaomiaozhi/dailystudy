#include <iostream>
using namespace std;

class BiNode {
private:
    char data;       //可以自己换类型
    BiNode *lchild;
    BiNode *rchild;

public:
    BiNode(){
        lchild = NULL;
        rchild = NULL;
    }

    BiNode(int e) {     //有传入参数的话调用此函数可直接行成节点
        data = e;
        lchild = NULL;
        rchild = NULL;
    }

    ~BiNode(){
        delete lchild;
        delete rchild;
    }
    friend class BiTree;
};

class BiTree {
private:
    BiNode *root;
    void CreateTree(BiNode *&t){    //建树
        char c;  
        cin >> c;
        if (c != '#'){             //一般以‘#’为空节点
            t = new BiNode(c);
            //这里采用前序遍历建树
            CreateTree(t -> lchild);  
            CreateTree(t -> rchild);
        }
        else
            t = NULL;
    }
    void PreOrder(BiNode *t) {     //前序遍历
        if (t) {
            cout << t -> data;
            PreOrder(t -> lchild);
            PreOrder(t -> rchild);
        }
    }

    void InOrder(BiNode *t) {      //中序遍历
        if (t) {
            InOrder(t -> lchild);
            cout << t -> data;
            InOrder(t -> rchild);
        }
    }

    void PostOrder(BiNode *t) {    //后序遍历
        if (t) {
            PostOrder(t -> lchild);
            PostOrder(t -> rchild);
            cout << t -> data;
        }
    }

public:
    BiTree(){
        root = NULL;
    }

    ~BiTree() {
        delete root;
    }

    //以下全部为启动函数
    void CreateTree() {
        CreateTree(root);
    }

    void PreOrder() {
        PreOrder(root);
        cout << endl;
    }
    void InOrder() {
        InOrder(root);
        cout << endl;
    }
    void PostOrder() {
        PostOrder(root);
        cout << endl;
    }
};

int main() {
    BiTree tree;

    //建树、前序遍历、中序遍历、后序遍历
    tree.CreateTree();
    tree.PreOrder();
    // tree.InOrder();
    // tree.PostOrder();

    return 0;
}