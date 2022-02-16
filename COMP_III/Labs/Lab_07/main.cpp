#undef debug

#include <iostream>
#include <string>
#include <list>
#include <map>
using namespace std;

template<typename T>
class BSTNode {
public:
  // Constructors, etc.
  BSTNode() : _data(0), _left(nullptr), _right(nullptr) {} // default constructor
  BSTNode(T data) : _left(nullptr), _right(nullptr) { _data = data; } // value constructor
  BSTNode(BSTNode&); // copy constructor
  ~BSTNode(); // destructor
  BSTNode& operator= (BSTNode&); // copy assignment operator
  
  // ***** Your group will define/implement the insert function
  // ***** at about line 89 below...
  void insert(const T& data);
  void listify(list<T>&) const;
  
  // Accessor and mutator functions
  BSTNode<T>* getLeft() const { return _left; }
  BSTNode<T>* getRight() const { return _right; }
  T& getData() const { return _data; }
  void setData(const T& data) { _data = data; }

  // Display functions used by operator<<.
  // ***** Your group will define/implement the pre & post display functions
  // ***** at about lines 114 & 127 below...
  void inOrderDisplay(ostream&) const;
  void preOrderDisplay(ostream&) const;
  void postOrderDisplay(ostream&) const;
  
  // The insertion operator below uses in-order display.
  // ***** Change the implementation of this insertion operator
  // ***** in order to switch to pre- or post-order display
  friend ostream& operator<< (ostream& out, const BSTNode<T>& b) {
    //b.preOrderDisplay(out); return out;
    //b.inOrderDisplay(out); return out;
    b.postOrderDisplay(out); return out;
  }
  
private:
  T _data;
  BSTNode<T>* _left;
  BSTNode<T>* _right;
  
  // private "helper" functions
  void addLeft(const T& data) { _left = new BSTNode(data); }
  void addRight(const T& data) { _right = new BSTNode(data); }
};

template<typename T>
BSTNode<T>::BSTNode(BSTNode& b) {
#ifdef debug
  cout << "BSTNode copy constructor called, _data == " << _data << endl;

#endif
  _data = b._data;
  _left = _right = nullptr;
  if (b._left != nullptr)
    _left = new BSTNode<T>(*b._left);

  if (b._right != nullptr)
    _right = new BSTNode<T>(*b._right);
}


template<typename T>
BSTNode<T>::~BSTNode() {
#ifdef debug
  cout << "BSTNode destructor called, _data == " << _data << endl;

#endif
  delete _left;
  delete _right;
}


template<typename T>
BSTNode<T>& BSTNode<T>::operator= (BSTNode& b) {
#ifdef debug
  cout << "BSTNode copy assignment operator: ";

#endif
  _data = b._data;
  _left = _right = nullptr;
  if (b._left != nullptr)
    _left = new BSTNode<T>(*b._left);

  if (b._right != nullptr)
    _right = new BSTNode<T>(*b._right);
  return *this;
}

template<typename T>
void BSTNode<T>::insert(const T& data) {
  // comment out the next line when you've completed this function!
  // cout << "BSTNode<T>::insert called with data == " << data << endl;
    if (this->_data > data){
        if (this->_left == nullptr){
            this->_left = new BSTNode(data);
        }
        else{
            this->_left->insert(data);
        }
    }
  
    if (this->_data < data){
        if (this->_right == nullptr){
            this->_right = new BSTNode(data);
        }
        else{
            this->_right->insert(data);
        }
    }
}

template<typename T>
void BSTNode<T>::listify(list<T>& Rodman) const {
  //perform an in-order traversal of the BST root, inserting the data of each BST node into the list rootList
  if (_left != nullptr) {
    _left->listify(Rodman);
  }
  Rodman.push_back(_data); //<--
  if (_right != nullptr) {
    _right->listify(Rodman);
  }
  return;
}

template<typename T>
void BSTNode<T>::inOrderDisplay(ostream& out) const {
  if (_left != nullptr) {
    _left->inOrderDisplay(out);
    out << ", ";
  }
  
  out << _data;
  
  if (_right != nullptr) {
    out << ", ";
    _right->inOrderDisplay(out);
  }
}

/**
 *  ***** Complete preOrderDisplay and postOrderDisplay below *****
 */
template<typename T>
void BSTNode<T>::preOrderDisplay(ostream& out) const {
  // comment out the next line when you've completed this function!
  // cout << "BSTNode<T>::preOrderDisplay called\n";
  out << _data;
  
  if (_left != nullptr) {
    out << ", ";
    _left->preOrderDisplay(out);
  }
  
  if (_right != nullptr) {
    out << ", ";
    _right->preOrderDisplay(out);
  }
}

template<typename T>
void BSTNode<T>::postOrderDisplay(ostream& out) const {
  // comment out the next line when you've completed this function!
  // cout << "BSTNode<T>::postOrderDisplay called\n";
  if (_left != nullptr) {
    _left->postOrderDisplay(out);
    out << ", ";
  }
  
  if (_right != nullptr) {
    _right->postOrderDisplay(out);
    out << ", ";
  }
  out << _data;
}

int main(void) {
  BSTNode<int> iroot(300);
  iroot.insert(200);
  iroot.insert(100);
  iroot.insert(20);
  iroot.insert(10);
  cout << "iroot == " << iroot << endl;
  
  BSTNode<string> sroot("Wednesday");
  sroot.insert("Tuesday");
  sroot.insert("Thursday");
  sroot.insert("Sunday");
  sroot.insert("Saturday");
  sroot.insert("Monday");
  sroot.insert("Friday");
  cout << "sroot == " << sroot << endl;


  list<int> irootList;
  list<int>::iterator ii;
  iroot.listify(irootList);
    cout << endl << "Creating irootList via iroot.listify" << endl;
  cout << endl << "irootList (forward Iterator) == ";
  for (ii = irootList.begin(); ii != irootList.end(); ++ii) {
    // Accessing values at locations pointed by iterator
    cout << (*ii) << " ";
  }
  
  
  list<int>::reverse_iterator rii;
  
  cout << endl << "irootList (reverse Iterator) == ";
  for (rii = irootList.rbegin(); rii != irootList.rend(); ++rii) {
    // Accessing values at locations pointed by iterator
    cout << (*rii) << " ";
  }
  
  
  cout << endl << "irootList (ranged for loop) == ";
  for (int _data : irootList) {
    cout << _data << " ";
  }
  cout << endl << endl;

  list<string> srootList;
  list<string>::iterator si;
  sroot.listify(srootList);
    cout << "Creating srootList via sroot.listify" << endl;
    
  cout << endl << "srootList (forward iterator) == ";
  for (si = srootList.begin(); si != srootList.end(); ++si) {
    // Accessing values at locations pointed by iterator
    cout << (*si) << " ";
  }
  
  list<string>::reverse_iterator rsi;
  
  cout << endl << "srootList (reverse iterator) == ";
  for (rsi = srootList.rbegin(); rsi != srootList.rend(); ++rsi) {
    // Accessing values at locations pointed by iterator
    cout << (*rsi) << " ";
  }
  
  cout << endl << "srootList (ranged for loop) == ";
  for (string _data : srootList) {
    cout << _data << " ";
  }
  
  BSTNode<int> iroot4(1000);
  
  iroot4.insert(2000);
  iroot4.insert(3000);
  iroot4.insert(4000);
  iroot4.insert(5000);
  
  list<int> iroot4List;
  iroot4.listify(iroot4List);
  
    cout << endl << endl << "iroot4 == ";
  for (ii = iroot4List.begin(); ii != iroot4List.end(); ++ii) {
    // Accessing values at locations pointed by iterator
    cout << (*ii) << ", ";
  }
  cout << endl << endl;
    
    
  cout << "Creating iroot4List via iroot4.listify" << endl;
  map<string, list<int>> mi;
  
  mi.emplace("iroot4List", iroot4List);
  mi.emplace("irootList", irootList);
  
  cout << endl << "Contents of map<string, list<int>> mi (using ranged for loops):  " << endl << "iroot4List: ";
  for (int _data : mi.at("iroot4List")) {
    cout << _data << " ";
  }
  
  cout << endl << "irootList: ";
  for (int _data : mi.at("irootList")) {
    cout << _data << " ";
  }
  cout << endl << endl;
  
  cout << "Using map index operator: " << endl;
  cout << "mi[\"irootList\"] == ";
  for (auto i : mi["irootList"]) {
    cout << i << " ";
  }
  cout << endl;
  
  cout << "mi[\"iroot4List\"] == ";
  for (auto i : mi["iroot4List"]) {
    cout << i << " ";
  }
  cout << endl;
  

#ifdef debug
  BSTNode<int> iroot2(iroot); // use copy constructor
  cout << "\nAfter copy constructor:\n";
  cout << "iroot2 == " << iroot2 << endl;
  
  BSTNode<int> iroot3;
  iroot3 = iroot2; // use copy assignment operator
  cout << "\nAfter copy assignment operator:\n";
  cout << "iroot3 == " << iroot3 << endl << endl;

#endif
  return 0;
}
