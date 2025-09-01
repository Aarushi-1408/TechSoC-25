## Problem Understanding
**What the problem is asking:**  
The problem is to implement the **Caesar Cipher**, a classical encryption algorithm, where each letter in a message is shifted by a fixed number of positions in the alphabet. The goal is to take input text and a shift value, and then output the encrypted (or decrypted) message.

**Key concepts involved:**  
- Modular arithmetic  
- Character encoding (ASCII values)  
- Basic string manipulation  

**My approach:**  
I wrote a C++ program that loops through each character of the input string.  
- If the character is an uppercase or lowercase letter, I shift it by the given key using modular arithmetic so it "wraps around" the alphabet.  
- Non-alphabetic characters (like spaces or punctuation) are left unchanged.  
- Finally, I display the encrypted output.

---

## Conceptual Learning

### **New Concepts I Discovered**
- **Caesar Cipher Algorithm:**  
  A simple substitution cipher where each letter is replaced with another letter at a fixed shift. It’s one of the earliest known encryption methods.  

- **Modular Arithmetic:**  
  Useful for "wrapping around" the alphabet. For example, shifting `Z` by 1 should give `A`. This is achieved using `% 26`.  

- **Character Encoding (ASCII):**  
  Each character is stored as an integer code. By adjusting ASCII values carefully, we can shift letters while preserving case (uppercase vs lowercase).  

### **How I Applied These Concepts**
- I used **modular arithmetic** to ensure the shifted letters stay within the `A–Z` or `a–z` range.  
- I applied **ASCII value calculations** to convert characters to numbers, shift them, and convert them back to letters.  
- The logic was implemented inside a simple loop over the input string.  

### **Real-World Connections**
- **Cryptography:** While the Caesar Cipher is insecure today, it forms the foundation of modern encryption techniques.  
- **Data Security:** Understanding simple ciphers helps in learning how information can be protected.  
- **Puzzle Design & Games:** Caesar Ciphers are often used in puzzle hunts, escape rooms, or beginner cryptography exercises.  
