// double headed linked list
#include <iostream>
class double_head_node
{
public:
    int data;
    double_head_node *next;
    double_head_node *prev;

    double_head_node(int val)
    {
        this->data = val;
    }
    double_head_node(int val, double_head_node *next)
    {
        this->next = next;
        this->data = val;
    }
    double_head_node(int val, double_head_node *next, double_head_node *prev)
    {
        this->data = val;
        this->next = next;
        this->prev = prev;
    }
};
class DoubleHeadLL
{
private:
    int counter = 0;
    bool flag = false;
    double_head_node *root;

public:
    DoubleHeadLL(double_head_node *root)
    {
        this->root = root;
        this->counter += 1;
    }
    void insert_at_last(int val)
    {
        double_head_node *tmp = root;
        while (tmp->next != nullptr)
        {
            tmp = tmp->next;
        }
        double_head_node *node = new double_head_node(val);
        tmp->next = node;
        node->prev = tmp;
        this->counter += 1;
    }
    void insert_at_start(int val)
    {
        double_head_node *node = new double_head_node(val);
        node->next = root;
        root->prev = node;
        root = node;
        this->counter += 1;
    }
    void insert_at_index(int val, int index)
    {
        int cnt = 0;
        if (index == 0)
            insert_at_start(val);
        else if (index == this->counter)
            insert_at_last(val);
        else
        {
            double_head_node *tmp = root;
            while (tmp != nullptr)
            {
                if (cnt == index - 1)
                    break;
                cnt += 1;
                tmp = tmp->next;
            }
            double_head_node *node = new double_head_node(val);
            node->next = tmp->next;
            node->next->prev = node;
            node->prev = tmp;
            tmp->next = node;
            this->counter += 1;
        }
    }
    int delete_at_start()
    {
        int val = root->data;
        root = root->next;
        root->prev = NULL;
        this->counter -= 1;
        return val;
    }
    int delete_at_last()
    {
        double_head_node *tmp = root;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        int val = tmp->data;
        tmp->next = NULL;
        tmp->prev->next = NULL;
        this->counter -= 1;
        return val;
    }
    int delete_at_index(int index)
    {
        if (index == 0)
            return delete_at_start();
        if (index == this->counter)
            return delete_at_last();
        int cnt = 0;
        double_head_node *tmp = root;
        while (tmp != NULL)
        {
            if (cnt == index)
                break;
            cnt += 1;
            tmp = tmp->next;
        }
        int val = tmp->data;
        this->counter -= 1;
        double_head_node *local_head = tmp->prev;
        tmp->prev->next = tmp->next;
        tmp->next->prev = local_head;
        tmp->next = NULL;
        tmp->prev = NULL;
        return val;
    }
    void display()
    {
        double_head_node *tmp = root;
        while (tmp != nullptr)
        {
            std::cout << tmp->data << " << ";
            tmp = tmp->next;
        }
        std::cout << "end" << std::endl;
    }
    void display_reverse()
    {
        double_head_node *tmp = root;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        while (tmp->prev != NULL)
        {
            std::cout << tmp->data << " << ";
            tmp = tmp->prev;
        }
        std::cout << tmp->data;
        std::cout << " << " << "start" << std::endl;
    }
    int getCount()
    {
        return this->counter;
    }
    int search(int target)
    {
        double_head_node *tmp = root;
        while (tmp != NULL)
        {
            if (tmp->data == target)
                return true;
            tmp = tmp->next;
        }
        return false;
    }
    bool iterate(double_head_node *node)
    {
        bool flag = false;
        double_head_node *tmp = node;
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
    double_head_node *root = new double_head_node(0);
    DoubleHeadLL branch = DoubleHeadLL(root);
    branch.insert_at_start(2);
    branch.insert_at_start(10);
    branch.insert_at_last(50);
    branch.insert_at_index(100, 0);
    branch.insert_at_index(1000, 5);
    branch.insert_at_index(500, 2);
    branch.insert_at_index(10000, 3);
    branch.insert_at_last(400);
    branch.insert_at_index(90, 0);
    branch.display();
    branch.delete_at_start();
    branch.display();
    branch.delete_at_index(3);
    branch.display();
    bool res = branch.search(500);
    std::cout << "Element is present / absent " << res << std::endl;
    return 0;
}