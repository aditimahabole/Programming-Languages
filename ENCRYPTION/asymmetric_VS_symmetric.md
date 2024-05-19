# Symmetric Encryption

![diagram-export-5-19-2024-2_08_55-PM](https://github.com/aditimahabole/Programming-Languages/assets/78752342/b989d1c1-4ce4-4734-b408-93a26cf32c79)


<br>

### Challenges with Symmetric Encryption
+ Key Distribution Problem:
    + In symmetric encryption, both the sender and the receiver need to have the same key.
    + Securely distributing this key over potentially insecure channels posed a significant challenge.
    + The key needed to be shared in advance, often requiring a secure channel itself, which defeated the purpose.


+ Scalability Issue:
    + In a network of n users, each pair of users needs a unique key. This results in **n(n-1)/2 keys**.
    + As the number of users grows, managing and distributing these keys becomes increasingly complex.





# Asymmetric Encryption


![image](https://github.com/aditimahabole/Programming-Languages/assets/78752342/1df47158-de26-4fe3-a49b-21cace98508b)


### Scenario: Alice Sends a Secure Message to Bob
Key Generation:
+ Bob generates a key pair consisting of a public key and a private key.
+ Bob keeps his private key secret and shares his public key openly.

Public Key Distribution:
+ Bob’s public key can be shared via a public directory, a secure website, or directly to Alice.
+ Alice obtains Bob’s public key from one of these sources.

Encryption:
+ Alice wants to send a confidential message to Bob.
+ Alice uses Bob’s public key to encrypt the plaintext message.
+ The encrypted message (ciphertext) can only be decrypted by someone with Bob’s private key.

Sending the Message:
+ Alice sends the encrypted message to Bob over any communication channel (e.g., email, messaging app).

Decryption:
+ Bob receives the encrypted message.
+ Bob uses his private key to decrypt the ciphertext, retrieving the original plaintext message.



