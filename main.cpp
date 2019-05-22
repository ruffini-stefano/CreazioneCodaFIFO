#include "fifo.h"
#include <iostream>

void test1() { // Creazione - Inserimento - Stampa - Rimozione - Stampa
  
  std::cout << "@@@ Test 1 ! @@@" << std::endl;   
  
  std::cout << "FIFO Con Int :" << std::endl;
  fifo<int> f1;
  f1.insert(1);
  f1.insert(2);
  f1.insert(3);
  f1.print(); 
  f1.remove();
  f1.print();

  std::cout << "FIFO Con Double :" << std::endl;
  fifo<double> f2;
  f2.insert(1.1);
  f2.insert(2.2);
  f2.insert(3.3);
  f2.print(); 
  f2.remove();
  f2.print();

  std::cout << "FIFO Con String :" << std::endl;
  fifo<std::string> f3;
  f3.insert("A");
  f3.insert("B");
  f3.insert("C");
  f3.print(); 
  f3.remove();
  std::cout << f3;

}

void test2() { // Creazione - Inserimento - Stampa - Rimozione Totale - Stampa

  std::cout << "@@@ Test 2 ! @@@" << std::endl;   
  
  std::cout << "FIFO Con Int :" << std::endl;
  fifo<int> f1;
  f1.insert(1);
  f1.insert(2);
  f1.insert(3);
  f1.print(); 
  f1.remove();
  f1.remove();
  f1.remove();
  f1.print();

  std::cout << "FIFO Con Double :" << std::endl;
  fifo<double> f2;
  f2.insert(1.1);
  f2.insert(2.2);
  f2.insert(3.3);
  f2.print(); 
  f2.remove();
  f2.remove();
  f2.remove();
  f2.print();

  std::cout << "FIFO Con String :" << std::endl;
  fifo<std::string> f3;
  f3.insert("A");
  f3.insert("B");
  f3.insert("C");
  f3.print(); 
  f3.remove();
  f3.remove();
  f3.remove();
  f3.print();

}

void test3() { // Creazione - Inserimento - Stampa - Troppa Rimozione - Stampa
  
  std::cout << "@@@ Test 3 ! @@@" << std::endl;   
  
  std::cout << "FIFO Con Int :" << std::endl;
  fifo<int> f1;
  f1.insert(1);
  f1.insert(2);
  f1.insert(3);
  f1.remove();
  f1.remove();
  f1.remove();
  f1.remove();
  f1.print();

  std::cout << "FIFO Con Double :" << std::endl;
  fifo<double> f2;
  f2.insert(1.1);
  f2.insert(2.2);
  f2.insert(3.3);
  f2.remove();
  f2.remove();
  f2.remove();
  f2.remove();
  f2.print();

  std::cout << "FIFO Con String :" << std::endl;
  fifo<std::string> f3;
  f3.insert("A");
  f3.insert("B");
  f3.insert("C");
  f3.remove();
  f3.remove();
  f3.remove();
  f3.remove();
  f3.print();

}

void testCopia() { // Costruttore Copia
  
  std::cout << "@@@ Test Copia ! @@@" << std::endl;   
  
  std::cout << "FIFO Con Int :" << std::endl;
  fifo<int> f1;
  f1.insert(1);
  f1.insert(2);
  f1.insert(3);
  f1.insert(4);
  f1.insert(5);
  f1.remove();
  std::cout << "F1 - Creato Normalmente :" << std::endl;
  f1.print();
  fifo<int> f2(f1);
  std::cout << "F2 - Creato Copiando F1 :" << std::endl;
  f2.print();

  std::cout << "FIFO Con Double :" << std::endl;
  fifo<double> f3;
  f3.insert(1.1);
  f3.insert(2.2);
  f3.insert(3.3);
  f3.insert(4.4);
  f3.insert(5.5);
  f3.remove();
  std::cout << "F3 - Creato Normalmente :" << std::endl;
  f3.print();
  fifo<double> f4(f3);
  std::cout << "F4 - Creato Copiando F3 :" << std::endl;
  f4.print();

   std::cout << "FIFO Con String :" << std::endl;
  fifo<std::string> f5;
  f5.insert("A");
  f5.insert("B");
  f5.insert("C");
  f5.insert("D");
  f5.insert("E");
  f5.remove();
  std::cout << "F5 - Creato Normalmente :" << std::endl;
  f5.print();
  fifo<std::string> f6(f5);
  std::cout << "F6 - Creato Copiando F5 :" << std::endl;
  f6.print();

}

void testOperatore() { // Operatore Assegnamento

  std::cout << "@@@ Test Operatore ! @@@" << std::endl;   
  
  std::cout << "FIFO Con Int :" << std::endl;
  fifo<int> f1;
  f1.insert(1);
  f1.insert(2);
  f1.insert(3);
  f1.insert(4);
  f1.insert(5);
  f1.remove();
  std::cout << "F1 - Creato Normalmente :" << std::endl;
  f1.print();
  fifo<int> f2;
  f2 = f1;
  std::cout << "F2 - Creato Da F1 :" << std::endl;
  f2.print();

  std::cout << "FIFO Con Double :" << std::endl;
  fifo<double> f3;
  f3.insert(1.1);
  f3.insert(2.2);
  f3.insert(3.3);
  f3.insert(4.4);
  f3.insert(5.5);
  f3.remove();
  std::cout << "F3 - Creato Normalmente :" << std::endl;
  f3.print();
  fifo<double> f4;
  f4 = f3;
  std::cout << "F4 - Creato Da F3 :" << std::endl;
  f4.print();

  std::cout << "FIFO Con String :" << std::endl;
  fifo<std::string> f5;
  f5.insert("A");
  f5.insert("B");
  f5.insert("C");
  f5.insert("D");
  f5.insert("E");
  f5.remove();
  std::cout << "F5 - Creato Normalmente :" << std::endl;
  f5.print();
  fifo<std::string> f6;
  f6 = f5;
  std::cout << "F6 - Creato Da F5 :" << std::endl;
  f6.print();
}

void testLettura() { // Accesso in lettura della testa e della coda
  
  std::cout << "@@@ Test Lettura ! @@@" << std::endl;   
  
  std::cout << "FIFO Con Int :" << std::endl;
  fifo<int> f1;
  f1.insert(1);
  f1.insert(2);
  f1.insert(3);
  f1.insert(4);
  f1.insert(5);
  std::cout << f1.getHeadValue() << std::endl ;
  std::cout << f1.getTailValue() << std::endl ;
  f1.remove();
  f1.remove();
  f1.remove();
  f1.remove();
  f1.remove();  
  
  std::cout << "FIFO Con Double :" << std::endl;
  fifo<double> f2;
  f2.insert(1.1);
  f2.insert(2.2);
  f2.insert(3.3);
  f2.insert(4.4);
  f2.insert(5.5);
  std::cout << f2.getHeadValue() << std::endl ;
  std::cout << f2.getTailValue() << std::endl ;
  f2.remove();
  f2.remove();
  f2.remove();
  f2.remove();
  f2.remove();  
  
  std::cout << "FIFO Con String :" << std::endl;
  fifo<std::string> f3;
  f3.insert("A");
  f3.insert("B");
  f3.insert("C");
  f3.insert("D");
  f3.insert("EEEEEE");
  std::cout << f3.getHeadValue() << std::endl ;
  std::cout << f3.getTailValue() << std::endl ;
  f3.remove();
  f3.remove();
  f3.remove();
  f3.remove();
  f3.remove();  
  
}

void testScrittura() { // Accesso in scrittura della testa e della coda
  
  std::cout << "@@@ Test Scrittura ! @@@" << std::endl;   
  
  std::cout << "FIFO Con Int :" << std::endl;
  fifo<int> f1;
  f1.insert(1);
  f1.insert(2);
  f1.insert(3);
  f1.insert(4);
  f1.insert(5);
  f1.setHeadValue(100);
  f1.setTailValue(100);
  f1.print();
  
  std::cout << "FIFO Con Double :" << std::endl;
  fifo<double> f2;
  f2.insert(1.1);
  f2.insert(2.2);
  f2.insert(3.3);
  f2.insert(4.4);
  f2.insert(5.5);
  f2.setHeadValue(100.100);
  f2.setTailValue(100.100);
  f2.print();

  std::cout << "FIFO Con String :" << std::endl;
  fifo<std::string> f3;
  f3.insert("A");
  f3.insert("B");
  f3.insert("C");
  f3.insert("D");
  f3.insert("E");
  f3.setHeadValue("Z");
  f3.setTailValue("Z");
  f3.print();

}

void testFind1() { // Elemento trovato

  std::cout << "@@@ Test Find1 ! @@@" << std::endl;   
  
  std::cout << "FIFO Con Int :" << std::endl;
  fifo<int> f1;
  f1.insert(1);
  f1.insert(2);
  f1.insert(3);
  f1.insert(1);
  std::cout << f1.find(1) << std::endl;

  std::cout << "FIFO Con Double :" << std::endl;
  fifo<double> f2;
  f2.insert(1.1);
  f2.insert(2.2);
  f2.insert(3.3);
  f2.insert(1.1);
  std::cout << f2.find(1.1) << std::endl;

  std::cout << "FIFO Con String :" << std::endl;
  fifo<std::string> f3;
  f3.insert("A");
  f3.insert("B");
  f3.insert("C");
  f3.insert("D");
  std::cout << f3.find("B") << std::endl;

}

void testFind2() { // Elemento non trovato

  std::cout << "@@@ Test Find2 ! @@@" << std::endl;   
  
  std::cout << "FIFO Con Int :" << std::endl;
  fifo<int> f1;
  f1.insert(1);
  f1.insert(2);
  f1.insert(3);
  f1.insert(1);
  std::cout << f1.find(10) << std::endl;

  std::cout << "FIFO Con Double :" << std::endl;
  fifo<double> f2;
  f2.insert(1.1);
  f2.insert(2.2);
  f2.insert(3.3);
  f2.insert(1.1);
  std::cout << f2.find(10.10) << std::endl;

  std::cout << "FIFO Con String :" << std::endl;
  fifo<std::string> f3;
  f3.insert("A");
  f3.insert("B");
  f3.insert("C");
  f3.insert("D");
  std::cout << f3.find("Z") << std::endl;

}

void testFind3() { // Elemento non trovato con coda vuota

  std::cout << "@@@ Test Find3 ! @@@" << std::endl;   
  
  std::cout << "FIFO Con Int :" << std::endl;
  fifo<int> f1;
  std::cout << f1.find(1) << std::endl;

  std::cout << "FIFO Con Double :" << std::endl;
  fifo<double> f2;
  std::cout << f2.find(1.1) << std::endl;

  std::cout << "FIFO Con String :" << std::endl;
  fifo<std::string> f3;
  std::cout << f3.find("A") << std::endl;

}

void testClear1() { // Rimuovere tutti gli elementi
  
  std::cout << "@@@ Test Clear1 ! @@@" << std::endl;   
  
  std::cout << "FIFO Con Int :" << std::endl;
  fifo<int> f1;
  f1.insert(1);
  f1.insert(2);
  f1.insert(3);
  f1.insert(1);
  f1.insert(7);
  f1.print();
  f1.clear();
  f1.print();

  std::cout << "FIFO Con Double :" << std::endl;
  fifo<double> f2;
  f2.insert(1.1);
  f2.insert(2.2);
  f2.insert(3.3);
  f2.insert(1.1);
  f2.insert(7.7);
  f2.print();
  f2.clear();
  f2.print();

  std::cout << "FIFO Con String :" << std::endl;
  fifo<std::string> f3;
  f3.insert("A");
  f3.insert("B");
  f3.insert("C");
  f3.insert("D");
  f3.insert("E");
  f3.print();
  f3.clear();
  f3.print();

}

void testClear2() { // Rimuovere tutti gli elementi con coda vuota
  
  std::cout << "@@@ Test Clear2 ! @@@" << std::endl;   
  
  std::cout << "FIFO Con Int :" << std::endl;
  fifo<int> f1;
  f1.clear();
  f1.print();

  std::cout << "FIFO Con Double :" << std::endl;
  fifo<double> f2;
  f2.clear();
  f2.print();

  std::cout << "FIFO Con String :" << std::endl;
  fifo<std::string> f3;
  f3.clear();
  f3.print();

}

void testClear3() { // Rimuovere tutti gli elementi con coda vuota avendola svuotata
  
  std::cout << "@@@ Test Clear3 ! @@@" << std::endl;   
  
  std::cout << "FIFO Con Int :" << std::endl;
  fifo<int> f1;
  f1.insert(1);
  f1.remove();
  f1.clear();
  f1.print();

  std::cout << "FIFO Con Double :" << std::endl;
  fifo<double> f2;
  f2.insert(1.1);
  f2.remove();
  f2.clear();
  f2.print();

  std::cout << "FIFO Con String :" << std::endl;
  fifo<std::string> f3;
  f3.insert("A");
  f3.remove();
  f3.clear();
  f3.print();

}


struct persona { // Tipo Custom
  std::string nome; 
  std::string cognome; 
  int eta; 
  persona() {}
  persona(std::string n, std::string c, int e) : nome(n), cognome(c), eta(e) {} 
};

std::ostream &operator<<(std::ostream &os, const persona &v) { // Stampa Tipo Custom
  os << v.nome << " " << v.cognome << " " << v.eta;
	return os;
}

bool operator==(const persona &X, const persona &Y) { // Operatore Confronto Tipo Custom ( Per Find )
  if ( 
        ( X.nome == Y.nome ) &&
        ( X.cognome == Y.cognome ) &&
        ( X.eta == Y.eta )
    ) return true;
  else return false;
}

void testPersona() { // Test su tipo custom

  std::cout << "@@@ Test Persona ! @@@" << std::endl;   
  
  fifo<persona> f1;
  f1.insert(persona("Pinco","Pallo",50));
  f1.insert(persona("Pongo","Pallino",27));
  f1.insert(persona("Hey","Ciao",17));
  std::cout << "F1 Creato Normalmente : " << std::endl;
  f1.print();
  std::cout << "F2 Creato Copiando F1 : " << std::endl;
  fifo<persona> f2(f1);
  f2.print();
  std::cout << "F Creato Assegnando F2 : " << std::endl;
  fifo<persona> f3;
  f3 = f2;
  f3.print();
  std::cout << f1.find(persona("Pinco","Pallino",23)) << std::endl;
  f1.setHeadValue(persona("Pinco","Pallino",23));
  f1.print();
  std::cout << f1;
  std::cout << f1.find(persona("Pinco","Pallino",23)) << std::endl;
  f1.remove();
  f1.print();
  f1.clear();
  f1.print();
  std::cout << f1;

}

void testIteratori() { // Iteratori

  std::cout << "@@@ Test Iteratori ! @@@" << std::endl;

  std::cout << "FIFO Con Int" << std::endl;

  int a[5] = {7, 9, 12, 2, 1};
	
	fifo<int> f(a,a+5);
  f.print();

  fifo<int>::iterator i1,i2;

  i1 = f.begin(); 
  i2 = f.end();
  fifo<int>::iterator i3(i2);

  std::cout << "HEAD : " << *i1 << std::endl;
  std::cout << "HEAD + 1 : " << *(i1++)  << std::endl;
  std::cout << "HEAD + 1 : " << *(++i1)  << std::endl;
  std::cout << ( i1 == i2 ) << std::endl;
  std::cout << ( i1 != i2 ) << std::endl;

  int i = 0;
  for(i1=f.begin(),i2=f.end(),i=0; i<f.countElements(); i1++,i++) {
    std::cout << "CICLO AL GIRO : " << i << "!" << std::endl;
    std::cout << ( i1 != i2 ) << std::endl;
    std::cout << "BEGIN  = " << *i1 << std::endl;
    std::cout << "END = " << *i2 << std::endl;
  }

  std::cout << "FIFO Con String : " << std::endl;

  std::string b[5] = {"A", "B", "C", "DDD", "E"};
	
	fifo<std::string> e(b,b+5);
  e.print();

  fifo<std::string>::const_iterator i4,i5;

  i4 = e.begin(); 
  i5 = e.end();
  fifo<std::string>::const_iterator i6(i5);

  std::cout << "HEAD : " << *i4 << std::endl;
  std::cout << "HEAD + 1 : " << *(i4++)  << std::endl;
  std::cout << "HEAD + 1 : " << *(++i4)  << std::endl;
  std::cout << ( i4 == i5 ) << std::endl;
  std::cout << ( i4 != i5 ) << std::endl;

  for(i4=e.begin(),i5=e.end(),i=0; i<e.countElements(); i4++,i++) {
    std::cout << "CICLO AL GIRO : " << i << "!" << std::endl;
    std::cout << ( i4 != i5 ) << std::endl;
    std::cout << "BEGIN  = " << *i4 << std::endl;
    std::cout << "END = " << *i5 << std::endl;
  }
  
}

struct less_zero {
	bool operator()(const int &n) const {
		return n < 0;
	}
};

struct opposto {
  int operator()( const int &n ) const {
    return -n;
  }
};

void testFunzione() {

  std::cout << "@@@ Test Funzione ! @@@" << std::endl;
  fifo<int> f;
  f.insert(-5);
  f.insert(-3);
  f.insert(0);
  f.insert(3);
  f.insert(7);
  f.print();

  less_zero P;
  opposto O;

  transformif(f,P,O);

  f.print();

}

void testStampa() {

  std::cout << "@@@ Test Stampa ! @@@" << std::endl;

  std::cout << "FIFO Con Int : " << std::endl;
  fifo<int> f1;
  f1.insert(1);
  f1.insert(2);
  f1.insert(3);
  f1.insert(4);
  f1.insert(5);
  f1.print();
  std::cout << f1 << std::endl;

  std::cout << "FIFO Con String : " << std::endl;
  fifo<std::string> f2;
  f2.insert("A");
  f2.insert("B");
  f2.insert("C");
  f2.insert("D");
  f2.insert("E");
  f2.print();
  std::cout << f2 << std::endl;
}


int main() {
  test1();
  test2();
  test3();
  testCopia();
  testOperatore();
  testLettura();
  testScrittura();
  testFind1();
  testFind2();
  testFind3();
  testClear1();
  testClear2();
  testClear3();
  testPersona();
  testIteratori();
  testFunzione();
  testStampa();
  return 0;
}