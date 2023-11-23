#include <iostream>
#include <thread>
#include <chrono>
using namespace std;
void function1()
{
    for(int i=0;i<5;i++)
    {
        cout<<"Thread 1"<<i<<"  "<<endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }
}
void function2()
{
    for(int i=0;i<5;i++)
    {
        cout<<"Thread 2"<<i<<"  "<<endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }
}
int main()
{
    thread t1(function1);
    thread t2(function2);
    t1.join();
    t2.join();
    return 0;
}



// Tree of Space:
#include <iostream>
#include <vector>
#include <unordered_map>

class TreeNode {
public:
    int nodeId;
    bool locked;
    int userId;
    TreeNode* parent;
    std::unordered_map<int, TreeNode*> children;

    TreeNode(int nodeId) : nodeId(nodeId), locked(false), userId(-1), parent(nullptr) {}
};

class LockingTree {
private:
    TreeNode* root;
    std::unordered_map<int, TreeNode*> nodes;

public:
    LockingTree(std::vector<int>& parent) : root(nullptr) {
        for (int i = 0; i < parent.size(); i++) {
            nodes[i] = new TreeNode(i);
        }

        for (int i = 0; i < parent.size(); i++) {
            if (parent[i] != -1) {
                nodes[i]->parent = nodes[parent[i]];
                nodes[parent[i]]->children[i] = nodes[i];
            } else {
                root = nodes[i];
            }
        }
    }

    bool lock(int nodeId, int userId) {
        TreeNode* node = nodes[nodeId];
        if (node->locked) {
            return false; // Node is already locked
        }

        // Check if any ancestor is locked
        TreeNode* current = node;
        while (current != nullptr) {
            if (current->locked) {
                return false; // An ancestor is locked
            }
            current = current->parent;
        }

        // Lock the node
        node->locked = true;
        node->userId = userId;
        return true;
    }

    bool unlock(int nodeId, int userId) {
        TreeNode* node = nodes[nodeId];
        if (!node->locked || node->userId != userId) {
            return false; // Node is not locked by the given user
        }

        // Unlock the node
        node->locked = false;
        node->userId = -1;
        return true;
    }

    bool upgrade(int nodeId, int userId) {
        TreeNode* node = nodes[nodeId];
        if (node->locked) {
            return false; // Node is already locked
        }

        // Check if all descendants are unlocked or locked by the same user
        if (checkDescendants(node, userId)) {
            // Upgrade the lock
            node->locked = true;
            node->userId = userId;
            return true;
        }

        return false;
    }

    bool checkDescendants(TreeNode* node, int userId) {
        if (node->locked && node->userId != userId) {
            return false; // A descendant is locked by a different user
        }

        for (auto& entry : node->children) {
            TreeNode* child = entry.second;
            if (!checkDescendants(child, userId)) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    std::vector<int> parent = {-1, 0, 0, 2, 2, 4, 4};
    LockingTree tree(parent);

    // Test the locking tree operations here

    return 0;
}


#include <iostream>
#include <unordered_map>
#include <vector>

class TreeNode {
public:
    std::string name;
    std::vector<TreeNode*> children;
    bool locked;
    std::string locked_by;

    TreeNode(std::string _name) : name(_name), locked(false), locked_by("") {}
};

class M_aryTree {
private:
    std::unordered_map<std::string, TreeNode*> node_map;

public:
    void addNode(std::string parentName, std::string nodeName) {
        TreeNode* parentNode = node_map[parentName];
        if (parentNode) {
            TreeNode* newNode = new TreeNode(nodeName);
            parentNode->children.push_back(newNode);
            node_map[nodeName] = newNode;
        } else {
            throw std::runtime_error("Parent node not found.");
        }
    }

    bool lock(std::string nodeName, std::string uid) {
        TreeNode* node = node_map[nodeName];
        if (!node) {
            return false;  // Node does not exist
        }

        if (node->locked) {
            return false;  // Node is already locked
        }

        if (hasDescendantLocked(node)) {
            return false;  // A descendant is already locked
        }

        if (hasAncestorLockedByOtherUser(node, uid)) {
            return false;  // An ancestor is locked by a different user
        }

        node->locked = true;
        node->locked_by = uid;
        return true;
    }

    bool unlock(std::string nodeName, std::string uid) {
        TreeNode* node = node_map[nodeName];
        if (!node) {
            return false;  // Node does not exist
        }

        if (!node->locked) {
            return false;  // Node is not locked
        }

        if (node->locked_by != uid) {
            return false;  // Node is locked by a different user
        }

        node->locked = false;
        node->locked_by = "";
        return true;
    }

    bool upgradeLock(std::string nodeName, std::string uid) {
        TreeNode* node = node_map[nodeName];
        if (!node) {
            return false;  // Node does not exist
        }

        if (!node->locked) {
            return false;  // Node is not locked
        }

        if (node->locked_by != uid) {
            return false;  // Node is locked by a different user
        }

        if (hasAncestorLockedByOtherUser(node, uid)) {
            return false;  // An ancestor is locked by a different user
        }

        node->locked = false;
        node->locked_by = "";

        // Lock all ancestor nodes by the user
        TreeNode* current = findParent(node);
        while (current) {
            current->locked = true;
            current->locked_by = uid;
            current = findParent(current);
        }

        return true;
    }

    TreeNode* findParent(TreeNode* node) {
        for (auto& it : node_map) {
            TreeNode* parent = it.second;
            for (TreeNode* child : parent->children) {
                if (child == node) {
                    return parent;
                }
            }
        }
        return nullptr;
    }

    bool hasDescendantLocked(TreeNode* node) {
        if (node->locked) {
            return true;
        }
        for (TreeNode* child : node->children) {
            if (hasDescendantLocked(child)) {
                return true;
            }
        }
        return false;
    }

    bool hasAncestorLockedByOtherUser(TreeNode* node, std::string uid) {
        TreeNode* current = findParent(node);
        while (current) {
            if (current->locked && current->locked_by != uid) {
                return true;
            }
            current = findParent(current);
        }
        return false;
    }
};

int main() {
    M_aryTree tree;
    tree.addNode("World", "North America");
    tree.addNode("North America", "USA");
    tree.addNode("USA", "California");

    // Locking
    std::cout << tree.lock("California", "User1") << std::endl;  // true
    std::cout << tree.lock("USA", "User2") << std::endl;         // false (Descendant is already locked)
    std::cout << tree.lock("North America", "User3") << std::endl;  // false (Ancestor is locked by a different user)

    // Unlocking
    std::cout << tree.unlock("California", "User1") << std::endl;  // true

    // Upgrading lock
    std::cout << tree.upgradeLock("California", "User1") << std::endl;  // true
    std::cout << tree.lock("USA", "User2") << std::endl;                // false (Ancestor is locked by the same user)

    return 0;
}
