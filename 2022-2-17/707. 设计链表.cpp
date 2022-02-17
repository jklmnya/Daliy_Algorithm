class MyLinkedList {

    struct Node {
        int val;
        Node next;
        Node()  val(0), next(nullptr) {};
        Node(int v)  val(v), next(nullptr) {}; 
    };

    Node head;
    Node tail;
    int len;

public
    MyLinkedList()  len(0) {
        head = new Node();
        tail = head;
    }
    
    int get(int index) {
        if (index  0  index = len)
            return -1;
        Node node = head-next;
        while (index--)
            node = node-next;
        return node-val;
    }
    
    void addAtHead(int val) {
        ++len;
        Node node = new Node(val);
        node-next = head-next;
        head-next = node;
        if (head == tail)
            tail = node;
    }
    
    void addAtTail(int val) {
        ++len;
        Node node = new Node(val);
        if (head == tail)
            head-next = node;
        else 
            tail-next = node;
        tail = tail-next;
    }
    
    void addAtIndex(int index, int val) {
        if (index  len)
            return;
        if (index == len) {
            addAtTail(val);
        } else if (index = 0) {
            Node node = head;
            while (--index = 0)
                node = node-next;
            Node temp = new Node(val);
            temp-next = node-next;
            node-next = temp;
            ++len;
        } else {
            addAtHead(val);
        }
    }
    
    void deleteAtIndex(int index) {
        if (index = 0 && index  len) {
            Node node = head;
            bool f = index == len - 1;
            while (index--)
                node = node-next;
            Node temp = node-next;
            node-next = node-next-next;
            if (f)
                tail = node;
            delete temp;
            temp = nullptr;
            --len;
        }
    }
};


  Your MyLinkedList object will be instantiated and called as such
  MyLinkedList obj = new MyLinkedList();
  int param_1 = obj-get(index);
  obj-addAtHead(val);
  obj-addAtTail(val);
  obj-addAtIndex(index,val);
  obj-deleteAtIndex(index);
 