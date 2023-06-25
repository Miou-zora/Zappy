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
        if char.isalpha():
            ascii_offset = 65 if char.isupper() else 97
            key_char = encryption_key[i % key_length]
            key_shift = ord(key_char)
            shifted_char = chr((ord(char) - ascii_offset + key_shift) % 26 + ascii_offset)
            encrypted_string += shifted_char
        else:
            encrypted_string += char
    return encrypted_string

def decrypt_string(encrypted_string, encryption_key):
    decrypted_string = ""
    key_length = len(encryption_key)
    for i, char in enumerate(encrypted_string):
        if char.isalpha():
            ascii_offset = 65 if char.isupper() else 97
            key_char = encryption_key[i % key_length]
            key_shift = ord(key_char)
            shifted_char = chr((ord(char) - ascii_offset - key_shift) % 26 + ascii_offset)
            decrypted_string += shifted_char
        else:
            decrypted_string += char
    return decrypted_string
