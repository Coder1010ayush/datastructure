#include <iostream>
#include <string.h>

class singleHead
{
public:
    int data;
    singleHead *next;
    singleHead() { this->data = 0; }
    singleHead(int val) { this->data = val; }
    singleHead(int val, singleHead *node)
    {
        this->data = val;
        this->next = node;
    }
};

class SingleLinkedList
{
private:
    singleHead *root;
    int counter = 0;
    bool flag = true;

public:
    SingleLinkedList(singleHead *node)
    {
        this->root = node;
        this->counter = 1;
    }
    void insertion_at_end(int val)
    {
        singleHead *tmp = root;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        singleHead *new_node = new singleHead(val);
        tmp->next = (new_node);
        this->counter += 1;
    }
    void insertion_at_start(int val)
    {
        singleHead *new_node = new singleHead(val);
        singleHead *tmp = root;
        new_node->next = root;
        root = new_node;
        this->counter += 1;
    }
    void insert_at_index(int val, int index)
    {
        if (index < 0 || index > this->counter)
            return;
        if (index == 0)
        {
            insertion_at_start(val);
        }
        else if (index == this->counter)
        {
            insertion_at_end(val);
        }
        else
        {
            int cnt = -1;
            singleHead *tmp = root;
            while (tmp != NULL)
            {
                if (cnt == index - 2)
                {
                    break;
                }
                cnt += 1;
                tmp = tmp->next;
            }
            singleHead *new_node = new singleHead(val);
            new_node->next = tmp->next;
            tmp->next = new_node;
            this->counter += 1;
        }
    }
    int delete_last()
    {
        singleHead *tmp = root;
        while (tmp->next->next != NULL)
        {
            tmp = tmp->next;
        }
        int val = tmp->next->data;
        tmp->next = nullptr;
        this->counter -= 1;
        return val;
    }
    int delete_first()
    {
        int val = root->data;
        root = root->next;
        this->counter -= 1;
        return val;
    }
    int delete_at_index(int index)
    {
        if (index == 0)
        {
            return delete_first();
        }
        else if (index == this->counter)
        {
            return delete_last();
        }
        else
        {
            int val;
            int cnt = 0;
            singleHead *tmp = root;
            while (tmp != NULL)
            {
                if (cnt == index - 1)
                    break;
                cnt += 1;
                tmp = tmp->next;
            }
            val = tmp->next->data;
            tmp->next = tmp->next->next;
            this->counter -= 1;
            return val;
        }
    }
    int getCount()
    {
        return this->counter;
    }
    void display()
    {
        singleHead *tmp = root;
        while (tmp != NULL)
        {
            std::cout << tmp->data << " << ";
            tmp = tmp->next;
        }
        std::cout << "end" << std::endl;
    }
    void display_helper(singleHead *tmp)
    {
        if (tmp == NULL)

        {
            return;
        }
        if (tmp != NULL)
        {
            display_helper(tmp->next);
            std::cout << tmp->data << " << ";
        }
    }
    void reverse_display()
    {
        singleHead *tmp = root;
        display_helper(tmp);
        std::cout << "end" << std::endl;
    }
    bool search(int target)
    {
        singleHead *tmp = root;
        while (tmp != NULL)
        {
            if (tmp->data == target)
                return true;
            tmp = tmp->next;
        }
        return false;
    }
    bool iterate(singleHead *node)
    {
        bool flag = false;
        singleHead *tmp = node;
        while (tmp != NULL)
        {
            if (tmp->next != NULL)
            {
                if (tmp->data > tmp->next->data)
                {
                    int loc = tmp->data;
                    tmp->data = tmp->next->data;
                    tmp->next->data = loc;
                    flag = true;
                }
            }
            tmp = tmp->next;
        }
        return flag;
    }
    void sort()
    {
        bool flag = iterate(root);
        while (flag)
        {
            flag = iterate(root);
        }
    }
};

int main()
{
    singleHead *root = new singleHead(10);
    SingleLinkedList branch = SingleLinkedList(root);
    branch.insertion_at_end(20);
    branch.insertion_at_end(100);
    branch.insertion_at_end(200);
    branch.insertion_at_end(300);
    branch.insertion_at_start(0);
    branch.insertion_at_start(1);
    branch.insert_at_index(500, 1);
    branch.insert_at_index(1000, 0);
    branch.insert_at_index(2000, 0);
    branch.display();
    branch.delete_first();
    branch.display();
    branch.delete_last();
    branch.display();
    branch.delete_at_index(1);
    branch.display();
    branch.sort();
    branch.display();
    branch.reverse_display();
    return 0;
}