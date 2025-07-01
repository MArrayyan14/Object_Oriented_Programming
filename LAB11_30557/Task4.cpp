#include <iostream>
#include <vector>
#include <string>
using namespace std;

class FileNode {
public:
    string fileName;
    int fileSize;
    string fileType;
    FileNode* left;
    FileNode* right;

    FileNode(string name, int size, string type) {
        fileName = name;
        fileSize = size;
        fileType = type;
        left = right = nullptr;
    }

    ~FileNode() {}
};

ostream& operator<<(ostream& os, const FileNode& node) {
    os << node.fileName << " (" << node.fileSize << " MB, " << node.fileType << ")";
    return os;
}

class FileBST {
private:
    FileNode* root;

    FileNode* insert(FileNode* node, string name, int size, string type, bool& success);
    FileNode* remove(FileNode* node, string name, bool& success);
    FileNode* findMin(FileNode* node);
    FileNode* rename(FileNode* node, string oldName, string newName, bool& success);
    FileNode* search(FileNode* node, string name);
    void searchBySize(FileNode* node, int threshold, vector<FileNode*>& results);
    void inorder(FileNode* node);
    void preorder(FileNode* node);
    void postorder(FileNode* node);
    void destroyTree(FileNode* node);

public:
    FileBST();
    ~FileBST();

    void insert(string name, int size, string type);
    void remove(string name);
    void rename(string oldName, string newName);
    void search(string name);
    void searchBySize(int threshold);
    void inorder();
    void preorder();
    void postorder();
};

FileBST::FileBST() {
    root = nullptr;
}

FileBST::~FileBST() {
    destroyTree(root);
}

void FileBST::destroyTree(FileNode* node) {
    if (!node) return;
    destroyTree(node->left);
    destroyTree(node->right);
    delete node;
}

FileNode* FileBST::insert(FileNode* node, string name, int size, string type, bool& success) {
    if (!node) {
        success = true;
        return new FileNode(name, size, type);
    }
    if (name == node->fileName) {
        success = false;
    } else if (name < node->fileName) {
        node->left = insert(node->left, name, size, type, success);
    } else {
        node->right = insert(node->right, name, size, type, success);
    }
    return node;
}

void FileBST::insert(string name, int size, string type) {
    bool success = false;
    root = insert(root, name, size, type, success);
    if (!success) cout << "Error: Duplicate file name.\n";
}

FileNode* FileBST::findMin(FileNode* node) {
    while (node && node->left) node = node->left;
    return node;
}

FileNode* FileBST::remove(FileNode* node, string name, bool& success) {
    if (!node) {
        success = false;
        return nullptr;
    }
    if (name < node->fileName) {
        node->left = remove(node->left, name, success);
    } else if (name > node->fileName) {
        node->right = remove(node->right, name, success);
    } else {
        success = true;
        if (!node->left) {
            FileNode* temp = node->right;
            delete node;
            return temp;
        } else if (!node->right) {
            FileNode* temp = node->left;
            delete node;
            return temp;
        } else {
            FileNode* temp = findMin(node->right);
            node->fileName = temp->fileName;
            node->fileSize = temp->fileSize;
            node->fileType = temp->fileType;
            node->right = remove(node->right, temp->fileName, success);
        }
    }
    return node;
}

void FileBST::remove(string name) {
    bool success = false;
    root = remove(root, name, success);
    if (!success) cout << "Error: File not found.\n";
}

FileNode* FileBST::rename(FileNode* node, string oldName, string newName, bool& success) {
    FileNode* target = search(root, oldName);
    if (!target || search(root, newName)) {
        success = false;
        return node;
    }
    string type = target->fileType;
    int size = target->fileSize;
    bool tempSuccess = false;
    root = remove(root, oldName, tempSuccess);
    root = insert(root, newName, size, type, success);
    return root;
}

void FileBST::rename(string oldName, string newName) {
    bool success = false;
    root = rename(root, oldName, newName, success);
    if (!success) cout << "Error: Rename failed (file not found or duplicate name).\n";
}

FileNode* FileBST::search(FileNode* node, string name) {
    if (!node) return nullptr;
    if (name == node->fileName) return node;
    if (name < node->fileName) return search(node->left, name);
    return search(node->right, name);
}

void FileBST::search(string name) {
    FileNode* result = search(root, name);
    if (result) cout << *result << endl;
    else cout << "File not found.\n";
}

void FileBST::searchBySize(FileNode* node, int threshold, vector<FileNode*>& results) {
    if (!node) return;
    searchBySize(node->left, threshold, results);
    if (node->fileSize > threshold) results.push_back(node);
    searchBySize(node->right, threshold, results);
}

void FileBST::searchBySize(int threshold) {
    vector<FileNode*> results;
    searchBySize(root, threshold, results);
    for (auto n : results) cout << *n << endl;
}

void FileBST::inorder(FileNode* node) {
    if (!node) return;
    inorder(node->left);
    cout << *node << endl;
    inorder(node->right);
}

void FileBST::preorder(FileNode* node) {
    if (!node) return;
    cout << *node << endl;
    preorder(node->left);
    preorder(node->right);
}

void FileBST::postorder(FileNode* node) {
    if (!node) return;
    postorder(node->left);
    postorder(node->right);
    cout << *node << endl;
}

void FileBST::inorder() {
    if (!root) cout << "Empty tree.\n";
    else inorder(root);
}

void FileBST::preorder() {
    if (!root) cout << "Empty tree.\n";
    else preorder(root);
}

void FileBST::postorder() {
    if (!root) cout << "Empty tree.\n";
    else postorder(root);
}

int main() {
    FileBST tree;

    tree.insert("file1.txt", 10, "txt");
    tree.insert("file2.pdf", 25, "pdf");
    tree.insert("file3.exe", 15, "exe");

    tree.insert("file1.txt", 5, "txt");
    tree.remove("file4.txt");

    cout << "\nInorder:\n";
    tree.inorder();

    cout << "\nSearch for file2.pdf:\n";
    tree.search("file2.pdf");

    cout << "\nFiles larger than 12MB:\n";
    tree.searchBySize(12);

    cout << "\nRenaming file3.exe to file3a.exe:\n";
    tree.rename("file3.exe", "file3a.exe");

    cout << "\nPreorder:\n";
    tree.preorder();

    cout << "\nPostorder:\n";
    tree.postorder();

    return 0;
}