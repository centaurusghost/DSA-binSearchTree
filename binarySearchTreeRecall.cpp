#include <iostream>

using namespace std;

struct node {
  node * left;
  int data;
  node * right;
};
node * CreateNode() {
  node * temp;
  temp = new node;
  if (temp) {
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
  }
}
node * InsertNodes(node ** rootNode, int data = 0) {
  node * temp1, * temp2;
  if ( * rootNode != NULL) {
    temp2 = * rootNode;
    if (temp2 -> data < data) {
      InsertNodes( & temp2 -> right, data);
    } else {
      InsertNodes( & temp2 -> left, data);
    }
  } else {
    temp1 = CreateNode();
    cout << "hello " << temp1 << endl;
    * rootNode = temp1;
    temp1 -> data = data;
    //system("pause");
  }
}
void PrintDataPreOrder(node **rootNode) {
  node * temp;
  temp = *rootNode;
  if (*rootNode != NULL) {
    cout << temp -> data << " ";
    PrintDataPreOrder(&temp->left);
    PrintDataPreOrder(&temp->right);
  } else {
    // cout<<"Node is Empty"<<endl;
    return;
  }
}
void PrintDataPostOrder(node **rootNode) {
  node * temp;
  temp = *rootNode;
  if (*rootNode != NULL) {
    PrintDataPreOrder(&temp->left);
    PrintDataPreOrder(&temp->right);
    cout << temp -> data << " ";
  } else {
    // cout<<"Node is Empty"<<endl;
    return;
  }
}
void PrintDataInOrder(node **rootNode) {
  node * temp;
  temp = *rootNode;
  if (*rootNode != NULL) {
    PrintDataPreOrder(&temp->left);
    cout << temp -> data << " ";
    PrintDataPreOrder(&temp->right);
  } else {
    // cout<<"Node is Empty"<<endl;
    return;
  }
}
int main() {
  struct node * rootNode = NULL;
  int choice, d;
  while (1) {
    system("cls");
    cout << "Enter choice" << endl;
    cout << "1.Insert Nodes& Branches" << endl;
    cout << "2.Print data" << endl;
    cin >> choice;
    switch (choice) {
    case 1: {
      cout << "Enter Data" << endl;
      cin >> d;
      if (rootNode == NULL) {
        rootNode = InsertNodes( & rootNode, d);
      } else {
        InsertNodes( & rootNode, d);
      }
      break;
    }
    case 2: {
      PrintDataPreOrder(&rootNode);
      system("pause");
    }
    }
  }
}