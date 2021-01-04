//Note: this is my solution to the isListPalindrome
// problem on codesignal 


//solution to exercise # 27

 template<typename T>
 struct ListNode {
   ListNode(const T &v) : value(v), next(nullptr) {}
   T value;
   ListNode *next;
 };

bool isListPalindrome(ListNode<int> * l) {
    ListNode<int>* temp= l; 
    std::stack <int> s; 
    //push all elements of the linkedlist onto the stack  
    while(temp != NULL) { 
        s.push(temp->value);  
        temp = temp->next; 
    } 
    //traverse linkedlist and pop off the stack
    while(l != NULL ) {  
        //get top of stack  
        int i=s.top(); 
        //pop off stack  
        s.pop(); 
        //if not matching, then it's not a palindrome
        if(l -> value != i) { 
            return false; 
        } 
        //move to next element in linkedlist  
        l=l->next; 
    } 
    return true; 
}
