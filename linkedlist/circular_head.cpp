// circular linked list
class circule_head
{
public:
    int data;
    circule_head *next;
    circule_head(int val)
    {
        this->data = val;
    }
    circule_head(int val, circule_head *next)
    {
        this->data = val;
        this->next = next;
    }
};
class CircularHeadLL
{
private:
    int counter = 0;
    circule_head *root;
    bool flag = true;

public:
    CircularHeadLL(circule_head *node)
    {
        this->root = node;
        this->counter += 1;
    }
    void insertion_at_start(int val)
    {
    }
    void insertion_at_end(int val)
    {
    }
    void insertion_at_index(int val, int index) {}
    int delete_at_start() {}
    int delete_at_end() {}
    int delete_at_index(int index) {}
    int getCount() { return this->counter; }
    bool search(int target) {}
    void sort() {};
};
