# rsa-decrypt

RSA algorithm is asymmetric cryptography algorithm.
Asymmetric actually means that it works on two different keys i.e. Public Key and Private Key. 
As the name describes that the Public Key is given to everyone and Private key is kept private.

# TO EXECUTE 

               $ gcc rsadecrypt.c -lm

OBTAINING ORIGINAL MESSAGE FROM ENCRYPTED MESSAGE 
(given p,q and c) c->ciphertext

              1)Find n=p*q
              2)Find phi(n)= (p-1)*(q-1)
              3)Find e, which is relatively prime to  phi(n)
              4)Find d, which is the multiplicative inverse of e in phi(n)
              5)Find M, which is c^d(mod n)
              M is the original message
