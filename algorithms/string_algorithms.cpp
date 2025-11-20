#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

// KMP (Knuth-Morris-Pratt) Pattern Matching
std::vector<int> compute_lps(const std::string& pattern) {
    int m = pattern.length();
    std::vector<int> lps(m, 0);
    int len = 0;
    int i = 1;
    
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    
    return lps;
}

std::vector<int> kmp_search(const std::string& text, const std::string& pattern) {
    std::vector<int> result;
    int n = text.length();
    int m = pattern.length();
    
    std::vector<int> lps = compute_lps(pattern);
    
    int i = 0; // index for text
    int j = 0; // index for pattern
    
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        
        if (j == m) {
            result.push_back(i - j);
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    
    return result;
}

// Rabin-Karp Algorithm
std::vector<int> rabin_karp(const std::string& text, const std::string& pattern) {
    std::vector<int> result;
    int n = text.length();
    int m = pattern.length();
    const int prime = 101;
    const int base = 256;
    
    if (m > n) return result;
    
    long long pattern_hash = 0;
    long long text_hash = 0;
    long long h = 1;
    
    // Calculate h = base^(m-1) % prime
    for (int i = 0; i < m - 1; i++) {
        h = (h * base) % prime;
    }
    
    // Calculate hash for pattern and first window of text
    for (int i = 0; i < m; i++) {
        pattern_hash = (base * pattern_hash + pattern[i]) % prime;
        text_hash = (base * text_hash + text[i]) % prime;
    }
    
    // Slide the pattern over text
    for (int i = 0; i <= n - m; i++) {
        if (pattern_hash == text_hash) {
            // Check characters one by one
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                result.push_back(i);
            }
        }
        
        // Calculate hash for next window
        if (i < n - m) {
            text_hash = (base * (text_hash - text[i] * h) + text[i + m]) % prime;
            if (text_hash < 0) {
                text_hash += prime;
            }
        }
    }
    
    return result;
}

// Manacher's Algorithm for Longest Palindromic Substring
std::string longest_palindrome(const std::string& s) {
    if (s.empty()) return "";
    
    // Transform string: "abc" -> "^#a#b#c#$"
    std::string transformed = "^#";
    for (char c : s) {
        transformed += c;
        transformed += '#';
    }
    transformed += '$';
    
    int n = transformed.length();
    std::vector<int> P(n, 0);
    int center = 0, right = 0;
    int max_len = 0, center_index = 0;
    
    for (int i = 1; i < n - 1; i++) {
        int mirror = 2 * center - i;
        
        if (i < right) {
            P[i] = std::min(right - i, P[mirror]);
        }
        
        // Try to expand palindrome centered at i
        while (transformed[i + (1 + P[i])] == transformed[i - (1 + P[i])]) {
            P[i]++;
        }
        
        // If palindrome centered at i extends past right, adjust center and right
        if (i + P[i] > right) {
            center = i;
            right = i + P[i];
        }
        
        // Update maximum length palindrome
        if (P[i] > max_len) {
            max_len = P[i];
            center_index = i;
        }
    }
    
    int start = (center_index - max_len) / 2;
    return s.substr(start, max_len);
}

// Z Algorithm for pattern matching
std::vector<int> z_algorithm(const std::string& s) {
    int n = s.length();
    std::vector<int> z(n);
    int l = 0, r = 0;
    
    for (int i = 1; i < n; i++) {
        if (i <= r) {
            z[i] = std::min(r - i + 1, z[i - l]);
        }
        
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    
    return z;
}

std::vector<int> z_search(const std::string& text, const std::string& pattern) {
    std::string combined = pattern + "$" + text;
    std::vector<int> z = z_algorithm(combined);
    std::vector<int> result;
    
    int pattern_len = pattern.length();
    for (int i = pattern_len + 1; i < combined.length(); i++) {
        if (z[i] == pattern_len) {
            result.push_back(i - pattern_len - 1);
        }
    }
    
    return result;
}

// Trie (Prefix Tree) for string operations
class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children;
    bool is_end_of_word;
    
    TrieNode() : is_end_of_word(false) {}
};

class Trie {
private:
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(const std::string& word) {
        TrieNode* current = root;
        for (char c : word) {
            if (current->children.find(c) == current->children.end()) {
                current->children[c] = new TrieNode();
            }
            current = current->children[c];
        }
        current->is_end_of_word = true;
    }
    
    bool search(const std::string& word) {
        TrieNode* current = root;
        for (char c : word) {
            if (current->children.find(c) == current->children.end()) {
                return false;
            }
            current = current->children[c];
        }
        return current->is_end_of_word;
    }
    
    bool starts_with(const std::string& prefix) {
        TrieNode* current = root;
        for (char c : prefix) {
            if (current->children.find(c) == current->children.end()) {
                return false;
            }
            current = current->children[c];
        }
        return true;
    }
};

int main() {
    std::cout << "=== String Algorithms ===\n\n";
    
    std::string text = "ABABDABACDABABCABCABCABCABC";
    std::string pattern = "ABABCABCABCABC";
    
    // KMP Algorithm
    std::cout << "1. KMP Pattern Matching:\n";
    std::cout << "Text: " << text << "\n";
    std::cout << "Pattern: " << pattern << "\n";
    
    auto kmp_matches = kmp_search(text, pattern);
    std::cout << "KMP matches at positions: ";
    for (int pos : kmp_matches) {
        std::cout << pos << " ";
    }
    std::cout << "\n\n";
    
    // Rabin-Karp Algorithm
    std::cout << "2. Rabin-Karp Pattern Matching:\n";
    auto rk_matches = rabin_karp(text, pattern);
    std::cout << "Rabin-Karp matches at positions: ";
    for (int pos : rk_matches) {
        std::cout << pos << " ";
    }
    std::cout << "\n\n";
    
    // Z Algorithm
    std::cout << "3. Z Algorithm Pattern Matching:\n";
    auto z_matches = z_search(text, pattern);
    std::cout << "Z Algorithm matches at positions: ";
    for (int pos : z_matches) {
        std::cout << pos << " ";
    }
    std::cout << "\n\n";
    
    // Longest Palindromic Substring
    std::cout << "4. Longest Palindromic Substring:\n";
    std::string palindrome_text = "babad";
    std::cout << "Text: " << palindrome_text << "\n";
    std::cout << "Longest palindrome: " << longest_palindrome(palindrome_text) << "\n\n";
    
    palindrome_text = "cbbd";
    std::cout << "Text: " << palindrome_text << "\n";
    std::cout << "Longest palindrome: " << longest_palindrome(palindrome_text) << "\n\n";
    
    // Trie operations
    std::cout << "5. Trie (Prefix Tree) Operations:\n";
    Trie trie;
    
    std::vector<std::string> words = {"apple", "app", "apricot", "banana", "band", "bandana"};
    
    std::cout << "Inserting words: ";
    for (const std::string& word : words) {
        std::cout << word << " ";
        trie.insert(word);
    }
    std::cout << "\n";
    
    std::vector<std::string> search_words = {"app", "apple", "application", "ban", "banana"};
    for (const std::string& word : search_words) {
        std::cout << "Search '" << word << "': " << (trie.search(word) ? "Found" : "Not found") << "\n";
    }
    
    std::vector<std::string> prefixes = {"app", "ban", "cat"};
    for (const std::string& prefix : prefixes) {
        std::cout << "Starts with '" << prefix << "': " << (trie.starts_with(prefix) ? "Yes" : "No") << "\n";
    }
    
    return 0;
}