//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

// Function to find the data of kth node from the end of a linked list.
class Solution {
  public:
    int getKthFromLast(Node *head, int k) {
        // Your code here
        Node *temp = head;
        Node *head1 = NULL;
        while(temp!=NULL){
            Node *node = new Node(temp->data);
            if(head1==NULL){
                head1=node;
            }
            else{
                node->next = head1;
                head1=node;
            }
            temp = temp->next;
        }
        temp = NULL;
        int count=0;
        temp = head1;
        int p=-1;
        while(temp!=NULL){
            count++;
            if(count==k){
                p = temp->data;
                break;
            }
            temp = temp->next;
        }
        return p;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }

        int x;
        cin >> x;
        cin.ignore();

        Node* head = nullptr;

        // Check if the array is empty
        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node* tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }

        Solution ob;
        cout << ob.getKthFromLast(head, x) << endl;
    }
    return 0;
}
// } Driver Code Ends
