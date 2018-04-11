#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Dictionary
{
    string      m_word;
    string      m_meaning;
    Dictionary *m_left; 
    Dictionary *m_right;
    int         m_count;

public:
    Dictionary()
    {
        m_left = m_right = NULL;
        m_count = 0;
    }

    const string& GetMeaning() { return m_meaning; }
    void DumpToFile(string& fileName);
    void DumpToFile(ofstream& fileStream);
    Dictionary* Zap();
    Dictionary* Search(string& word);
    Dictionary* Insert(string&, string&);
    Dictionary* Delete(string&);
    Dictionary* RR();
    Dictionary* LL();
    Dictionary* LR();
    Dictionary* RL();

    int Height();
    void PreOrder();
    void InOrder();

    Dictionary* RotateRight();
    Dictionary* RotateLeft();

    int BF();
};

Dictionary* CreateDictionaryFromFile(string &fileName)
{
    Dictionary* root = NULL;

    ifstream myFile(fileName.c_str());

    if (!myFile.is_open()) {
        cerr << "error: cant open file " << fileName << endl;
        return root;
    }

    root = new Dictionary; 
    while (myFile.good()) {
        string line;
        getline (myFile, line);

        if (line[0] == '#') 
            continue;

        size_t pos;
        pos = line.find(" ");
        pos = (pos != std::string::npos)? pos+1: 0;
        if (pos == 0) 
            continue;

        string word, meaning;
        word = line.substr(0, pos-1);
        meaning = line.substr (pos);

        root = root->Insert(word, meaning);
    }
    myFile.close();

    return root;
}

Dictionary* Dictionary::Insert(string& word, string& meaning)
{
    Dictionary *newRoot = this;

    if (m_count == 0) {
        m_word = word;
        m_meaning = meaning;
        m_count = 1;
    }

    if (word > m_word) {
        if (m_right == NULL) {
            m_right = new Dictionary;
        }
        m_right = m_right->Insert(word, meaning);

        if (BF() <= -2) {
            newRoot = (word > m_right->m_word)? RR(): RL();
        }
    }
    else if (word < m_word) {
        if (m_left == NULL) {
            m_left = new Dictionary;
        }

        m_left = m_left->Insert(word, meaning);
        if (BF() == 2) {
            newRoot = (word < m_left->m_word)? LL(): LR(); 
        }
    }

    return newRoot;
}

// Delete(): 
Dictionary* Dictionary::Delete(string& word)
{
    Dictionary *newRoot = this;

    if (word == m_word) {
        // We are on the node containing the word
        // If this is the leaf node, then return NULL as the new Root
        if (!m_right && !m_left) 
            newRoot = NULL;

        else if (!m_right) {
            Dictionary* t = m_left; 

            m_right = t->m_left;
            m_left = t->m_left;
            m_word = t->m_word;
            m_meaning = t->m_meaning;

            delete t;
        }
        else if (!m_left) {
            Dictionary* t = m_right; 

            m_right = t->m_left;
            m_left = t->m_left;
            m_word = t->m_word;
            m_meaning = t->m_meaning;

            delete t;
        }
        else {
            Dictionary* t;
    
            // Overwrite the current node with leaf node in the right subtree
            for (t = m_right; t->m_left; t = t->m_left);
            m_word = t->m_word;
            m_meaning = t->m_meaning;

            // Delete the leaf from the subtree
            t = m_right->Delete(word);
            if (t == NULL) 
                delete m_right;

            m_right = t;

            if (BF() >= 2)
                newRoot = (m_left->BF() >= 0)? LL(): LR();
        }
    }
    else if (m_right && word > m_word) {
        Dictionary *t;

        t = m_right->Delete(word);
        if (t == NULL)
            delete m_right;

        m_right = t;

        if (BF() >= 2) 
             newRoot = (m_left->BF() >= 0)? LL(): LR();
    }
    else if (m_left && word < m_word) {
        Dictionary *t;

        t = m_left->Delete(word);
        if (t == NULL)
             delete m_left;

        m_left = t;

        if (BF() <= -2) 
             newRoot = (m_right->BF() <= 0)? RR(): RL();
    }

    return newRoot;
}

Dictionary* Dictionary::LL()
{
    return RotateRight();
}

Dictionary* Dictionary::RR()
{
    return RotateLeft();
}

Dictionary* Dictionary::LR()
{
    if (m_left) {
         m_left = m_left->RotateLeft();
    }
    return RotateRight();
}

Dictionary* Dictionary::RL()
{
    if (m_right) {
         m_right = m_right->RotateRight();
    }
    return RotateLeft();
}

Dictionary* Dictionary::RotateRight()
{
    Dictionary *newRoot = NULL;

    newRoot = m_left;
    m_left = newRoot->m_right;
    newRoot->m_right = this;

    return newRoot;
}

Dictionary* Dictionary::RotateLeft()
{
    Dictionary *newRoot = NULL;

    newRoot = m_right;
    m_right = newRoot->m_left;
    newRoot->m_left = this;

    return newRoot;
}

int Dictionary::BF()
{
    int lh, rh;

    lh = (m_left)? m_left->Height(): 0;
    rh = (m_right)? m_right->Height(): 0;

    return (lh-rh);
}

void Dictionary::PreOrder()
{
    if (m_count) { 
        cout << m_word << ",";
        if (m_left) m_left->PreOrder();
        if (m_right) m_right->PreOrder();
    }
}

void Dictionary::DumpToFile(string& fileName)
{
    ofstream fileStream(fileName.c_str());

    if (!fileStream.is_open()) { 
        cerr << "error: cant open file " << fileName << endl;
        return;
    }

    DumpToFile(fileStream);
}

Dictionary* Dictionary::Zap()
{
    if (m_left) { 
        m_left->Zap();
        delete m_left; 
        m_left = NULL; 
    }
    if (m_right) { 
        m_right->Zap();
        delete m_right;
        m_right = NULL;
    }
    m_word = "";
    m_meaning = "";
    m_count = 0;
}

Dictionary* Dictionary::Search(string& word)
{
    if (m_count && word == m_word) 
        return this;

    if (word > m_word)
        return (m_right)? m_right->Search(word): NULL;
    else 
        return (m_left)? m_left->Search(word): NULL;
}

void Dictionary::DumpToFile(ofstream& fileStream)
{
    if (m_count) { 
        if (m_left) 
            m_left->DumpToFile(fileStream);
        fileStream << m_word << " " << m_meaning << endl;
        if (m_right) 
            m_right->DumpToFile(fileStream);
    }
}

void Dictionary::InOrder()
{
    if (m_count) { 
        if (m_left) 
            m_left->InOrder();
        cout << m_word << ",";
        if (m_right) 
            m_right->InOrder();
    }
}

int Dictionary::Height()
{
    int lh, rh;

    if (m_count == 0) 
        return 0;

    lh = (m_left)? m_left->Height(): 0;
    rh = (m_right)? m_right->Height(): 0;
    
    return (lh > rh)? lh+1: rh+1;
}

int main()
{
    Dictionary *root = NULL;
    int ch = 0;

    do {
        cout << " 1. Create Tree" << endl
             << " 2. Create Tree from File" << endl
             << " 3. Zap Tree" << endl
             << " 4. Save to File" << endl
             << " 5. Insert into Tree" << endl
             << " 6. Delete From Tree" << endl
             << " 7. Search In Tree" << endl
             << " 8. PreOrder" << endl
             << " 9. Inorder" << endl
             << "10. Exit" << endl;
        cout << "\nEnter choice: ";
        cin >> ch;

        switch (ch) {
            case 1: { 
                    if (root) { 
                        cout << "error: Tree is already created. "
                             << "ZAP before re-creating it." << endl;
                        break;
                    }

                    int n; 
                    cout << "\n Enter the number of words: ";
                    cin  >> n; 

                    root = new Dictionary;
                    for(int i=0; i<n; i++) {
                        string word, meaning;
                
                        cout << "Enter word " << i+1 << " :";
                        cin >> word;
                        cout << "Enter the meaning: ";
                        cin >> meaning;
                        root = root->Insert(word, meaning);
                    }
                    }
                    break;

            case 2: {
                    if (root) { 
                        cout << "error: Tree is already created. "  
                             << "ZAP before re-creating it." << endl;
                        break;
                    }

                    string fileName; 

                    cout << "Enter the file name: "; 
                    cin  >> fileName;

                    root = CreateDictionaryFromFile(fileName);
                    }
                    break;

            case 3: if (root) {
                        root->Zap();
                        delete root; 
                        root = NULL;
                    }
                    break;

            case 4: { 
                    if (!root) { 
                        cout << "Tree not yet creted" << endl; 
                        break;
                    }

                    string fileName;
                    cout << "Enter the file Name: ";
                    cin  >> fileName; 

                    root->DumpToFile(fileName);
                    }
                    break;

            case 5: {
                    if (root == NULL) { 
                        cout << "error: No Dictionary created yet" << endl;
                        break;
                    }
                    
                    string word, meaning; 

                    cout << "\n Enter the word: ";
                    cin >> word;
                    cout << "\n Enter the meaning: ";
                    cin >> meaning;

                    root = root->Insert(word, meaning);
                    }
                    break;

            case 6: {
                    string word;

                    cout << "\n Enter the word you want to delete: ";
                    cin >> word;

                    root = root->Delete(word);
                    }
                    break;

            case 7: { 
                    string word;
                    Dictionary* node = NULL;
                
                    cout << "Enter the word to search: "; 
                    cin  >> word;
                    
                    node = root->Search(word);
                    if (node) { 
                        cout << "The mearning of word " << word << " is " 
                             << node->GetMeaning() << endl;
                    }
                    else {
                        cout << "The word " << word 
                             << " not found in the dictionary" << endl;
                    }
                    cout << "Press any key to contine....";
                    cin  >> word;
                    }
                    break;

            case 8: {
                    if (!root) {
                        cout << "Tree not yet created" << endl; 
                        break;
                    }
                    root->PreOrder();
                    cout << endl << endl;
                    }
                    break;

            case 9: {
                    if (!root) { 
                        cout << "Tree not yet creted" << endl; 
                        break;
                    }
                    root->InOrder();
                    cout << endl << endl;
                    }
                    break;

            case 10: break;

            default:
                    cout << "Invalid choice" << endl;
            }
      } while (ch != 10);
      return 0;
}
