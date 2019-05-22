#ifndef FIFO_H
#define FIFO_H

#include <algorithm>
#include <cassert>
#include <cstddef>
#include <iostream>
#include <iterator> 
#include <ostream>

/**
   Classe che implementa una FIFO di dati generici T.  
	@brief FIFO
	@param T Tipo del dato.
*/
template <typename T> class fifo {
  
   private:
      
      /**
		   Struttura di supporto interna che implementa un nodo della lista.
		   @brief Nodo della lista
	   */
      struct node {
         
         T value; ///< Dato inserito nella lista
         node *next; ///< Puntatore al nodo successivo della lista
         
         /**
			   Costruttore di default
		   */
         node() : value(), next(0) {}
         
         /**
			   Costruttore secondario che inizializza il nodo
			   @param v Valore del dato
			   @param n Puntatore al nodo successivo
		   */
         node(const T &v, node *n = 0) : value(v), next(n) {}
      };
      
      unsigned int _occupied; ///<  Numero elementi presenti nella FIFO
      node *_head; ///<  Puntatore al primo elemento inserito
      node *_tail; ///<  Puntatore all'ultimo elemento inserito
  		      
   // end private

   public:

      /**
         @brief Costruttore di default
	   */
      fifo(): _occupied(0), _head(0), _tail(0) {}

      /**
         @brief Costruttore di copia
		   @param other FIFO da copiare.
		   @throw Eccezione di allocazione di memoria.
	   */
      fifo( const fifo &other ) : _occupied(0), _head(0), _tail(0) {
         const node *tmp = other._head;		
		   try {
			   while (tmp!=0) {
				   insert(tmp->value);
				   tmp = tmp->next;
			   }
		   }
		   catch(...) {
			   clear();
			   throw;
		   }		
	   }

      /**
		   @brief Operatore di assegnamento
		   @param other FIFO da copiare.
		   @return Reference a this.
		   @throw Eccezione di allocazione di memoria.
	   */
      fifo& operator=( const fifo &other ) {
         if (this != &other) {
			   fifo tmp(other);
			   std::swap(tmp._occupied, _occupied);
				std::swap(tmp._head, _head);
				std::swap(tmp._tail, _tail);
		   }
		   return *this;
	   }

     	/**
		   @brief Inserisce un elemento nella FIFO
		   @param value Valore da inserire.
		   @throw Eccezione di allocazione di memoria.
	   */
      void insert( const T &value ) {	
			try {
            if (_occupied == 0) {
				   _head = new node(value, 0);
				   _tail = _head;
				   _occupied = 1;
			   }
            else {
               node *tmp = new node(value,0);
               _tail->next = tmp;
               _tail = tmp;
               _occupied++;
            }
         }
         catch(...) {
			   clear();
			   throw;
		   }         
      }
      
       /**
		   @brief Ritorna il numero di elementi presenti nella FIFO
		   @return Numero di elementi presenti nella FIFO.
	   */
      unsigned int countElements() const { 
         return _occupied;
      }

      /**
		   @brief Ritorna un puntatore al primo elemento inserito
		   @return Puntatore al primo elemento inserito.
	   */
      node* head() {
         if ( _occupied == 0 ) return 0;
         else return this->_head;
      }

		/**
		   @brief Ritorna un puntatore al primo elemento inserito
		   @return Puntatore al primo elemento inserito.
	   */
      const node* head() const {
         if ( _occupied == 0 ) return 0;
         else return this->_head;
      }

      /**
		   @brief Ritorna il valore del primo elemento inserito
		   @return Valore del primo elemento inserito.
	   */
      const T getHeadValue() const {
         if ( _occupied == 0 ) {
            std::cout << "FIFO Vuota ! Nessun Elemento Testa !" << std::endl;
         }
         assert ( _occupied != 0 );
         return head()->value;
      }

      /**
		   @brief Modifica il valore del primo elemento inserito
		   @param value Nuovo valore.
	   */
      void setHeadValue( const T &value ) {
         if ( _occupied == 0 ) {
            std::cout << "FIFO Vuota ! Nessun Elemento Testa !" << std::endl;
         }
         else head()->value = value;
      }

      /**
		   @brief Ritorna un puntatore all'ultimo elemento inserito
		   @return Puntatore all'ultimo elemento inserito.
	   */
      node* tail() {
         if ( _occupied == 0 ) return 0;
         else return this->_tail;
      }

		/**
		   @brief Ritorna un puntatore all'ultimo elemento inserito
		   @return Puntatore all'ultimo elemento inserito.
	   */
      const node* tail() const {
         if ( _occupied == 0 ) return 0;
         else return this->_tail;
      }     

      /**
		   @brief Ritorna il valore dell'ultimo elemento inserito
		   @return Valore dell'ultimo elemento inserito.
	   */
      const T getTailValue() const {
         if ( _occupied == 0 ) {
            std::cout << "FIFO Vuota ! Nessun Elemento Coda !" << std::endl;
         }
         assert ( _occupied != 0 );
         return tail()->value;
      }
     
      /**
		   @brief Modifica il valore dell'ultimo elemento inserito
		   @param value Nuovo valore.
	   */     
      void setTailValue( const T &value ) {
         if ( _occupied == 0 ) {
            std::cout << "FIFO Vuota ! Nessun Elemento Coda !" << std::endl;
         }
         else tail()->value = value;
      }

      /**
		   @brief Cerca un valore tra gli elementi inseriti nella FIFO
		   @param value Valore da cercare.
         @return True se l'elemento cercato viene trovato, False altrimenti.
	   */
      bool find( const T &value ) const {
         if ( _occupied == 0 ) {
             std::cout << "FIFO Vuota !" << std::endl;
             std::cout << "Elemento Non Trovato !" << std::endl;
             return false;
         }
         else {
            node *tmp = _head;
             while ( tmp != 0 ) {
               if ( tmp->value == value ) {
                  std::cout << "Elemento Trovato !" << std::endl;
                  return true;
               }
               tmp = tmp->next;
            }
            std::cout << "Elemento Non Trovato !" << std::endl;
            return false;
         }
      }

      /**
		   @brief Stampa a console l'intera FIFO
	   */
      void print() const {
         if ( _occupied == 0 ) {
            std::cout << "FIFO Vuota !" << std::endl;
         }
         else {
            std::cout << "Occupied : " << countElements() << std::endl;
            std::cout << "Head : " << getHeadValue() << std::endl;
            std::cout << "Tail : " << getTailValue() << std::endl;
            node *tmp = _head;
            while ( tmp != 0 ) {
               if ( tmp != _tail ) std::cout << tmp->value << " - ";
               else std::cout << tmp->value << " . " << std::endl;
               tmp = tmp->next;
            }
            std::cout << std::endl;
         }
      }
     
      /**
		   @brief Rimuove il primo elemento inserito
	   */
      void remove() {
         if ( _occupied == 0 )
            std::cout << "La FIFO e' gia vuota ! Non si possono togliere altri elementi !" << std::endl;
         else {
            node *tmp = _head->next;
            delete _head;
            _head = tmp;
            _occupied--; 
         }
      }

      /**
		   @brief Svuota completamente la FIFO
	   */
      void clear() {
			node *tmp = _head;
   		while (tmp!=0) {
		   	node *n = tmp->next;
		   	delete tmp;
		   	tmp = n;
	   	}
        	_occupied = 0;
	   	_head = 0;
        	_tail = 0;	
   	}

      /**
		   @brief Distruttore
	   */
      ~fifo() {
		   clear();
	   }
      
      class const_iterator;
      
	   /**
		   @brief Iteratore della FIFO
	   */
      class iterator {

         private:
            
            node *n;

            friend class fifo;

            iterator(node *nn) : n(nn) {}
			         
         // end iterator private
         
         public:

            typedef std::forward_iterator_tag iterator_category;
		      typedef T                         value_type;
		      typedef ptrdiff_t                 difference_type;
		      typedef T*                        pointer;
		      typedef T&                        reference;

            iterator() : n(0) {}
		
		      iterator(const iterator &other) : n(other.n) {}

		      iterator& operator=(const iterator &other) {
			      n = other.n;
			      return *this;
		      }

		      ~iterator() {
			      n = 0;
		      }

		      reference operator*() const {
               return n->value;
		      }

		      pointer operator->() const {
			      return &(n->value);
		      }

		      iterator operator++(int) {
			      iterator tmp(*this);
			      n = n->next;
			      return tmp;
		      }

		      iterator& operator++() {
			      n = n->next;
			      return *this;
		      }

            bool operator==(const iterator &other) const {
               return (n == other.n);
		      }

		      bool operator!=(const iterator &other) const {
               return n != other.n;
		      }

		      friend class const_iterator;

		      bool operator==(const const_iterator &other) const {
			      return (n == other.n);
		      }

   		   bool operator!=(const const_iterator &other) const {
	   		   return n != other.n;
	   	   }

         // end iterator public

      }; // end iterator

	/**
		@brief Ritorna l'iteratore all'inizio della sequenza
		@return Iteratore all'inizio della sequenza.
	*/
      iterator begin() {
		   return iterator(_head);
	   }
	
	/**
		@brief Ritorna l'iteratore alla fine della sequenza
		@return Iteratore alla fine della sequenza.
	*/
	   iterator end() {
		   return iterator(_tail);
	   }
      
      /**
		   @brief Iteratore costante della FIFO
	   */
      class const_iterator {
         
         private:
            
            node *n; 

            friend class fifo;

            const_iterator(node *nn) : n(nn) {} 
			         
         // end const_iterator private
         
         public:

		      typedef std::forward_iterator_tag iterator_category;
		      typedef T                         value_type;
		      typedef ptrdiff_t                 difference_type;
		      typedef const T*                  pointer;
		      typedef const T&                  reference;

		      const_iterator() : n(0) {}
		
		      const_iterator(const const_iterator &other) : n(other.n) {}
			
		      const_iterator& operator=(const const_iterator &other) {
			      n = other.n;
			      return *this;	
		      }

		      ~const_iterator() {
			      n = 0;
		      }
            
		      reference operator*() const {
			      return n->value;
		      }

		      pointer operator->() const {
			      return &(n->value);
		      }
		
   		   const_iterator operator++(int) {
	   		   const_iterator tmp(*this);
			      n = n->next;
			      return tmp;
		      }

		      const_iterator& operator++() {
			      n = n->next;
			      return *this;
		      }

		      bool operator==(const const_iterator &other) const {
			      return (n == other.n);
		      }
		
		      bool operator!=(const const_iterator &other) const {
               return n != other.n;
            }

		      friend class iterator;

            bool operator==(const iterator &other) const {
			      return (n == other.n);	
		      }

   		   bool operator!=(const iterator &other) const {
			      return n != other.n;
		      }

   		   const_iterator(const iterator &other) : n(other.n) {}

	         const_iterator &operator=(const iterator &other) {
			      n = other.n;
			      return *this;
		      }
                     
         //end const_iterator public
         
      }; // end const_iterator
      
      /**
		   @brief Ritorna l'iteratore costante all'inizio della sequenza
		   @return Iteratore costante all'inizio della sequenza.
	   */
	   const_iterator begin() const {
		   return const_iterator(_head);
	   }
	
   	/**
		   @brief Ritorna l'iteratore costante alla fine della sequenza
		   @return Iteratore costante alla fine della sequenza.
	   */
	   const_iterator end() const {
		   return const_iterator(_tail);
	   }

	   /**
		   Costruttore secondario che costruisce la FIFO a partire
		   da una sequenza generica di dati identificata da due iteratori.
         @brief Costruttore con iteratori
		   @param begin Iteratore di inizio della sequenza.
		   @param end Iteratore di fine della sequenza.
		   @throw Eccezione di allocazione di memoria.
	   */
      template <typename U> fifo(U begin, U end) : _occupied(0), _head(0), _tail(0) {
			try {
            while (begin != end) {
               insert(static_cast<T>(*begin));
               begin++;
            }
         }
  	      catch(...) {
			   clear();
			   throw;
		   }
		}

   // end fifo public
   
}; // end fifo

/**
	@brief Funzione transformif
	@param Q FIFO su cui operare.
	@param P Predicato da controllare.
	@param F Operazione da svolgere.
*/
template <typename T, typename U, typename V> void transformif(fifo<T> &Q, const U &P, const V &F) {	
   unsigned int i;
   typename fifo<T>::iterator I = Q.begin();
   for ( i = 0 ; i < Q.countElements() ; i++) {
      if ( P(*I) == true )
         *I = F(*I);
      I++;
   }
}

/**
	Ridefinizione dell'operatore di stream per la FIFO
	@param os Oggetto stream di output
	@param f FIFO da stampare
	@return Reference allo stream di output
*/
template <typename T> std::ostream& operator<<(std::ostream &os, const fifo<T> &f) {
   typename fifo<T>::const_iterator I = f.begin();
	typename fifo<T>::const_iterator F = f.end();
	unsigned int i;
   if ( f.countElements() == 0 ) {
   	std::cout << "FIFO Vuota !" << std::endl;
   }
   else {
   	os << "Occupied : " << f.countElements() << std::endl;
      os << "Head : " << f.getHeadValue() << std::endl;
      os << "Tail : " << f.getTailValue() << std::endl;
   	for (i = 0 ; i < f.countElements(); i++) {
         if ( I != F ) {
				os << *I << " - ";
				I++;
			} 
         else os << *I << " . " << std::endl;
      }
		os << std::endl;
   }
   return os;
}

#endif