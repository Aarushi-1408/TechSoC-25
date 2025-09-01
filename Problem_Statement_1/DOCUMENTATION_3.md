## Problem Understanding
**What the problem is asking:**  
The bonus task is to take the ciphertext from the Caesar Cipher and apply **Base64 encoding** to it. This makes the encrypted text look more scrambled and harder to immediately recognize, adding another layer of obfuscation.

**Key concepts involved:**  
- Caesar Cipher (classical shift cipher)  
- Base64 encoding (binary-to-text encoding)  
- Combining multiple algorithms for stronger security  

**My approach:**  
After encrypting the message with Caesar Cipher, I converted the result into Base64 using a standard encoding function. This way, the final ciphertext is no longer just shifted letters, but a string of characters (`A–Z, a–z, 0–9, +, /`) that looks completely different from the original message.

---

## Conceptual Learning

### **New Concepts I Discovered**
- **Base64 Encoding:**  
  A method to represent binary data using 64 printable characters. Commonly used in email, JSON, and web applications to safely transmit data.  

- **Multi-layer Security (Hybrid Encryption):**  
  Applying more than one encoding/encryption technique in sequence to strengthen security.  

- **Data Representation:**  
  Base64 shows how the same underlying data can be represented in different forms (plain text vs. encoded).  

### **How I Applied These Concepts**
- I first applied the **Caesar Cipher** to shift the letters.  
- Then, I fed the resulting string into a **Base64 encoder**.  
- The output was a string that looks much more complex and less guessable than plain Caesar Cipher.  

### **Real-World Connections**
- **Web Development:** Base64 is used to embed images, transfer JSON data, and safely transmit binary files over text-based protocols.  
- **Cybersecurity:** Layered encoding/encryption makes it harder for attackers to decode messages at first glance.  
- **Data Obfuscation:** Even though Base64 is not encryption, when combined with Caesar Cipher, it demonstrates how multiple layers can confuse unintended readers.  
