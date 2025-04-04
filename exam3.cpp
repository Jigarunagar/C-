#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

vector<int> findPrimes(int arr[][3], int rows, int cols) {
    vector<int> primes; 
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (isPrime(arr[i][j])) {
                primes.push_back(arr[i][j]);
            }
        }
    }
    return primes;
}

int main() {
    int arr[3][3] = {
        {2, 4, 6},
        {3, 5, 8},
        {9, 11, 12}
    };

    vector<int> primeNumbers = findPrimes(arr, 3, 3);

    cout << "Prime numbers in the array: [";
    for (size_t i = 0; i < primeNumbers.size(); i++) {
        cout << primeNumbers[i];
        if (i < primeNumbers.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}
///////////////////////////////
#include <iostream>
#include <unordered_map>
using namespace std;

void twoSum(int arr[], int size, int target) {
    unordered_map<int, int> numMap;

    for (int i = 0; i < size; i++) {
        int complement = target - arr[i];


        if (numMap.find(complement) != numMap.end()) {
            cout << "two numbers: [" << numMap[complement] << ", " << i << "]" << endl;
            return;
        }
        numMap[arr[i]] = i;
    }

    cout << "No valid pair found." << endl;
}

int main() {
    int arr[] = {2, 7, 11, 15};
    int target = 9;
    int size = sizeof(arr) / sizeof(arr[0]);

    twoSum(arr, size, target);
    return 0;
}

/////////////////////////////////
#include <iostream>
#include <unordered_map>
using namespace std;


void printCharFrequency(const string &str) {
    unordered_map<char, int> freqMap; 

    for (char ch : str) {
        freqMap[ch]++;
    }
    cout << "Character frequencies: { ";
    for (auto pair : freqMap) {
        cout << "'" << pair.first << "': " << pair.second << ", ";
    }
    cout << "\b\b }" << endl;
}

int main() {
    string str = "hello world";

    printCharFrequency(str);

    return 0;
}
////////////////////////////////////////////
#include <iostream>
using namespace std;

void printFibonacciMax(int maxVal) {
    int a = 0, b = 1, nextTerm;

    cout << "Fibonacci series: [";
    while (a <= maxVal) {
        cout << a;
        nextTerm = a + b;
        if (nextTerm <= maxVal) cout << ", ";

        a = b;
        b = nextTerm;
    }
    cout << "]" << endl;
}

int main() {
    int maxValue = 50; 
    printFibonacciMax(maxValue);
    return 0;
}
//////////////////////////////////

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {  
        data = val;
        next = nullptr;
    }
};

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data;
        if (head->next != nullptr) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;  
        current->next = prev;  
        prev = current;        
        current = next;        
    }

    return prev; 
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original Linked List: ";
    printList(head);
    head = reverseList(head);
    cout << "Reversed Linked List: ";
    printList(head);

    return 0;
}
