plaintext = "Hello I'am 0xSaad"
key = "23"

plaintext = plaintext.replace(" ", "").upper()

# Number of columns
num_columns = len(key)

# Divide  into rows
rows = [
    plaintext[i:i + num_columns]
    for i in range(0, len(plaintext), num_columns)
]



print("Original Table:")
print(" ".join(key))

for row in rows:
    print(" ".join(row))

column_order = sorted(
    range(num_columns),
    key=lambda i: int(key[i])
)

print("\nColumn Order:", [i + 1 for i in column_order])



ciphertext = ""

for col in column_order:
    for row in rows:
        if col < len(row):
            ciphertext += row[col]

print("\nCiphertext:")
print(ciphertext)