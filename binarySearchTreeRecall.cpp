#include <iostream>

using namespace std;
//using default global array to check BST operations
//tedious to input values againa nd again
int arr[]={45,40,50,30,42,48,60};
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
void DeleteNode(node **rootNode, int data=0){
node *temp;
if(*rootNode!=NULL){
  temp=*rootNode;
if(temp->data>data){
  cout<<"goind left"<<endl;
  if(temp->left->data==data){
    cout<<"Data Found:"<<temp->left->data<<endl;
    temp->left=NULL;
    return;
  }
  DeleteNode(&temp->left,data);
}
else{
    cout<<"goind right"<<endl;
if(temp->right->data==data){
    cout<<"Data Found:"<<temp->right->data<<endl;
    temp->right=NULL;
    return;
  }
  DeleteNode(&temp->right,data);
}

}

}
int main() {
  struct node * rootNode = NULL;
  int choice, d;
  while (1) {
    system("cls");
    cout << "Enter choice" << endl;
    cout << "1.Insert Nodes& Branches" << endl;
    cout << "2.Traverse In PreOrder" << endl;
    cout << "3.Traverse In InOrder"<<endl;
    cout<<"4.Traverse in PostOrder"<<endl;
    cout<<"5.Delete A Node"<<endl;
    cin >> choice;
    switch (choice) {
    case 1: {
      //cout << "Enter Data" << endl;
      //cin >> d;
      int i=0;
      while(i!=7){
      if (rootNode == NULL) {
        rootNode = InsertNodes( & rootNode, arr[i]);
      } else {
        InsertNodes( & rootNode, arr[i]);
      }
      i++;
      }
     
      break;
    }
    case 2: {
      PrintDataPreOrder(&rootNode);
      system("pause");
      break;
    }
    case 3:{
      PrintDataInOrder(&rootNode);
       system("pause");
      break;
    }
    case 4:{
        PrintDataPostOrder(&rootNode);
         system("pause");
        break;
    }
    case 5:{
      cout<<"Enter Data To Be Deleted:";
      cin>>d;
      DeleteNode(&rootNode,d);
      system("pause");
        break;
    }
    }
  }
}