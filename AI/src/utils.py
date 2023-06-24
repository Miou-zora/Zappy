##
## EPITECH PROJECT, 2023
## Zappy-Mirror
## File description:
## utils
##

def clamp(n, smallest, largest):
    return max(smallest, min(n, largest))


def encrypt_string(input_string, encryption_key):
    encrypted_string = ""
    key_length = len(encryption_key)

    for i, char in enumerate(input_string):
        key_char = encryption_key[i % key_length]
        encrypted_char = chr(ord(char) ^ ord(key_char))
        encrypted_string += encrypted_char
    return encrypted_string

def decrypt_string(encrypted_string, encryption_key):
    decrypted_string = ""
    key_length = len(encryption_key)

    for i, char in enumerate(encrypted_string):
        key_char = encryption_key[i % key_length]
        decrypted_char = chr(ord(char) ^ ord(key_char))
        decrypted_string += decrypted_char
    return decrypted_string