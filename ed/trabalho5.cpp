template <class T>
struct node {
    T key;
    node<T> *left, *right;
    node(T x)   {
        key = x;
        left=right=0;
   }
};

template <class U>
struct bst {
 node<U>* root;

 void __add__(node<U> r, U x) {
     if (r==0)
        r = new node<U>(x);
     else if (x==r->key)
        return;
     else if(x < r->key) {
        __add__(r->left, x);
     } else {
        __add__(r->right, x); 
     }
 }  
 void add(U x) {
   __add__(root, x);
 } 
 node<U>* __rev__ (node<U>* a) {
    // implenente aqui
 }
 void rev() {
   __rev__(root);
 }
};

int main() {
}
