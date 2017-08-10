#include<iostream>

#define MAX(a,b)(a>b?a:b)
using namespace std ;

class node {
    public:
        int data ;
        node *left, *right ;

        node(){
            data = 0 ;
            left = right = NULL ;
        }
};

class AVLTree {
    public :
        node *root ;

        AVLTree() { root = NULL ;}
        
        void Insert(int data){
            InsertP(data, root) ;
            cout << "Insert : " << data << " complete: " << endl ;
        }

        void InsertP(int data, node *(&p)){
            if( p == NULL) {
                p = new node() ;
                p->data = data ;
            }
            else {
                // down right
                if( data > p->data ){
                    InsertP(data , p->right) ;
                    if(heightDiff(p) < -1 ){
                        if(heightDiff(p->right) < 0 ){
                            p = RR(p) ;
                            cout << "RR " << endl ;
                        }
                        else{
                            p = RL(p) ;
                            cout << "RL " << endl ;
                        }
                    }
                }
                // down left
                else {
                    InsertP(data, p->left) ;
                    if(heightDiff(p) > 1 ){
                        if(heightDiff(p->left) > 0 ){
                            p = LL(p) ;
                            cout << "LL " << endl ;
                        }
                        else{
                            p = LR(p) ;
                            cout << "LR " << endl ;
                        }
                    }
                }
            }
        }

        void Inorder(node *p) {
            if( p == NULL)
                return ;
            Inorder(p->left) ;
            cout << p->data << " " ;
            Inorder(p->right) ;
        }

        int height(node *p){
            if(p == NULL)
                return 0 ;
            else {
                return MAX( height(p->left)+1 , height(p->right)+1);
            }
        }

        int heightDiff(node *p){
            int diff = height(p->left) - height(p->right) ;
            cout << "diff : " << diff << endl ;
            return diff ;
        }

        node* RR(node *p){
            node *q = p->right ;
            p->right = q->left;
            q->left = p ;
            return p ;
        }

        node* LL(node *p){
            node *q = p->left ;
            p->left = q->right ;
            q->right = p ;
            return p ;
        }

        node* LR(node *p){
            node *q = p->left ;
            p->left = RR(q) ;
            return LL(p) ;
        }

        node* RL(node *p){
            node *q = p->right ;
            p->right = LL(q) ;
            return RR(p) ;
        }

        node* getRoot(){
            return root ;
        }
} ;

int main()
{
    AVLTree *t = new AVLTree() ;
    t->Insert(9);
    t->Insert(10);
    t->Insert(2);  
    t->Insert(1);
    t->Insert(5);
    t->Insert(3);  
  /*  t->Insert(6);
    t->Insert(4);
    t->Insert(7);  
    t->Insert(11);
    t->Insert(12);
   */ t->Inorder(t->getRoot()) ;


    return 0 ;
}
