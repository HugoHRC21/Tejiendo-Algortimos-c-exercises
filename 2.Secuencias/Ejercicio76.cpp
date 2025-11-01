#include<iostream>
#include<string>

using namespace std;


template <typename T>
class Slink
{
protected:
    Slink * next;
public:
  Slink() : next(this) {}

  void reset(){
    next = this; 
  }

  bool is_empty() const {
    return next == this; 
  }

  Slink *& get_next(){
    return next; 
  }

  void insert_next(Slink * p){
    assert(p not_eq nullptr);
    assert(p->is_empty());

    p->next = next;
    next = p;
  }

  Slink * remove_next()
  {
    Slink * ret_val = next;
    next = ret_val->next;
    ret_val->reset();
    return ret_val;
  }    
};

template <typename T> 
class Snode : public Slink
{
private:
  T data;
public:

    Snode() { /* empty*/ }

    Snode(const T & _data) : data(_data) {}
    Snode(const T && _data) : data(_data) {}

    Snode * remove_next() { 
        return (Snode*) Slink::remove_next(); 
    }
    Snode *& get_next() { 
        return (Snode*&) Slink::get_next(); 
    }

    Snode * remove_first() { 
        return Snode::remove_next(); 
    }

    Snode *& get_first() const { 
        return Snode::get_next(); 
    }
};

template <typename T> 
class Slist : public Snode<T> {
public:
    typedef Snode<T> Node;
    Slist() {}

    void insert_first(Node * node)
     {
      assert(node not_eq nullptr);
      assert(node->is_empty());

       this->insert_next(node);
     }
     
    Node * remove_first() 
        throw(exception, underflow_error) {
            if (this->is_empty())
                throw underflow_error ("list is empty");
                return this->remove_next();
        }

    Node * get_first() 
        Exception_Prototypes(underflow_error){
            if (this->is_empty())
                throw underflow_error ("list is empty");
                return this->get_next(); 
    }






  class Iterator
  {

  private:

    Slist * list;
    Node  * current;

  public:
        /// El tipo de conjunto sobre el cual se itera.
    typedef Snode<T> Set_Type;
        /// El tipo de elemento que retorna get_current().
    typedef Snode<T> * Item_Type;

      /** Constructor.

          Construye un iterador sobre la lista de nodos list.

          @param[in] _list la lista sobre la cual se desea iterar.
      */
    Iterator(Slist & _list) : list(&_list), current(list->get_first()) {}

        /// Retorna true si el iterador tiene nodo actual.
    bool has_current() const { return current != list; }

        /** Retorna el nodo actual sobre el cual está posicionado el iterador.

            @return un apuntador al elemento actual.
            @throw overflow_error si el iterador no está posicionado sobre 
            un elemento. 
         */
    Node * get_current() 

      throw(std::exception, std::overflow_error)

    {

      if (not this->has_current())
        throw std::overflow_error ("");

      return current;
    }
        /** Avanza el iterador hacia adelante.

            Avanza el iterador hacia el elemento siguiente del actual.

            Si el iterador se encuentra en el último elemento de la secuencia,
            entonces éste queda en un estado en que no hay elemento actual.

            @throw overflow_error si el iterador no se encuentra sobre un elemento 
            actual.
         */
    void next()

      throw(std::exception, std::overflow_error)

    {

      if (not this->has_current())
        throw std::overflow_error ("");

      current = current->get_next();
    }
        /// Coloca el iterador en el primer elemento de la lista.
    void reset_first() { current = list->get_next(); }
    Iterator & operator = (Node * node)
    {
      if (this == node) 
        return *this;

      current = node;
      return *this;
    }
  };
};

template <typename T> 
class Iterator{
    private:
        Slist * list;
        Node  * current;

    public:
        typedef Snode<T> Set_Type;
        typedef Snode<T> * Item_Type;

    Iterator(Slist & _list) : list(&_list), current(list->get_first()) {}

    bool has_current() const { return current != list; }

    Node * get_current(){
        throw(exception, overflow_error){
            if (not this->has_current()){
                throw std::overflow_error ("");
                return current;
                }
            }
    }
    void next(){
        throw(exception, overflow_error){
            if (not this->has_current()){
                throw std::overflow_error ("");
                current = current->get_next();
            }
        }
    }
    
    void reset_first() { 
        current = list->get_next(); 
    }
    
    
    Iterator & operator = (Node * node){
        if (this == node){
            return *this;
        }

        current = node;
        return *this;
    }
};

 template <typename T>
class DynSlist : public Slist<T>{
    private:
        size_t num_items;
        int        current_pos;
        Snode<T> * current_node;
        typename Slist<T>::Node * get_previous_to_pos(const int & pos){
            if (pos > num_items){
                throw out_of_range ("position out of range");
            }
           if (pos < current_pos){ 
                current_pos  = 0;
                current_node = this;
            }
            while (current_pos < pos){ 
                current_node = current_node->get_next();
                ++current_pos;
            }
            return current_node;
        }

    public:
        DynSlist() : num_items(0), current_pos(0), current_node(this){ } 

        T & operator [] (const size_t & i){
            throw(exception, out_of_range){
                return get_previous_to_pos(i)->get_next()->get_data();
            }    
        }

        size_t size() const { 
            return num_items; 
        }

        void insert(const int & pos, const T & data){
            throw(exception, bad_alloc, out_of_range){      
                typename Slist<T>::Node * node = new typename Slist<T>::Node (data);
                typename Slist<T>::Node * prev = get_previous_to_pos(pos); 
                prev->insert_next(node);
                ++num_items;
                }   
            }

        void remove(const int & pos){
            throw(exception, range_error){      
            typename Slist<T>::Node * prev = get_previous_to_pos(pos);
            typename Slist<T>::Node * node_to_delete = prev->remove_next();
            delete node_to_delete;
            --num_items;
            }
        }

        virtual ~DynSlist(){     
            while (not this->is_empty())
            delete this->remove_first(); 
        }

        class Iterator : public Slist<T>::Iterator{
    public:
        typedef Slist<T> Set_Type;
        typedef T Item_Type;
        Iterator(DynSlist & list) : Slist<T>::Iterator(list) { /* Empty */ } 

        T & get_current() { 
            return Slist<T>::Iterator::get_current()->get_data(); 
        }
  };

};

template <typename T> class Dnode; 
class Dlink{
    protected: 
        mutable Dlink * prev; 
        mutable Dlink * next;
    public:

        Dlink() : prev(this), next(this) {}

        Dlink(const Dlink & l) : { reset(); }

        Dlink & operator = (const Dlink & l) {
            reset();
            return *this;
        }   

        void reset(){
            next = prev = this;
        }

        bool is_empty() const { 
            return this == next and this == prev; 
        }

        bool is_unitarian() const { 
            return this != next and next == prev; 
        }

        bool is_unitarian_or_empty() const { 
            return next == prev; 
        }

        void insert(Dlink* node){
            node->prev = this;
            node->next = next;
            next->prev = node;
            next = node;
        }
        
        void append(Dlink* node){
            node->next = this;
            node->prev = prev;
            prev->next = node;
            prev = node;
        }

        Dlink *& get_next(){
            return next;
        }

        Dlink *& get_prev(){
            return prev;
        }

        void insert_list(Dlink * head){
            if (head->is_empty()){ 
                return;
            }

            head->prev->next = next;
            head->next->prev = this;
            next->prev       = head->prev;
            next             = head->next;
            head->reset();
        }
        
        void append_list(Dlink * head) {
            if (head->is_empty()){
                return;
            }

            head->next->prev = prev;
            head->prev->next = this;
            prev->next = head->next;
            prev = head->prev;
            head->reset();
  }

        void concat_list(Dlink * head) { 
            if (head->is_empty()){ 
                return;
            }

            if (this->is_empty()){
                swap(head);
                return;
            }

            prev->next = head->next;
            head->next->prev = prev;
            prev = head->prev;
            head->prev->next = this;
            head->reset();
        }

        size_t split_list(Dlink & l, Dlink & r){
    
            size_t count = 0;
            while (not is_empty()){
                l.append(remove_next()); ++count;

                if (is_empty())
                break;

                r.insert(remove_prev()); ++count;
            }

            return count;
        }

        void del() {
            prev->next = next;
            next->prev = prev;
            reset();
        }

        Dlink * remove_prev(){
            Dlink* retValue = prev;
            retValue->del();
            return retValue;
        }

        Dlink* remove_next(){
            Dlink * retValue = next;
            retValue->del();
            return retValue;
        }

        size_t revers_list(){
            if (is_empty()){
                return;
            }

            Dlink tmp;

            size_t counter = 0;
            for(; not is_empty; counter){
                tmp.insert(remove_next());
            }
            swap(&tmp);
            return counter;
        }

        void swap(Dlink * link)  {
            if (is_empty() and link->is_empty()){ 
                return
            ;}

            if (is_empty()){
                link->next->prev = this;
                link->prev->next = this;
                next = link->next;
                prev = link->prev;
                link->reset();
                return;
            }

            if (link->is_empty()){
                next->prev = link;
                prev->next = link;
                link->next = next;
                link->prev = prev;
                reset();
                return;
            }

            swap(prev->next, link->prev->next);
            swap(next->prev, link->next->prev);
            swap(prev, link->prev);
            swap(next, link->next);
        }

        void rotate_right(Dlink *list, size_t n){
            if(list->is_empty()){
                return;
            }

            Dlink *current = list->get_next();
            int size;

            while(current != list){
                size++;
                current = current->get_next();
            }

            Dlink *old_tail = current->prev;

            n = n % size;
            if(n == 0){return;}

            int newStar = size - n;
            current = list->get_next();

            for(int i=0; i < newStar; i++){
                current = current->get_next();
            }

            Dlink *new_head = current;
         

            old_tail->next = list->next;
            old_tail->next -> prev = old_tail;
            list -> next = new_head;
            list -> prev = new_head -> prev;
            list->prev->next = new_head;
            new_head-> prev -> next = list;
            new_head->prev = list->prev;
        }

        };



int main(){


    




};