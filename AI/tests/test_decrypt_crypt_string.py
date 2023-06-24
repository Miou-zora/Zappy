##
## EPITECH PROJECT, 2023
## Zappy-Mirror
## File description:
## test_decrypt_crypt_string
##

import unittest
from src.utils import encrypt_string, decrypt_string

class TestDecryptCryptString(unittest.TestCase):
    def test_crypt_string(self):
        key = "allo"
        string = "test"
        encrypted_string = encrypt_string(string, key)
        self.assertEqual(decrypt_string(encrypted_string, key), string)

    def test_crypt_string_with_empty_string(self):
        key = "allo"
        string = ""
        encrypted_string = encrypt_string(string, key)
        self.assertEqual(decrypt_string(encrypted_string, key), string)

    def test_crypt_string_with_space_key(self):
        key = " "
        string = "test"
        encrypted_string = encrypt_string(string, key)
        self.assertEqual(decrypt_string(encrypted_string, key), string)

    def test_crypt_string_with_space_string(self):
        key = "allo"
        string = " "
        encrypted_string = encrypt_string(string, key)
        self.assertEqual(decrypt_string(encrypted_string, key), string)

    def test_crypt_string_food_situation(self):
        key = "allo"
        string = "33470a99-c45f-4807-9d15-dc1dda4d01fc foods"
        encrypted_string = encrypt_string(string, key)
        self.assertEqual(decrypt_string(encrypted_string, key), string)

    def test_crypt_string_comming_situation(self):
        key = "allo"
        string = "33470a99-c45f-4807-9d15-dc1dda4d01fc comming to 33470a99-c45f-4807-9d15-dd1dda4d01fc"
        encrypted_string = encrypt_string(string, key)
        self.assertEqual(decrypt_string(encrypted_string, key), string)

    def test_crypt_string_ready_situation(self):
        key = "allo"
        string = "33470a99-c45f-4807-9d15-dc1dda4d01fc ready with 33470a99-c45f-4807-9d15-dd1dda4d01fc"
        encrypted_string = encrypt_string(string, key)
        self.assertEqual(decrypt_string(encrypted_string, key), string)