import base64

def xor_decrypt(encoded_line: bytes, key: str) -> str:

    encrypted_bytes = base64.b64decode(encoded_line)
    key_bytes = key.encode()
    decrypted = bytes([b ^ key_bytes[i % len(key_bytes)] for i, b in enumerate(encrypted_bytes)])
    return decrypted.decode('utf-8', errors='replace')


def main():
    key = "super_secret_key"
    with open("security_monitor/build/secure_log.txt", "rb") as f:
        for line in f:
            encoded_line = line.strip()
            decoded = xor_decrypt(encoded_line, key)
            print(decoded)
            

if __name__ == "__main__":
    main()
