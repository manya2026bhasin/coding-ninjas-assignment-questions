/*
Code: Merge Sort
 Given a singly linked list of integers, sort it using 'Merge Sort.'
Note :
No need to print the list, it has already been taken care. Only return the new head to the list.
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first and the only line of each test case or query contains the elements of the singly linked list separated by a single space.
Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output format :
For each test case/query, print the elements of the sorted singly linked list.

Output for every test case will be printed in a seperate line.
Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.

Time Limit: 1sec
Sample Input 1 :
1
10 9 8 7 6 5 4 3 -1
Sample Output 1 :
 3 4 5 6 7 8 9 10 
 Sample Input 2 :
2
-1
10 -5 9 90 5 67 1 89 -1
Sample Output 2 :
-5 1 5 9 10 67 89 90 
  */



/****************************************************************
 
    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/
Node* findmid(Node* head){
	Node *slow = head, *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

Node* mergeSortedLL(Node* head1,Node* head2){
	if (head1 == NULL)
    {
        return head2;
    }
    else if (head2 == NULL)
    {
        return head1;
    }
 Node *fh = NULL, *ft = NULL;
	Node* h1=head1;
	Node* h2=head2;
	if(h1->data<h2->data){
		fh=h1;
		ft=h1;
		h1=h1->next;
	}
	else{
		fh=h2;
		ft=h2;
		h2=h2->next;
	}
	while(h1!=NULL&&h2!=NULL){
		if(h1->data>h2->data){
			ft->next=h2;
			ft=h2;
			h2=h2->next;
		}
		else{
			ft->next=h1;
			ft=h1;
			h1=h1->next;
		}
	}
	while(h1!=NULL){
		ft->next=h1;
		ft=h1;
		h1=h1->next;
	}
	while(h2!=NULL){
		ft->next=h2;
		ft=h2;
		h2=h2->next;
	}
	return fh;
}

Node *mergeSort(Node *head)
{
	//Write your code here
	if(head==NULL||head->next==NULL){
		 return head;
	}
	 Node *mid = findmid(head);
    Node *he1 = head;
    Node *he2 = mid->next;
    mid->next = NULL;
    he1 = mergeSort(he1);
    he2 = mergeSort(he2);
    Node *finalHead = mergeSortedLL(he1, he2);
    return finalHead;
}
