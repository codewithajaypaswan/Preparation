class TextEditor {
public:
    stack<char>left, right;
    TextEditor() {
        
    }
    
    void addText(string text) {
        for(char c:text) {
            left.push(c);
        }
    }
    
    int deleteText(int k) {
        int cnt = 0;
        while(!left.empty() && k--) {
            left.pop();
            cnt++;
        }
        return cnt;
    }
    
    string cursorLeft(int k) {
        while(!left.empty() && k--) {
            char c = left.top(); left.pop();
            right.push(c);
        }
        return getString();
    }
    
    string cursorRight(int k) {
        while(!right.empty() && k--) {
            char c = right.top(); right.pop();
            left.push(c);
        }
        return getString();
    }
    string getString() {
        string res = "";
        while(!left.empty() && res.size() < 10) {
            res.push_back(left.top());
            left.pop();
        }
        reverse(res.begin(), res.end());
        for(int i=0; i<res.size(); i++) {
            left.push(res[i]);
        }
        return res;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */