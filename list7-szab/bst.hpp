#ifndef CLASS_BST
#define CLASS_BST

#include "treit.hpp"

namespace struktury{
    template <class T, typename traits = first_type_traits<T> >
    class Bst{
    private:
        class Node{
            T elem;
            Node *lt,*rt;
        public:
            friend void delete_all(Node *wezel);
            friend const Node* lookup(T key, const Node *wezel);
            friend void deletion(T del_el, Node *&wezel);
            friend void insertion(T new_el, Node *&wezel);
            friend void copy_tree(Node *&Root, Node *const &wezel);
            friend void fill_out(std::ostream &out, Node *const &wezel);
            Node(T wart){
                elem=wart;
                lt=nullptr;
                rt=nullptr;
            }
        };
        friend void delete_all(Node *wezel){
            if(wezel){
                delete_all(wezel->lt);
                delete_all(wezel->rt);
                wezel->~Node();
                wezel=nullptr;
            }
        }
        friend void insertion(T new_el, Node *&wezel){
            if(!wezel){
                wezel=new Node(new_el);
            }
            else if(traits::compare(new_el,wezel->elem))
                insertion(new_el, wezel->rt);
            else if (traits::compare(wezel->elem,new_el))
                insertion(new_el, wezel->lt);
        }
        friend const Node* lookup(T key, const Node *wezel){
            if(!wezel)
                throw std::invalid_argument("Brak elementu!");
            else if(traits::compare(key,wezel->elem))
                return lookup(key, wezel->rt);
            else if(traits::compare(wezel->elem,key))
                return lookup(key, wezel->lt);
            else
                return wezel;
        }
        friend void deletion(T del_el, Node *&wezel){
            if(!wezel)
                return;
            if(traits::compare(del_el,wezel->elem))
                deletion(del_el, wezel->rt);
            else if(traits::compare(wezel->elem,del_el))
                deletion(del_el, wezel->lt);
            else{
                if(!wezel->lt){
                    Node *buf=wezel->rt;
                    delete wezel;
                    wezel=buf;
                }
                else if(!wezel->rt){
                    Node *buf=wezel->lt;
                    delete wezel;
                    wezel=buf;
                }
                else{
                    Node *prev=wezel;
                    Node *curr=wezel->rt;
                    while(curr->lt!=NULL){
                        prev = curr;
                        curr = curr->lt;
                    }
                    wezel->elem=curr->elem;
                    if (prev!=wezel)
                        prev->lt = curr->rt;
                    else
                        wezel->rt = curr->rt;
                    delete curr;
                }
            }
        }
        Node *root;
        friend void copy_tree(Node *&Root, Node *const &wezel){
            if(!wezel)
                return;
            insertion(wezel->elem,Root);
            copy_tree(Root->lt, wezel->lt);
            copy_tree(Root->rt, wezel->rt);
        }
        friend void fill_out(std::ostream &out, Node *const &wezel){
            if(!wezel)
                return;
            fill_out(out, wezel->lt);
            out << wezel->elem << " ";
            fill_out(out, wezel->rt);
        }
    public:
        template <typename U>
        friend std::ostream& operator<< (std::ostream &out, const Bst<U> &drzew);
        Bst(){
            root=nullptr;
        }
        ~Bst(){
            delete_all(root);
        }
        Bst(const std::initializer_list<T> &lista) {
            root=nullptr;
            for (const T &element : lista)
                insertion(element, root);
        }
        Bst(const Bst &obj) {
            this->root=nullptr;
            copy_tree(this->root,obj.root);
        }
        Bst &operator=(const Bst &obj) {
            if (this == &obj)
                return *this;
            this->delete_all(this->root);
            copy_tree(this->root,obj.root);
            return *this;
        }
        Bst(Bst &&obj){
            this->node = obj.node;
            obj.node=nullptr;
        }
        Bst &operator=(Bst &&obj) {
            this->delete_all(this->root);
            this->node = obj.node;
            obj.node=nullptr;
            return *this;
        }
        Bst<T> ins(T new_el){
            insertion(new_el, root);
            return *this;
        }
        const Node* fnd(T key){
            return lookup(key, root);
        }
        Bst<T> dlt(T new_el){
            deletion(new_el, root);
            return *this;
        }
    };

    template <typename T>
    std::ostream& operator<< (std::ostream &out, const Bst<T> &drzew){
        fill_out(out,drzew.root);
        return out;
    }
}

#endif // CLASS_BST
